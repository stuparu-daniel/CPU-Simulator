/*****************************************************************************
 
  rng.cpp -- Random Number Generator.

 *****************************************************************************/

#include "rng.h"

void rng::combinate() {
    if (!reset.read()) {
      number_o.write(0);
    } else {
      number_o.write((LFSR_reg.read().range(31, 0) ^ CASR_reg.read().range(31, 0)) & 0x7FFFFFF);
    }
	
    if(PRINT_RNG && wait_cycles <= 0) {
        cout << "\t\t------------------------" << endl;   
        cout << "\t\tRNG : number out = "<< number_o.read() << endl;
        cout << "\t\tRNG : seed = "<< seed_i.read() << endl;
        cout.setf(ios::dec,ios::basefield);
        cout << "\t\t at CSIM " << sc_time_stamp() << endl;
        cout << "\t\t------------------------" << endl;  
    }
	wait_cycles--;
}

void rng::LFSR() {
    sc_uint<43> LFSR_var;
    bool outbit;

    if (!reset.read()) {
      LFSR_reg.write(1);
    } else {
        if (loadseed_i.read()) {
	        LFSR_var.range(42, 32) = 0;
	        LFSR_var.range(31, 0) = seed_i.read();
	        LFSR_reg.write(LFSR_var);
	    } else {
	            LFSR_var = LFSR_reg.read();

	            outbit = LFSR_var[42];
	            LFSR_var[42] = LFSR_var[41];
	            LFSR_var[41] = LFSR_var[40] ^ outbit;
	            LFSR_var[40] = LFSR_var[39];
	            LFSR_var[39] = LFSR_var[38];
	            LFSR_var[38] = LFSR_var[37];
	            LFSR_var[37] = LFSR_var[36];
	            LFSR_var[36] = LFSR_var[35];
	            LFSR_var[35] = LFSR_var[34];
	            LFSR_var[34] = LFSR_var[33];
	            LFSR_var[33] = LFSR_var[32];
	            LFSR_var[32] = LFSR_var[31];
	            LFSR_var[31] = LFSR_var[30];
	            LFSR_var[30] = LFSR_var[29];
	            LFSR_var[29] = LFSR_var[28];
	            LFSR_var[28] = LFSR_var[27];
	            LFSR_var[27] = LFSR_var[26];
	            LFSR_var[26] = LFSR_var[25];
	            LFSR_var[25] = LFSR_var[24];
	            LFSR_var[24] = LFSR_var[23];
	            LFSR_var[23] = LFSR_var[22];
	            LFSR_var[22] = LFSR_var[21];
	            LFSR_var[21] = LFSR_var[20];
	            LFSR_var[20] = LFSR_var[19] ^ outbit;
	            LFSR_var[19] = LFSR_var[18];
	            LFSR_var[18] = LFSR_var[17];
	            LFSR_var[17] = LFSR_var[16];
	            LFSR_var[16] = LFSR_var[15];
	            LFSR_var[15] = LFSR_var[14];
	            LFSR_var[14] = LFSR_var[13];
	            LFSR_var[13] = LFSR_var[12];
	            LFSR_var[12] = LFSR_var[11];
	            LFSR_var[11] = LFSR_var[10];
	            LFSR_var[10] = LFSR_var[9];
	            LFSR_var[9] = LFSR_var[8];
	            LFSR_var[8] = LFSR_var[7];
	            LFSR_var[7] = LFSR_var[6];
	            LFSR_var[6] = LFSR_var[5];
	            LFSR_var[5] = LFSR_var[4];
	            LFSR_var[4] = LFSR_var[3];
	            LFSR_var[3] = LFSR_var[2];
	            LFSR_var[2] = LFSR_var[1];
	            LFSR_var[1] = LFSR_var[0] ^ outbit;
	            LFSR_var[0] = LFSR_var[42];

	            LFSR_reg.write(LFSR_var);
	    }   
    }
}

void rng::CASR() {
    sc_uint<37> CASR_var, CASR_out;

    if (!reset.read()) {
      CASR_reg.write(1);
    } else {
        if (loadseed_i.read()) {
	        CASR_var.range(36, 32) = 0;
	        CASR_var.range(31, 0) = seed_i.read();
	        CASR_reg.write(CASR_var);
	    } else {
	        CASR_var = CASR_reg.read();

	        CASR_out[36] = CASR_var[35] ^ CASR_var[0];
	        CASR_out[35] = CASR_var[34] ^ CASR_var[36];
	        CASR_out[34] = CASR_var[33] ^ CASR_var[35];
	        CASR_out[33] = CASR_var[32] ^ CASR_var[34];
	        CASR_out[32] = CASR_var[31] ^ CASR_var[33];
	        CASR_out[31] = CASR_var[30] ^ CASR_var[32];
	        CASR_out[30] = CASR_var[29] ^ CASR_var[31];
	        CASR_out[29] = CASR_var[28] ^ CASR_var[30];
	        CASR_out[28] = CASR_var[27] ^ CASR_var[29];
	        CASR_out[27] = CASR_var[26] ^ CASR_var[27] ^ CASR_var[28];
	        CASR_out[26] = CASR_var[25] ^ CASR_var[27];
	        CASR_out[25] = CASR_var[24] ^ CASR_var[26];
	        CASR_out[24] = CASR_var[23] ^ CASR_var[25];
	        CASR_out[23] = CASR_var[22] ^ CASR_var[24];
	        CASR_out[22] = CASR_var[21] ^ CASR_var[23];
	        CASR_out[21] = CASR_var[20] ^ CASR_var[22];
	        CASR_out[20] = CASR_var[19] ^ CASR_var[21];
	        CASR_out[19] = CASR_var[18] ^ CASR_var[20];
	        CASR_out[18] = CASR_var[17] ^ CASR_var[19];
	        CASR_out[17] = CASR_var[16] ^ CASR_var[18];
	        CASR_out[16] = CASR_var[15] ^ CASR_var[17];
	        CASR_out[15] = CASR_var[14] ^ CASR_var[16];
	        CASR_out[14] = CASR_var[13] ^ CASR_var[15];
	        CASR_out[13] = CASR_var[12] ^ CASR_var[14];
	        CASR_out[12] = CASR_var[11] ^ CASR_var[13];
	        CASR_out[11] = CASR_var[10] ^ CASR_var[12];
	        CASR_out[10] = CASR_var[9] ^ CASR_var[11];
	        CASR_out[9] = CASR_var[8] ^ CASR_var[10];
	        CASR_out[8] = CASR_var[7] ^ CASR_var[9];
	        CASR_out[7] = CASR_var[6] ^ CASR_var[8];
	        CASR_out[6] = CASR_var[5] ^ CASR_var[7];
	        CASR_out[5] = CASR_var[4] ^ CASR_var[6];
	        CASR_out[4] = CASR_var[3] ^ CASR_var[5];
	        CASR_out[3] = CASR_var[2] ^ CASR_var[4];
	        CASR_out[2] = CASR_var[1] ^ CASR_var[3];
	        CASR_out[1] = CASR_var[0] ^ CASR_var[2];
	        CASR_out[0] = CASR_var[36] ^ CASR_var[1];

	        CASR_reg.write(CASR_out);
	    }
    }
}