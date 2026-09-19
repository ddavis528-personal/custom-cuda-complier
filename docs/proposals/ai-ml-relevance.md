# Proposal — three ISA additions weighed against what makes this machine relevant on AI/ML

**Status:** OPEN — for external review.
**Touches:** O-13, O-25, O-33, O-34, F-106, F-113, F-121, F-126, F-127, F-128, F-129, F-131, F-134, F-135, and §10's "out of scope for V1" list.
**Companion:** `warp-uniform.md`, which argued the third of these and should be read after §5 here rather than before.

---

## 0. Summary and strength of ask

| # | Ask | Strength |
|---|---|---|
| 1 | **FP packed dot-product-accumulate** (`dp2.bf16`, `dp2.f16` → FP32) at the eight free points of 48–63 | **Strong** |
| 2 | **Launch-block-relative addressing** — a Format D form whose base is a launch-block slot rather than a GPR | **Medium. Price it before deciding 3.** |
| 3 | **Warp-uniform register file** | **Weak as an immediate ask. Recommend deferring, with stated conditions to revive it.** |

Format H (tensor/MMA) is the strategic item behind all three and is **not** asked for here.
The compiler has nothing to contribute to its design yet — fragment layouts are the hard part
and no fragment has ever been formed. §6 says why it nonetheless frames the other three.

**The one-sentence version:** ask 1 is cheap, uses reserved space, and extends a mechanism
already shown to work; ask 2 targets the measured pain at a fraction of the surface of ask 3;
ask 3 is real but rests on the thinnest evidence in this document, and the compiler side does
not think it should be adopted on that evidence.

---

## 1. How this came up, and a retraction that matters to how you read the rest

`gpr-count-decision.md` settled 16 GPRs and named one live risk: FP32 GEMM accumulator
pressure, with a warp-uniform register file as the escape hatch *if that pressure binds*. It
asked for spill to be measured by cause. F-113 built that measurement. What followed was three
positions in one working session, and the review should know the order:

1. **F-126/F-128 argued FOR a uniform file**, reading `sweep-tiles.sh`'s pointer/index spill
   column (110 of 139 transfers at 2×4) beside the uniformity analysis's "peak uniform values
   live: 11" and concluding a uniform file would hold what was spilling.
2. **F-129 retracted it.** Both numbers were right and the conclusion did not follow. `sgemm`
   indexes by `threadIdx`, so its row and column offsets **differ per lane**. They are
   addresses and they are divergent, and a uniform file cannot hold a divergent value whatever
   role it plays. The uniformity pass now reports the split; at 2×4 the peak *divergent*
   working set is **95 values against a 16-entry file**.
3. The case that survives is narrower and is stated in §5.

The caveat that would have caught this was written down in F-126 — "the uniform count is an
IR-level ceiling, the spill classifier works on physical registers, they are not shown to be
the same eleven values" — and then argued past anyway. **Stating a caveat is not closing it**,
and the strength ratings below are set with that in mind.

---

## 2. What is measured, and what is not

Everything quantitative here comes from `tools/sweep-tiles.sh`, `tools/sweep-decode.sh`,
`tools/nv-tile-pressure.sh`, `tools/sweep-unroll.sh` and `ccv-llc -ccv-uniformity-stats`, all
regenerated into `benchmarks.md` by the gate rather than transcribed.

Two limits the review should apply throughout:

- **`fused.cu` is a kernel written for this measurement**, with the tensor count as a free knob
  whose range was also chosen here. It is a plausible shape, not a workload trace. It is the
  entire evidentiary basis for ask 3.
- **`sgemm` had never been executed until F-134**, which then found two bugs in it — a compiler
  miscompile that hung it, and a staging defect that meant it did not compute a matrix product.
  Every GEMM figure predating that is void. The ones below postdate it and the kernel is now
  executed against a matrix-product reference in the gate.

Peak simultaneously-live values, split by divergence, is the number the asks turn on:

| kernel | IR instrs | warp-uniform | peak uniform live | peak divergent live |
|---|---|---|---|---|
| `vadd` | 25 | 17 | 4 | 3 |
| `saxpy` | 23 | 14 | 4 | 3 |
| `dot` | 45 | 28 | 6 | 3 |
| `reduce` | 39 | 24 | 5 | 3 |
| `transpose` | 54 | 39 | 9 | 6 |
| `sgemm` 2×2 | 213 | 46 | 10 | **60** |
| `sgemm` 2×4 | 336 | 48 | 10 | **95** |
| `sgemm` 4×4 | 514 | 48 | 10 | **131** |

---

## 3. Ask 1 — FP packed dot-product-accumulate. **Strong.**

### The proposal

