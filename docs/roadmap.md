# Bring-up Roadmap and Compiler-Side ISA Findings

**Status:** Steps 0–5 complete, Step 6 substantially done. ISA at v1.6 with
O-41/O-42/O-43 decided on top. *(This line read "Phase 0, no code yet" for far
longer than it was true — there is a full backend, a simulator, an eight-kernel
benchmark and a verification gate.)*
**Companions:** `isa-v1.6-operation-map-and-encoding.md` (encoding ground truth),
`backend-context.md` (scope and rationale ground truth),
`compiler-findings-v1.6.md` (the architecture-track report).

This file is the working plan. It tracks two things: the order work is being
done in, and the ISA findings that compiler-side reasoning has surfaced. The
second list is the actual product of this effort — per `backend-context.md` §1,
the compiler's near-term job is to generate signal for ISA decisions.

---

## Part 0 — Where this stands, and what to pick up next

**Everything is committed and pushed on `claude/ptx-isa-compiler-setup-eluxxk`,
and `tools/verify.sh` is green.** It is also green on a fresh container with no
`vendor/` directory — the NVIDIA tools are optional and the SASS comparison skips
with an instruction rather than failing.

### Reproducing the environment

`vendor/` is gitignored and does not survive a new container. One command
restores it:

```
    ./tools/fetch-ptxas.sh        # ptxas + nvdisasm, from NVIDIA's pip wheels
```

Neither needs a GPU. Without them everything still builds and passes; only the
SASS column is absent, and `check-bench-doc.py` says so.

### Next steps, in the order they are worth doing

