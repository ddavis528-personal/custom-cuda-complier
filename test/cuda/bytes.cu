// F-161: byte memory access, at chwidth 8 (§3 takes a transfer's size from
// rdata's width). Signed bytes summed into an int (sign extension), unsigned
// bytes mixed into a CRC-8 step (zero extension), a string copied to its
// terminator, and 32 lanes each storing one byte of a shared word -- which a
// 32-bit store, or a read-modify-write of the word, would clobber. A byte
// array in .shared and one in the thread's frame, both indexed at run time.
// And a `short` stored in a different block from the 32-bit compare that
// widened it: the store must narrow it again or it moves four bytes over its
// neighbour (F-164).
// Executed by tools/check-bytes.sh.
#include "portable.h"

__global__ void bytes(const signed char *in, const unsigned char *str,
                      unsigned char *packed, int *out, const short *h,
                      short *hout) {
  __shared__ unsigned char sh[64];
  int i = TID_X;
  // Signed: in[] holds negative bytes.
  int s = 0;
  for (int k = 0; k < 4; ++k)
    s += in[(i + k) & 15];
  // Unsigned, CRC-8 (poly 0x07) over four bytes.
  unsigned crc = 0;
  for (int k = 0; k < 4; ++k) {
    crc ^= (unsigned char)in[(i * 3 + k) & 15];
    for (int b = 0; b < 8; ++b)
      crc = crc & 0x80 ? ((crc << 1) ^ 0x07) & 0xff : (crc << 1) & 0xff;
  }
  // A string, copied into the frame up to its terminator, then measured.
  unsigned char buf[16];
  int n = 0;
  while (n < 15 && str[n + (i & 3)] != 0) {
    buf[n] = str[n + (i & 3)];
    ++n;
  }
  buf[n] = 0;
  int len = 0;
  while (buf[len])
    ++len;
  // Each lane writes one byte of a word its neighbours write too.
  packed[i] = (unsigned char)(i * 7 + 1);
  // A short, kept only when non-zero; the compare widens it, the store is in
  // the next block.
  short hv = h[i];
  if (hv != 0)
    hout[i] = hv;
  // .shared, written and read back reversed.
  sh[i] = (unsigned char)(200 + i);
  SYNC();
  int r = sh[31 - i];
  out[4 * i + 0] = s;
  out[4 * i + 1] = (int)crc;
  out[4 * i + 2] = len * 1000 + buf[len - 1];
  out[4 * i + 3] = r;
}
