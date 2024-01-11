#define CATCH_CONFIG_RUNNER
#include "module_testing.h"
#include "floating.h"

int sc_main(int argc, char* argv[])
{
    test_utils::ElaborationFactory::get().initialize_modules();
    return Catch::Session().run(argc, argv);
}

struct FIXTURE_DEF(floating)
{
    sc_in<bool>   	       	in_valid;	// input valid bit
    sc_in<int>  	 	     	opcode;		// opcode
    sc_in<signed int>        	floata;		// operand A
    sc_in<signed int>        	floatb;		// operand B
    sc_in<unsigned>        	dest;		// write to which register
    sc_out<signed int>        		fdout;		// FPU output
    sc_out<bool>   	       		fout_valid;	// output valid
    sc_out<unsigned>        		fdestout;	// write to which register
    
    FIXTURE_CTOR(floating)
    {
        sc_clock clk("test_clk",1,SC_NS,1,1,SC_NS,false);
        INIT_UUT(floating);

        UUT->in_valid.bind(in_valid);
        UUT->opcode.bind(opcode);
        UUT->floata.bind(floata);
        UUT->floatb.bind(floatb);
        UUT->dest.bind(dest);
        
        fdout.bind(UUT->fdout);
        fout_valid.bind(UUT->fout_valid);
        fdestout.bind(UUT->fdestout);

        UUT->CLK.bind(clk);
    }
    
};

FIXTURED_TEST_THREAD(floating, "floating Module test")
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