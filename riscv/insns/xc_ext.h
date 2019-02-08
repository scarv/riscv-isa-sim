require_extension('x');

uint32_t lo = insn.xc_cs() * 2;
uint32_t hi = (insn.xc_cl() * 2) + lo - 1;

uint32_t mask = (0xFFFFFFFF << (32-hi)) >> (32-hi);
uint32_t wdata= (XCRS1 & (mask << lo)) >> lo;

WRITE_XCRD(wdata);

