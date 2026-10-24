// CP-3 (ISA v1.9 §5.7, O-54): a pointer in memory is the host's flat 64-bit
// address, not the register pair. Each lane reads a pointer from a table in
// global memory at a runtime index, dereferences it, and writes a pointer
// moved on from it back to memory. Entry 3 points at 0xFFFF_FFF0, so lanes
// that read through it cross 4 GiB, and the pointers they write need §5.7's
// carry from the low word into the high one. Executed by tools/check-ptrmem.sh.
#include "portable.h"

__global__ void ptrmem(float **tbl, float **slots, float *out) {
  int i = TID_X;
  float *b = tbl[i & 3];          // a pointer read from memory
  out[i] = b[i >> 2] * 2.0f;
  slots[i] = b + (i >> 2) + 4;    // a pointer written to memory
}
