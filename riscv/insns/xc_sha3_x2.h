
uint32_t x = RS1 & 0x7;
uint32_t y = RS2 & 0x7;

uint32_t shamt = insn.xc_pack_width();

uint32_t result = (((x+2)%5) + 5*((y)%5)) << shamt;

WRITE_RD(result);

