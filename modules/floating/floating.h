#include "systemc.h"
#include "directive.h"

struct floating : sc_module {
  sc_in<bool>   	       	in_valid;	// input valid bit
  sc_in<int>  	 	     	opcode;		// opcode
  sc_in<signed int>        	floata;		// operand A
  sc_in<signed int>        	floatb;		// operand B
  sc_in<unsigned>        	dest;		// write to which register
  sc_out<signed int>        		fdout;		// FPU output
  sc_out<bool>   	       		fout_valid;	// output valid
  sc_out<unsigned>        		fdestout;	// write to which register
  sc_in_clk 			CLK;


  SC_CTOR(floating) {
      SC_CTHREAD(entry, CLK.pos());
  }

  
  void entry();
};

// EOF
