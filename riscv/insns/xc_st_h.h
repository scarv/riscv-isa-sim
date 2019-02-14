require_extension('x');

uint64_t addr = RS1 + insn.xcimm_st();
uint16_t data = (XCRS2 >> (16 * insn.xc_cc())) & 0x0000FFFF;

MMU.store_uint16(addr, data);
