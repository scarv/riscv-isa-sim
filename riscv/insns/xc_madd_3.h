require_extension('x');

uint64_t result = XCRS1_64 + XCRS2_64 + (XCRS3 & 0x1);

WRITE_XCRDM(result);
