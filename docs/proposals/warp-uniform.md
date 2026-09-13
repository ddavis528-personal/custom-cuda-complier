# Warp-uniform execution: three designs, and what the measurement says

**Status:** open, for decision. Measured with `ccg-llc -ccg-uniformity-stats`
(O-25's warp-invariance reporting, finally implemented) and
`ccg-sim -counters`.
**Touches:** O-25, §1's "one live risk", F-52.

---

## 1. The measurement

O-25 said warp-invariance reporting was "the only evidence that would size a
warp-uniform register file". Here it is. *Warp*-uniform, not grid-uniform —
every lane of a warp is in one CTA, so `ctaid` and `ntid` are uniform and only
`tid` is not. LLVM's stock NVPTX answer calls `ctaid` divergent, which is right
across a grid and wrong here; `CCGTTIImpl` supplies the warp-scoped notion.

| kernel | instructions | warp-uniform | lane-activations wasted | peak uniform live |
|---|---|---|---|---|
| `vadd` | 25 | 14 (56%) | 54% | 4 |
| `saxpy` | 23 | 12 (52%) | 50% | 4 |
| `dot` | 47 | 26 (55%) | 53% | 6 |
| `reduce` | 41 | 23 (56%) | 54% | 5 |
| `transpose` | 76 | 57 (**75%**) | 72% | 10 |
| `sgemm` 2×4 | 345 | 48 (**14%**) | 13% | 11 |

"Lane-activations wasted" is the uniform fraction × 31/32: the energy spent
computing the same value in 32 lanes when one would do.

**Three things fall out, and the third is the one that matters.**

**Addressing-dominated kernels are majority uniform.** Half of everything these
kernels do is computed 32 times identically. `transpose` is 75% — which is
exactly why AMD's scalar unit beat us there (F-52). The measurement turns that
diagnosis into a number.

**GEMM is only 14% uniform.** The arithmetic dominates and it is genuinely
per-lane. So the uniform-register-file argument is **weakest exactly where
register pressure is worst**, which is the opposite of how O-25 framed it: §1
proposed the uniform file as the response *if GEMM spills too much*, and GEMM
is the kernel it helps least.

**Peak uniform values live is 4–11.** §1 guessed a 16-entry uniform file
without evidence. The evidence says 16 is comfortable, with 11 at the high end.

---

## 2. Option A — predicate to lane 0, then broadcast

No new architectural state. Execute uniform work with a lane-0-only predicate
and broadcast the result:

```
    pmov       P3, #1              ; 48  lane 0 only -- loop-invariant, hoist it
    @P3 <uniform op 1>             ;     one lane active
    @P3 <uniform op 2>
    ...
    shfl.idx   Rd, Rd, 0           ; 32  broadcast lane 0 to all
```

**What it buys: energy, and only energy.** If the datapath gates on the
execution mask — which it must, to implement predication at all — then 54% of
lane-activations become 54%/32. That is a real saving and it is the largest
single number in the table above.

**What it does not buy, and these matter:**

- **Register-file space is unchanged.** The value still occupies a full
  1024-bit row to hold 32 bits. §1's argument for the uniform file — "currently
  occupy full 1024-bit rows to hold 32 bits of real information" — survives
  untouched.
- **Issue bandwidth is unchanged.** It is still one instruction in the vector
  unit, one issue slot, one cycle. AMD's SALU issues **in parallel** with the
  VALU; uniform work there is genuinely off the critical path. Masking cannot
  produce a second issue port.
- **Instruction count gets worse.** Add one `shfl.idx` per value crossing from
  uniform to divergent use, plus the `pmov`.

**And two costs specific to this ISA:**

`pmov` is the only constant-to-predicate path and it is **48 bits** (Format I,
no 32-bit form — the lane mask does not fit). Loop-invariant, so hoistable, but
it is not free.

`shfl.idx` is **predicated-only** (Format G; §3 notes "unpredicated live in K",
but Format K has `vote` and `ballot` and no shuffle). So every broadcast also
needs a true predicate — the O-24 tax that O-32 just removed from compares
would come straight back on the broadcast path. See F-55.

**Verdict: worth having, not sufficient.** It is a real energy win available
with zero architectural change, and it should be measured on hardware before
anything more expensive is built. It does not address the register-file
argument at all.

---

## 3. The observation that reframes the whole question

**A uniform register file needs a broadcast too** — and how it provides one is
the entire design, not a detail.

AMD does not have a broadcast *instruction*. A VALU instruction can name an
SGPR directly as a source operand, and the hardware broadcasts it across the
wavefront for free. The cost is not an instruction; it is **one bit per source
operand field** saying which file that operand comes from.

That is the fork:

| | uniform→vector crossing | encoding cost |
|---|---|---|
| **A.** mask + shuffle | one `shfl` + a guard | none |
| **B.** uniform file, explicit moves | one move instruction | an opcode point or two |
| **C.** uniform file, uniform operands | **free** | one bit per source field |

§1's sketch — "it reuses the existing 4-bit field width under a different
namespace, so every settled encoding holds" — describes **B**, and B is the
worst of the three. It pays the register-file win back in move instructions at
every crossing, and the table in §1 shows crossings are frequent.

**C is what makes a uniform file worth having, and C costs encoding space this
ISA no longer has spare.** Format A's sources are `rs0`, `rs1`, `rs2` at 4 bits
each; a per-operand file bit is 3 more bits. Format A's opcode is 10 bits with
256 of 1024 points allocated, so three bits could come from there — at the cost
of dropping to 128 points and losing the conversion and SFU ranges O-31 just
opened. One bit covering `rs1` only (the common "vector op with one uniform
operand" shape) is far cheaper and covers most of the benefit.

---

## 4. Recommendation

**Do A now; it is free.** A backend pass that predicates uniform regions to lane
0 and broadcasts at the boundary needs no ISA change. The uniformity analysis
that identifies those regions is already implemented. Measure it, and fix F-55
(an unpredicated shuffle) so the broadcast does not reintroduce the O-24 tax.

**Do not do B.** It pays the win back at every crossing.

**Decide C on GEMM data, not on these kernels.** The energy argument for
scalar execution is strongest where uniformity is highest (`transpose`, 75%)
and the register-pressure argument is strongest where it is lowest (`sgemm`,
14%). They point at different kernels, and C is the only option that serves
both. Whether one bit of Format A is worth it depends on how much of the GEMM's
remaining pressure is uniform — which is now measurable, and is not measured
yet because the sweep reports spill volume rather than spill *by uniformity*.
