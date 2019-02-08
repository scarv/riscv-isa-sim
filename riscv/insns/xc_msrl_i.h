require_extension('x');

uint64_t lhs    = ((uint64_t)XCRS2<<32) | XCRS1;
uint32_t rhs    = insn.xc_cmshamt();

uint64_t result = lhs >> rhs;

WRITE_XCRDM(result)
