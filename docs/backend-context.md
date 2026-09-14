# Compiler Backend — Design Context

**Companion to:** `isa-v1.5-operation-map-and-encoding.md`
**Purpose:** Carries project context that the ISA spec doesn't capture — target
strategy, priorities, and the open items that specifically depend on compiler output.
Read this alongside the ISA spec, not instead of it; the spec is ground truth for
encoding, this file is ground truth for "why the backend is built the way it's built."

---

## 1. Project framing

**CCV — Custom CUDA Vector processing unit.** A CUDA-compatible VPU for AI/ML
workloads, personal project. Vector, not graphics: nothing in the ISA serves
rasterization, texture or fixed-function graphics, which is why the target was
renamed from `CCG` at the v1.5 audit. "GPU-class" describes the throughput
model — warps, per-thread PCs, a wide register file — not the workload.
Compatibility contract is at the **PTX / CUDA Runtime API level**, not the hardware
ISA level — the native ISA has no PTX/SASS encoding constraints. A purpose-built
compiler is the bridge, not a microcode translation layer.

Designer background: hardware engineer, deep expertise in CPU microarchitecture
(Intel/x86/AVX lineage), OoO execution, GPU programming models. Compiler-side
engagement is expected to stay at peer level — no need to over-explain standard
compiler concepts, register allocation theory, etc. Corrections should be direct
when a framing is wrong (e.g. SIMD vs. SIMT conflation), not softened.

**Success criterion for the compiler effort specifically:** a validated pipeline
that surfaces real issues in the ISA, expanded incrementally toward full CUDA
coverage. The compiler's job right now is to generate signal for ISA decisions,
not to be feature-complete.

---

## 2. Target strategy — decided

**Frontend:** do not write a CUDA parser from scratch. Use clang's existing CUDA
frontend to lower to LLVM IR. This is a solved problem upstream and reinventing it
has no payoff for this project.

**Backend:** custom LLVM backend (TableGen target description, instruction
selection, register allocation, scheduling) targeting the native ISA. This is
where the actual design work and ISA validation happens.

**Rationale:** the compatibility contract lives at the CUDA Runtime API / PTX
level, which is exactly the layer clang's CUDA frontend already targets. Writing
a backend, not a frontend, is the correct scope for this project.

---

## 3. Bootstrap priority — what "first pass" needs to prove

Full CUDA coverage is not the near-term goal. A minimal backend that lowers a
small set of representative kernels is enough to generate useful ISA signal:

- A GEMM tile (inner-loop accumulate pattern — exercises Format J `ffma.acc` /
  `dp4.acc` / `mad.acc`, and `packi`/`unpacki`)
- A reduction (exercises warp-collective Format G, barriers, predicates)
- A simple elementwise kernel at varying `chwidth` (exercises width-change
  drain behavior, Format B/B′ ladders, compressed Format K two-operand ops)

These three kernel shapes touch nearly every open item below. Prioritize getting
them through the pipeline end-to-end over broadening kernel coverage.

---

## 4. Open items where compiler output is the blocker

These are pulled from the ISA spec's §10/§11 open items, filtered to the ones
where compiler/backend behavior — not RTL or hardware design — is the missing
input. Backend work should be structured to produce this data as a side effect
of getting kernels through the pipeline, not as a separate measurement exercise.

**Status as of the v1.5 review.** Every item in this section that compiler output
could answer has been answered; what remains is listed at the end. The answers
live in the spec's §9 and in `docs/roadmap.md` Part 3 — this section records what
the question was and what the data said.

- **O-8 — Compressed-form density.** *Answered, and the answer was "not yet
  worth buying."* `-ccv-compress-stats` reports the hit rate: 2 of 3 candidates
  on §5.5, 0 of 1 on the reduction, and 13–22% across the GEMM tile sweep,
  **falling as register pressure rises** — the allocator lands `rd == rs0` less
  often when it has less freedom. So making destructive-form preference an
  explicit allocator objective would pay least exactly where code size matters
  most. O-29 records the decision: take what is free, do not buy the rest yet.
- **O-9 — Compressed load/store zero-offset assumption.** *Still open, and still
  for want of data.* Nothing in the benchmark set makes compressed-eligible
  loads with small nonzero offsets common enough to judge. Carried in §11 of the
  spec.
- **GPR count (16 vs. 32)** — *settled at 16 (O-25), and not by the spill data.*
  The widening does not survive the encoding: at 5-bit register fields Format J
  overruns 16 bits by three and Format A″ falls to a 1-bit opcode, so the
  compressed forms cannot address 32 registers and §6's density argument goes
  with them. The span/MMA tipping argument below is therefore moot — it was an
  argument about which way to resolve ambiguity, and there was no ambiguity to
  resolve. The GEMM sweep independently put the practical tile ceiling at 2×4,
  which is what §1 had guessed.
