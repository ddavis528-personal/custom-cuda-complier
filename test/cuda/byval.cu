// A by-value parameter struct, which is an ordinary CUDA idiom and was a silent
// miscompile (F-147).
//
// clang passes `Params p` as `ptr byval(%struct.Params)`: the struct's BYTES
// are in the parameter space and the pointer is a fiction of the calling
// convention. CCVLowerKernelArgs tested `isPointerTy()`, so it classified the
// struct as a window index, spent a launch slot on it, and read every field
// from whatever window the struct's first four bytes happened to name.
//
// That compiled. It assembled, it round-tripped, and it read the wrong memory.
// Nothing static could have caught it -- the instructions are all valid and the
// addressing mode is the one a pointer argument legitimately uses -- so the
// check that pins it has to EXECUTE, and has to put values in the launch block
// that would name a different window if they were misread as one.
#include "portable.h"

struct Params {
    int n;
    int mul;
    float add;
    int unused;
};

__global__ void byval(float *ALIGNED out, const float *ALIGNED in, Params p) {
    unsigned i = TID_X;
    if (i < (unsigned)p.n)
        out[i] = in[i] * (float)p.mul + p.add;
}
