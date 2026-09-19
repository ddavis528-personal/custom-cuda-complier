// Fused residual-add + RMSNorm. Still three tensors, two of them read-write.
//
// Shaped after vLLM's `fused_add_rms_norm_kernel`, which is the form that
// actually runs: the residual stream is added in and written back in the same
// pass that normalises, so the intermediate never reaches memory. Fusing is what
// this corpus is about, and this is the smallest real example of it -- fusing
// two kernels into one did NOT raise the pointer count, because the second
// kernel's input was already the first one's output.
//
// That is worth stating plainly, because the synthetic `fused.cu` assumes the
// opposite: that fusion raises the tensor count. Sometimes it does. Here it
// raises the number of ACCESSES per pointer instead, from three to five, and
// accesses are not what competes for the register file.
#include "fusion.h"

#ifndef NWARP_THREADS
#define NWARP_THREADS 32
#endif

__global__ void add_rmsnorm(float *ALIGNED input, float *ALIGNED residual,
                            const float *ALIGNED weight, float eps,
                            int hidden) {
    __shared__ float red[NWARP_THREADS];
    unsigned t = TID_X;
    unsigned base = CTAID_X * (unsigned)hidden;

    float ss = 0.0f;
    for (unsigned i = t; i < (unsigned)hidden; i += NTID_X) {
        float v = input[base + i] + residual[base + i];
        residual[base + i] = v;
        ss += v * v;
    }
    red[t] = ss;
    SYNC();
    for (unsigned s = NTID_X / 2; s > 0; s >>= 1) {
        if (t < s) red[t] += red[t + s];
        SYNC();
    }
    float scale = ccv_rsqrt(red[0] * ccv_recip((float)hidden) + eps);

    for (unsigned i = t; i < (unsigned)hidden; i += NTID_X)
        input[base + i] = residual[base + i] * scale * weight[i];
}
