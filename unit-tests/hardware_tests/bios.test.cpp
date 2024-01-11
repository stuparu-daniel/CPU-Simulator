#define CATCH_CONFIG_RUNNER
#include "module_testing.h"
#include "bios.h"

int sc_main(int argc, char* argv[])
{
    test_utils::ElaborationFactory::get().initialize_modules();
    return Catch::Session().run(argc, argv);
}

struct FIXTURE_DEF(bios)
{
    sc_in<unsigned > 		datain; 	// modified instruction
  	sc_in<bool> 			cs;    		// chip select
  	sc_in<bool>  			we;    		// write enable for SMC
  	sc_in<unsigned >  		addr;  		// physical address

  	sc_out<unsigned > 		dataout;  	// ram data out
  	sc_out<bool> 			bios_valid; 	// out valid
  	sc_out<bool>	 		stall_fetch; 	// stall fetch if output not valid
	sc_in_clk 			CLK;
    

    FIXTURE_CTOR(bios)
    {
        sc_clock clk("test_clk",1,SC_NS,1,1,SC_NS,false);
        INIT_UUT(bios);

        UUT->datain.bind(datain);
        UUT->cs.bind(cs);
        UUT->we.bind(we);
        UUT->addr.bind(addr);
        
        dataout.bind(UUT->dataout);
        bios_valid.bind(UUT->bios_valid);
        stall_fetch.bind(UUT->stall_fetch);
    
        UUT->CLK.bind(clk);
    }
    
};

FIXTURED_TEST_THREAD(bios, "bios Module test")
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