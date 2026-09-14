# Bring-up Roadmap and Compiler-Side ISA Findings

**Status:** Phase 0 (contract definition). No code yet.
**Companions:** `isa-v1.6-operation-map-and-encoding.md` (encoding ground truth),
`backend-context.md` (scope and rationale ground truth).

This file is the working plan. It tracks two things: the order work is being
done in, and the ISA findings that compiler-side reasoning has surfaced. The
second list is the actual product of this effort — per `backend-context.md` §1,
the compiler's near-term job is to generate signal for ISA decisions.

---

## Part 1 — Findings from the first compiler-side read of the ISA

These came out of reading the spec as a backend implementer rather than as an
architect. Two of them are blockers that the spec currently classifies as
deferred.

### F-1 — The special-register / launch-ABI surface is a Phase-1 blocker, not a deferred item

ISA spec §10 carries "special-register / launch-ABI surface" as a deferred item,
"not encoding-blocking so far." From the compiler side it is the *first* thing
that binds. There is no encoding for reading `%tid`, `%ctaid`, `%ntid`,
`%nctaid`, or `%laneid`, and every kernel in the bootstrap set of
`backend-context.md` §3 needs at least the first three within its first three
instructions. The trivial elementwise kernel — the Phase 1 pipeline validator —
cannot be expressed at all.

This is also the single most concrete consequence of the frontend decision. Once
clang's CUDA frontend is doing the lowering, the question is not abstract: it is
"what do `llvm.nvvm.read.ptx.sreg.tid.x` and friends lower to." That is a
small, well-bounded ISA question and it needs an answer before any kernel
compiles.

Options, in rough order of preference:

1. **A new Format-F-shaped opcode point**, `srd rd, #sreg` — `rd` at `[14:11]`,
   a special-register index in the immediate field. Format F already has the
   shape (destination plus a wide immediate, no sources) and 17 bits of
   immediate for what needs at most 6. Costs one opcode point in an
   unallocated map.
2. **A Format A extension-space opcode** reading an implicit source. Cheaper on
   opcode space but muddies "max GPR sources = 3, all independent of dest."
3. **A reserved address window** read through `ld.global`. Zero new encoding,
   but it puts a memory access and its latency on the critical path of every
   kernel prologue, and the values are warp-invariant constants. Not attractive.

Option 1 looks right. The open sub-question is whether `%laneid` is one of these
or is special — see F-2, where it turns out to be load-bearing for something
else entirely.

### F-2 — With 4 predicates and no `unballot`, predicates cannot be spilled

This is the sharper version of O-14, and it arrives before any workload does.

O-14 states that nothing reverses `ballot`, and defers the fix pending "a case
where a computed (non-constant) lane mask needs to become a predicate." Register
allocation is that case, structurally:

- A predicate can be spilled: `ballot rd, ps` moves the 32-bit lane mask into a
  GPR, which can then be stored.
- A predicate cannot be reloaded. `pmov` is constant-only. Every other predicate
  write (Format C compare, Format G vote) is computed from GPR sources under a
  fixed per-lane rule — none of them can reproduce an arbitrary per-lane bit
  pattern held in a warp-uniform GPR.

So the predicate file has **no legal spill/reload path**. With only 4 logical
predicates and a model that pushes toward if-conversion (per-thread PC, no
reconvergence brackets — see F-4), running out is not a tail case. A backend
that cannot spill a register class cannot guarantee it will compile a kernel; it
can only fail.

There is a synthesizable reload, and it depends on F-1:

```
    ld    Rt, [spillslot]        ; warp-uniform 32-bit mask, same in every lane
    srd   Rl, %laneid            ; requires F-1
    shr   Rt, Rt, Rl
    and   Rt, Rt, #1
    setp.ne P, Rt, #0
```

Four to five instructions per reload, and it only exists if `%laneid` is
readable. `unballot pd, rs` — which O-14 already sketches as fitting the
existing Format G layout with no new fields — collapses that to one.

The finding to carry back to the ISA discussion is not "add `unballot`" on
performance grounds. It is that **`unballot` (or a readable `%laneid`) is what
makes the predicate file spillable at all**, which is a compilability property,
not a density one. That reframes the O-14 trigger condition: it has already
fired.

It also bears on the predicate-count question in §1/§10. If predicates are
spillable, 4 is a performance parameter and spill data decides it. If they are
not, 4 is a hard ceiling on if-conversion depth and the count has to be set
conservatively instead of empirically.

### F-3 — `chwidth` is a mode-switch insertion problem, and the closest prior art is `vsetvli`

Element width as per-logical-register state rather than an instruction field is
the right call for the hardware, and it is the single largest piece of
non-standard work in the backend. LLVM's register allocator assumes a register
class has a fixed type; "R3 is currently 16-bit" has no native representation.

The workable shape:

- **Four register classes over the same 16 (or 32) physical registers**, one per
  width code. Width is a property of the *value* in IR — `<32 x i16>` vs.
  `<32 x i32>` — so this falls out of the type system naturally and is
  TableGen-friendly.
- **`chwidth` insertion is a post-RA pass**, not an ISel concern. It cannot run
  earlier: `chwidth` names a logical register, and which logical register a value
  lands in is not known until allocation is done. The pass computes a per-physical-register
  width dataflow, inserts `chwidth` / `chwidth.multi` at transitions, and hoists
  the multi-register form to a point where the affected registers are cold — which
  is exactly the placement discipline ISA spec §3 (Format I, O-6) asks the compiler for.
- **Prior art: `RISCVInsertVSETVLI`.** Same shape of problem — a mode-setting
  instruction with a real cost, placed by dataflow over a function, minimizing
  transitions. Worth reading before designing this rather than after. The
  difference is that `vsetvli` sets one global state and `chwidth` sets 16
  independent per-register states, which makes the lattice per-register rather
  than per-function but does not change the algorithm.

Two consequences worth flagging back to the ISA side:

- **The allocator needs a width-affinity objective.** Because `chwidth` drains
  in-flight dependents, reusing a physical register across widths is expensive.
  The allocator should softly partition the register file by width. That
  objective **conflicts with the destructive-form preference O-8 asks for** —
  one wants to constrain assignment for encoding density, the other for mode
  stability. Both are "prefer this assignment" heuristics competing for the same
  decision, and the experiment framing in `backend-context.md` §4 should expect
  to measure them against each other rather than independently.
- **This is a third argument toward 32 GPRs**, independent of both spill counts
  and the span/MMA tiebreaker recorded in §10. A kernel that uses two widths
  wants a soft partition of the register file; at 16 GPRs that is 8 usable per
  width. Like the span argument, it is a structural limit that raw spill
  numbers will not surface.

### F-4 — The per-thread-PC model is a large scope reduction, and `reconv.hint` is cheap

Good news, recorded because it changes the build estimate. NVPTX and AMDGPU both
carry substantial CFG structurization machinery to satisfy reconvergence
requirements. `backend-context.md` §5.2 removes that requirement outright —
correctness does not depend on compiler-marked reconvergence points, so
unstructured CFGs are fine and no structurizer is needed. That is one of the
larger GPU-backend cost centres deleted.

`reconv.hint` emission is correspondingly cheap. All three operands are things
LLVM already computes:

| Field | Source |
|---|---|
| Post-dominator bit | `MachinePostDominatorTree` |
| Nesting depth | region / loop nesting depth |
| Alternative path length | static instruction count on the sibling path, post-RA |

A small post-RA pass. Which means **O-4's residual question is answerable early
and cheaply**, exactly as `backend-context.md` §4 anticipates: once hints are
being emitted at real reconvergence points, the join-PC pairing question can be
evaluated against real placement rather than guesses.

### F-5 — Sequencing of the bootstrap kernel set

`backend-context.md` §3 lists three kernel shapes. They are the right three. The
order they are listed in is close to reverse difficulty order, and the plan in
Part 2 below sequences them differently:

- **Elementwise at fixed 32-bit width** is the pipeline validator — it touches
  the fewest ISA features and proves clang → IR → ISel → RA → MC → encode →
  execute end to end.
- **Reduction** adds control flow, Format G shuffles, barriers, predicates. It
  is also where F-2 (predicate spilling) will first bite.
