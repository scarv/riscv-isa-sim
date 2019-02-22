require_extension('x');

uint64_t addr        = RS1 + RS2;
uint32_t loaded_data = MMU.load_uint32(addr);

WRITE_XCRD(loaded_data);
