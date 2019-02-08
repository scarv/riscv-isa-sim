require_extension('x');

#include "xc_packed.h"

uint8_t  b0         = insn.xc_b0();
uint8_t  b1         = insn.xc_b1();
uint8_t  b2         = insn.xc_b2();
uint8_t  b3         = insn.xc_b3();

uint32_t p0         = (XCRS1 >> (b0*2 + 16)) & 0x3;
uint32_t p1         = (XCRS1 >> (b1*2 + 16)) & 0x3;
uint32_t p2         = (XCRS1 >> (b2*2 + 16)) & 0x3;
uint32_t p3         = (XCRS1 >> (b3*2 + 16)) & 0x3;

uint32_t to_insert  = (p3 <<  8) |
                      (p2 <<  4) |
                      (p1 <<  2) |
                      (p0 <<  0) ;

uint32_t result     = (XCRS1 & 0xFF00FFFF) | (to_insert << 16);

WRITE_XCRD(result);