- **GEMM tile** adds shared memory, Format J, and the register-pressure question
  that decides the 16-vs-32 GPR item. Hardest of the three.
- **Elementwise at varying `chwidth`** goes *last*, not with the first
  elementwise kernel, because it depends on the whole F-3 mode-insertion pass.

Same three shapes, same coverage, but each step only adds one new hard thing.

### F-6 — Nothing can be executed yet, and the encoding has no independent checker

The Phase 1 success criterion in `backend-context.md` §5.1 is a trivial kernel
through "PTX → compiler → native ISA → **execution**." There is no execution
target: no RTL yet, no simulator. Without one, the backend can only be inspected,
not validated, and "does it compile" is a much weaker signal than "does it
compute the right answer."

A functional simulator (ISS) is the cheap path and should come early — before
the backend is far enough along to need it. It buys a second thing beyond
execution: an **independent implementation of the decode tables**. The ISA spec
records that all 20 bit maps were checked for field-width mismatch, overlap and
gaps; a decoder written from the same tables and run against assembler output
turns that from a review result into a continuously-enforced one.

The way to get this nearly free is to make the TableGen target description the
single source of truth for encoding, and drive both directions from it. LLVM
generates a disassembler from the same `.td` that generates the encoder, so
assemble → disassemble → compare is a round-trip test for every instruction,
and the ISS consumes the generated decoder rather than a hand-written one.

### F-7 — Retarget NVVM IR rather than modifying clang

Practical note on the frontend decision. clang's CUDA support has NVPTX
assumptions distributed through its CUDA driver and codegen paths; making clang
aware of a new GPU target properly is real work and none of it is ISA-validation
work.

The cheaper path is to leave clang entirely alone and consume its output:

```
clang -x cuda --cuda-device-only -emit-llvm -S --cuda-gpu-arch=<some sm_xx>
```

then retarget the resulting IR. Device IR out of clang is largely
target-neutral; what is not is (a) the NVVM intrinsics and (b) address-space
numbering. Both are cheap to accommodate if decided deliberately up front:

- **Match NVVM's address-space numbering** (0 generic, 1 global, 3 shared,
  4 constant, 5 local) rather than inventing one. The ISA's address spaces are
  already `.global` / `.shared` per opcode, with `.local` windowed onto
  `.global` and `.const` mapped to a read-only `ld.global` contract — that maps
  onto NVVM's numbering without friction.
- **Lower the NVVM special-register intrinsics in the backend.** Which is F-1,
  stated from the other end. The two findings close on each other: the encoding
  gap and the intrinsic-lowering requirement are the same question.

This keeps the whole frontend a solved, unmodified, upstream problem — which is
what `backend-context.md` §2 decided — and confines all custom work to the
backend, which is where the ISA signal comes from.

---

## Part 2 — Plan

Ordered so each step adds one new hard thing, and so the open ISA items get
answered as a side effect of getting kernels through rather than as separate
measurement exercises.

### Step 0 — Close the ISA blockers *(no code)* — **complete**

Every finding that blocked codegen now has a settled direction, recorded in
`proposals/`. Total encoding cost: 4 Format D points, 5 Format K points, 1
Format G point, 1 Format B point. No new formats, no moved fields, nothing above
32 bits.

| Finding | Resolution | Proposal |
|---|---|---|
| F-1a identity primitive | `srd rd, #sel`, Format K, 1 point, 16 selectors | `identity-primitive.md` |
| F-1b kernel parameters | launch block; pointer argument = two 32-bit slots | `launch-abi.md` |
| F-1c entry register state | undefined; fixed address + Format F materialization | `launch-abi.md` |
| F-2 predicate spill path | `ld.pred` / `st.pred`, 4-bit mask, Format D | `predicate-transfer.md` |
| F-8 predicated predicate-dest writes | preserve | `predicate-transfer.md` |
| F-9 stale Format D opcode map | delete the second map | `predicate-transfer.md` |
| F-10 `packi` partial writes | preserve + `packi.z` | `predicate-transfer.md` |
| F-11 address width | `(rbase << 16) + roffset`, 64 bits only in the AGU | `address-model.md` |

**Exit criterion: met.** All of it was folded into ISA v1.3, which superseded
v1.2 as the encoding ground truth at the time. The current spec is
`isa-v1.6-operation-map-and-encoding.md`; every revision before it is kept for
the decision trail. The launch-block byte layout remains an ABI
document to be written, and blocks nothing.

### Step 1 — Machine description and MC layer *(complete)*

**Done:** TableGen target description (`llvm/CCV/`), generating cleanly through
`-gen-register-info`, `-gen-instr-info`, `-gen-emitter`, `-gen-disassembler` and
`-gen-asm-writer`; encoding invariant checker (`tools/check-encoding.py`); gate
script (`tools/verify.sh`). 65 instructions, at least one per format. Five new
findings, F-12 to F-16, all from transcribing §3 into a form a machine checks.

**Also done:** the C++ MC layer — target registration, `MCTargetDesc`, code
emitter, instruction printer, disassembler — built out-of-tree against installed
LLVM 18, plus `ccv-roundtrip`. **The Step 1 exit criterion is met**: 4160
encode/decode round trips clean across all 65 instructions, covering all three
instruction lengths.

**Next:** the asm parser (`-gen-asm-matcher`), so assembly can be round-tripped
as text rather than as `MCInst`s. Not a blocker for Step 2 or Step 3.



TableGen target description, register info, instruction definitions, asm
printer, asm parser, encoder, disassembler. No instruction selection yet.

Decisions to build in from the start:

- **GPR count and predicate count as subtarget features** (`+gpr32`, etc.), so
  the 16-vs-32 and predicate-count experiments are a flag flip rather than a
  fork. This is the single cheapest thing that can be done now to make the
  §10 open items answerable later.
- **Compressed forms (J and K) as a TableGen-driven MC-layer compression pass**,
  on the `RISCVCompressInstEmitter` / `CompressPat` model — not as an ISel
  concern. Density instrumentation for O-8 and O-9 then falls out of that pass
  as a counter rather than needing separate tooling.
- **48-bit siblings as MC-layer relaxation.** Select the short form, relax when
  the immediate does not fit. The "same tag, identical `[31:6]`, 16 more
  immediate bits" property makes this mechanical.
- Note that LLVM's variable-length encoding support (`VarLenCodeEmitterGen`) is
  thinly used upstream — M68k is the main consumer. Expect rough edges here.

**Exit criterion: met.** Every format encodes, disassembles and round-trips —
via programmatic `MCInst`s with randomized operands rather than hand-written
assembly, which covers more of the encoding space than a fixed test corpus
would. Text assembly follows with the asm parser.

### Step 2 — Functional simulator *(exit criterion met)*

**Done:** `tools/ccv-sim` executes a warp of 32 lanes with independent
per-thread PCs, driving the generated disassembler so decoding is not
re-implemented — the simulator is semantics only, which is the division F-6
settled on. Plus `tools/ccv-as.py`, a minimal assembler driven from the
TableGen JSON, so kernels are text rather than hand-built `MCInst`s.

**Exit criterion: met.** `test/elementwise.s` assembles, executes and produces
correct results for all 32 lanes, at three divergence levels (32, 20 and 1 active
thread). `tools/run-tests.sh` is the gate.

Two things it demonstrated that the encoding work could not:

- **Opportunistic reconvergence works as §1 describes it.** Under divergence the
  issue mask narrows to the active lanes for the body and returns to `ffffffff`
  at `exit` — lanes regroup because their PCs coincide, with no bracket
  instruction and nothing forcing it.
- **O-24**, below: a kernel cannot execute a single compare without first
  manufacturing an all-true predicate.

**Not yet:** shared memory, barriers, atomics, and the `chwidth` narrow-width
paths. Added as the reduction and GEMM kernels need them.

### Step 3 — Instruction selection, elementwise kernel at 32-bit width *(complete)*

**Exit criterion met — and with it the `backend-context.md` §5.1 Phase 1
milestone.** A CUDA kernel compiles from source and executes correctly:

```
vadd.cu → clang → NVVM IR → CCVLowerKernelArgs → ccv-llc → ELF
        → .text → ccv-sim
```

Nothing in that chain is hand-written. `tools/run-e2e.sh`:

