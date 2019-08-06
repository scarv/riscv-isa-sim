
uint32_t    uxcrypto_csr = p -> get_csr(CSR_UXCRYPTO);

uint32_t    lut = insn.xc_l() ? (uxcrypto_csr >> 24) & 0xFF :
                                (uxcrypto_csr >> 16) & 0xFF ;

uint32_t    r2  = RD ;
uint32_t    r1  = RS1;
uint32_t    r0  = RS2;

uint32_t    wdata = 0;

for(int i = 0; i < 32; i ++) {

    uint8_t idx = (((r2>>i) & 0x1) << 2) |
                  (((r1>>i) & 0x1) << 1) |
                  (((r0>>i) & 0x1) << 0) ;

    uint32_t b  = (lut >> idx) & 0x1;

    wdata |= b << i;

}

WRITE_RD(wdata);
