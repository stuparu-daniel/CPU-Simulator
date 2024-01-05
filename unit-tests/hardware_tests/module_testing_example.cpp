#define CATCH_CONFIG_RUNNER
#include <module_testing.h>


/*
 * Writing our own main function is needed to call initialize_modules().
 * Be sure to add this to exactly one of the source files,
 * and remove #define CATCH_CONFIG_RUNNER from other files.
 */
int main(int argc, char* argv[])
{
    test_utils::ElaborationFactory::get().initialize_modules();
    return Catch::Session().run(argc, argv);
}


/*
 * The following is an example module for demo purposes.
 * Normally this will be an external module in a separate header.
 */
struct Module : public sc_module
{
public:
    SC_HAS_PROCESS(Module);

    /*
     * Module constructor, can have any number of arguments besides name.
     */
    Module(sc_module_name name, int param)
        : sc_module(name)
    {
        internalParam = param;
        SC_THREAD(moduleThread);
    }

    /*
     * Reset function needs to be present, because this is called
     * in between successive test case runs.
     */
    void Reset()
    {
        // Reset state, clear fifos, etc
    }

    static constexpr int FIFO_SIZE = 8;
    /*
     * Example of two ports of this module
     */
    sc_port<sc_fifo_in_if<int>> in_port;
    sc_fifo<int> out_if{ FIFO_SIZE };

private:
    int internalParam;

    /*
     * Everything read from the in port will be written to out port
     * with a modified value (set in the constructor).
     */
    void moduleThread()
    {
        while (true)
        {
            auto val = in_port->read();
            val += internalParam;
            out_if.write(val);
        }
    }
};


/*
 * The following is necessary to create a FIXTURE for the module/unit under test (UUT)
 * A test fixture mocks everything around the module, connecting ports and provides reg bank:
 *  __________________________________
 * |             Fixture              |
 * |    __________________________    |
 * |   |        __________        |   |
 * |   | Ports |  Module  | Ports |   |
 * |   | ----> |__________| ----> |   |
 * |   |                          |   |
 *
 * First, declare a struct FIXTURE_DEF(Your_module_name) that
 * will contain the fixture for the UUT.
 */
struct FIXTURE_DEF(Module)
{
    /*
     * Declare here any ports that should be connected to the module.
     * In case of IDL generated IO, you can use the IDL::*_tb_io<>
     * for the reverse of the module IDL interface.
     */
    sc_fifo<int> module_in{ Module::FIFO_SIZE };
    sc_port<sc_fifo_in_if<int>> module_out;

    /*
     * Declare the constructor of the fixture struct
     * This will be created only once, during initialize_modules(),
     * because System-C only allows creation during the elaboration phase.
     */
    FIXTURE_CTOR(Module)
    {
        /*
         * Call INIT_UUT with the necessary arguments, omitting the name argument.
         * This will create a member variable called UUT.
         */
        INIT_UUT(Module, offset);

        /*
         * Bind or disable the ports of the module.
         */
        UUT->in_port.bind(module_in);
        module_out.bind(UUT->out_if);
    }

    const int offset = 1;
};


/*
 * Instead of TEST_CASE, use FIXTURED_TEST_THREAD to test the module.
 * This will be called within a System-C thread, such that wait() works as expected.
 * Inside this function, there is a FIXTURE variable available, pointing to
 * the instance of the fixture class above, as well as an UUT variable,
 * pointing to the Module under test.
 */
FIXTURED_TEST_THREAD(Module, "Example Module test")
{
    /*
     * All the Catch2 functionality is available in here, please
     * refer to the Catch2 documentation on github for more details.
     *
     * Usually, the test will set up register values here and initialize data.
     * Normal functions can be called directly on the UUT from here, like any other unit test.
     */

    const int data = 42;

    WHEN("Data is written to the input port")
    {
        // Avoid reading/writing the ports/fifos directly
        // FIXTURE->module_in.write(data);
        /*
         * Writing to a fifo could block, so we need to use EXPECT_WRITE()
         * which will report any blocked write as a failure.
         * The signature is: EXPECT_WRITE(port_or_fifo, data)
         */
        CHECK_WRITE(FIXTURE->module_in, data);
        /*
         * Alternatively, here we could have used the non-blocking
         * FIXTURE->module_in.nb_write(data);
         */

        THEN("module writes back new value")
        {
            /*
             * We need to use CHECK_READ() to read the port,
             * so that no write from the module will trigger a test failure.
             * Signature: auto CHECK_READ(port_or_fifo)
             */
            auto out_value = CHECK_READ(FIXTURE->module_out);
            REQUIRE(data + FIXTURE->offset == out_value);
        }

        /*
         * The following demonstrates the same result using event signaling
         */
        THEN("module writes back and out_if gets signaled")
        {
            /*
             * We can also wait for events like the data_written_event()
             * EXPECT_EVENT(event) reports any non-fired event as a test failure.
             * This can be used with any type of sc_event.
             */
            int out_value = 0;
            EXPECT_EVENT(UUT->out_if.data_written_event());
            REQUIRE(FIXTURE->module_out->nb_read(out_value));

            REQUIRE(data + FIXTURE->offset == out_value);
        }
    }

    /*
     * Finally, checking that the fifos are empty
     */
    REQUIRE(FIXTURE->module_in.num_available() == 0);
    REQUIRE(UUT->out_if.num_available() == 0);
    /*
     * A better way to check nothing else happens is to add a check
     * that no write event occurs until the end of the simulation.
     * EXPECT_NO_EVENT(event) adds a background wait() that is checked not to fire.
     */
    EXPECT_NO_EVENT(UUT->out_if.data_written_event());
}
