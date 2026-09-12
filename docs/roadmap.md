# Bring-up Roadmap and Compiler-Side ISA Findings

**Status:** Phase 0 (contract definition). No code yet.
**Companions:** `isa-v1.2-operation-map-and-encoding.md` (encoding ground truth),
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

**Exit criterion: met.** The remaining items are ISA-spec edits and an ABI
document, neither of which blocks Step 1.

### Step 1 — Machine description and MC layer

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

**Exit criterion:** hand-written assembly for all 20 formats assembles,
disassembles, and round-trips.

### Step 2 — Functional simulator

Per F-6. Consumes the generated decoder. Enough to execute a warp of 32 lanes
with the memory spaces, barriers and predicates the bootstrap kernels need.

**Exit criterion:** hand-written assembly kernels execute and produce correct
results.

### Step 3 — Instruction selection, elementwise kernel at 32-bit width

The Phase 1 pipeline validator. Fixed width throughout — no `chwidth`
transitions, so none of F-3 is needed yet.

**Exit criterion:** a CUDA elementwise kernel compiled from source through
clang, through the backend, executed on the simulator, correct result.
This is the `backend-context.md` §5.1 Phase 1 milestone.

### Step 4 — Reduction kernel

Adds control flow, Format G shuffles, barriers, predication, and `reconv.hint`
emission. First real exercise of the predicate file — where F-2 gets tested
against practice rather than argument.

**Produces:** first data on predicate pressure; real `reconv.hint` placement,
which opens the O-4 join-PC question.

### Step 5 — GEMM tile

Adds shared memory, Format J accumulate, and serious register pressure.

**Produces:** the spill data that decides 16 vs. 32 GPRs (O-8's companion
question in §10), and the destructive-form hit rate for O-8. Run both subtarget
configurations — the whole point of building the flag in at Step 1.

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
| F-9 Format D carries two contradictory opcode maps (editorial) | — | **open — second map is stale, should be deleted** |
| O-8 compressed-form density | Step 1 instrumentation + Step 5 | not started |
| O-9 compressed ld/st offset distribution | Step 1 instrumentation + Step 5 | not started |
| GPR count 16 vs. 32 | Step 5, both configurations | not started |
| Predicate count | Step 4; gated on F-2 | not started |
| O-4 `reconv.hint` join-PC pairing | Step 4 | not started |
| O-12 barrier phase-parity assumption | Step 4 (check against barrier spec) | not started |
