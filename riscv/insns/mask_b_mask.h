uint32_t r_0, r_1, x;

x = READ_REG( insn.rs1() );

 BoolMask( &r_0, &r_1, x );

WRITE_REG( ( insn.xc_rdm() << 1 ) | 0x0, r_0 );
WRITE_REG( ( insn.xc_rdm() << 1 ) | 0x1, r_1 );
