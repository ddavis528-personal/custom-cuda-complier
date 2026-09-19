# Compiler-side findings — since the v1.6 review

**Covers:** everything after [`compiler-findings-v1.6.md`](compiler-findings-v1.6.md):
acting on the v1.6 review's three decisions (O-44, O-45, O-46), and then a corpus of real
fused kernels that found five compiler defects, closed two open findings, retracted one
published headline and produced the first evidence for the warp-uniform register file that
was not written for the purpose.

**Written against:** the ISA text as it stood after O-46, which is now cut as
[`isa-v1.7-operation-map-and-encoding.md`](isa-v1.7-operation-map-and-encoding.md). This
report was written before that revision was cut — 1.6 had been accumulating decisions O-40
through O-46 without a version bump — so it is named for what it covers rather than for a
revision number. **§5 is the item 1.7 records as open against itself**, and §7 is the list a
1.8 would need to be reconciled with.

---

## 0. The short version

| | |
|---|---|
| **Acted on** | O-44 (FP packed dot products), O-45 (launch-slot addressing), O-46 (a second namespace on its own merits) |
| **Closed** | F-120 (SFU unreachable), F-126 (the uniform-file case is addressing) |
| **Retracted** | "CCV aligned is 0.94× SASS on instruction count" — it was 1.31× on a sweep that included a GEMM |
| **New, for the architecture side** | §5, O-33's masking is unsound without a reconvergence guarantee. This is the only item here that is a defect in the ISA's own model rather than in the compiler |
| **Still not asked for** | Format H. The compiler still has nothing to contribute to its design |

---

## 1. The v1.6 decisions, implemented

**O-44 — FP packed dot products.** `dp2.bf16`, `dp2.f16`, `dp4.e4m3` and `dp4.e5m2` are in
the machine description at §4 points 52–55 and in the simulator, and §4's normative rounding
rule — products summed exactly, rounded once — is executed against a reference computed in
exact rationals. **Nothing can form one.** Building the packed operand needs a bfloat, half
or FP8 value in the IR and this backend has none of those types (F-137). The semantics are
pinned so that the gap is a missing type rather than a missing agreement.

That check is worth one line on its own, because its first version was green while looking
at nothing: mutating the per-product rounding changed no result, since a bf16 product is
exact in FP32. It only became a test when it was rewritten to stress summation at 2²⁴, where
mutating the accumulator to `float` fails 2 of 5 cases.

**O-45 — launch-slot addressing.** Implemented, and **it did nothing for the case it was
adopted for until a two-revision-old compiler decision was reversed** (F-139). Straight-line
fused kernels improved; the grid-strided ones — the shape the ask was measured on — did not
move at all, because SelectionDAG works one basic block at a time and LICM hoists the window
load to the preheader, so the DAG in the loop body sees a register and not a load.
`CCVWindowRemat` had stopped cloning at GPR-width values on the grounds that cloning an i32
launch-block load "costs a load in every block that uses the window, which in a loop means
every iteration". True when written, and **falsified by O-45**, because the clone is no
longer a load — it is a 4-bit field. With that reversed: NT=4 64 → 42 instructions and 13 → 0
spills, NT=8 117 → 60 and 38 → 0, NT=16 202 → 114 and 79 → 9.

The general lesson is worth more than the numbers: **an addressing mode that removes a value
from the register file also removes the reason a pass was avoiding rematerialisation**, and
the two changes are worthless apart.

---

## 2. A corpus of real fused kernels, and what it cost to find out

The evidence the register-file question rested on was one kernel — `test/cuda/fused.cu` —
written for the measurement, with the tensor count as a compile flag whose range was also
chosen here. `test/cuda/fusion/` replaces it: eight kernels written from the published shape
of ones that actually run — RMSNorm and its fused-residual form, `silu_and_mul`, rotary
embedding, LayerNorm with saved statistics, the INT8 dequantisation epilogue, the
flash-decoding combine, and the fused AdamW step. **Every pointer count is forced by the
kernel's own mathematics.** All eight execute against references written from the
mathematics, because F-134 established that a kernel which has never run has only ever had
its text checked.

