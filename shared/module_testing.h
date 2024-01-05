/*************************************************************************/ /*!
@Copyright      Copyright (c) Imagination Technologies Ltd. All Rights Reserved
@License        Strictly Confidential.
*/
/**************************************************************************/
#pragma once

#include <functional>
#include <memory>
#include <vector>
#include <set>
#include <string>
#include <exception>
#include <stdexcept>
#include <iostream>

#include <catch2/catch.hpp>

#ifndef SC_INCLUDE_DYNAMIC_PROCESSES
#define SC_INCLUDE_DYNAMIC_PROCESSES
#endif
#include "systemc.h"


namespace test_utils
{

// macro stringification and concat utils
#define QUOTE(str) #str
#define EXPAND_AND_QUOTE(str) QUOTE(str)

#define CONCAT(x, y) x##y
#define EXPAND_AND_CONCAT(x, y) CONCAT(x, y)

#ifdef __COUNTER__// not standard and may be missing for some compilers
#define ANONYMOUS_NAME(x) EXPAND_AND_CONCAT(x, __COUNTER__)
#else// __COUNTER__
#define ANONYMOUS_NAME(x) EXPAND_AND_CONCAT(x, __LINE__)
#endif// __COUNTER__


class ElaborationFactory
{
public:
    static ElaborationFactory& get()
    {
        static ElaborationFactory instance;
        return instance;
    }

    // module initializers' registration:
    using ModuleInitializer = std::function<sc_core::sc_module*()>;

    // the return value allows call before main
    bool add_module_initializer(ModuleInitializer mm)
    {
        initializers.emplace_back(std::move(mm));
        return true;
    }

    // elaboration-time setup:
    void initialize_modules()
    {
        // disable any cout output from initializers,
        // as any output there would show up even if the binary is run with "--list-tests-only"
        std::cout.setstate(std::ios_base::failbit);
        for (auto& ii : initializers)
        {
            auto module = ii();
            if (module)
            {
                modules.emplace_back(ii());
            }
        }
        initializers.clear();
        std::cout.clear();
        sc_core::sc_start(SC_ZERO_TIME);// getting the init phase out of the way
    }

private:
    ElaborationFactory() = default;

    std::vector<ModuleInitializer> initializers;
    std::vector<std::unique_ptr<sc_core::sc_module>> modules;
};


class WaitedEvents
{
    std::set<std::string> events;

    template <typename>
    struct is_sc_port : std::false_type
    {
    };

    template <typename IF>
    struct is_sc_port<sc_core::sc_port<IF>> : std::true_type
    {
    };

    template <class T>
    inline auto& get_if(T& port_or_if)
    {
        if constexpr (is_sc_port<T>::value)
        {
            return *port_or_if.get_interface(0);
        }
        else
        {
            return port_or_if;
        }
    }

    sc_core::sc_event no_wait_stop;
    bool no_wait_stopped = false;
    std::vector<sc_core::sc_process_handle> no_wait_handles;

    void expect_no_wait_thread(sc_core::sc_event_or_expr e, const std::string fileNline)
    {
        wait(e);
        if (!no_wait_stopped)
        {
            events.insert(fileNline);
        }
    }

    class ScopedRegister
    {
        const std::string fileNline;

    public:
        ScopedRegister(const char* file, int line)
            : fileNline(std::string(file) + ":" + std::to_string(line))
        {
            WaitedEvents::get().events.insert(fileNline);
        }
        ~ScopedRegister()
        {
            WaitedEvents::get().events.erase(fileNline);
        }
    };

public:
    static WaitedEvents& get()
    {
        static WaitedEvents instance;
        return instance;
    }

    void registered_wait(sc_core::sc_event_or_list e, const char* file, int line)
    {
        ScopedRegister(file, line);
        wait(e);
    }

    void expect_no_wait(sc_core::sc_event_or_list e, const char* file, int line)
    {
        const std::string fileNline(std::string(file) + ":" + std::to_string(line));
        const auto handle = sc_spawn(sc_bind(&WaitedEvents::expect_no_wait_thread, this, e | no_wait_stop, fileNline));
        no_wait_handles.emplace_back(handle);
        sc_core::wait(sc_core::SC_ZERO_TIME);// ensure thread starts
    }

