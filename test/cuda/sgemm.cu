// Step 5: tiled SGEMM. The accumulator tile is the point -- it is what drives
// register count on every GPU, and §1 names FP32 accumulation as the one case
// with no mitigation (dp4.acc helps INT8 and nothing helps this).
//
// TM x TN is the per-thread C tile, set from the command line so the sweep
// O-25 asks for is a recompile rather than a rewrite.
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
#define TILE 16

// Indexing is one-dimensional on purpose: srd supplies %ctatid as a flat index
// (§5.3), and a y dimension would be launch-block state this ABI has not
// specified yet. The tile mapping is arithmetic on the flat index instead.
__global__ void sgemm(float *__attribute__((align_value(65536))) C,
                      const float *__attribute__((align_value(65536))) A,
                      const float *__attribute__((align_value(65536))) B,
                      int N) {
    __shared__ float As[TILE][TILE];
    __shared__ float Bs[TILE][TILE];

    unsigned t  = threadIdx.x;
    unsigned tx = t % TILE, ty = t / TILE;
    unsigned row = (blockIdx.x / (unsigned)(N / (TILE * TM))) * (TILE * TM) + ty * TM;
    unsigned col = (blockIdx.x % (unsigned)(N / (TILE * TN))) * (TILE * TN) + tx * TN;

    float acc[TM][TN];
    for (int i = 0; i < TM; ++i)
        for (int j = 0; j < TN; ++j)
            acc[i][j] = 0.0f;

    for (int k0 = 0; k0 < N; k0 += TILE) {
        As[ty][tx] = A[(row + 0) * N + (k0 + tx)];
        Bs[ty][tx] = B[(k0 + ty) * N + (col + 0)];
        __syncthreads();

        for (int k = 0; k < TILE; ++k) {
            float a[TM], b[TN];
            for (int i = 0; i < TM; ++i) a[i] = As[ty * TM + i < TILE ? ty * TM + i : 0][k];
            for (int j = 0; j < TN; ++j) b[j] = Bs[k][tx * TN + j < TILE ? tx * TN + j : 0];
            for (int i = 0; i < TM; ++i)
                for (int j = 0; j < TN; ++j)
                    acc[i][j] += a[i] * b[j];
        }
        __syncthreads();
    }

    for (int i = 0; i < TM; ++i)
        for (int j = 0; j < TN; ++j)
            C[(row + i) * N + (col + j)] = acc[i][j];
}
