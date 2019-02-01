require_extension('x');

uint32_t loaded_data = MMU.load_uint32(RS1 + insn.xcimm_ld());

WRITE_XCRD(loaded_data);
