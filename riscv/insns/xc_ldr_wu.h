require_rv64;

uint64_t address     = RS1 + (RS2 << 2);
WRITE_RD(MMU.load_uint32(address));

