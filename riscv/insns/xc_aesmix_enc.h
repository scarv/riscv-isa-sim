
#include "xc_aes_common.h"

uint8_t b0 = (RS1 >>  0) & 0xFF;
uint8_t b1 = (RS1 >>  8) & 0xFF;
uint8_t b2 = (RS2 >> 16) & 0xFF;
uint8_t b3 = (RS2 >> 24) & 0xFF;

uint8_t r0, r1, r2, r3;

r0 = AES_GFMUL(b0,2) ^ AES_GFMUL(b1,3) ^ AES_GFMUL(b2,1) ^ AES_GFMUL(b3,1);
r1 = AES_GFMUL(b0,1) ^ AES_GFMUL(b1,2) ^ AES_GFMUL(b2,3) ^ AES_GFMUL(b3,1);
r2 = AES_GFMUL(b0,1) ^ AES_GFMUL(b1,1) ^ AES_GFMUL(b2,2) ^ AES_GFMUL(b3,3);
r3 = AES_GFMUL(b0,3) ^ AES_GFMUL(b1,1) ^ AES_GFMUL(b2,1) ^ AES_GFMUL(b3,2);

uint32_t result = AES_PACK_BYTES(r0, r1, r2, r3);

WRITE_RD(result);