```
  kernel         ptrs  scal  instrs    bits  slots  spills uni-sp ptr-sp acc-sp  div/unif
  ---------------------------------------------------------------------------------------
  swiglu            2     1      39    1040      3       0      0      0      0       3/7
  rmsnorm           3     2      79    2128      4       0      0      0      0       6/9
  add_rmsnorm       3     2      84    2256      6       0      0      0      0       8/9
  rope              4     4     144    4000     13      24     17      0      0     11/15
  adamw             4     8      78    2096      7      11      6      0      2      8/15
  dequant           6     1      61    1616      6       0      0      0      0      5/10
  layernorm         6     2     113    3040      7       0      0      0      0      8/14
  attn_combine      4     2     219    6352     16      11      6      0      0      3/19
```

**Three results (F-143).**

**Pointer counts are two to six.** `fused.cu` swept 1 to 16 and every conclusion drawn from
it was read off the top settings. The kernel that most tempts the opposite assumption is
SwiGLU: written the obvious way it takes three pointers, and written the way it is actually
written it takes **two**, because the gate and up projections are the two halves of one
allocation produced by one matrix multiply. A kernel parameterised on "number of tensors"
cannot produce that shape.

**Pointer and index spill is zero in all eight.** After O-45 there is no window-base spill
left for a uniform register file to hold. That closes F-126 from the opposite side to
F-129's retraction, and it closes it against the position F-126 itself argued.

**What spills is warp-uniform scalars.** The three kernels that spill at all spill their
non-pointer arguments — `rope`'s head geometry, `adamw`'s eight optimiser constants,
`attn_combine`'s split count — and the CTA index. One launch-block word each, identical in
all 32 lanes, loop-invariant, and today costing either a spill slot or a lane-0 masked
compute plus a broadcast. **That is a third quantity**, and neither of the two previously
argued for a uniform register file: not GEMM accumulators, which are per-lane (F-138), and
not window bases, which O-45 removed.

### The cost of finding out

Five defects, none of them reachable by any kernel that was in the tree. They are listed
because collectively they are the argument for the corpus: a suite written to exercise
addressing modes had missed a compiler crash in the most ordinary addressing shape there is.

| | |
|---|---|
| **F-141** | Five of §4's eight SFU points were unreachable from CUDA, carried as "clang emits a libm call and there is no calling sequence". True of `expf` and irrelevant to a GPU kernel, which writes `__expf`/`__sinf`/`rsqrtf` or is built with fast-math — all of which arrive as intrinsics. All five select and execute now; the accurate libm form is still blocked on F-21 |
| **F-142** | `out[i + 1]` **segfaulted the compiler**. Format D base+index carries an 8-bit signed displacement, the simulator's AGU has always added it, and selection wrote a literal zero into it — so the address matched no arm of the combine and reached the type legalizer as a live 64-bit add. **Not one kernel in the tree had ever emitted a non-zero displacement** |
| **F-144** | **Every negative float constant was unencodable** — MOVI48's wide immediate was built sign-extended — and `fdiv -1.0, x` had no pattern, because the generic combiner manufactures it after the IR expansion pass has run |
| **F-145** | O-33's lane-0 masking is unsound when lanes are not co-issued. §5 |
| **F-147** | A by-value parameter struct was classified as a pointer and **silently miscompiled** — it read every field from whatever window the struct's first four bytes named, and it compiled, assembled and round-tripped. Lowered correctly now. Its struct-of-pointers form is §6 |

---

## 3. The instruction-count claim was an artifact of the kernel set

**This project published "CCV aligned is 0.94× of SASS on instruction count" for four
revisions. It is 1.31×** (F-148).

The sweep carried eight kernels from `test/bench/`, all straight-line or single-loop, none
spilling, none reaching a 48-bit immediate. The two kernels that stress the encoding had
**never been compiled for another target at all**: `sgemm` was written against clang's
builtin-vars header rather than the portable one, which is exactly why nobody noticed. So
the loudest claim here was unfalsified precisely where it was most likely to fail.

| pooled, aligned | CCV | SASS | ratio |
|---|---|---|---|
| eight easy kernels | 210 instrs | 224 | 0.94× |
| all ten | 767 instrs | 586 | **1.31×** |
| `sgemm` alone | 360 instrs | 196 | **1.84×** |

It is one kernel; the other nine sit at 1.04×, and `gemv` is below every AMD generation.
About 102 of `sgemm`'s excess is spill traffic, and `ptxas` runs the same file at that tile
in 32 registers with **zero** spill.

