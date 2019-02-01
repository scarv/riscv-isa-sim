
uint32_t loaded_data = MMU.load_uint8(RS1 + insn.xcimm_ld());
uint8_t  tgt_byte    = (insn.xc_cc() << 1) | insn.xc_cd();

xcr_reg_t dst_value = STATE.XCR[insn.xcrd()];

if(tgt_byte == 0) {
    
    // If loading to 0th byte of target register, blank entire
    // register and replace with loaded value.
    WRITE_XCRD(loaded_data);

} else {

    // Replace target byte of destination register with loaded
    // byte value.

    dst_value = (dst_value & ~(0x000000FF << (8*tgt_byte))) |
                (loaded_data              << (8*tgt_byte)) ;
    
    WRITE_XCRD(dst_value);
}