- **Predicate count (4)** — *still provisional, now with data.* Measured pressure
  is 1–2 of 4 across every kernel written, which is what made O-33's
  unconditional reservation of P3 affordable. A performance parameter, not a
  structural ceiling, since O-19 made the file spillable.
- **Reconvergence hint placement (O-4 residual risk)** — *still open.*
  `reconv.hint` is emitted and inert. The simulator confirms the property it
  exists to help: under divergence the issue mask narrows and returns to
  `ffffffff` at `exit` with no bracket instruction and no mask stack. Whether
  join-PC pairing would help a real scheduler is still a Phase 2 question.
- **O-14 — `unballot` (GPR mask → predicate).** *Resolved — added in v1.3*, at
  Format G point 9, and defined in `CCVInstrInfo.td`. The trigger this item
  described (a computed lane mask needing to become a predicate) arrived with
  predicate spilling, which O-19/O-30 route through `ld.pred`/`st.pred`.

**What compiler output has not yet answered**, and is the live list:

- **F-59** — §4's conversion scheme has no encoding for an integer source, so
  `cvt.f32.u32` has no slot in the spec's own scheme. Blocks F-56.
- **F-58** — `sel` spends the predicate qualifier field on data, so no `select`
  can be masked to lane 0. Larger than F-56 and with no cheap encoding fix.
- **F-52** — whether a warp-uniform register file or the cheaper uniform-operand
  encoding bit is worth it. O-33 bought the energy half of this; the issue-slot
  half needs one of the two.
- **F-3 / `chwidth`** — the mode-insertion pass is the one piece of Step 6 not
  started, so width-transition frequency and `chwidth.multi` hoisting
  effectiveness are still argued rather than measured.

---

## 5. Architecture context carried from earlier planning conversations

The ISA spec (`isa-v1.5-...md`) records *what* was settled. This section records
*why*, pulled from the planning conversations that preceded the encoding work.
Useful for the backend because several of these reasons directly bound on
codegen and register-allocation decisions, not just RTL.

### 5.1 Bring-up phasing

The original staged plan, for context on why the bootstrap kernel set in §3 is
scoped the way it is:

- **Phase 0 — Contract definition.** Freeze PTX version target, execution
  model, barrier semantics.
- **Phase 1 — Minimal viable subset.** Get a trivial kernel through the full
  pipeline (PTX → compiler → native ISA → execution) correctly. This phase
  validates the *pipeline*, not coverage — matches the framing in §3 above.
- **Phase 2 — Tiered opcode expansion.** Rank remaining PTX opcodes by
  frequency × implementation cost. Shared memory and sync primitives before
  warp-shuffle/vote; `wmma`/tensor ops deliberately last, since fragment
  layouts are undocumented upstream and that's reverse-engineering, not just
  coverage work.
- **Phase 3 — Resource-model fidelity.** Occupancy-calculator equivalent,
  register allocation limits, shared memory banking. Flagged explicitly
  because mismatches here cause *silent* failures (wrong occupancy, wrong
  performance) rather than compile errors — this needs its own validation
  harness, not just "does it compile and run."
- **Phase 4 — Ecosystem.** cuBLAS/cuDNN-equivalent library coverage.
  Kernel-level ISA compatibility alone doesn't move most real workloads —
  worth keeping in view as the actual finish line, even though it's far out.

### 5.2 Per-thread PC and reconvergence

Independent per-thread PC scheduling (ISA spec §1, divergence handling) means
PC and call-stack state are stored **per thread, not per warp** — this is the
actual hardware cost of the decision, not just a scheduling policy label. The
SIMT unit opportunistically groups threads with matching PCs for issue;
nothing forces convergence.

**Follow-on decision, not yet in the ISA doc's rationale:** no explicit
reconvergence instruction or bracket (no SASS-style `BSSY`/`BSYNC`) is needed.
Correctness doesn't depend on compiler-marked reconvergence points — each
thread simply follows its own PC, and threads that happen to land on the same
PC are naturally eligible to reconverge. This is close to Nvidia's own
Volta+ independent thread scheduling, where correctness doesn't depend on
explicit reconvergence points either.

**What's given up is purely a performance opportunity, not correctness.**
Without a compiler-supplied signal about *where* reconvergence is likely, the
hardware can only reconverge opportunistically — a pathological case (threads
diverge, could reconverge at a loop backedge, but drift out of PC alignment
due to scheduling order) is correct but can serialize where a hint-aware
scheduler would have reconverged sooner. **This is precisely the gap
`reconv.hint` (Format K, ISA spec §3/§7 O-4) exists to mitigate** — worth
stating explicitly since the ISA doc specifies the hint's operand shape
without restating why the hint is needed at all.

