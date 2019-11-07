
int rd1 = (insn.xc_rdm() << 1)       ;
int rd2 = (insn.xc_rdm() << 1) | 0x1 ;

if(xlen == 32) {

    uint64_t    lhs         = ((uint64_t)(RS1 & 0xFFFFFFFF)<<32) | 
                              (uint64_t)(RS2 & 0xFFFFFFFF) ;
                              
    uint32_t    rhs         = (uint32_t)(RS3 & 0xFFFFFFFF) ;

    uint64_t    result      = lhs + rhs;

    uint32_t    result_lo   = (uint32_t)(result      );
    uint32_t    result_hi   = (uint32_t)(result >> 32);

    WRITE_REG(rd1, result_lo);
    WRITE_REG(rd2, result_hi);

} else if(xlen == 64) {
    
    uint64_t result_lo;
    uint64_t result_hi;
    
    result_lo = RS2 + RS3;
    result_hi = RS3 + (result_lo < RS2);

    WRITE_REG(rd1, result_lo);
    WRITE_REG(rd2, result_hi);

} else {
    // TBD: How do these instructions work on RV128?
    assert(0);
}


