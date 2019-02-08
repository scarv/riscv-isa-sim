require_extension('x');

uint16_t ab0     = (XCRS1 >>  0) & 0xFFFF;
uint16_t ab1     = (XCRS1 >> 16) & 0xFFFF;

uint16_t db0     = (XCRD  >>  0) & 0xFFFF;
uint16_t db1     = (XCRD  >> 16) & 0xFFFF;

reg_t   addr_0  = RS1 + ab0;
reg_t   addr_1  = RS1 + ab1;

MMU.store_uint16(addr_0, db0);
MMU.store_uint16(addr_1, db1);

