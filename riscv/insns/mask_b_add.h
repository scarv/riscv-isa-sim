uint32_t r_0, r_1, x_0, x_1, y_0, y_1;

x_0 = READ_REG( ( insn.xc_rsm1() << 1 ) | 0x0 );
x_1 = READ_REG( ( insn.xc_rsm1() << 1 ) | 0x1 );
y_0 = READ_REG( ( insn.xc_rsm2() << 1 ) | 0x0 );
y_1 = READ_REG( ( insn.xc_rsm2() << 1 ) | 0x1 );

BoolAdd( &r_0, &r_1, x_0, x_1, y_0, y_1 );

WRITE_REG( ( insn.xc_rdm() << 1 ) | 0x0, r_0 );
WRITE_REG( ( insn.xc_rdm() << 1 ) | 0x1, r_1 );
