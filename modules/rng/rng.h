#include "systemc.h"
#include "directive.h"

struct rng : public sc_module {
  sc_in<bool>                   loadseed_i;
  sc_in<sc_uint<32>>            seed_i;

  sc_out<sc_uint<32>>           number_o;

  sc_signal<sc_uint<43>>        LFSR_reg;
  sc_signal<sc_uint<37>>        CASR_reg;

  sc_in<bool>                   reset;
    sc_in_clk                   CLK;

  int wait_cycles; 					// cycles # it takes to generate random number

//   void init_param(int given_delay_cycles) {
//     wait_cycles = given_delay_cycles; 
//   }

  SC_CTOR(rng) {
    SC_METHOD(CASR);
    sensitive_pos << CLK;
    sensitive_neg << reset;

    SC_METHOD(LFSR);
    sensitive_pos << CLK;
    sensitive_neg << reset;

    SC_METHOD(combinate);
    sensitive_pos << CLK;
    sensitive_neg << reset;
  }

  void CASR();
  void LFSR();
  void combinate();
};
