
int rd1 = (insn.xc_rdm() << 1)       ;
int rd2 = (insn.xc_rdm() << 1) | 0x1 ;

int ramt= RS3 & 0x3F;
    
uint64_t result_lo;
uint64_t result_hi;

uint64_t rot_in = ((uint64_t)RS1<<32) | RS2;
uint64_t result = (rot_in >> ramt) | (rot_in << (64-ramt));

result_lo       = result & 0xFFFFFFFF;
result_hi       = result >> xlen     ;

WRITE_REG(rd1, result_lo);
WRITE_REG(rd2, result_hi);