```
  PASS  n=32: 32 lanes correct (18 issue groups)
  PASS  n=20: 32 lanes correct (18 issue groups)
  PASS  n= 1: 32 lanes correct (18 issue groups)
  PASS  n= 0: 32 lanes correct (10 issue groups)
```

`n=0` is worth its own line: every lane takes the compiled guard branch and the
body is skipped, so the group count drops. Inactive lanes are checked to be
*untouched*, not merely wrong-free.

**What the pieces are.**

- *Frontend* — clang unmodified, no CUDA toolkit (F-7 in practice).
- *Kernel ABI* — parameters become invariant launch-block loads; the address
  model is explicit IR arithmetic, so the aligned case constant-folds and O-23
  falls out of the optimiser.
- *Address lowering* — consumed in a DAGCombine before type legalization, so no
  register ever holds an address (invariant 11, F-20).
- *Predicates* — codegen pseudos carry predicate registers and are expanded
  after register allocation, where the register number becomes the qualifier
  immediate. O-24's guard is tied to the compare's destination, so the allocator
  enforces the self-guarding form.
- *Branch fixups* — §3's offsets are PC-relative, halfword-granular, and
  measured from the next instruction; `bra.pred`'s is **split around the
  qualifier**, so it is scattered by hand in `applyFixup` (F-25).

**Deliberately not done:** unsigned and FP compares (F-24), calls (F-21, F-22),
`i32`/`f32` bitcasts, inline asm. Each is diagnosed rather than miscompiled.

### Step 4 — Reduction kernel *(complete)*

Added control flow, Format G shuffles, barriers, predication, and `reconv.hint`
emission. First real exercise of the predicate file — where F-2 got tested
against practice rather than argument.

**Produced:** predicate pressure of 1–2 of 4 across every kernel written since,
which is what made O-33's unconditional reservation of P3 affordable. F-2's
spill path exists and is exercised by O-30 rather than by this step, because the
reduction never needed it. `tools/check-relaxation.py` and the barrier tests in
`tools/run-tests.sh` are this step's regression surface.

### Step 5 — GEMM tile *(complete)*

Added shared memory, Format J accumulate, and serious register pressure.

**Produced:** `tools/sweep-tiles.sh` and the table in `docs/benchmarks.md` §3.
`sp/fma` bottoms out at the 2×4 tile and rises again at 4×4, so 16 GPRs put the
practical ceiling at 2×4 — which is what §1 guessed before there was anything to
measure. Format K hit rate is 13–22% and falls as pressure rises, so O-29's
proposed allocation bias would pay least where code size matters most. Getting
here also produced F-46 (no spill path at all — the backend could not compile a
GEMM at any tile size) and F-47.

**The GPR count is no longer the question.** Settled at 16 (v1.5 O-25), so this
step is not a 16-vs-32 experiment. What it measures instead:

1. **Spill by cause, not volume.** Separate accumulator spill — the live risk —
   from pointer and index spill, which O-23 already addresses. A total is not
   interpretable.
2. **Accumulator tile sweep.** 2×2, 2×4, 4×4; report where spill traffic overtakes
   the arithmetic-intensity gain. **FP32 and INT8 separately** — `dp4.acc` performs
   four MACs per accumulator register, so it changes the answer for INT8 and not
   for FP32. FP32 accumulation is the case with no mitigation.
3. **Aligned and unaligned shapes separately** (O-23). The unaligned prologue
   overstates both register pressure and compressed-form density — four of the
   seven instructions alignment removes are 16-bit.
4. **Warp-invariance reporting.** How many warp-invariant values are simultaneously
   live at peak. LLVM's divergence analysis already computes this; it is reporting,
   not new analysis, and it is the only evidence that would size the warp-uniform
   register file that v1.5 §1 names as the response if the GEMM data is bad.

**Note on framing:** per `backend-context.md` §4, ambiguous spill data tips
toward 32 because of the span/MMA register-group argument. F-3 adds a second
independent argument in the same direction. The experiment should report spill
counts *and* width-transition counts, so both arguments are measured rather than
only the first.

### Step 6 — `chwidth` mode insertion, elementwise at varying width *(in progress)*

The F-3 pass. Last because it is the largest single piece of non-standard
backend work and because it benefits from having working kernels to regress
against.

**Produces:** width-transition frequency and `chwidth.multi` hoisting
effectiveness — data on whether the O-6 multi-register form earns its format.

**The `chwidth` pass now exists, for 16-bit width.** `CCVInsertChwidth` is a
post-RA forward dataflow over physical registers, placing `chwidth` at width
transitions; `ccv-sim` executes narrow-width integer ALU and memory, with
transfer size taken from `rdata`'s width per §3. A 16-bit kernel compiles from
LLVM IR and runs.

Three things it produced that the argument did not:

- **F-65** — the ISA never says what the bits above a narrow element hold after
  widening. The pass is built to be correct either way: it inserts `chwidth`
  only at a definition (old value dead) or as a *narrowing* of a live register
  (a truncation, element bits preserved), never as a widening.
- **The width is per OPERAND, not per instruction.** A 16-bit store takes a
  16-bit data register and a 32-bit base address. A per-instruction width tag
  was built first and set the mode on the address register.
- **F-66** — narrow→wide extension has no lowering and fails loudly.

**Still open from F-3's list:** `chwidth.multi` merging (O-6), i8 and i4, the
width-affinity allocator objective and its conflict with O-8's destructive-form
preference, and the width-transition measurement across real kernels rather
than one test. Much of the earlier part of this step went to work the benchmarks
surfaced instead — O-31 through O-37 — which was a deliberate reordering, each
driven by a measurement rather than by the plan.

---

## Part 3 — Open items tracking

Mirrors `backend-context.md` §4, annotated with where in the plan each gets
answered. Update as items resolve.

