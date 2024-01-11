/*****************************************************************************
 
  icache.cpp -- Instruction Cache Unit.

 *****************************************************************************/

#include "icache.h"


void icache::entry()
{
    unsigned int 	address;

 while (true) {
    	do { wait(); } while ( !(cs == true) ); 
    	address = addr.read();
	if (address == BOOT_LENGTH) {
		 printf("ICU ALERT: *********************************************************************\n");
		 printf("         : *****************************AFTER RESET*****************************\n");
		 printf("ICU ALERT: *********************************************************************\n");
	}
	if (address >= BOOT_LENGTH) {
		if (ld_valid.read() == true) {
			pid = ld_data.read();
			printf("------------------------\n");
			printf("ICU: PID = [%d]", pid); 
                       	cout << " at CSIM " << sc_time_stamp() << endl;
			printf("------------------------\n");
      			wait();
      			wait();
		}
    		if (we.read() == true) { // Write operation
      			wait();
			if (address < MAX_CODE_LENGTH)
                          icmemory[address] = datain.read();
                        else
                          printf("ICU ALERT: **MEMORY OUT OF RANGE**\n");
      			wait();
    		}
    		else { // Read operation
			wait(); // Introduce delay needed
			if (address >= MAX_CODE_LENGTH) {
				dataout.write(0xffffffff);
				printf("ICU ALERT: **MEMORY OUT OF RANGE**\n");
			}
                        else
        		  dataout.write(icmemory[address]);

			icache_valid.write(true);

			if (PRINT_ICU) {
				printf("------------------------\n");
				printf("ICU: fetching mem[%d]\n", address);
                                if (address < MAX_CODE_LENGTH) 
				  printf("ICU: (%0x)", icmemory[address]); 
       		                cout.setf(ios::dec,ios::basefield);
                        	cout << " at CSIM " << sc_time_stamp() << endl;
				printf("------------------------\n");
			}

      			wait();
			icache_valid.write(false);
      			wait();
    		}    
	}
 }
} // end of entry function

