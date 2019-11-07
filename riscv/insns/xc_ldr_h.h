
uint64_t address     = RS1 + (RS2 << 1);
WRITE_RD(MMU.load_int16(address));

