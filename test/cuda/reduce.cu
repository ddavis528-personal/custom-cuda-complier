// Block reduction: shared memory, barriers, a loop, and divergence.
// Step 4's first kernel -- the first real exercise of the predicate file.
#define __global__ __attribute__((global))
#define __device__ __attribute__((device))
#define __shared__ __attribute__((shared))
#include <__clang_cuda_builtin_vars.h>

__global__ void reduce(float *__attribute__((align_value(65536))) out,
                       const float *__attribute__((align_value(65536))) in,
                       int n) {
    __shared__ float sdata[256];
    unsigned tid = threadIdx.x;
    unsigned i = blockIdx.x * blockDim.x + tid;

    sdata[tid] = (i < (unsigned)n) ? in[i] : 0.0f;
    __syncthreads();

    for (unsigned s = blockDim.x / 2; s > 0; s >>= 1) {
        if (tid < s) sdata[tid] += sdata[tid + s];
        __syncthreads();
    }

    if (tid == 0) out[blockIdx.x] = sdata[0];
}
