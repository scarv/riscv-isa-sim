require_rv64;

uint64_t address     = RS1 + (RS2 << 3);
WRITE_RD(MMU.load_int64(address));

