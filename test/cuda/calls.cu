// F-21: device functions that are really called, not inlined. Exercises a
// value return, a two-deep chain (the outer function must keep its own link
// value across the inner call), arguments in four registers, a short (i16)
// argument and return, and values live across calls in a loop -- the
// callee-saved convention's job -- and a local array in both a caller and its
// callee, live at once, which only the static frame layout keeps apart.
// Pointers cross calls too (F-22), as (rbase, roffset) pairs: read through,
// forwarded a level further with an offset added, and returned. Arguments past
// the sixth go on the callee's frame: a short among them, a function that
// takes stack arguments and passes others on while its own are still live,
// and a pointer whose pair straddles R6 and the first stack slot.
// Executed by tools/check-calls.sh.
#include "portable.h"

__device__ __noinline__ int mix(int a, int b, int c, int d) {
  return (a * 3 + b) ^ (c - d);
}

__device__ __noinline__ short half_step(short x) { return (short)(x + 3); }

__device__ __noinline__ int chain(int x, int k) {
  // Two calls, and x, k and the first result live across the second.
  int m = mix(x, k, x + 7, k - 2);
  int h = half_step((short)x);
  return m + h + x * k;
}

// Several 16-bit temporaries, so the callee narrows more than one register --
// and its caller then does 32-bit work in registers it is free to reuse. Every
// register must be 32 bits wide again when the callee returns.
__device__ __noinline__ short narrow3(short a, short b, short c) {
  short x = a + b, y = c - a, z = x ^ y;
  return z + c;
}

// A frame of its own: t[] is dynamically indexed, so it stays in memory.
__device__ __noinline__ int scratch(int x, int j) {
  int t[4];
  for (int k = 0; k < 4; ++k)
    t[k] = x * (k + 2) + 100;
  return t[j & 3];
}

__device__ __noinline__ int sum3(const int *p, int k) {
  return p[k] + p[k + 1] + p[k + 2];
}
// Forwards its own pointer parameter, moved by one element.
__device__ __noinline__ int sum3_via(const int *p, int k) { return sum3(p + 1, k); }
__device__ __noinline__ int *advance(int *p, int n) { return p + n; }

__device__ __noinline__ int many(int a, int b, int c, int d, int e, int f,
                                 int g, short h, int k) {
  return a - b * 2 + c * 3 - d * 4 + e * 5 - f * 6 + g * 7 - h * 8 + k * 9;
}
// g and h arrive on its frame and are read again after it calls many, whose
// own stack arguments are written below it.
__device__ __noinline__ int many2(int a, int b, int c, int d, int e, int f,
                                  int g, int h) {
  int r = many(h, g, f, e, d, c, b, (short)a, g + h);
  return r + g * h;
}
// p is the sixth parameter, so its rbase is in R6 and its roffset on the stack.
__device__ __noinline__ int pick(int a, int b, int c, int d, int e,
                                 const int *p) {
  return p[a & 3] + b - c + d - e;
}

__global__ void calls(const int *in, int *out, int n) {
  int i = TID_X;
  if (i >= n) return;
  int acc = 0;
  int v = in[i];
  for (int k = 0; k < 4; ++k)      // acc, v, k and i live across every call
    acc += chain(v + k, k + 1);
  // buf[] lives in the kernel's frame across the call; scratch's t[] must not
  // land on it.
  int buf[4];
  for (int k = 0; k < 4; ++k)
    buf[k] = v * 7 + k;
  int s = scratch(v, i);
  int w = narrow3((short)v, (short)(v >> 3), (short)i);
  int p0 = v * 3, p1 = v ^ i, p2 = v - i * 5, p3 = v + 99, p4 = i * i;
  int q = p0 * p1 + p2 * p3 + p4 * w + (p0 ^ p3) + (p1 - p4);
  int s3 = sum3_via(in, i & 7);
  int *o = advance(out, i);          // == &out[i], through a returned pair
  int m = many2(v, i, v ^ i, v + 1, i * 3, v - 7, i + 11, v >> 2);
  int pk = pick(i, v, i * 5, 13, v >> 4, in + 2);
  *o = acc + s * 3 + buf[(i + 1) & 3] + q + s3 + m + pk;
}
