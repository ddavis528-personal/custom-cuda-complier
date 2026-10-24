#include "portable.h"
#define __host__ __attribute__((host))
#pragma clang force_cuda_host_device begin
extern "C" {
#include "coremark.h"
}
#pragma clang force_cuda_host_device end
extern "C" __host__ __device__ ee_s32 portme_sys1(void) { return 0; }
extern "C" __host__ __device__ ee_s32 portme_sys2(void) { return 0; }
extern "C" __host__ __device__ ee_s32 portme_sys3(void) { return 0x66; }
extern "C" __host__ __device__ ee_s32 portme_sys4(void) { return 1; }
extern "C" __host__ __device__ ee_s32 portme_sys5(void) { return 0; }
extern "C" __host__ __device__ void *iterate(void *) { return 0; }
// One CoreMark context per lane: each runs list, matrix and state on its own
// 2000-byte block, and writes its four CRCs.
__global__ void coremark(ee_u8 *mem, ee_u16 *out, int iterations) {
  int t = TID_X;
  core_results r;
  // CCV_SEED_PER_LANE: lane t seeds with t, so the lanes take their own
  // data-dependent paths and the warp diverges (CP-43, O-81). Otherwise every
  // lane runs CoreMark's performance-run seeds and the warp never diverges.
#ifdef CCV_SEED_PER_LANE
  r.seed1 = t;
#else
  r.seed1 = 0;
#endif
  r.seed2 = 0; r.seed3 = 0x66; r.iterations = iterations;
  r.execs = ALL_ALGORITHMS_MASK;
  r.size = TOTAL_DATA_SIZE / NUM_ALGORITHMS;
  ee_u8 *b = mem + t * TOTAL_DATA_SIZE;
  r.memblock[0] = b;
  for (int i = 0; i < NUM_ALGORITHMS; ++i)
    r.memblock[i + 1] = b + r.size * i;
  r.list = core_list_init(r.size, (list_head *)r.memblock[1], r.seed1);
  core_init_matrix(r.size, r.memblock[2], (ee_s32)r.seed1 | (((ee_s32)r.seed2) << 16), &r.mat);
  core_init_state(r.size, r.seed1, (ee_u8 *)r.memblock[3]);
  r.crc = 0; r.crclist = 0; r.crcmatrix = 0; r.crcstate = 0;
  for (ee_u32 i = 0; i < r.iterations; ++i) {
    ee_u16 c = core_bench_list(&r, 1);
    r.crc = crcu16(c, r.crc);
    c = core_bench_list(&r, -1);
    r.crc = crcu16(c, r.crc);
    if (i == 0) r.crclist = r.crc;
  }
  out[4 * t + 0] = r.crc;
  out[4 * t + 1] = r.crclist;
  out[4 * t + 2] = r.crcmatrix;
  out[4 * t + 3] = r.crcstate;
}
