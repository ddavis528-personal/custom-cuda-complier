# Compiler-side findings — the v1.6 review

**Covers:** everything since the v1.5 review — the rest of Step 6, which is the
`chwidth` mode-insertion pass and the narrow-width path it enables. Written for
the architecture side, so it is organised by what the compiler work found about
the ISA, not by what was built.

**Current spec:** `isa-v1.6-operation-map-and-encoding.md`. The previous report
is [`compiler-findings-v1.5.md`](compiler-findings-v1.5.md).

---

## 1. There is now a fourth obligation, and the element-width model rests on it

§1a of the spec lists the properties the compiler emits code against and cannot
verify. v1.5 had three. O-40 adds the fourth, and it is different in kind from
the others:

> **Narrow element work must retire at a multiple of the 32-bit rate.** The
> datapath allocation splits, so a 16-bit instruction retires at twice the rate
> of a 32-bit one.

The first three obligations each protect *one optimisation* — turn the
optimisation off and the machine is merely slower than it could be. This one is
the return on **invariant 1 itself**. Element width is per-register state rather
than an opcode field precisely so that a narrow instruction is the same
instruction against a narrower slice, which is what lets two of them share a
32-bit allocation. Without the higher retire rate the narrow forms are pure
cost: they add `chwidth` transitions and save nothing an instruction count can
see.

**The fraction it applies to is now measured, and it decides everything.** The
simulator counts element-work instructions by width. A kernel's speedup at a 2×
retire rate is bounded by how much of its stream is narrow:

| | narrow fraction | cycles @2× | vs its own fp32 twin |
|---|---|---|---|
| `vadd16` (straight-line, 1 element/thread) | 0.286 | 15.0 vs 16.0 | 1.067× |
| `vadd16_loop` (8 elements/thread) | **0.552** | **53.0 vs 68.0** | **1.283×** |

Same ISA, same instructions, same retire rate. What differs is how much of the
issued stream is element work rather than prologue — which is a property of the
kernel, not of the machine.

**Two consequences for RTL.** First, of the narrow instructions in `vadd16`,
**one is an ALU operation and three are loads and stores**: a split allocation
that widens the ALU and leaves the memory path alone makes the narrow form
*slower* than its 32-bit equivalent (17.5 cycles against 16.0). The obligation
is on the memory path first, which is the opposite of where attention naturally
goes. Second, at 1.5× rather than 2× the straight-line kernel loses outright.
There is no margin at the fraction a short kernel produces.

---

## 2. The element-width model works, and the compiler nearly gave all of it away

This is the main finding of the review, and it is a compiler finding rather than
an ISA one — which is itself the point, because it was invisible until the
benchmark grew a kernel with a loop.

`vadd16` is `vadd` at half the element width. When it was first measured it cost
**two instructions more** than the fp32 kernel and returned nothing in issue
count, because at one element per thread a 16-bit element occupies a 32-bit lane
exactly as a float does. Worse, a looping version paid those two instructions
**per element, forever** — the width transitions sat inside the loop body, so
the overhead that should amortize did not.

Three compiler defects, all now fixed, all of which the ISA permitted the
compiler to avoid:

- **Transitions were placed inside blocks.** Where predecessors disagree about a
  register's width — a preheader supplying 32, a back-edge supplying 16 — the
  pass resolved it at the first access *in the block*. The width is
  loop-invariant and belongs on the incoming **edge** (F-87).
- **A transition was emitted for a register nobody reads.** Format C's
  materialization destination `rd` is dead on a loop's back-edge test, and the
  allocator put it in a narrowed register. The pass widened that register to
  accommodate a value no instruction reads, once per iteration (F-89).
- **The allocator let one register carry both widths.** O-39 permits a load's
  `rdata` to share with its `rbase`/`rindex`, since the address read takes all
  32 bits; that saves a register and costs a width change per iteration, which
  no placement pass can lift out because the width genuinely changes inside the
  body (F-80).

