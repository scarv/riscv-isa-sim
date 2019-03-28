require_extension('x');

uint32_t cs = insn.xc_cs();
uint32_t cl = insn.xc_cl();
uint32_t end= cs + cl     ;

if(end >= 32) {
    
    throw trap_illegal_instruction(0);

} else {

    uint32_t mask = ~(0xFFFFFFFF << (cl+1));
    uint32_t src  = XCRS1 & mask;
    uint32_t wdata= (XCRD & ~(mask << cs)) | (mask << cs);

    WRITE_XCRD(wdata);

}

