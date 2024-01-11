/*****************************************************************************
 
  stimulus.cpp -- Hardware Sensor Seed Provider.

 *****************************************************************************/

#include "stimulus.h"

void stimulus::run_stimulus () {
    reset.write(0);
    reset.write(1);
    
    loadseed_o.write(1);
    seed_o.write(number_i.read() | initial_seed_i.read());
    loadseed_o.write(0);

}