Add `dp2.bf16` and `dp2.f16`, two BF16/FP16 products per lane summed into an FP32 accumulator,
at points in the 48–63 range §4 already allocates to packed dot products. §4 currently spends
eight of those sixteen points (`dp4.ss/su/us/uu`, `dp8.ss/su/us/uu`); **eight are free.** No
new format, no new operand model, no new register state.

### Justification

`gpr-count-decision.md` credits `dp4.acc` with making 16 GPRs sufficient under INT8
accumulator pressure, on the grounds that it performs four MACs per accumulator register.
**F-121 built the path and F-113 measured the credit, and it is earned:** the INT8 GEMM's
spill profile is nearly identical to the FP32 one — same tiles, same addressing, same
accumulator count — while doing four times the arithmetic per accumulator, so `sp/mac` lands
at 0.51–1.03 against FP32's 2.07–3.78.

That is the mechanism working exactly as argued. **And it covers only INT8.** The FP32 case is
the one §1 names as having no mitigation, and F-113 measured why that matters: accumulator
spill is 2, 2, 4, 23 transfers at 1×1 through 2×4 and then **182 at 4×4 and 1136 at 8×8**. It
is a cliff, and the tile where it falls is the tile a throughput matmul wants.

**The precision argument is the decisive one.** FP32 GEMM is not the modern ML workload;
BF16/FP16 inputs with FP32 accumulate is. `dp2` gives that case two MACs per accumulator
register — half the relief `dp4` gives INT8, for the precision that actually runs. §10 already
lists "FP packed dot-product (BF16×BF16 → FP32 and similar)" as out of scope for V1 and ties
it to Format H. **The ask is to untie it.** The exponent handling §10 cites as the reason to
design it with fragment operands is a property of the *reduction*, not of the operand model,
and `dp4` already establishes that a packed reduction can live in Format A without touching
invariant 1: the packing factor is in the opcode, no register is narrow, and nothing outside
the instruction observes the packed view.

### Strength: **strong**

Reserved space, no new format, an existing and now-measured precedent, and it addresses the
precision the target workload uses. The cost is the reduction hardware, which is real but is
the same class as `dp4`'s.

### What the compiler will do with it

> **CORRECTION (ISA review).** This section originally read: "`CCVCompress` already folds any
> three-source accumulate whose addend the allocator landed on the destination into Format J
> (F-121). A `dp2` would ride that unchanged." **It cannot.** Format J's subop field is two
> bits and all four points are allocated — `ffma.acc` format 0, `ffma.acc` format 1,
> `dp4.acc`, `mad.acc` — so there is no free subop. **`dp2` is 32-bit only**, and the
> compressed-form density that makes `dp4.acc` valuable in a GEMM inner loop is not available
> to it. The ask was priced as though it were, and it should not have been: the twelve bits of
> register fields leaving exactly two for the subop is stated in §3 of the spec, beside the
> table I was reading from.
>
> The arithmetic credit — two MACs per accumulator register — is real and independent of
> encoding length, so the ask survives at the corrected price. What it forces is a trade the
> ISA review declined to resolve and neither does this document: if a compressed `dp2` turns
> out to matter, something in Format J has to be displaced, and the only candidates are the two
> `ffma.acc` points `dp2` would partly subsume. **That question should not be opened until
> `dp2` is measured at 32 bits** — if the 32-bit form closes the FP32 accumulator cliff
> adequately, it never needs answering.

Forming `dp2` from IR needs the same DAG combine shape `combineDP4` uses, which exists and is
tested by mutation (`tools/check-dp4.sh`). `CCVCompress`'s Format J fold is not available to it
per the correction above.

---

## 4. Ask 2 — launch-block-relative addressing. **Medium. Price this before ask 3.**

### The measurement it comes from

`sweep-decode.sh`, on a grid-strided fused elementwise chain — residual, scale, bias,
activation, fused so intermediates never reach memory, with the number of fused tensors swept:

| kernel | instrs | spills | divergent/uniform live | uniform reloads |
|---|---|---|---|---|
| `loop NT=1` | 33 | 0 | 4/7 | 27% |
| `loop NT=4` | 64 | 13 | 4/10 | 25% |
| `loop NT=8` | 117 | 38 | 4/14 | 21% |
| `loop NT=16` | 202 | 79 | 4/22 | 20% |

**The divergent working set is four values at every tensor count** — the element, the index,
the loop counter, the bound. The uniform working set is the §5.1 window bases, and it grows
with the number of tensors fused. Spill begins where that crosses 16 and reaches 79 transfers.

In the straight-line version of the same chain nothing spills, which is not the same as
nothing costing: each base is re-fetched from the launch block at its single use instead of
being held, and that is **20–38% of the kernel's instructions**.

### The observation

Those values are not merely warp-uniform. They are **warp-uniform, loop-invariant, and already
resident in memory** — they live in the launch block, which is CTA-wide, read-only for the
kernel's lifetime (§5.2), and small. A register is being spent to cache something that is
already in a known, tiny, immutable table.

