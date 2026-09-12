#define __global__ __attribute__((global))
#define __device__ __attribute__((device))
#include <__clang_cuda_builtin_vars.h>

__global__ void vadd(float *c, const float *a, const float *b, int n) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i < n) c[i] = a[i] + b[i];
}
