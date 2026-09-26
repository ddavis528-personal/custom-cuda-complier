// Division by COMPILE-TIME CONSTANTS, which nothing else tests.
//
// Every other division test divides by a runtime value, which is the path
// CCVExpandDivision handles. Constant divisors take a different route: for
// unsigned, instcombine strength-reduces them before the pass ever sees them;
// for signed it does NOT -- that is a DAGCombiner job -- so a signed constant
// divisor either gets the generic 17-instruction expansion or gets
// strength-reduced at isel, depending on what the pass chooses to claim.
//
// Either way the ANSWER has to be right, and no test checked it. The cases
// below are the ones that break naive strength reduction: negative dividends
// (C rounds toward zero, an arithmetic shift rounds toward -inf), INT_MIN, and
// negative divisors.
#define __global__ __attribute__((global))
#define ALIGNED __attribute__((align_value(65536)))
#include <__clang_cuda_builtin_vars.h>

__global__ void divconst(int *ALIGNED out, const int *ALIGNED in, int n) {
    unsigned i = threadIdx.x;
    int v = in[i];
    out[i * 8 + 0] = v / 16;      // signed, power of two
    out[i * 8 + 1] = v % 16;
    out[i * 8 + 2] = v / 7;       // signed, not a power of two
    out[i * 8 + 3] = v % 7;
    out[i * 8 + 4] = v / -16;     // negative divisor
    out[i * 8 + 5] = (int)((unsigned)v / 16u);   // unsigned, power of two
    out[i * 8 + 6] = (int)((unsigned)v / 7u);    // unsigned, not
    out[i * 8 + 7] = (int)((unsigned)v % 7u);
}