### The proposal, and an encoding question the compiler cannot settle

A Format D form whose base is a **launch-block slot index** rather than a GPR, so a window base
never occupies a register at all. The AGU would take the window from the launch block directly.
This is what NVIDIA's `ULDC` and AMD's buffer descriptors both amount to.

**The encoding is genuinely open and the compiler side is not confident it can propose one.**
Two shapes, with the objection to each:

- **Replace `rbase` with a 4-bit immediate slot selector, selected by an opcode bit**, as
  `opcode[2]` already selects base+offset against base+index within tag `1000`. The objection
  is invariant 8: register fields sit at fixed positions across tiers so that a renamer can
  find them without decoding, and a field that is sometimes a register and sometimes an
  immediate defeats that. **I am flagging this rather than asserting it** — the last time this
  proposal series invoked invariant 8 against an encoding, the reasoning was wrong and the ISA
  review corrected it (F-110): invariant 8 governs register fields, and Format D already varies
  its *immediate* position by opcode. Whether varying what a *register* field means is the same
  kind of thing or the opposite kind is exactly the question, and it belongs to the ISA side.
- **Keep `rbase` a register field and add a mode bit selecting which file it indexes.** This
  preserves the field but introduces a second namespace, which is a slice of ask 3's baggage
  and should be counted as such rather than presented as free.

### Justification

It targets the measured pressure precisely — the values that hurt are exactly the ones this
removes — at a fraction of ask 3's surface: no second general-purpose namespace, no
uniform/divergent operand typing, no inter-file moves, no second spill path, no second
allocator. It also removes the 20–38% instruction overhead in the straight-line case, which
ask 3 would also remove but which nothing cheaper currently does.

### Strength: **medium**

The need is measured; the encoding is not designed; and the hardware cost is not zero — the
AGU needs the slot, so something has to hold or cache the launch block. What the compiler side
is asking for is that **this is priced before ask 3 is adopted**, not that it is adopted now.

---

## 5. Ask 3 — warp-uniform register file. **Weak as an immediate ask. Recommend deferring.**

### The case, stated at its strongest

`warp-uniform.md` §0 shows the compatibility target ships one: `S2UR` into a uniform register,
`ULDC` loading constants into the uniform file, and ordinary vector instructions naming uniform
operands. So the mechanism is not exotic, and O-33's lane-0 masking is a software approximation
of it. The table in §2 shows the addressing-dominated kernels are majority warp-uniform.

**And there is a real simplification credit that the baggage argument should be netted
against: a uniform file would make O-33 unnecessary.** That removes a compiler pass, one of
§1a's four obligations on the implementation, and an entire class of bug — F-134's hang was a
missing broadcast in exactly that pass, and it survived undetected because the kernel it broke
had never been executed.

### Why the compiler side still recommends deferring

**It does not address what decides AI/ML relevance.** §6. Matrix throughput and memory
bandwidth decide that; a uniform file makes the kernels *around* the matmul cheaper.

**It does nothing for the two shapes that were supposed to motivate it.** `sgemm` binds on
divergent values (60, 95, 131 against 16) — §1's framing of accumulator pressure does not
reach it, and F-128's framing of address pressure was retracted because `sgemm`'s addressing
*is* divergent. Batch-1 decode GEMV does not bind at all: 11 spill transfers in 217
instructions, because there is no reuse to tile for and the register file has nothing to hold.

**The evidence that remains is one kernel written for the purpose.** §4's table is the whole
case, `fused.cu` is mine, the tensor count is a knob I chose, and spill only begins around
eight fused tensors. That is thinner than anything else in this document.

**Ask 2 may capture most of it.** The values in §4's table are window bases. If a launch-block
addressing mode removes them from the register file, the residual case for a general uniform
file is whatever pressure is left — and nothing has measured that residual.

### Conditions that would revive this to a strong ask

1. A **real fused-kernel corpus** — not `fused.cu` — showing tensor counts that bite.
2. Ask 2 priced and either rejected on cost, or adopted and **measured to leave** significant
   uniform pressure behind.
3. A kernel where uniform pressure binds that is *not* addressing — if every uniform value a
   uniform file would hold turns out to be a window base, ask 2 is the right shape and ask 3 is
   the general solution to a specific problem.

### Strength: **weak as an immediate ask**

Not because the mechanism is wrong — it is what the compatibility target built — but because
the measurement supporting it is the weakest here, the alternatives are unpriced, and the cost
is the largest in this document.

---

## 6. Format H, which frames all three and is not asked for

