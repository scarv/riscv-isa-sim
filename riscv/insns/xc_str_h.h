require_extension('x');

uint64_t addr       = RS1 + RS2;
uint8_t  src_byte   = insn.xc_b0();

if(src_byte != 0 && src_byte != 2) {
    throw trap_illegal_instruction(0);
}

uint16_t data       = (XCRD  >> (8 * src_byte)) & 0x0000FFFF;

MMU.store_uint32(addr, data);
