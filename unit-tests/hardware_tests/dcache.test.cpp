#define CATCH_CONFIG_RUNNER
#include "module_testing.h"
#include "dcache.h"

int sc_main(int argc, char* argv[])
{
    test_utils::ElaborationFactory::get().initialize_modules();
    return Catch::Session().run(argc, argv);
}

struct FIXTURE_DEF(dcache)
{
    sc_in<signed> 		datain; 	// input data
  	sc_in<unsigned>  	statein; 	// input state bit MESI(=3210)
  	sc_in<bool>  		cs;    		// chip select
  	sc_in<bool>  		we;    		// write enable 
  	sc_in<unsigned >  	addr;  		// address
  	sc_in<unsigned>  	dest;    	// write back to which register
  	sc_out<unsigned>  	destout;    	// write back to which register
  	sc_out<signed>  	dataout;  	// dataram data out
  	sc_out<bool>  		out_valid;    	// output valid
  	sc_out<unsigned>  	stateout;  	// state output

    FIXTURE_CTOR(dcache)
    {
        sc_clock clk("test_clk",1,SC_NS,1,1,SC_NS,false);
        INIT_UUT(dcache);

        UUT->datain.bind(datain);
        UUT->statein.bind(statein);
        UUT->cs.bind(cs);
        UUT->we.bind(we);
        UUT->addr.bind(addr);
        UUT->dest.bind(dest);
        
        destout.bind(UUT->destout);
        dataout.bind(UUT->dataout);
        out_valid.bind(UUT->out_valid);
        stateout.bind(UUT->stateout);
    
        UUT->CLK.bind(clk);
    }
    
};

FIXTURED_TEST_THREAD(dcache, "dcache Module test")
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