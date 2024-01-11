#include "paging.h"


void paging::entry()
{
 int		address=0;
 int	 	dataout_tmp =0;

 while (true) {
    	do { wait(); } while ( !(paging_csin == true) ); 
	address = logical_address.read();

	if (address >= 5) {
    		if (paging_wein.read() == true) { 	// Write operation
			paging_dout.write(paging_din.read());
			paging_csout.write(true);
			paging_weout.write(true);
			physical_address.write(logical_address.read());
      			wait();
			paging_csout.write(false);
			paging_weout.write(false);
			
    		}
    		else { 					// Read operation
			paging_csout.write(true);
			paging_weout.write(false);
			physical_address.write(logical_address.read());
			wait();
			do { wait(); } while ( !(icache_validin == true) );
			dataout_tmp = icache_din.read();
			
			if (PRINT_PU){
   				cout << "-----------------------" << endl;
				printf( "PAGE : mem=%x\n",dataout_tmp);
   				cout << "PAGE : " ;
   				cout << " at CSIM " << sc_time_stamp() << endl;
   				cout << "-----------------------" << endl;
			}

			dataout.write(icache_din.read());
			data_valid.write(true);
			paging_csout.write(false);
			wait(); 
			data_valid.write(false);
			wait();
    		}    
	}
 }
} // end of entry function

