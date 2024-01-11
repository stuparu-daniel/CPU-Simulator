/*****************************************************************************
 
  decode.cpp  -- Instruction Decode Unit.

 *****************************************************************************/


#include <climits>	// for definition on value 's MAX
#include "decode.h"

int polynomial(const int a, const int b, const int c, const int x) {
        return a * x * x + b * x + c;
}

void printFloatBits(float value) {
    // Treat the float as an unsigned int to access its bits
    unsigned int* floatBits = (unsigned int*)&value;

    // Size of float in bytes
    int floatSize = sizeof(float);

    // Size of unsigned int in bits
    int intSize = sizeof(unsigned int) * 8;

    // Iterate through each bit of the float
    for (int i = floatSize * intSize - 1; i >= 0; --i) {
        // Print the bit at position i
        printf("%d", ((*floatBits) & (1 << i)) ? 1 : 0);

        // Print a space for better readability
        if (i % intSize == 0)
            printf(" ");
    }

    // Print a newline character at the end
    printf("\n");
}



void decode::entry()
{
  unsigned int 	instr_tmp = 0;
  unsigned int 	opcode_tmp = 0;
  unsigned int  regA_tmp = 0;
  unsigned int  regB_tmp = 0;
  unsigned int  regC_tmp = 0;
  unsigned int  imm_tmp = 0;
  unsigned int  offset_tmp = 0;
  signed   int  label_tmp = 0;
  unsigned int  longlabel_tmp = 0;
  signed int	srcA_tmp = 0;
  signed int	srcB_tmp = 0;
  signed int	srcC_tmp = 0;
  int		i;
  bool		branch_direction_tmp = 0;
  

  branch_valid.write(false);
  decode_valid.write(false);
  float_valid.write(false);
  mmx_valid.write(false);
  wait(2);

  while (true) {
	if (destreg_write.read() == true) {
		cpu_reg[destreg_write_src.read()] = alu_dataout.read();
                cout << "\t\t\t-------------------------------" << endl;
		printf("\t\t\tID: R%d=0x%x(%d) fr ALU", destreg_write_src.read(), alu_dataout.read(),alu_dataout.read());
		cout.setf(ios::dec,ios::basefield);
   		cout << " at CSIM " << sc_time_stamp() << endl;
                cout << "\t\t\t-------------------------------" << endl;
	}
	if (dram_rd_valid.read() == true) {
		cpu_reg[dram_write_src.read()] = dram_dataout.read();
                cout << "\t\t\t-------------------------------" << endl;
		printf("\t\t\tID: R%d=0x%x(%d) fr MemLd", dram_write_src.read(), dram_dataout.read(), dram_dataout.read());
		cout.setf(ios::dec,ios::basefield);
   		cout << " at CSIM " << sc_time_stamp() << endl;
                cout << "\t\t\t-------------------------------" << endl;
	}
	if (fpu_valid.read() == true) {
		cpu_reg[fpu_destout.read()] = fpu_dout.read();
                cout << "\t\t\t-------------------------------" << endl;
		printf("\t\t\tID: R%d=0x%x fr MMX", fpu_destout.read(), fpu_dout.read());
		cout.setf(ios::dec,ios::basefield);
   		cout << " at CSIM " << sc_time_stamp() << endl;
                cout << "\t\t\t-------------------------------" << endl;
	}
	if ((instruction_valid.read() == true)) {
		pc_reg = pc.read();
		if (clear_branch.read() == true) {
                	cout << "\t\t\t-------------------------------" << endl;
			printf("\t\t\tID: clear branch");
			cout.setf(ios::dec,ios::basefield);
   			cout << " at CSIM " << sc_time_stamp() << endl;
                	cout << "\t\t\t-------------------------------" << endl;
			branch_valid.write(false);
		}
   		instr_tmp  = instruction.read();
		opcode_tmp 	= (instr_tmp & 0xff000000) >> 24; 
		regC_tmp   	= (instr_tmp & 0x00f00000) >> 20; 
		regA_tmp   	= (instr_tmp & 0x000f0000) >> 16; 
		regB_tmp   	= (instr_tmp & 0x0000f000) >> 12; 
		imm_tmp    	= (instr_tmp & 0x0000ffff); 
		offset_tmp 	= (instr_tmp & 0x00000fff); 
		label_tmp  	= (instr_tmp & 0x0000ffff); 
		longlabel_tmp   = (instr_tmp & 0x00ffffff); 
		branch_direction_tmp = (instr_tmp & 0x00008000) >> 15;
		if (branch_direction_tmp) {			// handle backward branch
			label_tmp = - (0xffff - label_tmp + 1)  ;
		}

                int y0, y1, ymax;
                int x0, x1;
                float x_rng, y_rng, result, aux;
                int good_points = 0, total_points = 0;
                float *aux1;
                int* aux2;
		printf("opcode = %d regC = %d regA = %d regB = %d\n",opcode_tmp, regC_tmp, regA_tmp, regB_tmp);
		srcA_tmp = cpu_reg[regA_tmp];
		srcB_tmp = cpu_reg[regB_tmp];
		srcC_tmp = cpu_reg[regC_tmp];
		wait();
                cout << "\t\t\t-------------------------------" << endl;
/******************************************************************************
		unsigned int lastreg_tmp = regC_tmp;
		if (regA_tmp == lastreg_tmp){
			forward_A.write(true);
			forward_B.write(false);
		}  else  if (regB_tmp == lastreg_tmp){
				forward_A.write(false);
				forward_B.write(true);
		} else {
			forward_A.write(false);
			forward_B.write(false);
		}
*********************************************************************************/

		switch(opcode_tmp) {
			case 0x0:	// halt
					printf("\n\n\t\t\t*******************************\n");
					printf("\t\t\tID: REGISTERS DUMP");
					cout << " at CSIM " << sc_time_stamp() << endl;
					printf("\t\t\t*******************************\n");
					printf("REG :==================================================================\n");
					for(i =0; i<32; i++){
						printf("  R%2d(%08x)  ",i, cpu_reg[i]);
						if ((i==3) || (i== 11) || (i==19) || (i== 27) ||(i==7) || (i==15) || (i==23) || (i==31)){
							printf("\n");
						}
					}
					printf("=======================================================================\n\n");
					wait();
					wait();
					break;
			case 0x01:	// add R1, R2, R3
					printf("\t\t\tID: R%d= R%d(=%d)+R%d(=%d)", 
						regC_tmp, regA_tmp, srcA_tmp, regB_tmp, srcB_tmp);
					cout << " \n\t\t\t  : at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
					src_A.write(srcA_tmp);
					src_B.write(srcB_tmp);
					alu_src.write(regC_tmp);	
					alu_op.write(3);	
					decode_valid.write(true);
					wait();
					decode_valid.write(false);
					wait();
					break;
			case 0x02:	// addi R1, R2, #value
					printf("\t\t\tID: R%d= R%d(=%d)+%d", 
						regC_tmp, regA_tmp, srcA_tmp, imm_tmp);
					cout << " \n\t\t\t  : at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
					src_A.write(srcA_tmp);
					src_B.write(imm_tmp);
					alu_src.write(regC_tmp);
					alu_op.write(3);	
					decode_valid.write(true);
					wait();
					decode_valid.write(false);
					wait();
					break;
			case 0x03:	// addc R1, R2, R3 + Carrybit
					printf("\t\t\tID: R%d=  R%d(=%d)+R%d(=%d)+C", 
						regC_tmp, regA_tmp, srcA_tmp, regB_tmp, srcB_tmp);
					cout << " \n\t\t\t  : at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
					src_A.write(srcA_tmp);
					src_B.write(srcB_tmp);
					alu_src.write(regC_tmp);
					alu_op.write(1);
					decode_valid.write(true);
					wait();
					decode_valid.write(false);
					wait();
					break;
			case 0x04:	// sub R1, R2, R3 
					printf("\t\t\tID: R%d=R%d(=%d)-R%d(=%d)", 
						regC_tmp, regA_tmp, srcA_tmp, regB_tmp, srcB_tmp);
					cout << " \n\t\t\t  : at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
                                        src_A.write(srcA_tmp);
                                        src_B.write(srcB_tmp);
                                        alu_src.write(regC_tmp);
                                        alu_op.write(4);
                                        decode_valid.write(true);
                                        wait();
                                        decode_valid.write(false);
                                        wait();
					break;
			case 0x05:	// subi R1, R2,  #value
					printf("\t\t\tID: R%d=R%d(=%d)-%d", 
						regC_tmp, regA_tmp, srcA_tmp, imm_tmp);
					cout << " \n\t\t\t  : at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
                                        src_A.write(srcA_tmp);
                                        src_B.write(imm_tmp);
                                        alu_src.write(regC_tmp);
                                        alu_op.write(4);
                                        decode_valid.write(true);
                                        wait();
                                        decode_valid.write(false);
                                        wait();
					break;
			case 0x06:	// subc R1, R2, R3 - Carrybit
                                        printf("\t\t\tID: R%d=R%d(=%d)-R%d(=%d)-C", 
						regC_tmp, regA_tmp, srcA_tmp, regB_tmp, srcB_tmp);
					cout << " \n\t\t\t  : at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
                                        src_A.write(srcA_tmp);
                                        src_B.write(srcB_tmp);
                                        alu_src.write(regC_tmp);
                                        alu_op.write(2);
                                        decode_valid.write(true);
                                        wait();
                                        decode_valid.write(false);
                                        wait();
					break;
			case 0x07:	// mul R1, R2, R3 
					printf("\t\t\tID: R%d=R%d(=%d)*R%d(=%d)", 	
						regC_tmp, regA_tmp, srcA_tmp, regB_tmp, srcB_tmp);
					cout << " \n\t\t\t  : at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
                                        src_A.write(srcA_tmp);
                                        src_B.write(srcB_tmp);
                                        alu_src.write(regC_tmp);
                                        alu_op.write(5);
                                        decode_valid.write(true);
                                        wait();
                                        decode_valid.write(false);
                                        wait();
					break;
			case 0x08:	// div R1, R2, R3 
					printf("\t\t\tID: R%d=R%d(=%d)/R%d(=%d)", 	
						regC_tmp, regA_tmp, srcA_tmp, regB_tmp, srcB_tmp);
					cout << " \n\t\t\t  : at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
                                        src_A.write(srcA_tmp);
                                        src_B.write(srcB_tmp);
                                        alu_src.write(regC_tmp);
                                        alu_op.write(6);
                                        decode_valid.write(true);
                                        wait();
                                        decode_valid.write(false);
                                        wait();
					break;
			case 0x09:	// nand R1, R2, R3 
					printf("\t\t\tID: R%d=R%d(=%x) nand R%d(=%x)", 	
						regC_tmp, regA_tmp, srcA_tmp, regB_tmp, srcB_tmp);
					cout << " \n\t\t\t  : at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
                                        src_A.write(srcA_tmp);
                                        src_B.write(srcB_tmp);
                                        alu_src.write(regC_tmp);
                                        alu_op.write(7);
                                        decode_valid.write(true);
                                        wait();
                                        decode_valid.write(false);
                                        wait();
					break;
			case 0x0a:	// and R1, R2, R3 
					printf("\t\t\tID: R%d=R%d(=%x) and R%d(=%x)", 	
						regC_tmp, regA_tmp, srcA_tmp, regB_tmp, srcB_tmp);
					cout << " \n\t\t\t  : at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
                                        src_A.write(srcA_tmp);
                                        src_B.write(srcB_tmp);
                                        alu_src.write(regC_tmp);
                                        alu_op.write(8);
                                        decode_valid.write(true);
                                        wait();
                                        decode_valid.write(false);
                                        wait();
					break;
			case 0x0b:	// or R1, R2, R3 
                                        printf("\t\t\tID: R%d=R%d(=%x) or R%d(=%x)",
                                                regC_tmp, regA_tmp, srcA_tmp, regB_tmp, srcB_tmp);
					cout << " \n\t\t\t  : at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
                                        src_A.write(srcA_tmp);
                                        src_B.write(srcB_tmp);
                                        alu_src.write(regC_tmp);
                                        alu_op.write(9);
                                        decode_valid.write(true);
                                        wait();
                                        decode_valid.write(false);
                                        wait();
                                        break;
			case 0x0c:	// xor R1, R2, R3 
                                        printf("\t\t\tID: R%d=R%d(=%x) xor R%d(=%x)",
                                                regC_tmp, regA_tmp, srcA_tmp, regB_tmp, srcB_tmp);
					cout << " \n\t\t\t  : at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
                                        src_A.write(srcA_tmp);
                                        src_B.write(srcB_tmp);
                                        alu_src.write(regC_tmp);
                                        alu_op.write(10);
                                        decode_valid.write(true);
                                        wait();
                                        decode_valid.write(false);
                                        wait();
                                        break;
                        case 0x0d:      // NOT R1, R2 
                                        printf("\t\t\tID: R%d= NOT R%d(=%x)",
                                                regC_tmp, regA_tmp, srcA_tmp);
                                        cout << " \n\t\t\t  : at CSIM " << sc_time_stamp() << endl;
                                        cout << "\t\t\t-------------------------------" << endl;
                                        src_A.write(srcA_tmp);
                                        src_B.write(0);
                                        alu_src.write(regC_tmp);
                                        alu_op.write(11);
                                        decode_valid.write(true);
                                        wait();
                                        decode_valid.write(false);
                                        wait();
                                        break;
                        case 0x0e:      // modulo R1 = R2 mod R3 
                                        printf("\t\t\tID: R%d= R%d(=%x) mod R%d(=%x)", 
						regC_tmp, regA_tmp, srcA_tmp, regB_tmp, srcB_tmp);
                                        cout << " \n\t\t\t  : at CSIM " << sc_time_stamp() << endl;
                                        cout << "\t\t\t-------------------------------" << endl;
                                        src_A.write(srcA_tmp);
                                        src_B.write(srcB_tmp);
                                        alu_src.write(regC_tmp);
                                        alu_op.write(14);
                                        decode_valid.write(true);
                                        wait();
                                        decode_valid.write(false);
                                        wait();
                                        break;
			case 0x4d:	// lw R1, R2, offset
					printf("\t\t\tID: R%d<=mem[R%d=(%d)+%d]", 
						regC_tmp, regA_tmp, srcA_tmp, offset_tmp);
					cout << " \n\t\t\t  : at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
					mem_access.write(true);
					mem_write.write(false);
					alu_src.write(regC_tmp);
					offset_tmp = offset_tmp + srcA_tmp;
					mem_address.write(offset_tmp);
					wait();
					mem_access.write(false);
					wait();
					break;
			case 0x4e:	// sw R1, R2, offset
					printf("\t\t\tID: R%d=>mem[R%d(=%d) + %d]", 
						regC_tmp, regA_tmp, srcA_tmp, offset_tmp);
					cout << " \n\t\t\t  : at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
					mem_access.write(true);
					mem_write.write(true);
					offset_tmp = offset_tmp + srcA_tmp;
					mem_address.write(offset_tmp);
					wait();
					mem_access.write(false);
					mem_write.write(false);
					wait();
					break;
			case 0x0f:	// mov R1, R2
					printf("\t\t\tID: R%d=R%d(=%d)", 
						regC_tmp, regA_tmp, srcA_tmp);
					cout << " \n\t\t\t  : at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
					src_A.write(srcA_tmp);
					src_B.write(0);
					alu_src.write(regC_tmp);
					alu_op.write(3);	
					decode_valid.write(true);
					wait();
					decode_valid.write(false);
					wait();
					break;
			case 0x10:	// beq R1, R2, label
					src_A.write(0);
					src_B.write(0);
					alu_src.write(0);
					alu_op.write(3);	
					decode_valid.write(true);
					if (srcC_tmp == srcA_tmp) {
						branch_target_address.write(pc_reg + label_tmp);
						br_instruction_address.write(instr_tmp);
						branch_valid.write(true);
						printf("\t\t\tID: beq R%d(=%d), R%d(=%d), pc+=(%d).\n", 
							regC_tmp, srcC_tmp, regA_tmp, srcA_tmp, label_tmp);
					} else {
						printf("\t\t\tID: beq R%d(=%d) != R%d(=%d),pc++.\n", 
							regC_tmp, srcC_tmp, regA_tmp, srcA_tmp);
					}
					cout << "\t\t\tID: at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
					wait();
					branch_target_address.write(pc_reg + 1);
					decode_valid.write(false);
					wait();
					break;
			case 0x11:	// bne R1, R2, label
                                        src_A.write(0);
                                        src_B.write(0);
                                        alu_src.write(0);
                                        alu_op.write(3);
                                        decode_valid.write(true);
                                        if (srcC_tmp != srcA_tmp) {
						branch_target_address.write(pc_reg + label_tmp);
						br_instruction_address.write(instr_tmp);
                                                branch_valid.write(true);
                                                printf("\t\t\tID: bne R%d(=%d), R%d(=%d), pc+=(%d).\n",
                                                        regC_tmp, srcC_tmp, regA_tmp, srcA_tmp, label_tmp);
                                        } else {
                                                printf("\t\t\tID: bne R%d(=%d) = R%d(=%d),pc++.\n",
                                                        regC_tmp, srcC_tmp, regA_tmp, srcA_tmp);
                                        }
					cout << "\t\t\tID: at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
                                        wait();
					branch_target_address.write(pc_reg + 1);
                                        decode_valid.write(false);
                                        wait();
                                        break;
			case 0x12:	// bgt R1, R2, label
                                        src_A.write(0);
                                        src_B.write(0);
                                        alu_src.write(0);
                                        alu_op.write(3);
                                        decode_valid.write(true);
                                        if (srcC_tmp > srcA_tmp) {
						branch_target_address.write(pc_reg + label_tmp);
						br_instruction_address.write(instr_tmp);
                                                branch_valid.write(true);
                                                printf("\t\t\tID: bgt R%d(=%d)>R%d(=%d), pc+=(%d).\n",
                                                        regC_tmp, srcC_tmp, regA_tmp, srcA_tmp, label_tmp);
                                        } else {
                                                printf("\t\t\tID: bgt R%d(=%d) <= R%d(=%d),pc++.\n",
                                                        regC_tmp, srcC_tmp, regA_tmp, srcA_tmp);
                                        }
					cout << "\t\t\tID: at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
                                        wait();
					branch_target_address.write(pc_reg + 1);
                                        decode_valid.write(false);
                                        wait();
                                        break;
			case 0x13:	// bge R1, R2, label
                                        src_A.write(0);
                                        src_B.write(0);
                                        alu_src.write(0);
                                        alu_op.write(3);
                                        decode_valid.write(true);
                                        if (srcC_tmp >= srcA_tmp) {
						branch_target_address.write(pc_reg + label_tmp);
						br_instruction_address.write(instr_tmp);
                                                branch_valid.write(true);
                                                printf("\t\t\tID: bge R%d(=%d)>=R%d(=%d), pc+=(%d).\n",
                                                        regC_tmp, srcC_tmp, regA_tmp, srcA_tmp, label_tmp);
                                        } else {
                                                printf("\t\t\tID: bge R%d(=%d) < R%d(=%d),pc++.\n",
                                                        regC_tmp, srcC_tmp, regA_tmp, srcA_tmp);
                                        }
					cout << "\t\t\tID: at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
                                        wait();
					branch_target_address.write(pc_reg + 1);
                                        decode_valid.write(false);
                                        wait();
                                        break;
			case 0x14:	// blt R1, R2, label
                                        src_A.write(0);
                                        src_B.write(0);
                                        alu_src.write(0);
                                        alu_op.write(3);
                                        decode_valid.write(true);
                                        if (srcC_tmp < srcA_tmp) {
						branch_target_address.write(pc_reg + label_tmp);
						br_instruction_address.write(instr_tmp);
                                                branch_valid.write(true);
                                                printf("\t\t\tID: blt R%d(=%d)<R%d(=%d), pc+=(%d).\n",
                                                        regC_tmp, srcC_tmp, regA_tmp, srcA_tmp, label_tmp);
                                        } else {
                                                printf("\t\t\tID: blt R%d(=%d) >= R%d(=%d), pc++.\n",
                                                        regC_tmp, srcC_tmp, regA_tmp, srcA_tmp);
                                        }
					cout << "\t\t\tID: at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
                                        wait();
					branch_target_address.write(pc_reg + 1);
                                        decode_valid.write(false);
                                        wait();
                                        break;
			case 0x15:	// ble R1, R2, label
                                        src_A.write(0);
                                        src_B.write(0);
                                        alu_src.write(0);
                                        alu_op.write(3);
                                        decode_valid.write(true);
                                        if (srcC_tmp <= srcA_tmp) {
						branch_target_address.write(pc_reg + label_tmp);
						br_instruction_address.write(instr_tmp);
                                                branch_valid.write(true);
                                                printf("\t\t\tID: ble R%d(=%d)<=R%d(=%d), pc+=(%d).\n",
                                                        regC_tmp, srcC_tmp, regA_tmp, srcA_tmp, label_tmp);
                                        } else {
                                                printf("\t\t\tID: ble R%d(=%d)>R%d(=%d), pc++.\n",
                                                        regC_tmp, srcC_tmp, regA_tmp, srcA_tmp);
                                        }
					cout << "\t\t\tID: at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
                                        wait();
					branch_target_address.write(pc_reg + 1);
                                        decode_valid.write(false);
                                        wait();
                                        break;
			case 0x16:	// j label
                                        src_A.write(0);
                                        src_B.write(0);
                                        alu_src.write(0);
                                        alu_op.write(3);
                                        decode_valid.write(true);
                                        branch_target_address.write(longlabel_tmp);
					br_instruction_address.write(instr_tmp);
                                        branch_valid.write(true);
                                        printf("\t\t\tID: pc jump to => (%d).", longlabel_tmp);
					cout << " \n\t\t\t  : at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
                                        wait();
					branch_target_address.write(pc_reg + 1);
                                        decode_valid.write(false);
                                        wait();
                                        break;
			case 0x17:	// jal label for procedure call
					printf("\t\t\tID: j pc(%d) and sp <- pc", longlabel_tmp);
					cout << " at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
					wait();
					wait();
					break;
			case 0x18:	// jr
					printf("\t\t\tID: jr and pc <- sp\n");
					cout << " at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
					wait();
					wait();
					break;
                        case 0x29:      // fadd R1, R2, R3
                                        printf("\t\t\tID: FR%d=FR%d(=%x)+FR%d(=%x)",
                                                regC_tmp, regA_tmp, srcA_tmp, regB_tmp, srcB_tmp);
					cout << " \n\t\t\t  : at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
                                        src_A.write(srcA_tmp);
                                        src_B.write(srcB_tmp);
                                        alu_src.write(regC_tmp);
                                        alu_op.write(3);
                                        float_valid.write(true);
                                        wait();
                                        float_valid.write(false);
                                        wait();
                                        break;
                        case 0x2a:      // fsub R1, R2, R3
                                        printf("\t\t\tID: FR%d=FR%d(=%x)-FR%d(=%x)",
                                                regC_tmp, regA_tmp, srcA_tmp, regB_tmp, srcB_tmp);
					cout << " \n\t\t\t  : at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
                                        src_A.write(srcA_tmp);
                                        src_B.write(srcB_tmp);
                                        alu_src.write(regC_tmp);
                                        alu_op.write(4);
                                        float_valid.write(true);
                                        wait();
                                        float_valid.write(false);
                                        wait();
                                        break;
                        case 0x2b:      // fmul R1, R2, R3
                                        printf("\t\t\tID: FR%d=FR%d(=%x)*FR%d(=%x)",
                                                regC_tmp, regA_tmp, srcA_tmp, regB_tmp, srcB_tmp);
					cout << " \n\t\t\t  : at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
                                        src_A.write(srcA_tmp);
                                        src_B.write(srcB_tmp);
                                        alu_src.write(regC_tmp);
                                        alu_op.write(5);
                                        float_valid.write(true);
                                        wait();
                                        float_valid.write(false);
                                        wait();
                                        break;
                        case 0x2c:      // fdiv R1, R2, R3
                                        printf("\t\t\tID: FR%d=FR%d(=%x)/FR%d(=%x)",
                                                regC_tmp, regA_tmp, srcA_tmp, regB_tmp, srcB_tmp);
					cout << " \n\t\t\t  : at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
                                        src_A.write(srcA_tmp);
                                        src_B.write(srcB_tmp);
                                        alu_src.write(regC_tmp);
                                        alu_op.write(6);
                                        float_valid.write(true);
                                        wait();
                                        float_valid.write(false);
                                        wait();
                                        break;
                        case 0x31:      // mmxadd R1, R2, R3
                                        printf("\t\t\tID: MR%d=MR%d(=%x)+MR%d(=%x)",
                                                regC_tmp, regA_tmp, srcA_tmp, regB_tmp, srcB_tmp);
					cout << " \n\t\t\t  : at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
                                        src_A.write(srcA_tmp);
                                        src_B.write(srcB_tmp);
                                        alu_src.write(regC_tmp);
                                        alu_op.write(3);
                                        mmx_valid.write(true);
                                        wait();
                                        mmx_valid.write(false);
                                        wait();
                                        break;
                        case 0x32:      // mmxadds R1, R2, R3
                                        printf("\t\t\tID: MR%d=MR%d(=%x)+MR%d(=%x) Sat",
                                                regC_tmp, regA_tmp, srcA_tmp, regB_tmp, srcB_tmp);
					cout << " \n\t\t\t  : at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
                                        src_A.write(srcA_tmp);
                                        src_B.write(srcB_tmp);
                                        alu_src.write(regC_tmp);
                                        alu_op.write(4);
                                        mmx_valid.write(true);
                                        wait();
                                        mmx_valid.write(false);
                                        wait();
                                        break;
                        case 0x33:      // mmxsub R1, R2, R3
                                        printf("\t\t\tID: MR%d=MR%d(=%x)-MR%d(=%x)",
                                                regC_tmp, regA_tmp, srcA_tmp, regB_tmp, srcB_tmp);
					cout << " \n\t\t\t  : at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
                                        src_A.write(srcA_tmp);
                                        src_B.write(srcB_tmp);
                                        alu_src.write(regC_tmp);
                                        alu_op.write(5);
                                        mmx_valid.write(true);
                                        wait();
                                        mmx_valid.write(false);
                                        wait();
                                        break;
                        case 0x34:      // mmxsubs R1, R2, R3
                                        printf("\t\t\tID: MR%d=MR%d(=%x)-MR%d(=%x) Sat",
                                                regC_tmp, regA_tmp, srcA_tmp, regB_tmp, srcB_tmp);
					cout << " \n\t\t\t  : at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
                                        src_A.write(srcA_tmp);
                                        src_B.write(srcB_tmp);
                                        alu_src.write(regC_tmp);
                                        alu_op.write(6);
                                        mmx_valid.write(true);
                                        wait();
                                        mmx_valid.write(false);
                                        wait();
                                        break;
                        case 0x35:      // pmadd R1, R2, R3
                                        printf("\t\t\tID: MR%d=MR%d(=%x) ,MR%d(=%x) PMADD",
                                                regC_tmp, regA_tmp, srcA_tmp, regB_tmp, srcB_tmp);
					cout << " \n\t\t\t  : at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
                                        src_A.write(srcA_tmp);
                                        src_B.write(srcB_tmp);
                                        alu_src.write(regC_tmp);
                                        alu_op.write(7);
                                        mmx_valid.write(true);
                                        wait();
                                        mmx_valid.write(false);
                                        wait();
                                        break;
                        case 0x36:      // pack R1, R2, R3
                                        printf("\t\t\tID: MR%d=MR%d(=%x) pack MR%d(=%x)",
                                                regC_tmp, regA_tmp, srcA_tmp, regB_tmp, srcB_tmp);
					cout << " \n\t\t\t  : at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
                                        src_A.write(srcA_tmp);
                                        src_B.write(srcB_tmp);
                                        alu_src.write(regC_tmp);
                                        alu_op.write(8);
                                        mmx_valid.write(true);
                                        wait();
                                        mmx_valid.write(false);
                                        wait();
                                        break;
                        case 0x37:      // mmxck R1, R2, R3 MMX Chroma Keying
                                        printf("\t\t\tID: MR%d=MR%d(=%x) mmxck MR%d(=%x)",
                                                regC_tmp, regA_tmp, srcA_tmp, regB_tmp, srcB_tmp);
                                        cout << " \n\t\t\t  : at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
                                        src_A.write(srcA_tmp);
                                        src_B.write(srcB_tmp);
                                        alu_src.write(regC_tmp);
                                        alu_op.write(9);
                                        mmx_valid.write(true);
                                        wait();
                                        mmx_valid.write(false);
                                        wait();
                                        break;
                        case 0xe0:      // flush register
                                        printf("\t\t\tID: flush all registers");
                                        cout << " \n\t\t\t  : at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
                                        src_A.write(0);
                                        src_B.write(0);
                                        alu_src.write(0);
                                        alu_op.write(0);
					for (i = 0; i< 32; i++) {
						cpu_reg[i] = 0;
					}
                                        wait();
                                        wait();
                                        break;
                        case 0xf0:      // ldpid process_number
                                        printf("\t\t\tID: ld pid =%d", longlabel_tmp);
                                        cout << " \n\t\t\t  : at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
                                        src_A.write(0);
                                        src_B.write(0);
                                        alu_src.write(0);
                                        alu_op.write(0);
					pid_valid.write(true);
					decode_valid.write(false);
					float_valid.write(false);
					mmx_valid.write(false);
					pid_data.write(longlabel_tmp);
                                        wait();
					pid_valid.write(false);
                                        wait();
                                        break;
			case 0xf1:	// movi R1, #value
					printf("\t\t\tID: R%d=%d", 
						regC_tmp, imm_tmp);
					cout << " at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
					src_A.write(imm_tmp);
					src_B.write(0);
					alu_src.write(regC_tmp);
					alu_op.write(3);	
					decode_valid.write(true);
					wait();
					decode_valid.write(false);
					wait();
					break;
                        case 0xf2:      // rng R1
                                        cout << "\t\t\tID: R" << regC_tmp << "=" << random.read() << endl;
                                        cout << "\t\t\t at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;
                                        src_A.write(random.read());
                                        src_B.write(0);
					alu_src.write(regC_tmp);
					alu_op.write(3);	
					decode_valid.write(true);
					wait();
					decode_valid.write(false);
					wait();
					break;
                        case 0xc4:      //solve_poly
                                        cout << "\t\t\tID: R" << regC_tmp << "= solve_poly()" << endl;
                                        cout << "\t\t\t at CSIM " << sc_time_stamp() << endl;
                			cout << "\t\t\t-------------------------------" << endl;

                                        

                                        x0 = cpu_reg[3];
                                        x1 = cpu_reg[4];

                                        y0 = polynomial(cpu_reg[0], cpu_reg[1], cpu_reg[2], cpu_reg[3]);
                                        y1 = polynomial(cpu_reg[0], cpu_reg[1], cpu_reg[2], cpu_reg[4]);

                                        ymax = (y0 > y1) ? y0 : y1;

                                        for(int i = 0; i < NUMBER_OF_ITERATIONS; i++) {
                                                x_rng = x0 + (static_cast<float>(rand()) / static_cast<double>(RAND_MAX)) * (x1 - x0);
                                                y_rng = (static_cast<float>(rand()) / static_cast<double>(RAND_MAX)) * ymax;

                                                if(polynomial(cpu_reg[0], cpu_reg[1], cpu_reg[2], x_rng) >= y_rng) {
                                                        good_points++;
                                                }
                                                total_points++;
                                        }

                                        cout << "\t\t\tApprox integral of " << cpu_reg[0] << "x^2 +" << cpu_reg[1] << "x + " << cpu_reg[2]
                                        << " from " << x0 << " to " << x1 << " is " << static_cast<float>(static_cast<float>(good_points) / static_cast<float>(total_points) * ((x1 - x0) * ymax)) << endl;
                                        //cout << "Bits of result (no cast)\n";
                                        result = static_cast<float>(good_points) / static_cast<float>(total_points) * static_cast<float>((x1 - x0) * ymax);
                                        //printFloatBits(result);
                                        //cout << "Bits of result (with cast)\n";
                                        //printFloatBits(static_cast<signed int>(result));

                                        cpu_reg[7] = static_cast<int>(result);

                                        wait();

                                        ////store length of interval of integration in R11
                                        //src_A.write(cpu_reg[4]);
                                        //src_B.write(cpu_reg[3]);
					//alu_src.write(11);
					//alu_op.write(4);	
					//decode_valid.write(true);
					//wait();
					//decode_valid.write(false);
					//wait();
//
                                        //// store ymax in R6
                                        //src_A.write(ymax);
                                        //src_B.write(0);
					//alu_src.write(6);
					//alu_op.write(3);	
					//decode_valid.write(true);
					//wait();
					//decode_valid.write(false);
					//wait();
//
                                        //for(int i = 0; i < NUMBER_OF_ITERATIONS; i++) {
//
                                        //        //-----------Calculate x_rng--------------------
//
                                        //        //store first rng in R9
                                        //        src_A.write(random.read());
                                        //        src_B.write(0);
					//        alu_src.write(9);
					//        alu_op.write(3);	
					//        float_valid.write(true);
					//        wait();
					//        float_valid.write(false);
                                        //        wait();
//
                                        //        //R12 = R9 / RAND_MAX
                                        //        src_A.write(cpu_reg[9]);
                                        //        src_B.write(0xffffff);
					//        alu_src.write(12);
					//        alu_op.write(6);	
					//        float_valid.write(true);
					//        wait();
					//        float_valid.write(false);
					//        wait();
//
                                        //        //R12 = R12 * R11
                                        //        src_A.write(cpu_reg[11]);
                                        //        src_B.write(cpu_reg[12]);
					//        alu_src.write(12);
					//        alu_op.write(5);	
					//        float_valid.write(true);
					//        wait();
					//        float_valid.write(false);
					//        wait();
//
                                        //        //R12 = R12 + R4 -> x_rng
                                        //        src_A.write(cpu_reg[12]);
                                        //        src_B.write(cpu_reg[4]);
					//        alu_src.write(15);
					//        alu_op.write(3);	
					//        float_valid.write(true);
					//        wait();
					//        float_valid.write(false);
					//        wait();
//
                                        //        //-----------Calculate y_rng--------------------
                                        //        
                                        //        //store second rng in R16
                                        //        src_A.write(second_random.read());
                                        //        src_B.write(0);
					//        alu_src.write(16);
					//        alu_op.write(3);	
					//        float_valid.write(true);
					//        wait();
					//        float_valid.write(false);
					//        wait();
//
                                        //        //R16 = R16 / RAND_MAX 
                                        //        src_A.write(cpu_reg[16]);
                                        //        src_B.write(0xffffff);
					//        alu_src.write(12);
					//        alu_op.write(16);	
					//        float_valid.write(true);
					//        wait();
					//        float_valid.write(false);
					//        wait();
//
                                        //        //R16 = R16 * R6
                                        //        src_A.write(cpu_reg[16]);
                                        //        src_B.write(cpu_reg[6]);
					//        alu_src.write(16);
					//        alu_op.write(5);	
					//        float_valid.write(true);
					//        wait();
					//        float_valid.write(false);
					//        wait();
//
                                        //        aux = polynomial(cpu_reg[0], cpu_reg[1], cpu_reg[2], cpu_reg[12]);
                                        //        if(cpu_reg[16] <= aux) {
                                        //                good_points++;
                                        //        }
                                        //        total_points++;
                                        //}
//
                                        ////R6 = good_points / total_points
                                        //src_A.write(good_points);
                                        //src_B.write(total_points);
					//alu_src.write(6);
					//alu_op.write(6);	
					//float_valid.write(true);
					//wait();
					//float_valid.write(false);
					//wait();
//
                                        ////R6 = R6 * delta_x
                                        //src_A.write(cpu_reg[6]);
                                        //src_B.write(cpu_reg[11]);
					//alu_src.write(6);
					//alu_op.write(5);	
					//float_valid.write(true);
					//wait();
					//float_valid.write(false);
					//wait();
//
                                        ////R7 = R6 * ymax
                                        //src_A.write(cpu_reg[6]);
                                        //src_B.write(ymax);
					//alu_src.write(7);
					//alu_op.write(5);	
					//float_valid.write(true);
					//wait();
					//float_valid.write(false);
					//wait();

                                        wait();
                                        break;
                        case 0xff:      // QUIT
					printf("\t\t\tID: - SHUTDOWN - ");
					cout << "at CSIM " << sc_time_stamp() << endl;
					decode_valid.write(false);
					float_valid.write(false);
					mmx_valid.write(false);
					wait();
					printf("\t\t\tID: - PLEASE WAIT ...... - \n");
                			cout << "\t\t\t-------------------------------" << endl;
					sc_stop();
					printf("\n\n\n////////////////////////////////////////////////////////////////////////////////\n");
                                        wait();
					wait();
					break;
			default :
					printf("\t\t\tID: INVALID OPCODE");
					cout << " \n\t\t\t  : at CSIM " << sc_time_stamp() << endl;
					wait();
					break;
		}
		next_pc.write(true);
		wait();
	} else {
		next_pc.write(true);
		wait();
	}


  }
} // end of entry function


