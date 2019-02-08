require_extension('x');

uint32_t lo = insn.xc_cs() * 2;
uint32_t hi = (insn.xc_cl() * 2) + lo - 1;

uint32_t mask = (0xFFFFFFFF << (32-hi)) >> (32-hi);
uint32_t src  = XCRS1 & mask;
uint32_t wdata= (XCRD & ~(mask << lo)) | (mask << lo);

WRITE_XCRD(wdata);

