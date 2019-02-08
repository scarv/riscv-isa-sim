require_extension('x');

uint64_t result = (XCRS1 - XCRS2) - (XCRS3 & 0x1);

WRITE_XCRDM(result);
