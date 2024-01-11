#define CATCH_CONFIG_RUNNER
#include "module_testing.h"
#include "stimulus.h"

int sc_main(int argc, char* argv[])
{
    test_utils::ElaborationFactory::get().initialize_modules();
    return Catch::Session().run(argc, argv);
}

struct FIXTURE_DEF(stimulus)
{
    sc_in<sc_uint<32>>            number_i;
    sc_in<sc_uint<32>>            initial_seed_i;
    sc_out<bool>                  loadseed_o;
    sc_out<sc_uint<32>>           seed_o;
    sc_out<bool>                  reset;

    FIXTURE_CTOR(stimulus)
    {
        sc_clock clk("test_clk",1,SC_NS,1,1,SC_NS,false);
        INIT_UUT(stimulus);

        UUT->number_i.bind(number_i);
        UUT->initial_seed_i.bind(initial_seed_i);
        
        loadseed_o.bind(UUT->loadseed_o);
        seed_o.bind(UUT->seed_o);
        reset.bind(UUT->reset);
    
        UUT->CLK.bind(clk);
    }
    
};

FIXTURED_TEST_THREAD(stimulus, "stimulus Module test")
{

    WHEN("Data is written to the input port")
    {
        //CHECK_WRITE(FIXTURE->mod_in, value);

        THEN("module writes back new value")
        {
            //REQUIRE(FIXTURE->mod_out.read() == value);
        }
        
    }

}