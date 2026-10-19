// Pointer arguments are laid out before everything else, whatever order the
// signature declares them in (DA's response CP-4, 2026-10-08).
//
// The launch-slot index names a window word and §5.2 puts those 8 bytes apart,
// so the slot stride is 8 and sixteen slots reach sixteen POINTER arguments --
// but only if the pointers are the first sixteen 8-byte steps of the argument
// area. A scalar declared between two pointers would otherwise push the later
// one along by four bytes, which is both out of step with the stride and a
// waste of reach.
//
// So this signature INTERLEAVES deliberately: pointer, scalar, pointer, scalar,
// pointer. Declaration order gives 'out, n, a, s, b'; the ABI must give
// 'out, a, b' at 32, 40, 48 and then 'n, s' at 56, 60. Nothing about the source
// says that, which is the point -- the rule lives in the lowering pass and this
// is the only kernel in the tree that can tell whether it is being applied.
//
// The values matter too, and `check-slot-reach.sh` executes it: an ABI that put
// the arguments somewhere else would still compile and still assemble, and
// would read whatever happened to be at the offsets it chose. That is the
// F-147 failure shape, and the only thing that catches it is running the thing.
#include "portable.h"

__global__ void argorder(float *ALIGNED out, int n, const float *ALIGNED a,
                         float s, const float *ALIGNED b) {
    unsigned i = CTAID_X * NTID_X + TID_X;
    if (i >= (unsigned)n)
        return;
    out[i] = a[i] * s + b[i];
}