    void stop_expect_no_wait()
    {
        no_wait_stopped = true;
        no_wait_stop.notify();
        for (auto h : no_wait_handles)
        {
            if (!h.terminated())
            {
                sc_core::wait(h.terminated_event());
            }
        }
        no_wait_handles.clear();
        no_wait_stopped = false;
    }

    template <class T>
    auto registered_read(T& port_or_if, const char* file, int line)
    {
        ScopedRegister(file, line);
        return get_if(port_or_if).read();
    }

    template <class T, class S>
    void registered_write(T& port_or_if, S&& object, const char* file, int line)
    {
        ScopedRegister(file, line);
        get_if(port_or_if).write(object);
    }

    std::set<std::string> get_events_and_clear()
    {
        return std::exchange(events, {});
    }
};


template <typename UUT_T, typename Fixture>
using RootTestBody = std::function<void(UUT_T*, Fixture*)>;

struct FixtureRunnerBase
{
protected:
    static void throw_on_unsignaled_events()
    {
        const auto waitedEvents = WaitedEvents::get().get_events_and_clear();
        if (waitedEvents.empty())
        {
            return;
        }

        std::string message = "Waited event(s) failed:\n";

        for (auto& e : waitedEvents)
        {
            message += "   " + e + "\n";
        }

        throw std::runtime_error(message);
    }
};

template <typename UUT_T, typename Fixture>
struct FixtureRunner : public sc_core::sc_module, private FixtureRunnerBase
{
    static_assert(
        requires(UUT_T& uut) { uut.Reset(); },
        "UUT has no Reset() function");

    using SC_CURRENT_USER_MODULE = FixtureRunner;
    static Fixture* fx;

    FixtureRunner(sc_core::sc_module_name const& fx_mn)
        : sc_module(fx_mn)
    {
        SC_THREAD(base_thread);
        SC_THREAD(post_test_thread);
    }

    void run_test(RootTestBody<UUT_T, Fixture> body)
    {
        test_case_body = body;
        trigger.notify();
        sc_core::sc_start();
        post_test_trigger.notify();
        sc_core::sc_start();
        rethrow_on_exception_from_test_case();
        throw_on_unsignaled_events();
        throw_on_unfinished_test_case();
    }

    virtual void Reset()
    {
    }

protected:
    std::unique_ptr<UUT_T> UUT;

private:
    sc_core::sc_event trigger;
    sc_core::sc_event post_test_trigger;
    RootTestBody<UUT_T, Fixture> test_case_body;

    std::exception_ptr test_case_exception;

    bool test_case_running = false;

    void base_thread()
    {
        while (true)
        {
            wait(trigger);
            // assert(UUT != nullptr, "INIT_UUT must be called from the fixture CTOR");
            UUT->Reset();
            Reset();
            try
            {
                test_case_running = true;
                test_case_body(UUT.get(), fx);
                test_case_running = false;
            }
            catch (...)
            {
                test_case_exception = std::current_exception();
            }
        }
    }

    void post_test_thread()
    {
        while (true)
        {
            wait(post_test_trigger);
            WaitedEvents::get().stop_expect_no_wait();
        }
    }

    void rethrow_on_exception_from_test_case()
    {
        if (test_case_exception)
        {
            std::rethrow_exception(std::exchange(test_case_exception, nullptr));
        }
    }