**Result:** `vadd16_loop`'s steady-state body is **seven instructions — the same
as its fp32 twin — with no `chwidth` among them.** The entire width cost is one
instruction in the prologue: `issues = 13 + 7n` against fp32's `12 + 7n`,
measured across iteration counts. §8 of `walkthrough.md` traces it end to end.

**For the architecture side, the useful statement is this.** The ISA side of the
element-width model is sound: nothing in §3 prevented any of the three fixes,
and each was a compiler limitation. But the feature is unusually sensitive to
compiler quality — at v1.5's codegen it was a net loss on every kernel, and the
gap between "net loss" and "1.28×" is entirely in where three instructions go.

---

## 3. The fix for F-80 says something about the register file

The width-affinity objective the F-3 plan asked for turned out to have exactly
one available expression: **the allocation order**. `chwidth` names physical
registers, so element width is a post-RA concept, and the register *class* is
the only width information the allocator has. `GPR16` now allocates descending
where `GPR` allocates ascending — same sixteen registers, opposite preference —
so narrow and wide values cluster apart and never meet under low pressure.

That is a soft partition of the register file by width, which is what the plan
predicted. **It is also a third argument toward 32 GPRs that the spill counts
will not surface**, and it is now concrete rather than structural: at 16
registers, a kernel using two widths has eight per width before the partition
starts costing something. No benchmark kernel reaches that — the narrow kernels
use three narrow registers — so the graceful-degradation claim is reasoning, not
measurement (F-92).

The conflict this was predicted to have with O-8's destructive-form preference
**did not appear on these kernels**: total bytes identical both ways, and the
`rd == rs0` hit rate unchanged. That is weak evidence and is labelled so in the
roadmap — both kernels have almost no compression to lose.

---

## 4. The density claim was resting on one 2017 ISA; it no longer is

v1.5's comparison used gfx900 alone, which left the headline open to the reading
that it beats an obsolete encoding. Every AMD generation this toolchain can
assemble now answers that — both encoding families and the datacentre line:

| | GCN5 '17 | RDNA2 '20 | RDNA3 '22 | RDNA4 '24 | CDNA3 '23 |
|---|---|---|---|---|---|
| pooled bits/instruction | 40.7 | 43.7 | 41.8 | 43.8 | 43.1 |

CCV's pooled figure is **27.6**, or 0.63×–0.68× of every one of them. AMD's
density is flat across eight years and two encoding families, so the margin is
not an artifact of the baseline. The ratio against RDNA4 is the same as against
Vega.

**A correction that matters more than the broadening.** v1.5 presented
instruction counts as a control on the density claim — "CCV is lower on four of
five" — comparing per-*warp* counts across machines whose warps are different
sizes. A gfx900 wavefront is 64 lanes to CCV's 32, and the document had stated
exactly that caveat about SIMT efficiency since 1.4 without applying it here.
Normalized to work done:

| issues per 1024 elements | CCV | GCN5 | RDNA3 | CDNA3 |
|---|---|---|---|---|
| `vadd` | 512 | **464** | 1024 | **368** |

**CCV issues more instructions per element than every wave64 machine** and beats
every wave32 part by close to 2×. The encoding still wins the column it was
designed for — on the same kernel CCV fetches 1792 instruction bytes per 1024
elements against gfx900's 2432, so **26% fewer bytes while issuing 10% more
instructions**. Whether that trade is good is a hardware question this benchmark
cannot settle: it exchanges fetch bandwidth and I-cache footprint, which CCV
wins, for issue slots and scheduler bandwidth, which wave64 wins.

**The comparison is still against the wrong vendor.** CCV's compatibility target
is CUDA and its density claim is measured against AMD. SASS needs `ptxas`, which
needs a CUDA toolkit that is not installed, and broadening the AMD sweep did not
close that. The §6 figure of 128 bits per SASS instruction remains a citation.

---

