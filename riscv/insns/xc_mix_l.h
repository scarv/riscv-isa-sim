require_extension('x');

uint32_t ramt   = insn.xc_rtamt();

uint32_t t      = (XCRS1 >> ramt) | (XCRS1 << (32-ramt));

uint32_t wdata  = (XCRD & ~XCRS2) | (t & XCRS2);

WRITE_XCRD(wdata);

