#include "bios.h"



void bios::entry()
{
  unsigned address;

  while (true) {
	do { wait(); } while ( !(cs == true) );
	address = addr.read();
	if (address < BOOT_LENGTH) {		// in BOOTING STAGE
    		if (we.read() == true) { // Write operation
      			wait(wait_cycles-1);
      			imemory[address] = datain.read();
    		}
    		else { // Read operation
			if (wait_cycles > 2) {
				wait(wait_cycles-2); // Introduce delay needed
			}
			dataout.write(imemory[address]);

			if (PRINT_BIOS) {
				printf("------------------------\n");
				printf("BIOS: fetching mem[%d]\n", address);
				printf("BIOS: (%0x)", imemory[address]);
 				cout.setf(ios::dec,ios::basefield);
   				cout << " at CSIM " << sc_time_stamp() << endl;
				printf("------------------------\n");
			}

			bios_valid.write(true);
      			wait();
			bios_valid.write(false);
			wait();
    		}
	} else {
		bios_valid.write(false);
		wait();
	}
  }
} // end of entry function
