
#include "xc_packed.h"

uint32_t pack_width = insn.xc_pack_width();
uint32_t w          = 0;
int      n          = 0;
uint32_t mask       = 0;

XC_DECODE_PACK_WIDTHS(pack_width, w, n, mask);

uint64_t result     = 0;
uint32_t rtamt      = insn.shamt() & 0x1F;

for(int i = 0; i < n; i ++) {

    uint64_t lhs    =  (((uint64_t)RS1 >> (i*w)) & mask)        | 
                      ((((uint64_t)RS1 >> (i*w)) & mask) << w)  ;
    uint64_t rhs    = rtamt;
    uint64_t pr     = (lhs   >> rhs) & mask;
    
    result         |= pr << (i*w);
}

WRITE_RD(result);


