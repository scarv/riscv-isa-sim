
// Concatenate RS1 || RS2
uint64_t lut = (((uint64_t)RS1 & 0xFFFFFFFF) << 32) | (RS2&0xFFFFFFFF);

uint32_t wdata = 0;

uint32_t rd = RD;

// For each nibble in rs1
for(int i = 0; i < 8; i ++) {

    // 0 <= to_sub < 16 - the i'th nibble
    uint8_t to_sub = (rd >> (4*i)) & 0xF;
    
    // Index into the LUT.
    uint32_t subd  = (lut >> (to_sub*4)) & 0xF;

    wdata |= subd << (4*i);
}

WRITE_RD(wdata);

