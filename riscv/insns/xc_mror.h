
int rd1 = (insn.xc_rdm() << 1)       ;
int rd2 = (insn.xc_rdm() << 1) | 0x1 ;

int ramt= RS3 & 0x3F;
    
uint32_t result_lo;
uint32_t result_hi;

uint64_t rs1 = RS1 & 0xFFFFFFFF;
uint64_t rs2 = RS2 & 0xFFFFFFFF;

uint64_t rot_in = (((uint64_t) rs1) << 32) | ((uint64_t) rs2);
uint64_t result = (rot_in >> ramt) | (rot_in << (64-ramt));

//printf("# RS1 = %08lx, %08lx\n", RS1, rs1);
//printf("# RS2 = %08lx, %08lx\n", RS2, rs2);
//printf("#(%d,%d) %016lx >>> %d = %016lx\n",rd2,rd1,rot_in,ramt,result);
//fflush(stdout);

result_lo       = result & 0xFFFFFFFF;
result_hi       = result >> xlen     ;

WRITE_REG(rd1, result_lo);
WRITE_REG(rd2, result_hi);



