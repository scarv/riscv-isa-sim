require_extension('x');

#include "xc_packed.h"

uint8_t  b0         = insn.xc_b0();
uint8_t  b1         = insn.xc_b1();
uint8_t  b2         = insn.xc_b2();
uint8_t  b3         = insn.xc_b3();

uint32_t p0         = (XCRS1 >> (b0*8)) & 0xFF;
uint32_t p1         = (XCRS1 >> (b1*8)) & 0xFF;
uint32_t p2         = (XCRS1 >> (b2*8)) & 0xFF;
uint32_t p3         = (XCRS1 >> (b3*8)) & 0xFF;

uint32_t result     = (p3 << 24) |
                      (p2 << 16) |
                      (p1 <<  8) |
                      (p0 <<  0) ;

WRITE_XCRD(result);

