require_extension('x');

#include "xc_packed.h"

uint8_t  b0         = insn.xc_b0();
uint8_t  b1         = insn.xc_b1();
uint8_t  b2         = insn.xc_b2();
uint8_t  b3         = insn.xc_b3();

uint32_t p0         = (XCRS1 >> (b0*4)) & 0xF;
uint32_t p1         = (XCRS1 >> (b1*4)) & 0xF;
uint32_t p2         = (XCRS1 >> (b2*4)) & 0xF;
uint32_t p3         = (XCRS1 >> (b3*4)) & 0xF;

uint32_t to_insert  = (p3 << 12) |
                      (p2 <<  8) |
                      (p1 <<  4) |
                      (p0 <<  0) ;

uint32_t result     = (XCRS1 & 0xFFFF0000) | to_insert;

WRITE_XCRD(result);