## 5. `transpose` was two compiler bugs, not an architectural gap

For two revisions `transpose` was the outlier on every column, and the
explanation on file was O-33's lane masking plus AMD's scalar unit. Taking the
kernel apart found **21 of its 79 issued instructions** in two compiler defects,
neither related to masking:

- **A signed constant divisor took the full runtime-divisor expansion.**
  `CCVExpandDivision` claimed instcombine strength-reduces constant divisors.
  It does for unsigned and not for signed — rounding toward zero is a CodeGen
  trade, not a canonicalisation — so `n / 16` with `n` an `int` got Newton
  iteration and all. 79 → 60 (F-93).
- **The fused reciprocal seed was dead code nothing collected.** 60 → 58 (F-94).

`transpose` now issues **58 against GCN5's 64**, below it, and 236 bytes against
308. It remains 2 above on static instruction count, which is the scalar-unit
gap and is architectural: AMD computes a warp-uniform divisor once for the whole
wavefront where CCV issues it to all 32 lanes.

**The masking A/B always said masking was 6 instructions of 58.** The relevance
for the architecture side is that *the case for a warp-uniform register file
(F-52, O-25) was partly resting on this kernel's cost*, and most of that cost
was ours. The case still stands on redundant execution, but it is now a smaller
number than this document previously implied.

## 6. Corrections to figures this project published

Two, both found by measurement rather than review, and both recorded in place
rather than quietly restated:

- **The narrow fraction and speedup were overstated.** The by-width counter took
  the narrowest of *all* an instruction's GPR operands, and Format C's `rd` is an
  operand the compare never writes — so a 32-bit comparison whose dead
  destination sat in a narrowed register counted as narrow element work once per
  loop iteration. `vadd16_loop` was reported at 0.690 narrow and **1.360×**;
  corrected, the same code is 0.552 and **1.259×** (F-91).
- **Six figures in `benchmarks.md` had drifted from its own tables**, all in the
  direction of flattering the machine's past self — including an O-33 A/B table
  that was stale in every cell, hand-copied once and then left behind by two
  changes to the divide sequence and one correction to the counter (F-76).

---

## 7. What is now mechanically checked

The recurring failure in this project is a green check that was green because it
was not looking, and the v1.6 cycle converted four more instances into gates:

- **`check-spec-tables.py`** — the ISA document's summary tables against its own
  bit maps, compared as sets of bit positions, plus the tag-length table against
  both prose exclusion lists. An external review found Format F given two
  different immediate widths, stale since 1.2 in a table nothing downstream read
  (F-70 – F-73).
- **`check-bench-doc.py`** — extended past the generated tables to the markdown
  tables and inline prose figures that restate them, since F-76 showed what
  "prose is not checked" costs (F-77).
- **`check-walkthrough.py`** — every instruction the walkthrough's prose names
  must appear in one of its own generated listings. It was describing `f48`
  where the listing said `movi`, and a `por`-manufactured predicate that O-32
  had made unnecessary several revisions earlier.
- **`check-narrow-loop.sh`** — 256 elements over eight iterations per thread,
  checking **every** element. F-87's saving is precisely that the loop never
  re-establishes the width, so a mode that decayed after the first iteration
  would pass the existing single-iteration test and fail everywhere else.

---

## 8. Open questions for the architecture side

- **O-40's ratio is a target, not a measurement.** 2× is what the ISA asks for.
  At 1.5× the short kernel loses. The memory path matters more than the ALU
  path, which is worth settling early.
- **The register-pressure case for width affinity is untested** (F-92). Nothing
  fills the register file with narrow values, so the claim that opposite
  allocation orders degrade gracefully when the two widths collide is reasoning
  rather than measurement.
- **The 32-GPR question has a third argument now** (§3 above), still unmeasured.
- **SASS.** Unchanged from v1.5, and now the largest single gap in the
  comparison: the density argument is written against a vendor the benchmark
  cannot reach.
