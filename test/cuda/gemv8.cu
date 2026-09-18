// Decode-shaped GEMV with INT8 weights (F-129).
//
// The realistic decode path: weights quantized to INT8 and packed four per
// word, activations likewise, accumulating INT32 through `dp4`. Same shape as
// gemv.cu so the two differ only in arithmetic -- one MAC per weight element
// either way, but four weight elements per word loaded, which is the whole
// point of quantizing for a bandwidth-bound kernel.
#include "portable.h"

#ifndef KT
#define KT 32                      // packed activation words staged per pass
#endif

__device__ static inline int dp4(int a, int b, int acc) {
    acc += (int)(signed char)(a >> 0)  * (int)(signed char)(b >> 0);
    acc += (int)(signed char)(a >> 8)  * (int)(signed char)(b >> 8);
    acc += (int)(signed char)(a >> 16) * (int)(signed char)(b >> 16);
    acc += (int)(signed char)(a >> 24) * (int)(signed char)(b >> 24);
    return acc;
}

__global__ void gemv8(int *ALIGNED y, const int *ALIGNED W,
                      const int *ALIGNED x, int K) {
    __shared__ int xs[KT];
    unsigned row = CTAID_X * NTID_X + TID_X;
    int acc = 0;
    for (int k0 = 0; k0 < K; k0 += KT) {
        if (TID_X < KT) xs[TID_X] = x[k0 + TID_X];
        SYNC();
#pragma unroll
        for (int k = 0; k < KT; ++k)
            acc = dp4(W[row * K + (k0 + k)], xs[k], acc);
        SYNC();
    }
    y[row] = acc;
}
