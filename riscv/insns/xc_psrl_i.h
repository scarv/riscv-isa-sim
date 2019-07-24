require_extension('x');

#include "xc_packed.h"

uint32_t pack_width = insn.xc_pack_width();
uint32_t w          = 0;
uint32_t n          = 0;
uint32_t mask       = 0;

XC_DECODE_PACK_WIDTHS(pack_width, w, n, mask);

uint32_t result     = 0;

uint32_t rhs        = insn.xc_cshamt();
uint32_t original   = XCRS1;

for(uint32_t i = 0; i < n; i ++) {

    uint32_t lhs    = (XCRS1 >> (i*w)) & mask;
    uint32_t pr     = (lhs   >> rhs) & mask;
    
    result         |= pr << (i*w);
}

WRITE_XCRD(result);

//printf("# xc.psrl.i (%d,%d) %d, %d, %d = 0x%08X - 0x%08X\n",
//    w,pack_width,insn.xcrd(),insn.xcrs1(), rhs, result, original);