**What survives is the claim that was always the load-bearing one.** Across all ten, CCV
aligned is **2656 bytes against SASS's 9376 (0.28×) and gfx900's 4748 (0.56×)**, and adding
the two hard kernels moved CCV's pooled density from 25.9 to 27.5 bits per instruction while
gfx900's moved 40.7 to 43.4 — the ratio barely moved. **The encoding claim is robust to the
kernel set. The instruction-count claim was not.**

For the architecture side this is the 16-GPR decision appearing in a column that had never
been asked to price it. §3 of `benchmarks.md` already said the register file binds on GEMM;
until now that cost nothing in §2.

---

## 4. Where the GEMM pressure actually is

Asked directly whether `sgemm`'s pressure is uniform or per-lane, two independent
measurements agree it is per-lane.

**Peak simultaneously-live values, by divergence.** The uniform working set is **10 and does
not move with the tile**; the divergent one is 2–18× the register file.

| tile | 1×1 | 1×2 | 2×2 | 2×4 | 4×4 | 8×8 |
|---|---|---|---|---|---|---|
| divergent | 28 | 46 | 60 | 95 | 131 | 282 |
| uniform | 10 | 10 | 10 | 10 | 10 | 10 |

**Spill by cause** is pointer/index dominant to 2×4 and accumulator dominant from 4×4 (1133
of 1441 transfers at 8×8). Warp-uniform spill is 0–15 transfers throughout.

**One caveat, stated because it bounds the answer.** The spill classifier recognises
uniformity only at its structural sources — a launch-block read, `srd %ctaid`, O-33's
broadcast — so address arithmetic derived from those lands in `unclassified` and the uniform
column is a floor. The bracket is 3.2%–29.5% at 2×4 and **0.14%–2.4% at 8×8**, the tile a
throughput SGEMM uses. Closing it properly means attributing stack slots from the *virtual*
register uniformity that `CCVMaskUniform` already computes correctly, rather than
reconstructing it from physical registers after allocation; an attempt to do the latter
produced a confidently wrong 40–51% and was withdrawn (F-149).

---

## 5. **O-33's lane-0 masking is unsound, and it is a reconvergence question**

The most consequential item in this report, and the only one that is a defect in the ISA's
execution model rather than in the compiler.

The masking pass computes a warp-uniform value in lane 0 and `shfl.idx` broadcasts it. Its
stated safety condition is that **every lane reaches the block**. That is necessary and it is
not sufficient. The broadcast is warp-collective: it needs lane 0 **issuing with** the lanes
that read it, and §1 gives this machine per-thread PCs with **opportunistic** reconvergence.
`reconv.hint` exists precisely because Phase 1 hardware guarantees no join, and §3 says the
hint "does nothing in Phase 1". So after any divergent branch, lanes that all eventually
arrive at a block may arrive at different times, and a group issuing there need not contain
lane 0.

`rope` is the smallest real kernel that shows it. An inner loop whose trip count comes from
`threadIdx` leaves lanes 4–31 running ahead to the outer latch while lanes 0–3 are still
inside. The latch post-dominates the inner exit, so it is not control-dependent on it and the
pass's condition passed it. The outer loop counter was masked to lane 0, the group without
lane 0 read lane 0's stale counter, and **the kernel never terminated**.

Fixed compiler-side by an AND-meet dataflow that additionally requires lanes to be
co-issued: no divergent branch on any path from the entry, or a barrier since the last one, a
barrier re-establishing it because every lane leaves one at the same PC. The existing wins
are untouched — `transpose` still masks 7 with 3 broadcasts — because its masked work is
before any divergence.

**What this costs, and what the architecture side may want to do about it.** The compiler now
declines to mask anything after any divergent branch anywhere in the function, unless a
barrier intervenes. In a kernel with an early-exit guard — which is most kernels — that is
the whole body. O-33 is the ISA's answer to redundant execution of warp-uniform work and its
reach is now bounded by something the ISA deliberately left unguaranteed.

Three ways out, in rising order of cost, none of them asked for here:

1. **Make `reconv.hint` do something in Phase 1.** It is already emitted at every
   reconvergence point and already costs encoding space. If arriving lanes wait at a hinted
   join, the compiler's co-issue condition becomes "no divergent branch since the last hint",
   which is nearly everywhere.
