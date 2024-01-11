#define CATCH_CONFIG_RUNNER
#include "module_testing.h"
#include "mmxu.h"

int sc_main(int argc, char* argv[])
{
    test_utils::ElaborationFactory::get().initialize_modules();
    return Catch::Session().run(argc, argv);
}

struct FIXTURE_DEF(mmxu)
{
    sc_in<bool>   	       	mmx_valid;	// MMX unit enable
    sc_in<int>  	      		opcode;		// opcode
    sc_in<signed int>        	mmxa;		// operand A
    sc_in<signed int>        	mmxb;		// operand B
    sc_in<unsigned>        	dest;		// Destination register number
    sc_out<signed int>        	mmxdout;	// MMX output
    sc_out<bool>   	       	mmxout_valid;	// MMX output valid
    sc_out<unsigned>        	mmxdestout;	// destination number

    FIXTURE_CTOR(mmxu)
    {
        sc_clock clk("test_clk",1,SC_NS,1,1,SC_NS,false);
        INIT_UUT(mmxu);

        UUT->mmx_valid.bind(mmx_valid);
        UUT->opcode.bind(opcode);
        UUT->mmxa.bind(mmxa);
        UUT->mmxb.bind(mmxb);
        UUT->dest.bind(dest);
        
        mmxdout.bind(UUT->mmxdout);
        mmxout_valid.bind(UUT->mmxout_valid);
        mmxdestout.bind(UUT->mmxdestout);
    
        UUT->CLK.bind(clk);
    }
    
};

FIXTURED_TEST_THREAD(mmxu, "mmxu Module test")
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