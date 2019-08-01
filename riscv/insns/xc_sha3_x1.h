
uint32_t x = RS1 & 0x7;
uint32_t y = RS2 & 0x7;

uint32_t shamt = insn.xc_sha3_sh();

uint32_t result = (((x+1)%5) + 5*((y)%5)) << shamt;

//printf("#sha3.x1 x=%d, y=%d, shamt=%d, result = %d\n",x,y,shamt,result);
//fflush(stdout);

WRITE_RD(result);

