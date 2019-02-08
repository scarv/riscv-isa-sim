
/*
This file contains various untility macros for the XCrypto extension
packed operations.
*/

#ifndef XC_PACKED_H
#define XC_PACKED_H

#define XC_DECODE_PACK_WIDTHS(pack_width, w, n, mask)  \
    if(pack_width == 0 || pack_width == 4) { \
        w = 32; \
        n =  1; \
        mask = 0xFFFFFFFF; \
    } else if(pack_width == 1) { \
        w = 16; \
        n =  2; \
        mask = 0x0000FFFF; \
    } else if(pack_width == 2) { \
        w =  8; \
        n =  4; \
        mask = 0x000000FF; \
    } else if(pack_width == 3) { \
        w =  4; \
        n =  8; \
        mask = 0x0000000F; \
    } else if(pack_width == 5) { \
        w =  2; \
        n = 16; \
        mask = 0x00000003; \
    } else { \
        throw trap_illegal_instruction(0); \
    }

#define XC_CARRYLESS_MUL_PARTIAL(LHS, RHS, P) \
   (LHS ^ (((RHS >> P) & 0x1) ? LHS << P : 0))

#define XC_CARRYLESS_MUL(LHS, RHS) ( \
    XC_CARRYLESS_MUL_PARTIAL(LHS,RHS, 0) | \
    XC_CARRYLESS_MUL_PARTIAL(LHS,RHS, 1) | \
    XC_CARRYLESS_MUL_PARTIAL(LHS,RHS, 2) | \
    XC_CARRYLESS_MUL_PARTIAL(LHS,RHS, 3) | \
    XC_CARRYLESS_MUL_PARTIAL(LHS,RHS, 4) | \
    XC_CARRYLESS_MUL_PARTIAL(LHS,RHS, 5) | \
    XC_CARRYLESS_MUL_PARTIAL(LHS,RHS, 6) | \
    XC_CARRYLESS_MUL_PARTIAL(LHS,RHS, 7) | \
    XC_CARRYLESS_MUL_PARTIAL(LHS,RHS, 8) | \
    XC_CARRYLESS_MUL_PARTIAL(LHS,RHS, 9) | \
    XC_CARRYLESS_MUL_PARTIAL(LHS,RHS,10) | \
    XC_CARRYLESS_MUL_PARTIAL(LHS,RHS,11) | \
    XC_CARRYLESS_MUL_PARTIAL(LHS,RHS,12) | \
    XC_CARRYLESS_MUL_PARTIAL(LHS,RHS,13) | \
    XC_CARRYLESS_MUL_PARTIAL(LHS,RHS,14) | \
    XC_CARRYLESS_MUL_PARTIAL(LHS,RHS,15) | \
    XC_CARRYLESS_MUL_PARTIAL(LHS,RHS,16) | \
    XC_CARRYLESS_MUL_PARTIAL(LHS,RHS,17) | \
    XC_CARRYLESS_MUL_PARTIAL(LHS,RHS,18) | \
    XC_CARRYLESS_MUL_PARTIAL(LHS,RHS,19) | \
    XC_CARRYLESS_MUL_PARTIAL(LHS,RHS,20) | \
    XC_CARRYLESS_MUL_PARTIAL(LHS,RHS,21) | \
    XC_CARRYLESS_MUL_PARTIAL(LHS,RHS,22) | \
    XC_CARRYLESS_MUL_PARTIAL(LHS,RHS,23) | \
    XC_CARRYLESS_MUL_PARTIAL(LHS,RHS,24) | \
    XC_CARRYLESS_MUL_PARTIAL(LHS,RHS,25) | \
    XC_CARRYLESS_MUL_PARTIAL(LHS,RHS,26) | \
    XC_CARRYLESS_MUL_PARTIAL(LHS,RHS,27) | \
    XC_CARRYLESS_MUL_PARTIAL(LHS,RHS,28) | \
    XC_CARRYLESS_MUL_PARTIAL(LHS,RHS,29) | \
    XC_CARRYLESS_MUL_PARTIAL(LHS,RHS,30) | \
    XC_CARRYLESS_MUL_PARTIAL(LHS,RHS,31) )
    
#endif

