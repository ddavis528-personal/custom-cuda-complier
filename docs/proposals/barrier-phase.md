# F-30 — `bar.wait`'s phase parity cannot be an immediate

**Status:** open, needs an ISA decision. Blocks the Step 4 reduction kernel.
**Touches:** O-12, §3 Format K point 52.

## The problem

O-12 settled the barrier operand split and put the phase parity in the
instruction:

| point | operation | payload |
|---|---|---|
| 51 | `bar.arrive #id` | `[13:8]` = 6-bit barrier ID |
| 52 | `bar.wait #id, phase` | `[13:8]` = barrier ID, `[14]` = phase parity |

and justified it this way:

> the phase parity is **software-tracked** — the compiler alternates the bit
> each time through the loop, and the comparator matches it against the table
> entry's epoch parity.

**The compiler cannot do that.** The bit is an immediate, fixed when the
instruction is assembled. The barrier's epoch parity flips on every completion,
so a `__syncthreads()` executed N times needs N alternating expected values —
and there is one encoded bit, which takes one value for all N executions.

The immediate is correct exactly when the barrier executes at most once per
kernel, or inside a loop the compiler fully unrolls by an even factor. Neither
covers the ordinary case.

This is not a corner case. The canonical reduction is:

```c
for (unsigned s = blockDim.x / 2; s > 0; s >>= 1) {
    if (tid < s) sdata[tid] += sdata[tid + s];
    __syncthreads();          // <-- executes log2(blockDim.x) times
}
```

The compiler currently diagnoses this rather than emitting a wrong phase
(`test/reject/barrier-in-loop.ll`). Every other piece of that kernel now
compiles: unsigned compares, FP compares, FP constants, cross-block window
arithmetic, and the `bar.arrive`/`bar.wait` pair itself.

**O-12 anticipated exactly this.** It closed with "worth a check against the
settled barrier spec." This is that check, and it comes back negative for the
software-tracked reading.

## What still holds

The *encoding* is fine — O-12 said as much: "the encoding is safe either way;
the phase bit is cheap insurance and can be ignored by hardware that does not
need it." What fails is the argument that software tracking keeps per-warp
state out of the machine **for free**. It does not; it needs either a register
operand or hardware state.

The other two thirds of O-12 are untouched: `bar.arrive` genuinely needs only
an ID, and `bar.init` genuinely needs 32 bits.

## Options

### A. Hardware tracks the per-warp epoch; the phase bit becomes advisory

This is the alternative O-12 already named and rejected on storage grounds.
`bar.wait #id` blocks until the warp's own arrival epoch has retired, and the
encoded bit is ignored.

- **Encoding change:** none. Point 52 keeps its layout; bit `[14]` becomes
  don't-care, or is repurposed later.
- **Compiler cost:** none. The diagnostic is deleted and `__syncthreads()`
  lowers to `bar.arrive` + `bar.wait` anywhere.
- **Hardware cost:** one bit per (resident warp × barrier entry). At 64 barrier
  entries and, say, 64 resident warps, that is 4096 bits per SM — 512 bytes.
  O-12 objected to this as "small-state-times-large-multiplicity", which is the
  right instinct in general; here the multiplicand is one bit.
- This is what NVIDIA's `mbarrier` hardware does.

### B. The phase comes from a predicate register

`bar.wait #id, ps` — the ID at `[13:8]` and a 2-bit predicate address at
`[15:14]`, which is the part of the Format K payload `bar.wait` does not use.
The compiler keeps the phase in a predicate and flips it each iteration.

- **Encoding change:** reinterpret `[15:14]`, inside the existing point. No
  format change, no new point, no field move. Invariant 8 is untouched because
  Format K is already exempt from the canonical-slot rule.
- **Compiler cost:** one predicate register held live across the loop, plus one
  16-bit `pxor` per barrier per iteration to flip it. At 4 predicates that is a
  quarter of the file, in exactly the kernels that also want predicates for
  divergence — which is the pressure Step 4 exists to measure.
- **Hardware cost:** none beyond reading a predicate, which every predicated
  instruction already does. Note the predicate is warp-uniform here, so only
  one lane's bit is meaningful; that is a slightly odd use of a 32-bit
  per-lane resource.

### C. Keep the immediate, require even unrolling

Rejected. It makes a correctness property depend on an optimisation, and it
doubles code size in the loops that use barriers most.

## Recommendation

**Option A.** The storage is one bit per warp per barrier entry, which is a
different order of magnitude from the register-file costs O-12's instinct was
formed on — and it buys back a predicate register and an instruction per
iteration in precisely the kernels where both are scarcest. It also needs no
encoding change at all, so it is reversible: if the barrier design turns out to
want software tracking after all, bit `[14]` is still there and Option B is
still available inside the same opcode point.

The compiler work is identical either way and is already done up to the
diagnostic; A deletes it, B replaces it with a predicate-allocation path.
