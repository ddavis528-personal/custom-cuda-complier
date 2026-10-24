// 64-bit integers (IS-13 (2)): long long through 32-bit pairs. Each lane builds
// x and y from two 32-bit inputs and writes 17 results, each as its low and
// high words, which tools/check-int64.sh compares with C's own semantics.
#include "portable.h"

__global__ void int64ops(const unsigned *a, const unsigned *b, unsigned *o,
                         int n) {
  int i = TID_X;
  if (i >= n) return;
  unsigned long long x = ((unsigned long long)a[i] << 32) | b[i];
  unsigned long long y = ((unsigned long long)b[i] << 32) | a[(i + 1) % n];
  long long sx = (long long)x, sy = (long long)y;
  unsigned s = b[i] & 63;
  unsigned long long r[17] = {
      x + y,
      x - y,
      x * y,
      x >> 7,
      x << s,
      x >> s,
      (unsigned long long)(sx >> s),
      x < y ? x : y,
      sx < sy ? x : y,
      x / (y | 1),
      x % (y | 1),
      (unsigned long long)(sx / (sy | 1)),
      (unsigned long long)(sx % (sy | 1)),
      x % 1000,
      (unsigned long long)(sx / -7),
      x == y,
      (unsigned long long)a[i] * b[i] + x,
  };
#pragma unroll
  for (int k = 0; k < 17; ++k) {
    o[34 * i + 2 * k] = (unsigned)r[k];
    o[34 * i + 2 * k + 1] = (unsigned)(r[k] >> 32);
  }
}
