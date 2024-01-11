/*****************************************************************************
 
  pic.h -- Programmable Interrupt Unit.

 *****************************************************************************/
 
#include "systemc.h"

struct pic : sc_module { 
  	sc_in<bool>  		ireq0; 		// interrupt request 0   	
  	sc_in<bool>  		ireq1;    	// interrupt request 1
  	sc_in<bool>  		ireq2;    	// interrupt request 2
  	sc_in<bool>  		ireq3;    	// interrupt request 3
  	sc_in<bool>  		cs;    		// chip select
  	sc_in<bool>  		rd_wr;    	// read or write
  	sc_in<bool>  		intack_cpu;    	// interrupt acknowledge from CPU
  	sc_out<bool>  		intreq;         // interrupt request to CPU		
  	sc_out<bool>  		intack;         // interrupt acknowledge to devices		
  	sc_out<unsigned>        vectno;         // vector number		


  //Constructor 
  SC_CTOR(pic) {
      SC_METHOD(entry);
      dont_initialize();
      sensitive << ireq0 << ireq1 << ireq2 << ireq3 ;
  }


  // Process functionality in member function below
  void entry();
};


