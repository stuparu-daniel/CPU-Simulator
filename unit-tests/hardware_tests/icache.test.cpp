#define CATCH_CONFIG_RUNNER
#include "module_testing.h"
#include "icache.h"

int sc_main(int argc, char* argv[])
{
    test_utils::ElaborationFactory::get().initialize_modules();
    return Catch::Session().run(argc, argv);
}

struct FIXTURE_DEF(icache)
{
    sc_in<unsigned >  	datain; 	// modified instruction
  	sc_in<bool>  		cs;    		// chip select
  	sc_in<bool>  		we;    		// write enable for SMC
  	sc_in<unsigned >  	addr;  		// address
  	sc_in<bool>  		ld_valid;	// load valid    
  	sc_in<signed>  		ld_data;    	// load data value
  	sc_out<unsigned >  	dataout;  	// ram data out
  	sc_out<bool>  		icache_valid; 	// output valid
  	sc_out<bool>  		stall_fetch; 	// stall fetch if busy

    FIXTURE_CTOR(icache)
    {
        sc_clock clk("test_clk",1,SC_NS,1,1,SC_NS,false);
        INIT_UUT(icache);

        UUT->datain.bind(datain);
        UUT->cs.bind(cs);
        UUT->we.bind(we);
        UUT->addr.bind(addr);
        UUT->ld_valid.bind(ld_valid);
        UUT->ld_data.bind(ld_data);
        
        dataout.bind(UUT->dataout);
        icache_valid.bind(UUT->icache_valid);
        stall_fetch.bind(UUT->stall_fetch);
    
        UUT->CLK.bind(clk);
    }
    
};

FIXTURED_TEST_THREAD(icache, "icache Module test")
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