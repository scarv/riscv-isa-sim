require_extension('x');

uint32_t    lut  = insn.xc_lut8();

uint32_t    r2  = XCRD ;
uint32_t    r1  = XCRS2;
uint32_t    r0  = XCRS1;

uint32_t    wdata = 0;

for(int i = 0; i < 32; i ++) {

    uint8_t idx = (((r2>>i) & 0x1) << 2) |
                  (((r1>>i) & 0x1) << 1) |
                  (((r0>>i) & 0x1) << 0) ;
    
    uint32_t b  = (lut >> idx) & 0x1;

    wdata |= b << i;

}

WRITE_XCRD(wdata);
