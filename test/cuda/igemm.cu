// Step 5's accumulator-tile sweep, INT8 half (F-113).
//
// The same shape as sgemm.cu -- same tiling, same staging, same TM x TN
// per-thread accumulator tile -- so the only difference between the two
// measurements is the arithmetic. That is the point: `gpr-count-decision.md`
// credits `dp4.acc` with making 16 GPRs sufficient under INT8 accumulator
// pressure, on the grounds that it does four MACs per accumulator register,
// and the claim is only testable against an FP32 kernel of the same shape.
//
// A and B hold INT8 packed four-per-word along K, which is how a quantized
// GEMM stores them; C is INT32. So one K step here covers four of sgemm's,
// and the accumulator count is still TM*TN. The dot product is written out
// rather than called through `__dp4a`: LLVM 18 has no dp4a intrinsic, and the
// backend forms `dp4.ss` from this shape in a DAG combine (F-121).
#define __global__ __attribute__((global))
#define __device__ __attribute__((device))
#define __shared__ __attribute__((shared))
#include <__clang_cuda_builtin_vars.h>

#ifndef TM
#define TM 2
#endif
#ifndef TN
#define TN 2
#endif

#define BX 8
#define BY 4
#define KT 8                       // K-tile depth in PACKED words, so 4*KT int8

__device__ static inline int dp4(int x, int y, int acc) {
    acc += (int)(signed char)(x >> 0)  * (int)(signed char)(y >> 0);
    acc += (int)(signed char)(x >> 8)  * (int)(signed char)(y >> 8);
    acc += (int)(signed char)(x >> 16) * (int)(signed char)(y >> 16);
    acc += (int)(signed char)(x >> 24) * (int)(signed char)(y >> 24);
    return acc;
}

__global__ void igemm(int *__attribute__((align_value(65536))) C,
                      const int *__attribute__((align_value(65536))) A,
                      const int *__attribute__((align_value(65536))) B,
                      int N, int bpr) {
    __shared__ int As[KT][BY * TM];
    __shared__ int Bs[KT][BX * TN];

    unsigned t  = threadIdx.x;
    unsigned tx = t % BX, ty = t / BX;
    unsigned brow = (unsigned)blockIdx.x / (unsigned)bpr;
    unsigned bcol = (unsigned)blockIdx.x - brow * (unsigned)bpr;
    unsigned row0 = brow * (BY * TM) + ty * TM;
    unsigned col0 = bcol * (BX * TN) + tx * TN;

    int acc[TM][TN];
#pragma unroll
    for (int i = 0; i < TM; ++i)
#pragma unroll
        for (int j = 0; j < TN; ++j)
            acc[i][j] = 0;

    for (int k0 = 0; k0 < N; k0 += KT) {
        // Flat index over the tile, for the reason sgemm.cu gives: (t % KT,
        // tx) collide when BX == KT and stage only the diagonal (F-134).
#pragma unroll
        for (unsigned idx = t; idx < KT * (BY * TM); idx += BX * BY) {
            unsigned kk = idx / (BY * TM), rr = idx % (BY * TM);
            As[kk][rr] = A[(brow * (BY * TM) + rr) * N + (k0 + kk)];
        }
#pragma unroll
        for (unsigned idx = t; idx < KT * (BX * TN); idx += BX * BY) {
            unsigned kk = idx / (BX * TN), cc = idx % (BX * TN);
            Bs[kk][cc] = B[(k0 + kk) * N + (bcol * (BX * TN) + cc)];
        }
        __syncthreads();

#pragma unroll
        for (int k = 0; k < KT; ++k) {
            int a[TM], b[TN];
#pragma unroll
            for (int i = 0; i < TM; ++i) a[i] = As[k][ty * TM + i];
#pragma unroll
            for (int j = 0; j < TN; ++j) b[j] = Bs[k][tx * TN + j];
#pragma unroll
            for (int i = 0; i < TM; ++i)
#pragma unroll
                for (int j = 0; j < TN; ++j)
                    acc[i][j] = dp4(a[i], b[j], acc[i][j]);
        }
        __syncthreads();
    }

#pragma unroll
    for (int i = 0; i < TM; ++i)
#pragma unroll
        for (int j = 0; j < TN; ++j)
            C[(row0 + i) * N + (col0 + j)] = acc[i][j];
}
