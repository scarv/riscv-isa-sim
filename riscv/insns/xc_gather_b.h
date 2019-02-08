require_extension('x');

uint8_t ab0     = (XCRS1 >>  0) & 0xFF;
uint8_t ab1     = (XCRS1 >>  8) & 0xFF;
uint8_t ab2     = (XCRS1 >> 16) & 0xFF;
uint8_t ab3     = (XCRS1 >> 24) & 0xFF;

reg_t   addr_0  = RS1 + ab0;
reg_t   addr_1  = RS1 + ab1;
reg_t   addr_2  = RS1 + ab2;
reg_t   addr_3  = RS1 + ab3;

uint32_t lb0    = MMU.load_uint8(addr_0);
uint32_t lb1    = MMU.load_uint8(addr_1);
uint32_t lb2    = MMU.load_uint8(addr_2);
uint32_t lb3    = MMU.load_uint8(addr_3);

uint32_t wdata  = (lb3 << 24) |
                  (lb2 << 16) |
                  (lb1 <<  8) |
                  (lb0 <<  0) ;

WRITE_XCRD(wdata);

