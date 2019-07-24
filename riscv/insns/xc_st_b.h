require_extension('x');

uint64_t addr       = RS1 + insn.xcimm_st();
uint8_t  src_byte   = (insn.xc_cc() << 1) | insn.xc_cd();
uint8_t  data       = (XCRS2 >> (8 * src_byte)) & 0x000000FF;

MMU.store_uint8(addr, data);
