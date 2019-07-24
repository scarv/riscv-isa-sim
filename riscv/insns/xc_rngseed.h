require_extension('x');

//
// We cannot model a proper cryptographic random number generator here
// inside spike. The aim is to make it possible to develop software.
//
// Instead we make rngseed and rngsamp work as an interface to the C
// standard functions `rand` and `srand`.
//
// While *not* cryptographically appropriate, it helps make software
// development using spike easier and repeatable.
//
// Note: because rngtest uses the `rand` function to generate an entropy
// result, both rngsamp and rngtest will affect the repeatability of
// the RNG.
//

uint32_t seed = XCRS1;

srand(seed);

