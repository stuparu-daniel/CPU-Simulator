#define CATCH_CONFIG_RUNNER
#include "module_testing.h"
#include "paging.h"

int sc_main(int argc, char* argv[])
{
    test_utils::ElaborationFactory::get().initialize_modules();
    return Catch::Session().run(argc, argv);
}

struct FIXTURE_DEF(paging)
{
    sc_in<unsigned >   paging_din; 	// input data       
    sc_in<bool>           paging_csin;    	// chip select        
    sc_in<bool>           paging_wein;    	// write enable       
    sc_in<unsigned >   logical_address; 	// logical address  
    sc_in<unsigned >   icache_din;      	// data from BIOS/icache
    sc_in<bool>           icache_validin;   // data valid bit 
    sc_in<bool>           icache_stall;     // stall IFU if busy
    sc_out<unsigned >  paging_dout;            // output data
    sc_out<bool>  	      paging_csout;           // output cs to cache/BIOS
    sc_out<bool>  	      paging_weout;           // write enable to cache/BIOS
    sc_out<unsigned >  physical_address;       // physical address 
    sc_out<unsigned >  dataout;        	      // dataout from memory
    sc_out<bool>  	      data_valid;             // data valid
    sc_out<bool>  	      stall_ifu;              // stall IFU if busy

    FIXTURE_CTOR(paging)
    {
        sc_clock clk("test_clk",1,SC_NS,1,1,SC_NS,false);
        INIT_UUT(paging);

        UUT->paging_din.bind(paging_din);
        UUT->paging_csin.bind(paging_csin);
        UUT->paging_wein.bind(paging_wein);
        UUT->logical_address.bind(logical_address);
        UUT->icache_din.bind(icache_din);
        UUT->icache_validin.bind(icache_validin);
        UUT->icache_stall.bind(icache_stall);
        
        paging_dout.bind(UUT->paging_dout);
        paging_csout.bind(UUT->paging_csout);
        paging_weout.bind(UUT->paging_weout);
        physical_address.bind(UUT->physical_address);
        dataout.bind(UUT->dataout);
        data_valid.bind(UUT->data_valid);
        stall_ifu.bind(UUT->stall_ifu);
    
        UUT->CLK.bind(clk);
    }
    
};

FIXTURED_TEST_THREAD(paging, "paging Module test")
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