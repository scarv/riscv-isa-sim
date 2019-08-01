
uint32_t x = RS1 & 0x7;
uint32_t y = RS2 & 0x7;

uint32_t shamt = insn.xc_sha3_sh();

uint32_t result = (((y)%5) + 5*((2*x+3*y)%5)) << shamt;

WRITE_RD(result);