`nv-tile-pressure.sh` compiles the same `sgemm.cu`, same block shape, same tiles, for sm_70 and
reads `ptxas -v`: **32 registers through 2×4, 48 at 4×4, 121 at 8×8, and zero spill at every
tile.** CCV runs its best tile with 118 spill transfers where NVIDIA spills nothing, and at 8×8
issues 2552 instructions with 1459 spills — not a tuning point but a report that 64
accumulators do not fit in 16 registers.

**The gap is arithmetic intensity, not instruction count.** A TM×TN tile does TM·TN MACs per
TM+TN operand elements, so 2×4 buys 1.33 and 8×8 buys 4.0. Three times the arithmetic per byte
of operand traffic is a bandwidth argument, and CCV is already competitive on density — 1.045×
of SASS on the aligned build when this was written, and **0.94× after O-45**, which is below
parity on instruction count.

Two things properly qualify that. `dp4.acc` closes most of it for quantized work, which is why
ask 1 extends the same mechanism to the precision that runs. And **nobody does throughput ML
GEMM with SIMT register tiles any more** — since Volta it runs on the matrix unit, where
operand reuse happens inside the unit. So the 8×8 SIMT tile is the right answer to "can CCV run
SGEMM" and the wrong answer to "is CCV competitive at AI/ML".

**Which is why Format H is the strategic item and the other three are not substitutes for it.**
It is already reserved with the `11` length escape and the `1111` format tag. No ask is made
here because the compiler has formed no fragment and has nothing to say about the layouts that
are the hard part. One caveat worth recording for whoever designs it: **a matrix unit moves the
operand-reuse constraint inside the unit; it does not make accumulator capacity free.** Some of
the 4×4/8×8 cliff survives Format H in a different shape.

---

## 7. What needs no ISA change

- **Partial unrolling.** F-135 measured it dynamically: at 2×2 one K-tile, full unroll is 378
  issue groups executed and 50 spill transfers; unroll=4 is 355 and **22**. The instruction win
  is ~6% where the static count suggested 25%, but the spill traffic halves. It is a spill
  optimisation, it is a source-level choice, and no cost model can override a `#pragma unroll`.
  This belongs to the tuned-library work, not to the ISA.
- **Everything in F-111's audit.** 47 of 267 instructions could not be produced at all; the
  reachable ones are now wired up and gated. No ISA change was needed for any of them.

---

## 8. What the ISA side is being asked to decide

1. **Ask 1 — adopt or reject `dp2.bf16`/`dp2.f16` at 48–63.** If adopted, which of the eight
   free points, and whether both precisions or only BF16. If rejected, whether the reason is
   the reduction hardware or the intent to keep all FP packing inside Format H — the compiler
   side would want that recorded, because §10's current reason is the fragment operand model
   and §3 argues that reason does not hold.
2. **Ask 2 — is a launch-block-relative Format D form legal, and at what cost?** Specifically:
   does replacing a register field with an immediate under an opcode bit violate invariant 8,
   or is it the same class of thing Format D already does with its immediate position? The
   compiler side has been wrong about this invariant once and is not asserting an answer.
3. **Ask 3 — defer or not.** The compiler side recommends deferring, with §5's three
   conditions. If the ISA side disagrees, the most useful thing it could supply is the reason:
   whether it is the compatibility-target argument, the O-33 simplification credit, or a
   workload judgement the compiler has no access to.
4. **Format H — is it the next thing?** Not an ask, but the other three are weighed against it
   and that weighing is worth confirming or correcting.


---

## CORRECTION, after review, for the record

Two figures in this document have since been measured differently, and the decision it
carries was taken partly on them. Neither is restated in place, because a proposal that was
reviewed should stay readable as what the reviewer read.

**1. "0.94× of SASS on instruction count" (§5) is wrong, and it was wrong when written.**
The sweep it came from had no GEMM in it: for eight revisions `bench.py` carried eight
straight-line or single-loop kernels, and `sgemm` had never been compiled for another
target at all because it was written against clang's builtin-vars header rather than the
portable one. With `sgemm` and `gemv` added, CCV aligned is **1.31× SASS**, and `sgemm`
alone is 1.84×. The bytes claim is unaffected — 0.28× of SASS, 0.56× of gfx900, and the
pooled bits-per-instruction moved only 25.9 → 27.5. Compiler-side F-148.

**2. Ask 3's evidence base has been replaced, and the ask survives it in a narrower form.**
§2 flagged that `fused.cu` was "a kernel written for this measurement, with the tensor count
as a free knob". That objection is now closed by measurement rather than argued: a corpus of
eight kernels written from the published shape of real inference and training kernels
(F-143) puts real pointer counts at **two to six**, not sixteen, and shows **zero** pointer
or index spill after O-45 in any of them. What those kernels do spill is their warp-uniform
SCALAR arguments — a third quantity, and neither of the two this document argued from. The
recommendation to defer ask 3 stands; the case for eventually adopting it now rests on
something measured in kernels nobody wrote for the purpose.
