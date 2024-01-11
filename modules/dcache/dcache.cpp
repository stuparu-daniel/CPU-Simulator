#include "dcache.h"

void dcache::entry()
{
  unsigned int	address;			// address to DataCache
  unsigned int  dest_tmp = 0;


  while (true) {
    	do { wait(); } while ( !(cs == true) ); 
     	dest_tmp = dest.read();
    	address = addr.read();
    	if (we.read() == true) { 		// Write operation
      		wait();
      		out_valid.write(false);
      		dmemory[address] = datain.read();
      		dsmemory[address] = statein.read();
      		dtagmemory[address] = addr.read();
		cout << "\t\t\t\t\t\t\t-------------------------------" << endl;
		printf("\t\t\t\t\t\t\tDCU :St %x->mem[%d]", dmemory[address], address);
		cout << " at CSIM " << sc_time_stamp() << endl;
		cout << "\t\t\t\t\t\t\t-------------------------------" << endl;
		wait();
    	}
    	else { 					// Read operation
		wait(); 	
        	dataout.write(dmemory[address]);
		stateout.write(dsmemory[address]);
		destout.write(dest_tmp);
        	out_valid.write(true);
		cout << "\t\t\t\t\t\t\t-------------------------------" << endl;
		printf("\t\t\t\t\t\t\tDCU :ld %d<-mem[%d]->R%d\n", dmemory[address], address, dest_tmp);
		printf("\t\t\t\t\t\t\tDCU :Tag = 0x%x", dtagmemory[address]);
		if (dsmemory[address] == 3) {
			printf(" (M)");
		} else if (dsmemory[address] == 2) {
			printf(" (E)");
		} else  if (dsmemory[address] == 1) {
			printf(" (S)");
		} else if (dsmemory[address] == 0) {
			printf(" (I)");
		} else 
			printf(" (X)");
		cout << " at CSIM " << sc_time_stamp() << endl;
		cout << "\t\t\t\t\t\t\t-------------------------------" << endl;
        	wait();
        	out_valid.write(false);
        	wait();
    	}    
  }
} // end of entry function

