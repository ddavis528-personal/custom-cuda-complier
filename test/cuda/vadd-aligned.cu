// Same kernel, with the alignment the runtime can vouch for declared per
// argument (O-23). clang's align_value lowers to LLVM's align parameter
// attribute; the backend queries alignment, not the attribute.
#define __global__ __attribute__((global))
#define ALIGNED __attribute__((align_value(65536)))
#include <__clang_cuda_builtin_vars.h>

__global__ void vadd(float *ALIGNED c, const float *ALIGNED a,
                     const float *ALIGNED b, int n) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i < n) c[i] = a[i] + b[i];
}
