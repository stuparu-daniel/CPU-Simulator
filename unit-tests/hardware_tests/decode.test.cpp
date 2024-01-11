#define CATCH_CONFIG_RUNNER
#include "module_testing.h"
#include "decode.h"

int sc_main(int argc, char* argv[])
{
    test_utils::ElaborationFactory::get().initialize_modules();
    return Catch::Session().run(argc, argv);
}

struct FIXTURE_DEF(decode)
{
    sc_in<bool>  			resetin;      		// input reset
  	sc_in<unsigned>  		instruction;		// fetched instruction
  	sc_in<unsigned>  		pred_instruction;	// fetched instruction
  	sc_in<bool>  			instruction_valid;      // input valid
  	sc_in<bool>  			pred_inst_valid;	// input valid
  	sc_in<bool>  			destreg_write;      	// register write enable
  	sc_in<unsigned>  		destreg_write_src;	// which register to write?      
  	sc_in<signed>  		alu_dataout; 		// data from ALU     
  	sc_in<signed>  		dram_dataout;           // data from Dcache
  	sc_in<bool>  			dram_rd_valid;      	// Dcache read data valid
  	sc_in<unsigned>  		dram_write_src;         // Dcache data write to which reg
  	sc_in<signed>  		fpu_dout;      		// data from FPU
  	sc_in<bool>  			fpu_valid;      	// FPU data valid
  	sc_in<unsigned>  		fpu_destout;      	// write to which register
  	sc_in<bool>  			clear_branch;      	// clear outstanding branch
  	sc_in<bool>  			display_done;      	// display to monitor done
  	sc_in<unsigned >  		pc;      		// program counter from IFU
  	sc_in<bool>  			pred_on;      		// branch prediction is on
	sc_in<sc_uint<32>>      random;             // randomly generated number
  	sc_out<unsigned > 		br_instruction_address; // branch invoke instruction
  	sc_out<bool>  			next_pc;      		// next pc ++ ?
  	sc_out<bool>  			branch_valid;      	// branch valid signal
  	sc_out<unsigned >  		branch_target_address;	// branch target address
  	sc_out<bool>  			mem_access;      	// memory access valid 
  	sc_out<unsigned >  		mem_address;      	// memory physical address
  	sc_out<int>  			alu_op;      		// ALU/FPU/MMU Opcode
  	sc_out<bool>  			mem_write;      	// memory write enable
  	sc_out<unsigned>  			alu_src;      		// destination register number
  	sc_out<bool>  			reg_write;      	// not implemented
  	sc_out<signed int>           	src_A;			// operand A
  	sc_out<signed int>           	src_B;			// operand B
  	sc_out<bool>  			forward_A;      	// data forwarding to operand A
  	sc_out<bool>  			forward_B;      	// data forwarding to operand B
  	sc_out<bool>  			stall_fetch;      	// stall fetch due to branch
  	sc_out<bool>  			decode_valid;      	// decoder output valid
  	sc_out<bool>  			float_valid;      	// enable FPU
  	sc_out<bool>  			mmx_valid;      	// enable MMU
  	sc_out<bool>  			pid_valid;      	// load process ID
  	sc_out<signed>  		pid_data;      		// process ID value

    FIXTURE_CTOR(decode)
    {
        sc_clock clk("test_clk",1,SC_NS,1,1,SC_NS,false);
        INIT_UUT(decode);

        UUT->resetin.bind(resetin);
        UUT->instruction.bind(instruction);
        UUT->pred_instruction.bind(pred_instruction);
        UUT->instruction_valid.bind(instruction_valid);
        UUT->pred_inst_valid.bind(pred_inst_valid);
        UUT->destreg_write.bind(destreg_write);
        UUT->destreg_write_src.bind(destreg_write_src);
        UUT->alu_dataout.bind(alu_dataout);
        UUT->dram_dataout.bind(dram_dataout);
        UUT->dram_rd_valid.bind(dram_rd_valid);
        UUT->dram_write_src.bind(dram_write_src);
        UUT->fpu_dout.bind(fpu_dout);
        UUT->fpu_valid.bind(fpu_valid);
        UUT->fpu_destout.bind(fpu_destout);
        UUT->clear_branch.bind(clear_branch);
        UUT->display_done.bind(display_done);
        UUT->pc.bind(pc);
        UUT->pred_on.bind(pred_on);
        UUT->random.bind(random);

        br_instruction_address.bind(UUT->br_instruction_address);
        next_pc.bind(UUT->next_pc);
        branch_valid.bind(UUT->branch_valid);
        branch_target_address.bind(UUT->branch_target_address);
        mem_access.bind(UUT->mem_access);
        mem_address.bind(UUT->mem_address);
        alu_op.bind(UUT->alu_op);
        mem_write.bind(UUT->mem_write);
        alu_src.bind(UUT->alu_src);
        reg_write.bind(UUT->reg_write);
        src_A.bind(UUT->src_A);
        src_B.bind(UUT->src_B);
        forward_A.bind(UUT->forward_A);
        forward_B.bind(UUT->forward_B);
        stall_fetch.bind(UUT->stall_fetch);
        decode_valid.bind(UUT->decode_valid);
        float_valid.bind(UUT->float_valid);
        mmx_valid.bind(UUT->mmx_valid);
        pid_valid.bind(UUT->pid_valid);
        pid_data.bind(UUT->pid_data);
    
        UUT->CLK.bind(clk);
    }
    
};

FIXTURED_TEST_THREAD(decode, "decode Module test")
{

    WHEN("Data is written to the input port")
    {
        //CHECK_WRITE(FIXTURE->mod_in, value);

        THEN("module writes back new value")
        {
            //REQUIRE(FIXTURE->mod_out.read() == value);
        }
        
    }

}