| Item | Answered by | Status |
|---|---|---|
| F-1a identity primitive | Step 0 | **resolved — `srd rd, #sel`, Format K, 1 point; see `proposals/identity-primitive.md`** |
| F-1b kernel parameter passing | Step 0 | **resolved — launch block; pointer arg = two 32-bit slots** |
| F-1c entry register state / ABI | — | **resolved — fixed address + Format F materialization; entry state stays undefined** |
| F-11 address width | Step 0 | **resolved — `(rbase << 16) + roffset`, 64 bits only in the AGU** |
| F-2 predicate spill path / `unballot` (O-14) | Step 0 | **resolved — `ld.pred`/`st.pred` at Format D opcodes `01000`–`01011` (global and shared, 4-bit mask) and `unballot` at Format G point 9; both in `CCVInstrInfo.td`, and O-30 spills predicates through them. Row said "open, blocks Step 4" until the 2026-09-14 audit, two steps after Step 4 shipped** |
| F-8 predicated write to a predicate destination — preserve or clear? | Step 0 | **resolved — preserve, and generalized: invariant 10 says a partial write preserves what it does not write, at all three sites that ask (predicated GPR write, predicated predicate write, `packi`). Clearing is a separate opcode where it is wanted, never a change of rule** |
| F-10 `packi` partial-write semantics — preserve + `packi.z` variant | Step 0 | **resolved — preserve (invariant 10), with `packi.z` at its own Format B opcode point for the clearing semantic. §3 carries both** |
| F-9 Format D carries two contradictory opcode maps (editorial) | — | resolved in v1.3 |
| F-12 32 GPRs is an encoding fork, not a subtarget flag | — | **closed — 16 settled in v1.5 O-25.** `GPRC` and R16–R31 removed from the machine description; one encoding path, two allocator objectives not three |
| F-17 §5.5 figures were wrong (23 not 22 instructions, 27.1 not 28.4 b/instr, 8 not ~10 live) | — | fixed in v1.4; `tools/check-listings.py` now re-derives them |
| F-17a Both worked listings were hand-written, so neither tracked codegen | — | resolved — `tools/check-spec-vs-codegen.py` diffs §5.5 and §5.6 against fresh `ccv-llc` output in `verify.sh`; caught peak-live 8→5 and the uncompressed third fold |
| F-20 LLVM requires a pointer in a register; invariant 11 says there is none | Step 3 | **resolved — consumed in a pre-type-legalization DAGCombine; no 64-bit register class. Severity was overstated; see `proposals/pointer-representation.md`** |
| F-21 Value-returning device functions need a variadic return pseudo | Step 4 | open — kernels return void, so not blocking |
| F-22 Pointers escaping an addressing mode have no lowering convention | Step 4 | open — diagnosed at compile time, not silently miscompiled; needs an (rbase, roffset) pair convention |
| F-23 The <4 GiB allocation precondition is implicit in the lowering | Step 5 | open — belongs with O-23's launch-time validation; the compiler cannot check it |
| F-24 Unsigned and FP compares not selected | Step 4 | **resolved — Format C/C′ now carry one shared 16-point compare map (O-26). Unsigned lt/le and FP olt/ole/oeq/une select; gt/ge come from operand swap. SETONE/SETUEQ/SETO/SETUO still diagnosed** |
| F-30 `bar.wait`'s phase parity is an immediate, but must alternate per dynamic execution | Step 4 | **resolved — O-27. The per-warp epoch moves into hardware, so the compressed `bar.wait #id` carries no phase and is correct at every iteration; `[14]` becomes reserved. `test/accept/barrier-in-loop.ll` was a reject case and is now an accept case** |
| F-35 `bar.wait.phase` has no selection path | Step 5 | open — O-27 added it at Format E `00100` for pipelined producer/consumer, where a warp waits on a barrier it did not arrive at. Encodable, assembler-reachable and round-trip tested, but CUDA C produces it only through async-pipeline intrinsics, which the frontend path does not yet carry |
| F-36 The whole accept/reject suite was gitignored | — | **resolved — a stray `*.ll` rule meant 16 of 19 files under `test/` were never committed; a fresh clone had three `.cu` files and no regression suite. `run-tests.sh` now fails on an empty suite rather than passing vacuously** |
| F-31 Shared memory (`addrspace(3)`) has no load/store selection | Step 4 | **resolved — `CCVLowerShared` assigns each shared object its offset in the CTA allocation and replaces the global with an `inttoptr` constant; `.shared` is flat 32-bit so there is nothing to relocate. Base+index forms added at Format D `00110`/`00111`. The windowed DAGCombine is now excluded from `.shared`, which it would otherwise have miscompiled** |
| F-37 The windowed DAGCombine had no address-space guard | Step 3 | **resolved — `matchBaseOff` matches any constant address, so a `.shared` access at a constant offset would have become an `ld.global` of that offset. Guard is "not shared", not "is global": `.const` and `.local` are windowed too (§5.1), and an early attempt at "is global" broke every launch-block load** |
| F-38 Most of §3/§4's opcode map had no instructions | Step 4 | **resolved — 4 of Format K's 24 ALU points and 3 of Format A's 26 integer points existed; the rest were added from §3 and §4's own lists. 148 instructions, up from 68 at the start of Step 4. Exposed O-28: the spec named operations but never numbered them, and the numbering is load-bearing** |
| F-39 Signed fields decoded unsigned — every backward branch was wrong | Step 4 | **resolved — TableGen's default decoder zero-extends, so `bra -26` decoded as `bra 2097126` and every negative load/store displacement was wrong too. Signed operand classes now carry an explicit `decodeSImm<N>`. Invisible until the reduction, because every branch before it was forward** |
| F-40 The round trip could not catch F-39 | Step 4 | **resolved — two independent gaps. It generated immediates as `RNG() & Mask`, so no signed field ever saw a negative value; and it compared only register operands, so the entire immediate path was unchecked. Operand widths were also taken from the *narrowest* field on the instruction (2 bits on a Format C compare), so wide immediates were only ever tested with tiny values. Now per-operand width and signedness from the same `.td`. Verified by reverting F-39's fix: 34 failures, then 0** |
| F-41 Simulator lacked shared memory, barriers, and most of the ALU | Step 4 | **resolved — `.shared` as a separate flat 32-bit space, barrier arrival/epoch state per lane with scheduler stalls and deadlock detection, and the full §3/§4 ALU and compare sets. `tools/run-reduce.sh` runs the block reduction from CUDA source to a correct sum** |
| F-42 `select` hung the compiler in an infinite legalization loop | Step 5 | **resolved — SELECT was Expand, which expands to SELECT_CC, which was also Expand and expands back to SELECT. Not a crash: ccv-llc spun. Latent since Step 3 because every conditional until now became real control flow. §4 point 19 is `sel`, now defined (Format A′, and the one predicated instruction that writes rd unconditionally)** |
| F-43 Compressed shift immediates were silently truncated | Step 5 | **resolved — `(shl/srl/sra GPR, imm)` selected Format K's 4-bit immediate form with no range predicate, so a shift by 31 encoded as a shift by 15. Invisible to the round trip, which agrees with itself on the truncated value. `verifyImmediatesFit` in the emitter now rejects any immediate that does not fit its field, checked against the same `.td` — the general form of the bug, not just this instance** |
| F-44 Predicate copies were emitted as GPR moves | Step 5 | **resolved — `copyPhysReg` emitted `C_MOV` for every copy. P0–P3 and R0–R3 encode identically, so `mov p1, p0` assembled, disassembled and executed as `mov r1, r0`, silently clobbering a GPR. Predicate copies now use `por pd, ps, ps` (O-20, 16 bits, no new opcode); a GPR↔predicate copy is a hard error** |
| F-45 Integer division had no lowering | Step 5 | **resolved — `CCVExpandDivision` applies LLVM's shift-subtract expansion in IR, as nvcc does for the same reason. Constant divisors never reach it; instcombine turns those into a multiply and a shift. Executed in the gate, not just compiled** |
| F-46 No spill path — the allocator corrupted the heap | Step 5 | **resolved — O-30. Not "spills badly": the backend could not compile a GEMM at all, at any tile size including 1×1, and crashed with `free(): invalid pointer` from inside `InlineSpiller` rather than diagnosing. `.local` now has a window per thread, the frame pointer is a window index, and predicates spill through O-19's `ld.pred`/`st.pred`** |
| F-47 `CCVWindowRemat` held raw pointers across recursive deletion | Step 5 | **resolved — two roots can share operands, so deleting one frees instructions still in the list. Use-after-free, surfaced as heap corruption in the GEMM (whose window chains share a launch-block load) and in nothing earlier, where the chains were disjoint** |
| F-48 Integer division used a shift-subtract loop where a float reciprocal would do | Step 5 | **resolved — O-31. Measured before fixing: one `udiv` was 97 dynamic instructions per thread. Now 32, straight-line. `transpose` fell from 143 static instructions to 83, and from 482 bytes to 294 — below GCN's 308, so CCV is now smaller on every benchmark kernel. Exactness checked against integer division over the edge cases and a large sample, not argued** |
| F-49 Float division (`fdiv`) has no lowering | Step 6 | **resolved — O-36.** Software sequence over `rcp.f32` and `ffma`: exponents forced to zero, two Newton refinements, an FMA residual that makes the rounding correct, and a split scalbn. Correctly rounded whenever the result is normal — 40184/40184 in the algorithm model and 10240/10240 executed on the simulator. Subnormal results are 1 ulp out (F-62). About 30 instructions, which is what IEEE division costs without a divider. Previously — only `1.0f/x` is selected, to `rcp.f32`. General IEEE `a/b` needs a Newton sequence with correct rounding, which is its own piece of work. CUDA's default `/` on floats is IEEE-correct, so this is a compatibility gap, not an optimisation one |
| F-50 No memory instruction had `mayLoad`/`mayStore` set | Step 5 | **resolved — they are selected in C++ from CCVISD nodes rather than from patterns, so TableGen had nothing to infer from and marked every load and store as having no memory effect. Nothing depended on it (no scheduler is enabled) but it is wrong for anything that reorders, and it made the simulator's counters classify every global access as ALU** |
| F-51 No execution counters | Step 5 | **resolved — `ccv-sim -counters` reports issue groups, lane-instructions, per-thread work, SIMT efficiency, dynamic bits/instruction, and a breakdown by class with spill traffic separated. Static count is a proxy for work done; this is the measurement, and the two differ by 3x on a kernel with a division in it** |
| F-52 Warp-uniform values are computed redundantly in all 32 lanes | Step 6 | open — measured against AMDGCN on `transpose`: the divisor is uniform (it depends only on `blockIdx` and `n`), so their compiler puts the whole division on the scalar unit at one instruction per operation for the wavefront, while CCV recomputes it in every lane. 77 issued against 64, and the instruction counts understate it — a scalar instruction is a fraction of the energy of a 64-lane vector one. **This is the first measured evidence for the warp-uniform register file §1 names as O-25's fallback**, which was argued from register pressure and turns out to matter for redundant execution first. LLVM's divergence analysis already computes what is uniform |
| F-53 O-24's manufactured predicate cost an instruction per compare | Step 6 | **resolved — O-32. §1's own rule says every predicated operation needs a distinct unpredicated encoding (hence A/A′/A″ and D/D′); the compare family was the exception, having spent both tags on reg-reg vs reg-imm. Format C″ at tag `1111`, 32-bit, which was free because H is 48-bit only and §2 decodes length before the tag. One tag covers both operand shapes because dropping the qualifier frees three bits. Dynamic cost in the reduction kernels went from 13% to zero: `dot` 91.9 → 78.9, `reduce` 88.9 → 75.9 instructions per thread** |
| F-54 All sixteen 32-bit format tags are now allocated | — | open, informational — O-32 took the last free one. A future format needs either a sub-encoding inside an existing tag (as `bar.wait.phase` did with a Format E opcode point) or a 48-bit-only home. Worth knowing before the next format is proposed, not a problem today |
| F-55 `shfl` is predicated-only, so a broadcast needs a guard | Step 6 | **resolved by not needing one — O-33 guards the broadcast with the NEGATED lane-0 mask, which is the mask it already has. Lanes 1–31 read lane 0 and lane 0 keeps its own value (invariant 10), so one instruction is a complete broadcast and no all-true predicate is involved** |
| F-56 Conversions and SFU cannot be predicated | Step 6 | **resolved — O-34 and O-37.** O-34 moved conversions into 64–127, inside Format A′'s 7-bit reach (3 → 1 on `transpose`). O-37 then gave Format A′ a **48-bit sibling** carrying the full 10-bit opcode, so `rcp.f32` at §4 point 256 — the last one — can carry a qualifier too. `transpose`'s "no A′ form" bucket is **0**. The finding is closed in the stronger sense as well: §4's extension space is no longer a one-way door, so allocating an operation above 127 does not forfeit its predicated form |
| F-57 The uniformity report's blocked bucket was a catch-all wearing an ISA claim | Step 6 | **resolved — `isPredicable` ended in `default: return false`, and everything that fell through was printed as "blocked: encoding (§4 128+/256+ have no A′ form)". Branches, stores, `srd` and `select` all landed there, so F-56 was sized at 5 in `transpose` when 3 were conversions, and `select` counted as MASKABLE, inflating the reported ceiling from 44 to 54 and understating broadcasts by half. Now seven named buckets with distinct owners — spec change, `.td` gap, invariant 7, semantics, contended field, control flow, and an UNMODELLED bucket that names its opcodes. `tools/check-uniformity-buckets.sh` fails the gate on any unmodelled instruction, and on an F-56 count in a kernel with no conversion. Verified by breaking `classify()` on purpose and watching it fail** |
| F-58 `sel` spends the qualifier field on data, so no `select` can be masked | Step 6 | **resolved, and the premise was wrong twice.** The finding said a value already predicated for control flow cannot also be masked to lane 0 because both want `[29:27]`, and that a second predicate field is the only fix. Neither holds. **(1) Those selects never needed `sel`.** All seven in the benchmark set are the conditional-overwrite shape `sel rd, a, rd`, which is exactly `@q mov rd, a` under invariant 10 — same instruction count, and the predicated form writes only the guarded lanes instead of all 32. `PSEUDO_PMOV` is now two-address so the coalescer produces it, and §4 point 18 gained its Format A′ encoding. Measured on `transpose`: 1747 → 1587 lane-activations, **no change in instruction count**. **(2) Predicates compose.** The qualifier names a predicate *register*, and the conjunction of two conditions is a predicate register — §3's `pand` is a 16-bit Format K instruction that computes it. The field was never the constraint; nobody was computing the conjunction. `-ccv-mask-compose`, **on by design-track decision**: one `pand` buys ~12 lane-activations against O-33's 31-per-instruction. It spends a second RTL property on top of O-33's first — a predicate-file op must cost much less than a warp-wide one — and that obligation is now recorded in §9, O-33 alongside lane gating. `transpose` 1555 → 1493; the flag withdraws this row alone if the property does not hold. `tools/run-tests.sh` fails if a select ever lowers back to `sel` |
| F-59 §4's `cvt` block has a count but no arithmetic | Step 6 | **resolved — O-34.** First framing was wrong and said §4 had no encoding for an integer source: the 2-bit format code selects an interpretation read at the register's `chwidth`, not a width, and codes `10`/`11` were unallocated at every `chwidth`. What was real is that §4 fixed the block's shape and never its arithmetic, so `CCVInstrInfo.td` assigned 128–131 flat. Now `64 + 16×dest + 4×src + round`, normative. The design track took the decision on a stronger ground than the proposal argued: the eight destination bases differed by element width, which is an element-width field in the opcode and a violation of invariant 1 |
| O-33 lane-0 masking | Step 6 | **done — `ccv-mask-uniform`, on by default, `-ccv-mask-stats` to report. Result-identical by construction and checked as such: `tools/check-mask.sh` runs the same kernel masked and unmasked against an independent reference and fails if nothing was masked, so it cannot pass vacuously. Measured −14% lane-activations on a uniform-chain microbenchmark and −21.5% on `transpose`. The IR-level ceiling reported alongside it was overstated until F-57; `transpose`'s is 44 maskable against 33 crossings, not 54 against 17** |
| O-25 warp-invariance reporting | Step 5 | **done — `ccv-llc -ccv-uniformity-stats`. Needed a warp-scoped `CCVTTIImpl`, because LLVM's stock NVPTX answer calls `ctaid` divergent, which is right across a grid and wrong across a warp. Result: addressing-dominated kernels are 52–75% warp-uniform, GEMM is 14%, and peak uniform values live is 4–11 against §1's guessed 16-entry file** |
| F-32 Cross-block window values crashed the type legalizer | Step 3 | **resolved — `CCVWindowRemat` clones the window chain into each using block before ISel, so the DAGCombine always sees it locally. Any kernel with control flow hit this; vadd escaped only by being one basic block. `test/accept/window-cross-block.ll`** |
| F-33 `ConstantFP` expanded to a constant-pool load | Step 4 | **resolved — there is no constant pool and no addressing mode for one; ConstantFP is Legal and the f48 wide immediate carries the bit pattern, so a float constant costs what an integer constant costs** |
| F-34 TableGen re-ran only for four of the seven `.td` files | Step 3 | **resolved — `CCVInstrPatterns.td` and `CCVCallingConv.td` were missing from CMake's `DEPENDS`, so pattern edits silently reused stale tables and TableGen's errors never reached the build log. Now globbed; `verify.sh` also runs `gen-dag-isel` and `gen-callingconv`, which it never did** |
| F-26 No branch-analysis hooks, so fall-through edges became real branches | Step 3 | resolved — `analyzeBranch`/`removeBranch`/`insertBranch`/`reverseBranchCondition`; the kernel went from 18 instructions to 17, matching §5.6 exactly |
| F-27 Unaligned pointer addressing is not implemented | Step 3 | **resolved — `matchBaseIdx` folds `roffset + (i << scale)` into one index register with scale-enable clear, trading O-7's scaling for the fourth addend. §5.5 is now generated from codegen, so O-23's "both shapes supported" is fact** |
| F-28 `bra.short` (Format K, ±256 B) has no selection pattern | Step 4 | **resolved — not a pattern question: whether a branch fits is a property of the final layout, so the selector always emits the 16-bit form and `CCVAsmBackend` relaxes it to Format E's `bra` when it cannot reach. Neither direction shows in the `.s`, which prints `bra.short` either way, so `check-relaxation.py` asserts both against the objects. Teaching only the selector would have silently reintroduced F-26: `analyzeBranch` recognised one opcode as an unconditional branch, and the dead fall-through came straight back** |
| F-29 No compressed-form (Format K) selection path | Step 4 | **resolved — `CCVCompress` compresses what already satisfies `rd == rs0` and never inserts a copy to create it; O-29 records why the other half is deliberately left open. O-8 instrumentation now exists (`-ccv-compress-stats`): 2 of 3 on §5.5, 0 of 1 on the reduction, and 0 candidates on §5.6 because alignment already removed them. Too few to be a rate — Step 5's GEMM is where it means something** |
| F-25 Branch relocations | Step 3 | resolved — three fixup kinds; `bra.pred`'s split field scattered in `applyFixup` |
| F-19 Every compare is predicated; a kernel must manufacture a true predicate | Step 2 | resolved in v1.4 O-24, refined in v1.5 — self-guarding form costs one predicate, not two; regression test in `test/predicate-remat.s` |
| F-18 Two of the four GPR arguments are contingent on kernel-pointer alignment | Step 0 | resolved — per-argument attribute, v1.4 O-23; see `proposals/pointer-alignment.md`. Step 5 must report both shapes |
| F-13 Format G is several field layouts presented as one table | Step 1 | resolved in v1.4 — written out as four tables |
| F-14 Format B′/B″ move the predicate qualifier off `[29:27]` | Step 1 | resolved in v1.4 — O-22; checker now reports 0 deviations |
| F-15 Invariant 8 claims a shared J/K compressed geometry that does not exist | Step 1 | resolved in v1.4 |
| F-16 Invariant 8's "no exceptions" claim does not cover Format I | Step 1 | resolved in v1.4 — exclusions named |
| O-8 compressed-form density | Step 5 | instrumentation done (`-ccv-compress-stats`, O-29); the measurement that matters is the GEMM inner loop |
| O-9 compressed ld/st offset distribution | Step 1 instrumentation + Step 5 | not started |
| GPR count 16 vs. 32 | Step 5, both configurations | not started |
| Predicate count | Step 4; gated on F-2 | not started |
| O-4 `reconv.hint` join-PC pairing | Step 4 | not started |
| O-12 barrier phase-parity assumption | Step 4 (check against barrier spec) | not started |
| F-60 `lane-activations` charged predicate-file ops 32 lanes each | Step 6 | **resolved.** `pand`/`por`/`pxor`/`pmov` read and write the predicate file — 32 bits, one per lane (invariant 5) — and never touch a GPR lane, an ALU operand or a result bus, which is exactly what the counter is defined to measure. Charging them the same 32 activations as a warp-wide ALU operation overstated them by roughly the width of a lane. Now counted separately as `predicate-file ops`. This was not cosmetic: it **inverted a design conclusion** — F-58's `pand` composition measured as a clear loss against the broken counter (1587 → 1685) and as a modest win against the fixed one (1555 → 1493). The sixth time a number in this project was wrong in a direction that would have changed a decision |
| F-61 The fp32 reciprocal round trip cost four instructions per division | Step 6 | **resolved — O-35.** O-31 built integer division on `rcp.f32` because §4 had no integer reciprocal, which meant `cvt.f32.u32` / `f48` / `fmul` / `cvt.u32.f32` around it. The obvious fix — a more accurate `rcp.f32` — buys **nothing**: fp32 has a 24-bit significand, so even a correctly-rounded reciprocal leaves an error near 2⁸ once scaled to 2³², and the Newton step is forced by the format rather than by the unit. `rcp.u32` at §4 point 263 returns the seed directly under a 16-bit relative-accuracy contract, measured by `tools/model-rcp.py` and enforced by the simulator returning the worst legal value — `tools/check-div.sh` fails on eight cases at 15 bits. Sequence 21 → 17 instructions; `transpose` 89 → 86 static and 1493 → 1428 lane-activations |
| F-62 Subnormal quotients are 1 ulp out | Step 6 | open, bounded — O-36's final scalbn is two multiplies and the last rounds a value already rounded. Double rounding, and not fixable with multiplies. Affects only results below the smallest normal fp32; `tools/model-fdiv.py` and `tools/check-fdiv.sh` both measure the gap rather than assume it, and fail if it exceeds 1 ulp. CUDA with `-ftz=true` flushes these to zero anyway |
| F-63 `ffma` was not fused in the simulator | Step 6 | **resolved.** Written `a * b + c` — two roundings — for an instruction whose name is the fusion, and it had been that way since the instruction was added. Nothing depended on single rounding until O-36's residual step, which rests on it entirely: 164 of 2048 divisions came out 1 ulp wrong against a model that was right. Now `std::fmaf`. **A wrong instruction semantic that no test could see, because every test that used `ffma` used it for arithmetic where the difference does not show** |
| F-64 Two immediate-selection bugs, both pre-existing | Step 6 | **resolved.** (1) Any i32 constant with the top bit set reached `MOVI48` sign-extended and the encoder rejected it, so `and x, 0x807FFFFF` was a hard compiler error; the target constant is now carried as i64 so it arrives zero-extended. (2) `add reg, imm` had no range predicate, so a constant above 4095 selected into `ADDI` (13-bit field) and was rejected — the identical defect to F-43, sitting one line above the comment that explains F-43. Both found by the software divide needing a mask and a large addend; neither has anything to do with division, and nothing in the suite had used either shape |
| F-65 The ISA does not say what widening a narrow register yields | Step 6 | **resolved — O-38: cleared.** §1 said a narrow register is "a narrower physical slice of a row" and §3 said `chwidth` "reinterprets the existing contents", but nothing said what the bits above the element hold afterwards. **Decided on security grounds**: the register file is partitioned between resident warps and reused across launches, so stale bits in a reclaimed slice are another warp's data or the previous kernel's, readable by an unprivileged width change. `ccv-sim` preserved them at first, on O-35's model-the-worst-contract principle — right in general, wrong here, because it trades an information leak against a correctness mistake. §1 now states the clear as a bullet, and `test/chwidth.s` asserts it |
| F-66 Narrow→wide extension has no lowering | Step 6 | **resolved.** `zext` is free — O-38 makes a widening `chwidth` clear the exposed bits, which is exactly a zero-extension. `sext` is **one instruction**, and O-34 had already specified it without anyone noticing: both its format codes are "signed integer" and the widths come from the registers' `chwidth`, so §4 point 104 is s8→s32, s16→s32 and s4→s32 alike. The obvious lowering is three instructions — widen, `shl`, `sra` — and §3's shift-immediate forms carry four bits, so a shift by 16 needs a register too |
| F-67 A 16-bit global store selected the 32-bit form | Step 6 | **resolved.** `store i16` to `.global` went through the window-model selection path, which was width-agnostic and picked `st.global` at 32 bits. §3 takes transfer size from `rdata`'s `chwidth`, so that wrote **four bytes into a `short` array**, clobbering the next element. **Every output the kernel was asked about was correct** — the right value at the right address, with two extra bytes past it — which is why no existing test could see it. `tools/check-narrow.sh` writes a guard element past the array and checks it survives; with the bug restored, all 32 results still pass and only the guard fails |
| F-68 The ISA does not say what width an addressing index is read at | Step 6 | **resolved — O-39: 32 bits, always.** Only `rdata` participates in the element-width model; `rbase` and `rindex` are address components and invariant 11 keeps addresses out of it. §3 now says so, and says the consequence too: `rdata` **may** share a register with `rbase` or `rindex`, because the address read takes all 32 bits that a narrowing `chwidth` left intact. The `@earlyclobber` workaround is gone and with it the extra register per narrow load |
| F-69 `chwidth.multi` merging recovers nothing on a real kernel | Step 6 | **resolved, and the answer is "it depends on the kernel shape".** The pass now hoists each width change as early as it is legal — up past any instruction that does not touch the register, stopping at block entry — which is the placement §3 asks for, and then merges adjacent same-width runs. Measured: `test/accept/chwidth-multi.ll` (four narrow loads from one base, the "entering a packed section" shape §3 names) merges **2 of 3, 3 instructions to 2**. `vadd16` still merges **0 of 3** after hoisting 2 — and that is correct, not a failure: its transitions are separated by address arithmetic **on the very registers being narrowed**, so no legal placement brings them together. **O-6 earns its format on the first shape and cannot on the second**, which is a sharper statement than §3's and worth carrying back |
| F-70 §2's sibling rule still said "16 more **immediate** bits" | Step 6 | **resolved — external v1.6 review.** O-37's log entry claimed "§2's wording was amended accordingly" and §3 quoted the exact replacement, so the document asserted in two places that §2 was fixed while §2 still carried the pre-O-37 rule. A reader starting at §2 — where the encoding is introduced — concluded the A′ long form was irregular, which is the misreading O-37 wrote the amendment to prevent. §2 now says "16 more bits" and names what fills them: an immediate in B/B′/B″/C′/D/D′/F, an opcode extension in A′ |
| F-71 §2's tag-length prose contradicted the table above it | Step 6 | **resolved — external v1.6 review.** "Nine of sixteen tags have a 48-bit form" against a table listing **eleven**, with an exclusion list wrong twice over: A′ is in "the A family" and has had a 48-bit form since O-37 (the table says so one line earlier), and Format I has one (`pmov` is 48-bit only, as §3 states). §3's copy of the same sentence was correct; §2's was the stale one. Now eleven, and "A, A″, C, E, G" to match §3 |
| F-72 Format F's immediate width was given two different values | Step 6 | **resolved — external v1.6 review, and the only one an implementer could have acted on.** The wide-immediate siblings table said 18/34 bits at `[31:14]`; the Format F bit maps say 17/33 at `[31:15]`, and F's own prose says "33 bits still covers any 32-bit constant with room over". The bit maps are right: F was realigned in the V1.2 deep dive to put `rd` at `[14:11]` and the opcode at `[10:6]` for invariant 8, at a cost of exactly the one bit. The siblings row was never updated and **has been wrong through 1.2, 1.3, 1.4, 1.5 and 1.6**. It never reached silicon-facing code because `FormatF`/`FormatF48` were written from the bit maps — the document was the only thing that disagreed. Fixed, and `tools/check-spec-tables.py` now parses both and requires them to agree |
| F-73 A fact stated twice eventually disagrees with itself | Step 6 | **resolved — `tools/check-spec-tables.py`, in the gate.** F-70/71/72 are one failure mode (a table updated, the prose beside it not), and it is the mode this project keeps hitting: O-28's opcode numbering described as a product with no arithmetic, three TableGen field-position deviations surviving prose review across three revisions, now this. The checker parses the siblings table against the §3 bit maps as **sets of bit positions** (so `[31:19]` and `[31:30]`,`[26:19]` compare equal), requires 48-bit = 32-bit + 16 and a high half at `[47:32]`, and checks the tag-length table against both prose exclusion lists and the spelled-out count. Verified against nine mutations including both directions of each finding; an unwired siblings row or a renamed bit-map heading is a **failure, not a skip** — the ninth instance of "green because it wasn't looking" is what this file exists to prevent |
| F-74 The density claim rested on one 2017 ISA | Step 6 | **resolved — five generations now, and the claim holds.** gfx900 (GCN5, 2017) was the only real-ISA reference, which left the headline open to the reading that CCV beats an obsolete encoding. `tools/bench.py` now sweeps gfx900, gfx1030 (RDNA2), gfx1100 (RDNA3), gfx1200 (RDNA4, 2024) and gfx942 (CDNA3/MI300). **AMD's density is flat across eight years and two encoding families — 40.1 to 43.1 bits/instruction pooled, no trend — and CCV's 27.4 is 0.63×–0.68× of every one.** The ratio against RDNA4 is 0.65, the same as against Vega. Two findings the single column hid: RDNA3 is *less* dense than GCN5 on these kernels and needs more instructions for the same work (71 vs 54 on `reduce`), `s_delay_alu` being explicit scheduling in the instruction stream; and CDNA3 beats CCV on instruction count for `saxpy` and `dot` while still costing 1.5× the bits |
| F-75 Tail padding counted as code inflates any gfx10+/CDNA comparison | Step 6 | **resolved, and it nearly published a false headline.** gfx10+ pads a kernel's tail with `s_code_end` and CDNA3 with `s_nop` to fill the instruction prefetch buffer. Counted as code, gfx1100's `vadd` reads **146 instructions and 640 bytes rather than 32 and 184** — CCV would have appeared 5× denser than RDNA3 on padding alone. Two plausible fixes are also wrong and were both tried: filtering those mnemonics anywhere removes CDNA's real hazard-slot `s_nop`s, and cutting at the last `s_endpgm` removes real code, because an early-exit `s_endpgm` is followed by the block restoring `exec` — on `dot` it silently deleted the whole reduction loop, 17 instructions. `bench.py` drops only a **trailing run** of padding, and the check that it is right is that it reproduces the published gfx900 column exactly on all five kernels |
| F-76 benchmarks.md prose had drifted from its own tables | Step 6 | **resolved — six stale figures, all in the direction of flattering the machine's past self.** The control table's `transpose` cell read 84 against a measured 87; "grew to 84 instructions and 316 bytes" against 87 and 320; the O-33 A/B table was stale in **every cell** (2304/2304/100% and 2592/1493/58% against 2176/2016/93% and 2528/1429/57%), having been hand-copied once and then left behind by two changes to the divide sequence (O-31, O-35) and one correction to the counter itself (F-60); "811 fewer lanes, a 35% cut, nine added instructions" against a measured 587, 29% and 11; "76 instructions issued" against 79; "1493 → 1428 lane-activations" against 1429. The masking A/B is now generated by `bench.py` rather than transcribed |
| F-77 A prose number restating a table is unowned | Step 6 | **resolved — `check-bench-doc.py` now owns them, closing the third of the external reviewer's three recommendations.** The checker previously held down three fenced tables and explicitly declined prose: *"Prose is not checked — a checker cannot."* F-76 shows what that costs. It now also compares the two markdown tables by **value** (text comparison is impossible — the document renders markdown, the tool fixed-width) and regex-matches three inline prose claims against the tool's JSON. Verified by restoring each original defect: all four fail, a clean tree passes. A reworded claim fails rather than silently unhooking, so the checker cannot go green by ceasing to look |
| F-78 No benchmark exercises v1.6's own headline feature | Step 6 | **resolved — `vadd16` is in the benchmark, and the result is not flattering.** `vadd` at half the element width costs CCV **18 issued instructions against 16, and 62 bytes against 56**, and buys *nothing* in issue count: at one element per thread a 16-bit element occupies a 32-bit lane exactly as a float does. What it buys is half the memory traffic and two-byte stores, which is what F-67 was. The comparison point is that **gfx900 gets narrow types for free** — its `vadd16` is 29 instructions and 152 bytes, identical to its `vadd`, and genuinely 16-bit (`global_load_ushort`, `v_add_u16_e32`, `global_store_short`) — because GCN encodes 16-bit operations in the same formats as 32-bit ones. CCV is the machine that *pays* for narrow types on this shape |
| F-79 No benchmark kernel packs two narrow elements per lane | Step 6 | **open, and it is where the narrow-width model would actually pay.** `vadd16` is one element per thread, so the packed form — two adjacent 16-bit elements in one 32-bit lane, which is what O-6's element model exists for — is never exercised. A kernel written that way would halve the issue count for the same element count, which is the only way narrow widths reduce instructions rather than just memory traffic. Until such a kernel exists, the benchmark shows the cost of the feature and none of the benefit |
| F-80 The width-affinity allocator objective, now with a number | Step 6 | **open, and measured for the first time.** `vadd16` emits three `chwidth` transitions and one of them is a pure **restore**: the allocator narrows `r3`, uses it, then reuses `r3` for a 32-bit load and must widen it back, because §3 takes transfer size from the destination register's width. Eleven registers were free. This is the width-affinity objective F-3 left open and `backend-context.md` §4 frames against O-8's destructive-form preference; the cost of not having it is **one instruction in eighteen, 5.6%**, on the only kernel that exercises narrow widths |
| F-81 Instruction counts were compared across different warp widths | Step 6 | **resolved — and the correction reverses a published claim.** The control table compared CCV's per-warp instruction counts against gfx900's with no normalization, while the document has stated since 1.4 that SIMT efficiency is *not* comparable for exactly that reason: a CCV warp is 32 lanes and a gfx900 wavefront is 64. Normalized to work done — `1024 × instructions ÷ warp width`, with the width read from the generated kernel descriptor rather than assumed — **CCV issues more instructions per element than every wave64 machine**, 512 against gfx900's 464 and CDNA3's 368 on `vadd`, and beats every wave32 part by close to 2×. The encoding still wins the column it was designed for: on the same kernel CCV fetches **26% fewer instruction bytes than gfx900 while issuing 10% more instructions**. "Lower on five of six" was overstated; the honest claim is that CCV beats wave32 prior art outright and trades fetch bandwidth against issue slots versus wave64 |
| F-82 Nothing measured how much of the stream is narrow | Step 6 | **resolved — the simulator counts element work by width, and the fraction is the number O-40 lives on.** `vadd16` reaches **28.6% narrow element work** (4 of 14), and at O-40's 2× retire rate that is `14 + 4/2 =` **16.0 cycles against `vadd`'s 16.0 — exactly break-even**. The 2× recovers the two instructions the narrow form costs and nothing more. Width is taken from the GPR operands themselves rather than an opcode table, because element width is per-register state (invariant 1) and a table would be a second opinion about something the machine already knows; where operands disagree the narrowest wins. `chwidth` is excluded from element work — counting the transition instruction as narrow would credit the model with the very instruction it exists to pay for |
| F-83 The retire-rate benefit is a memory-pipe property, not an ALU one | Step 6 | **open, and it inverts where attention would naturally go.** Of `vadd16`'s four narrow instructions, **one is ALU and three are loads and stores**. Modelled: both pipes dual-issuing gives 16.0 cycles (break-even); memory only, 16.5; **ALU only, 17.5 — slower than the 32-bit kernel**; neither, 18.0. A split allocation that widens the ALU and leaves the memory path alone makes the narrow form a regression. Recorded in §1a.4 as part of O-40's obligation, and it is the half of it a hardware implementer is most likely to skip |
| F-84 O-40 has no margin at the fraction today's codegen produces | Step 6 | **open.** At 1.5× rather than 2×, `vadd16` is 16.7 cycles and loses to its own 32-bit equivalent; break-even sits at exactly the 4 narrow instructions the kernel has, and `N=5` would win at 15.5. Two compiler changes move it: **F-80** — removing the one avoidable `chwidth` restore gives 17 issued, 4 narrow, **15.0 cycles, 1.067×**, so the width-affinity allocator objective is what converts break-even into a gain rather than being a tidiness item — and **F-79**, packing two elements per lane, which raises the fraction directly. Until one of them lands, the ISA is asking hardware for 2× and spending all of it on parity |
| F-85 `ccv-lower-kernel-args` segfaults on a kernel that opens by reading `blockDim` | Step 6 | **resolved — a latent crash that survived on instruction ordering alone.** The pass anchors an `IRBuilder` on the entry block's first insertion point, then erases the dimension-intrinsic calls it replaces. When the first instruction in the entry block *is* one of those calls, erasing it leaves the builder holding a dangling iterator and the next insert writes through it. `vadd` opens with `ctaid`, which is not erased; `vadd16_loop` opens with `ntid`, which is — and clang emits the reads in source order, so `unsigned stride = NTID_X;` was enough to crash the compiler. Every benchmark kernel happened to be the safe shape. The builder is now re-anchored on the last instruction the pass itself inserted, which is always positioned after `launch.base` so re-anchoring cannot move an insert above the pointer the loads derive from |
| F-86 Window rematerialization cloned the invariant load into every loop iteration | Step 6 | **resolved — `-ccv-window-remat-stop-at-gpr`, on by default.** `CCVWindowRemat` exists for correctness: invariant 11 plus SelectionDAG's per-block nature means a cross-block i64 window address becomes a virtual register with no class and the type legalizer aborts. But it cloned the *whole* operand cone, including the i32 `.const` load that produces `rbase` — and only the **i64 arithmetic** cannot cross a block. In a straight-line kernel the difference is invisible; in a loop it re-executed six loop-invariant loads every iteration. The chain now stops at GPR-width values, which stay put and reach the clone as ordinary cross-block register values. Measured: `vadd_loop`'s body **10 → 7** instructions per element, `vadd16_loop`'s **14 → 9**, no spills either way; `dot` and `reduce` each one instruction smaller. **The tradeoff is real and is register pressure**: the GEMM sweep gains 5–6 spills at 1×1 through 2×2, is unchanged at 2×4 — the practical operating point §1 and §3 both name — and is 14 instructions *better* at 4×4. On by default on that balance; the flag turns it off |
| F-88 The benchmark had no looping elementwise kernel | Step 6 | **resolved — `vadd_loop` and `vadd16_loop`.** Five of the six kernels were straight-line in their hot path, so every measurement was of a *prologue*: `vadd16`'s width transitions and argument loads were paid once per element because each thread handled exactly one. That made the benchmark structurally unable to answer whether the overhead amortizes, and it hid both F-86 and F-87 — and F-85, which was a crash the moment a kernel with a loop was compiled at all. The pair fits `issues = 12 + iterations × body` exactly, so the prologue separates cleanly from the steady state, which is what makes the two findings above measurable rather than arguable |
| F-87 Width transitions are loop-carried and never amortize | Step 6 | **resolved — `CCVInsertChwidth` now places a transition on the incoming EDGES when predecessors disagree, and this is the largest measured win in the benchmark.** Step 1 marked a loop header's entry width Unknown (the preheader supplied 32, the back-edge 16) and step 2 resolved it *inside* the block, so a loop-invariant width change re-executed every iteration. Placement is guarded by three conditions, each necessary: **no back-edge may need the insert**, or the instruction has only moved from the top of the loop to the bottom — reachability is computed in the pass rather than via MachineLoopInfo, to avoid an analysis dependency pre-emit; **the register must be dead on the predecessor's other edges**, because a terminator's `chwidth` executes whichever way the branch goes and on a critical edge would re-mode a register another successor is still reading (splitting the edge would also work and costs a branch; this takes the cheap half and declines the rest); and the insert goes **before the first terminator**. The dataflow is re-run after each placement, and now reads existing `chwidth` instructions so it cannot re-derive a state the code contradicts. Measured: `vadd16_loop` **84.0 → 70.0** issues per thread, steady-state body **9 → 7** — *identical to the fp32 kernel* — with the whole width cost moved into the prologue (`issues = 14 + 7n` against fp32's `12 + 7n`). Narrow fraction **69%**, and at O-40's 2× that is **50.0 cycles against fp32's 68.0: 1.36×**. `-ccv-chwidth-cross-block=false` restores the old behaviour |
| F-89 A `chwidth` was emitted for a register nobody reads | Step 6 | **resolved — skip dead definitions.** O-32's unpredicated compare writes a materialization destination `rd` beside its predicate, and on a loop's back-edge test that destination is dead. The allocator gave it a register the loop body had narrowed, so the pass emitted a widening `chwidth` to accommodate a value no instruction reads — **once per iteration**, 1 instruction in 9 of `vadd16_loop`'s steady-state body. A dead def needs no width: nothing can observe which slice of the row it lands in, and `chwidth` is not free even for a dead value because §3 has it drain in-flight dependents. Step 1's dataflow skips dead defs too, or it would describe a width the emitted code never establishes. This also exposed a simulator gap: with `rd` left narrow, the compare tripped the width-aware refusal on an operand its semantics never touch, so the compares were made **genuinely** width-aware — operands read at their register's element width, signed relations sign-extending and unsigned zero-extending, narrow FP refused since §4 has no narrow FP — and only then added to the whitelist. Putting the whitelist entry first is how `ld.shared` came to vouch for itself while calling `read32` (F-67) |
| F-90 No test could see a width mode failing to survive a back edge | Step 6 | **resolved — `tools/check-narrow-loop.sh`, in the gate.** F-87's saving is precisely that the loop never re-establishes the width, which makes the mode's persistence across the back edge load-bearing for correctness in a way no straight-line test can reach: `check-narrow.sh` runs one iteration, so a mode that decayed after the first would still pass it. The new test runs **256 elements over eight iterations per thread and checks every element**, reporting which iterations failed — all-but-the-first is the signature of a mode that did not survive the edge. It also asserts the aligned loop body contains **no `chwidth` at all**, since a regression there is invisible in the results, and it verified itself against `-ccv-chwidth-cross-block=false`, which fails it. The unaligned build is run for correctness too and its remaining 3 transitions are **reported, not asserted**: there the allocator gives one register both the in-window address arithmetic and the narrow data, so the width genuinely changes inside the body and no edge placement can lift it out (F-80) |
