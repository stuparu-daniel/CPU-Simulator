#include "systemc.h"
#include "directive.h"

#define BOOT_LENGTH  5

struct bios : sc_module {
  	sc_in<unsigned > 		datain; 	// modified instruction
  	sc_in<bool> 			cs;    		// chip select
  	sc_in<bool>  			we;    		// write enable for SMC
  	sc_in<unsigned >  		addr;  		// physical address

  	sc_out<unsigned > 		dataout;  	// ram data out
  	sc_out<bool> 			bios_valid; 	// out valid
  	sc_out<bool>	 		stall_fetch; 	// stall fetch if output not valid
	sc_in_clk 			CLK;

  // Parameter
  unsigned *imemory;	 			// BIOS program data memory
  unsigned *itagmemory;	 			// program tag memory (NOT USED)
  int wait_cycles; 				// Cycle # it takes to access memory

  void init_param(int given_delay_cycles) {
    wait_cycles = given_delay_cycles;
  }

  //Constructor
  SC_CTOR(bios) {
        SC_CTHREAD(entry, CLK.pos());

	// initialize instruction imemory from external file
	FILE *fp = fopen("bios.img","r");
	int size=0;
	unsigned mem_word;
  	imemory 	= new unsigned[4000];
  	itagmemory 	= new unsigned[4000];
	printf("** ALERT ** BIOS: initialize BIOS\n");
	for (size = 0; size < 4000; size++) {	// initialize bad data
		imemory[size] = 0xffffffff;
		itagmemory[size] = 0xffffffff;
	}
	size = 0;
	while (fscanf(fp,"%x\n", &mem_word) != EOF) {
		imemory[size] = mem_word;
		itagmemory[size] = size;
		size++;
	}
  }

  // Process functionality in member function below
  void entry();
};
