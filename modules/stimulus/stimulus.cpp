#include "stimulus.h"

void stimulus::run_stimulus () {
  wait(CLK->posedge_event());
  reset.write(0);
  wait(CLK->posedge_event());
  reset.write(1);
  wait(CLK->posedge_event());
  loadseed_o.write(1);
  seed_o.write (0x12678);
  wait(CLK->posedge_event());
  loadseed_o.write(0);
}