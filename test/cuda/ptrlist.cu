// F-22: pointers as values. Each lane builds a linked list of eight nodes in
// global memory, reverses it in place, walks it into a struct in its own
// frame, and searches it -- pointer phis, pointer stores of a select that is
// sometimes NULL, compares against NULL and between pointers, a pointer to a
// frame object passed down a call, and a pointer's low bits read as an
// integer. The pool starts 2 KiB below a window boundary, so nodes straddle
// it: a pointer read back from memory is normalized to the next window while
// the same address computed by indexing keeps a large offset, and only the
// flat address compares them equal. Executed by tools/check-ptrlist.sh.
#include "portable.h"

struct node {
  node *next;
  int val;
};

__device__ __noinline__ node *find(node *h, int v) {
  while (h && h->val != v)
    h = h->next;
  return h;
}

__device__ __noinline__ node *reverse(node *h) {
  node *p = 0;
  while (h) {
    node *n = h->next;
    h->next = p;
    p = h;
    h = n;
  }
  return p;
}

struct acc {
  int sum, count;
};

// a points into its caller's frame.
__device__ __noinline__ void tally(const node *h, acc *a) {
  for (; h; h = h->next) {
    a->sum += h->val;
    a->count++;
  }
}

__global__ void ptrlist(node *pool, int *out) {
  int t = TID_X;
  node *base = pool + t * 8;
  for (int k = 0; k < 8; ++k) {
    base[k].val = t * 10 + k;
    base[k].next = k < 7 ? &base[k + 1] : 0;
  }
  node *h = reverse(base);
  acc a = {0, 0};
  tally(h, &a);
  node *f = find(h, t * 10 + (t & 7));
  node *g = find(h, -1);
  unsigned al = (unsigned)(unsigned long)&f->val & 15;
  out[4 * t + 0] = a.sum;
  out[4 * t + 1] = a.count;
  out[4 * t + 2] = f ? f->val : -1;
  out[4 * t + 3] = (g == 0) + 2 * (h == &base[7]) + 4 * al;
}
