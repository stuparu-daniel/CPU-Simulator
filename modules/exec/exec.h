
/*****************************************************************************
 
  exec.h -- Integer Execution Unit.
 
 *****************************************************************************/


#include "systemc.h"
#include "directive.h"

struct exec : sc_module {
  sc_in<bool>   	       	reset;			// reset not used.
  sc_in<bool>   	       	in_valid;		// input valid
  sc_in<int>  	      		opcode;			// opcode from ID
  sc_in<bool>  	      		negate;			// not implemented
  sc_in<int>        		add1;			// not implemented
  sc_in<bool>   	     	shift_sel;		// not implemented
  sc_in<signed int>        	dina;			// operand A
  sc_in<signed int>        	dinb;			// operand B
  sc_in<bool>        		forward_A;		// data forwarding A valid
  sc_in<bool>        		forward_B;		// data forwarding B valid
  sc_in<unsigned>        	dest;			// destination register number
  sc_out<bool>              	C;			// Carry bit 
  sc_out<bool>              	V;			// Overflow bit
  sc_out<bool>              	Z;			// Zero bit
  sc_out<signed int>        	dout;			// output data
  sc_out<bool>   	       	out_valid;		// output valid
  sc_out<unsigned>        	destout;		// write to which registers?
  sc_in_clk 			CLK;


  SC_CTOR(exec) {
      SC_CTHREAD(entry, CLK.pos());
  }
  
  void entry();
};

// EOF
