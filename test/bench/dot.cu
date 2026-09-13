// Dot product: a reduction with a multiply, so the inner loop is FMA-shaped.
#include "portable.h"
__global__ void dot(float *ALIGNED out, const float *ALIGNED a,
                    const float *ALIGNED b, int n) {
    __shared__ float s[256];
    unsigned tid = TID_X;
    unsigned i = CTAID_X * NTID_X + tid;
    s[tid] = (i < (unsigned)n) ? a[i] * b[i] : 0.0f;
    SYNC();
    for (unsigned k = NTID_X / 2; k > 0; k >>= 1) {
        if (tid < k) s[tid] += s[tid + k];
        SYNC();
    }
    if (tid == 0) out[CTAID_X] = s[0];
}
