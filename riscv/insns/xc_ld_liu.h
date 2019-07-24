require_extension('x');

uint32_t imm     = insn.xc_imm16z();
uint32_t current = XCRD;

uint32_t wdata   = (current & 0xFFFF0000) | imm;

WRITE_XCRD(wdata);

