// SwiGLU / `silu_and_mul`. TWO tensors, and that is the interesting part.
//
// Shaped after vLLM's `silu_and_mul_kernel`. The obvious way to write the gated
// MLP activation is `out = silu(gate) * up` with three pointers; the way it is
// actually written takes ONE input, because the gate and up projections are the
// two halves of a single `[N, 2d]` allocation produced by one matrix multiply.
// A synthetic fused kernel parameterised on "number of tensors" cannot produce
// that shape and would have counted this as three.
//
// So the cost is not three window bases. It is one base and a constant
// displacement of `d` elements -- which is precisely the Format D base+index
// displacement field that F-142 found the compiler was writing as zero.
#include "fusion.h"

__global__ void swiglu(float *ALIGNED out, const float *ALIGNED input, int d) {
    unsigned row = CTAID_X;
    unsigned in = row * 2u * (unsigned)d;
    unsigned o = row * (unsigned)d;
    for (unsigned i = TID_X; i < (unsigned)d; i += NTID_X)
        out[o + i] = ccv_silu(input[in + i]) * input[in + (unsigned)d + i];
}
