require_extension('x');

uint32_t b0 = ((XCRS1 >> (8*insn.xc_b0())) & 0xFF) <<  0;
uint32_t b1 = ((XCRS1 >> (8*insn.xc_b1())) & 0xFF) <<  8;
uint32_t b2 = ((XCRS1 >> (8*insn.xc_b2())) & 0xFF) << 16;
uint32_t b3 = ((XCRS1 >> (8*insn.xc_b3())) & 0xFF) << 24;

uint32_t wdata = b0 | b1 | b2 | b3;

WRITE_XCRD(wdata);

