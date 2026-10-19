// The fused AdamW step. Four tensors, all read-modify-write, and a grid-stride
// loop -- which is not a stylistic choice here but the only way the kernel is
// ever written, because it runs over a whole parameter tensor of unknown size.
//
// This is the training-side counterpart to the inference epilogues, and it is
// the corpus's closest approach to the shape `fused.cu` was built to imitate: a
// long-running loop whose window bases are all loop-invariant and therefore all
// live at once. The difference is that the count is FOUR and cannot be turned
// up: AdamW has a parameter, a gradient, a first moment and a second moment,
// and the amsgrad variant adds exactly one more.
//
// Eleven scalar arguments, which is the other thing a synthetic kernel would not
// have produced. Each is a launch-block word, each is warp-uniform, and they
// compete for the same registers the window bases do.
#include "fusion.h"

__global__ void adamw(float *ALIGNED param, float *ALIGNED grad,
                      float *ALIGNED exp_avg, float *ALIGNED exp_avg_sq,
                      float lr, float beta1, float beta2, float eps,
                      float weight_decay, float bias_correction1,
                      float bias_correction2_rsqrt, int n) {
    unsigned stride = NTID_X * NCTAID_X;
    for (unsigned i = CTAID_X * NTID_X + TID_X; i < (unsigned)n; i += stride) {
        float g = grad[i];
        float p = param[i] * (1.0f - lr * weight_decay);   // decoupled decay
        float m = exp_avg[i] * beta1 + g * (1.0f - beta1);
        float v = exp_avg_sq[i] * beta2 + g * g * (1.0f - beta2);
        exp_avg[i] = m;
        exp_avg_sq[i] = v;
        float denom = __builtin_sqrtf(v) * bias_correction2_rsqrt + eps;
        param[i] = p - lr * bias_correction1 * m * ccv_recip(denom);
    }
}
