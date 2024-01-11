#include "systemc.h"
#include "directive.h"

struct mmxu : sc_module {
  sc_in<bool>   	       	mmx_valid;	// MMX unit enable
  sc_in<int>  	      		opcode;		// opcode
  sc_in<signed int>        	mmxa;		// operand A
  sc_in<signed int>        	mmxb;		// operand B
  sc_in<unsigned>        	dest;		// Destination register number
  sc_out<signed int>        	mmxdout;	// MMX output
  sc_out<bool>   	       	mmxout_valid;	// MMX output valid
  sc_out<unsigned>        	mmxdestout;	// destination number
  sc_in_clk 			CLK;


  // can make it asynchronous process to speed up simulation
  SC_CTOR(mmxu) {
      SC_CTHREAD(entry, CLK.pos());
  }
  
  void entry();
};

// EOF
