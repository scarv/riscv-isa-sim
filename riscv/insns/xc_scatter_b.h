require_extension('x');

uint8_t ab0     = (XCRS2 >>  0) & 0xFF;
uint8_t ab1     = (XCRS2 >>  8) & 0xFF;
uint8_t ab2     = (XCRS2 >> 16) & 0xFF;
uint8_t ab3     = (XCRS2 >> 24) & 0xFF;

uint8_t db0     = (XCRD >>  0) & 0xFF;
uint8_t db1     = (XCRD >>  8) & 0xFF;
uint8_t db2     = (XCRD >> 16) & 0xFF;
uint8_t db3     = (XCRD >> 24) & 0xFF;

reg_t   addr_0  = RS1 + ab0;
reg_t   addr_1  = RS1 + ab1;
reg_t   addr_2  = RS1 + ab2;
reg_t   addr_3  = RS1 + ab3;

MMU.store_uint8(addr_0, db0);
MMU.store_uint8(addr_1, db1);
MMU.store_uint8(addr_2, db2);
MMU.store_uint8(addr_3, db3);

