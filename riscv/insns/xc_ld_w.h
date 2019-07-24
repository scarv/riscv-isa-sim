require_extension('x');

uint32_t loaded_data = MMU.load_uint32(RS1 + insn.xcimm_ld());

WRITE_XCRD(loaded_data);

//printf("# xc.ld.w x%d <- 0x%08X [%d(0x%08X)]\n", insn.xcrd(), loaded_data,
//    insn.xcimm_ld(), RS1 );
//fflush(stdout);
