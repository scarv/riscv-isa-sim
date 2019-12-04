uint32_t r, x_0, x_1;

x_0 = READ_REG( ( insn.xc_rsm1() << 1 ) | 0x0 );
x_1 = READ_REG( ( insn.xc_rsm1() << 1 ) | 0x1 );

 BoolUnmask( &r, x_0, x_1 );

WRITE_REG( insn.rd(), r );
