require_extension('x');

uint32_t cs = insn.xc_cs()     ;
uint32_t cl = insn.xc_cl();

if((cs + cl) >= 32) {

    throw trap_illegal_instruction(0);

} else {
    
    uint32_t mask   = ~(0xFFFFFFFF << (cl+1));
    uint32_t wdata  = (XCRS1 >> cs) & mask;

    WRITE_XCRD(wdata);

}

