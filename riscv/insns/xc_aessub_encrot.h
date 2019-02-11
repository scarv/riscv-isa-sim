require_extension('x');

#include "xc_aes_common.h"

AES_UNPACK_BYTES(b0, b1, b2, b3);

// Forward SBOX
AES_SBOX(b0, b1, b2, b3);

// Rotate output bytes
uint32_t result = AES_PACK_BYTES(b3, b0, b1, b2);

WRITE_XCRD(result);