1. **O-45 — launch-slot-relative addressing.** Adopted and unimplemented: §3 has the
   encoding, nothing emits it. This is the one with measured demand behind it
   (F-129's fused-kernel spill) and it is the piece the uniform-file deferral
   rests on — F-106's revival condition 2 is that this is adopted and **measured
   to leave** significant uniform pressure behind, which cannot be tested until
   it exists. Needs a Format D variant in the machine description, a selection
   path that recognises a launch-block load feeding an address, and the
   simulator's AGU reading the slot.

2. **F-137 remainder — selection for O-44's FP dot products.** The encodings and
   semantics are in; nothing can form one, because the backend has no bfloat,
   half or FP8 type. The blocker is a type, not a pattern: `dp2.bf16` needs
   `bfloat` legal enough to survive to ISel, at which point `combineDP4`'s shape
   generalises. Until then O-44's arithmetic credit is unearned in exactly the
   way `dp4.acc`'s was before F-121.

3. **F-119 — a predicate broadcast, so O-33 can gate a compare.** Lane-0 masking
   skips every compare, because the result is a predicate and the broadcast is a
   `shfl` on a GPR. `ballot`/`unballot` are the pair to build it from, and both
   are unlowered (F-118), so the two share a fix. This also gives the ten Format
   C′ predicated-immediate forms their first producer.

4. **F-92 — width affinity under register pressure.** The claim that opposite
   allocation orders degrade gracefully when the two widths collide is reasoning,
   not measurement: no kernel fills the file with narrow values. Needs a kernel,
   not a code change.
5. **F-84 / O-40 — the retire-rate margin.** At 1.5× rather than 2×, the
   straight-line 16-bit kernel loses to its own 32-bit equivalent. There is no
   further *compiler* lever on the narrow fraction (a lane holds one element at
   every width, so the element-work count is fixed by the element count); what is
   left is the addressing overhead beside it.
6. **O-42 — revisit the three-source immediate** when `sgemm` at larger tiles has
   been examined for strided addressing. Deferred on cost, not legality.

### Not worth picking up

- **F-79 is withdrawn** — packing two elements per lane contradicts invariant 1
  and O-13. The row explains why it was tempting, so it is not re-proposed.
- **O-43 is rejected** — the zero register. Same reason: the row preserves the
  evidence that dissolved it.

### Standing hazards, learned the hard way

- **Three vendors pad their kernel tails** — `s_code_end` (gfx10+), `s_nop`
  (CDNA3), NOPs to 128 bytes (NVIDIA) — and in every case counting the padding
  flatters CCV. Drop only a *trailing* run; a NOP inside the body is real.
- **A green check that was green because it was not looking** has now happened
  about a dozen times. Each instance became a gate check; the gate is the
  project's real asset.
- **Dated reports are not re-measured.** `compiler-findings-v1.4/v1.5.md` say
  what was believed when written. `benchmarks.md` is the live measurement.

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

**Outcome — the pass is built, and the plan above held up better than it had to.**
`CCVInsertChwidth.cpp` is post-RA with a per-physical-register width dataflow,
as predicted, and `RISCVInsertVSETVLI` was the right prior art. Three things the
plan did not anticipate:

- **Placement inside the block is not enough.** Transitions also have to go on
  CFG **edges** where predecessors disagree, or a loop-invariant width change
  sits in the loop body and re-executes forever (F-87). The plan's "hoist to a
  point where the affected registers are cold" is an intra-block notion; the
  coldest point is often in another block entirely.
- **A dead definition needs no width.** The single largest per-iteration cost
  was a `chwidth` accommodating Format C's materialization destination on a
  loop's back-edge test — a register nothing reads (F-89).
- **The width-affinity objective is the allocation ORDER**, not a new heuristic.
  The plan called for "softly partitioning the register file by width", which is
  exactly right, and the cheapest expression of it is giving `GPR16` the
  opposite allocation order to `GPR` (F-80). The register class is the only
  width signal the allocator has, so there was nowhere else to put it.

**The predicted conflict with O-8 did not appear — on these kernels.** Measured
both ways on `vadd16` and `vadd16_loop`: total bytes identical (496 and 576),
and the destructive-form hit rate unchanged (0, and 1 at 100%). The
one-instruction difference is the `chwidth.multi` merge, which is byte-neutral
by construction — two 16-bit transitions against one 32-bit one. **This is weak
evidence and should not be read as more:** both kernels have almost no
compression opportunity to lose, so a kernel with real `rd == rs0` pressure
could still show the conflict the plan expects. The 32-GPR argument is likewise
untouched — nothing here fills the file with narrow values (F-92).

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
| F-79 ~~No benchmark kernel packs two narrow elements per lane~~ | Step 6 | **withdrawn — it contradicted a stated invariant, and should never have been opened.** §1 is explicit: *"No register has sub-lane structure. A register's elements are one per lane, always"*, and §9 names the failure mode by name — *"Design pressure toward packing as a property of a **register** is the warning sign, not packing inside an opcode"* — which is precisely what this finding was. O-13 had already rejected the register-level packing model. The arithmetic that made it tempting is real and is why it needs naming rather than deleting: halving the lane count would halve the issue count directly, so a benchmark showing the narrow model "finally paying" was available by breaking the invariant. **The correct statement is the opposite one.** A lane holds one element at every width, so a narrow kernel issues exactly as many element-work instructions as its 32-bit twin, by construction; narrow width never reduces issue count for a given element count and was never going to. What it buys is half the memory traffic and O-40's retire rate, and the only lever on the narrow *fraction* is removing work that is not element work — F-80 and F-87, both landed. `packi`/`unpacki` and `dp4`/`dp8` address positions inside a lane from an opcode or immediate, for the duration of one instruction; that is the line §1 draws and they stay on the legal side of it |
| F-81 Instruction counts were compared across different warp widths | Step 6 | **resolved — and the correction reverses a published claim.** The control table compared CCV's per-warp instruction counts against gfx900's with no normalization, while the document has stated since 1.4 that SIMT efficiency is *not* comparable for exactly that reason: a CCV warp is 32 lanes and a gfx900 wavefront is 64. Normalized to work done — `1024 × instructions ÷ warp width`, with the width read from the generated kernel descriptor rather than assumed — **CCV issues more instructions per element than every wave64 machine**, 512 against gfx900's 464 and CDNA3's 368 on `vadd`, and beats every wave32 part by close to 2×. The encoding still wins the column it was designed for: on the same kernel CCV fetches **26% fewer instruction bytes than gfx900 while issuing 10% more instructions**. "Lower on five of six" was overstated; the honest claim is that CCV beats wave32 prior art outright and trades fetch bandwidth against issue slots versus wave64 |
| F-82 Nothing measured how much of the stream is narrow | Step 6 | **resolved — the simulator counts element work by width, and the fraction is the number O-40 lives on.** `vadd16` reaches **28.6% narrow element work** (4 of 14), and at O-40's 2× retire rate that is `14 + 4/2 =` **16.0 cycles against `vadd`'s 16.0 — exactly break-even**. The 2× recovers the two instructions the narrow form costs and nothing more. Width is taken from the GPR operands themselves rather than an opcode table, because element width is per-register state (invariant 1) and a table would be a second opinion about something the machine already knows; where operands disagree the narrowest wins. `chwidth` is excluded from element work — counting the transition instruction as narrow would credit the model with the very instruction it exists to pay for |
| F-83 The retire-rate benefit is a memory-pipe property, not an ALU one | Step 6 | **open, and it inverts where attention would naturally go.** Of `vadd16`'s four narrow instructions, **one is ALU and three are loads and stores**. Modelled: both pipes dual-issuing gives 16.0 cycles (break-even); memory only, 16.5; **ALU only, 17.5 — slower than the 32-bit kernel**; neither, 18.0. A split allocation that widens the ALU and leaves the memory path alone makes the narrow form a regression. Recorded in §1a.4 as part of O-40's obligation, and it is the half of it a hardware implementer is most likely to skip |
| F-84 O-40 has no margin at the fraction a straight-line kernel produces | Step 6 | **partly resolved; the margin is a kernel property and now has both ends measured.** At 1.5× rather than 2×, `vadd16` is 16.7 cycles and loses to its own 32-bit equivalent. **F-80 and F-87 both landed and moved it**: `vadd16` is now 17 issued with 4 narrow — 15.0 cycles, **1.067×**, above break-even for the first time — and `vadd16_loop`, where the per-thread prologue amortizes over eight elements, reaches 55.2% narrow and **1.283×**. What remains open is that the margin on a *short* kernel is still thin, and **there is no further compiler lever on the fraction itself**: a lane holds one element at every width, so the element-work count is fixed by the element count and only the overhead beside it can shrink. Raising it past what F-80 and F-87 give would mean packing two elements into a lane, which F-79 was withdrawn for contradicting. The remaining lever is the addressing overhead that makes up the rest of the stream |
| F-85 `ccv-lower-kernel-args` segfaults on a kernel that opens by reading `blockDim` | Step 6 | **resolved — a latent crash that survived on instruction ordering alone.** The pass anchors an `IRBuilder` on the entry block's first insertion point, then erases the dimension-intrinsic calls it replaces. When the first instruction in the entry block *is* one of those calls, erasing it leaves the builder holding a dangling iterator and the next insert writes through it. `vadd` opens with `ctaid`, which is not erased; `vadd16_loop` opens with `ntid`, which is — and clang emits the reads in source order, so `unsigned stride = NTID_X;` was enough to crash the compiler. Every benchmark kernel happened to be the safe shape. The builder is now re-anchored on the last instruction the pass itself inserted, which is always positioned after `launch.base` so re-anchoring cannot move an insert above the pointer the loads derive from |
| F-86 Window rematerialization cloned the invariant load into every loop iteration | Step 6 | **resolved — `-ccv-window-remat-stop-at-gpr`, on by default.** `CCVWindowRemat` exists for correctness: invariant 11 plus SelectionDAG's per-block nature means a cross-block i64 window address becomes a virtual register with no class and the type legalizer aborts. But it cloned the *whole* operand cone, including the i32 `.const` load that produces `rbase` — and only the **i64 arithmetic** cannot cross a block. In a straight-line kernel the difference is invisible; in a loop it re-executed six loop-invariant loads every iteration. The chain now stops at GPR-width values, which stay put and reach the clone as ordinary cross-block register values. Measured: `vadd_loop`'s body **10 → 7** instructions per element, `vadd16_loop`'s **14 → 9**, no spills either way; `dot` and `reduce` each one instruction smaller. **The tradeoff is real and is register pressure**: the GEMM sweep gains 5–6 spills at 1×1 through 2×2, is unchanged at 2×4 — the practical operating point §1 and §3 both name — and is 14 instructions *better* at 4×4. On by default on that balance; the flag turns it off |
| F-88 The benchmark had no looping elementwise kernel | Step 6 | **resolved — `vadd_loop` and `vadd16_loop`.** Five of the six kernels were straight-line in their hot path, so every measurement was of a *prologue*: `vadd16`'s width transitions and argument loads were paid once per element because each thread handled exactly one. That made the benchmark structurally unable to answer whether the overhead amortizes, and it hid both F-86 and F-87 — and F-85, which was a crash the moment a kernel with a loop was compiled at all. The pair fits `issues = 12 + iterations × body` exactly, so the prologue separates cleanly from the steady state, which is what makes the two findings above measurable rather than arguable |
| F-87 Width transitions are loop-carried and never amortize | Step 6 | **resolved — `CCVInsertChwidth` now places a transition on the incoming EDGES when predecessors disagree, and this is the largest measured win in the benchmark.** Step 1 marked a loop header's entry width Unknown (the preheader supplied 32, the back-edge 16) and step 2 resolved it *inside* the block, so a loop-invariant width change re-executed every iteration. Placement is guarded by three conditions, each necessary: **no back-edge may need the insert**, or the instruction has only moved from the top of the loop to the bottom — reachability is computed in the pass rather than via MachineLoopInfo, to avoid an analysis dependency pre-emit; **the register must be dead on the predecessor's other edges**, because a terminator's `chwidth` executes whichever way the branch goes and on a critical edge would re-mode a register another successor is still reading (splitting the edge would also work and costs a branch; this takes the cheap half and declines the rest); and the insert goes **before the first terminator**. The dataflow is re-run after each placement, and now reads existing `chwidth` instructions so it cannot re-derive a state the code contradicts. Measured: `vadd16_loop` **84.0 → 70.0** issues per thread, steady-state body **9 → 7** — *identical to the fp32 kernel* — with the whole width cost moved into the prologue (`issues = 14 + 7n` against fp32's `12 + 7n`). Narrow fraction **69%**, and at O-40's 2× that is **50.0 cycles against fp32's 68.0: 1.36×**. `-ccv-chwidth-cross-block=false` restores the old behaviour |
| F-89 A `chwidth` was emitted for a register nobody reads | Step 6 | **resolved — skip dead definitions.** O-32's unpredicated compare writes a materialization destination `rd` beside its predicate, and on a loop's back-edge test that destination is dead. The allocator gave it a register the loop body had narrowed, so the pass emitted a widening `chwidth` to accommodate a value no instruction reads — **once per iteration**, 1 instruction in 9 of `vadd16_loop`'s steady-state body. A dead def needs no width: nothing can observe which slice of the row it lands in, and `chwidth` is not free even for a dead value because §3 has it drain in-flight dependents. Step 1's dataflow skips dead defs too, or it would describe a width the emitted code never establishes. This also exposed a simulator gap: with `rd` left narrow, the compare tripped the width-aware refusal on an operand its semantics never touch, so the compares were made **genuinely** width-aware — operands read at their register's element width, signed relations sign-extending and unsigned zero-extending, narrow FP refused since §4 has no narrow FP — and only then added to the whitelist. Putting the whitelist entry first is how `ld.shared` came to vouch for itself while calling `read32` (F-67) |
| F-90 No test could see a width mode failing to survive a back edge | Step 6 | **resolved — `tools/check-narrow-loop.sh`, in the gate.** F-87's saving is precisely that the loop never re-establishes the width, which makes the mode's persistence across the back edge load-bearing for correctness in a way no straight-line test can reach: `check-narrow.sh` runs one iteration, so a mode that decayed after the first would still pass it. The new test runs **256 elements over eight iterations per thread and checks every element**, reporting which iterations failed — all-but-the-first is the signature of a mode that did not survive the edge. It also asserts the aligned loop body contains **no `chwidth` at all**, since a regression there is invisible in the results, and it verified itself against `-ccv-chwidth-cross-block=false`, which fails it. The unaligned build is run for correctness too and its remaining 3 transitions are **reported, not asserted**: there the allocator gives one register both the in-window address arithmetic and the narrow data, so the width genuinely changes inside the body and no edge placement can lift it out (F-80) |
| F-80 Width affinity in the register allocator | Step 6 | **resolved — GPR16 allocates descending where GPR allocates ascending, and it is the only lever available.** The allocator gave one register the in-window address arithmetic *and* the narrow data loaded through it, so a register went 32-bit, narrow, 32-bit every iteration. O-39 permits that sharing — `rdata` may share with `rbase`/`rindex` because the address read takes all 32 bits — and it trades a register for a width change, which in a loop body is a per-iteration instruction that **F-87's edge placement cannot lift out**, because the width genuinely changes inside the body. Element width is per-register state, so the allocator is the only pass that can prevent the handover, and **the register class is the only width information it has**: `chwidth` names physical registers, so width is otherwise a post-RA concept entirely. Same sixteen registers in both classes (the set must match or a cross-class COPY is not the no-op §1 says it is), opposite preference, so 32-bit values cluster from R0 up and 16-bit from R14 down and under low pressure never meet. Measured: the unaligned `vadd16_loop` body **3 transitions → 0, 15 instructions → 12**; `vadd16` **26 → 24** unaligned and **18 → 17** aligned; `vadd16_loop` **70 → 69** issues. At O-40's 2× that is `vadd16` **1.000× → 1.067×** and `vadd16_loop` **1.259× → 1.283×**. It also made O-6's merging fire on `vadd16` for the first time — the two narrow registers are now adjacent so their transitions collapse into one `chwidth.multi`, where F-69 measured 0 of 3 and concluded the kernel shape was wrong for it. The shape was right; the allocation was wrong |
| F-91 The narrow-fraction counter counted a compare as narrow work | Step 6 | **resolved, and it had inflated a published figure.** The O-40 counter took the narrowest of *all* an instruction's GPR operands. Format C's materialization destination `rd` is a GPR operand the compare never writes, so when the allocator gave a loop's back-edge test a `rd` in a narrowed register, a plainly 32-bit comparison counted as narrow element work **once per iteration**. `vadd16_loop` was published at 40 narrow, a **0.690** fraction and **1.360×**; corrected, the same code is 32 narrow, **0.552** and **1.259×**. The counter now skips that operand, which is the same reasoning as F-89 one level up: a register operand the semantics never touch says nothing about the width the instruction operates at. Both the fraction and the speedup were overstated, and `docs/benchmarks.md` now records the correction rather than quietly restating the number |
| F-92 The width-affinity pressure case is untested | Step 6 | **open.** F-80's descending order is argued to degrade gracefully — under pressure the two widths meet in the middle and share as before, and sharing beats spilling to keep them apart — but **no benchmark kernel exercises it**. `sgemm` is fp32 throughout, so GPR16 never appears in the tile sweep and its numbers are unchanged to the instruction; the loop kernels use three narrow registers against sixteen. A narrow kernel with enough live values to fill the file would decide whether the opposite orders cost spills when they collide, and none exists |
| F-93 Signed constant divisors got the full runtime-divisor expansion | Step 6 | **resolved, and it was most of `transpose`'s outlier status.** `CCVExpandDivision` opened with *"Constant divisors never reach here — instcombine turns those into a shift"*. True for unsigned, **false for signed**: instcombine reduces `udiv x, 16` to `lshr` and leaves `sdiv x, 16` alone, because rounding toward zero costs three extra instructions and is a CodeGen trade rather than a canonicalisation. `transpose` computes `n / T` with `T` a compile-time 16 and `n` an `int`, so its constant divisor took the **full Newton-iteration sequence**. The pass now skips constant divisors entirely and DAGCombiner's `BuildSDIV`/`BuildUDIV` strength-reduce them: a shift for a power of two, a magic-number multiply otherwise. **`transpose` 79 → 60 issued instructions.** It stayed hidden because `rcp.u32` of a constant **folds**, so the generic expansion of a constant divisor emits no reciprocal — every correction step was in the listing with nothing to say what it was for |
| F-94 The fused reciprocal seed was left as dead code | Step 6 | **resolved — `CCVFuseRcpSeed` collects its own chain.** The pass replaced the fp32 reciprocal chain with `rcp.u32` and left the chain for *"the generic dead-machine-instr elimination that follows"*. No such elimination removed it, so every division carried a dead `cvt.f32.u32` and `rcp.f32` — neither marked with side effects, so nothing was protecting them; they simply outlived the pass meant to collect them. The original caution was that a shared scale constant makes hand-unlinking unsafe, which is how `CCVWindowRemat` produced a use-after-free (F-47). That caution was right and the conclusion was wrong: the pass runs **pre-RA on SSA virtual registers**, so `MachineRegisterInfo::use_nodbg_empty` answers the sharing question exactly, and a shared constant keeps its remaining use and stays. Iterated to a fixpoint so erasing the multiply exposes its operands. **`transpose` 60 → 58** |
| F-95 No test divided by a compile-time constant | Step 6 | **resolved — `tools/check-divconst.sh`, in the gate.** Every division test divided by a *runtime* value, so the entire constant-divisor path — a different lowering with different failure modes — was numerically unverified, and F-93 changed which compiler component owns it. The test covers 32 dividends against 8 constant divisors: the cases that break naive strength reduction (negative dividends, where C rounds toward zero and an arithmetic shift rounds toward −∞; `INT_MIN`; negative divisors) across signed and unsigned, div and rem, powers of two and not. It also **bounds the instruction count**, because the answers are right either way and nothing else would show a regression to the generic path — 56 instructions strength-reduced against 91 through it. Checking for `rcp` was tried first and does **not** work: `rcp.u32` of a constant folds, so the generic path emits no reciprocal either |
| F-96 `transpose`'s outlier status was attributed to the wrong cause | Step 6 | **resolved, and the lesson outlives the fix.** Two revisions of `benchmarks.md` explained `transpose`'s cost as O-33's broadcasts plus AMD's scalar unit. The A/B always showed masking costing **6 instructions of 58**; the real causes were F-93 and F-94, worth **21 of the original 79**. `transpose` now issues **58 against GCN5's 64 — below it** — and is below on bytes (236 against 308) while remaining 2 above on static instruction count. A plausible cause that is genuinely present in the code will absorb an unexplained cost indefinitely if nobody measures the parts, and the instruction histogram that found this took one command |
| F-97 Lane-0 masking blocks dead-code elimination of what it predicates | Step 6 | **understood, and it is why F-94 existed at all.** The dead `cvt.f32.u32`/`rcp.f32` seed left by `CCVFuseRcpSeed` was removed by the generic DCE in every *unmasked* kernel and survived in every *masked* one — measured directly: `transpose` under the old passes carried **2 dead-seed instructions with masking on and 0 with it off**. `CCVMaskUniform` runs after `CCVFuseRcpSeed` in `addILPOpts`, and a predicated definition is not something the generic dead-machine-instruction elimination will remove. So an optimisation silently disabled a later cleanup, and the cost showed up attributed to the optimisation's own broadcasts. **The general shape is worth carrying: any pass that predicates instructions moves them out of reach of DCE**, so a pass that leaves dead code for "the DCE that follows" is relying on something masking can take away. F-94 fixed the instance by having the producer collect its own chain; the class is still live for anything else that predicates |
| F-98 Which kernels the division fixes actually helped | Step 6 | **measured, and the answer is narrow.** F-93 and F-94 changed **`transpose` (87 → 66 static, 79 → 58 issued, 320 → 236 bytes)** and **`sgemm` (639 → 637 at the 2×4 tile)** and *nothing else* — every other benchmark kernel is identical to the instruction, because none of them contains a division. F-93 reaches only kernels with a **constant** divisor: `transpose`'s `n / 16` and the new `divconst.cu` (91 → 56). F-94 reaches only **masked** kernels with a runtime integer division, per F-97 — `transpose` and `sgemm`, two instructions each. The `.ll` division tests gained nothing because they are unmasked, so their dead seed was already being collected. Recorded because "we fixed a compiler bug" invites the assumption that everything got faster, and the honest scope here is two kernels |
| F-99 SASS was never measured, and it did not need a CUDA toolkit | Step 6 | **resolved — `tools/fetch-ptxas.sh`, and the blocker was an assumption.** Every revision of `benchmarks.md` said SASS "needs `ptxas`, which needs the CUDA toolkit, which is not installed", and named it the largest gap in the comparison. `ptxas` is a **host compiler that needs no GPU**, NVIDIA publishes it as a pip wheel, and the install is one command. No disassembler is needed and none is on PyPI: the cubin's `.text.<kernel>` section **is** the SASS. **Pooled over eight kernels: CCV 295 instructions and 1006 bytes at 27.3 bits each; SASS 224 instructions and 3584 bytes at 128.0.** CCV needs **1.32× the instructions and 0.28× the bytes** — the same kernels are 3.6× larger as SASS — and **SASS uses the fewest instructions of any machine measured**, fewer than CCV and fewer than all five AMD generations. The two fail in opposite directions, which is the cleanest statement of §6's trade: NVIDIA buys scheduling determinism with 64 bits of control per instruction and this design declines to spend them |
| F-100 §6's 128-bits-per-instruction figure was an unverified citation | Step 6 | **resolved — it measures 128.0 exactly.** Carried from the design discussion through four spec revisions with no way to check it, and labelled as a citation each time. Every benchmark kernel measures **128.0 bits per instruction exactly**, and it holds **Volta through Blackwell** — nine years and five architectures with no change, a stronger flatness than the AMD sweep found. §6 now states it as measured. Pre-Volta is excluded deliberately: sm_60 and earlier use a 64-bit encoding with separate control words, which the 16-byte walk would silently miscount, so `sass()` refuses anything below sm_70 rather than reporting a number it cannot justify |
| F-101 NVIDIA pads kernels with NOPs, and it fooled the first measurement | Step 6 | **resolved, and it is the third vendor in a row to do this.** `ptxas` pads a kernel's tail with NOPs to a 128-byte boundary. The giveaway was that **all eight kernels' `.text` sections were exact multiples of 128** — eight kernels do not land on that boundary by chance — and counted as code it reads `vadd` as 24 instructions rather than 17, and 384 bytes rather than 272. Same rule as the AMD fix (F-75): drop only the **trailing run**, because a NOP inside the body is a real scheduling slot. Worth recording as a pattern rather than three separate bugs: gfx10+ pads with `s_code_end`, CDNA3 with `s_nop`, NVIDIA with NOPs, and in every case the naive measurement flatters CCV |
| F-102 CCV/SASS instruction count was reported against the wrong CCV build | Step 6 | **corrected.** The prior-art table uses CCV's **unaligned** column, so the SASS comparison was published as **1.32×** the instructions. O-23's alignment attribute is CCV's intended ABI, and NVIDIA passes 64-bit pointers directly because invariant 11 does not apply to them, so the build-for-build figure is **CCV aligned 238 against SASS 224 — 1.06×, parity** — and CCV is *ahead* on `vadd` (16 v 17) and `vadd_loop` (19 v 20). The gap is concentrated in `dot`, `reduce` and `transpose` at **five instructions each**, which is what F-103 explains. Both columns are now in the document; the unaligned one is the pessimistic bound, not the headline |
| F-103 Where SASS's instruction-count advantage actually comes from | Step 6 | **answered by disassembly, and it is entirely encoding rather than architecture.** `nvdisasm` (unsuffixed `nvidia-cuda-nvdisasm` on PyPI) reads the cubin. **They have no integer divide**: `transpose`'s runtime division is `I2F.U32.RP` → `MUFU.RCP` → `F2I` → Newton via two `IMAD.HI.U32` → two `ISETP`/`IADD3` corrections — **O-31/O-35's algorithm step for step**, so nothing was skipped. Predicated control flow is not it either (`@P0 EXIT`, `@!P2 LOP3` — all available in Format A′). What is real: **9 of the 19 `movi` in the whole benchmark exist only because an immediate has nowhere to go** — 5 want a **zero register** (`RZ` as any operand), 3 want **reg-immediate at three addresses**, 1 wants a **three-source form with an immediate** (`IMAD R11, R5, 0x44, R9`). On `transpose` that is 5, the entire 58-vs-53 gap |
| F-104 Format B has free opcode points and the compressed format has the immediates | Step 6 | **resolved — O-41 adopted by ISA review and implemented.** Nine Format B instructions defined by the projection rule (`subi` 1, `muli` 2, `andi` 7, `ori` 8, `xori` 9, `andni` 10, `shli` 11, `shri` 12, `srai` 13), with selection patterns and simulator semantics. The semantics **map onto §4's** rather than reimplementing them — a second copy of `shl` would be a place for the two to disagree. Measured together with F-108's `mul.lo`: **`transpose` 66 → 62 static, 58 → 54 issued, 236 → 220 bytes**, and CCV aligned against SASS **1.062× → 1.045×**. One bug caught by the round-trip check and worth recording: the B and B′ tiers take **different immediate widths** — B has 13 contiguous bits at `[31:19]`, B′ splits its field around the predicate qualifier and keeps 10 — and the multiclass initially passed `simm13` to both, silently encoding a 13-bit constant into a 10-bit field on all six affected forms |
| F-108 Three instructions available with no ISA change at all | Step 6 | **partly resolved.** (1) **`mul.lo` at §4 point 2 is defined** — the ISA had always allocated a three-address multiply while the backend had only the compressed two-address `C_MUL_LO` and the three-source `MADLO`, so `Pat<(mul $a, $b), (MADLO $a, $b, (MOVI 0))>` materialised a zero for an addend the operation does not have. Now `Pat<(mul $a, $b), (MUL_LO $a, $b, $b)>`. (2) and (3), the immediate-compare and compressed-form selection gaps, are **closed by F-111's audit**: `CCVISelDAGToDAG.cpp` now selects Format C″'s immediate form for the ten condition codes it can reach (the gt/ge points cannot be — F-115), and `CCVCompress` gained `C_SUBI`/`C_ANDI`/`C_ORI`/`C_XORI`, `C_MUL_LO` and the zero-displacement memory pair `C_LD_GLOBAL`/`C_ST_GLOBAL` |
| F-107 The zero-register ask did not survive checking | Step 6 | **withdrawn, and the withdrawal is the finding.** F-103 reported 5 `movi rX, 0` that a hardwired zero register would remove. Checking what each feeds: **two** are `setp.eq` against zero and **Format C′ already has the immediate compare** (`SETP_EQ_I` is defined and generated — a selection gap); **two** are loop accumulators that need a writable register initialised to zero, which `mov rd, RZ` would cost the same instruction to produce; **one** is `mad.lo rd, rs0, rs1, #0`, which is a multiply, and **§4 point 2 already specifies `mul.lo`** — the backend simply never defined it. None is an argument for spending a GPR, and the cost would be real: R15 is reserved for the frame pointer (O-30), so a hardwired zero leaves 14. Recorded so the next person who notices the pattern finds the analysis instead of repeating it |
| F-105 CCV's folded addressing mode beats SASS, and it is why the simple kernels win | Step 6 | **noted, no action.** `ld.global r2, [r2, r1, 1, 0]` computes `base + index × scale` **and** loads in one instruction. Every memory access in the SASS listings is two — `IMAD.WIDE.U32` then `LDG.E` — because a 64-bit address has to be materialized in a register pair first, which is exactly what invariant 11 exists to avoid. This is the mechanism behind CCV being ahead of SASS on `vadd` and `vadd_loop`, and it is worth stating in the positive: the windowed address model is not only a density choice, it removes an instruction per memory access |
| F-106 NVIDIA ships the warp-uniform register file this project keeps arguing about | Step 6 | **OPEN — escalated above F-104 by ISA review, and it is the most consequential finding of the SASS work.** The SASS carries a uniform register file: `S2UR UR4, SR_CTAID.X` puts the CTA index in one register for the whole warp rather than 32 copies, `ULDC` loads constants into it, and ordinary vector instructions take `UR` operands beside vector ones (`IMAD R9, R9, UR4, R0`). Separate namespace, separate load path, direct operand access — which is what O-25 argued from register-file size and F-52 from redundant execution, **shipping in the compatibility target**. The reframing is the uncomfortable part: **O-33's lane-0 masking is a software approximation of it**, and `transpose` spends three `shfl.idx` broadcasts recovering what a uniform register supplies free. ISA review notes this is the escape hatch its GPR-count decision named — a small warp-uniform file reusing the existing 4-bit field under a different namespace, with `rbase`'s existing warp-uniform requirement for `st.pred` as precedent — and that the argument now has evidence. O-25 and F-12 are **settled** (16 GPRs, final), which is what makes this live
rather than a reopening: `gpr-count-decision.md` names a warp-uniform file as
the escape hatch if the GEMM case comes back bad, and is explicit that the
answer is **not** more GPRs. Written up in `proposals/warp-uniform.md` §0 |
| F-109 ISA review of `immediate-operands.md` — outcomes | Step 6 | **decided.** **Case 1 adopted and upgraded**: recorded as **O-41**, a normativity fix of the O-28 class rather than an optimisation — Format B's 32 points were *described and never enumerated*, which is the third instance of a range given as prose that two implementations could order differently. The projection rule is adopted with a required amendment the proposal missed: §4 holds **ternary** operations too (`mad.lo` 5, `mad.hi` 6, `prmt` 25), so the rule is binary-projects / unary-or-ternary-does-not. `sel` at 19 was confirmed **binary in register operands** — the condition comes from the predicate qualifier — so it projects, but only into B′/B″, since plain B has no qualifier field. Review also corrected the free-point arithmetic: the projection couples the two maps, so **13 points are genuinely free, not 28**, and §4 growth claims more. **Case 2 deferred (O-42), case 3 rejected (O-43)** |
| F-110 The invariant-8 objection to case 2 was wrong | Step 6 | **corrected by ISA review, and the correction is kept visible.** The proposal rejected "shrink Format B's immediate and add `rs1` at `[22:19]`" because an opcode-dependent immediate position is "exactly what invariant 8 forbids". It is not: invariant 8 governs **register** fields and says so, and immediates are explicitly not on the rename path. **Format D already varies its immediate position by opcode within one tag** — base+offset at `[31:19]`, base+index at `[31:24]`, selected by `opcode[2]`. So the option is legal and a 9-bit immediate at `[31:23]` would cover the motivating case. It is deferred on **cost** — one instruction does not justify a fourth Format B sub-layout — and O-42 records that reason instead, because a wrong reason in the log forecloses an option later on false grounds |
| F-111 Defined-but-unselected encodings were a pattern, not three incidents | Step 6 | **closed, and it was worse than three.** `tools/check-unselected.py` enumerates every instruction in the `CCV` namespace and demands a production path that is evidence rather than assertion: a `TARGET_VAL(CCV::x)` slot in the generated matcher table, an EMIT site in a named backend source file, or an entry in a reason-annotated declaration list. Of 267 instructions, **47 could not be produced at all**. The audit found one correctness bug (F-125), nine categories of gap, and 3 instructions plus 32 bytes of code size pooled over the eight kernels once the reachable ones were wired up. Two things it got right by being made to look twice: an emit site is only a production path if something produces its TRIGGER, so reachability is a fixpoint — the first version passed the whole dead `PSEUDO_SETP_*` path as healthy, which is the failure the check exists to catch; and a mapping-table entry whose source is unreachable is reported as dead code, which is how the float asymmetry in F-117 surfaced. `tools/check-unselected-mutation.sh` removes each of the three originally-found production paths and requires the failure |
| F-112 The GPR-count decision's four backend directives, audited | Step 6 | **three done, one not.** `gpr-count-decision.md` (16 GPRs settled, supersedes the "provisional" marking in v1.4 §1/§11) gives four instructions to backend work. **(1) One encoding path** — done: `GPRC` and R16–R31 are gone from the machine description, and the allocator's objectives are the two it names, O-8's destructive-form preference and width affinity, which F-80 implemented and measured against each other. **(3) Report aligned and unaligned separately** — done: both are columns in `benchmarks.md` §2, and F-102 showed why it matters, since the SASS comparison reads 1.30× on one and 1.05× on the other. **(4) Add warp-invariance analysis now** — done: `-ccv-uniformity-stats`, which is what produced F-52, F-56, F-57 and F-58. **(2) Instrument spill by cause is NOT done** — see F-113, and it is the measurement of the one live risk |
| F-113 GEMM spill, separated by cause | Step 6 | **closed — measured, and it contradicts the inference it replaces.** `llvm/CCV/CCVSpillStats.cpp` runs straight after register allocation, while every spill still names its frame index, and classifies each slot by what the spilled value IS: **pointer/index** when it is used as a base or index operand (unambiguous — invariant 11 says no register holds an address, so it is a window base or an element index), **accumulator** when it is the accumulating operand of a multiply-add or dot product (Format J's tied `rd_in`, or the third source of the three-address forms), **staged operand** for a value out of shared memory that feeds arithmetic as a multiplicand. Classification is by USE where a use exists, because a use names the role exactly; address wins over accumulator, since a value used as a base is an address whatever produced it. A slot neither a use nor a defining opcode establishes is left **unclassified** rather than assigned to whichever column looks likelier, and the residual is printed. `sweep-tiles.sh` now sweeps FP32 and INT8 kernels of identical shape. **The result: through 2×4 — every tile that fits 16 GPRs — spill is overwhelmingly addressing.** FP32 accumulator spill is 0, 0, 4, 8 against pointer/index 22, 42, 66, 110, and only at 4×4 does it reach 148 against 146. The prose's inference ("spill that scales with TM×TN is accumulator spill") pointed the right way and was wrong about magnitude at every tile that fits: the risk §1 named is a **cliff one tile beyond the practical ceiling**, not a slope through it |
| F-114 The `por`-rematerialization guidance is superseded | Step 6 | **closed by O-32, and recorded so it is not implemented.** `gpr-count-decision.md` §"Related allocator guidance" asks the allocator to rematerialize `por pd, !ps, ps` at each use rather than hoisting it, on the grounds that O-24 requires an all-true predicate before *every* semantically-unpredicated compare — making the effective predicate file 3 entries, not 4, in compare-heavy code. **O-32 removed the requirement entirely** by adding Format C″, the unpredicated compare, so no `por` is emitted before any compare and the effective file is 4. The guidance was correct when written and the document predates the fix; `benchmarks.md` measured the removal as the single largest avoidable overhead the benchmark had found, 13% of dynamically issued instructions in the reduction kernels |
| F-115 Six of §3's sixteen compare points are unreachable by construction | Step 6 | **open — an ISA observation, not a compiler defect.** `CCVISelDAGToDAG.cpp` selects `setgt`/`setge` as `lt`/`le` with the operands swapped, for signed, unsigned and float alike, because swapping is free and the points are reversible. So **nothing this compiler can emit uses `setp.gt` or `setp.ge`** — 24 of the 267 defined instructions, counting the predicated, unpredicated and immediate tiers. The immediate tiers do not escape it: the swap is unavailable when one side is a constant, but `x > k` is `!(x <= k)` and a predicate qualifier carries a negate bit, so the consumer absorbs the negation at no cost. **The question for the ISA is whether the gt/ge points are worth their opcode space.** Two readings, both real: if the ISA serves only this compiler they are reclaimable, and §3 is short of points in exactly the places O-42 was deferred over; if it serves hand-written PTX and `setp.gt` as an assembly mnemonic, they earn their keep. Compiler-side evidence says reclaimable; the decision is not the compiler's |
| F-116 The dead predicated-compare scaffolding is removed | Step 6 | **closed.** O-32 added Format C″, the unpredicated compare, and ISel selects it directly; the ten `PSEUDO_SETP_*` pseudos and `PSEUDO_PTRUE` that O-24 had needed — when every compare manufactured its own true guard with `por pd, !pd, pd` — have emitted nothing since. F-111's audit found their expansion arms still in `CCVExpandPseudos`, looking exactly like producers of the ten predicated Format C compares, which is why reachability in the gate is a fixpoint rather than a grep. The machine description is 11 instructions smaller, 267 → 256. **The Format C instructions themselves stay**: they are §3 encodings, the assembler and round-trip check cover them, and they are what lane-0 masking of a compare will select once F-119 provides a predicate broadcast — so they moved from `dead` to the same `todo` group as the Format C′ immediate tier, which waits on the same missing primitive. Removing them would have deleted ISA coverage to tidy up a compiler, which is the wrong direction. One consequence worth recording: this removed the last live example of the transitive case, so `check-unselected-mutation.sh` now injects one, in both directions — an emit gated on an unreachable trigger must not count, and the same emit ungated must be caught. A check that stops exercising what it was written for is the failure mode this project keeps finding |
| F-117 The integer and float halves of the ALU disagree about when the tie is imposed | Step 6 | **closed by measurement — O-8's preference stands.** Integer arithmetic selects the three-address Format A form and lets `CCVCompress` narrow it to Format K after register allocation, where the two-address tie is free. Float arithmetic does the opposite: `CCVInstrPatterns.td` matches `fadd`/`fmul`/`fminnum`/`fmaxnum` straight to `C_FADD`/`C_FMUL`/`C_FMIN`/`C_FMAX`, imposing the tie before allocation. F-111 found the asymmetry by noticing that the Format A float forms were unreachable **and that the entries for them in both `CCVCompress` and `CCVMaskUniform` could never fire.** Measured both ways: selecting three-address instead is instruction-for-instruction identical on all eight kernels, identical in issue count and lane activations, and **two bytes worse** in `vadd`, `vadd_loop` and `dot`, because post-allocation narrowing misses ties that matching the destructive form gets for free. So the float patterns stay and the dead table entries were removed. **One consequence is recorded rather than assumed harmless: O-33 cannot lane-gate a uniform float add or multiply.** It costs nothing on these kernels, where the float arithmetic is per-lane data and divergent anyway, but a kernel with warp-uniform float work would pay for it |
| F-118 The intrinsic surface is defined and unlowered | Step 6 | **open — scope, not a defect.** Ten instructions have encodings, spec text and simulator semantics and no path from CUDA: `atom.add.g`, `cas.g`, the warp group `ballot`/`unballot`/`vote.any`, the barrier phase pair `bar.init`/`bar.wait.phase`, `pmov` as a constant-to-predicate path, and the predicate spill pair `ld.pred.s`/`st.pred.s`. Each needs a PTX intrinsic mapped in `CCVISelLowering`, which is Step 7 work. Listed because F-111's declaration list makes the scope explicit and countable instead of implicit |
| F-119 Lane-0 masking cannot gate a compare | Step 6 | **open — the missing primitive is a predicate broadcast.** O-33 masks a warp-uniform operation to lane 0 and broadcasts the result, and the broadcast is `PSEUDO_BCAST`, a `shfl` on a GPR. A compare's result is a **predicate**, so there is nothing to shuffle, and `CCVMaskUniform` therefore skips every compare. That leaves the ten reachable Format C′ predicated-immediate forms with no producer, and more importantly leaves compares out of O-33's energy story entirely. `ballot` and `unballot` are the obvious pair to build a predicate broadcast from — and both are themselves unlowered (F-118), so the two findings share a fix |
| F-120 The SFU transcendentals are unreachable through clang | Step 6 | **open, blocked on F-21.** `sin.f32`, `cos.f32`, `ex2.f32`, `lg2.f32` and `rsqrt.f32` are defined and have no pattern, but the reason is upstream of pattern matching: clang lowers `sinf`/`cosf`/`exp2f`/`log2f` to libm **calls**, and there is no calling sequence yet, so nothing reaches ISel to match. `rsqrt` arrives as a `fdiv` by `sqrt` and is already handled by the reciprocal path. The fix is the same `TargetLowering` work that makes any libcall legal, plus intrinsic recognition for the approximate forms |
| F-121 The Format J accumulate forms are selected | Step 6 | **closed, and the FP32 half was worse than unselected.** Three parts. (1) **Nothing formed an FMA at all.** The GEMM inner loop reached the backend as `contract`-flagged `fmul` + `fadd` and stayed that way, because `isFMAFasterThanFMulAndFAdd` was never overridden — so the machine's fused multiply-add went unused and `FFMA_F0` was reachable only from an `llvm.fma` no kernel produced. Overriding it turns 64 instructions into 32 in `sgemm` 2×2 and takes `saxpy` from 22 to 21. (2) **`CCVCompress` gained the Format J fold**: a three-source operation whose addend the allocator landed on the destination is an accumulate, and accumulate has a 16-bit form. Done after allocation rather than at ISel, so an `fma` whose addend is still live keeps the three-address form instead of paying a copy. (3) **`dp4.ss` is formed in a DAG combine.** LLVM 18 has no `dp4a` intrinsic, so there is no shortcut through one; the combine groups the terms of an add tree by source pair and takes the first group holding all four bytes, because unrolling and reassociation put several dot products in one sum — an earlier version required the tree to be exactly one dot product and so matched a toy kernel and not the GEMM it was written for. Three byte-extract shapes reach it and all three are the same source written differently, since the generic combiner canonicalises the shift pair into `sign_extend_inreg` and folds the top byte to a bare `sra`. `test/cuda/igemm.cu` emits 32 dot products, 25 of them compressed, and `tools/check-dp4.sh` executes the result against a four-MAC reference sharing no code with either the combine or the simulator. Measured effect on F-113's question: INT8 `sp/mac` is 0.51–1.03 against FP32's 2.07–3.78 |
| F-122 Sub-word pack and unpack have no lowering | Step 6 | **open — low priority, and note what they are for.** `packi`, `packi.z` and `unpacki` address **memory** packing, not register packing: a lane holds one element at every width, which O-13 settled and F-79 was withdrawn for contradicting. Their use is forming and consuming a packed load of sub-word data, and nothing in the backend forms one |
| F-123 There is no multi-precision lowering to consume the carry predicate | Step 6 | **open — scope.** `add.pp` and `addi.pp` write a predicate beside the result, which is what multi-precision addition wants, and nothing lowers `i64` arithmetic. Two instructions, and the reason they are unreachable is the absence of a whole feature rather than a missing pattern |
| F-124 Two Format K hints have no lowering | Step 6 | **open — trivial.** `reconv.hint` is unreachable because reconvergence is opportunistic and the compiler emits no hint, and `fence` is unreachable because the barrier path covers what the kernels need. Both are one-line additions whenever a kernel wants them |
| F-125 A 16-bit global access through base+displacement transferred four bytes | Step 6 | **fixed — and it was a miscompile, not a missed optimisation.** §3 takes transfer size from `rdata`'s `chwidth`, so a narrow access must select the 16-bit instruction to put its destination in `GPR16` and let `CCVInsertChwidth` narrow it. The base+**index** path has checked the memory type since a `short` kernel first clobbered its neighbour, and the comment there says so. **The base+displacement path was never given the same check** and always selected the 32-bit form: the data register was 32 bits wide at the access and narrowed afterwards, so the load read four bytes (past the end of a two-byte element) and the store wrote four (over the next element). The value the kernel is asked about is correct in both cases and only the neighbour is wrong, which is why nothing downstream saw it. F-111's audit found it by asking what could produce `LD_GLOBAL_W16` and `ST_GLOBAL_W16`, and the answer was nothing. Fixed, and worth 3 instructions on the test case as well; `test/accept/base-offset-i16.ll` plus a check in `run-tests.sh` pins it, keyed on the tell — a **widening** `chwidth` in a kernel that is 16-bit throughout |
| F-126 The case for a warp-uniform file is addressing, not accumulators | Step 6 | **open — this is the evidence F-106 was waiting for, and it points somewhere else.** F-113's split shows pointer/index spill dominating at every tile that fits 16 GPRs, and the uniformity analysis reports **peak warp-uniform values live at 11, unchanged across every tile size** — it is a property of the addressing, not of the accumulator tile. Those eleven are the window bases and block offsets, CTA-wide by construction, and they are exactly what the `ptr-sp` column spills. `gpr-count-decision.md` named a uniform file as the escape hatch *if GEMM accumulator pressure binds*; the measurement says accumulator pressure does not bind until 4×4, one tile past the `sp/mac` minimum, while **address pressure binds everywhere**. So the argument for F-106 is stronger than the decision's own framing and rests on a different quantity. What it does not yet establish is how much of `ptr-sp` a uniform file would actually remove: `unif` is a ceiling from IR-level analysis, and the spill classifier works on physical registers after allocation, so the two are measured at different points and are not the same eleven values. Closing that gap is the one measurement left before the call |
| F-127 The tile ceiling against a machine that does not spill | Step 6 | **open — the competitive framing of F-113, and it is worse than the spill counts alone suggest.** `tools/nv-tile-pressure.sh` compiles the same `sgemm.cu`, same block shape, same tiles, to PTX for sm_70 and reads `ptxas -v`. **Zero spill at every tile**, including 8×8: 32 registers through 2×4, 48 at 4×4, 121 at 8×8. CCV runs its best tile (2×4) with 139 spill transfers where NVIDIA uses 32 registers and spills nothing, and at 8×8 issues 2582 instructions with 1491 spills, which is not a tuning point but a report that 64 accumulators do not fit in 16 registers. **The gap is arithmetic intensity, not instruction count**: a TM×TN tile does TM·TN MACs per TM+TN operand elements, so 2×4 buys 1.33 and 8×8 buys 4.0 — three times the arithmetic per byte of operand traffic, which is a bandwidth argument that encoding density does not answer, and CCV is already competitive on density (0.94× of SASS aligned after O-45; 1.045× when this was written). Two qualifications, neither of which removes it: `dp4.acc` closes most of the gap for quantized work (INT8 `sp/mac` 0.51 against FP32's 2.07), and a throughput SGEMM is not what a 16-GPR machine is for. But FP32 GEMM is the case `gpr-count-decision.md` itself named as unmitigated |
| F-128 ~~The spill a uniform file would relieve~~ — **retracted, and why** | Step 6 | **withdrawn by F-129's measurement, and the retraction is the useful part.** F-128 read `sweep-tiles.sh`'s `ptr-sp` column (110 of 139 spill transfers at 2×4 are pointer/index) beside the uniformity analysis's `peak uniform values live: 11` and concluded a warp-uniform register file would hold what was spilling. **Both numbers were right and the conclusion did not follow.** `sgemm` indexes by `threadIdx` — `row0` is `brow*(BY*TM) + ty*TM` and `ty` is derived from the thread id — so its row and column offsets **differ per lane**. They are addresses, and they are divergent, and a uniform register file cannot hold a divergent value whatever role it plays. The uniformity pass now reports the split: at 2×4 the peak **divergent** working set is **69 values against a 16-entry file**, and at 8×8 it is 227. Move every uniform value elsewhere for free and this kernel spills essentially as much as before. What survives F-128 is the observation that spill CAUSE crosses over — pointer/index dominates to 2×4, accumulator takes over at 4×4 and is 78% at 8×8 — and the conclusion that a uniform file does nothing for the tile ceiling, which was right for a reason F-128 did not give: accumulators are divergent, and so is most of the addressing. **I had flagged the gap in F-126 — "`unif` is an IR-level ceiling, the spill classifier works on physical registers, they are not shown to be the same eleven values" — and then argued from the pairing anyway. The flag was correct and stating it was not a substitute for closing it** |
| F-129 Where a warp-uniform file would actually pay | Step 6 | **measured, and it is none of the shapes the argument had been made about.** `tools/sweep-decode.sh` sweeps the shapes an inference workload is mostly made of, with `test/cuda/gemv.cu`, `gemv8.cu` and `fused.cu`. Three shapes, three answers. **`gemv` (batch-1 decode) does not bind**: 6 divergent and 7 uniform values live, 11 spill transfers in 226 instructions — there is no reuse to tile for, every weight is read once, and the register file has nothing to hold. `gemv8` is identical on every column and does four times the arithmetic per word. **`sgemm` binds on divergent values** (47–227), so a uniform file is beside the point. **The grid-strided fused elementwise chain is the case**: its divergent working set is **4 values at every tensor count** — element, index, counter, bound — while its uniform working set is the window bases and grows 7 → 10 → 14 → 22 with the number of tensors fused. Spill begins exactly where that crosses the 16-entry file and reaches 79 transfers at sixteen tensors. **Four divergent values spilling because twenty-two uniform ones are in the way** is the one measured shape where a uniform file removes essentially all of the traffic rather than some of it. The straight-line version of the same chain does not spill and is not free either: each base is re-fetched from the launch block at its single use rather than kept in a register, which is **about a third of the kernel's instructions**. So the case for F-106 rests on looping fused elementwise kernels — the dominant non-GEMM shape in inference — and on neither argument previously made for it |
| F-130 The uniformity analysis reports the divergence split, and is no longer cubic | Step 6 | **done, in service of F-129.** `peak uniform values live` was a single number and the decisive question needed two: a uniform register file holds uniform values and cannot hold divergent ones, so what decides it is whether the **divergent** peak alone already exceeds the file. The pass now reports peak total live with its split at the busiest point, peak uniform live and peak divergent live. The walk was also rewritten from def/last-use positions with a difference array instead of rescanning every value's users at every program point — it was O(n³), which stopped being runnable at the tile sizes F-113 added. `CCVWindowRemat` gained `-ccv-window-remat=false` so the incumbent mitigation for uniform pressure can be A/B'd; it turns out not to be what absorbs it in the straight-line fused kernels, where the bases are simply re-loaded per use |
| F-131 Accumulator capacity: what a uniform file cannot do, what tuning can, and one claim I got wrong | Step 6 | **measured, with a correction.** (1) **Can a warp-uniform register file hold accumulators? No, and not for an implementation reason.** A GEMM accumulator is `C[row0+i][col0+j]` with `row0` and `col0` derived from `threadIdx`: every lane holds a *different* element, which is what data-parallel accumulation means, while a uniform register holds one value shared by 32 lanes. Incompatible by definition. It helps only indirectly, by vacating GPRs addressing occupied, and F-129 measured `sgemm`'s divergent working set at 69 values against a 16-entry file at 2×4 — vacating ten does not change that. (2) **The accumulator problem is smaller than it looked**: accumulator spill is 0, 0, 4, 8 of 34, 54, 85, 139 transfers at the tiles the machine can practically run. The cliff is 4×4 and beyond; below it what binds is divergent index arithmetic. (3) **The largest measured lever is how the kernel is written.** `sgemm.cu` carries `#pragma unroll` on every inner loop — the idiom of a 255-register machine, and no cost model overrides a pragma. Unrolling only the K loop, at 2×2: **294 instructions and 85 spill transfers at full unroll against 156 and 24 at K-unroll=1**; at 2×4, 440 and 139 against 224 and 51. **(5) F-135 settled the static/dynamic question and cut this headline by about four: dynamic issue count improves only ~6% where the static count said 25%, but dynamic spill traffic falls 2.3×. Partial unrolling is worth doing and it is a spill optimisation, not a code-size one. (4) CORRECTION.** I first reported that this lever was *blocked* by a compiler crash. It was not: the crash came from my own sweep applying `#pragma unroll 1` to the array-fill loops as well, which is what stopped mem2reg promoting `a[TM]`/`b[TN]`. Unrolling only the K loop compiles at every setting and always did. The static/dynamic caveat stands and is now the open question: a shorter body executed more often is not obviously less spill traffic, and the simulator has not been run |
| F-132 Two cost-model levers tried and reverted, recorded so they are not retried blind | Step 6 | **negative results.** Both were plausible, neither moved a number, and both are reverted rather than left in as unmeasured correctness. (1) **Marking the Format B register-immediate ops rematerializable.** The motivating pattern is real — `sgemm` computes shared-memory addresses as `or rd, r2, #k` and spills each one immediately, where recomputing costs one instruction against a store plus a load — but adding `isReMaterializable` to `SUBI`/`MULI`/`ANDI`/`ORI`/`XORI`/`ANDNI`/`SHLI`/`SHRI`/`SRAI` changed spill counts by zero at every tile. The values are spilled at their definition, not reloaded under pressure, so there is no reload for remat to replace; the source register would have to be live too, and it is not. (2) **Telling TTI the machine has 16 registers** (`getNumberOfRegisters`, `getRegisterBitWidth`) and capping unrolling in `getUnrollingPreferences`: also zero, because the unrolling in question is a source `#pragma unroll` and a pragma overrides the cost model. That is how F-131 found the real lever |
| F-133 Local arrays have a lowering path | Step 6 | **mostly done, with a named boundary.** An `alloca` the middle end could not promote used to abort the backend in the type legalizer — "Do not know how to expand the result of this operator!", because an alloca's pointer is addrspace(0) and this data layout makes that 64 bits. The ISA needed nothing new: §5.1 windows `.local` exactly as it windows `.global`, O-30 reserves R15 as the window base (which is why a spill has always been `[r15 + disp]`), and a dynamically indexed array is Format D base+index with R15 as the base. What was missing was a matcher. `matchFrame` now folds a frame address before legalization — for the same reason the window combine does (F-20) — walking the address expression to collect a constant displacement and at most one dynamic term, re-creating the frame index as an i32 TARGET frame index so no i64 survives as an operand, and peeling the element scaling so the AGU does it. Three further gaps fell out and are fixed: **`llvm.lifetime` markers** kept an i64 frame index live into the legalizer and are now dropped in the combine; **an i1 constant had no selection** (`Cannot select: i1 = Constant<-1>`, from a boolean loop-carried value in a partially unrolled loop) and now selects `pmov` per O-14; and **`eliminateFrameIndex` assumed the displacement sat one operand after the base**, which is true of base+offset and not of base+index, and checked 13 bits for both where base+index has 8 — a frame offset past 127 bytes would have truncated into the narrower field silently. `tools/check-local-array.sh` writes through the dynamic form and reads back through the constant form, including the index where the two alias, which is what pins the displacement and the scale together; both a cleared scale-enable and a misplaced displacement operand fail it. **The boundary:** an address rooted at a frame object with a shape outside base + one index + a constant is diagnosed rather than lowered. `sgemm` at TM=2/TN=4 with the K loop not unrolled at all still hits it, and I stopped chasing the tail rather than guess at a fourth shape |
| F-134 `sgemm` had never been executed, and two bugs were waiting in it | Step 6 | **both fixed, and the lesson is the shape of them.** `sgemm` is the kernel most of this project's architecture conclusions lean on — O-25's tile sweep, F-113's spill split, F-127's comparison against NVIDIA, F-131's unroll question — and it is not in `bench.py`'s `ARGS` table, so it had never been RUN. Every check it ever passed was a check on its text. The first time it executed it **hung**, and the hang was a compiler bug: `CCVMaskUniform`'s `inUniformRegion` asked "is this use uniform and in an undivergent block" when the question is "will this use run under the lane-0 mask". A **compare** passed the wrong test — `setp` defines a uniform predicate — so no broadcast was inserted, but no compare is maskable (F-119), so it ran in all 32 lanes reading operands only lane 0 had computed. In `sgemm` those are the `bpr` division feeding the loop bound: lane 0 left the K loop while 31 lanes stayed in it, and those 31 waited at a `bar.wait` for a lane that was never going to arrive. The fix costs instructions where broadcasts were genuinely missing — `transpose` 61 → 64, and its masking saving falls from 341 lane-activations to 217 — which is the real price of the transformation, previously undercounted. **The second bug was in the kernel.** Its K-tile staging indexed `Bs` by `(t % KT, tx)`, and `tx` is `t % BX` with `BX == KT`, so the two collide and only the diagonal of `Bs` was ever written: it did not compute a matrix product. Restaged by a flat index over the tile. Every GEMM figure in `benchmarks.md` moved as a result and is regenerated. `tools/check-sgemm.sh` now executes it against a matrix-product reference in the gate, so neither can come back |
| F-135 Partial unrolling, measured dynamically: the spill win is real, the instruction win was not | Step 6 | **settles F-131's open question, and cuts its headline by about four.** `tools/sweep-unroll.sh` runs `sgemm` for one K-tile at each unroll factor. At 2×2: full unroll is 382 static instructions, **378 issue groups executed and 50 spill transfers executed**; unroll=4 is 286 static, **355 executed and 22 spilled**; unroll=1 is 232 static, **382 executed and 20 spilled**. So dynamic issue count has a shallow minimum at unroll=4 worth about **6%**, where the static count suggested 25% — a shorter body executed more often is very nearly the same work, exactly as the caveat said it might be. **Dynamic spill traffic is the real result: 50 → 22, a 2.3× cut**, and that is memory traffic the register file was forcing. 1×1 agrees: 22 → 6. So partial unrolling is worth doing on this machine and it is a *spill* optimisation, not a code-size one — and the earlier static-only claim would have oversold it four-fold on the axis it did not measure |
| F-136 The AI/ML relevance proposal, for external review | Step 6 | **written, awaiting review.** `proposals/ai-ml-relevance.md` puts three ISA additions to the ISA side with a strength of ask for each, weighed against Format H rather than in isolation. **(1) FP packed dot-product-accumulate** (`dp2.bf16`/`dp2.f16` → FP32) at the eight free points of 48–63 — **strong**: reserved space, no new format, and it extends the mechanism F-121 built and F-113 measured to the precision the target workload actually uses, where `dp4.acc` covers only INT8. §10 currently defers FP packing to Format H on the grounds of the fragment operand model, and the proposal argues that reason does not hold because `dp4` already shows a packed reduction living in Format A without touching invariant 1. **(2) Launch-block-relative addressing** — **medium, and asked to be priced before (3)**: the values that spill in fused kernels are window bases, which are warp-uniform, loop-invariant AND already resident in a small read-only table, so a register is being spent to cache something that is already in memory. The encoding question is put to the ISA side rather than answered, explicitly because this proposal series got invariant 8 wrong once before (F-110). **(3) The warp-uniform register file** — **weak, recommend deferring**, with three stated conditions to revive it. The retraction history (F-126/F-128 → F-129) is in §1 so the review can discount accordingly, and `warp-uniform.md` gained a banner pointing at the disagreement rather than being quietly overwritten |
| F-137 O-44's FP packed dot products, implemented and pinned | Step 6 | **encodings and semantics done; selection is not, and cannot be yet.** `dp2.bf16`, `dp2.f16`, `dp4.e4m3` and `dp4.e5m2` are in the machine description at §4 points 52–55 and in the simulator. **Nothing can form one**: building the packed operand needs a bfloat, half or FP8 value in the IR and this backend has none of those types, so they are declared `todo` in the F-111 gate rather than left to look reachable. What is pinned instead is the part that would otherwise go unchecked — §4 makes the accumulation rule normative (products sum exactly, one rounding into the accumulator) and `tools/check-dp-fp.sh` hand-assembles the instructions and executes them against a reference computed in exact rationals. **The first version of that test was green because it was not looking:** it mutated per-product rounding, which changes nothing, because a product of two BF16 values has at most 16 mantissa bits and is exact in FP32 either way. The rule decides the SUMMATION, so the cases now sit at 2^24 where FP32 runs out of integers and a step-rounded sum loses what an exact one keeps; mutating the accumulator to `float` fails two of five. One case comment was also wrong and is corrected in place — `+1` then `−1` is not a no-op at 2^24, because the first addition rounds to even and the second then has a full ulp to give back |
| F-138 `gpr-count-decision.md` names the wrong trigger for the uniform file | Step 6 | **correction required in a document outside this repository.** O-44's review and F-129 arrived at the same place from opposite directions. `gpr-count-decision.md` names the warp-uniform register file as the escape hatch *if GEMM accumulator pressure binds*. **Accumulators are per-lane — divergent — so a uniform file was never the answer to that trigger.** The mechanism was named correctly and attached to the wrong condition, and the F-106 escalation compounded it by citing the SASS evidence (`S2UR`, `ULDC`, uniform operands on vector instructions) as though it confirmed uniform registers address accumulator pressure; it confirms they exist and are useful, which is a different claim. **The amendment asked for:** strike the claim that a uniform file is the response to GEMM accumulator pressure, and replace the escape hatch with the honest statement — accumulator pressure is divergent, no uniform mechanism reaches it, and the remaining candidates are Format H's operand model or a larger file. The document is not in this repository, so this row is the record until it is amended |
| F-139 O-45 implemented, and it needed F-86 reversed to deliver | Step 6 | **done, and the measurement is the point.** Launch-slot addressing is in: `FormatDslot` with a 4-bit slot index where `rbase` sits, a matcher that recognises a launch-block window load in either shape the combiner may have left it in, selection, and the simulator's AGU reading the slot. **On its own it did almost nothing for the case it was adopted for.** The straight-line fused kernels improved (NT=16 102 → 94 instructions) and the grid-strided ones — the shape F-129 measured and the reason O-45 exists — did not move at all: still 202 instructions and 79 spill transfers. SelectionDAG works one basic block at a time, and LICM hoists the window load to the preheader, so the DAG in the loop body sees a register and not a load. **F-86 is what had to change.** `CCVWindowRemat` stopped cloning at GPR-width values because cloning the i32 launch-block load "costs a load in every block that uses the window, which in a LOOP means every iteration" — true when it was written, and **reversed by O-45**, because the clone no longer becomes a load. It becomes a 4-bit field. With launch-block loads cloned past that boundary: **NT=4 64 → 42 instructions and 13 → 0 spills; NT=8 117 → 60 and 38 → 0; NT=16 202 → 114 and 79 → 9.** The general lesson is worth more than the numbers: an addressing mode that removes a value from the register file also removes the reason a pass was avoiding rematerialisation, and the two changes are worthless apart |
| F-140 The 4-bit slot index reaches the first eight pointer arguments | Step 6 | **a design limit found by measurement, for the ISA side to weigh.** Slot *k* is the word at launch-block byte offset `32 + 4k`, so sixteen slots cover 64 bytes — and §5.2 gives a pointer argument 8 bytes (window plus in-window offset), so **the form reaches pointer arguments 0–7 and no further**. `fused.cu` at NT=16 has eighteen pointer arguments and gets exactly 8 slot-form accesses, the rest falling back to a register base; that is the 9 residual spills in F-139's NT=16 row. Not a defect — the fallback is correct and the limit is the natural consequence of spending 4 bits — but it is the reason the largest fused kernel still spills where the smaller ones no longer do, and if fused kernels routinely exceed eight tensors the slot field is the thing to widen. Recorded rather than fixed: widening it costs encoding space and the compiler side has one synthetic kernel, which is the same thin evidence the uniform-file ask was rated weak on. **Superseded by F-146**, which finds the field is not too narrow but scaled wrong, and withdraws the widening ask |
| F-141 The SFU was unreachable the slow way, not unreachable | Step 6 | **closed, five instructions.** `check-unselected.py` carried `sin.f32`, `cos.f32`, `ex2.f32`, `lg2.f32` and `rsqrt.f32` as `todo` with the reason "clang emits a libm call and there is no calling sequence yet (F-21)". That is true of `expf(x)` and **irrelevant to a GPU kernel**, which writes `__expf`/`__sinf`/`rsqrtf` or is built with fast-math — and every one of those arrives in LLVM IR as an INTRINSIC, needing no calling sequence: `llvm.exp2.f32`, `llvm.log2.f32`, `llvm.nvvm.{rsqrt,sin,cos}.approx.f`. Five patterns select them, and `ex2`/`lg2` additionally needed `setOperationAction(Legal)` because LLVM's default for both is Expand — which does not mean "expand into arithmetic", it means "call `exp2f`", and that libcall **crashed the compiler rather than diagnosing anything**, which is how the gap stayed invisible. `tools/check-sfu.sh` executes all five from one kernel against their own functions, because a crossed pattern table (`flog2 → EX2_F32`) compiles, encodes, disassembles and round-trips perfectly. What remains genuinely blocked is the accurate libm form, which is a different function and still needs F-21. **The finding is about the triage, not the patterns**: a `todo` reason that names a real blocker is not the same as a `todo` reason that names the blocker for the case that matters |
| F-142 `out[i + 1]` segfaulted the compiler, and the field to hold it was always there | Step 6 | **a two-year-old crash that no kernel in the tree had ever written.** Format D base+index carries an 8-bit signed displacement (`disp`, `Inst{31:24}`), the simulator's AGU has always added it, and **instruction selection wrote a literal zero into it**. `matchBaseIdx` matched a window plus one index and nothing else, so an address with a constant on top — `(window + i*4) + 4`, which is what clang leaves for `out[i + 1]` when the constant comes from a second GEP — matched neither base+index nor base+offset, fell through every arm of the combine, and reached the type legalizer as a live 64-bit add. There is no expansion for one: it **SEGFAULTED**, with no diagnostic. `CCVCheckIR` did not catch it because its rule counted a constant GEP index as a register addend, which made it disagree with the matcher in the safe direction on unaligned pointers and the unsafe direction on aligned ones. Fixed on both sides: the matcher peels the constant into the field (folding into the index register only when it exceeds 8 bits), and the IR rule counts dynamic indices only. **Why it survived: not one kernel in `test/cuda/` or `test/bench/` emitted a single non-zero displacement** — the shape is ubiquitous in real code and absent from a corpus written to exercise addressing modes on purpose. That is the argument for a corpus of kernels written from real workloads rather than to exercise the machine, made by accident |
| F-143 A real fused-kernel corpus, and it says something different | Step 6 | **built and measured, and it moves two open questions at once.** `test/cuda/fusion/` holds eight kernels written from the published shape of ones that actually run -- RMSNorm and its fused-residual form, `silu_and_mul`, rotary embedding, LayerNorm with saved statistics, the INT8 dequantisation epilogue, the flash-decoding combine, AdamW -- with **every pointer count forced by the kernel's own mathematics rather than swept**. `tools/sweep-fusion.sh` measures them and `tools/check-fusion.py` EXECUTES all eight against references written from the mathematics, per F-134. Three results. **(1) The corpus reaches six pointer arguments, and the slot field reaches eight**, so F-140's proposal to widen it has no measured kernel behind it: `silu_and_mul` takes two pointers because the gate and up projections are halves of one allocation, which is exactly the detail a kernel parameterised on "number of tensors" cannot produce. **(2) `ptr-sp` is zero in all eight** -- after O-45 there is no window-base spill left for a uniform file to hold, which closes what remained of F-126/F-128 from the other side. **(3) What spills is warp-uniform SCALARS**: `rope`'s head geometry, `adamw`'s eight optimiser constants, `attn_combine`'s split count, and the CTA index -- one launch-block word each, identical in all 32 lanes, loop-invariant, and today costing either a spill slot or a lane-0 masked compute plus a broadcast. That is a **third** thing, and it is neither of the two previously argued for a uniform register file: not accumulators (divergent, F-138) and not window bases (O-45). The case for F-106 survives both of its failed arguments, narrower, better founded, and smaller -- 3 to 17 transfers in a real kernel against 79 in the synthetic one. `CCVSpillStats` gained the `warp-uniform` cause to measure it, established structurally (a launch-block read, `srd %ctaid`, or O-33's broadcast) rather than inferred, and its classifier now follows predecessors so a value spilled in a loop but computed in the preheader is attributed instead of landing in `unclassified` |
| F-144 Every negative float constant was unencodable | Step 6 | **two selection defects, both found by the first kernel that needed them.** `fpimm_bits` built MOVI48's wide immediate as an `MVT::i32` target constant, which reaches the MachineOperand SIGN-extended -- so any float with its sign bit set arrived negative and failed MOVI48's unsigned 33-bit field check. A **hard compiler error on `-1.0f`**, and the sibling transform for integers carries a comment explaining this exact hazard, dated from when the software divide hit it. Separately, `fdiv -1.0, x` reached instruction selection with no pattern: `CCVExpandDivision` runs on IR and only exempts `1.0/x`, and the generic combiner MANUFACTURES the negated form later by reassociating `a - b * (1.0f/x)`. Both fixed. Both invisible until `ccv_exp` needed `exp2f(-x * log2e)` and AdamW needed to subtract a reciprocal-scaled term; no kernel in the tree had ever written a negative float literal |
| F-145 O-33's lane-0 masking is unsound when lanes are not co-issued | Step 6 | **a soundness bug in a shipped optimisation, found by an ordinary nested loop.** The masking pass computes a warp-uniform value in lane 0 and `shfl.idx` broadcasts it, and its stated safety condition is that **every lane reaches the block**. That is necessary and not sufficient. The broadcast is warp-collective: it needs lane 0 ISSUING WITH the lanes that read it, and §1 gives this machine per-thread PCs with **opportunistic** reconvergence -- `reconv.hint` exists precisely because Phase 1 hardware guarantees no join, and the hint "does nothing in Phase 1". So after a divergent branch, lanes that all eventually arrive may arrive at different times. `rope` is the smallest real kernel that shows it: an inner loop whose trip count comes from `threadIdx` leaves lanes 4–31 running ahead to the outer latch while 0–3 are still inside; the latch post-dominates the inner exit so it was not control-dependent on it, the outer loop counter was masked to lane 0, and **the group without lane 0 read lane 0's stale counter forever**. The kernel never terminated. Fixed by an AND-meet forward dataflow that additionally requires lanes to be co-issued -- no divergent branch on any path from the entry, or a barrier since the last one, a barrier re-establishing it because every lane leaves one at the same PC. **The existing wins are untouched**: `transpose` still masks 7 with 3 broadcasts. `tools/check-fusion.py` is the regression test. **For the ISA side**: this is the first place where opportunistic reconvergence has a measurable compiler cost, and it is an argument for `reconv.hint` doing something in Phase 1, or for a mask-aware broadcast -- the compiler currently pays for the absence of a join guarantee by declining to optimise across every divergent branch in the function |
| F-146 The slot field is not too narrow, it is scaled wrong | Step 6 | **measured, then withdrawn as a widening ask; `proposals/slot-field-reach.md` is open for review.** F-140 proposed spending encoding bits on the 4-bit launch-slot index. Two things say not to. **(1) The field supplies the AGU a WINDOW INDEX, and the only launch-block words holding one are pointer arguments' window words — which §5.2 puts 8 bytes apart while the slot stride is 4. Eight of the sixteen encodable slots name an in-window offset or a scalar and can never be a legal `rbase`: half the slot space is dead by construction.** Re-scaling the stride to 8 bytes doubles the reach to sixteen pointer arguments with **no encoding change whatever** — same 4 bits at `[18:15]`, same two opcodes — for one bit of shift in the slot decode, plus an ABI rule that pointers occupy the front of the argument area. Measured by patching the three places that must agree (argument layout, ISel matcher, simulator AGU) and running the whole gate including everything that executes: on `fused.cu` as a grid-strided loop, slot-form accesses go 8 → 16 at NT=16, instructions 114 → 92, and **spill transfers 9 → 0**. The patch was then reverted; the tree does not carry an unapproved change to what an encoded field means. **(2) On the real corpus it changes nothing at all** — every row of `sweep-fusion.sh` is byte-identical under both scalings, because no kernel there has more than six pointers (F-143). So the re-scaling is free, correct and a strict improvement, and the only kernel it currently helps is the synthetic one. Widening the field is withdrawn outright: the bit would have to come out of Format D's 8-bit `disp`, which F-142 has just shown is load-bearing, to buy reach past sixteen that not even `fused.cu` asks for. The next step past sixteen is a dynamically indexed slot rather than a wider one — `multi_tensor_apply` passes its pointer array as a by-value struct and indexes it at runtime — and that is not asked for here, because this backend cannot lower a by-value aggregate kernel argument at all |
