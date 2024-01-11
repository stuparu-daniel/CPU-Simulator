#include "systemc.h"
#include "directive.h"

struct paging : sc_module {
        sc_in<unsigned >   paging_din; 	// input data       
        sc_in<bool>           paging_csin;    	// chip select        
        sc_in<bool>           paging_wein;    	// write enable       
        sc_in<unsigned >   logical_address; 	// logical address  
        sc_in<unsigned >   icache_din;      	// data from BIOS/icache
        sc_in<bool>           icache_validin;   // data valid bit 
        sc_in<bool>           icache_stall;     // stall IFU if busy

        sc_out<unsigned >  paging_dout;            // output data
        sc_out<bool>  	      paging_csout;           // output cs to cache/BIOS
        sc_out<bool>  	      paging_weout;           // write enable to cache/BIOS
        sc_out<unsigned >  physical_address;       // physical address 
        sc_out<unsigned >  dataout;        	      // dataout from memory
        sc_out<bool>  	      data_valid;             // data valid
        sc_out<bool>  	      stall_ifu;              // stall IFU if busy
	sc_in_clk 	      CLK;

        signed int pid_reg;             //CPU process ID register      

  SC_CTOR(paging) {
      SC_CTHREAD(entry, CLK.pos());
      pid_reg = 0;
  }
  
  void entry();
};

// EOF
