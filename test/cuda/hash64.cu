// 64-bit integer kernels as CUDA code writes them (IS-13 (2)): splitmix64, the
// usual per-thread random stream, and FNV-1a over a 16-byte key. They are what
// tools/check-int64.sh measures add.cc/addc against: every 64-bit add or
// subtract here is today an add, a compare, an add and a predicated add.
#include "portable.h"

__device__ unsigned long long splitmix64(unsigned long long &s) {
  unsigned long long z = (s += 0x9E3779B97F4A7C15ull);
  z = (z ^ (z >> 30)) * 0xBF58476D1CE4E5B9ull;
  z = (z ^ (z >> 27)) * 0x94D049BB133111EBull;
  return z ^ (z >> 31);
}

__global__ void hash64(const unsigned *seed, const unsigned char *key,
                       unsigned *o, int n) {
  int i = TID_X;
  if (i >= n) return;
  unsigned long long s = ((unsigned long long)seed[i] << 32) | (unsigned)i;
  unsigned long long acc = 0;
#pragma unroll
  for (int k = 0; k < 8; ++k)
    acc += splitmix64(s);
  unsigned long long h = 0xCBF29CE484222325ull;
#pragma unroll
  for (int k = 0; k < 16; ++k) {
    h ^= key[16 * i + k];
    h *= 0x100000001B3ull;
  }
  o[4 * i] = (unsigned)acc;
  o[4 * i + 1] = (unsigned)(acc >> 32);
  o[4 * i + 2] = (unsigned)h;
  o[4 * i + 3] = (unsigned)(h >> 32);
}
