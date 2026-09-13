// Block reduction: shared memory, barriers, a loop, and divergence.
#include "portable.h"
__global__ void reduce(float *ALIGNED out, const float *ALIGNED in, int n) {
    __shared__ float sdata[256];
    unsigned tid = TID_X;
    unsigned i = CTAID_X * NTID_X + tid;
    sdata[tid] = (i < (unsigned)n) ? in[i] : 0.0f;
    SYNC();
    for (unsigned s = NTID_X / 2; s > 0; s >>= 1) {
        if (tid < s) sdata[tid] += sdata[tid + s];
        SYNC();
    }
    if (tid == 0) out[CTAID_X] = sdata[0];
}
