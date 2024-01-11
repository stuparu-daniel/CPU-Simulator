/*****************************************************************************
 
  icache.h -- Instruction Cache Unit.

 *****************************************************************************/

#include "systemc.h"
#include "directive.h"

#define BOOT_LENGTH 5
#define MAX_CODE_LENGTH 500

struct icache : sc_module { 
  	sc_in<unsigned >  	datain; 	// modified instruction
  	sc_in<bool>  		cs;    		// chip select
  	sc_in<bool>  		we;    		// write enable for SMC
  	sc_in<unsigned >  	addr;  		// address
  	sc_in<bool>  		ld_valid;	// load valid    
  	sc_in<signed>  		ld_data;    	// load data value
  	sc_out<unsigned >  	dataout;  	// ram data out
  	sc_out<bool>  		icache_valid; 	// output valid
  	sc_out<bool>  		stall_fetch; 	// stall fetch if busy
  	sc_in_clk 		CLK;

  // Parameter
  unsigned *icmemory;	 				// icache data memory
  unsigned *ictagmemory; 				// icache tag memory
  signed int pid;	 				// process ID

  int wait_cycles; // Number of cycles it takes to access imemory

  void init_param(int given_delay_cycles) {
    wait_cycles = given_delay_cycles;
  }
 
  //Constructor
  SC_CTOR(icache) {
        SC_CTHREAD(entry, CLK.pos());

	// initialize instruction icmemory from external file
	pid = 0;
	FILE *fp = fopen("icache.img","r");
	int size=0;
	unsigned int mem_word;
  	icmemory 	= new unsigned[MAX_CODE_LENGTH];
  	ictagmemory 	= new unsigned[MAX_CODE_LENGTH];
	for (size = 0; size < MAX_CODE_LENGTH; size++) {	// initialize bad data
		icmemory[size] = 0xeeeeeeee;
		ictagmemory[size] = 0xeeeeeeee;
	}
	size = 0;
	while (fscanf(fp,"%x", &mem_word) != EOF) {
		icmemory[size] = mem_word;
		ictagmemory[size] = size;
		size++;
	}
  }

  // Process functionality in member function below
  void entry();
};


