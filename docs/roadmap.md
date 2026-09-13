# Bring-up Roadmap and Compiler-Side ISA Findings

**Status:** Phase 0 (contract definition). No code yet.
**Companions:** `isa-v1.5-operation-map-and-encoding.md` (encoding ground truth),
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

**Exit criterion: met.** All of it is folded into
`isa-v1.3-operation-map-and-encoding.md`, which is now the encoding ground truth;
v1.2 is kept for the decision trail. The launch-block byte layout remains an ABI
document to be written, and blocks nothing.

### Step 1 — Machine description and MC layer *(in progress)*

**Done:** TableGen target description (`llvm/CCG/`), generating cleanly through
`-gen-register-info`, `-gen-instr-info`, `-gen-emitter`, `-gen-disassembler` and
`-gen-asm-writer`; encoding invariant checker (`tools/check-encoding.py`); gate
script (`tools/verify.sh`). 65 instructions, at least one per format. Five new
findings, F-12 to F-16, all from transcribing §3 into a form a machine checks.

**Also done:** the C++ MC layer — target registration, `MCTargetDesc`, code
emitter, instruction printer, disassembler — built out-of-tree against installed
LLVM 18, plus `ccg-roundtrip`. **The Step 1 exit criterion is met**: 4160
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

**Done:** `tools/ccg-sim` executes a warp of 32 lanes with independent
per-thread PCs, driving the generated disassembler so decoding is not
re-implemented — the simulator is semantics only, which is the division F-6
settled on. Plus `tools/ccg-as.py`, a minimal assembler driven from the
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
vadd.cu → clang → NVVM IR → CCGLowerKernelArgs → ccg-llc → ELF
        → .text → ccg-sim
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

### Step 4 — Reduction kernel

Adds control flow, Format G shuffles, barriers, predication, and `reconv.hint`
emission. First real exercise of the predicate file — where F-2 gets tested
against practice rather than argument.

**Produces:** first data on predicate pressure; real `reconv.hint` placement,
which opens the O-4 join-PC question.

### Step 5 — GEMM tile

Adds shared memory, Format J accumulate, and serious register pressure.

**Produces:** the spill data that decides 16 vs. 32 GPRs, and the destructive-form
hit rate for O-8.

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

### Step 6 — `chwidth` mode insertion, elementwise at varying width

The F-3 pass. Last because it is the largest single piece of non-standard
backend work and because it benefits from having three working kernels to
regress against.

