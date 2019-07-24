
#include "xc_packed.h"

uint32_t pack_width = insn.xc_pack_width();
uint32_t w          = 0;
int      n          = 0;
uint32_t mask       = 0;

XC_DECODE_PACK_WIDTHS(pack_width, w, n, mask);

uint64_t result     = 0;

uint64_t l = RS1;
uint64_t r = RS2;

for(int i = 0; i < n; i ++) {

    uint64_t lhs    = (RS1 >> (i*w)) & mask;
    uint64_t rhs    = (RS2 >> (i*w)) & mask;
    uint64_t pr     = (lhs + rhs)    & mask;
    
    result         |= pr << (i*w);
}

WRITE_RD(result);

//printf("# xc.padd (%d,%d) %d, 0x%08X, 0x%08X = 0x%08X\n",
//    w,pack_width,insn.xcrd(),l,r, result);

