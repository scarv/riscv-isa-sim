
uint16_t ab0     = (RS2 >>  0) & 0xFFFF;
uint16_t ab1     = (RS2 >> 16) & 0xFFFF;

uint16_t db0     = (RS3 >>  0) & 0xFFFF;
uint16_t db1     = (RS3 >> 16) & 0xFFFF;

// Automatically halfword align the *offsets*.
reg_t   addr_0  = RS1 + (ab0<<1);
reg_t   addr_1  = RS1 + (ab1<<1);

MMU.store_uint16(addr_0, db0);
MMU.store_uint16(addr_1, db1);

