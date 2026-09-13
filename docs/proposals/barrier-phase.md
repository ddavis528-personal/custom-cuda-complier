# F-30 — `bar.wait`'s phase parity cannot be an immediate

**Status:** RESOLVED — see O-27. Both options were adopted, for different reasons.
Kept for the reasoning; the recommendation at the end is what was decided.
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


---

## Resolution (O-27)

**Both**, and not as belt-and-braces — the review point was that A and B answer
different questions and neither subsumes the other.

**A is adopted for `__syncthreads()`.** The per-warp arrival epoch is tracked in
hardware, the compressed `bar.wait #id` carries no phase operand at all, and
`[14]` becomes reserved. The reduction kernel's in-loop barrier compiles;
`test/reject/barrier-in-loop.ll` became `test/accept/barrier-in-loop.ll`.

**B is adopted as a separate instruction**, `bar.wait.phase #id, ps`, at Format E
opcode `00100` — not as a reinterpretation of the Format K payload. Putting it in
the 32-bit format rather than squeezing it into the compressed one turned out to
be strictly better:

- The compressed payload had 2 spare bits and needed 3 (a source-select bit plus
  a 2-bit predicate address). Shrinking the barrier ID to fit would have broken
  the 64-entry table.
- Format E has 28 free opcode points and room for the barrier ID at `[16:11]`,
  the *same field `bar.init` uses*, so no operand moves.
- It gets a predicate **qualifier** at `[29:27]` as well as the predicate
  **source**. Compressed forms are never predicated, so the Format K wait cannot
  be guarded — and warp-specialised kernels, which are exactly the ones that
  need explicit phases, also need the wait to be guarded.

The argument that settled it is in O-27: hardware epoch tracking answers "has my
own arrival retired?", which is all of bulk sync and none of a pipelined
producer/consumer, where a warp arrives at one barrier and waits on another. A
split barrier whose wait can only target your own arrival is a fused barrier with
extra steps.
