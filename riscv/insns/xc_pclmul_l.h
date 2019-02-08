require_extension('x');

#include "xc_packed.h"

uint32_t pack_width = insn.xc_pack_width();
uint32_t w          = 0;
uint32_t n          = 0;
uint32_t mask       = 0;

XC_DECODE_PACK_WIDTHS(pack_width, w, n, mask);

uint32_t result     = 0;

for(uint32_t i = 0; i < n; i ++) {

    uint64_t lhs    = (XCRS1 >> (i*w)) & mask;
    uint64_t rhs    = (XCRS2 >> (i*w)) & mask;
    uint64_t pr     = XC_CARRYLESS_MUL(lhs,rhs) & mask;
    
    result         |= pr << (i*w);
}

WRITE_XCRD(result);

