// IS-17 / ISA O-60: forward progress between diverged lanes of one warp.
//
// Lane 0 spins on a flag that lane 1 sets, and lane 1's store sits at a
// HIGHER PC than lane 0's spin loop. A scheduler that always issues the
// lowest-PC group (strict min-PC) never issues lane 1 again once lane 0 is in
// the loop, so the kernel hangs. O-60 says every diverged group of a live warp
// eventually issues, so under any fairness rule it finishes. This is the
// lock-handoff shape -- a waiter at a lower PC than the code that releases it
// -- written with a volatile flag because atomics are not yet lowered (F-118).
//
// The PC order is what the test rests on, so check-spinwait.sh asserts it on
// the emitted code rather than assuming it.
#include "portable.h"

__global__ void spinwait(volatile int *flag, int *out) {
  int t = TID_X;
  if (t == 0) {
    int spins = 0;
    while (*flag == 0)          // lower PC: the waiter
      ++spins;
    out[0] = spins > 0 ? 1 : 2; // 1: it really waited
  } else if (t == 1) {
    out[1] = 7;
    *flag = 1;                  // higher PC: the releaser
  }
}
