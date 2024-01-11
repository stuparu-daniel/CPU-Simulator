#define CATCH_CONFIG_RUNNER
#include "module_testing.h"
#include "fetch.h"

int sc_main(int argc, char* argv[])
{
    test_utils::ElaborationFactory::get().initialize_modules();
    return Catch::Session().run(argc, argv);
}

struct FIXTURE_DEF(fetch)
{
    sc_in<unsigned > 		ramdata;	// instruction from RAM    
    sc_in<unsigned > 		branch_address; // branch target address   
    sc_in<bool>  			next_pc;   	// pc ++
    sc_in<bool>  			branch_valid;  	// branch_valid
    sc_in<bool>  			stall_fetch;   	// STALL_FETCH
    sc_in<bool>  			interrupt;   	// interrrupt 
    sc_in<unsigned>  		int_vectno;   	// interrupt vector number
    sc_in<bool>  			bios_valid;   	// BIOS input valid
    sc_in<bool>  			icache_valid;  	// Icache input valid
    sc_in<bool>  			pred_fetch;  	// branch prediction fetch
    sc_in<unsigned >  		pred_branch_address; 	// branch target address   
    sc_in<bool>  			pred_branch_valid; 	// branch prediction fetch
    sc_out<bool>  		ram_cs;   	// RAM chip select
    sc_out<bool>  		ram_we; 	// RAM write enable for SMC
    sc_out<unsigned >  	address;    	// address send to RAM
    sc_out<unsigned >  	smc_instruction; // for self-modifying code 
    sc_out<unsigned>  		instruction; 	 // instruction send to ID
    sc_out<bool>  		instruction_valid; // inst valid
    sc_out<unsigned >  	program_counter; // program counter	
    sc_out<bool>  		interrupt_ack;   // interrupt acknowledge
    sc_out<bool>  		branch_clear;    // clear outstanding branch
    sc_out<bool>  		pred_fetch_valid;  	// branch prediction fetch
    sc_out<bool>  		reset;  	// reset

    FIXTURE_CTOR(fetch)
    {
        sc_clock clk("test_clk",1,SC_NS,1,1,SC_NS,false);
        INIT_UUT(fetch);

        UUT->ramdata.bind(ramdata);
        UUT->branch_address.bind(branch_address);
        UUT->next_pc.bind(next_pc);
        UUT->branch_valid.bind(branch_valid);
        UUT->stall_fetch.bind(stall_fetch);
        UUT->interrrupt.bind(interrupt);
        UUT->int_vectno.bind(int_vectno);
        UUT->bios_valid.bind(bios_valid);
        UUT->icache_valid.bind(icache_valid);
        UUT->pred_fetch.bind(pred_fetch);
        UUT->pred_branch_address.bind(pred_branch_address);
        UUT->pred_branch_valid.bind(pred_branch_valid);
        
        ram_cs.bind(UUT->ram_cs);
        ram_we.bind(UUT->ram_we);
        address.bind(UUT->address);
        smc_instruction.bind(UUT->smc_instruction);
        instruction.bind(UUT->instruction);
        instruction_valid.bind(UUT->instruction_valid);
        program_counter.bind(UUT->program_counter);
        interrupt_ack.bind(UUT->interrupt_ack);
        branch_clear.bind(UUT->branch_clear);
        pred_fetch_valid.bind(UUT->pred_fetch_valid);
        reset.bind(UUT->reset);
    
        UUT->CLK.bind(clk);
    }
    
};

FIXTURED_TEST_THREAD(fetch, "fetch Module test")
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