require_extension('x');

uint32_t addr = RS1 + insn.xcimm_st();

//printf("# xc.st.w 0x%08X <- 0x%08X\n", addr, XCRS2);

MMU.store_uint32(addr, XCRS2);

