require_extension('x');

uint16_t ab0    = (XCRS1 >>  0) & 0xFFFF;
uint16_t ab1    = (XCRS1 >> 16) & 0xFFFF;

reg_t   addr_0  = RS1 + ab0;
reg_t   addr_1  = RS1 + ab1;

uint32_t ld0    = MMU.load_uint16(addr_0);
uint32_t ld1    = MMU.load_uint16(addr_1);

uint32_t wdata  = (ld1 << 16) | ld0;

WRITE_XCRD(wdata);

