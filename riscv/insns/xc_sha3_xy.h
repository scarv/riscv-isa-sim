require_extension('x');

uint32_t x = RS1 & 0x1F;
uint32_t y = RS2 & 0x1F;

uint32_t shamt = insn.xc_b0();

uint32_t result = (((x)%5) + 5*((y)%5)) << shamt;

WRITE_RD(result);