2. **A mask-aware broadcast** — a `shfl` variant that names the lowest *active* lane rather
   than lane 0. Cheaper than a join guarantee and it fixes the broadcast without fixing
   divergence; the compiler would still need to know the value is uniform across the active
   set, which it does.
3. **The warp-uniform register file** (F-106), which removes the need to approximate one in
   software at all. This is the item §2's corpus gave new evidence for, and the two
   questions are more related than they looked: **O-33's masking is a software uniform
   register, and §5 is the first measured statement of what it costs to not have one.**

---

## 6. A pointer read out of memory has no representation

`multi_tensor_apply` — one launch applying an optimiser update across a list of hundreds of
parameter tensors — passes its tensor pointers in a by-value metadata struct and indexes it
at runtime. Two things stood in the way of lowering it and one of them is not a compiler
question.

F-147 fixed the first: by-value aggregate arguments now lower as objects resident in the
launch block. The second is that a struct of tensor pointers means **loading a pointer out of
memory**, and §5.1 gives an address a window index and an in-window offset while invariant 11
keeps the pair out of the register file. **Nothing says what that pair looks like as a value
in memory.** `CCVCheckIR`'s invariant-11 group covered a pointer compared, a pointer phi, a
pointer passed across a call and a pointer *stored*; reading one back was the direction
nobody had written a rule for, and it is the direction that occurs, because a kernel indexing
a pointer table never stores one. It is diagnosed now rather than aborting in the legalizer.

Two notes that bound how urgent this is. **The compiler-generated form of the same workload
does not need it**: Inductor emits foreach kernels as Triton, and Triton kernels take one
pointer argument per tensor, so what a compiler produces is the many-argument shape rather
than the indexed-array shape. And **a runtime-indexed window needs no new addressing mode** —
it is the ordinary Format D base+index access, which exists and works; O-45's slot form is a
constant-index optimisation that falls back to it. See `proposals/pointer-representation.md`.

---

## 7. Open questions for the architecture side

- **Reconvergence.** §5. Whether `reconv.hint` should do something in Phase 1, or a
  mask-aware broadcast should exist, or neither and O-33's reach stays bounded. This is the
  one item here that the compiler cannot decide alone and cannot work around.
- **The warp-uniform register file** (F-106). Now rests on a third quantity — warp-uniform
  scalar arguments, measured in kernels nobody wrote for the purpose — and is smaller than
  the case that was retracted: 3 to 17 transfers in a real kernel rather than 79 in a
  synthetic one. Better founded, and less urgent.
- **The launch-slot field is not too narrow, it is scaled wrong** (F-146). Half the slot
  space cannot name anything, because the field supplies a window index and pointer window
  words are 8 bytes apart while the slot stride is 4. Re-scaling doubles the reach to sixteen
  pointer arguments with **no encoding change**. Measured, reverted pending review;
  `proposals/slot-field-reach.md`. The widening ask F-140 raised is withdrawn.
- **The pointer representation in memory.** §6.
- **16 GPRs now has a price in the density comparison.** §3. `sgemm` at 1.84× SASS on
  instruction count, against a machine that spills nothing at that tile.
- **O-40's ratio is still a target, not a measurement**, and **the width-affinity pressure
  case is still untested** (F-83, F-92). Unchanged from the v1.6 report.
- **Format H.** Still not asked for. The compiler has formed no fragment and has nothing to
  contribute to its design.

---

## 8. What is mechanically checked, as of this report

93 passing gate checks, of which 13 tools run the kernel in the simulator rather than
inspecting its text, plus `run-tests.sh`'s own suite. New since v1.6:

- **every instruction has a production path** — 264 instructions, each either reachable from
  instruction selection or declared unreachable with a reason; and a mutation suite that
  removes each production path in turn and requires the failure
- **the fused corpus executes**, all eight kernels, against references written from the
  mathematics
- **each SFU intrinsic computes its own function**, from one kernel, so a crossed pattern
  table has nowhere to hide
- **a by-value struct reads the launch block**, with field values chosen so that a
  regression misreading the struct as a window index reads plausible floats
- **the spec cites no revision later than its own**, and **§1a's prose count matches the
  obligations §1a lists** — both added after this document's intro said "three obligations"
  for two revisions after O-40 added a fourth, and after §3 described a change against a
  revision that does not exist
