#define CATCH_CONFIG_RUNNER
#include "module_testing.h"
#include "exec.h"

int sc_main(int argc, char* argv[])
{
    test_utils::ElaborationFactory::get().initialize_modules();
    return Catch::Session().run(argc, argv);
}

//creare fixture
//inlocuit cu nume modul
struct FIXTURE_DEF(exec)
{
    //declarare porturi
    sc_inout<bool>   	       	reset;			// reset not used.
    sc_inout<bool>   	       	in_valid;		// input valid
    sc_inout<int>  	      		opcode;			// opcode from ID
    sc_inout<bool>  	      		negate;			// not implemented
    sc_inout<int>        		add1;			// not implemented
    sc_inout<bool>   	     	shift_sel;		// not implemented
    sc_inout<signed int>        	dina;			// operand A
    sc_inout<signed int>        	dinb;			// operand B
    sc_inout<bool>        		forward_A;		// data forwarding A valid
    sc_inout<bool>        		forward_B;		// data forwarding B valid
    sc_inout<unsigned>        	dest;			// destination register number
    sc_out<bool>              	C;			// Carry bit 
    sc_out<bool>              	V;			// Overflow bit
    sc_out<bool>              	Z;			// Zero bit
    sc_out<signed int>        	dout;			// output data
    sc_out<bool>   	       	out_valid;		// output valid
    sc_out<unsigned>        	destout;		// write to which registers?
    //sc_in_clk 			CLK;
    

    //constructor
    FIXTURE_CTOR(exec)
    {
        sc_clock clk("test_clk",1,SC_NS,1,1,SC_NS,false);
        INIT_UUT(exec);

        //bind ports
        UUT->reset.bind(reset);
        UUT->in_valid.bind(in_valid);
        UUT->opcode.bind(opcode);
        UUT->negate.bind(negate);
        UUT->add1.bind(add1);
        UUT->shift_sel.bind(shift_sel);
        UUT->dina.bind(dina);
        UUT->dinb.bind(dinb);
        UUT->forward_A.bind(forward_A);
        UUT->forward_B.bind(forward_B);
        UUT->dest.bind(dest);
        
        C.bind(UUT->C);
        V.bind(UUT->V);
        Z.bind(UUT->Z);
        dout.bind(UUT->dout);
        out_valid.bind(UUT->out_valid);
        destout.bind(UUT->destout);

        UUT->CLK.bind(clk);
    }
    
};

//asta e folosit pt a testa modulul
FIXTURED_TEST_THREAD(exec, "exec/alu Module test")
{
    //initializare date
    const int data = 3;
    

    WHEN("Data is written to the input port")
    {
        //da valoare @ input
        CHECK_WRITE(FIXTURE->dina, 1);
        CHECK_WRITE(FIXTURE->dinb, 1);
        CHECK_WRITE(FIXTURE->in_valid, 1);
        CHECK_WRITE(FIXTURE->opcode, data);
        
        THEN("addition without carry test")
        {
            REQUIRE(FIXTURE->dout.read() == 2);
            REQUIRE(FIXTURE->out_valid.read() == 1);
        }
        
        CHECK_WRITE(FIXTURE->opcode, 4);
    
        THEN("substraction without carry test")
        {
            REQUIRE(FIXTURE->dout.read() == 0);
            REQUIRE(FIXTURE->out_valid.read() == 1);
        }
    }

}