
int rd1 = (insn.xc_rdm() << 1)       ;
int rd2 = (insn.xc_rdm() << 1) | 0x1 ;

if(xlen == 32) {

    uint64_t    result      = (uint64_t)(RS1 & 0xFFFFFFFF) - 
                              (uint64_t)(RS2 & 0xFFFFFFFF) - 
                              (uint64_t)(RS3 & 0x1);
    uint32_t    result_lo   =       (uint32_t)(result      );
    uint32_t    result_hi   = 0x1 & (uint32_t)(result >> 32);

    WRITE_REG(rd1, result_lo);
    WRITE_REG(rd2, result_hi);

} else if(xlen == 64) {

    uint128_t   result      = (uint128_t)(RS1 & 0xFFFFFFFFFFFFFFFF) - 
                              (uint128_t)(RS2 & 0xFFFFFFFFFFFFFFFF) - 
                              (uint128_t)(RS3 & 0x1);
    uint64_t    result_lo   =       (uint64_t)(result      );
    uint64_t    result_hi   = 0x1 & (uint64_t)(result >> 64);

    WRITE_REG(rd1, result_lo);
    WRITE_REG(rd2, result_hi);

} else {
    // TBD: How do these instructions work on RV128?
    assert(0);
}



