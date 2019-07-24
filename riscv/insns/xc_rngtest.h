
//
// It is impossible to properly model a TRNG in software only.
//
// Given the range of implementation options for an RNG in hardware,
// this instruction may effectivley return a constant when implemented,
// though this would not imply good things about the cryptographic
// appropriateness of the implementation.
//
// In order to make software development easier, and to ensure all code paths
// can be stressed, this instruction will return a pseudo random result.
//
// - 70% of the time it will write non-zero to the destination, indicating
//   sufficient entropy is available.
// - 30% of the time, it will write zero, indicating not enough entrop is
//   available.
//
// This should be enough to develop software which correctly handles all
// scenarios relating to the XCrypto RNG.
//

uint32_t rval       = rand();

// Mask RAND_MAX to be upto 32-bits.
uint32_t threshold  = ((0xFFFFFFFF&RAND_MAX)/10) * 30;

if(rval < threshold) {
    // Emulate not enough entropy
    WRITE_RD(0);
} else {
    // Emulate enough entropy
    WRITE_RD(1);
}
