require_extension('x');

uint32_t cs = insn.xc_cs();
uint32_t cl = insn.xc_cl();
uint32_t len = cl + 1     ;

if((cs + cl) >= 32) {

    throw trap_illegal_instruction(0);

} else {
    
    uint32_t mask   = len == 32 ? 0xFFFFFFFF : ~(0xFFFFFFFF << len);
    uint32_t wdata  = (XCRS1 >> cs) & mask;
    
    //printf("# xc.ext %d, %d, %08X, %08X\n",cs,len,XCRS1, wdata);
    //fflush(stdout);

    WRITE_XCRD(wdata);

}

