require_extension('x');

uint32_t bit_src  = insn.xc_cs();
uint32_t bit_dest = insn.xc_cl();

uint32_t rs1      = XCRS1;
uint32_t rs1_bit  = ((rs1 >> bit_src) & 0x1) << bit_dest;

uint32_t wdata    = (XCRD & ~rs1_bit) | rs1_bit;

WRITE_XCRD(wdata);

