// `vadd` with a loop -- the 32-bit control for vadd16_loop. Identical shape, so
// the pair isolates what the element width costs in steady state.
#include "portable.h"
__global__ void vadd_loop(float *ALIGNED c, const float *ALIGNED a,
                          const float *ALIGNED b, int n) {
    unsigned stride = NTID_X;
    for (unsigned i = CTAID_X * NTID_X + TID_X; i < (unsigned)n; i += stride)
        c[i] = a[i] + b[i];
}
