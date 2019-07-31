
uint16_t ab0    = (RS2 >>  0) & 0xFFFF;
uint16_t ab1    = (RS2 >> 16) & 0xFFFF;

// Automatically halfword align the *offsets*.
reg_t   addr_0  = RS1 + (ab0<<1);
reg_t   addr_1  = RS1 + (ab1<<1);

uint32_t ld0    = MMU.load_uint16(addr_0);
uint32_t ld1    = MMU.load_uint16(addr_1);

uint64_t wdata  = (ld1 << 16) | ld0;

WRITE_RD(wdata);

