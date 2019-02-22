require_extension('x');

uint64_t addr       = RS1 + RS2;
uint8_t  src_byte   = insn.xc_b0();
uint16_t data       = (XCRD  >> (8 * src_byte)) & 0x000000FF;

MMU.store_uint32(addr, data);
