require_extension('x');

uint64_t result = 0;

for (int i = 0; i < 32; i ++) {
    if((XCRS2 >> i) & 0x1) {
        result ^= ((uint64_t)XCRS1) << i;
    }
}

result ^= XCRS3;

WRITE_XCRDM(result);
