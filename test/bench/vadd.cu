// Elementwise add. The simplest kernel that touches three arrays.
#include "portable.h"
__global__ void vadd(float *ALIGNED c, const float *ALIGNED a,
                     const float *ALIGNED b, int n) {
    unsigned i = CTAID_X * NTID_X + TID_X;
    if (i < (unsigned)n) c[i] = a[i] + b[i];
}
