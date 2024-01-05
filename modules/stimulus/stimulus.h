#include "systemc.h"

struct stimulus : public sc_module {
  sc_out<bool>                  loadseed_o;
  sc_out<sc_uint<32>>           seed_o;
  sc_in<sc_uint<32>>            number_i;

  sc_out<bool>                  reset;
    sc_in_clk                   CLK;

  void run_stimulus ();

  SC_CTOR (stimulus) {
    // cout.unsetf (ios::dec);
    // cout.setf (ios::hex);
    // cout.setf (ios::showbase);

    SC_THREAD (run_stimulus);
  }
};