### 5.3 Atomics — why they run on the normal ALU

The ISA spec states atomics execute in the normal ALU using the existing load
and store buffers as settled (Format M/M′). The reasoning behind it is a real
reversal worth keeping:

Initial direction favored **memory-side** atomic execution, on two arguments:
power (avoid round-tripping operands to the core) and contention (memory-side
execution can serialize same-address accesses more cheaply than sending every
contender to a core to fight over the line).

That direction was **abandoned** once it became clear that speculative
execution already requires the load buffer, forwarding, and disambiguation
logic to sit at the execution units for correctness — meaning the operand
round-trip the memory-side design was trying to avoid happens regardless of
where the arithmetic nominally lives. The power argument evaporates. The
contention argument partially survives, but it turns out to be a property of
the **exclusive-ownership coherence protocol**, not of where the RMW's
arithmetic executes — the same serialization benefit holds even with the ALU
op running in the core.

**Final model:** atomics execute in the core's existing ALU, single ROB entry,
using the existing load buffer (with an exclusive-ownership request) and store
buffer (commit-at-retirement) — no dedicated memory-side atomic unit, no new
functional unit. This is why atomics required no new hardware, which the ISA
doc records as settled without the "why."

**Deferred, not settled:** speculative exclusive-ownership contention/
arbitration between concurrent atomics (also listed in ISA spec §10) — the
correctness mechanism is settled, the arbitration policy under contention is
not.

### 5.4 Upper-lane utilization: split register allocation + hybrid coalescing

This is the mechanism behind "hybrid TLP/ILP coalescing" (ISA spec §1/§10),
with a register-file consequence not yet written into the ISA doc.

**Why hybrid, specifically, and not a fixed packing factor tied to SMT
width:** tying the coalescing candidate pool to SMT width was explicitly
rejected — SMT-8 (needed for 8-way INT4 packing at SMT-4 active-tier width)
was judged too messy, and a hard linkage between SMT width and packing factor
would break if warp width later grows (e.g. 32 → 64). Hybrid coalescing avoids
this because it doesn't need a *fixed* number of simultaneous candidates from
any one pool — thread-level parallelism (TLP, across warps) and
instruction-level parallelism (ILP, within one warp's issue window) backfill
each other. If TLP supply is short, ILP fills the gap, and vice versa. This is
architecturally decoupled from SMT-4 by design, not just deferred.

**Register-file consequence:** to keep the 1024-bit physical datapath
efficiently filled under packed/narrow execution, a physical register row
needs a **subdivision allocation scheme** — allocatable whole for full-width
operands, or carved into N same-width logical-register slices for packed
narrow operands. Allocation should **prefer co-locating same-packing-factor
slices into shared rows**, to avoid fragmentation that would otherwise degrade
full-width operation performance (a stray narrow allocation shouldn't strand
the rest of a row). This means a rename-table entry for a narrow logical
register has to carry not just a physical row ID but **which slice of that
row** — structurally a buddy/slab-allocator problem, not a flat
register-to-register mapping. This is the physical-allocation mechanism behind
the ISA spec's invariant 6 (sub-row allocation never couples retirement) and
invariant 9 (packing lives in an instruction, never a register) — those
invariants describe the *architectural* guarantee; this is the *allocator*
mechanism that has to deliver it underneath.

Not yet a compiler concern directly — the width field already carried in the
ISA (via `chwidth`) is sufficient signal for the allocator/coalescer; no
additional compiler-visible hint is needed for this mechanism specifically.
Flagged here because it's exactly the kind of thing a spill/allocation
experiment in the backend (§4 above) could accidentally reason about
incorrectly if the backend author assumes a flat register file.

---

## 6. Explicitly not the compiler's job right now

Carried from the ISA spec's "out of scope for V1" list, restated here so the
backend doesn't accidentally scope-creep into designing around them:

- Span / multi-register transfers (`.v2`/`.v4`) — deferred at the ISA level.
- Format H (tensor/MMA) — undesigned; don't build codegen paths anticipating it.
- FP packed dot-product — `dp4`/`dp8` are integer-only for V1.
- Compressed predicated forms — deliberately excluded from the encoding.

If backend work surfaces a strong case for revisiting any of these, that's ISA
spec discussion, not something to route around in codegen.

---

## 7. How to use this file

- Keep this file and the ISA spec doc in the repo (e.g. `docs/`) so both are
  on disk for Claude Code to reference directly.
- Update §4 as open items get resolved or new ones surface from backend work —
  this file should track compiler-relevant decisions the way the ISA spec's
  §9 decision log tracks encoding decisions.
- This file assumes familiarity with the ISA spec; it doesn't restate encoding
  details, only the context around why the backend is being built this way.
