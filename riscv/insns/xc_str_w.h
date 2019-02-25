require_extension('x');

uint64_t addr       = RS1 + RS2;
uint32_t data       = XCRD;

MMU.store_uint32(addr, data);

