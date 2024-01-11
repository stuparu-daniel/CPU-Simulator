///////////////////////////////////////////////////////////////
//	This example demonstrates a simple RISC CPU design.
//      This is a simulation only example using Synopsys's
//	SystemC(TM) C++ class library.
//     
//      Several text files were used to initialize memory data
//	bios 	= system bios data
//	icache	= initial instruction cache
//	dcache	= initial data cache
//	register = initial register values
//	abc.asm	= a sample program
//
//	A simple assembler named assembler.pl which was written in PERL. 
//	Usage: assembler.pl <testname> -code > icache.img
//	Usage: assembler.pl <testname> > printout.img (for viewing only)
//
//	Steps:
//
//	NOTE: ALL COMMAND LISTED ARE UNIX COMMANDS.
//
//	1) set up the enviroment for SystemC.
//
//	2) based on abc.asm , write your own assembly language program, named <testname.asm>
//
//	3) assembler.pl abc.asm -code > icache.img
//
//	4) gmake
//	
//	5) run the executable demo.x
//
// Here is some details:
//
//First let me briefly describe the micro-architecture of this RISC CPU model.
//The CPU itself is modeled using SystemC.  The CPU reads in assembly program and
//execute it and write the result back to registers/data memory.  The instruction
//set is defined based on commercial RISC processor together with MMX-like 
//instruction for DSP program. It consists of >39 instructions (arithmetic, 
//logical, branch, floating point, SIMD(MMX-like)).
// 
//For Hardware/software partitioning, user can either write their algorithm
//in assembly program, or use YACC to convert it to this CPU's instruction
//set.  Then run it through the CPU, and you can measure how many cycles it
//takes and user can alter the memory latency or CPU behavior to be more
//realistic to get a better estimate.  Say, IDCT is the algorithm considered.
//User can then write a hardware IDCT model using SystemC, and determine
//what is the complexity and cost if IDCT is going to be implemented in hardware.
//Then maybe some part of IDCT can be hardware, some can be software. In either
//cases, SystemC is a useful tool in hardware/software partitioning.
// 
//Furthermore, this example can be also interpreted as ISS (instruction set 
//simulator), software developer can use this model to test their software
//early in the development cycle before the silicon chip come back from 
//fabrication/manufacturing. 
// 
//Finally, in order to compile the example you have to execute 'make'. Please
//note that the file Makefile.defs contains the location of the SystemC
//class library, which might be different for you, depending on your
//installation. Once the compilation is finished, you will find an
//executable 'cpu-simulator'. 
// 
//The CPU example structure looks like this:
// 
//.____________________________________________________.
//| Hardware Side                                      |
//|            .________.                              |
//|            |        |                              |
//|            |Stimulus|                              |
//|            .________.                              |
//|                 |                                  |
//|            .____|___.                              |  
//|            |        |                              |
//|            |  RNG   |                              |
//|            .________.                              |
//|                |                                   |
//| ._______.  .___|____.     .___________________.    |   
//| |       |  |        |   +-|Integer Execution  |--  |
//| | Fetch |--| Decode |---| `-------------------' |  |
//| ._______.  .________.   | .___________________. |  |
//|     |          |        +-|Floating Point Exe |-+  |
//| .___|___.  .___|____.   | `-------------------' |  |
//| |       |  |        |   | ._________________.   |  |                      
//| |Icache |  | Dcache |   +-|MMXlike Execution|---+  |
//| ._______.  .________.     `-----------------'   |  |
//|     ^          |--------------------------------.  |
//._____|______________________________________________.
//      |
//      |
//      .---------------------------------.
//._______________________________________|____________.
//| Software Side (Develop for your market|segments)   |
//| ._________________________.           |            | 
//| | Assembly code:          |           |            |
//| |   lw       R5, R5, 1    |           .            |
//| |   addi     R5, R5       | %assembler.pl foo.asm >| 
//| |   fadd     R3, R11, R11 |  -code > icache        |
//| |   bne      R5, R6,  5   |                        |
//| |   mmxadds  R13, R11, R11|           ^            |
//| |   sw       R13, R0, 10  |           |            |
//| ._________________________. _ _ _ _ _>|            |
//|                                       |            |
//|                                       |            |
//| ._________________________.           |            | 
//| | Polynomial code:        |           |            |
//| |   1x^2+1x+1             |           .            |
//| |   addi     R5, R5       | %script.pl    foo.asm >|
//| |                         |      register.img      | 
//| ._________________________. _ _ _ _ _>|            |
//.____________________________________________________.
// 
// 
///////////////////////////////////////////////////////////////

