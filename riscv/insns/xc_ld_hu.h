require_extension('x');

uint64_t address     = RS1 + insn.xcimm_ld();
uint32_t loaded_data = MMU.load_uint16(address) & 0x0000FFFF;
uint8_t  tgt_hw      = insn.xc_cc();

xcr_reg_t dst_value = STATE.XCR[insn.xcrd()];

if(tgt_hw == 0) {
    
    // If loading to 0th halfword of target register, blank entire
    // register and replace with loaded value.
    WRITE_XCRD(loaded_data);

} else {

    // Replace target byte of destination register with loaded
    // byte value.

    dst_value = (dst_value & ~(0x0000FFFF << (16*tgt_hw))) |
                (loaded_data              << (16*tgt_hw)) ;

    WRITE_XCRD(dst_value);
}

