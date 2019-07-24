
int rd1 = (insn.xc_rdm() << 1)       ;
int rd2 = (insn.xc_rdm() << 1) | 0x1 ;
    
uint64_t result_lo;
uint64_t result_hi;

if(xlen == 32) {

    uint64_t result = RS1 - RS2 - (RS3 & 0x1);

    result_lo       = result & 0xFFFFFFFF;
    result_hi       = result >> xlen     ;

} else if(xlen == 64) {

    int128_t result = (int128_t)RS1 - RS2 - (RS3&0x1);

    result_lo = result & 0xFFFFFFFFFFFFFFFF;
    result_hi = (result >> xlen);

} else {
    // TBD: How do these instructions work on RV128?
    assert(0);
}

WRITE_REG(rd1, result_lo);
WRITE_REG(rd2, result_hi);