    void throw_on_unfinished_test_case()
    {
        if (test_case_running)
        {
            test_case_running = false;
            throw std::runtime_error("Testcase lockup detected");
        }
    }
};

template <typename UUT_T, typename Fixture>
Fixture* FixtureRunner<UUT_T, Fixture>::fx = nullptr;

// FIXTURE struct
#define UUT_FIXTURE_TYPE(UUT_NAME) EXPAND_AND_CONCAT(UUT_NAME, Fixture)
#define UUT_FIXTURE_MODULE_NAME(UUT_NAME) EXPAND_AND_QUOTE(UUT_FIXTURE_TYPE(UUT_NAME))

#define FIXTURE_DEF(UUT_NAME)                                                                                          \
    UUT_FIXTURE_TYPE(UUT_NAME);                                                                                        \
    struct UUT_NAME##FixtureHasProcess                                                                                 \
    {                                                                                                                  \
        using SC_CURRENT_USER_MODULE = UUT_FIXTURE_TYPE(UUT_NAME);                                                     \
    };                                                                                                                 \
    struct UUT_FIXTURE_TYPE(UUT_NAME)                                                                                  \
        : public ::test_utils::FixtureRunner<UUT_NAME, UUT_FIXTURE_TYPE(UUT_NAME)>                                     \
        , public UUT_NAME##FixtureHasProcess

#define FIXTURE_CTOR(UUT_NAME)                                                                                         \
    UUT_FIXTURE_TYPE(UUT_NAME)                                                                                         \
    (sc_core::sc_module_name const& fx_mn)                                                                             \
        : FixtureRunner(fx_mn)

#define INIT_UUT(UUT_NAME, ...)                                                                                        \
    do                                                                                                                 \
    {                                                                                                                  \
        UUT.reset(new UUT_NAME(sc_core::sc_module_name(#UUT_NAME), ##__VA_ARGS__));                                    \
    } while (0)

#define STRUCT_FIXTURE_REGISTER(UUT_NAME)                                                                              \
    static auto const ANONYMOUS_NAME(FIXTURE_STATIC_INIT_) =                                                           \
        ::test_utils::ElaborationFactory::get().add_module_initializer(                                                \
            []() -> decltype(UUT_FIXTURE_TYPE(UUT_NAME)::fx)                                                           \
            {                                                                                                          \
                if (!UUT_FIXTURE_TYPE(UUT_NAME)::fx)                                                                   \
                {                                                                                                      \
                    UUT_FIXTURE_TYPE(UUT_NAME)::fx =                                                                   \
                        new UUT_FIXTURE_TYPE(UUT_NAME)(UUT_FIXTURE_MODULE_NAME(UUT_NAME));                             \
                    return UUT_FIXTURE_TYPE(UUT_NAME)::fx;                                                             \
                }                                                                                                      \
                return nullptr;                                                                                        \
            })

// TEST CASES

#define FIXTURED_TEST_THREAD_IMPL(UUT_NAME, FX_NAME, TC_NAME, ANON_TC_NAME, ...)                                       \
    static void ANON_TC_NAME(UUT_NAME* const, FX_NAME* const);                                                         \
    STRUCT_FIXTURE_REGISTER(UUT_NAME);                                                                                 \
    TEST_CASE(TC_NAME, ##__VA_ARGS__)                                                                                  \
    {                                                                                                                  \
        FX_NAME::fx->run_test(ANON_TC_NAME);                                                                           \
    }                                                                                                                  \
    static void ANON_TC_NAME(UUT_NAME* const UUT, FX_NAME* const FIXTURE)

#define FIXTURED_TEST_THREAD(UUT_NAME, TC_NAME, ...)                                                                   \
    FIXTURED_TEST_THREAD_IMPL(UUT_NAME, UUT_NAME##Fixture, TC_NAME, ANONYMOUS_NAME(FIXTURE_WRAPPED_TC_), ##__VA_ARGS__)


#define EXPECT_EVENT(EVENT) ::test_utils::WaitedEvents::get().registered_wait(EVENT, __FILE__, __LINE__)

#define EXPECT_NO_EVENT(EVENT) ::test_utils::WaitedEvents::get().expect_no_wait(EVENT, __FILE__, __LINE__)

#define CHECK_READ(PORT_OR_FIFO) ::test_utils::WaitedEvents::get().registered_read(PORT_OR_FIFO, __FILE__, __LINE__)

#define CHECK_WRITE(PORT_OR_FIFO, OBJECT)                                                                              \
    ::test_utils::WaitedEvents::get().registered_write(PORT_OR_FIFO, OBJECT, __FILE__, __LINE__)

#define REQUIRE_READ(PORT_OR_FIFO, EXPECTED_OBJECT)                                                                    \
    do                                                                                                                 \
    {                                                                                                                  \
        auto read_object = CHECK_READ(PORT_OR_FIFO);                                                                   \
        decltype(read_object) read_object_exp = EXPECTED_OBJECT;                                                       \
        REQUIRE(read_object == read_object_exp);                                                                       \
    } while (0)

}// namespace test_utils