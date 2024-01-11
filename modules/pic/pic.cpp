#include "pic.h"

void pic::entry(){

	if (ireq0.read() == true) {
		intreq.write(true);
		vectno.write(0);
	} else if (ireq1.read() == true) {
			intreq.write(true);
			vectno.write(1);
		} else if (ireq2.read() == true) {
				intreq.write(true);
				vectno.write(2);
			} else if (ireq3.read() == true) {
						intreq.write(true);
						vectno.write(2);
				} else {
				} 
	if ((intack_cpu.read() == true) && (cs.read() == true)) {
			intreq.write(false);
	}
  }

// EOF

