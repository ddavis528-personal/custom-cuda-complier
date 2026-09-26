#define __global__ __attribute__((global))
#include <__clang_cuda_builtin_vars.h>
__global__ void k(int *c, const int *a, const int *b, int n) {
    int i = threadIdx.x;
    int acc = c[i];
    int x = a[i], y = b[i];
    // The four-byte dot product, written out. This is what a quantized inner
    // loop looks like before anything recognises it.
    acc += (int)(signed char)(x >> 0)  * (int)(signed char)(y >> 0);
    acc += (int)(signed char)(x >> 8)  * (int)(signed char)(y >> 8);
    acc += (int)(signed char)(x >> 16) * (int)(signed char)(y >> 16);
    acc += (int)(signed char)(x >> 24) * (int)(signed char)(y >> 24);
    c[i] = acc;
}
