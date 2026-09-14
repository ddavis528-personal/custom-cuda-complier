// `vadd16` with a loop, so per-thread overhead amortizes.
//
// vadd16 is one element per thread and entirely straight-line, so every width
// transition, argument load and address setup is paid once per element. That
// makes it a measurement of the PROLOGUE, not of the steady state. A real
// 16-bit kernel runs many elements per thread and the question that matters is
// what the loop body costs once the prologue is behind it -- and in particular
// whether the `chwidth` transitions are inside the loop or above it.
#include "portable.h"
__global__ void vadd16_loop(short *ALIGNED c, const short *ALIGNED a,
                            const short *ALIGNED b, int n) {
    unsigned stride = NTID_X;
    for (unsigned i = CTAID_X * NTID_X + TID_X; i < (unsigned)n; i += stride)
        c[i] = (short)(a[i] + b[i]);
}
