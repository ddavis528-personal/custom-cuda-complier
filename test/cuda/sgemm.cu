// Step 5: tiled SGEMM. The per-thread accumulator tile is the measurement --
// it is what drives register count on every GPU, and §1 names FP32
// accumulation as the case with no mitigation (dp4.acc helps INT8, and
// nothing helps this).
//
// TM x TN is the per-thread C tile, set from the command line so O-25's sweep
// is a recompile rather than a rewrite.
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

// One warp per block, so the simulator can execute what it measures. BX*BY=32.
#define BX 8
#define BY 4
#define KT 8                       // K-tile depth staged through shared memory

// Indexing is one-dimensional: srd supplies %ctatid as a flat index (§5.3),
// and a y dimension would be launch-block state this ABI has not specified.
// `bpr` (blocks per row) is a kernel argument rather than a division of N,
// because §4 has no integer divide -- the expansion is ~30 instructions and
// does not belong in an index computation.
__global__ void sgemm(float *__attribute__((align_value(65536))) C,
                      const float *__attribute__((align_value(65536))) A,
                      const float *__attribute__((align_value(65536))) B,
                      int N, int bpr) {
    __shared__ float As[KT][BY * TM];
    __shared__ float Bs[KT][BX * TN];

    unsigned t  = threadIdx.x;
    unsigned tx = t % BX, ty = t / BX;
    unsigned brow = (unsigned)blockIdx.x / (unsigned)bpr;
    unsigned bcol = (unsigned)blockIdx.x - brow * (unsigned)bpr;
    unsigned row0 = brow * (BY * TM) + ty * TM;
    unsigned col0 = bcol * (BX * TN) + tx * TN;

    float acc[TM][TN];
#pragma unroll
    for (int i = 0; i < TM; ++i)
#pragma unroll
        for (int j = 0; j < TN; ++j)
            acc[i][j] = 0.0f;

    for (int k0 = 0; k0 < N; k0 += KT) {
        // Stage one K-tile. 32 threads cover BY*TM rows and BX*TN columns.
#pragma unroll
        for (int i = 0; i < TM; ++i)
            As[t % KT][ty * TM + i] = A[(row0 + i) * N + (k0 + t % KT)];
#pragma unroll
        for (int j = 0; j < TN; ++j)
            Bs[t % KT][tx * TN + j] = B[(k0 + t % KT) * N + (col0 + j)];
        __syncthreads();

#pragma unroll
        for (int k = 0; k < KT; ++k) {
            float a[TM], b[TN];
#pragma unroll
            for (int i = 0; i < TM; ++i) a[i] = As[k][ty * TM + i];
#pragma unroll
            for (int j = 0; j < TN; ++j) b[j] = Bs[k][tx * TN + j];
#pragma unroll
            for (int i = 0; i < TM; ++i)
#pragma unroll
                for (int j = 0; j < TN; ++j)
                    acc[i][j] += a[i] * b[j];
        }
        __syncthreads();
    }

#pragma unroll
    for (int i = 0; i < TM; ++i)
#pragma unroll
        for (int j = 0; j < TN; ++j)
            C[(row0 + i) * N + (col0 + j)] = acc[i][j];
}
