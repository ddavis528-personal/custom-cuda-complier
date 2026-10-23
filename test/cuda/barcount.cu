// O-74: named barriers with a thread count, as warp-specialised CUDA writes
// them. 160 threads, five warps. Warps 0-1 produce into a double buffer in
// .shared and warps 2-3 consume it: barrier b (0, 1) says buffer b is full,
// 2 + b that it is empty, each counting 128 arrivals -- the producers'
// bar.arrive and the consumers' bar.sync, or the reverse. Warp 4 takes no
// part in them: it waits on barrier 4 for the consumers' 64 arrivals, then
// sums their results. Under the every-live-lane rule (no count) barrier 0
// would wait for warp 4, which waits for the consumers: a deadlock. The sync
// is clang's builtin (llvm.nvvm.barrier.sync.cnt), the arrive inline PTX as
// CUTLASS writes it, and warp 4's sync inline PTX with literal operands.
#include "portable.h"

#define ITER 8

__device__ inline __attribute__((always_inline)) void arrive(unsigned id, unsigned n) {
  asm volatile("bar.arrive %0, %1;" ::"r"(id), "r"(n) : "memory");
}

__global__ void barcount(const unsigned *in, unsigned *out) {
  __shared__ unsigned buf[2][64];
  int t = TID_X;
  if (t < 64) {
    for (int k = 0; k < ITER; ++k) {
      int b = k & 1;
      if (k >= 2)
        __nvvm_barrier_sync_cnt(2 + b, 128);   // buffer b is empty again
      buf[b][t] = in[k * 64 + t] * 3 + k;
      arrive(b, 128);                          // buffer b is full
    }
  } else if (t < 128) {
    int c = t - 64;
    unsigned acc = 0;
    for (int k = 0; k < ITER; ++k) {
      int b = k & 1;
      __nvvm_barrier_sync_cnt(b, 128);
      acc += buf[b][c];
      arrive(2 + b, 128);
    }
    out[c] = acc;
    arrive(4, 96);
  } else {
    asm volatile("bar.sync 4, 96;" ::: "memory");
    int l = t - 128;
    out[64 + l] = out[l] + out[32 + l];
  }
}
