
#include "xc_aes_common.h"

uint8_t b0 = (RS1 >>  0) & 0xFF;
uint8_t b1 = (RS1 >>  8) & 0xFF;
uint8_t b2 = (RS2 >> 16) & 0xFF;
uint8_t b3 = (RS2 >> 24) & 0xFF;

uint8_t r0, r1, r2, r3;

r0 = AES_GFMUL(b0,14) ^ AES_GFMUL(b1,11) ^ AES_GFMUL(b2,13)^AES_GFMUL(b3, 9);
r1 = AES_GFMUL(b0, 9) ^ AES_GFMUL(b1,14) ^ AES_GFMUL(b2,11)^AES_GFMUL(b3,13);
r2 = AES_GFMUL(b0,13) ^ AES_GFMUL(b1, 9) ^ AES_GFMUL(b2,14)^AES_GFMUL(b3,11);
r3 = AES_GFMUL(b0,11) ^ AES_GFMUL(b1,13) ^ AES_GFMUL(b2, 9)^AES_GFMUL(b3,14);

uint32_t result = AES_PACK_BYTES(r0, r1, r2, r3);

WRITE_RD(result);

