#define CATCH_CONFIG_RUNNER
#include "module_testing.h"
#include "rng.h"

int sc_main(int argc, char* argv[])
{
    test_utils::ElaborationFactory::get().initialize_modules();
    return Catch::Session().run(argc, argv);
}

struct FIXTURE_DEF(rng)
{
    sc_in<bool>                   loadseed_i;
    sc_in<sc_uint<32>>            seed_i;
    sc_in<bool>                   reset;

    sc_out<sc_uint<32>>           number_o;


    FIXTURE_CTOR(rng)
    {
        sc_clock clk("test_clk",1,SC_NS,1,1,SC_NS,false);
        INIT_UUT(rng);

        UUT->loadseed_i.bind(loadseed_i);
        UUT->seed_i.bind(seed_i);
        UUT->reset.bind(reset);
        
        number_o.bind(UUT->number_o);

        UUT->CLK.bind(clk);
    }
    
};

FIXTURED_TEST_THREAD(rng, "rng Module test")
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