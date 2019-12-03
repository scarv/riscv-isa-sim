int rd1 = ( insn.xc_rdm() << 1 )       ;
int rd2 = ( insn.xc_rdm() << 1 ) | 0x1 ;

int rs1 = ( insn.xc_rdm() << 1 )       ;
int rs2 = ( insn.xc_rdm() << 1 ) | 0x1 ;
int rs3 = ( insn.xc_rdm() << 1 )       ;
int rs4 = ( insn.xc_rdm() << 1 ) | 0x1 ;

    
uint64_t result_lo;
uint64_t result_hi;



WRITE_REG( rd1, result_lo );
WRITE_REG( rd2, result_hi );
