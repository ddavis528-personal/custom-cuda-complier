// The SFU group, reached the way a CUDA kernel actually reaches it (F-141).
//
// §4 allocates eight special-function points and the simulator has implemented
// all of them since it existed, but five were unreachable from CUDA: the
// production-path gate carried them as `todo` with the reason "clang emits a
// libm call and there is no calling sequence yet". That reason described
// `expf(x)`, and no GPU kernel on a fast path writes `expf(x)`. It writes
// `__expf` / `__sinf` / `rsqrtf`, or it is built with fast-math, and every one
// of those arrives in LLVM IR as an intrinsic -- which needs no calling
// sequence and lands straight on a pattern.
//
// Both pointers are window-aligned (O-23): `o[i*5+k]` is a window, an index
// and a constant displacement, and an unaligned pointer would add an in-window
// offset on top of that -- four addends into a three-input AGU (§5.1).
//
// Five outputs per lane rather than five kernels, so that one compile and one
// execution cover the whole group and a selection swap between two of them --
// the failure a pattern table makes easy -- has somewhere to show up.
#define __global__ __attribute__((global))
#include <__clang_cuda_builtin_vars.h>

__global__ void sfu(float *__attribute__((align_value(65536))) o,
                    const float *__attribute__((align_value(65536))) a, int n) {
    int i = threadIdx.x;
    float v = a[i];
    o[i * 5 + 0] = __builtin_exp2f(v);        // ex2.f32   (this is __expf's core)
    o[i * 5 + 1] = __builtin_log2f(v);        // lg2.f32
    o[i * 5 + 2] = __nvvm_rsqrt_approx_f(v);  // rsqrt.f32 (this is rsqrtf)
    o[i * 5 + 3] = __nvvm_sin_approx_f(v);    // sin.f32   (this is __sinf)
    o[i * 5 + 4] = __nvvm_cos_approx_f(v);    // cos.f32   (this is __cosf)
}