**Produces:** width-transition frequency and `chwidth.multi` hoisting
effectiveness — data on whether the O-6 multi-register form earns its format.

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
| F-2 predicate spill path / `unballot` (O-14) | Step 0 | **open — proposal in `proposals/predicate-transfer.md`; blocks Step 4** |
| F-8 predicated write to a predicate destination — preserve or clear? | Step 0 | **open — preserve recommended, see proposal §7–8; blocks if-conversion** |
| F-10 `packi` partial-write semantics — preserve + `packi.z` variant | Step 0 | **open — see proposal §6** |
| F-9 Format D carries two contradictory opcode maps (editorial) | — | resolved in v1.3 |
| F-12 32 GPRs is an encoding fork, not a subtarget flag | — | **closed — 16 settled in v1.5 O-25.** `GPRC` and R16–R31 removed from the machine description; one encoding path, two allocator objectives not three |
| F-17 §5.5 figures were wrong (23 not 22 instructions, 27.1 not 28.4 b/instr, 8 not ~10 live) | — | fixed in v1.4; `tools/check-listings.py` now re-derives them |
| F-17a Both worked listings were hand-written, so neither tracked codegen | — | resolved — `tools/check-spec-vs-codegen.py` diffs §5.5 and §5.6 against fresh `ccg-llc` output in `verify.sh`; caught peak-live 8→5 and the uncompressed third fold |
| F-20 LLVM requires a pointer in a register; invariant 11 says there is none | Step 3 | **resolved — consumed in a pre-type-legalization DAGCombine; no 64-bit register class. Severity was overstated; see `proposals/pointer-representation.md`** |
| F-21 Value-returning device functions need a variadic return pseudo | Step 4 | open — kernels return void, so not blocking |
| F-22 Pointers escaping an addressing mode have no lowering convention | Step 4 | open — diagnosed at compile time, not silently miscompiled; needs an (rbase, roffset) pair convention |
| F-23 The <4 GiB allocation precondition is implicit in the lowering | Step 5 | open — belongs with O-23's launch-time validation; the compiler cannot check it |
| F-24 Unsigned and FP compares not selected | Step 4 | **resolved — Format C/C′ now carry one shared 16-point compare map (O-26). Unsigned lt/le and FP olt/ole/oeq/une select; gt/ge come from operand swap. SETONE/SETUEQ/SETO/SETUO still diagnosed** |
| F-30 `bar.wait`'s phase parity is an immediate, but must alternate per dynamic execution | Step 4 | **resolved — O-27. The per-warp epoch moves into hardware, so the compressed `bar.wait #id` carries no phase and is correct at every iteration; `[14]` becomes reserved. `test/accept/barrier-in-loop.ll` was a reject case and is now an accept case** |
| F-35 `bar.wait.phase` has no selection path | Step 5 | open — O-27 added it at Format E `00100` for pipelined producer/consumer, where a warp waits on a barrier it did not arrive at. Encodable, assembler-reachable and round-trip tested, but CUDA C produces it only through async-pipeline intrinsics, which the frontend path does not yet carry |
| F-36 The whole accept/reject suite was gitignored | — | **resolved — a stray `*.ll` rule meant 16 of 19 files under `test/` were never committed; a fresh clone had three `.cu` files and no regression suite. `run-tests.sh` now fails on an empty suite rather than passing vacuously** |
| F-31 Shared memory (`addrspace(3)`) has no load/store selection | Step 4 | **resolved — `CCGLowerShared` assigns each shared object its offset in the CTA allocation and replaces the global with an `inttoptr` constant; `.shared` is flat 32-bit so there is nothing to relocate. Base+index forms added at Format D `00110`/`00111`. The windowed DAGCombine is now excluded from `.shared`, which it would otherwise have miscompiled** |
| F-37 The windowed DAGCombine had no address-space guard | Step 3 | **resolved — `matchBaseOff` matches any constant address, so a `.shared` access at a constant offset would have become an `ld.global` of that offset. Guard is "not shared", not "is global": `.const` and `.local` are windowed too (§5.1), and an early attempt at "is global" broke every launch-block load** |
| F-38 Most of §3/§4's opcode map had no instructions | Step 4 | **resolved — 4 of Format K's 24 ALU points and 3 of Format A's 26 integer points existed; the rest were added from §3 and §4's own lists. 148 instructions, up from 68 at the start of Step 4. Exposed O-28: the spec named operations but never numbered them, and the numbering is load-bearing** |
| F-39 Signed fields decoded unsigned — every backward branch was wrong | Step 4 | **resolved — TableGen's default decoder zero-extends, so `bra -26` decoded as `bra 2097126` and every negative load/store displacement was wrong too. Signed operand classes now carry an explicit `decodeSImm<N>`. Invisible until the reduction, because every branch before it was forward** |
| F-40 The round trip could not catch F-39 | Step 4 | **resolved — two independent gaps. It generated immediates as `RNG() & Mask`, so no signed field ever saw a negative value; and it compared only register operands, so the entire immediate path was unchecked. Operand widths were also taken from the *narrowest* field on the instruction (2 bits on a Format C compare), so wide immediates were only ever tested with tiny values. Now per-operand width and signedness from the same `.td`. Verified by reverting F-39's fix: 34 failures, then 0** |
| F-41 Simulator lacked shared memory, barriers, and most of the ALU | Step 4 | **resolved — `.shared` as a separate flat 32-bit space, barrier arrival/epoch state per lane with scheduler stalls and deadlock detection, and the full §3/§4 ALU and compare sets. `tools/run-reduce.sh` runs the block reduction from CUDA source to a correct sum** |
| F-42 `select` hung the compiler in an infinite legalization loop | Step 5 | **resolved — SELECT was Expand, which expands to SELECT_CC, which was also Expand and expands back to SELECT. Not a crash: ccg-llc spun. Latent since Step 3 because every conditional until now became real control flow. §4 point 19 is `sel`, now defined (Format A′, and the one predicated instruction that writes rd unconditionally)** |
| F-43 Compressed shift immediates were silently truncated | Step 5 | **resolved — `(shl/srl/sra GPR, imm)` selected Format K's 4-bit immediate form with no range predicate, so a shift by 31 encoded as a shift by 15. Invisible to the round trip, which agrees with itself on the truncated value. `verifyImmediatesFit` in the emitter now rejects any immediate that does not fit its field, checked against the same `.td` — the general form of the bug, not just this instance** |
| F-44 Predicate copies were emitted as GPR moves | Step 5 | **resolved — `copyPhysReg` emitted `C_MOV` for every copy. P0–P3 and R0–R3 encode identically, so `mov p1, p0` assembled, disassembled and executed as `mov r1, r0`, silently clobbering a GPR. Predicate copies now use `por pd, ps, ps` (O-20, 16 bits, no new opcode); a GPR↔predicate copy is a hard error** |
| F-45 Integer division had no lowering | Step 5 | **resolved — `CCGExpandDivision` applies LLVM's shift-subtract expansion in IR, as nvcc does for the same reason. Constant divisors never reach it; instcombine turns those into a multiply and a shift. Executed in the gate, not just compiled** |
| F-46 No spill path — the allocator corrupted the heap | Step 5 | **resolved — O-30. Not "spills badly": the backend could not compile a GEMM at all, at any tile size including 1×1, and crashed with `free(): invalid pointer` from inside `InlineSpiller` rather than diagnosing. `.local` now has a window per thread, the frame pointer is a window index, and predicates spill through O-19's `ld.pred`/`st.pred`** |
| F-47 `CCGWindowRemat` held raw pointers across recursive deletion | Step 5 | **resolved — two roots can share operands, so deleting one frees instructions still in the list. Use-after-free, surfaced as heap corruption in the GEMM (whose window chains share a launch-block load) and in nothing earlier, where the chains were disjoint** |
| F-48 Integer division uses a shift-subtract loop where a float reciprocal would do | Step 5 | open — measured against AMDGCN on `transpose`: ~35 instructions plus a loop of up to 32 iterations, against AMD's ~10 straight-line via `v_rcp_iflag_f32` and a Newton step. §4 has `fmul` and conversions at 128+, so the ISA is not the limitation; the compiler has simply not made the choice. Costs far more dynamically than the static count shows. See `benchmarks.md` |
| F-32 Cross-block window values crashed the type legalizer | Step 3 | **resolved — `CCGWindowRemat` clones the window chain into each using block before ISel, so the DAGCombine always sees it locally. Any kernel with control flow hit this; vadd escaped only by being one basic block. `test/accept/window-cross-block.ll`** |
| F-33 `ConstantFP` expanded to a constant-pool load | Step 4 | **resolved — there is no constant pool and no addressing mode for one; ConstantFP is Legal and the f48 wide immediate carries the bit pattern, so a float constant costs what an integer constant costs** |
| F-34 TableGen re-ran only for four of the seven `.td` files | Step 3 | **resolved — `CCGInstrPatterns.td` and `CCGCallingConv.td` were missing from CMake's `DEPENDS`, so pattern edits silently reused stale tables and TableGen's errors never reached the build log. Now globbed; `verify.sh` also runs `gen-dag-isel` and `gen-callingconv`, which it never did** |
| F-26 No branch-analysis hooks, so fall-through edges became real branches | Step 3 | resolved — `analyzeBranch`/`removeBranch`/`insertBranch`/`reverseBranchCondition`; the kernel went from 18 instructions to 17, matching §5.6 exactly |
| F-27 Unaligned pointer addressing is not implemented | Step 3 | **resolved — `matchBaseIdx` folds `roffset + (i << scale)` into one index register with scale-enable clear, trading O-7's scaling for the fourth addend. §5.5 is now generated from codegen, so O-23's "both shapes supported" is fact** |
| F-29 No compressed-form (Format K) selection path | Step 4 | **open — nothing in the backend tries to land `rd == rs0`. Two of three three-operand ALU ops in §5.5 satisfy it by accident and one does not, costing 16 bits on a 656-bit kernel. Matters in proportion to ALU density, so a GEMM inner loop is the measurement. Blocks O-8 instrumentation, which also does not exist** |
| F-28 `bra.short` (Format K, ±256 B) has no selection pattern | Step 4 | **resolved — not a pattern question: whether a branch fits is a property of the final layout, so the selector always emits the 16-bit form and `CCGAsmBackend` relaxes it to Format E's `bra` when it cannot reach. Neither direction shows in the `.s`, which prints `bra.short` either way, so `check-relaxation.py` asserts both against the objects. Teaching only the selector would have silently reintroduced F-26: `analyzeBranch` recognised one opcode as an unconditional branch, and the dead fall-through came straight back** |
| F-29 No compressed-form (Format K) selection path | Step 4 | **resolved — `CCGCompress` compresses what already satisfies `rd == rs0` and never inserts a copy to create it; O-29 records why the other half is deliberately left open. O-8 instrumentation now exists (`-ccg-compress-stats`): 2 of 3 on §5.5, 0 of 1 on the reduction, and 0 candidates on §5.6 because alignment already removed them. Too few to be a rate — Step 5's GEMM is where it means something** |
| F-25 Branch relocations | Step 3 | resolved — three fixup kinds; `bra.pred`'s split field scattered in `applyFixup` |
| F-19 Every compare is predicated; a kernel must manufacture a true predicate | Step 2 | resolved in v1.4 O-24, refined in v1.5 — self-guarding form costs one predicate, not two; regression test in `test/predicate-remat.s` |
| F-18 Two of the four GPR arguments are contingent on kernel-pointer alignment | Step 0 | resolved — per-argument attribute, v1.4 O-23; see `proposals/pointer-alignment.md`. Step 5 must report both shapes |
| F-13 Format G is several field layouts presented as one table | Step 1 | resolved in v1.4 — written out as four tables |
| F-14 Format B′/B″ move the predicate qualifier off `[29:27]` | Step 1 | resolved in v1.4 — O-22; checker now reports 0 deviations |
| F-15 Invariant 8 claims a shared J/K compressed geometry that does not exist | Step 1 | resolved in v1.4 |
| F-16 Invariant 8's "no exceptions" claim does not cover Format I | Step 1 | resolved in v1.4 — exclusions named |
| O-8 compressed-form density | Step 5 | instrumentation done (`-ccg-compress-stats`, O-29); the measurement that matters is the GEMM inner loop |
| O-9 compressed ld/st offset distribution | Step 1 instrumentation + Step 5 | not started |
| GPR count 16 vs. 32 | Step 5, both configurations | not started |
| Predicate count | Step 4; gated on F-2 | not started |
| O-4 `reconv.hint` join-PC pairing | Step 4 | not started |
| O-12 barrier phase-parity assumption | Step 4 (check against barrier spec) | not started |
