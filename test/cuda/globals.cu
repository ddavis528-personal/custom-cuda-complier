// O-61 (CP-10): a module's globals, in one data image whose window is
// launch-block word 28. Constant tables read at a runtime index, a table of
// pointers to them (relocated at load), a float table, a table of structs with
// 16-bit fields, a writable array the loader zeroes, an initialized writable
// global, and a device function that reaches a global through its own read of
// word 28. Executed by tools/check-globals.sh.
#include "portable.h"
#define __constant__ __attribute__((constant))

__constant__ int row0[4] = {1, 2, 3, 4};
__device__ const int row1[4] = {10, 20, 30, 40};
__device__ const int *const rows[2] = {row0, row1};
__constant__ float scale[2] = {0.5f, 2.0f};
struct pt {
  short x;
  int y;
};
__device__ const pt pts[3] = {{1, -7}, {-2, 9}, {3, 100}};
__device__ int acc[32];
__device__ int bias = 5;

__device__ __noinline__ int via_callee(int i) {
  return pts[i % 3].x * pts[i % 3].y + bias;
}

__global__ void globals(int *out) {
  int i = TID_X;
  acc[i] += rows[i & 1][i & 3] + via_callee(i);
  out[2 * i] = acc[i];
  out[2 * i + 1] = (int)(scale[i & 1] * (float)i);
}
