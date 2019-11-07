
#include "xc_aes_common.h"

AES_UNPACK_BYTES(b0, b1, b2, b3);

// Forward SBOX
AES_SBOX(b0, b1, b2, b3);

uint32_t result = AES_PACK_BYTES(b0, b1, b2, b3);

WRITE_RD(result);


