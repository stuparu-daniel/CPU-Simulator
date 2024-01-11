#define CATCH_CONFIG_RUNNER
#include "module_testing.h"
#include "pic.h"

int sc_main(int argc, char* argv[])
{
    test_utils::ElaborationFactory::get().initialize_modules();
    return Catch::Session().run(argc, argv);
}

struct FIXTURE_DEF(pic)
{
    sc_in<bool>  		ireq0; 		// interrupt request 0   	
  	sc_in<bool>  		ireq1;    	// interrupt request 1
  	sc_in<bool>  		ireq2;    	// interrupt request 2
  	sc_in<bool>  		ireq3;    	// interrupt request 3
  	sc_in<bool>  		cs;    		// chip select
  	sc_in<bool>  		rd_wr;    	// read or write
  	sc_in<bool>  		intack_cpu;    	// interrupt acknowledge from CPU
  	sc_out<bool>  		intreq;         // interrupt request to CPU		
  	sc_out<bool>  		intack;         // interrupt acknowledge to devices		
  	sc_out<unsigned>        vectno;         // vector number		

    FIXTURE_CTOR(pic)
    {
        INIT_UUT(pic);

        UUT->ireq0.bind(ireq0);
        UUT->ireq1.bind(ireq1);
        UUT->ireq2.bind(ireq2);
        UUT->ireq3.bind(ireq3);
        UUT->cs.bind(cs);
        UUT->rd_wr.bind(rd_wr);
        UUT->intack_cpu.bind(intack_cpu);

        intreq.bind(UUT->intreq);
        intack.bind(UUT->intack);
        vectno.bind(UUT->vectno);
    }
    
};

FIXTURED_TEST_THREAD(pic, "pic Module test")
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