require_extension('x');

uint8_t t0 = XCRS2 == XCRS3;
uint8_t t1 = XCRS2 <  XCRS3;

WRITE_RD(t1 || (t0 && RS1));

