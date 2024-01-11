#include "systemc.h"
#include "directive.h"

struct dcache : sc_module { 
  	sc_in<signed> 		datain; 	// input data
  	sc_in<unsigned>  	statein; 	// input state bit MESI(=3210)
  	sc_in<bool>  		cs;    		// chip select
  	sc_in<bool>  		we;    		// write enable 
  	sc_in<unsigned >  	addr;  		// address
  	sc_in<unsigned>  	dest;    	// write back to which register
  	sc_out<unsigned>  	destout;    	// write back to which register
  	sc_out<signed>  	dataout;  	// dataram data out
  	sc_out<bool>  		out_valid;    	// output valid
  	sc_out<unsigned>  	stateout;  	// state output
        sc_in_clk 		CLK;


  // Parameter
  unsigned *dmemory;	 				// data memory
  unsigned *dsmemory;	 				// data state memory
  unsigned *dtagmemory;	 				// tag memory
  int wait_cycles; 					// cycles # it takes to access dmemory

  void init_param(int given_delay_cycles) {
    wait_cycles = given_delay_cycles; 
  }
 
  //Constructor 
  SC_CTOR(dcache) {
        SC_CTHREAD(entry, CLK.pos());

	// initialize instruction dmemory from external file
	FILE *fp = fopen("dcache.img","r");
	int size=0;
	int i=0;
	unsigned mem_word;
  	dmemory = new unsigned[4000];
  	dsmemory = new unsigned[4000];
  	dtagmemory = new unsigned[4000];
	printf("** ALERT ** DCU: initialize Data Cache\n");
	while (fscanf(fp,"%x", &mem_word) != EOF) {
		dmemory[size] = mem_word;
		dsmemory[size] = 0;
		dtagmemory[size] = size;
		size++;
	}
	for (i=size; i<4000; i++) {
		dtagmemory[i] = 0xdeadbeef;
		dmemory[i] = 0xdeadbeef;
		dsmemory[i] = 0;
	}
  }

  // Process functionality in member function below
  void entry();
};


