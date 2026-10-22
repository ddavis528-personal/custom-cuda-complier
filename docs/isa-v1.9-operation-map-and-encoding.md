# CCV Native ISA — Operation Map and Encoding

**Version 1.9** · 20 October 2026

**CCV — Custom CUDA Vector processing unit.** A VPU, not a GPU: the machine is a
data-parallel compute engine and nothing in this document serves rasterization, texture or
any other fixed-function graphics work. Revisions up to 1.4 named no machine at all, and the
backend carried a working name of `CCG` whose "G" was never written down anywhere and did
not survive being asked about.

The compatibility contract is at the PTX / CUDA Runtime API level, so this ISA carries no
PTX or SASS encoding constraints. A purpose-built CUDA compiler is the bridge.

All bit maps in §3 have been checked for field-width mismatch, overlap and gaps, and are
checked mechanically rather than by reading. One parameter remains provisional — the
predicate count — and is marked as such in §1. §9 is the decision log recording what was
settled and why; §10 and §11 hold what is out of scope and what is deferred.

**§1a states four obligations this specification places on the implementation** and cannot
check from the compiler side. One of them is a security requirement. Read that section
before building anything.

---

## Changes since 1.8

**1.8 is frozen** at its content of 20 October 2026, including the amendments it took after its
first cut. Changes through 1.8 are recorded there. This revision adopts the **fault model**,
IS-2, now that DA's one sub-question is answered. No encoding changes: every bit map, opcode
point and format tag is as 1.8 left it. What changes is that every encoding, and every
encoding meeting architectural state, now has defined behaviour.

### The fault model is adopted (O-57; IS-2)

**Invariant 12 is new and invariant 3 is amended.** Every encoding, and every combination of
an encoding with architectural state, gives a result or a defined fault; nothing is undefined.
§12 is the fault model: four detection stages, nine causes, precise faults taken at
retirement, a sticky per-context record, and containment between contexts per O-38. It is
`fault-model-spec.md` as adopted, with four corrections made since that document was written:

- **A fatal fault terminates the context, not the grid** (DA's response IS-2, 2026-10-20, on
  AR's recommendation). Grid scope could turn a fault into a host sync hang, and CUDA
  discards a context after a sticky error anyway.
- **Replayable faults need no stream-tagged squash** (OA's IS-4 response). Squash is
  contiguous in ROB order, and the fault model's claim to the contrary is struck.
- **Its open questions on alignment and `.const` are answered**: natural alignment with
  `F-ALIGN` (IS-1), and `.const` faulting with `F-RO` (O-51, in 1.8).
- **Its statement of FP exceptions follows O-56**: subnormals are kept, never flushed, and the
  narrow formats saturate.

**Applied through the document.** Every field, bit, opcode point and value marked reserved is
reserved and must be zero: using one raises `F-ILLEGAL` (§3's preamble states this once for
every table). O-37's long form with `opcode[9:7]` = `000` raises `F-ILLEGAL`. A memory access
at `chwidth`=4 raises `F-WIDTH`. A format code reserved at its register's width raises
`F-FORMAT`. Execute-stage faults are raised only for lanes in issue mask ∩ predicate, which is
the rule bounds-guarded loads depend on. A misaligned or out-of-image PC, including a `ret` to
an odd offset, raises `F-FETCH`.

### Natural alignment is required (O-58; IS-1)

A lane's effective address must be a multiple of its transfer size: 4 bytes at `chwidth`=32,
2 at 16, any at 8. A violation raises `F-ALIGN` per lane. Agreed in substance on 2026-10-04 and
blocked only on the fault model, which this revision adopts.

### Two results defined that were not

`rcp.u32` with a zero divisor returns `0xFFFFFFFF` (IS-12 (d), agreed by CP). A conversion or
FP operation on a code reserved at its width faults rather than computing.

### The fault model's remaining questions, closed (IS-16)

**Entry register state is defined**: every GPR reads zero, every predicate false, every
`chwidth` 32, at no cost (§5.2). **A CTA has at most 16 barriers** (O-59): IDs 16–63 raise
`F-ILLEGAL`, and an ID past the CTA's allocation raises a ninth cause, `F-BARRIER`, at dispatch.

### Forward progress between diverged lanes is guaranteed (O-60; IS-17)

§1 now states the per-thread PC model it was always citing. It also states CUDA's guarantee
since Volta: every PC group of a live warp that is not waiting at a barrier eventually issues.
DA decided it on 2026-10-21. It binds the implementation, not the encoding. A scheduler needs a
fairness rule beside min-PC, and room for one PC per lane, so a split never waits on a merge.

### A module's data has a home (O-61; CP-10)

A module's globals live in one data image, which the runtime loads once per module and
context. Its window index is launch-block word 28 (§5.2). Its constant part is the `.const`
range of O-51, and only data pointers inside it are relocated. No instruction or encoding
changes.

### An instruction writes only its own group's lanes (O-62, O-63; CP-11, IS-18)

Invariant 10 now covers lanes outside the issue mask, not only lanes the guard excludes. The
case that raised it is `ld.pred`, which writes only the issuing group's bits of each
predicate. `st.pred` likewise stores only those bits, merged into memory's word (O-63). So a
predicate spill slot is per-lane storage, and diverged groups can share it.

### Still open

SFU accuracy is ruled under IS-12, but its PTX bound table is not yet written.

---

## 1. Settled parameters this encoding assumes

| Parameter | Value | Confidence |
|---|---|---|
| Logical GPRs | 16 (`R0`–`R15`), 4-bit field | **settled** — see the note below and O-25 |
| Logical predicates | 4 (`P0`–`P3`) | provisional, pending compiler data |
| Address width | 48 bits | settled |
| Effective address | `(rbase << 16) + roffset`, `.global` only | settled |
| Base shift `S` | 16 | settled |
| Predicate qualifier field | 3 bits (2-bit address + 1 negate) | settled |
| Predicate destination field | 2 bits (no negate — write side) | settled |
| Max GPR sources | 3, all independent of dest | settled |
| Element width | per-register state via `chwidth`, **not** an instruction field | settled |
| Width codes | `00`=32b, `01`=16b, `10`=8b, `11`=4b | settled |
| FP format | per-instruction, folded into opcode space | settled |
| Warp width | 32 lanes | settled |
| Instruction length | 16 / 32 / 48 bits, 16-bit granular | settled |

**On the GPR count — settled at 16.** Previously marked provisional pending compiler spill
data. It is no longer: the cost of changing it is now known precisely, and three of the four
arguments that pointed at 32 have been retired or dissolved by decisions taken since. See
O-25 for the full record.

**Widening the register field from 4 to 5 bits is a reset, not a parameter change:**

| Format | opcode bits at 4-bit fields | at 5-bit fields |
|---|---|---|
| A | 10 | 6 |
| A′ | 7 | 3 |
| A″ | 5 | **1** |
| K, reg-reg | 6 | 4 |
| J | (2-bit subop, no opcode) | **overruns 16 bits by 3** |

Format J carries three register fields in the twelve bits left after the class code and
subop; at five bits each that is nineteen bits in a sixteen-bit instruction. It does not
shrink, it ceases to exist. Format A″ falls to two opcode points against the thirty-two it
needs, and Format A's map already allocates 194 points into a space that would drop to 64.
Recovering all of that means a second compressed encoding over a 16-register subset, plus
relocating conversions and SFU into a 48-bit Format A form — three coordinated changes, not
one field widening.

**And the case for paying that has weakened.** Of the four arguments previously recorded
here:

1. *Span/MMA fragment groups leave only four legal aligned quads.* **Retired.** That is an
   artifact of naming a register group with a single field. Format H is undesigned and will
   be 48 or 64 bits; at that length it can list four 4-bit operands explicitly — sixteen bits
   total, no alignment constraint. The limit exists only if H inherits span-style group
   naming, and nothing requires it to.
2. *Soft width partitioning of the file.* **Survives, weakened.** `chwidth.multi` collapses a
   block transition into one drain, and in the shapes that matter the partition is static —
   FP16 inputs with FP32 accumulators never transition inside the loop. It binds on kernels
   needing three or more live widths at once, not on any two-width kernel.
3. *Two GPRs per live pointer.* **Dissolved by O-23 and O-45.** O-23 made an aligned pointer
   one register, and O-45's launch-slot form takes the window base out of the file entirely:
   in §5.5 and §5.6 no pointer base occupies a GPR, and the unaligned form holds only its
   folded in-window offset, and only until its access.
4. *8 of 16 live in the elementwise prologue.* **Retired — the measurement was wrong.**
   That figure came from a hand-written listing that held all six pointer halves live at
   once. Real codegen peaks at **4 of 16 unaligned and 3 of 16 aligned** (§5.5, §5.6), since
   no pointer base occupies a register at all under O-45. Neither number is evidence of
   pressure. *(1.7 said 5 and 4, figures from before the slot form that the prose kept
   after the generated listings moved on; corrected in 1.8.)*

**The one live risk is GEMM accumulator blocking**, and it is not addressed by any of the
above. Register-tile size drives register count on every GPU: a 4×4 per-thread C tile is 16
accumulators, the whole file, before pointers or indices. At 16 GPRs the practical ceiling is
roughly 2×2 or 2×4, which lowers arithmetic intensity and raises shared-memory traffic per
FLOP. Two things help that do not help an in-order GPU — OoO execution plus warp residency
tolerate lower arithmetic intensity, and `dp4.acc` performs four MACs per accumulator
register at INT8. **FP32 accumulation gets neither**, and is the case to measure.

**If that measurement comes back bad, the response is not more GPRs.** It is a small
**warp-uniform register file**. Bases, strides, loop bounds and everything read from the
launch block are warp-invariant and currently occupy full 1024-bit rows to hold 32 bits of
real information; a 16-entry uniform file is 512 bits per warp against roughly 16 KB for the
GPRs. It is additive rather than a reset: it reuses the existing **4-bit field width** under
a different namespace, so every settled encoding holds, the compressed forms are untouched,
and Format J still fits. `rbase` in Formats D/D′/M becomes a uniform-file address, for which
there is already precedent — `ld.pred`/`st.pred` require `rbase` to be warp-uniform (§3).
The cost is its own moves and loads plus a uniform-destination ALU path, essentially AMD's
SALU: Phase-2-shaped work that invalidates nothing specified here. See O-25.

**A logical GPR always holds 32 lanes.** At `chwidth`=32 that is 32×32 = 1024 bits; at
`chwidth`=8 it is 32×8 = 256 bits. Narrow registers occupy a **narrower physical slice of a
row**, they do not pack more elements into a lane. Narrow throughput comes from
**sections**: each lane's 32-bit datapath divides into four byte-position sections, and narrow
operations whose footprints are disjoint co-issue in them, from one warp or from several
(§1a obligation 4, O-48). No single instruction is widened, and no physical row is shared
between warps. Memory access is at least 8 bits (a 4-bit access raises `F-WIDTH`, §12): 4-bit data lives in memory packed two
elements per byte and enters and leaves registers through `unpacki` / `packi`. Consequences
that follow throughout this document:

- **A predicate register is 32 bits — one bit per lane — at every width.** Predicates do not
  narrow with `chwidth` and have no internal structure to address.
- **Widening a register clears the bits the widening exposes.** A `chwidth` to a wider
  element zero-fills the part of the row slice that was outside the old element. This is a
  **security requirement**, not a convenience: the register file is partitioned between
  resident warps and reused across kernel launches, so bits left over from whatever last
  occupied that slice are another warp's data or the previous kernel's. See O-38.
- **No register has sub-lane structure.** A register's elements are one per lane, always.
  Three instructions do address positions inside a lane — `packi`, `unpacki` and `dp4`/`dp8`
  — but they do so from an opcode or an immediate, on ordinary full-width registers. The
  sub-lane view exists for the duration of the instruction and is invisible to allocation,
  renaming, predicates and shuffles. That is the line: **packing may live in an instruction,
  never in a register.**

**Per-thread PCs, and forward progress between them — normative (O-60).** Every lane has its
own PC. Lanes at one PC issue together as a **PC group**. A branch whose lanes disagree splits
its group, and groups that reach one PC may merge. That is opportunistic reconvergence, never
guaranteed (O-33 as amended, CP-2). Up to 32 groups may exist, one per lane, and the ISA sets no
smaller limit: a `ret` with a different `rs` in each lane (§3 Format E), or five nested
data-dependent branches, reaches 32 in ordinary code. **Forward progress is guaranteed between
groups: every PC group of a live warp that is not waiting at a barrier (`bar.wait`,
`bar.wait.phase`) eventually issues, whatever the warp's other groups do.** This is CUDA's
guarantee since Volta's independent thread scheduling. Intra-warp locks, spin-waits and
producer–consumer code depend on it.

The guarantee is the ISA's; the mechanism is the implementation's. Two natural mechanisms do
not meet it alone. Always issuing the lowest-PC group fails, because a group spinning at a lower
PC starves the higher one it waits for. Holding a divergent branch until groups merge also
fails, because the held lanes may be the ones the others wait for. So an implementation needs a
fairness rule with a bound on how long a ready group can be passed over, and room for a PC per
lane, so no split ever waits. Every lane's PC lies in the warp's one 4 GiB code window (§3
Format E) and is 16-bit granular, so a per-lane PC needs 31 stored bits, not 48. The ISA
promises no particular schedule. The bound need not be small or fixed, only finite.

**No hardwired always-true predicate.** With only 4 logical predicates and no `PT`
equivalent, an unpredicated instruction cannot be expressed as "predicated on true."
Every predicated operation therefore requires a distinct unpredicated encoding. This is
the structural reason the A/A′/A″ and B/B′/B″ ladders, and the D/D′ pair, exist as separate
formats rather than one format with an optional field.

---

## 1a. Obligations on the implementation

Four properties the compiler depends on, emits code against, and **cannot verify**. They
were scattered across the decision log; they are collected here because a reader
building the machine needs all four and will not find them by reading §3.

They are not the same kind of obligation, and the difference matters more than the list.

### 1. A predicated-off lane must not switch (O-33)

> A lane excluded by the predicate qualifier must not toggle its ALU or its ALU operand
> registers. Its result is the merge value passed through, never computed.

**What rename costs, and the obligation does not ask (IS-10).** Through 1.7 this read "its
ALU operands, its register-file write port, or its result bus". On a renamed machine that
cannot hold: a predicated write targets a fresh physical register, so an inactive lane's old
value must reach it. In the core it crosses the lane both ways — in as the fourth operand on
`ccv_rcu_lane_ops`, back as the result on `ccv_lane_rcu_res` — and the register file writes it
(A-33, A-44, A-51). So the operand and result buses and the write port carry the merge value
in masked lanes, and O-33's saving is the ALU's, not theirs. OA's IS-10 response rules out
the cheaper forms under rename. A write-back merge in RCU, re-reading the old destination as
predicates already do, would keep the merge value off both lane buses at a PRF read per write;
that is a perf-register candidate for AR and RCU, not a first-build change.

`ccv-mask-uniform` runs warp-uniform work on lane 0 and broadcasts the result, which cut
lane-activations by 14% and 21.5% on the two kernels O-33 measures. Those are ALU lane-activations; they do not count the merge traffic below. Gating only the *write* is
not enough: the extra issued lane slots buy nothing and the whole saving collapses into a
code-size regression.

**Its reach is narrower than 1.7 implied (O-33 as amended, CP-2).** The broadcast is sound
only where lane 0 *co-issues* with the lanes that read its result, and per-thread PCs with
opportunistic reconvergence do not guarantee that after a divergent branch, even when every
lane eventually reaches the block. So the compiler masks nothing after a divergent branch
unless a barrier intervenes. In a kernel with an early-exit guard that is the whole body, so
the saving above is available only to kernels without one, or before the guard. No mechanism
recovers the rest; O-33 records why.

**Cost if wrong:** the benefit, and a few instructions per kernel. Detectable in silicon by
measuring; not detectable from here.

### 2. Predicate-file logic must be much cheaper than warp-wide logic (F-58)

> `pand`/`por`/`pxor` must cost far less than an instruction that drives the vector
> datapath.

A predicate is 32 bits, one per lane (invariant 5), so `pand` is 32 AND gates against 32
lanes of 32-bit datapath and the ratio should be about the width of a lane. The compiler
spends one `pand` per guarded value to mask instructions that already carry a control-flow
predicate. If predicate logic runs through the vector path instead, that is a loss of a few
instructions per kernel.

**Cost if wrong:** one optimisation, withdrawn by `-ccv-mask-compose=false` without
touching anything else.

### 3. Widening a register must clear the bits it exposes (O-38)

> A `chwidth` to a wider element zero-fills the part of the row slice that was outside the
> old element. **And every write to a `chwidth`=4 destination leaves bits `[7:4]` of its
> section zero, whatever the arithmetic produced** — lane results, RCU results and load data
> alike.

**This one is not a performance assumption.** §1 makes a narrow register a narrower physical
slice of a row, so the bits above the element hold whatever last occupied that slice — and
the register file is partitioned between resident warps and reused across kernel launches
without being scrubbed. Handing those bits back on a width change is a cross-context read of
another warp's data or the previous kernel's, through an ordinary unprivileged instruction.

A machine that skips the clear is not slower. It leaks.

**Why the second sentence is not implied by the first (O-49).** A `chwidth`=4 register
occupies a full 8-bit section with its upper nibble zeroed at allocation (OI-29). Zeroing at
allocation is not sufficient. A 4-bit element is four bits and its arithmetic wraps there, so
an `add` that overflows four bits would otherwise leave its carry in bits `[7:4]`, and a later
widening to `chwidth`=8 would read that carry as data. The widening clear does not fire: no
slice is gained, only the interpretation widens. So the obligation is on the **write path**,
not the allocation path — the same class of exposure as O-38 and not the same case. It is
discharged in the lane at write-back, from the 2-bit width code carried per operand. That
code must be the width encoding over {4, 8, 16, 32} and **not** a section count: a section
count merges 4 into 8 and loses exactly the distinction the mask exists to preserve. Load
data is moot, because memory access is at least 8 bits (§1).

**Cost if wrong:** an information-disclosure channel between mutually distrusting contexts
on the same device, and a compiler that has been emitting zero-extensions which are not.

### 4. Narrow element work must retire at a multiple of the 32-bit rate (O-40)

> Each lane's 32-bit datapath divides into four independently controlled **sections**, one
> per byte position. A narrow operation claims a **footprint** — the union of its operands'
> sections, widened to its execution unit's minimum — and operations whose footprints are
> disjoint co-issue. **Across the resident warps**, 16-bit element work therefore retires at
> **twice** the 32-bit rate and 8-bit at **four times**; 4-bit also at four times, because a
> `chwidth`=4 register occupies a full 8-bit section (OI-29, with 8× deferred).
>
> **The multiple is aggregate across warps, not a per-stream guarantee.** Under the decided
> defaults a single instruction stream never sees it, on either the ALU or the memory path:
> memops stay in program order per warp at one a cycle (OA-13, deferred to PF-28), and a
> warp's narrow destinations default to its own home section (DA, 2026-10-09), so one warp's
> narrow operations contend for one section rather than spreading across four. `vadd16` at
> one resident warp is **1.0×, by design**. The rate comes from four warps occupying four
> sections, which is what home = tier-1 slot index arranges.
>
> **The multiple is general across element types.** Integer and floating point reach it
> alike: every execution unit but the SFU has a one-section minimum footprint, so E4M3 and
> E5M2 at `chwidth`=8, and E2M1 at `chwidth`=4, reach 4× on the same terms as INT8 (DA's
> response IS-7, 2026-10-09). The SFU's minimum is four sections.

**The first build meets a measured rate, not the ladder (DA's response OA-19, 2026-10-20).**
The ladder above is the obligation's target and stays the target. What the first build is
held to is what the OOE model measured at four resident warps under the decided default,
home section = tier-1 slot index, with select's section-only fallback pick: **2.40× at 8 bits
and 1.59× at 16**, counted as narrow element-work operations retired per cycle against the
32-bit rate (OI's IS-9 run). Daniel's words, accepting the rate: "Let's go with (a) for our
first build and put all other options on our future features register to evaluate later";
and on the 16-bit figure: "Yes, 1.59/2 is an acceptable utilization ratio for a first
implementation." (DA's responses OA-19, 2026-10-20.) An aligned-half fallback reaches 1.90×
at 16 bits but synthesises at 26.8 NGD against the 25 stage; it is PF-38 on the perf register. The gap at 8 bits has one main
cause: one home section per warp leaves select without ready narrow work in the other three.
The remedies are on the perf register, not in this revision: compiler-declared register
positions (OI-35, PF-29), whose encoding has a home in `chwidth`'s spare bits, and a
warp-uniform register file with a loop-uniformization transform (CP-7), worth at most 1.28×.
*(Earlier revisions stated the ladder as what the hardware delivers. IS-9 measured it, the
default fell short, and the decision was to accept the measured rate rather than build more
for the first silicon.)*

This is the whole reason the element-width model exists. Invariant 1 makes width per-register
state rather than an opcode field precisely so that a narrow instruction is the *same*
instruction against a *narrower slice*, which is what lets two of them share a 32-bit
allocation. Without the higher retire rate the narrow forms are pure cost: they add `chwidth`
transitions and save nothing an instruction count can see.

**What co-issues, precisely.** Sections are shared by every resident warp at select, so
narrow operations from *different* warps co-issue in different sections, and operations from
*one* warp co-issue when their footprints are disjoint. Registers are warp-private: while any
section of a row is live the row belongs to one tier-1 slot, so narrow registers never share a
row across warps. Earlier revisions had the allocator packing narrow registers from different
warps into one physical row — that is the part OI-29 removes. The
several-independent-streams claim is not, and co-issue by disjoint lane *masks* is a separate
future feature (PF-26), not this.

**A section is a byte position within each lane's 32-bit word.** In-lane byte routing —
selecting an operand from its own section, steering a result to its destination's — is part of
an operation's execution and costs no instruction. Moving data *between lanes* is an unrelated
mechanism: it takes an explicit warp-collective instruction, executed in RCU. **Invariant 9
depends on these two staying distinct.** Where older material says "cross-lane move" in a
width context, read "cross-section".

**The cost of bad placement is footprint width, not inserted work.** An operation whose source
sits in S0 and destination in S2 claims two sections and blocks a co-issuer from both. This is
the failure mode to watch, because nothing fails: every operation issues, no moves appear, and
only the idle-section count moves. The measurement is therefore mean sections claimed per
narrow operation — target 1.0 at 8 bits — and idle sections per cycle, reported **per bypass
group** (OI-34).

**This obligation is measured against, and the margin is thin.** `vadd16` — the benchmark's
16-bit kernel — issues 18 instructions against `vadd`'s 16, of which **4 are narrow element
work**. At a 2× retire rate that is 14 + 4/2 = **16 cycles, exactly break-even**. At 1.5× it
is a loss. The ISA is asking for 2× and getting no margin at the fraction today's codegen
produces.

Two consequences a reader building the machine should take from that:

- **The narrow work is mostly memory, not ALU.** Of `vadd16`'s four narrow instructions,
  **one is an ALU operation and three are loads and stores**. If the split allocation dual-
  issues in the ALU but not the memory pipe, the kernel comes out at 17.5 cycles — *slower*
  than the 32-bit version. The obligation is on the memory path first.

  **Resolved.** MIU becomes four resources P0–P3 under the same footprint scheme, so a
  memop's footprint is four pipes at 32 bits, two at 16 and one at 8, and narrow memory
  co-issues exactly as narrow ALU work does (OI-33). The 17.5-cycle regression does not occur.
  The warning stays because it is the reason the memory path was sized that way: a future
  change to MIU's grant count re-opens it, and at one grant per cycle the regression returns
  in full.
- **The break-even is a codegen property, and the only lever is the non-element work.**
  A lane holds one element at every width (invariant 1), so a narrow kernel issues exactly
  as many element-work instructions as its 32-bit twin — the fraction rises only by removing
  what is *not* element work. Width transitions the compiler did not need (F-80, F-87) and
  per-thread prologue are the whole of it. `vadd16` at one element per thread reaches 0.286
  and is 1.067×; `vadd16_loop`, where the prologue amortizes over eight elements, reaches
  0.552 and 1.283×. Same instructions, same retire rate, different ratio of element work to
  overhead.

  **And the rate it is measured against is the achieved rate, not the ceiling.** The ladder
  above is what the hardware can do when footprints are one section wide. What a kernel gets
  is that ceiling divided by its mean footprint width, so a kernel with a 2.0 mean footprint
  at 8 bits runs at the 16-bit rate however narrow its data is. Obligation 4 is met only if
  the sweep shows footprints near 1.0.

  It does **not** rise by packing two elements into a lane. That is the register-level
  packing model O-13 rejected and this invariant forbids, and it is worth naming here
  because the arithmetic above makes it tempting: halving the lane count would halve the
  issue count directly. It would also put two elements in a register, which is the warning
  sign §9 names rather than the optimisation it looks like.

**Cost if wrong:** the element-width model is a net loss on every kernel, and the `chwidth`
machinery is overhead with no return. This is the one obligation on the list that the whole
feature rests on rather than one optimisation.

---

## 2. Instruction header

Length is decodable from bits `[1:0]` alone, before any format decode.

### Length / class field — bits `[1:0]`

| Code | Meaning |
|---|---|
| `00` | **32-bit** — format tag in `[5:2]` |
| `01` | **16-bit compressed, group 0** (Format J) — payload in `[15:2]` |
| `10` | **16-bit compressed, group 1** (Format K) — payload in `[15:2]` |
| `11` | **48-bit** — format tag in `[5:2]`, same position as 32-bit |

There is no separate sub-length field. 48 bits is the only long form; anything wider is
reached through tag `1111`, which carries its own length in `[9:6]`. Instruction length is
therefore always determined inside the **first halfword**: bits `[1:0]` in every case, plus
`[9:6]` in the one extended case.

**The format tag sits at `[5:2]` regardless of length**, and a 48-bit instruction carries
**the same tag as its 32-bit sibling**. Tag `0011` means "B family, register-immediate" at
either length; only bits `[1:0]` differ, and they say how wide the immediate is. Format
decode is therefore length-independent — the tag decoder does not care, and neither does
anything downstream of it except the immediate's sign-extension mux.

The consequence that matters: **a 48-bit instruction is its 32-bit sibling with 16 more
bits at `[47:32]`.** Those bits carry an immediate in B, B′, B″, C′, D, D′ and F, and an
opcode extension in A′ (O-37) — the rule is about the halfword, not about what goes in it.
Bits `[31:6]` are laid out identically. Every register field, the opcode, the predicate
qualifier and the predicate destination stay exactly where they are in the 32-bit form, so
invariant 8 holds across lengths and not just across tiers.

Compressed forms still get 14 bits of payload. Spending a full quarter of the low-2-bit
space on the 48-bit form (rather than the RISC-V polarity, which gives compressed forms
three of four codes) remains the right trade: the 32-bit formats are mostly exact-fit, and
several of them have no slack at all.

### Format tag — bits `[5:2]`, all lengths

| Code | Format | Description |
|---|---|---|
| `0000` | A | ALU register-register |
| `0001` | A′ | ALU reg-reg, predicated |
| `0010` | A″ | ALU reg-reg, predicated + predicate-dest |
| `0011` | B | ALU register-immediate |
| `0100` | B′ | ALU reg-imm, predicated |
| `0101` | B″ | ALU reg-imm, predicated + predicate-dest |
| `0110` | C | Compare, register-register |
| `0111` | C′ | Compare, register-immediate |
| `1000` | D | Load / store |
| `1001` | M | Atomic (RMW and CAS) |
| `1010` | E | Control flow, barrier, fence |
| `1011` | F | Wide immediate |
| `1100` | G | Warp-collective (predicated forms; unpredicated live in K) |
| `1101` | D′ | Load / store, predicated |
| `1110` | I | Register / predicate metadata (`chwidth.multi`, `pmov`) |
| `1111` | C″ / H | **32-bit: unpredicated compare (O-32)**; 48-bit: escape / tensor, reserved |

**Which tags have which lengths:**

| Tag | 32-bit | 48-bit |
|---|---|---|
| `0000` | A | — (already carries the full 10-bit opcode) |
| `0001` | A′ | **A′ long** — opcode extension, not an immediate (O-37) |
| `0010` | A″ | — (reaches 0–31, which is where its subset lives) |
| `0011`–`0101` | B / B′ / B″ | wide-immediate siblings |
| `0110` | C | — |
| `0111` | C′ | wide-immediate sibling |
| `1000` | D | wide-offset sibling |
| `1001` | M (RMW) | M′ (CAS) — opcode selects, CAS requires 48 |
| `1010` | E | — |
| `1011` | F | F48 |
| `1100` | G | — |
| `1101` | D′ | wide-offset sibling |
| `1110` | I | subop `01` (`pmov`) only |
| `1111` | C″ (O-32) | H — carries its own length in `[9:6]` |

Tag `1111` is the one place two unrelated formats share a code, and §2's length-first rule
is what makes that safe: the length is known from `[1:0]` before the tag is read, so a 32-bit
C″ and a 48-bit H are never candidates for the same decode.

Eleven of sixteen tags have a 48-bit form and none of them needed a new tag to get one. The
formats with nothing to lengthen — A, A″, C, E, G — have no 48-bit rendering at all,
consistent with invariant 7. A is already at its full 10-bit opcode and A″'s bounded subset
lives in 0–31, so neither is short of reach; C, E and G carry no immediate worth widening.

---

## 3. Format bit maps

Bit 0 is LSB. Formats are 32-bit unless the heading says otherwise. Every table below is
self-contained — the header fields are repeated rather than implied.

**Reserved means must-be-zero, and using it faults (invariant 12, §12).** Every field or bit
marked reserved in any table in this document must be zero, and every opcode point, field value
or format code marked reserved must not be used. An instruction that sets a reserved bit, or
uses a reserved point or value, raises `F-ILLEGAL` at decode, whole instruction, whatever its
predicate. The rule is stated once here rather than in every row; a "reserved" anywhere in §3
or §4 carries it. Reserved rather than ignored, because an ignored field can never be given
meaning later: code that happened to set it would change behaviour.

### Format J — compressed accumulate (16-bit)

| Bits | Width | Field |
|---|---|---|
| `[1:0]` | 2 | class = `01` |
| `[3:2]` | 2 | subop |
| `[7:4]` | 4 | `rd` — accumulator, **read and written** |
| `[11:8]` | 4 | `rs0` |
| `[15:12]` | 4 | `rs1` |

Semantics: `rd = rd + (rs0 × rs1)`.

| Subop | Operation |
|---|---|
| `00` | `ffma.acc`, FP format code 0 (FP32 / FP16 / E4M3 by width) |
| `01` | `ffma.acc`, FP format code 1 (BF16 / E5M2 by width) |
| `10` | `dp4.acc` — 4×INT8 per lane → INT32, signed operands |
| `11` | `mad.acc` — integer multiply-add, any source/accumulator width combination |

This is the GEMM/conv inner-loop instruction and it justifies its own class code. Note it
is not a new operation: it is the existing Format A three-source op with `rs2` constrained
to equal `rd`, which is what an accumulation loop emits anyway. Twelve bits of register
fields leave exactly two for the subop, so the class code has to carry the rest of the
discrimination — hence a whole 16-bit group rather than an opcode point inside Format K.

Both FP format codes are present because FP16 and BF16 are used in roughly equal measure;
restricting compressed FMA to one of them would push half of all training-shaped code back
to 32 bits. Format codes `10`/`11` need the long form.

Two integer subops, covering the two shapes of quantized inner loop. `mad.acc` with
`rs0`/`rs1` at `chwidth`=8 and `rd` at `chwidth`=32 is one MAC per lane on register-resident
narrow data. `dp4.acc` is four MACs per lane on full-width registers holding packed bytes,
which is what a wide load from a k-contiguous tile delivers.

Only the signed/signed `dp4` reaches the compressed form — two bits of subop cannot carry the
signedness matrix, and `dp8` needs Format A entirely. Mixed-signedness inner loops therefore
encode at 32 bits per FMA rather than 16, which is the cost of keeping both FP format codes
compressed.

### Format K — compressed two-operand (16-bit)

| Bits | Width | Field |
|---|---|---|
| `[1:0]` | 2 | class = `10` |
| `[7:2]` | 6 | opcode — 64 points |
| `[11:8]` | 4 | `rd` — destination; also source 0 for destructive ops |
| `[15:12]` | 4 | `rs` / `imm4` / opcode-defined field |

**Opcode map:**

| Range | Use | Field `[15:12]` |
|---|---|---|
| 0–23 | destructive ALU reg-reg, `rd = rd OP rs` | `rs` |
| 24–27 | compressed load/store, zero offset | `rbase` |
| 28 | `srd rd, #sel` — identity / dynamic state read | `[15:12]` = 4-bit selector |
| 29–31 | reserved | — |
| 32–47 | destructive ALU reg-imm, `rd = rd OP imm4` | `imm4` |
| 48 | `chwidth rd, width` | `[13:12]` = width code |
| 49 | `bra.short` | `[15:8]` = 8-bit signed halfword offset |
| 50 | `call.short` | `[15:8]` = 8-bit signed halfword offset; **implicit** link register |
| 51 | `bar.arrive #id` | `[13:8]` = 6-bit barrier ID; 0–15 valid, 16–63 reserved (O-59) |
| 52 | `bar.wait #id` | `[13:8]` = barrier ID; phase is implicit (O-27), `[14:15]` reserved |
| 53 | `ret rs` | `[15:12]` = `rs`, link-register source |
| 54 | `exit` | unused |
| 55 | `reconv.hint` | `[11:8]` = alt-path length, `[14:12]` = nesting depth, `[15]` = post-dominator |
| 56 | `fence` | `[10:8]` = scope, `[12:11]` = ordering |
| 57–58 | `vote.any`, `vote.all` | `[10:8]` = `ps`, `[12:11]` = `pd` |
| 59 | `ballot rd` | `[10:8]` = `ps`, `[15:12]` = `rd` |
| 60–63 | `pand`, `por`, `pxor`, `pmov` — predicate logic | `[9:8]` = `pd`, `[12:10]` = `ps0`, `[15:13]` = `ps1` |

Points 0–23: `add`, `sub`, `mul.lo`, `and`, `or`, `xor`, `andn`, `shl`, `shr`, `sra`,
`min.s`, `min.u`, `max.s`, `max.u`, `mov`, `neg`, `not`, `abs`, `fadd.f0`, `fadd.f1`,
`fmul.f0`, `fmul.f1`, `fmin`, `fmax`.

Points 24–27: `ld.global`, `st.global`, `ld.shared`, `st.shared`, all with implicit zero
offset (`rd` = data, `rs` = base). Precomputed-address access is common enough in
coalesced kernels to be worth four opcode points.

Points 32–47: `add`, `sub`, `and`, `or`, `xor`, `shl`, `shr`, `sra`, `min.s`, `max.s`,
`mov` (small constant materialization), and 5 reserved. Immediate signedness is
opcode-defined, as in Format B.

**Predicate logic — points 60–63.** The only predicate-to-predicate operations in the
ISA. Both sources carry a 2-bit address and a negate bit, in the same shape as the
predicate qualifier:

| Bits | Width | Field |
|---|---|---|
| `[1:0]` | 2 | class = `10` |
| `[7:2]` | 6 | opcode — `pand` / `por` / `pxor` / `pmov` |
| `[9:8]` | 2 | `pd` |
| `[12:10]` | 3 | `ps0` — 2-bit address + negate |
| `[15:13]` | 3 | `ps1` — 2-bit address + negate |

Eight bits of operand against the eight Format K leaves after its opcode: an exact fit,
which is why these fields do not align with the compressed GPR geometry (`rd` at `[11:8]`,
`rs` at `[15:12]`). That is consistent with invariant 8 rather than an exception to it —
predicates have their own RAT (invariant 5), so the predicate rename path reads its own
fixed wires, and these positions are fixed across all four ops.

**Three points cover every two-input boolean function**, because independently negatable
sources do the rest: `andn`/`orn` by negating `ps1`, `nor` and `nand` by negating both,
`xnor` by negating one. Verified by enumeration — all sixteen are reachable.

Both constants come from the negate bit and cost 16 bits rather than `pmov`'s 48:

| | |
|---|---|
| all-zeros | `pand pd, ps, !ps` |
| all-ones | `por pd, ps, !ps` |

This does **not** reintroduce an always-true predicate in the sense §1 rules out — an
unpredicated instruction still cannot be expressed as predicated-on-true, because the
encodings differ. It makes a *materialized* all-true predicate cheap enough to serve as the
identity element when combining predicates during if-conversion.

Both idioms read a source only to discard it, so **the decoder should recognize
both-fields-equal-with-opposite-negate and break the dependency**, exactly as x86 does for
`xor r, r`. A 2-bit comparator and an XOR of the negate bits, on a path that already
decodes the opcode.

`pmov pd, ps` takes the fourth point despite being covered by `pand pd, ps, ps`, because a
predicate-to-predicate move is a **rename-time no-op** and the renamer has to recognize it
to elide it. A dedicated point makes that an opcode compare rather than a comparison of two
source fields and two negate bits. There is no collision with Format I's
`pmov pd, #lanemask`: register-operand and immediate-operand forms of one mnemonic are
standard, and Format K already does this for `mov`, which appears in both the reg-reg and
reg-imm ranges.

**Not added: a three-input predicate op.** `pd` plus three qualifier-style sources is 11
bits against the 8 available, so it would need a 32-bit Format I encoding — exactly
break-even against two 16-bit two-input ops. Invariant 7 forbids it. See O-20.

**`srd rd, #sel` — point 28.** The identity primitive, specified in §5.3. Its content is an
opcode and a destination, four bits of operand against the eight available, so invariant 7
requires the 16-bit form. The four bits that would otherwise be reserved carry a selector,
so one opcode point covers sixteen values.

**On the destructive form.** Requiring `rd == rs0` is free in a renaming machine — the RAT
handles the read-write dependency like any other. When the compiler cannot arrange it, the
fallback is a compressed `mov` plus a compressed op: 32 bits total, exactly break-even
against one 32-bit three-operand instruction, and the `mov` is a rename-time no-op at
execution. So the compressed reg-reg form is a win whenever `rd == rs0` falls out naturally
(accumulation, in-place update, dead source) and never a loss otherwise.

**No compressed form is predicated**, and none carries a predicate destination. Both would
cost 3 and 2 bits respectively out of 14, and predication is a bounded subset by design.

`chwidth`, `reconv.hint`, `ret` and `exit` are the clearest wins in the whole compressed
set: all four have well under 16 bits of real content, and `reconv.hint` in particular is
emitted at every reconvergence point from day one while doing nothing in Phase 1 hardware.
Spending 32 bits on it was pure waste.

**`call` and `ret` compress asymmetrically.** Compressed `ret` has room for an explicit
link-register source; compressed `call` does not, because all eight remaining bits go to
the offset. So `call.short` uses **R14**, the ABI's link register, implicitly, and any
call needing a different one takes the 32-bit form. The offset range is the real limiter
anyway: ±256 bytes reaches a nearby leaf helper and little else, so `call.short` will hit
far less often than `ret`. That is still a net win — a 32-bit `call` paired with a 16-bit
`ret` beats two 32-bit instructions.

### Formats A / A′ / A″ — ALU register-register (32-bit)

All three tiers share one field skeleton. Register fields, the low five opcode bits, and
the predicate qualifier sit at **fixed positions across all three tiers**; only `[31:27]`
is interpreted per-tier.

| Bits | Width | A | A′ | A″ |
|---|---|---|---|---|
| `[1:0]` | 2 | `00` | `00` | `00` |
| `[5:2]` | 4 | fmt `0000` | fmt `0001` | fmt `0010` |
| `[10:6]` | 5 | `opcode[4:0]` | `opcode[4:0]` | `opcode[4:0]` |
| `[14:11]` | 4 | `rd` | `rd` | `rd` |
| `[18:15]` | 4 | `rs0` | `rs0` | `rs0` |
| `[22:19]` | 4 | `rs1` | `rs1` | `rs1` |
| `[26:23]` | 4 | `rs2` | `rs2` | `rs2` |
| `[29:27]` | 3 | `opcode[7:5]` | **pred qualifier** | **pred qualifier** |
| `[31:30]` | 2 | `opcode[9:8]` | `opcode[6:5]` | **pred dest** |

Resulting opcode widths: **A = 10 bits**, **A′ = 7 bits**, **A″ = 5 bits**.

#### Format A′ long — 48-bit predicated ALU (O-37)

A′'s seven bits reach opcode points 0–127. Everything above — the conversions before O-34
moved them, and the SFU at 256+ — is Format A only and cannot carry a qualifier. This is
A′'s 48-bit sibling, and it closes that gap for the whole map at once.

| Bits | Width | Field |
|---|---|---|
| `[1:0]` | 2 | length = `11` (48-bit) |
| `[5:2]` | 4 | fmt = `0001` — the same tag as 32-bit A′ |
| `[10:6]` | 5 | `opcode[4:0]` |
| `[14:11]` | 4 | `rd` |
| `[18:15]` | 4 | `rs0` |
| `[22:19]` | 4 | `rs1` |
| `[26:23]` | 4 | `rs2` |
| `[29:27]` | 3 | **predicate qualifier** |
| `[31:30]` | 2 | `opcode[6:5]` |
| `[34:32]` | 3 | **`opcode[9:7]` — `000` raises `F-ILLEGAL`** |
| `[36:35]` | 2 | reserved, named for a future predicate destination |
| `[47:37]` | 11 | reserved |

**The low 32 bits are bit-identical to a 32-bit A′ instruction.** Every invariant-8 position
holds and the decoder for the first halfword pair is unchanged; the opcode becomes a
three-piece splice instead of two.

**`opcode[9:7]` ≠ `000` is a constraint on the field, not a convention.** With those bits
zero the form would encode points 0–127, which the 32-bit A′ already encodes — two encodings
of one instruction, which invariant 7's second sentence forbids and which would hand the
round trip a canonicalization question with no answer. So the long form encodes **exactly
points 128–1023**, complementary to the short form rather than overlapping it.
`tools/check-encoding.py` asserts it; an assembler emitting the long form for an opcode
below 128 is a bug, not a size preference. In hardware the encoding raises `F-ILLEGAL` (§12),
so the assertion now proves the assembler never emits a faulting encoding, which is a
different property and still a useful one.

**Invariant 7 is satisfied at minimum length, not despite waste.** The content is 35 bits — a
32-bit A′ plus three opcode bits — and 48 is the shortest length available at 16-bit
granularity. The reserved bits are a rounding artifact, exactly as `pmov`'s six are.

**`[36:35]` is reserved *for* a predicate destination rather than merely reserved.** Nothing
needs it: the intersection of "opcode above 127" and "produces a status predicate" looks
genuinely empty rather than unmeasured, because the SFU and conversions have no status output
and A″'s status-producing arithmetic lives in 0–31 by construction. Naming the two bits
anyway costs nothing and stops two implementations allocating them differently — O-28's
argument applied to reserved space.


The point of this arrangement is that `rd`, `rs0`, `rs1`, `rs2` and `opcode[4:0]` are at
identical positions in all three tiers, and the predicate qualifier is at an identical
position in the two tiers that have one. **Nothing on the register-read path needs a
format-dependent mux.** The RAT lookup can start from fixed wires before the format tag
has been decoded at all. Only `[31:27]` — five bits feeding opcode decode and the
predicate-dest write port, neither of which is on the critical rename path — requires a
mux.

The earlier layout, which shortened A″'s opcode in place and shifted every field below it
down by one bit, had the register fields landing in three different positions across the
ladder. Pushing A's and A′'s surplus opcode bits *up* into the previously-reserved high
bits fixes this at no cost, and is strictly better than what it replaces: A gains a
10-bit opcode rather than 6.

**Opcode allocation rule across tiers.** A′'s 7-bit space maps onto A's low 128 opcode
points, and A″'s 5-bit space onto A's low 32. Common operations therefore live low and get
predicated variants for free; exotic ones (SFU, rarely-predicated conversions) live in the
extension space and do not. This is a deliberate allocation constraint on the opcode map,
not an accident of the encoding.

### Formats B / B′ / B″ — ALU register-immediate (32-bit)

Same treatment as the A family: fixed register and opcode-low positions, predicate
qualifier at the canonical `[29:27]`, immediate split around it where it would otherwise
collide.

| Bits | Width | B | B′ | B″ |
|---|---|---|---|---|
| `[1:0]` | 2 | `00` | `00` | `00` |
| `[5:2]` | 4 | fmt `0011` | fmt `0100` | fmt `0101` |
| `[10:6]` | 5 | `opcode[4:0]` | `opcode[4:0]` | `opcode[4:0]` |
| `[14:11]` | 4 | `rd` | `rd` | `rd` |
| `[18:15]` | 4 | `rs0` | `rs0` | `rs0` |
| `[26:19]` | 8 | *immediate* | *immediate* `[7:0]` | *immediate* `[7:0]` |
| `[29:27]` | 3 | *immediate* | **pred qualifier** | **pred qualifier** |
| `[31:30]` | 2 | *immediate* | *immediate* `[9:8]` | **pred dest** |

**Changed in 1.4.** B′ and B″ previously put the predicate qualifier at `[21:19]` and B″ the
predicate destination at `[23:22]`, which made them the only exceptions to invariant 8 among
the 32/48-bit formats — and exceptions on the one field, the qualifier, that feeds the
predicate RAT. Splitting the immediate around the qualifier is the technique already used by
D′ (O-10) and `bra.pred`; applying it here costs nothing and removes the exception. See O-22.

Immediate widths are unchanged: `[31:19]` = 13 bits in B, 10 bits in B′ across
`[31:30]`,`[26:19]`, and `[26:19]` = 8 bits in B″.

**Sign-bit positions.** B and B′ keep their MSB at bit 31. B″'s sits at bit 26 — the same
position as C′'s, whose field layout B″ now matches exactly. This adds no decode cost: the
two sign-bit positions in the 32-bit formats were already 31 and 26, and B″ moves from the
first group to the second rather than introducing a third. Immediates are not on the rename
path, and B″ becoming layout-identical to C′ is a consistency gain the previous arrangement
forwent.

Two side effects of the realignment, both favourable: B and B′ each gain an immediate bit
(12 → 13 and 9 → 10) by recovering the bit the old 6-bit opcode was consuming, and all three
tiers now share a 5-bit opcode. Thirty-two points is ample for reg-immediate ALU — most of
Format A's opcode map (SFU, conversions, three-source ops, bit-manipulation) has no
immediate form at all.

Immediate signedness remains opcode-defined.

**Tier allocation, as in the A family.** The three tiers share one 5-bit opcode space, and
B″ is a bounded subset of it — only status-producing arithmetic has any use for a predicate
destination. `packi`/`unpacki` exist in B and B′ and have no B″ form.

### Format B opcode map — the projection rule (O-41)

Until 1.6 this range was described but never enumerated: §3 said "thirty-two points is
ample for reg-immediate ALU" and named informally which Format A operations lack an
immediate form. **That is the same exposure O-28 found twice and O-34 found once** — a range
given as a description rather than a table lets two implementations choose different orders
and produce silently incompatible binaries. It is closed here as a normativity fix, not as
an optimisation; the instruction counts that prompted it are a bonus, not the justification.

> **Where §4 point *n* names a BINARY operation, Format B point *n* is that operation with
> the second source replaced by the immediate. Where §4 point *n* is UNARY or TERNARY,
> Format B point *n* carries no immediate form and is free for immediate-only operations.**

The rule is derivable rather than memorised, and a decoder can share §4's map. `addi` at
point 0 against `add` at §4 point 0 was already this rule, applied unaided.

| pt | | pt | | pt | |
|---|---|---|---|---|---|
| 0 | `addi` | 8 | `ori` | 12 | `shri` |
| 1 | `subi` | 9 | `xori` | 13 | `srai` |
| 2 | `muli` | 10 | `andni` | 20 | `packi` |
| 7 | `andi` | 11 | `shli` | 21 | `packi.z` |
| | | | | 22 | `unpacki` |

**Arity, stated because the rule depends on it.** §4's binary points are 0–4 and 7–17.
Unary: 18, 20–24. Ternary: 5 (`mad.lo`), 6 (`mad.hi`), 25 (`prmt`). **Point 19 `sel` is
binary in register operands** — `rd = pq ? rs0 : rs1`, with the condition taken from the
predicate qualifier field rather than a third register — so the rule projects it. But a
qualifier is exactly what plain Format B lacks, so **`seli` is meaningful only in the B′
and B″ tiers**, and point 19 is unallocated in B itself. That is the one place where the
projection is tier-dependent.

**What the projection costs: Format B's points are no longer independently allocatable.**
Coupling the two maps is the price of decoder sharing, and it has to be visible to whoever
next wants a Format B point.

| Category | §4 points | Format B status |
|---|---|---|
| Binary | 0–4, 7–17 (16) | **claimed by the rule.** 10 defined above; 6 reserved — `mul.hi.s`/`u`, `min.s`/`u`, `max.s`/`u` |
| Unary | 18, 20–24 (6) | free for immediate-only; 3 used by the `packi` family |
| Ternary | 5, 6, 25 (3) | free for immediate-only |
| `sel` | 19 | B′/B″ only |
| Unallocated in §4 | 26–31 (6) | free, but **claimed if §4 later allocates a binary operation there** |

**Genuinely free for a future immediate-only operation: 12 of 32, not 28** (1.7 said 13; the table above sums to 3 + 3 + 6) — and shrinking
as §4 grows.

**`packi` and `unpacki` — moving between narrow and wide registers.**

| Mnemonic | Effect |
|---|---|
| `packi rd, rs, #slot` | insert `rs`'s lane value into slot `#slot` of `rd`'s lane, other slots preserved |
| `unpacki rd, rs, #slot` | extract slot `#slot` of `rs`'s lane into `rd`'s lane |

Both are per-lane: lane *n* of the source maps to lane *n* of the destination, never
crossing lanes. Element width comes from the narrow operand's `chwidth` (`rs` for `packi`,
`rd` for `unpacki`); the slot count is the width ratio, so the 3-bit immediate covers the
maximum case of eight 4-bit slots in a 32-bit lane. A slot index beyond the ratio is a
compiler-contract violation and produces a deterministic result, as with every other width
mismatch.

**`packi.z` clears the slots it does not write.** Same operands, one further opcode point.
`packi` preserves, which makes `rd` an implicit source; that costs nothing the machine does
not already pay, since predication requires every predicated instruction to read its
destination, and `packi` is a full-lane read-merge-write rather than a partial physical
write. What preservation does cost is a false dependency at the **head** of a compose chain,
where `rd`'s previous contents are all about to be overwritten and only the compiler knows
it:

```
    packi.z  rd, ra, #0        ; clears slots 1-3, no dependency on old rd
    packi    rd, rb, #1
    packi    rd, rc, #2
    packi    rd, rs, #3
```

Same instruction count as preserve-only, no extra temporaries, false dependency gone.
Clearing as the *only* semantic was rejected: it would make the four writes independent but
force an OR tree and four live temporaries, costing `packi` the one use case O-16 rates
break-even. `packi.z rd, rs, #0` is also independently useful as a raw zero-extending
narrow-to-wide placement, which `cvt` does not express. See O-21.

`unpacki` needs no variant: its destination is a narrow register written in full.

**`packi` reads its destination.** It is the one Format B opcode where `rd` is a source as
well — insertion has to preserve the slots it does not write. Renaming handles the
read-write dependency exactly as it does for Format K's destructive forms; the renamer takes
this from the opcode, which it decodes anyway.

**Why these exist.** Without them there is no way to compose a wide value from narrow ones,
and no way at all to decompose one. The composition direction could be synthesized —
widening `cvt`, then `shl`, then `or`, three instructions per element — but the
decomposition direction could not: nothing else in the ISA moves a slice of a wide register
into a narrow one, so packed data arriving from memory would be unreadable by the narrow
ALU. That is a hole in the type system independent of any performance argument, and the
performance argument is in fact weak: see O-16.

### Formats C / C′ — Compare (32-bit)

Aligned to the same skeleton as the A family, so `rd`, `rs0`, `rs1`, the predicate
qualifier and the predicate destination all sit where an A-format instruction puts them.

| Bits | Width | C (reg-reg) | C′ (reg-imm) |
|---|---|---|---|
| `[1:0]` | 2 | `00` | `00` |
| `[5:2]` | 4 | fmt `0110` | fmt `0111` |
| `[10:6]` | 5 | `opcode[4:0]` | `opcode[4:0]` |
| `[14:11]` | 4 | `rd` — materialization dest | `rd` |
| `[18:15]` | 4 | `rs0` | `rs0` |
| `[22:19]` | 4 | `rs1` | *immediate* |
| `[26:23]` | 4 | reserved | *immediate* |
| `[29:27]` | 3 | **pred qualifier** | **pred qualifier** |
| `[31:30]` | 2 | **pred dest** (mandatory) | **pred dest** (mandatory) |

C′'s immediate is `[26:19]`, 8 bits, MSB at bit 26 — one more bit than the previous
layout. The sign bit sits at a different position than the B family's, which is a mux the
decoder has to carry; unlike register fields, immediates are not on the rename path.

The 5-bit opcode map is **shared between C and C′**, so a mnemonic means the same opcode
value whichever way its second operand arrives. That is what makes `setp.ge` expressible at
all: the register form of `ge` is reachable by swapping operands, but `setp.ge rs0, #imm`
is not — an immediate cannot be the left operand. See O-26.

The map needs **16 points, not the 18** of `{6 predicates} × {signed, unsigned, FP}`:
integer `eq`/`ne` compare bit patterns and are sign-agnostic, so they are not duplicated
across the signed and unsigned classes.

| point | | point | | point | |
|---|---|---|---|---|---|
| 0 | `setp.lt` | 6 | `setp.lt.u` | 10 | `setp.lt.f` |
| 1 | `setp.le` | 7 | `setp.le.u` | 11 | `setp.le.f` |
| 2 | `setp.eq` | 8 | `setp.gt.u` | 12 | `setp.eq.f` |
| 3 | `setp.ne` | 9 | `setp.ge.u` | 13 | `setp.ne.f` |
| 4 | `setp.gt` | | | 14 | `setp.gt.f` |
| 5 | `setp.ge` | | | 15 | `setp.ge.f` |

`eq.f` is ordered-equal and `ne.f` is unordered-or-not-equal, an exact complementary pair:
for any operand pair, NaN included, exactly one holds. That makes C's `!=` on floats — which
LLVM emits as `fcmp une` — a single instruction rather than a negation.

That leaves 16 points for the materializing `set` variants, which is exactly enough and no
more. `rd` is always allocated and the opcode selects whether it is written.

**`chwidth` does not affect compares.** A compare reads one element per lane at whatever
width the sources carry and writes one bit per lane, so the predicate destination is 32 bits
in every case. There is no width interaction and nothing to encode.

### Formats D / D′ — Load / store (32-bit)

Distinct opcodes per address space; **predication by format tag** (`1000` / `1101`),
consistent with the A and B ladders. Two addressing modes per tier, selected by
`opcode[2]`.

**D — unpredicated, base + offset:**

| Bits | Width | Field |
|---|---|---|
| `[1:0]` | 2 | length = `00` |
| `[5:2]` | 4 | fmt = `1000` |
| `[10:6]` | 5 | opcode |
| `[14:11]` | 4 | `rdata` |
| `[18:15]` | 4 | `rbase` |
| `[31:19]` | **13** | signed offset |

**D — unpredicated, base + index:**

| Bits | Width | Field |
|---|---|---|
| `[1:0]` | 2 | length = `00` |
| `[5:2]` | 4 | fmt = `1000` |
| `[10:6]` | 5 | opcode |
| `[14:11]` | 4 | `rdata` |
| `[18:15]` | 4 | `rbase` |
| `[22:19]` | 4 | `rindex` |
| `[23]` | 1 | scale enable |
| `[31:24]` | **8** | signed displacement |

**D′ — predicated, base + offset:**

| Bits | Width | Field |
|---|---|---|
| `[1:0]` | 2 | length = `00` |
| `[5:2]` | 4 | fmt = `1101` |
| `[10:6]` | 5 | opcode |
| `[14:11]` | 4 | `rdata` |
| `[18:15]` | 4 | `rbase` |
| `[26:19]` | 8 | offset `[7:0]` |
| `[29:27]` | 3 | **pred qualifier** |
| `[31:30]` | 2 | offset `[9:8]` |

**D′ — predicated, base + index:**

| Bits | Width | Field |
|---|---|---|
| `[1:0]` | 2 | length = `00` |
| `[5:2]` | 4 | fmt = `1101` |
| `[10:6]` | 5 | opcode |
| `[14:11]` | 4 | `rdata` |
| `[18:15]` | 4 | `rbase` |
| `[22:19]` | 4 | `rindex` |
| `[23]` | 1 | scale enable |
| `[26:24]` | 3 | displacement `[2:0]` |
| `[29:27]` | 3 | **pred qualifier** |
| `[31:30]` | 2 | displacement `[4:3]` |

**This resolves O-10.** Splitting the predicate qualifier's neighbours around it — offset
low bits below, high bits above — keeps the qualifier at the canonical `[29:27]` position
*and* keeps the offset's sign bit at 31, at the cost of a split field. D′ base+offset
therefore keeps its full 10-bit offset rather than dropping to 8. A two-piece splice into
the AGU is trivial wiring, and immediates were never on the rename path; register fields,
which are, stay in their canonical positions throughout.

Predicated base+index is the tightest form at a 5-bit displacement, which is acceptable —
it is the rarest of the four and the index register carries most of the addressing work.

**Opcode map (5 bits, 32 points), identical for D and D′:**

| Opcode | Mode | Mnemonic |
|---|---|---|
| `00000`–`00011` | base + offset | `ld.global`, `st.global`, `ld.shared`, `st.shared` |
| `00100`–`00111` | base + index | same four |
| `01000`–`01011` | base + offset | `ld.pred`, `st.pred` × `{global, shared}` |
| `01100`–`01101` | **launch-slot + index** | `ld.global`, `st.global` (O-45) |
| `01110`–`01111` | — | reserved (the O-45 form for other spaces, if wanted) |
| `10000`+ | — | reserved (span/wide transfers) — deferred, see §10 |

*(This row first read `01100`–`01111` covering all four spaces. `.shared` is flat 32-bit and
has no window — §5.1 exempts it — so a launch-slot base means nothing there, and `.const` is
where the launch block itself lives. Two points, not four.)*

**Launch-slot + index (O-45).** A third addressing mode in which `[18:15]` is **not a register
number but a 4-bit launch-block slot index**: the window base comes from the launch block
directly and never occupies a GPR.

| Bits | Width | Field |
|---|---|---|
| `[1:0]` | 2 | length = `00` |
| `[5:2]` | 4 | fmt = `1000` |
| `[10:6]` | 5 | opcode |
| `[14:11]` | 4 | `rdata` |
| `[18:15]` | 4 | **launch slot** — an immediate, not a register |
| `[23]` | 1 | scale enable, as base+index |
| `[31:24]` | 8 | signed displacement, as base+index |
| `[22:19]` | 4 | `rindex` |

**This does not weaken invariant 8, and the precedent is Format D itself.** `[22:19]` is
already a register field in one mode of tag `1000` and immediate bits in the other, selected
by `opcode[2]`; the renamer already consults the opcode for this tag. Adding `[18:15]` to the
conditional set is the same kind of cost, not a new kind. Invariant 8's content is that
register fields sit at fixed positions **when present** — presence being opcode-conditional is
shipped behaviour, and the invariant now says so explicitly rather than leaving it implicit,
which had cost two review cycles by the time this was written.

**The slot numbering.** Slot *k* is the 32-bit word at launch-block byte offset
`OffArgs + 8k`, where `OffArgs` is 32 — so the sixteen slots cover the first 128 bytes of the
argument area and name **pointer arguments 0–15**. A pointer argument's **window index** is
the word at its slot. The stride is 8 rather than 4 because §5.2 gives a pointer argument
eight bytes (window index plus in-window offset, O-23) whether or not it is aligned, so an
8-byte step is what lands on a window word every time; and the ABI puts directly-passed
pointer arguments at the **front** of the argument area, in declaration order, so that slot
*k* is pointer argument *k* and a scalar in the middle of a signature cannot push a pointer
out of reach.

The front-loading rule is stated in §5.2 and covers pointers passed **directly**. A pointer
inside a by-value aggregate keeps the host's layout inside the struct, claims no slot, and
reaches the AGU through §5.7's in-memory representation. *(The stride was 4 in 1.7 as
released, which made every odd step name an in-window offset or a scalar, so half the slot
space was dead by construction and the form reached only pointer arguments 0–7. Re-scaled
without an encoding change: same 4 bits at `[18:15]`, same two opcodes, one bit of shift in the
slot decode. See O-50.)*

**Unaligned pointers get less from this than aligned ones**, and that is consistent rather than
surprising. O-23's unaligned form carries a window *and* an in-window byte offset; the slot
supplies the window, so the offset still has to reach the index register, exactly as it does
for base+index today. The form is a win for aligned pointers and neutral for unaligned ones.

**Why it exists.** The §5.1 window bases of a fused elementwise kernel are warp-uniform,
loop-invariant, and already resident in the launch block — a small, CTA-wide, read-only table
(§5.2). Holding one in a GPR spends a register caching something that is already in memory,
and the compiler measurement is that this is what binds: in a grid-strided fused chain the
*divergent* working set is four values at any tensor count while the uniform one grows with
the number of tensors fused, crossing the 16-entry file and spilling from there (F-129).

**The open cost is on the hardware side and is not settled here:** something has to hold or
cache the launch block for the AGU. It is CTA-wide, read-only and small, which is what makes a
cache plausible, but plausible is not priced.

**A second shape was considered and rejected** — keeping `[18:15]` a register field and adding
a mode bit selecting which *file* it indexes. That introduces a second register namespace for
no encoding benefit over a form the tag already precedents. If a second namespace is ever
wanted it should be wanted on its own merits, not arrive as a side effect of an addressing
mode. See O-46.

Transfer size is inherited from `rdata`'s `chwidth` — no size field. Address space is in
the opcode. **A memory access whose `rdata` is at `chwidth`=4 raises `F-WIDTH`** (§12), at
dispatch, whole instruction, independent of predicate and issue mask; no memory access occurs.
4-bit data reaches registers only through `packi` and `unpacki`.

**Execute-stage faults are per lane and predicate-gated — normative.** `F-ALIGN`, `F-ADDR`,
`F-SHARED` and `F-RO` are raised only for lanes in issue mask ∩ predicate. A lane predicated
off, or at another PC, never faults, whatever address it computed: that is what lets a
bounds-guarded load compute garbage addresses on its tail (§12.2).

**Natural alignment is required (O-58).** A lane's effective address must be a multiple of its
transfer size: 4 bytes at `chwidth`=32, 2 at 16, any at 8. A lane that violates it raises
`F-ALIGN`. With scale-enable set, `rindex << scale` is aligned by construction, so only `disp`,
an unaligned base, or a byte-offset index with scale clear can misalign; the compiler proves its
§5.5 fold preserves alignment, and the hardware checks it regardless.

**`rbase` and `rindex` are read at 32 bits, whatever their own `chwidth`** (O-39). They are
address components, and invariant 11 keeps addresses outside the element-width model
entirely; only `rdata` is narrow. A consequence worth stating because a compiler will rely
on it: `rdata` may name the same register as `rbase` or `rindex`, since the address read
takes all 32 bits and the narrow write lands inside them.

Effective address in the base+index modes is `rbase + (rindex << scale) + disp`, where
`scale` is `log2(element_size)` taken from `rdata`'s current `chwidth` when bit `[23]` is
set, and zero when it is clear; it is defined for `chwidth` ∈ {8, 16, 32}, since a 4-bit
access faults before any address is formed.

**Why chwidth-derived scale rather than an explicit scale field.** The index a kernel
computes is almost always an *element* index, not a byte index. Deriving the shift from the
destination register's width means `A[i]` is one instruction whether `A` is FP32, FP16 or
INT8 — and, more to the point, means **changing precision does not change the address
arithmetic**. For a machine whose entire premise is running the same kernel shape across
four element widths, having the addressing mode track `chwidth` automatically is worth more
than the generality of an explicit scale field. The scale-enable bit covers the residual
case (byte-addressing a narrow buffer through a wide register).

This resolves O-7.

**On whether register-offset earns its place.** The compiler can always materialize
`rbase + rindex` into a temporary first, and with a 16-bit compressed destructive `add`
that costs very little encoding. What it does not avoid is *latency*: the add sits on the
load's critical path, delaying address generation by a cycle on every indexed access.
Folding it into the AGU — which already has an adder for the displacement — removes that.
The three-input add (base, shifted index, displacement) is standard AGU practice and not a
new cost centre.

**Address generation is 64-bit; registers are not.** For `.global` (and `.const`, and
`.local` through its window) the effective address is

```
    (rbase << 16) + (rindex << scale) + disp
```

with the base shift `S` = 16 fixed and taken from the **address space**, not from a field —
so no bit map above changes. `.shared` does not shift: a CTA's shared memory is hundreds of
kilobytes and 64-bit reach there is meaningless.

The 48-bit result exists only inside the AGU. No register holds more than 32 bits, `chwidth`
is untouched, no register pairing is introduced, and span stays deferred. See §5.1 for why
`S` = 16 and for what it costs the compiler.

Note the operand count: `rindex` **is** the in-window offset. The wanted address has four
addends against a three-input AGU, so a nonzero allocation offset is folded into the index
register by the compiler, which then carries bytes rather than elements and leaves
scale-enable clear. Chwidth-derived scaling therefore applies to `.shared`, and to `.global`
where the allocation is 2^16-aligned, rather than universally. This qualifies O-7 without
reversing it.

### `ld.pred` / `st.pred` — predicate transfer (32-bit)

A predicate is 32 bits at every `chwidth` (invariant 5), so a transfer is one aligned word
per predicate, and the whole architectural predicate file is 128 bits. The `rdata` field is
4 bits and the predicate file has 4 entries, so `rdata` carries a **predicate bitmask** and
the instruction is the Format D base+offset skeleton unchanged:

| Bits | Width | Field |
|---|---|---|
| `[1:0]` | 2 | length = `00` |
| `[5:2]` | 4 | fmt = `1000` |
| `[10:6]` | 5 | opcode |
| `[14:11]` | 4 | **predicate mask** — one bit per `P0`–`P3` |
| `[18:15]` | 4 | `rbase` |
| `[31:19]` | 13 | signed offset |

```
    st.pred  {P0}, [R5+16]
    st.pred  {P0,P1,P2,P3}, [R5+16]      ; whole file, one 16-byte access
```

Every field in its canonical position, sign bit at 31, and the 48-bit sibling comes free
under the same tag for a 29-bit offset. Base+offset only — spill slots are
base-plus-constant — and no `D′` form, per invariant 7.

**The frame is positional.** Word *i* of a fixed 16-byte frame always holds `Pi`, whatever
the mask. A packed layout would make the effective address depend on mask popcount and make
masks non-composable: save `{P0,P2}`, restore `{P2}`, wrong word.

**A mask with N bits set is N predicate accesses from one instruction**, and it does not
need a decode-cracking sequencer. The predicate RAT is four entries; writing all four is a
4-bit write enable on a flop array. Single ROB entry, single AGU operation, one 16-byte
access. This is cheap precisely because the file is tiny — the same asymmetry that makes
span hard for GPRs (§10) makes a full bitmask free here, with no alignment constraint and
all sixteen combinations legal.

**`rbase` must be warp-uniform.** A predicate is warp-scoped state and `rbase` is 32 lanes
wide; the address is taken from lane 0 and a non-uniform `rbase` produces a deterministic
result, per invariant 3 — the same contract already governing width and FP-format
mismatches. The predicate spill region is therefore warp-scoped, which §5.2's window
covers. See O-19.

**Under divergence, `ld.pred` writes only the issuing group's lanes — normative (O-62).**
For each predicate in the mask, lane *i*'s bit takes bit *i* of the predicate's word if lane
*i* is in the issue mask, and keeps its value otherwise (invariant 10). **The address is lane
0's `rbase` value whether or not lane 0 is in the issue mask** (the value lane 0's element of
that register holds, merged as any register is), never the lowest executing lane's. That
gives a warp one slot per frame across every split and merge, so a reload finds the slot its
spill used even when the groups have changed in between. The lowest executing lane would move
the slot whenever a group splits.

**`st.pred` stores only the issuing group's bits — normative (O-63).** For each predicate in
the mask, bit *i* of its word takes lane *i*'s bit if lane *i* is in the issue mask, and keeps
memory's value otherwise: `new = (old & ~m) | (p & m)`, with `m` the issue mask. Each word's
read and write are one indivisible step: no other access sees the word between them. So each lane's bit in a slot is
written and read only by that lane's thread. With `ld.pred`'s rule above, a spill and its reload
are per lane under any split, merge or interleaving of groups, at one shared slot, with no
compiler precaution. `st.pred` is a store for every other rule: `F-RO` (§12.3), `F-ALIGN`, and
ordering against the warp's later loads.

`.local` maps to `ld.global`/`st.global` via the thread-private windowing convention.
`.const` maps to `ld.global` for reads. **A store or atomic any byte of which falls in
the `.const` window raises `F-RO`**, whether or not the atomic would have changed memory.
There is no dedicated opcode: the protection is a bounds check in the memory pipe, on the same
path as the launch block's (§5.2), so MIU carries a `.const` base and limit per kernel beside
the launch block's. See O-51.

**Ordinary loads and stores carry no ordering qualifier.** Formats D, D′, M and M′ have no
ordering field at any length. The only ordering mechanism in the instruction set is `fence`
(Format K point 56, 3 bits of scope at `[10:8]` and 2 of ordering at `[12:11]`), so
`volatile`, `acquire`, `release` and `.mmio` have no per-access representation and lower to a
fence plus a plain access — correct for acquire and release, and a compiler obligation for
`volatile`.

**One consequence is normative and easy to miss.** Because there is no qualifier, a plain
`ld` serves as both the non-atomic load, where a concurrent write is a data race and the
hardware owes nothing, and the relaxed atomic load, where read-read coherence binds. The
hardware cannot distinguish them and must honour the stronger obligation: **two loads of the
same address in one warp may not be reordered with each other**, whatever the hardware does
with loads to different addresses. See O-52.

### Formats M / M′ — Atomics

**Properties, not a mechanism.** An atomic is one instruction with one ROB entry. **Each
active lane's read-modify-write is individually atomic** and full-width at its memory
location, and each lane returns the old value it saw where the instruction has a
destination. Atomicity is per lane, as in CUDA, not per instruction: another instruction's
lanes, from any warp, may land between two lanes of this one. Every operation allocated here is integer and order-independent, so
same-address lanes within one instruction may apply in any order; a non-associative form,
such as the FP add IS-14 proposes, arrives with its own ordering rule. Where the operation executes is the
implementation's choice. *(1.7 and the first cut of 1.8 said "normal ALU execution on the
buffered old value; existing load buffer and store buffer handle the memory side", which
named the lane ALU as the site. That site cannot apply a same-address lane chain in one pass,
and holds the line exclusive across a round trip to the lanes. Struck under AR-21, as
invariant 2's mechanism clause was under OA-16; the site is AR's and DA's.)*

**Simple RMW (32-bit):**

| Bits | Width | Field |
|---|---|---|
| `[1:0]` | 2 | length = `00` |
| `[5:2]` | 4 | fmt = `1001` |
| `[10:6]` | 5 | opcode |
| `[14:11]` | 4 | `rd` — returned old value |
| `[18:15]` | 4 | `rbase` |
| `[22:19]` | 4 | `rs` — operand |
| `[31:23]` | **9** | signed offset |

Opcodes: `{add, min.s, min.u, max.s, max.u, and, or, xor, exch}` × `{global, shared}` =
18 points of 32.

**CAS (48-bit):**

| Bits | Width | Field |
|---|---|---|
| `[1:0]` | 2 | length = `11` (48-bit) |
| `[5:2]` | 4 | fmt = `1001` (M) |
| `[10:6]` | 5 | opcode (`cas.global` / `cas.shared`) |
| `[14:11]` | 4 | `rd` — old value |
| `[18:15]` | 4 | `rbase` |
| `[22:19]` | 4 | `rs_cmp` |
| `[26:23]` | 4 | `rs_swap` |
| `[29:27]` | 3 | **pred qualifier** |
| `[31:30]` | 2 | `pd` — success predicate |
| `[47:32]` | **16** | signed offset |

CAS is the clearest case in the whole ISA for variable length: two sources, two
destinations across separate register spaces, and an address. It does not fit in 32 bits
and should not be forced to.

The memory-side RMW is full-width. `chwidth` on `rd` governs only how the returned old
value is interpreted — no atomicity implication.

### Format E — Control flow, barrier, fence (32-bit)

**Branch:**

| Bits | Width | Field |
|---|---|---|
| `[1:0]` | 2 | length = `00` |
| `[5:2]` | 4 | fmt = `1010` |
| `[10:6]` | 5 | opcode |
| `[31:11]` | **21** | signed offset, 16-bit granular (±2 MB) |

**Call — explicit link register:**

| Bits | Width | Field |
|---|---|---|
| `[1:0]` | 2 | length = `00` |
| `[5:2]` | 4 | fmt = `1010` |
| `[10:6]` | 5 | opcode = `call` |
| `[14:11]` | 4 | `rd` — link register destination |
| `[31:15]` | **17** | signed offset, 16-bit granular (±128 KB) |

**Offset base — normative.** Every PC-relative offset in the instruction set — Format E's
branch, `call` and `bra.pred`, and Format K's short branch — counts 16-bit units from the
address of the **next** instruction, that is, the branch's own address plus its length:
`target = PC + length + 2 × offset`. The compiler and the simulator already agree on this;
1.7 left it unstated, which let two implementations differ by one instruction length.

**Return:** no 32-bit form. The compressed `ret rs` (Format K, opcode 53) addresses all 16
GPRs and carries the operation's entire content; a 32-bit encoding would add nothing but
13 reserved bits. Same for `exit` and `reconv.hint`. See invariant 8.

The link register is explicit in both, at the standard `rd` / `rs0` positions, and it costs
nothing. `ret` had 21 bits doing nothing at all. `call` pays for its field by giving up
offset range it does not need: ±128 KB of code is far beyond any realistic kernel image,
and if it ever binds, Format E can take a 48-bit sibling like any other format.

This matters more than it looks. We chose link-register-plus-software-convention over a
hardware call stack specifically to keep resident warp state small, which pushed nesting
cost onto spill traffic. An explicit destination lets a two-deep call chain use two
different link registers — `call R14, f` inside `call R13, g` — with **no spill at all**.
The convention gets materially cheaper for free.

**What `call` writes and what `ret` reads — normative (CP-9, AR-22).** Code lives in
**4 GiB windows**: aligned 2^32-byte regions of the code address space, and a kernel's image,
with everything it calls, lies within one. `call rd, off` and `call.short off` write, to every
active lane of the link register (`rd`, or R14 for `call.short`), the **low 32 bits of the
next instruction's address** (the call's own address plus its length) as an unsigned value.
`ret rs` sets each active lane's PC to the **`ret`'s own window with that lane's `rs` as the
offset**: `{PC[47:32] of the ret, rs[31:0]}`. That is a concatenation, not an add, and needs
no image-base state: every instruction already carries its PC. A function pointer is the
offset of its target within the window, so it is a constant of the image wherever the image's
window sits, and a loader places an image at a window-aligned base so that the offset from the
image base and the low 32 bits are the same number. Every `rs` names a location in the
`ret`'s own window, so no `ret` can leave it: a pointer taken in one window and returned
through in another lands at the same offset in the second window, which is defined behaviour
and, for code the driver keeps in one window per context, never arises. Lanes may return to
different offsets; per-thread PCs (§1) make that ordinary divergence, and it is what lets an
indirect call be a `call` to a one-instruction `ret` stub. A `ret` target with bit 0 set is
not 16-bit granular, so the fetch from it raises `F-FETCH` (§12). The link value is a **code** offset, which invariant 11 does not cover: that invariant
keeps 48-bit *data* addresses out of the register file, and a 32-bit code offset is an
ordinary value. Which registers a callee preserves is the ABI's choice, not the ISA's; the
compiler's calling-convention proposal sets it by measurement.

**Predicated branch:**

| Bits | Width | Field |
|---|---|---|
| `[1:0]` | 2 | length = `00` |
| `[5:2]` | 4 | fmt = `1010` |
| `[10:6]` | 5 | opcode = `bra.pred` |
| `[26:11]` | 16 | offset `[15:0]` |
| `[29:27]` | 3 | **predicate qualifier** |
| `[31:30]` | 2 | offset `[17:16]` |

Splitting the offset around the qualifier keeps it at `[29:27]` with no loss of range —
still 18 bits (±256 KB), sign bit still at 31. Same technique as Format D′.

**Barrier initialization:**

| Bits | Width | Field |
|---|---|---|
| `[1:0]` | 2 | length = `00` |
| `[5:2]` | 4 | fmt = `1010` |
| `[10:6]` | 5 | opcode = `bar.init` |
| `[16:11]` | 6 | barrier ID: 0–15 valid, 16–63 reserved (O-59) |
| `[26:17]` | 10 | expected arrival count |
| `[31:27]` | 5 | reserved |

**Explicit-phase barrier wait:**

| Bits | Width | Field |
|---|---|---|
| `[1:0]` | 2 | length = `00` |
| `[5:2]` | 4 | fmt = `1010` |
| `[10:6]` | 5 | opcode = `bar.wait.phase` |
| `[16:11]` | 6 | barrier ID — same field as `bar.init` |
| `[18:17]` | 2 | `ps` — predicate supplying the expected phase |
| `[26:19]` | 8 | reserved |
| `[29:27]` | 3 | **predicate qualifier** |
| `[31:30]` | 2 | reserved |

`ps` is a predicate **source**, not a qualifier, and the two are both present: the qualifier
at `[29:27]` decides whether the instruction executes, `ps` is data it reads. See O-27 for
why this instruction exists alongside the compressed wait.

`bar.arrive` and the ordinary `bar.wait` have **no 32-bit form** — both are fully expressed
in Format K. Initialization needs 32 bits because a barrier ID plus a 10-bit expected count
is 16 bits of operand and the compressed forms have 8. `bar.wait.phase` needs 32 bits
because it adds a predicate source and a qualifier to that same ID. See O-12 and O-27.

**Fence:** no 32-bit form. Scope (3 bits) plus ordering (2 bits) is 5 bits of content,
fully expressed in Format K. Fences are emitted around every barrier and atomic sequence,
so this is one of the higher-frequency compressions in the set.

**Opcode map (5 bits):**

| Opcode | Mnemonic | Notes |
|---|---|---|
| `00000` | `bra` | long range (±2 MB) |
| `00001` | `bra.pred` | divergence entry point |
| `00010` | `call` | explicit link-register destination |
| `00011` | `bar.init` | barrier ID + expected arrival count |
| `00100` | `bar.wait.phase` | barrier ID + predicate-sourced phase (O-27) |
| `00101`+ | reserved | |

`ret`, `exit`, `reconv.hint`, `fence`, `bar.arrive` and the implicit-phase `bar.wait` have
no 32-bit encoding — all six are fully expressed in Format K.

`bra.pred` reads the predicate at thread granularity (K=1) always. There is no packed
interpretation of a branch condition — `chwidth` has no interaction with Format E.

`reconv.hint` is emitted by the compiler from day one and ignored by Phase 1 hardware, so
Phase 2 scheduler work can be designed against real hint placement rather than guesses. Its
operands are specified in §3 under Format K and discussed under O-4.

### Format F — Wide immediate

**32-bit form:**

| Bits | Width | Field |
|---|---|---|
| `[1:0]` | 2 | length = `00` |
| `[5:2]` | 4 | fmt = `1011` |
| `[10:6]` | 5 | opcode |
| `[14:11]` | 4 | `rd` |
| `[31:15]` | **17** | immediate |

**48-bit form:**

| Bits | Width | Field |
|---|---|---|
| `[1:0]` | 2 | length = `11` (48-bit) |
| `[5:2]` | 4 | fmt = `1011` |
| `[10:6]` | 5 | opcode |
| `[14:11]` | 4 | `rd` |
| `[31:15]` | 17 | immediate `[16:0]` |
| `[47:32]` | 16 | immediate `[32:17]` |

`rd` sits at `[14:11]` and the opcode at `[10:6]`, matching every other format, at the cost
of one immediate bit relative to a layout that packed them lower. 33 bits still covers any
32-bit constant with room over.

The 48-bit form materializes any 32-bit constant in **one instruction** — no `lui`/`addi`
pair, no hi/lo split. This is a concrete win from variable length that a fixed 32-bit
encoding could not have delivered. Immediates are warp-uniform (broadcast to all lanes).

### Wide-immediate siblings (48-bit)

Every immediate-carrying format has a 48-bit rendering under the **same tag**, with bits
`[31:6]` laid out identically to the 32-bit form and 16 further immediate bits at
`[47:32]`. Nothing else changes — no field moves, no new tag, no new decode path.

| Format | 32-bit immediate | 48-bit immediate | Low bits | High bits |
|---|---|---|---|---|
| B | 13 | **29** | `[31:19]` | `[47:32]` |
| B′ | 10 | **26** | `[31:30]`,`[26:19]` | `[47:32]` |
| B″ | 8 | **24** | `[26:19]` | `[47:32]` |
| C′ | 8 | **24** | `[26:19]` | `[47:32]` |
| D (base+offset) | 13 | **29** | `[31:19]` | `[47:32]` |
| D (base+index) | 8 | **24** | `[31:24]` | `[47:32]` |
| D′ (base+offset) | 10 | **26** | `[31:30]`,`[26:19]` | `[47:32]` |
| D′ (base+index) | 5 | **21** | `[31:30]`,`[26:24]` | `[47:32]` |
| F | 17 | **33** | `[31:15]` | `[47:32]` |

The sign bit sits at 47 in every 48-bit form. In the 32-bit forms it sits at 31 everywhere
except C′ and B″, which put it at 26 — two positions, not one, and that was already true of
C′ before 1.4 despite the previous wording here claiming otherwise. Three fixed wires total,
selected by the format tag and a signal available at bit 0.

**This resolves O-5.** The tight immediates that prompted it (B″ and C′ at 8 bits, D′
base+index at 5) are no longer a ceiling, they are just the short encoding. The compiler
picks per-instruction and pays 16 bits only where it needs them.

Note what this replaces. Without the sibling, an over-range immediate costs a Format F
materialization plus a register plus a reg-reg instruction — 64 to 80 bits and one register
of pressure, on a machine with only 16. The sibling costs 16 bits and no register. It also
means B/B′/B″ do not need generous 32-bit immediates "just in case," which is what let the
short forms stay tight enough to fit the field-alignment scheme in the first place.

Formats with no immediate — A, A″, C, E, G — have no 48-bit rendering. There would be
nothing to put in the extra halfword, and invariant 7 forbids reserved-bit padding.

**Format A′ is the exception, and it is the same rule rather than a break from it.** Its
48-bit sibling extends an **opcode** where B, C′, D, D′ and F extend an **immediate** — so
the sibling rule reads "a 48-bit instruction is its 32-bit sibling with 16 more *bits* at
`[47:32]`", not "16 more *immediate* bits". A′ is the one tier whose reach is narrower than
the operations that want it: 7 opcode bits against Format A's 10. A and A″ have no long form
because neither is short of reach — A already has all ten bits, and A″'s bounded subset
genuinely lives in 0–31. See O-37.

Two qualifications. Format I is absent from the table but *does* have a 48-bit form: `pmov`
carries a 32-bit lane mask and exists only at that length, while `chwidth.multi` exists only
at 32 — the two subops sit at different lengths rather than being siblings. And within
Format B, `packi`/`unpacki` do not take the sibling: a 3-bit slot index has nothing to widen,
so those opcodes are 32-bit only.

### Format G — Warp-collective (32-bit)

**Changed in 1.4.** Previous revisions gave Format G as a single table whose fields carried
"or" clauses — `[23:19]` a shuffle lane index "or `ps` at `[21:19]` for vote/ballot", and
`[31:30]` a vote destination "or reserved". Those are four distinct field layouts sharing a
tag, not one layout, and a decoder implementer reading the merged table had to reconstruct
the split unaided. They are now written out. No bit assignment changes.

**Shuffles** — GPR source and destination, 5-bit lane index, no predicate destination.

**The source lane is read whether or not it is active.** A shuffle reads the register file
across lanes; the predicate qualifier gates which lanes *write*, not which lanes can be
*read from*. O-33's broadcast depends on exactly this — lane 0 computes a value and is then
excluded from the shuffle that distributes it.

| Bits | Width | Field |
|---|---|---|
| `[1:0]` | 2 | length = `00` |
| `[5:2]` | 4 | fmt = `1100` |
| `[10:6]` | 5 | opcode |
| `[14:11]` | 4 | `rd` |
| `[18:15]` | 4 | `rs0` |
| `[23:19]` | 5 | lane index |
| `[26:24]` | 3 | reserved |
| `[29:27]` | 3 | **pred qualifier** |
| `[31:30]` | 2 | reserved |

**`vote.any` / `vote.all`** — predicate in, predicate out, no GPR operand:

| Bits | Width | Field |
|---|---|---|
| `[1:0]` | 2 | length = `00` |
| `[5:2]` | 4 | fmt = `1100` |
| `[10:6]` | 5 | opcode |
| `[18:11]` | 8 | reserved |
| `[21:19]` | 3 | `ps` |
| `[26:22]` | 5 | reserved |
| `[29:27]` | 3 | **pred qualifier** |
| `[31:30]` | 2 | **`pd`** |

**`ballot`** — predicate in, GPR out:

| Bits | Width | Field |
|---|---|---|
| `[1:0]` | 2 | length = `00` |
| `[5:2]` | 4 | fmt = `1100` |
| `[10:6]` | 5 | opcode |
| `[14:11]` | 4 | `rd` |
| `[18:15]` | 4 | reserved |
| `[21:19]` | 3 | `ps` |
| `[26:22]` | 5 | reserved |
| `[29:27]` | 3 | **pred qualifier** |
| `[31:30]` | 2 | reserved |

**`unballot`** (1.3, O-14) — GPR in, predicate out. The exact inverse of `ballot`, with `rs0`
and `pd` both at their canonical invariant-8 positions and no new fields, as O-14 claimed:

| Bits | Width | Field |
|---|---|---|
| `[1:0]` | 2 | length = `00` |
| `[5:2]` | 4 | fmt = `1100` |
| `[10:6]` | 5 | opcode |
| `[14:11]` | 4 | reserved |
| `[18:15]` | 4 | `rs0` |
| `[26:19]` | 8 | reserved |
| `[29:27]` | 3 | **pred qualifier** |
| `[31:30]` | 2 | **`pd`** |

**Opcode map:** `shfl.idx`, `shfl.up`, `shfl.down`, `shfl.bfly`, each with an
immediate/register index-source bit, plus predicated `vote.any`, `vote.all`, `ballot`, and
`unballot`.

**`unballot pd, rs`** is the exact inverse of `ballot`: bit *n* of `rs` becomes lane *n*'s
predicate bit. It fits the layout above with no new fields — `rs` at `[18:15]`, `pd` at
`[31:30]`, both canonical. Added in 1.3; see O-14.

`unballot` and `ld.pred` address different problems and neither substitutes for the other.
`ld.pred` reloads spilled predicate state from memory. `unballot` returns a **computed**
lane mask to the predicate file — a ballot result manipulated arithmetically, an active-lane
set narrowed by a loop counter — without a memory round trip.

The shuffle index is **5 bits** — it selects one of 32 lanes, and that is the only
granularity the machine has.

**Shuffles do not cross widths.** A shuffle moves a lane's value to another lane at whatever
width that value carries; `rd` and `rs` are expected to share a `chwidth`. If they differ,
the value moves as a raw bit field and is truncated or zero-extended into the destination —
deterministic, no interlock, the same policy applied to width mismatches everywhere else.
Changing element width is `cvt`'s job and composes cleanly before or after a shuffle.

There is deliberately **no cross-width gather**: no instruction collects several narrow
registers' lane *n* into one wide register's lane *n*. That operation moves nothing between
lanes, so calling it a shuffle would misdescribe it, and nothing in the instruction set needs
it — see O-15.

`[26:24]` is reserved. PTX's shuffle carries a combined clamp / segment-mask operand that
this encoding does not yet express; those three bits plus the reserved `[26:22]` region are
where it would go if it turns out to be needed.

**Format G′ is deleted.** It existed as a 48-bit predicated variant; folding the predicate
qualifier into G at `[29:27]` — the invariant-8 position — covers it in 32 bits and frees a
tag. G carries no immediate, so it has no 48-bit rendering at all. Unpredicated
`vote`/`ballot` live only in Format K; the 32-bit forms here
justify their length by carrying predication, which the compressed forms cannot.

### Format I — Register and predicate metadata (32-bit)

Two operations, selected by a 2-bit subop at `[7:6]`. Neither compresses: `chwidth.multi`
needs a 16-bit register mask and `pmov` needs a 32-bit lane mask, against the 8 bits of
operand Format K provides.

**Subop `00` — `chwidth.multi #regmask, width`:**

| Bits | Width | Field |
|---|---|---|
| `[1:0]` | 2 | length = `00` |
| `[5:2]` | 4 | fmt = `1110` |
| `[7:6]` | 2 | subop = `00` |
| `[23:8]` | 16 | register bitmask (one bit per logical GPR) |
| `[25:24]` | 2 | width code |
| `[31:26]` | 6 | reserved |

The single-register `chwidth rd, width` is 8 bits of content and lives in Format K
(opcode 48); it has no 32-bit encoding. Only the multi-register form needs this format.

**Accepted** (O-6). `chwidth` requires draining in-flight dependents on the affected
register, and a kernel entering a packed section typically reconfigures several at once.
Setting them in one instruction collapses N drain events into one and saves N−1
instructions of prologue. The drain scope becomes the union of the masked registers, which
is still bounded and still scoped — no global pipeline drain.

**Measured, and the qualifier matters more than the acceptance.** The compiler hoists each
width change as early as it is legal — past any instruction that does not touch the register,
stopping at block entry — and then merges adjacent same-width runs. On the shape this
paragraph describes, four narrow loads from one base, that merges 2 of 3 and turns three
instructions into two. On a kernel whose narrow loads are interleaved with **address
arithmetic on the very registers being narrowed**, it merges 0 of 3 after hoisting 2, and no
legal placement can do better: the transitions are separated by a real dependency.

So the multi-register form earns its format on one shape and cannot on the other. That is
sharper than "typically reconfigures several at once", and it is a property of the kernel
rather than of the compiler. See F-69.

Cost: the drain is now wider, so a carelessly-placed multi-form stalls more than a
carefully-placed single-form. That is a compiler scheduling concern, not a correctness one:
the compiler should hoist the mask instruction to a point where the affected registers are
cold, which in a packed-section prologue is where it naturally wants to sit anyway.

**Subop `01` — `pmov pd, #lanemask` (48-bit only):**

| Bits | Width | Field |
|---|---|---|
| `[1:0]` | 2 | length = `11` (48-bit) |
| `[5:2]` | 4 | fmt = `1110` |
| `[7:6]` | 2 | subop = `01` |
| `[9:8]` | 2 | `pd` — predicate destination |
| `[15:10]` | 6 | reserved |
| `[47:16]` | **32** | lane mask, one bit per lane |

Writes a constant 32-bit lane mask to a predicate register. Bit *n* of the immediate becomes
lane *n*'s predicate bit. No width code and no `chwidth` interaction: a predicate is 32 bits
at every element width.

**This subop has no 32-bit form.** A 32-bit instruction leaves 22 bits after the header, the
subop and `pd` — not enough for a 32-lane mask, and a truncated mask would be useless. Nor
does subop `00` have a 48-bit form; its 16-bit register mask already fits. The two subops
therefore live at different lengths, which invariant 7 permits: each exists only at the
length its operand actually requires.

**Why this belongs in the ISA.** Every other predicate write comes from a compare (Format C)
or a vote (Format G), and all of them need sources. There is no path from a constant to a
predicate at all. Worse, `ballot` moves a lane mask from predicate to GPR but nothing moves
it back, so even a mask already computed in a GPR cannot become a predicate. A compile-time
pattern — a half-warp, an alternating stride, a butterfly step in a warp reduction — would
otherwise have no encoding whatsoever. `pmov` closes the constant half of that gap in one
instruction; see O-14 for the dynamic half.

**`pmov` does not drain.** It shares a format tag with `chwidth.multi` but not its pipeline
behaviour: `chwidth` reinterprets the existing contents of a register and must therefore
drain in-flight dependents, whereas `pmov` is an ordinary renamed write to a fresh physical
predicate. Drain semantics belong to the operation, never to the format.

---

## 4. Format A opcode map

10 bits (`[31:27]` ++ `[10:6]`), 1024 points, allocated as follows:

| Range | Contents | Reachable from |
|---|---|---|
| 0–31 | integer, bitwise, misc | A, A′, A″ |
| 32–47 | floating point, 8 ops × format codes `00`/`01` | A, A′ |
| 48–63 | packed dot-product-accumulate | A, A′ |
| 64–127 | conversions, `64 + 16×dest + 4×src + round` | A, A′ |
| 128–255 | unallocated — freed by O-34, previously conversions | A only |
| 256–1023 | SFU (256–263 allocated) and future extension | A only |

**Everything below 128 is now allocated solid.** O-34 packed 32–127 so that
conversions and packed dot-product could both keep a predicated encoding rather
than compete for one range. The consequence is that the two rules that generate
opcodes in this span — `32 + 8×format + op` and `64 + 16×dest + 4×src + round` —
are adjacent with no gap, and the first one's domain is now **format ∈ {`00`,
`01`} only**. `tools/check-encoding.py` rejects any instruction that lands in
48–63 without being a packed dot product (`dp2`, `dp4`, `dp8`), because both sides of that collision would be
well-formed Format A and the decoder would accept either silently.

Per the tier allocation rule, A′'s 7-bit opcode reaches the low 128 and A″'s 5-bit opcode
the low 32. Operations that want predication therefore have to live low, which is why the
ordering above is a constraint on the map rather than a description of it.

### Integer / bitwise / misc — points 0–31

**26 of 32 used.** The numbering is the list order, and it is normative — see O-28.

| pt | | pt | | pt | | pt | |
|---|---|---|---|---|---|---|---|
| 0 | `add` | 7 | `and` | 14 | `min.s` | 21 | `neg` |
| 1 | `sub` | 8 | `or` | 15 | `min.u` | 22 | `popc` |
| 2 | `mul.lo` | 9 | `xor` | 16 | `max.s` | 23 | `clz` |
| 3 | `mul.hi.s` | 10 | `andn` | 17 | `max.u` | 24 | `brev` |
| 4 | `mul.hi.u` | 11 | `shl` | 18 | `mov` | 25 | `prmt` |
| 5 | `mad.lo` | 12 | `shr` | 19 | `sel` | 26–31 | free |
| 6 | `mad.hi` | 13 | `sra` | 20 | `abs` | | |

### Floating point — points 32–47

8 operations × format codes `00` and `01`:

`fadd`, `fsub`, `fmul`, `ffma`, `fmin`, `fmax`, `fneg`, `fabs`

The opcode is `32 + 8×format + op`, with `op` indexing the eight operations in the order
listed and `format` the 2-bit format code — so each format code owns a contiguous block of
eight. `ffma.f0` is therefore 35, which is what the backend already assumed. O-28.

**The rule's domain is `format` ∈ {`00`, `01`}.** Codes `10` and `11` are reserved at every
`chwidth` (below) and the points the rule would generate for them — 48–63 — went to
`dp4`/`dp8` in O-34. Allocating a third or fourth FP format code now requires moving `dp`
first; it is not a free extension.

FP format is encoded in the **format code** rather than as a separate field —
per-instruction, as settled, but at zero additional field cost:

| Register `chwidth` | Format `00` | Format `01` | `10` / `11` |
|---|---|---|---|
| 32-bit | IEEE FP32 | — | reserved |
| 16-bit | IEEE FP16 | BF16 | reserved |
| 8-bit | E4M3 | E5M2 | reserved |
| 4-bit | E2M1 | reserved | reserved |

Mismatching format against a register's actual contents produces deterministic garbage,
not a hazard — compiler-correctness contract, no interlock, consistent with the policy
applied to width mismatches generally. A format code that is *reserved* at the operand's width
is different: it names nothing, and raises `F-FORMAT` at dispatch (§12).

**The narrow formats are OCP's (O-53).** E4M3 and E5M2 are those of the **OCP 8-bit Floating
Point Specification (OFP8), revision 1.0**, and E2M1 is that of the **OCP Microscaling
Formats (MX) Specification, version 1.0**, cited by name and version rather than restated
here. Their special values differ and the difference is normative:

| Format | Infinity | NaN | Max finite |
|---|---|---|---|
| E4M3 | none | `S.1111.111` only | 448 |
| E5M2 | `S.11111.00` | `S.11111.{01,10,11}` | 57344 |
| E2M1 | none | none | 6 |

So format code `00` against `01` at `chwidth`=8 selects two special-value regimes rather than
one layout parameterised by exponent width, and `chwidth`=4 a third with no special values at
all. FP32, FP16 and BF16 are IEEE 754 binary32, binary16 and bfloat16.

**Narrow FP arithmetic — normative (O-56; DA's response IS-8, 2026-10-20).** Every FP
operation at `chwidth`=8 or 4 rounds to nearest even, keeps subnormals, and **saturates to
±max finite**: a result whose magnitude exceeds the format's maximum, including one that
would be infinite because an operand is infinite, gives ±448 for E4M3, ±57344 for E5M2 and
±6 for E2M1. A NaN operand gives NaN where the format has one: `S.1111.111` for E4M3, a quiet
NaN for E5M2. E2M1 has no NaN, so an invalid operation there gives +6, as its conversion
does. E5M2 infinities therefore enter only through loads and are never produced by
arithmetic. At 16 and 32 bits arithmetic is IEEE, with overflow to ±Inf. Daniel's criterion
was consistency with industry: IEEE 754 defines no 8- or 4-bit format, OCP permits saturating
and non-saturating modes, NVIDIA builds only the saturating one, and CCV has no exception
flags for a non-saturating result to signal through. What lost: NaN on overflow at 8 bits and
wrapping at 4.

**Subnormals and NaN selection — normative (O-56; DA's response IS-13, 2026-10-20).** Every
FP format keeps subnormals, as inputs and as results; there is no flush-to-zero mode
(invariant 2) and no flushing instruction. A PTX `.ftz` lowers to the non-flushing operation,
a documented divergence confined to the subnormal range. `fmin` and `fmax` are IEEE 754-2008
minNum and maxNum: a NaN operand gives the other operand, and two NaNs give NaN. That is
PTX's `min.f32` and `max.f32`.

---

### Packed dot-product-accumulate — points 48–63

| pt | Operation | | pt | Operation |
|---|---|---|---|---|
| 48 | `dp4.ss` | | 56 | `dp8.ss` |
| 49 | `dp4.su` | | 57 | `dp8.su` |
| 50 | `dp4.us` | | 58 | `dp8.us` |
| 51 | `dp4.uu` | | 59 | `dp8.uu` |
| 52 | `dp2.bf16` | | 60 | *free* |
| 53 | `dp2.f16` | | 61 | *free* |
| 54 | `dp4.e4m3` | | 62 | *free* |
| 55 | `dp4.e5m2` | | 63 | *free* |

`dp4.*` is 4×INT8 per lane → INT32 with signedness per operand; `dp8.*` is 8×INT4 per lane →
INT32; `dp2.*` is 2×BF16 or 2×FP16 per lane → **FP32**; `dp4.e4m3`/`dp4.e5m2` are 4×FP8 per
lane → **FP32**.

**The numbering is normative, and enumerating it is new in 1.7 (O-47).** Through 1.6 this
block was a list with no point column — the same shape §3's Format B range had before O-41,
and the same exposure O-28 found twice: a range given as a description rather than a table
lets two implementations choose different orders and produce silently incompatible binaries.
It mattered here because **O-44 added four instructions to it**, so the revision that adopted
them would otherwise have shipped them into an unnumbered range. The order chosen is the one
the machine description, the encoder, the disassembler and the simulator already implement.

**The FP entries were added by the AI/ML relevance decision (O-44).** Twelve of sixteen points
are now used; four remain. They are ordinary two-source Format A instructions: four E4M3
values occupy one 32-bit lane exactly as four INT8 do, so FP8 needs no operand model beyond
integer `dp4`'s. Only the 16-bit types are lane-constrained, at two per lane.

**Accumulation order and rounding — normative.** The products are summed **exactly** and the
result rounds **once** into the accumulator. Per-product rounding is not permitted.

This has to be stated and integer `dp4` sets no precedent for it: a sum of four INT8 products
into INT32 is exact, so the order is unobservable and §4 never needed a rule. An FP reduction
is observable, both orders are defensible, and shipping implementations differ. Leaving it
unstated would be an O-28-class gap — two implementations producing numerically different
output from identical binaries, surfacing as a convergence drift rather than as a test
failure. `ffma` already fuses one product with one addend under a single rounding (F-63); this
is the same principle at four products, and choosing it keeps the two consistent.

**The integer reduction is exact, which is why no order is specified for it** — four INT8
products into INT32 cannot overflow or round, so every summation order agrees. The FP rule
above is a deliberate addition for the cases where that stops being true, not an
inconsistency.

**All operands are `chwidth`=32.** `dp4` reads two ordinary full-width registers, interprets
each lane's 32 bits as four INT8, multiplies elementwise, sums the four products and adds
them to the accumulator lane. The packing factor is in the opcode, not in any register's
width — the lane stays a 32-bit register in every other respect, and the packed view exists
solely for the duration of the instruction. `packi`/`unpacki` are the only other instructions
that address inside a lane, and they do it with an explicit slot index for the same reason:
the position has to be named by the instruction because no register can encode it.

This is why they do not violate invariant 1. No register is narrow, no allocation is
affected, the predicate is still one bit per lane, and nothing outside the opcode can
observe the packing. Contrast the model rejected in O-13, where packing was a property of
the *register* and therefore leaked into shuffles, compares, predicates and allocation.

Mixed signedness matters: quantized inference commonly pairs unsigned activations with
signed weights, so all four combinations get a point.

Living at 48–63 makes these reachable from A′ (predicated) but not A″, which is correct —
a dot product has no status output to write.

**These were at 64–127 until O-34**, which needed that range for the conversion product and
found 48–63 free: it is what `32 + 8×format + op` generates for FP format codes `10` and
`11`, which are reserved at every `chwidth` and hold nothing. Twelve points are used of
sixteen. The cost is not paid by `dp` — it keeps its predicated tier — but by the FP block,
whose two spare format codes are now spoken for.

**`mad.lo` remains the alternative**, with `rs0`/`rs1` at narrow `chwidth` and `rs2`/`rd`
wide: one MAC per lane, no packing anywhere. It costs roughly 3× the instructions of `dp4`
for the same work and is the right choice when the narrow data is already register-resident.
See O-15.

Shifts are uniform-amount only: one shift count broadcast across all packed elements, no
cross-element bit movement.

### Conversions — points 64–127

Both formats are **2-bit format codes**, read against their own register's `chwidth` exactly
as `fadd.f0`'s format code is. The instruction names no width, which is invariant 1.

| Code | Read at that register's `chwidth` |
|---|---|
| `00` | FP format 0 — FP32 / FP16 / E4M3 / E2M1 |
| `01` | FP format 1 — BF16 / E5M2 (reserved at 32-bit and 4-bit) |
| `10` | **signed integer** — s32 / s16 / s8 / s4 |
| `11` | **unsigned integer** — u32 / u16 / u8 / u4 |

Codes `00` and `01` are the FP format table above, unchanged. Codes `10` and `11` were
reserved there and are allocated here, which is why an integer source needs no new
mechanism — it was always expressible, just never assigned.

**The arithmetic is normative** (O-34, applying O-28 to the third range that needed a rule
rather than a list):

```
opcode = 64 + 16×dest + 4×src + round
```

| Field | Width | Values |
|---|---|---|
| `dest` | 2 | format code, read at the **destination** register's `chwidth` |
| `src` | 2 | format code, read at the **source** register's `chwidth` |
| `round` | 2 | `rn` 0, `rz` 1, `rm` 2, `rp` 3 |

`dest` and `src` are adjacent so the pair forms one 4-bit field naming the conversion path,
which is what a converter datapath selects on. Rounding is rounding-logic control and sits
in the low bits. 2 + 2 + 2 = 6 bits fills 64–127 exactly.

Worked points:

| | `dest` | `src` | `round` | opcode |
|---|---|---|---|---|
| `cvt.f32.s32` | `00` | `10` | `rn` | 64 + 0 + 8 + 0 = **72** |
| `cvt.f32.u32` | `00` | `11` | `rn` | 64 + 0 + 12 + 0 = **76** |
| `cvt.s32.f32` | `10` | `00` | `rz` | 64 + 32 + 0 + 1 = **97** |
| `cvt.u32.f32` | `11` | `00` | `rz` | 64 + 48 + 0 + 1 = **113** |
| `cvt.bf16.f32` | `01` | `00` | `rn` | 64 + 16 + 0 + 0 = **80** |
| `cvt.e4m3.f16` | `00` | `00` | `rn` | 64 + 0 + 0 + 0 = **64** |
| `cvt.s32.s8` | `10` | `10` | — | 64 + 32 + 8 + 0 = **104** |

The last row is a real instruction, not a formality: `chwidth` reinterprets a register's
elements rather than extending them, so widening an integer is a conversion. Mixed-`chwidth`
operands are established practice — see `mad.lo`, which reads narrow and writes wide.

**Conversions to the narrow FP formats saturate (O-53).** A conversion whose destination is
E4M3, E5M2 or E2M1 rounds as its `round` field says and then saturates to the destination's
maximum finite magnitude; a NaN source gives NaN where the destination has one. There is no
unsaturated conversion to these formats. That is forced, not preferred: E4M3 and E2M1 have no
infinity, so for two of the three it is the only representable answer, and PTX's `cvt` forms
targeting `.e4m3x2`, `.e5m2x2` and `.e2m1x2` take `.satfinite` as a **required** modifier.
**A conversion to FP16 or BF16 is IEEE: overflow gives ±Inf**, as PTX's `cvt.rn.f16.f32` and
CUDA's `__float2half` do. Infinite sources saturate like any other overflow: ±Inf gives
±max finite at all three narrow formats. E2M1 has no NaN, so a NaN source gives **+6.0**, the
positive maximum, whatever its sign. That is NVIDIA's reference conversion in `cuda_fp4.hpp`
(CP's IS-8 response, against CUDA 12.9), and `.satfinite`'s mandatory status was checked
against `ptxas` 12.9. CUDA's `__NV_NOSAT` FP8 conversion is computed in software by NVIDIA's
own headers, so the ISA needs no unsaturated form for it.

**Rounding is meaningless on some combinations** — integer to integer has nothing to round.
Those points are reserved rather than reclaimed, and using one raises `F-ILLEGAL`: the block is a product, and carving
exceptions out of a product costs more than the dead space.

**Being inside 64–127 puts conversions within Format A′'s 7-bit opcode**, so they can carry a
predicate qualifier. That is what O-33's lane-0 masking needs and what the previous
placement at 128+ denied it.

**This resolves O-2, and O-34 amends how.** The destination format is still in the opcode
and the source format still in its low bits, so the two never share a field and there is
nothing to disambiguate. What changed is that the destination is a *code within* the opcode
rather than one of eight bases. The eight-base scheme (`cvt2fp32`, `cvt2fp16`, `cvt2bf16`, …)
distinguished its FP destinations **by element width**, which is an element-width field in
the opcode and therefore a violation of invariant 1 — and it left `cvt2fp16` targeting a
32-bit register with no defined meaning. The format-code scheme has no such case.

### SFU — points 256+

| pt | | pt | |
|---|---|---|---|
| 256 | `rcp.f32` | 260 | `lg2.f32` |
| 257 | `rsqrt.f32` | 261 | `sin.f32` |
| 258 | `sqrt.f32` | 262 | `cos.f32` |
| 259 | `ex2.f32` | 263 | **`rcp.u32`** — integer reciprocal seed (O-35) |

Accuracy of the floating-point set is implementation-defined and approximate, as on every
machine that has one. `rcp.u32` is the exception: it carries a **contract**, because a
compiler-generated sequence depends on it and cannot check it.

**`rcp.u32 rd, rs`** returns an under-estimate of ⌊2³²/`rs`⌋ with 16 bits of relative
accuracy:

> ⌊2³²/`rs`⌋ · (1 − 2⁻¹⁶) ≤ `rd` ≤ ⌊2³²/`rs`⌋

Both halves bind.

**Relative, not absolute.** A reciprocal unit produces N correct leading bits, so the
absolute error scales with the result and a large divisor — whose reciprocal is small — is
cheap to get right. An absolute bound would demand that a 16-bit unit return garbage for
`rs` = 2³¹, where the true answer is 2.

**Never an over-estimate.** The Newton step that follows converges only from below: if the
seed exceeds 2³²/d then `e·d` wraps past 2³² and the correction term becomes huge instead of
small, pushing the estimate further out. This is the same requirement that makes O-31's fp32
path scale by `0x4F7FFFFE` rather than by 2³²; it is now the hardware's to honour rather
than the compiler's to engineer around.

**Sixteen is measured, not chosen.** `tools/model-rcp.py` runs the full sequence against
exact integer division over the edge cases and a large random sample, at every accuracy from
one bit upward. Sixteen is the least that is exact — which is what one Newton step doubling
to 32 predicts — and `tools/check-div.sh` fails on eight cases at fifteen. The simulator
returns the **worst value the contract permits**, so the gate tests the bound rather than a
convenient implementation.

**`rcp.u32` with `rs` = 0 returns `0xFFFFFFFF`**, the saturated reciprocal (IS-12 (d)). 1.8
left it unspecified, which invariant 12 forbids. Division by zero is poison at the language
level and no sequence depends on the value, so the cheapest deterministic answer is the right
one.

## 5. Execution environment and launch ABI

V1.2 had no section here, and that absence was the first thing first-pass compiler work
hit. A kernel needs three things this document never supplied: an address it can form, its
own arguments, and its own identity. None had an encoding.

Scoped to what the *encoding* must state. Byte-level launch-block layout belongs in a
companion ABI document.

### 5.1 Address model

**64-bit width exists only in the computed effective address, never in a register.** For
`.global`, the AGU computes `(rbase << 16) + (rindex << scale) + disp`, giving 48 bits of
reach from two 32-bit registers. `.shared` is flat 32-bit. The shift comes from the address
space, which is already in the opcode, so no format changes and no field moves — see §3,
Format D.

**Why the shift is 16 and not 32.** With a 32-bit `rbase` and 32-bit `rindex` the reachable
window is 4 GiB wide, placed at a multiple of 2^S:

| S | reach | window stride | largest allocation reachable from one `rbase` |
|---|---|---|---|
| 12 | 44 bits | 4 KiB | 4 GiB |
| **16** | **48 bits** | **64 KiB** | **4 GiB − 64 KiB** |
| 24 | 56 bits | 16 MiB | 4 GiB − 16 MiB |
| 32 | 64 bits | 4 GiB | **0** |

`S` = 32 is degenerate. The windows become disjoint, so an allocation is reachable from a
single `rbase` only if it is exactly 4 GiB-aligned; every other allocation straddles a
boundary and needs carry propagation from the offset into the base. The ISA has no
add-with-carry and no carry flag — §4's integer range ends at `prmt` with no carry-producing
add — so that would cost a compare and a predicated increment on every pointer add, in the
inner loop.

For any `S` < 32 the windows **overlap** and the problem disappears: pick
`rbase = addr >> S` for any address and the allocation begins at `roffset < 2^S`, so
anything up to 2^32 − 2^S is reachable without ever touching `rbase`. No allocator alignment
constraint, no carry, no renormalization. 16 puts reach at 48 bits, matching canonical
x86-64 and current GPU virtual-address widths, at a 64 KiB window stride.

**Why this is the right shape rather than the alternatives.** Register pairs would need a
pairing mechanism, which is span — deferred, and structurally awkward at 16 GPRs (§10). A
64-bit `chwidth` code has nowhere to go: the width-code table is full, and 32 lanes × 64
bits breaks the 1024-bit row. A separate address register file adds architectural state and
a rename namespace. This adds none of the three: invariant 1 is untouched, the register file
is unchanged, and the AGU already had a three-input add with a shifter.

**What it costs the compiler.** `getelementptr inbounds` guarantees a derived pointer stays
within its object, which is exactly the property the windowed model needs — so `rbase` is
loop-invariant, loaded once in the prologue, and the inner loop touches only the offset with
ordinary 32-bit arithmetic. **No 64-bit arithmetic appears in generated code at all.**
Against that: every live pointer occupies two GPRs, both warp-uniform, which is the third
of the four arguments in §1 pointing toward 32 GPRs.

### 5.2 The launch block

Launch parameters and kernel arguments live in one CTA-private block of read-only memory,
populated by the launch mechanism, read by ordinary loads. No opcode is required for any of
it.

**It must not carry MMIO memory semantics**, despite being naturally implemented as
memory-mapped registers. Device registers are conventionally uncacheable, non-speculatable
and strongly ordered; apply that here and every kernel prologue becomes a serialization
point. Every warp in a CTA reads the same lines, so uncacheable means an 8-warp CTA pays
full memory latency eight times for identical data, and a non-speculative load sits at the
head of every kernel in a machine whose premise is out-of-order execution.

These reads must be **cacheable, speculatable, reorderable and invariant** — the last so the
compiler can rematerialize a launch value from a constant address rather than spill it,
which matters at 16 GPRs. The ISA already has the right contract: `.const`, read through
`ld.global` and protected by `F-RO` on any store or atomic (§3, O-51). The launch block is
`.const`.

**Entry register state — normative (IS-16).** At kernel entry every GPR reads zero, at every
width and every position; every predicate reads false; and every register's `chwidth` is 32.
No register holds an ABI value, so the launch block (below) is how a kernel finds its
arguments. This costs nothing: launch maps every logical register to the hardwired zero
registers, so no row is written, and it closes the O-38 exposure of a new grid reading a
previous grid's values. *(1.8 said "entry register state is undefined", which invariant 12
forbids.)* The block sits at a fixed architectural address and the
prologue materializes it in one instruction:

```
    movi       R0, #LAUNCH_WINDOW
    ld.global  R1, [R0 + #NTID_X]
```

**The 32-bit form suffices, not the 48-bit one.** What the prologue materializes is the
*window index*, `LAUNCH_BASE >> 16`, not the address — so Format F's 17-bit immediate covers
any launch block below 2^33 bytes. Earlier revisions wrote `f48` here and in both worked
listings, which cost 16 bits per kernel for range no launch block will use. The 48-bit
sibling stays available and is what an arbitrary 32-bit constant still needs.

This keeps the ISA free of ABI, consistent with §3 Format E choosing explicit link registers
over a hardware call stack for the same reason.

**One ABI rule the encoding depends on (O-50).** Format D's launch-slot mode names slot *k* as
the word at launch-block byte offset `OffArgs + 8k`, so it reaches a pointer argument only if
that argument's window word lands there. Therefore:

> Pointer arguments passed **directly** are placed at the front of the argument area, in
> declaration order, so that pointer argument *k* occupies launch slot *k* for *k* < 16.
> **Pointers inside aggregates are out of this rule's scope**: a by-value struct keeps the
> host's layout, its pointers claim no slot, and they reach the AGU through §5.7's in-memory
> representation.

The second sentence is load-bearing. A struct passed by value can carry pointers anywhere
inside it and no front-loading rule reaches them, so without the exclusion the first metadata
struct would violate the rule. Scalars follow the pointers at their natural alignment.

**The launch block's fixed words.** The ISA fixes three: `.local`'s CTA-wide window index at
byte offset 24 (O-30), the module data window `W_d` at 28 (below), and the argument area from
`OffArgs` = 32 (§3 Format D's slot rule). Everything else in the block is the launch ABI's.

**The whole launch window is read-only (O-61).** `LAUNCH_BASE` is 64 KiB-aligned, and the
launch block lies within the 64 KiB region `[LAUNCH_BASE, LAUNCH_BASE + 2^16)`, the addresses
whose bits `[47:16]` equal `LAUNCH_WINDOW`. Each CTA sees its own block there. A store or
atomic to any address in that region raises `F-RO`, unless an earlier cause wins (§12.5). An
address past the block's end is either unmapped (`F-ADDR`) or read-only, so nothing writable
lives in the region, and no module image is placed at `W_d` = `LAUNCH_WINDOW`. The check
needs no per-CTA bound: it is one compare of the effective address against a constant. The
value of `LAUNCH_BASE` is the launch ABI's. `ccv-sim` uses `0x20000`, window 2.

**Where a module's data lives — normative (O-61).** Device code is compiled as a closed module.
Every global it holds (`__constant__` and `__device__` variables, string literals, lookup
tables) is laid out in **one data image per module**: the constant globals first, then the
writable ones.

- **Load.** The runtime loads the image once per module **per context** at
  `W_d << 16`, a 64 KiB-aligned address (§5.1), and writes `W_d` to word 28 of every launch
  block of that module's kernels. One window reaches an image of up to 4 GiB − 64 KiB. A global
  at image offset *o* is the pair (`W_d`, *o*): one launch-block load, warp-uniform and
  hoistable, then an ordinary Format D access.
- **Constant part.** The constant globals occupy `[W_d << 16, (W_d << 16) + const_size)`, which
  is that launch's `.const` range: a store or atomic into it raises `F-RO` (O-51).
  `const_size` needs no padding. The base is 64 KiB-aligned, so with natural alignment (O-58)
  no access straddles it. An access that straddles the limit has its first byte below it. So
  `const_base ≤ addr < const_limit` on each lane's first byte decides §12.3's any-byte rule
  exactly.
- **Writable part.** Writable globals are shared by every launch of the module within its
  context, and never across contexts. This is CUDA's semantics. Their initial state is
  defined (invariant 12, O-38). Initialized globals take the image's values. Every other byte
  is zero, written by the loader, never what memory held before.
- **Relocation.** A data pointer stored in the image is O-54's flat 64-bit address, in a
  naturally aligned 8-byte slot. Its target is known only once `W_d` is chosen. So the image
  carries a list of those slots, and the loader adds `W_d << 16` to each. A **code** pointer
  in the image needs no relocation. It is the target's offset in its code window (§3
  Format E), a constant of the image wherever it is loaded. The code image itself carries no
  relocation.
- **Invariance is per launch.** The cacheable, speculatable and invariant contract above holds
  for `.const` for the duration of a launch. The host may write constant globals between
  launches. The implementation must make such a write visible to the next launch's reads.

### 5.3 `srd` — what a kernel cannot read from memory

A memory location can supply any value that is uniform across its readers. It cannot supply
one that **distinguishes** them, nor one that is not yet determined when the block is
written. The dividing line is:

> **Known when the runtime prepares the launch** → launch block.
> **Assigned when work is dispatched or executed** → instruction.

| Value | Determined | Source |
|---|---|---|
| grid dimensions, block dimensions, kernel arguments, reciprocal constants | launch | block |
| CTA index within grid | dispatch | `srd` |
| thread index within CTA | execution | `srd` |

CTA index is dispatch state, not launch state — the dispatcher assigns it as SMs free up, so
putting it in the block would mean materializing one block per CTA, a hundred thousand of
them for a hundred-thousand-CTA grid. Thread index is per-lane by definition and no single
location can hold it.

`srd rd, #sel` is specified in §3 under Format K. Two selectors are allocated:

| Selector | Value |
|---|---|
| `0` | `%ctatid` — flat thread index within CTA, 10 bits |
| `1` | `%ctaid` — flat CTA index within grid |
| `2–15` | reserved — `%smid`, `%clock`, `%globaltimer` if a workload forces them |

**Everything else derives**, using dimensions the block already carries:

| Wanted | Derivation |
|---|---|
| `%tid.x` (1-D block), `%ctaid.x` (1-D grid) | free |
| `%laneid` | `%ctatid & 31` — one 16-bit reg-imm `and` |
| `%warpid` | `%ctatid >> 5` — one 16-bit reg-imm `shr` |
| `%tid.y/.z`, `%ctaid.y/.z` | `mul.hi` against block-carried reciprocals |

The reciprocals matter because §4's integer map has **no divide**, and the divisor is a
runtime value so a compile-time reciprocal does not apply. The host knows the dimensions at
launch, so it writes the magic multiplier and shift into the block alongside them. This is
only possible because the block is runtime-written memory rather than a hardware register
file — a second dividend from that choice.

**`srd #0` is the only lane-varying instruction with no lane-varying source.** Every other
instruction is lane-wise from lane-wise sources or a broadcast; §3 Format F states that
immediates are warp-uniform, broadcast to all lanes. `srd #0` writes lane *n* with
`warp_base + n` — a broadcast of the warp's base index ORed with a per-lane wire. Selector 1
is a plain broadcast. `chwidth` applies as everywhere else: the destination is written at
its current width and truncates below 16 bits, per invariant 3.

### 5.4 Memory scopes and windowing

`.local`'s thread-private windowing convention (§3, Format D) generalizes. One mechanism,
three scopes, covering everything this revision needs:

| Scope | Serves |
|---|---|
| Thread-private | `.local` |
| Warp-private | predicate spill region — `ld.pred` / `st.pred`, §3 |
| CTA-private | launch block and kernel arguments, §5.2 |

The warp-private scope is what makes `rbase` warp-uniform for predicate transfer, which that
instruction requires. It is not a new mechanism.

### 5.5 Worked prologue

The simplest useful CUDA kernel, fully lowered, exercising every decision in this
revision. The pointer arguments carry no alignment guarantee, so each one costs
two launch-block slots and an in-window fold — the general case.

**This listing is emitted by the compiler, not written by hand.** It is checked
against fresh `ccv-llc` output by `tools/check-spec-vs-codegen.py`, which runs in
`tools/verify.sh`; a divergence is a build failure, not a review catch.

```
    movi       r0, 2                ; 32   launch window (O-28: 17 bits is plenty)
    ld.global  r1, [r0 + 0]         ; 32   blockDim.x, from the block (§5.3)
    srd        r2, 0                ; 16   %ctatid
    srd        r3, 1                ; 16   %ctaid
    mad.lo     r1, r3, r1, r2       ; 32   i = ctaid*ntid + tid
    ld.global  r2, [r0 + 56]        ; 32   n
    setp.le    p0, r2, r1           ; 32   Format C″, unpredicated (O-32)
    @p0 bra    Lexit                ; 32
    shl        r1, 2                ; 16   element index -> byte offset, hoisted
    ld.global  r2, [r0 + 52]        ; 32   b.roffset -- the UNALIGNED half
    add        r2, r1               ; 16   fold; rd == rs0, so Format K
    ld.global  r2, [#2, r2, 0, 0]   ; 32   b[i]; O-45 slot 2 = b.rbase, scale CLEAR
    ld.global  r3, [r0 + 44]        ; 32   a.roffset
    add        r3, r1               ; 16   fold; Format K
    ld.global  r3, [#1, r3, 0, 0]   ; 32   a[i]; slot 1
    fadd       r3, r2               ; 16   compressed destructive, rd == rs0
    ld.global  r0, [r0 + 36]        ; 32   c.roffset
    add        r0, r1               ; 16   fold
    st.global  r3, [#0, r0, 0, 0]   ; 32   c[i]; slot 0
Lexit:
    exit                            ; 16
```

20 instructions, 512 bits — **25.6 bits per instruction**, against 640 for a
fixed-32 encoding, a 20% saving. The compressed forms fire on `srd`, the index
shift, all three offset folds, `fadd` and `exit` without the allocator being
asked for anything.

**All three folds compress here, and that is the allocator's luck rather than a
guarantee.** An earlier listing paid 32 bits on the third because the allocator
landed on `rd != rs0`. `CCVCompress` rewrites a three-operand ALU instruction to
Format K whenever the registers it already has satisfy the constraint, and never
inserts a copy to create one; nothing *biases* allocation toward the tie. See
**F-29** and O-29 for why the hit rate is smaller and less interesting than it
looks. *(1.7's prose said 15%, `por`, and two of three, describing a listing
before O-32 and O-45; the listing above is the generated one.)*

**A compare is one instruction, and used not to be.** Formats C and C′ carry a
**mandatory** predicate qualifier, and with no hardwired always-true predicate (§1) the
first compare in a kernel had nothing valid to be guarded by. O-24 solved that by
manufacturing one: `por pd, !pd, pd` yields all-ones whatever `pd` held, in 16 bits, and
the compare then guarded on the predicate it was about to overwrite.

That worked and it was not free — **13% of dynamically issued instructions in the reduction
kernels**. O-32 adds Format C″, an unpredicated compare, which is what §1's own rule said
should have existed all along: every predicated operation needs a distinct unpredicated
encoding, which is why A/A′/A″ and D/D′ exist. The compare family was the exception, having
spent both its tags on reg-reg versus reg-imm.

The O-24 idiom remains correct and remains the answer for *genuinely* predicated compares;
it is simply no longer on the common path.

Peak live GPRs is **4 of 16**, at `ld.global r3, [r0 + 44]`: the launch window in
`r0`, the byte offset in `r1`, `b[i]` in `r2`, and `a`'s in-window offset. No
pointer base is in a register at any point, because the slot supplies it. The
hand-written version of this listing claimed 8, by holding all six pointer halves
live simultaneously.


### 5.6 The same kernel with an aligned pointer argument

Where a kernel pointer argument is known to be 2^16-aligned, its in-window offset
is zero — so there is nothing to fold, all three arrays share one index register,
and the index can carry an **element** index rather than a byte offset, which
re-enables the `chwidth`-derived scaling of O-7.

**This listing too is emitted by the compiler**, and checked the same way. The
two sections are the same source file compiled twice: `test/cuda/vadd.cu` and
`test/cuda/vadd-aligned.cu` differ only in the alignment attribute on the
pointer arguments.

```
    movi       r1, 2                ; 32   launch window
    ld.global  r0, [r1 + 0]         ; 32   blockDim.x
    srd        r2, 0                ; 16   %ctatid
    srd        r3, 1                ; 16   %ctaid
    mad.lo     r0, r3, r0, r2       ; 32   i = ctaid*ntid + tid
    ld.global  r1, [r1 + 56]        ; 32   n
    setp.le    p0, r1, r0           ; 32   Format C″
    @p0 bra    Lexit                ; 32
    ld.global  r1, [#2, r0, 1, 0]   ; 32   b[i]; O-45 slot 2, scale-enable SET
    ld.global  r2, [#1, r0, 1, 0]   ; 32   a[i]; slot 1
    fadd       r2, r1               ; 16   compressed destructive
    st.global  r2, [#0, r0, 1, 0]   ; 32   c[i]; slot 0
Lexit:
    exit                            ; 16
```

| | Instructions | Bits | Peak live GPRs | Pointer bases in GPRs |
|---|---|---|---|---|
| Unaligned (§5.5) | 20 | 512 | 4 | 0 |
| Aligned (§5.6) | 13 | 352 | **3** | 0 |

The alignment attribute is worth **7 instructions and 160 bits on a 20-instruction
kernel** — a 31% code-size reduction on the smallest kernel that does anything —
and it removes the in-window offset load and fold per pointer.

**Peak live aligned is 3.** `r1` holds the launch window until `ld.global r1,
[r1 + 56]` redefines it, so the window and `n` never coexist; `check-listings.py`
counts a reused register name as one interval and reports 4. *(1.7's table said
23/624/5 and 16/448/4, from listings before O-45 took the bases out of the file;
corrected in 1.8 against the generated listings.)*

**Note what O-7 costs the last row.** Chwidth-derived index scaling was justified
by "`A[i]` is one instruction whether `A` is FP32, FP16 or INT8." It only fires in
the aligned case: unaligned, the effective address wants four addends against a
three-input AGU, so the in-window offset must be folded into the index and
scale-enable stays clear. Alignment is what makes O-7 pay.

**Two of §1's four GPR arguments are contingent on this.** Argument 3 (two
warp-uniform GPRs per pointer) is gone in both shapes, since the slot form keeps
the base out of the file. Argument 4 is 4 of 16 unaligned and 3 aligned, measured
rather than the 8 it was originally built on. Arguments 1 and 2 are untouched.

**Settled: the guarantee is a per-argument alignment attribute.** See O-23.

**Both shapes are implemented.** The unaligned form needs
`(rbase << 16) + roffset + index` — four addends against a three-input AGU — which
is resolved by folding `roffset` into the index with a separate `add` and leaving
scale-enable clear. That fold is what §5.5 costs three instructions on, and it is
why O-7's `chwidth`-derived scaling only fires in the aligned case. O-23's "both
shapes stay supported" is now a statement of fact: see F-27, closed.

### 5.7 A pointer in memory (O-54)

Invariant 11 keeps addresses out of the register file. It says nothing about memory, and a
pointer stored in memory is ordinary data. What a stored pointer looks like is nevertheless
forced, and it is not the register form.

**The in-memory representation is a flat 64-bit address**, 8-byte aligned, little-endian,
identical to the host's `void *`. The (`rbase`, `roffset`) pair of §5.1 is **register-only**:
it exists between a load and the AGU and is never what memory holds. The reason is that some
pointer tables are built by code the CCV compiler never sees. `multi_tensor_apply` builds its
metadata struct in host code and passes it by value, so its layout is whatever the host
compiler produced, and the runtime cannot translate it because it has no type layout for an
opaque by-value argument. The launch block's split form (a window word and an offset word,
§5.2) is available only for data the runtime itself writes.

**Loading one costs about four instructions, once, outside the loop.** Two 32-bit loads,
since there is no 64-bit load and `chwidth` stops at 32, then the split:

```
window = (hi << 16) | (lo >> 16)        ; the rbase for §5.1's (rbase << 16) + roffset
offset = lo & 0xFFFF                    ; the in-window offset, folded into the index
```

The window is valid for any address below 2^48, which is §5.1's reach. No new addressing
mode is needed: a runtime-indexed table of pointers is an ordinary Format D base+index access
to the table, followed by the split. Storing a pointer reverses it, and needs a carry,
because a register-form `roffset` can be anything below 2^32 − 2^16 (§5.1):
`lo = (rbase << 16) + roffset`, `hi = (rbase >> 16) + (lo < roffset)`, unsigned. §4 has no
add-with-carry, so the carry is a compare and a predicated add (see §11's carry-producing
add).

**Interaction with the ABI rule (§5.2).** The front-loading rule covers directly-passed
pointer arguments only, and this is why: a pointer inside a by-value aggregate is in this
representation, at the host's offset, and claims no launch slot.

### 5.8 Narrow floating-point types at the source (O-55)

The compatibility contract is CUDA source and PTX, so the source spelling of FP8 and FP4 is
CUDA's own, from `cuda_fp8.h` and `cuda_fp4.h`. There is no CCV-specific spelling.

| CUDA type | Bytes | CCV register view |
|---|---|---|
| `__nv_fp8_e4m3`, `__nv_fp8_e5m2` (and `__nv_fp8_storage_t`) | 1 | one `chwidth`=8 element; format code `00` / `01` in the instruction |
| `__nv_fp8x2_*` | 2 | one `chwidth`=16 word; reached through conversions |
| `__nv_fp8x4_*` | 4 | one `chwidth`=32 word; the operand of `dp4.e4m3` / `dp4.e5m2` |
| `__nv_fp4_e2m1` | 1 | value in the low nibble; one `chwidth`=4 element after `unpacki` |
| `__nv_fp4x2_e2m1` | 1 | two elements, the lower-indexed in bits `[3:0]`; the unit of memory |

**Layout and ABI.** A scalar is a 1-byte storage type, laid out exactly as `uint8_t`, and the
vector types as the same-sized unsigned integer; arrays are byte-contiguous. A by-value
narrow-FP kernel argument sits at its host offset in the argument area like any scalar of its
size. The format is never in the register: a register holds `chwidth`-wide bits, and the
instruction's format code says how to read them (§4).

**`chwidth`=4 is reached only through `unpacki`.** Memory holds E2M1 packed two per byte, a
load is at `chwidth`=8, `unpacki` takes an element to `chwidth`=4 and `packi` takes it back.
CUDA source cannot observe the restriction, because CUDA has no addressable 4-bit object
either.

**How standard CUDA code reaches the native narrow datapath.** CUDA's FP8 and FP4 types are
storage types: a kernel computes by converting to `half` or `float`, operating, and converting
back with saturation, because PTX's conversion to these formats requires `.satfinite`. So
`fadd.f0` at `chwidth`=8 is reached from unmodified CUDA source only by contraction:
`cvt.satfinite(fadd.f32(cvt(a), cvt(b)))` → `fadd.f0`. The contraction is exact for add,
subtract and multiply when the native operation rounds to nearest even, keeps subnormals and
saturates to ±max finite. For E4M3 and E2M1 the FP32 sum or product of two narrow values is
exact. For E5M2 the FP32 sum can round, but FP32's 24 significand bits exceed 2p + 2 for every
narrow format, so the second rounding is innocuous and the result is the correctly rounded
narrow one. Negation and absolute value are exact; `fmin` and `fmax` contract once their NaN
rule is stated. **Fused multiply-add does not contract**: `cvt(fma.f32(a, b, c))` rounds twice,
and a fused narrow `ffma` rounds once. Native narrow arithmetic saturates (§4, O-56), so the
contraction is exact for add, subtract and multiply. Had overflow given NaN instead, the
contraction would have been illegal and the 4× FP8 datapath reachable only through a CCV
extension; that is why the decision went the way it did.

---

## 6. Encoding density

Three lengths: 16, 32, 48. The 16-bit forms cover the two highest-frequency shapes in ML kernel code
— accumulate-form FMA and two-operand destructive ALU — plus the small-content operations
(`chwidth`, `reconv.hint`, `ret`, `exit`, zero-offset load/store, short branch). Everything
else is 32 bits by default, with the 48-bit sibling available per-instruction wherever an
immediate does not fit. Only CAS and `pmov` require 48 unconditionally.

A GEMM inner loop consisting mostly of accumulate-FMA and pointer arithmetic should
encode at close to 16 bits per instruction. How close depends entirely on how often the
allocator can arrange `rd == rs0`, which is a compiler-backend question, not an ISA one.

Volta-and-later SASS uses 128 bits per instruction — 64 bits of instruction plus 64 bits of
compiler-encoded scheduling control (stall counts, barrier masks, reuse flags).

**That figure is now measured rather than cited.** It was carried from the design
discussion through four revisions of this document with no way to check it; `ptxas` turns
out to be a host compiler that needs no GPU, and the benchmark now runs it. Every kernel
measures **128.0 bits per instruction exactly**, from Volta through Blackwell — nine years
with no change. `docs/benchmarks.md` §2 has the tables.

The predicted "roughly 4×" was close. Measured over the benchmark's ten kernels, CCV
encodes the same work in **27.5 bits per instruction against SASS's 128.0** — 0.21× — and
the same kernels are **3.2× larger as SASS**. What the prediction did not anticipate is the
direction of the instruction count: **SASS uses the fewest instructions of any machine
measured**, 586 against CCV's 859, so the density win is not being paid for with extra
instructions on NVIDIA's side but with 64 bits of control on each of theirs.

The instruction-count ratio moved when the benchmark stopped being only easy kernels.
Compiler-side F-148: the sweep carried eight straight-line or single-loop kernels for eight
revisions, and `sgemm` — the one that spills — had never been compiled for another target
at all, so it was absent. With it in, CCV's aligned build is 1.31× SASS's instruction count
rather than the 0.94× this project published. The bits-per-instruction figure barely moved
(25.9 → 27.5 as gfx900 moved 40.7 → 43.4); **the encoding claim is robust to the kernel set
and the instruction-count claim was not**.

The comparison is still not free, and the reason is unchanged: that control payload buys
NVIDIA static scheduling, which this design replaces with hardware OoO. The density win and
the OoO hardware cost are the same trade viewed from two directions — and the trade is now
quantified on one side of it.

---

## 7. Design invariants

1. **No instruction carries an element-width field.** Width is per-logical-register state,
   set by `chwidth`, defaulting to max (32-bit). Every format — A, B, C, D, G, M, and the
   compressed J and K — respects it. `dp4`/`dp8` are not exceptions: their packing factor is
   opcode space, not a width field, and the registers they read are ordinary full-width ones.
   `packi`/`unpacki` take element width from the narrow operand's `chwidth` like everything
   else; their immediate is a slot index, not a width.
2. **No hidden mode state.** `chwidth` is architecturally committed and non-speculative by
   the time anything downstream observes it (drain-before-issue), so it needs no rename, no
   checkpoint, and no special rollback path.
3. **Width mismatches are compiler-correctness problems, not hardware hazards.** They
   produce deterministic results **or a defined fault**, never undefined behavior. Same for FP
   format mismatches. The faults are the two §12 names: `F-WIDTH` and `F-FORMAT`.
4. **Predication is bounded and signalled by format tag**, never a universal guard operand
   and never an opcode bit. There is no always-true predicate to fall back on.
5. **Predicate registers and GPRs are separate namespaces** with separate RATs. A predicate
   is 32 bits — one per lane — at every `chwidth`, so predicate allocation is uniform and
   never varies with element width. Lane masks are predicates, never GPR-resident data;
   `pmov` (Format I) exists so that constant masks can honour this too.
6. **Sub-row physical allocation never couples retirement.** Every logical register and
   predicate retires independently regardless of physical co-location.
7. **No format encodes an operation it does not lengthen.** If an operation's entire
   content fits in 16 bits, it has no 32-bit encoding; if it fits in 32, it has no 48-bit
   encoding. A longer form must earn its length by carrying something the shorter one
   cannot — more offset range, an explicit register, a predicate qualifier, a predicate
   destination. Reserved bits in a long form where a short form exists are a bug, not
   headroom. Applying this rule removed the 32-bit `ret`, `exit`, `reconv.hint`, `fence`,
   single-register `chwidth`, unpredicated `vote`/`ballot`, and `bar.arrive`/`bar.wait`,
   and deleted Format G′ outright. It also governs which *opcodes* within a format take the
   48-bit rendering: `packi`/`unpacki` carry a 3-bit slot index that gains nothing from a
   wider immediate, so they exist only at 32 bits even though Format B has a 48-bit sibling.
   Format I splits the other way — `chwidth.multi` fits in 32 and has no long form, `pmov`
   needs 32 immediate bits and has no short one.
8. **Register fields sit at fixed positions across format tiers *and lengths*, when
   present.** `rd` at `[14:11]`,
   `rs0` at `[18:15]`, `rs1` at `[22:19]`, `rs2` at `[26:23]`, predicate qualifier at
   `[29:27]`, predicate dest at `[31:30]` — held constant across A/A′/A″, C/C′ and, for the
   fields they use, B/B′/B″, D/D′ and M/M′ — and identically in the 48-bit rendering of any
   of them, since a 48-bit instruction is its 32-bit sibling plus a high halfword. Rename
   lookup starts from fixed wires before format decode resolves, and before length is even
   relevant. Surplus opcode bits go *up* into high positions rather than being carved out of
   the middle, and where a large immediate would collide with the qualifier the immediate is
   split around it (D′, `bra.pred`, and **B′/B″ as of 1.4**) rather than the qualifier being
   moved. **There are now no exceptions among the formats listed above**, which was not true
   before 1.4 — B′ and B″ carried the qualifier at `[21:19]`, and B″ the predicate
   destination at `[23:22]`. See O-22.

   Two formats sit outside the list and always did. **Format G** conforms to the canonical
   positions for the fields it uses. **Format I** does not and should not: `pmov` puts `pd`
   at `[9:8]` and `chwidth.multi` has no canonical slots at all. Format I is metadata with a
   deliberately different shape, reached by its own decode path, and nothing renames from it
   speculatively. Prior revisions claimed no exceptions "among the 32/48-bit formats," a
   wider claim than the enumeration supports; the enumeration is the real rule.

   The compressed forms have their own internal geometry, and **J and K do not share one**.
   Format K is `rd` at `[11:8]`, `rs` at `[15:12]`. Format J is `rd` at `[7:4]`, `rs0` at
   `[11:8]`, `rs1` at `[15:12]` — it carries three register fields in the twelve bits left
   after the class code and subop, so its `rd` has to sit lower. Each is fixed within its own
   class, which is what the rename path needs; prior revisions described a single shared J/K
   geometry that Format J's own bit map contradicts.

9. **Packing lives in an instruction, never in a register.** A register's elements are one
   per lane at its `chwidth`; no encoding names a position inside a lane as a property of the
   register. An instruction may interpret a full-width lane as packed data (`dp4`, `dp8`) or
   name a slot within one (`packi`, `unpacki`), because in those cases the interpretation is
   carried by the opcode or an immediate and disappears when the instruction retires. The
   distinction is not stylistic: register-level packing would make element position depend on
   how the allocator filled a physical row, which invariant 6 exists to keep invisible, and
   it would propagate into shuffle indices, compare results, predicate widths and allocation.
   Design pressure toward packing as a register property is the warning sign. This invariant
   was violated twice during specification — see O-13 and O-15.

10. **A partial write preserves what it does not write.** Three sites ask this question and
    they get one answer. A predicated instruction leaves its destination unchanged in lanes
    where the guard is false — for GPRs this is forced, since it is what predication *means*.
    `packi` preserves the slots its immediate does not name. A predicated write to a
    **predicate** destination likewise preserves the lanes the guard excludes; V1.2 left this
    unstated, and if-conversion cannot be built against either reading without it. The
    mechanism is already universal — every predicated instruction reads its destination, as
    do Format K's 40 destructive points — so preservation costs nothing new anywhere. Where
    a clearing semantic is wanted it is a **separate opcode**, never a change of rule:
    `packi.z` (§3, Format B) is the only one, and `pand pd, ps, !ps` clears a predicate in
    16 bits. **Lanes outside the issuing group are a fourth site, with the same answer**
    (O-62). An instruction changes a lane's GPR elements and predicate bits only if the lane
    is in its issue mask, whatever the instruction, `ld.pred` included. A lane in another PC
    group is another thread, and executes nothing here. A register's `chwidth` is register-wide
    state, not per lane, and is outside this rule.

11. **No register holds a data address.** Data addresses are 48 bits and exist only as the
    output of address generation; the registers feeding it hold at most 32 bits each. This is what
    keeps invariant 1 intact under 64-bit addressing — there is no 64-bit width code, no
    register pair, and no address register file. See §5.1.

12. **Every encoding has defined behaviour.** Every instruction encoding, and every
    combination of an encoding with architectural register state, produces either a result
    or a defined fault. Reserved opcode points, reserved field bits, reserved field values and
    non-canonical encodings all fault; none is ignored, and none is left to the
    implementation. A statement about what the compiler emits is not a specification of
    hardware behaviour: the RTL receives whatever an instruction stream contains, and O-38
    treats this machine as running mutually distrusting contexts. §12 is the fault model.

---

## 8. Open items

Four items remain open; after them come decisions taken since 1.6 and recorded here (O-40 onward). Of the four, two are blocked on the first-pass compiler, one is a check against
the existing barrier spec, and one is a compiler-experimentation question worth answering
early. None blocks RTL work on the settled formats, and **none now blocks compiler work** —
the V1.2 open list contained two items that did, both closed in this revision (see O-17
through O-21 in §9).

O-14 is closed and moved to the decision log.

**O-4 — `reconv.hint` operand shape — specified; one residual re-emit risk.**

The governing principle: the hint's consumer does not exist yet, so it carries **facts about
the program, not directives to the scheduler**. A "wait N cycles" field would freeze a
Phase-1 guess at policy into the encoding; a field describing the control-flow region lets
Phase 2 build any policy it likes on top. This also rules out anything the hardware can
already observe — with independent per-thread PCs, the scheduler *sees* where every thread
is. It does not need to be told.

Three facts survive that filter, and all three are compiler-only knowledge:

| Field | Bits | Meaning |
|---|---|---|
| Alternative path length | `[11:8]` (4) | Static instruction count of the longest path reaching this join, saturating log₂ bucket |
| Nesting depth | `[14:12]` (3) | Relative divergence depth, 0 = innermost, 7 saturates |
| Post-dominator | `[15]` (1) | 1 = every thread that took the dominating branch must pass through here; 0 = partial merge (some path exits or bypasses) |

Eight bits, which is exactly the operand space Format K's compressed form already had
sitting unused — so the hint stays 16 bits and costs nothing it was not already spending.

Why these three:

- **Path length** is what tells the scheduler whether ganging is worth the stall. Holding
  early arrivers is nearly free if the other path is five instructions and expensive if it
  is two hundred. Expressed as a static instruction count rather than cycles, because the
  compiler cannot predict cycles and memory latency dominates anyway. The exact bucketing of
  the 4-bit scale is a decode-table detail and can be tuned later; the **field width** is the
  part that is expensive to change, so that is what is being locked here.
- **Post-dominator** distinguishes "waiting will definitely pay off, all threads arrive" from
  "some threads may never show up." Hardware cannot derive this without walking the CFG; the
  compiler has it for free.
- **Nesting depth** lets the scheduler prefer inner joins, which regain width soonest, and
  avoid holding threads at an outer join that an inner one will feed anyway.

**Residual risk:** if Phase 2 wants the hint *paired* with its branch — a join-PC reference
carried on `bra.pred` so hardware can set up a reconvergence expectation at divergence time
rather than discovering it at the join — that cannot be retrofitted without a compiler
re-emit, because it means touching a second, much hotter instruction whose offset field has
no slack. Deciding this does not require Phase 2 hardware, only compiler experimentation, so
it is worth answering early rather than treating it as a hardware-era question.

**O-8 — Compressed density depends on the register allocator.** *(blocked on compiler)* Format J requires
`rs2 == rd`; Format K's reg-reg range requires `rd == rs0`. Both are natural in
accumulation and in-place-update code and unnatural elsewhere. The break-even fallback
(compressed `mov` + compressed op) means there is no downside risk, but the actual density
win is unknown until the backend exists, and it is worth making destructive-form preference
an explicit allocator objective rather than an accident.

**O-9 — Compressed load/store carries no offset.** *(blocked on compiler)* Points 24–27 imply zero displacement,
which assumes the address is fully precomputed in `rbase`. If real code frequently wants a
small non-zero offset, four opcode points with a 2-bit displacement (scaled by `chwidth`)
would be a better use of the range than four separate address-space opcodes. Needs data.


---

**O-42 — Three-source with an immediate — deferred, and the recorded reason matters.**
`mad.lo rd, rs0, #imm, rs2` has no encoding. The compiler-side proposal rejected the obvious
one — shrink Format B's immediate, put `rs1` at `[22:19]`, immediate at `[31:23]` — on the
grounds that an opcode-dependent immediate position is what invariant 8 forbids. **That
reasoning is wrong and must not stand in the log.** Invariant 8 governs *register* fields and
says so; immediates are not on the rename path. And **Format D already does exactly this**:
base+offset places its immediate at `[31:19]`, base+index at `[31:24]`, same tag `1000`,
selected by `opcode[2]`.

So the option is open, and a 9-bit immediate at `[31:23]` would cover the motivating case
with room over. It is deferred on cost rather than legality: **one instruction in the
benchmark does not justify a fourth Format B sub-layout**, and the asymmetry argument that
carries O-41 does not apply here — no format of any length provides this today, so nothing
is catching up.

Revisit when `sgemm` at larger tiles has been examined for strided addressing. A wrong
reason in the log forecloses an option later on false grounds, which is worse than
recording none.

---

**O-44 — FP packed dot-product-accumulate — adopted.** `dp2.bf16`, `dp2.f16`, `dp4.e4m3` and
`dp4.e5m2` join §4's points 48–63, taking four of the eight that were free. Twelve of sixteen
are now used.

The argument is that the mechanism is already built and measured, and covers the wrong
precision. `dp4.acc` is what `gpr-count-decision.md` credits with making 16 GPRs sufficient
under INT8 accumulator pressure, and the credit is earned: the INT8 GEMM's spill profile is
nearly identical to the FP32 one — same tiles, same addressing, same accumulator count — while
doing four times the arithmetic per accumulator, so spill per MAC lands at 0.51–1.03 against
FP32's 2.07–3.78. **And FP32 GEMM is not the workload.** BF16 or FP16 in with FP32 accumulate
is, and `dp2` gives that case two MACs per accumulator register.

**The FP8 variants are allocated on timing rather than on demonstrated need.** The points are
free today and will not be after a second round, FP8 inference is where the frontier already
is, and both formats are first-class in the ISA with `cvt` support (O-34). FP8 also costs
nothing structurally: four E4M3 fill a 32-bit lane exactly as four INT8 do, so `dp4.e4m3` is an
ordinary two-source Format A instruction.

**Three things the adoption carries.** (1) §10's objection to FP packing is struck, with the
reason recorded there: exponent handling is a property of the reduction, not of the operand
model. (2) The accumulation order and rounding are **normative** — products sum exactly and the
result rounds once — because an FP reduction is observable where the integer one is not. (3)
**`dp2` is 32-bit only.** Format J's subop field is two bits and all four points are allocated,
so the compressed accumulate form is unavailable to it. The compiler-side proposal priced the
ask as though Format J had room; it does not. Whether a compressed `dp2` is worth displacing
one of Format J's two `ffma.acc` points is deferred until `dp2` has been measured at 32 bits —
if the 32-bit form closes the FP32 accumulator cliff adequately the question never arises.

**Mixed-format FP8 is left unallocated, and one point would do it if it is ever wanted.** A dot
product is symmetric in its two operands, so `e4m3 × e5m2` and `e5m2 × e4m3` are one operation
with the registers swapped — the compiler picks the order, exactly as it does for the compare
points F-115 found unreachable. Four points remain free.

---

**O-45 — Launch-slot-relative addressing — adopted, and invariant 8 gains two words.** §3's
Format D takes a third addressing mode at opcodes `01100`–`01111`, in which `[18:15]` is a
4-bit launch-block slot index rather than a register number, so a §5.1 window base never
occupies a GPR.

**The invariant-8 question has a clear answer and the precedent is Format D itself.** `[22:19]`
is already a register field in one mode of tag `1000` and immediate bits in the other, selected
by `opcode[2]`. The renamer already consults the opcode for this tag; adding `[18:15]` to the
conditional set is the same kind of cost, not a new kind. The invariant now reads "when
present", which is what it has always meant and what Format D has always done — leaving it
implicit had cost two review cycles, once in F-110 and once in the proposal that produced this
decision.

The hardware cost is real and unpriced: something must hold or cache the launch block for the
AGU. It is CTA-wide, read-only and small, which makes a cache plausible without making it free.

---

**O-46 — A second register namespace, if ever wanted, must be wanted on its own merits.** The
rejected alternative to O-45 kept `[18:15]` a register field and added a mode bit selecting
which *file* it indexes. That is a second register namespace arriving as a side effect of an
addressing mode, for no encoding benefit over a form the tag already precedents. The
warp-uniform register file (F-106) is the place to want one; see the deferral recorded there.

---

**O-47 — The packed dot-product block is enumerated, not described — decided; the same
normativity fix as O-41.** §4's points 48–63 carried twelve operations in a list with no point
column. That is the shape the Format B range had before O-41 and the shape the conversion
block had before O-34, and it is the exposure O-28 found twice: a range given as a description
rather than a table lets two implementations choose different orders and produce silently
incompatible binaries.

**It became urgent rather than tidy because O-44 added four instructions to it.** A revision
adopting `dp2.bf16`, `dp2.f16`, `dp4.e4m3` and `dp4.e5m2` into an unnumbered range ships four
new opcodes whose encoding is not specified anywhere. Found while auditing this revision
against the decision that produced O-44.

The order recorded is the one already implemented — `dp4.*` at 48–51, the FP four at 52–55,
`dp8.*` at 56–59, 60–63 free — so nothing that assembles today stops assembling, and the
machine description, the encoder, the disassembler and the simulator were already agreeing
with each other about a numbering the document did not state. `tools/check-spec-tables.py`
now checks the table against the machine description, so the agreement is owned by the gate
rather than by whoever last remembered it.

Note the asymmetry with `dp8`: it is specified and has no implementation, so its points are
reserved by this table and by nothing else. That is deliberate — the alternative is leaving
four more points undefined in a block that has now been mis-specified once.

---

**O-48 — Narrow throughput is section co-issue across warps, over warp-private rows — decided
in 1.8; cross-warp row packing is withdrawn.** §1 and §1a described the 1024-bit datapath as
filled by coalescing several independent instruction streams, with the allocator packing
narrow registers from different warps into one physical row. DA's responses OI-28, OI-29 and
OI-31 (2026-10-08) decided a different mechanism: four byte-position sections per lane, a
footprint per operation, disjoint footprints co-issuing, rows owned by one tier-1 slot while
any section is live. The cross-warp part survives, because sections are shared by every
resident warp at select. Only the shared *row* dies. The ladder's scope was then qualified
under AR-16: it is aggregate across warps, and one warp at its home section sees 1.0×. IS-5
first called the mechanism intra-warp, which was wrong in the opposite direction from 1.7, and
OA's IS-5 response corrected both. §1 and §1a.4 carry the text.

**Why it was the largest change in 1.8.** The OOE implementation was building to the section
model while citing §1a obligation 4 as the specification of record. A specification that
describes a mechanism nobody is building is the failure where every row citing it still reads
as grounded.

---

**O-49 — Every write to a 4-bit destination clears its section's upper nibble — decided in
1.8.** Raised as IS-6, agreed on OA's response (2026-10-09). Discharged as write-back masking
in the lane, the cheaper of the two options. The rejected option was clearing on every
widening transition whether or not slices are gained: it fixes the same exposure later and
less locally. §1a.3 carries the text.

---

**O-50 — The launch-slot stride is 8 bytes, and directly-passed pointer arguments come first —
decided.** Raised by the compiler as CP-4, agreed as DA's response CP-4 (2026-10-08), with
IS's condition that the ABI rule be written down and scoped to pointers passed directly.
Implemented in the backend and simulator at commit af55f38, with the gate proving the three
copies of the stride agree. The field names a window index, and §5.2 puts window words 8
bytes apart, so at a 4-byte stride half the slots could never be a legal `rbase`. No encoding
change. 1.7 carried it as an amendment marked in place; §3 and §5.2 now state it. The scoping
sentence is the part most likely to be lost and is load-bearing: without it, the first
by-value struct carrying a pointer violates the rule.

---

**O-51 — `.const` is hardware-protected; a store or atomic into it raises `F-RO` — decided in
1.8.** Raised as IS-3 and ruled by IS. 1.7 specified `.const` as read-only "by compiler
contract". That is a statement about what a compiler emits, and it constrains nothing the RTL
can be handed — the shape of defect the proposed invariant 12 exists to remove. Faulting was
chosen over writable-and-defined on three counts. PTX cannot express a store to `.const`, so
forbidding it costs nothing against the compatibility target. A writable `.const` breaks §5.2's
cacheable-speculatable-invariant assumption, which is the reasoning that already made the
launch block's half `F-RO`. And specifying the two halves differently would itself be a
defect. The cost is one more base-and-limit pair on MIU's CTA channel. `F-RO`'s delivery is the
fault model's (IS-2).

---

**O-52 — No per-access ordering qualifier exists, and same-address loads in a warp stay ordered
— recorded in 1.8.** From IS's OA-13 response (2026-10-09). A-68's `ordering` field was sized
as though the ISA could drive it; Formats D, D′, M and M′ have no ordering bits. Read-read
coherence binds the relaxed atomic load, a plain `ld` cannot be told apart from one, so the
hardware honours the stronger rule. The cheap enforcement is detection rather than blocking:
loads issue freely, and the younger is squashed when an older load to the same address returns
a different value. OA-13's optimisation was deferred to the perf register as PF-28 with that
form as its design. The escalation, if the replay rate proves material, is a per-access
ordering qualifier on Format D, costed as the second claim on its opcode space after O-45.

---

**O-53 — The narrow FP formats are OCP's; conversions to them saturate; conversions to FP16 and
BF16 are IEEE — decided in 1.8, arithmetic overflow open.** Raised as IS-8. The three narrow
formats disagree on infinity, NaN and range, so the names alone did not specify them. PTX
makes `.satfinite` mandatory on every conversion to them, so saturation there is forced.
**What lost, and it was IS's own text:** the amendment set had every narrowing FP conversion
saturating, FP16 and BF16 included, "for consistency". That would have broken
`__float2half`, whose overflow is ±Inf, and was corrected before it landed. Arithmetic overflow
at 8 and 4 bits was decided afterwards, as saturation: O-56.

---

**O-54 — A pointer in memory is a flat 64-bit address; the (`rbase`, `roffset`) pair is
register-only — decided in 1.8.** Raised as CP-3, answered by IS (2026-10-04). Forced by
`multi_tensor_apply`, whose metadata struct is built in host code and passed by value. The
cheap answer, reusing the launch block's split form, is available only for data the runtime
writes, and was rejected for that reason. No new addressing mode. §5.7 carries the split.

---

**O-55 — Narrow FP at the source is CUDA's own types, and `chwidth`=4 is reached only through
`unpacki` — decided in 1.8.** Raised as CP-6, the compiler's blocker for DA's 4× FP8 (IS-7).
A vendor-neutral spelling was rejected because it adds a second surface to keep in agreement
and the contract names CUDA source. The finding that matters more than the mapping: CUDA's
FP8 types carry no arithmetic, so native narrow FP is reached from standard source only by
contracting convert-operate-convert. That contraction is exact only if native narrow
arithmetic rounds to nearest even, keeps subnormals and saturates. §5.8 carries it.

---

**O-56 — Narrow FP arithmetic saturates; subnormals are kept everywhere; `fmin`/`fmax` are
minNum/maxNum — decided.** DA's responses IS-8 and IS-13, 2026-10-20, recorded in the DA tab.
§4 carries the rules. The overflow rule completes O-53, which had settled only the
conversions. It was taken on industry consistency: OCP permits both modes, NVIDIA ships the
saturating one, and no exception flag exists to make a non-saturating result useful. It also
makes O-55's contraction exact. The subnormal rule costs LANE a subnormal path in the FP32
FMA and the compiler a fix to the divide's subnormal quotients (F-62); a flush mode was
rejected as hidden mode state under invariant 2.

---

**O-57 — The fault model is adopted — decided in 1.9.** IS-2, unblocked by DA's response
IS-2 of 2026-10-20, which answered its one sub-question: a fatal fault terminates the context,
not the grid. That was AR's recommendation, because grid scope can turn a fault into a host
sync hang. §12 is `fault-model-spec.md` as adopted, with invariant 12 new and invariant 3
amended. Three corrections were made against the proposed document: context scope; the
replay obstacle struck, per OA's IS-4 response; and FP exceptions aligned with O-56. The RTL
was ahead of the ISA here: the interface and partitioning specs already built to it, with DEC
owning reserved-field checks and CRU the fault record.

**Why this was the missing invariant.** Three places in 1.7 stated a compiler contract where
a hardware behaviour was required: `.const`'s protection, O-37's `opcode[9:7]` constraint, and
the width policy's silence on 4-bit memory access. Each was found independently. Invariant 12
makes the next one a review failure rather than a discovery.

---

**O-58 — Natural element alignment is required — decided in 1.9.** IS-1, agreed in
substance on 2026-10-04 and blocked only on `F-ALIGN` existing. A lane's effective address is
a multiple of its transfer size; a violation raises `F-ALIGN`, per lane, gated by issue mask ∩
predicate. What lost: permitting unaligned access. PTX already makes it undefined, and a lane's
word spanning two lines would break DCU's four-lookups-a-cycle contract, while the check is a
few gates per lane. The compiler half was discharged by CP: `check-align.sh` proves §5.5's fold
preserves alignment for 4-aligned offsets, and `ccv-sim` counts misaligned lane accesses. What
remains is `ccv-sim` faulting rather than counting, so that the oracle agrees with the RTL.

---

**O-59 — A CTA has at most 16 barriers; past its allocation is `F-BARRIER` — decided in 1.9.**
IS-16 item 2, on AR's response. The 6-bit ID was annotated "64 entries — matches the 4×16
table", reading a per-SM table as a per-CTA reach, while the interfaces carry 4 bits ("16
barriers per CTA", `CCV_W_BAR_ID`), so an ID of 16 or more would have wrapped onto 0. Sixteen is
PTX's named-barrier limit, so nothing the compatibility target can express is lost. IDs 16–63
become reserved values, decidable from the encoding, and raise `F-ILLEGAL`. An ID below 16 but
at or above the CTA's allocated count raises `F-BARRIER`, a ninth cause, at dispatch, checked in
OOE against a count RAU supplies. What lost: 64 barriers per CTA, which would widen the ID to 6
bits on both SYU channels for a reach PTX cannot use; and checking in SYU, which has no fault
path back to OOE. No encoding changes: the field stays 6 bits, its top values reserved.

---

**O-63 — `st.pred` stores only the issuing group's bits, merged into the word — decided in
1.9.** IS-18, following O-62. O-62 alone left a shared spill slot unsafe. Group A spills P0,
then changes its own lanes of P0. Group B then spills P0 over the same slot, so the word's
A-lane bits become A's new value, and A's reload returns that instead of what it spilled.
With the merge, each lane's bit in the slot is written only by its own thread, so a slot is
per-lane storage. AR priced it (AR's IS-18 responses). `st.pred` stays a store, and MIU's
post-commit drain reads the word, merges it under the store's mask, and writes it: about 32
two-input muxes. No channel gains a field, and DCU, OOE and LANE are unchanged. AR's first
form, the atomic path, was dropped because it would have stalled the ROB head on every spill
(OA's IS-18 response). The region is warp-private (§5.4), so no other agent contends, and the
warp's in-order commit makes each word's merge indivisible. What lost: (a) bit-granular write
enables in DCU, which touch every write port for one rare op; (b) the atomic path, with its
head-of-ROB stall; and the compiler-only rule (full-word spills only in converged code, a per-lane GPR path elsewhere),
which needs a free GPR at the moment of pressure. A predicate spill now costs a
read-merge-write instead of a plain store, and spills are rare on four predicates.

---

**O-62 — An instruction writes only the lanes of its issue mask, `ld.pred` included —
decided in 1.9.** CP-11. The compiler spills predicates with `rbase` = R15,
so every group of a diverged warp spills a given predicate to lane 0's slot. `ccv-sim`
restored all 32 bits on `ld.pred`, so one group's reload overwrote another group's live bits.
That is a write to a thread that executed nothing. Invariant 10 already preserved lanes the
guard excludes, and per-thread PCs (§1) make a lane in another group the same case, so the
invariant now says so. It should need nothing new in hardware: a write by a group smaller
than the warp already reads its destination and merges the other lanes, the core's implicit
old-destination source. OA is asked to confirm that `ld.pred`'s predicate write takes it. What it does not settle: with `st.pred`
storing the full word, a shared slot is still unsafe for groups live at once. The fix is
either a bit-masked `st.pred` or a per-group slot in the compiler, and it is IS-18's. What
lost: the full-width `ld.pred`, which is the only reading under which one thread's reload
changes another's state.

---

**O-61 — A module's data lives in one image per module, its window in launch-block word 28 —
decided in 1.9.** CP-10, from the CoreMark-derived workload (AR-20). `core_state.c` reads
constant tables of string pointers by a runtime index. Until now the backend had no data
section, and nothing told a kernel where O-51's `.const` range was. CP's proposal
(CP-10, on CP's branch) is adopted with IS's four additions. Code pointers
need no relocation. The writable part's initial state is defined, zero where not
initialized. The image is per context. Invariance is per launch, so host writes between
launches are allowed. TI confirmed word 28 is free in its launch model (TI's rev 108); the
core never decodes the launch block. What lost: rejecting pointers in initializers, which rules
out CoreMark and every string table; per-launch copies in the launch block, which are wrong for
writable globals and grow the block; and a launch *slot* for `W_d`, which would save one load
per function but move every argument by 8 bytes, deferred until a measurement asks for it. No
encoding changes.

---

**O-60 — Forward progress between diverged lanes is guaranteed — decided in 1.9.** IS-17,
raised while answering TI-24 (3). DA's words: "Yes, we must make a progress guarantee" (DA
tab, IS-17). The ISA had per-thread PCs and no statement about whether a diverged group that
can run must eventually run. Strict min-PC scheduling then hangs a spin-wait, and a group bound
below 32 that holds a split until groups merge hangs the same pattern. Both are correct code on
NVIDIA hardware since Volta. Adopted: CUDA's guarantee, normative in §1, stated as a property
and not a mechanism. AR's pricing (IS-17) gives the first build's form: per-lane PCs in the
window, 1,008 bits a warp against 384 for four groups; a rotating-lane fairness pointer of
about 10 flops a warp; and min-PC kept as a reconvergence heuristic that may be a cycle stale.
What lost: no guarantee, as before Volta. That kept four groups and strict min-PC, and would
have hung intra-warp locks that no compiler can detect. Also withdrawn: IS's first proposal, a
group bound with the split serialized. It deadlocks, because the held lanes may be the
producer. No encoding changes.

---

**O-43 — A hardwired zero register — rejected.** Proposed on the strength of five
`movi rX, 0` in the benchmark. Checking what each feeds dissolves it: **two** are `setp.eq`
against zero and Format C′ already carries the immediate compare, so they are a selection
gap; **two** are loop accumulators, which need a writable register initialised to zero and
would still cost `mov rd, rz`; **one** is `mad.lo rd, rs0, rs1, #0`, which is a multiply, and
§4 point 2 already specifies `mul.lo`. None is an argument for spending a register.

The cost is decisive on its own: the file is 16 (§1), R15 is reserved for the frame pointer
under O-30, and a hardwired zero would leave **14** general registers while O-25 and the
32-GPR question are open.

Recorded so the `movi rX, 0` pattern is not re-proposed from the same evidence.

---

**O-41 — Format B's opcode map, by projection from §4 — decided; a normativity fix, not an
optimisation.** Format B's 32 opcode points were described and never enumerated: §3 said the
space was "ample" and named informally which operations lack an immediate form. **That is
the O-28 exposure a third time** — a range given as a description rather than a table lets
two implementations choose different orders and produce silently incompatible binaries.

The closure is a rule rather than a flat list, so it is derivable and a decoder can share
§4's map: **where §4 point *n* is binary, Format B point *n* is that operation with the
second source replaced by the immediate; where §4 point *n* is unary or ternary, Format B
point *n* carries no immediate form.** `addi` at 0 against `add` at 0 was already this,
applied unaided by the backend.

Nine points follow from it: `subi` 1, `muli` 2, `andi` 7, `ori` 8, `xori` 9, `andni` 10,
`shli` 11, `shri` 12, `srai` 13. No field moves, no new decode path, and the 48-bit sibling
comes free under §2's existing rule.

**It would have been closed even with nothing to gain.** What it happens to gain is three
instructions on the benchmark: the 16-bit compressed format carries eight register-immediate
ALU forms and the 32-bit format carried one, so an operation was encodable only when the
destination *was* the source and the constant fitted `uimm4`. See §3's Format B map for the
arity table the rule depends on, the `sel` tier exception, and what the projection costs in
allocatable points.

---

**O-40 — Narrow element work retires faster — decided; the ratio is a hardware target, not
a measurement.** The datapath allocation splits so that 16-bit element work retires at twice
the 32-bit rate. This is the return on the element-width model: invariant 1 keeps width out
of the opcode so that a narrow instruction is the same instruction on a narrower slice, and
two such slices share one 32-bit allocation.

Recorded as an obligation in §1a.4 rather than as an encoding change, because **nothing in
the encoding expresses it** — no bit anywhere says "this retires at 2×". The width is
register state, the retire rate follows from the width, and the compiler's only lever is how
much of the instruction stream it can make narrow.

The benchmark now measures that fraction, and it is the number this decision lives or dies
on: `vadd16` reaches **28.6% narrow element work** at one element per thread and
**`vadd16_loop` reaches 55.2%**, where the per-thread prologue amortizes over eight
elements. At 2× that is 1.067× and 1.283× against the same kernels at 32 bits.

The fraction is raised only by removing what is **not** element work — invariant 1 puts one
element in a lane at every width, so a narrow kernel issues exactly as many element-work
instructions as its 32-bit twin and the difference is all overhead. F-80 and F-87 are that
work on the compiler side. See §1a.4 for why the memory pipe matters more than the ALU.

---

**O-11 — withdrawn.** The number was assigned during the V1.2 deep dive and its decision was
folded into a neighbour before either was written up, leaving a gap rather than a decision.
Recorded here so the gap is deliberate: `tools/check-docs.py` only verifies that *cited*
O-numbers resolve, so an unused number is invisible to it and would otherwise read as a lost
decision on every future audit. Nothing references O-11 and nothing should.

---

**O-12 — Barrier operand split — decided; one assumption to confirm against the barrier spec.**

The three barrier operations need very different amounts of operand, and the previous split
had them backwards:

- **`bar.init #id, count`** genuinely needs 32 bits. A 6-bit barrier ID plus a 10-bit
  expected arrival count is 16 bits of operand and the compressed forms have 8. This is the
  only barrier operation that carries the expected count — it is configuration state for the
  table entry, set once, not something an arriving thread supplies.
- **`bar.arrive #id`** needs only the ID. The earlier 10-bit count field on this instruction
  was misplaced: with independent per-thread PC scheduling, threads arrive individually, so
  an arrival is inherently one arrival. There is nothing for a count field to mean here. The
  compressed form was not "hardwiring count = 1" — count = 1 is the only sensible semantic.
- **`bar.wait #id`** needs only the ID. **This bullet originally gave it a phase-parity
  bit and called the parity software-tracked; that is superseded by O-27, which found
  the compiler cannot alternate an immediate across dynamic executions.**

**The assumption that needed checking — and failed.** O-12 assumed the wait's phase parity
could be **software-tracked**: the compiler alternates the bit each time through the loop,
and the comparator matches it against the table entry's epoch parity. That would keep `wait`
at seven bits of operand and keep all per-warp barrier state out of the machine.

The compiler cannot do it. See **O-27**, which resolves this by taking the alternative O-12
named — the barrier table tracks a per-warp arrival epoch, so the ID alone suffices — and
adds a separate explicit-phase instruction for the case hardware tracking structurally
cannot serve.

---

**Opened in 1.9 by the fault model — states invariant 12 now forbids leaving undefined.**

**Barrier references beyond a CTA's allocation** — opened and closed in 1.9 (O-59): a CTA has
at most 16 barriers; IDs 16–63 raise `F-ILLEGAL`, and an ID at or above the CTA's allocated
count raises `F-BARRIER` at dispatch (§12.3).

**Entry register state** — opened and closed in 1.9: every register reads zero (false for
predicates, `chwidth` 32) at entry, §5.2, at no cost (OA's IS-16 response).


## 9. Decision log — resolved during specification

Recorded because the reasoning matters more than the outcome if any of these is revisited.

**O-1 — Predication mechanism — resolved.** Predication is signalled by **format tag**
everywhere: A/A′/A″, B/B′/B″, D/D′. Format D got tag `1101`, freed by the invariant-7
deletions. Consequence: the prime suffix now means "predicated" consistently, so the old
Format D′ (atomics) was renamed **Format M**, with the 48-bit CAS form as M′.

**O-2 — `cvt` two format specifiers — resolved; amended by O-34.** Destination format is in
the opcode, source format in its low bits, widths from `chwidth` on each register. The two
formats never share a field, so there is nothing to disambiguate.

**O-34 amends how the destination half is spelled**, and does not reverse this. The original
form named eight destination *bases* (`cvt2e4m3`, `cvt2bf16`, …); the destination is now a
2-bit format code read against the destination register's `chwidth`, symmetric with the
source. The reason is invariant 1: `cvt2fp32` and `cvt2fp16` differ only in element width,
so the base was an element-width field in the opcode. See §4 and O-34.

**O-3 — SFU operations — resolved.** Format A's opcode is now 10 bits (1024 points) with only
64 allocated. `rcp`, `rsqrt`, `ex2`, `lg2`, `sin`, `cos` and their rounding-mode variants
land in the extension space above 64, where they are reachable from A but not from A′/A″ —
which is correct, since predicated transcendentals are rare.

**O-5 — Immediate widths — resolved.** Every immediate-carrying format has a 48-bit
sibling under the same tag with 16 extra immediate bits at `[47:32]`. Short form when it
fits, long form when it does not, no new tags and no fields moved.

Laying this out replaced the original long-form header. That scheme escaped through
`[1:0]`=`11` into a sub-length field with the format tag at `[7:4]`, which pushed every
field in a long instruction up by two bits and made register positions vary with length —
quietly breaking the alignment property established one revision earlier. Collapsing
64/96-bit support into a single tag's private business buys those two bits back and makes
the encoding uniform across all three lengths.

**O-6 — Multi-register `chwidth` — accepted.** Format I carries the 16-bit register mask
form and nothing else. Compiler placement discipline covers the widened drain scope.

**O-7 — Scaled index addressing — resolved.** Base + (index << chwidth) + displacement, with
a scale-enable bit. See Format D.

**O-10 — Format D′ field alignment — resolved.** Split the offset around the qualifier:
low bits at `[26:19]`, high bits at `[31:30]`, qualifier at the canonical `[29:27]`. Keeps
the full 10-bit offset, keeps the sign bit at 31, keeps every register field in place.

**O-13 — Constant predicate masks — added in 1.1.** V1.0 had no encoding that produced a
predicate from a constant. `pmov pd, #lanemask` (Format I, subop `01`, 48-bit) fills it.

Specifying it exposed a modelling error that had propagated through V1.0 and needed
correcting alongside: several sections described narrow `chwidth` as packing multiple
elements into a lane, and reasoned about "sub-element" masks and indices on that basis. That
is the packed-SIMD model, not this machine's. A GPR always holds 32 lanes; narrow width
makes the register a **narrower slice**, and the datapath is filled by coalescing independent
32-lane instructions. Nothing indexes below lane granularity. The corrections:

| Location | V1.0 said | Corrected |
|---|---|---|
| §1 | (unstated) | Lane model now stated explicitly, so it cannot be re-derived wrongly |
| Format C | packed compares produce a width-matched predicate | one bit per lane, always; no width interaction |
| Format G | shuffle index is 8 bits, thread × sub-element | 5 bits, lane only; `[26:24]` freed |
| Invariant 5 | predicates "physically narrow when narrow suffices" | predicates are 32 bits at every width; allocation is uniform |

This also simplifies the physical register file: predicate instances are uniformly sized, so
only GPR rows need sub-row subdivision.

**O-15 — `dp` reads full-width operands — settled after two wrong turns.**

V1.0 specified `dp` with *narrow* sources: `rs0`/`rs1` at their own narrow `chwidth`,
accumulator wide. That is unimplementable. Narrow registers hold one element per lane, so
the four bytes a dot product must reduce live in four different logical registers, and
gathering them would mean naming physical adjacency that invariant 6 exists to hide.

Deleting the opcode was then considered, on the reasoning that `mad.lo` with mixed widths
does the same work and that narrow throughput comes from the coalescer. The first half is true; the second was too
glib. The coalescer fills the *datapath*, not the front end — four narrow MACs still occupy
four decode slots, four rename ports and four ROB entries, and in a GEMM those are scarcer
than multiplier area. Writing out both inner loops makes it plain: 14 instructions per four
k-steps against 5, and 26 against 5 at INT4.

The form adopted here reads **full-width operands** and interprets each lane's 32 bits as packed
data internally, with the packing factor in the opcode. The packing is then visible only
inside the instruction — registers stay ordinary, allocation is untouched, predicates stay
one bit per lane, shuffles are unaffected. That is what distinguishes it from the register-
level packing model rejected in O-13, and it is why the principle that survives is narrower
than a blanket ban on packing:

> **No register holds more than one element per lane.** An instruction may still interpret a
> full-width lane as packed data. Design pressure toward packing as a property of a
> *register* is the warning sign, not packing inside an opcode.

`dp` is profitable when the packed operands come from memory, since a wide load delivers
them already packed: 3 instructions per four k-steps against 12. Composing them in-register
costs 8 `packi` plus one `dp4`, which never beats four `mad.acc`. `dp` therefore pays off on
memory-sourced data and `mad.lo` is the right choice for register-resident narrow data. Both
are encodable; the compiler picks.

One layout consequence: `dp` wants both tiles k-contiguous per output index, so the B tile
needs transposing during global→shared staging. Standard practice, amortized per tile, but
not free.

**O-16 — `packi` / `unpacki` — added in 1.2 on completeness grounds.**

These are not performance instructions and the spec should not pretend otherwise. Feeding
`dp4` from register-resident narrow data costs 8 `packi` plus one `dp4` for four k-steps,
against four `mad.acc` — never profitable. Packing narrow results for a wide store is 4
`packi` plus one store against four narrow stores, a wash. The instruction count rarely
favours them.

They are in the ISA because their absence was a hole in the type system. Composition could
at least be synthesized (widening `cvt`, `shl`, `or` — three instructions per element).
Decomposition could not be synthesized at all: no other instruction moves a slice of a wide
register into a narrow one, so packed data loaded from memory was readable by `dp4` and by
nothing else. An ISA that can construct a value it cannot take apart is incomplete, and the
gap would have been discovered by a compiler writer rather than by us.

The `rd`-as-source deviation in `packi` is the only one in Format B. It is unavoidable —
insertion must preserve the slots it does not write — and free under renaming.

Not included: a register-sourced slot index. Slot numbers are compile-time constants in
unrolled code, and a variable slot would want a different operand shape. Revisit only if
compiler output shows dynamic slot selection actually arising.

**O-14 — `unballot` — added in 1.3; the trigger condition had already fired.**

V1.2 deferred `unballot` pending "workload evidence" that a computed lane mask needs to
become a predicate. Register allocation is that evidence, and it does not need a workload.

A predicate could be spilled — `ballot` moves the lane mask to a GPR, which can be stored —
but never reloaded. `pmov` is constant-only, and every other predicate write computes one
bit per lane from GPR sources under a fixed rule, none of which can reproduce an arbitrary
per-lane pattern held warp-uniformly in a register. So the predicate file had **no legal
spill/reload path at all**, with four entries, in a machine whose per-thread PC model pushes
toward if-conversion. A register class that cannot be spilled is one a compiler cannot
guarantee to compile — it can only fail.

The fix is two instructions, not one, because two different problems were conflated.
`ld.pred`/`st.pred` (O-19) handles spill and reload. `unballot` handles what O-14 originally
described: a mask that was *computed* rather than saved. Neither substitutes for the other.

---

**O-17 — Address width — resolved.** The effective address is `(rbase << 16) + roffset`,
48 bits, formed only inside the AGU. V1.2 never stated an address width anywhere, and the
widest value a GPR lane can hold is 32 bits, which caps the address space at 4 GB —
irreconcilable with 64-bit device pointers from the CUDA Runtime API.

The shift is 16 rather than 32 because at 32 the windows are disjoint, making every
non-4 GiB-aligned allocation require carry propagation the ISA cannot express; at any
smaller shift the windows overlap and the problem disappears entirely. Full reasoning and
the alternatives rejected are in §5.1.

One consequence is recorded against O-7 rather than hidden: the wanted address has four
addends against a three-input AGU, so `rindex` also serves as the in-window offset, carries
bytes rather than elements in the general case, and leaves scale-enable clear.
Chwidth-derived scaling therefore fires for `.shared` and for 2^16-aligned allocations
rather than universally. O-7's reasoning survives; its scope narrows.

---

**O-18 — Special-register and launch-ABI surface — resolved.** Carried in V1.2's §10 as a
deferred item, "not encoding-blocking so far." It was blocking the first instruction of the
first kernel: nothing in V1.2 could read a thread index, find a kernel argument, or state
what a register held at entry.

Resolved by §5 in three parts, of which only the third costs an opcode: launch parameters
and kernel arguments in a CTA-private read-only block; entry register state left undefined,
with the prologue materializing a fixed address through the 48-bit Format F form; and `srd`
for the two values no memory location can supply. Sixteen selectors, two allocated.

The reason this was not caught earlier is worth recording. This document specifies from the
inside out — operations, formats, density. A launch ABI is the *boundary* between a kernel
and its runtime, which is precisely what an encoding-focused specification does not surface.
V1.2's own note that "O-13 is the first decision that leaned on its absence" was the warning.

---

**O-19 — Predicate transfer — added in 1.3.** `ld.pred` / `st.pred` with a 4-bit predicate
mask in the `rdata` field, Format D base+offset unchanged. See §3 and O-14 above.

The multi-register form is included here although span transfers stay deferred for GPRs
(§10), because all three reasons for that deferral either fall away or invert. The one that
inverts is the structural one: a four-register group at 16 GPRs leaves four legal aligned
destinations, whereas a 4-bit mask over a 4-entry file has no alignment constraint and all
sixteen combinations are legal. And N predicate accesses from one instruction need no decode
cracking, because the predicate RAT is four entries and writing all four is a write enable,
not a sequence. The mask is free in encoding terms — `rdata` is four bits whether it carries
a mask or four reserved bits.

---

**O-20 — Predicate logic — added in 1.3.** `pand` / `por` / `pxor` / `pmov`, Format K points
60–63. V1.2 had **no predicate-to-predicate operation of any kind**: every predicate write
came from a compare, a vote, a status-producing ALU op, or a constant, and predicates could
be consumed only as a guard qualifier.

That is what made four entries bind. Predicate combining is the fundamental operation of
if-conversion — `if (a && b)` and any nested divergent region want `P2 = P0 AND P1` — and
without it a combined predicate has to be re-derived by a predicated compare, which keeps
both the source predicate and the compare's GPR operands live across the region.
Combine-and-free is what keeps the file viable past nesting depth three.

Four points, not more. The set is functionally complete at three — all sixteen two-input
boolean functions, verified by enumeration — and the fourth buys rename-time elision of
predicate copies. Filling out the remaining space was declined: the ALU cost of another
boolean function is nil, but the scarce resource is Format K opcode points, which carry the
entire compressed instruction set and are the only headroom the 16-bit forms have.

---

**O-21 — `packi` partial writes — resolved; `packi.z` added.** `packi` preserves, as V1.2
specified. The alternative — clearing the unwritten slots, so `rd` is not an implicit
source — was considered and rejected on three grounds.

The implicit-source cost is already paid machine-wide: predication requires every predicated
instruction to read its destination, and Format K's destructive ranges add 40 more points.
`packi` is a full-lane read-merge-write, not a partial physical write, so there is no
partial-register hazard of the kind that motivated VEX zeroing on x86. And clearing would
turn a four-instruction dependent chain into four independent `packi` plus a three-deep OR
tree with four live temporaries, costing `packi` the one use case O-16 rates break-even —
on an instruction O-16 keeps for type-system completeness, not performance.

What preservation genuinely costs is a false dependency at the head of a compose chain,
which `packi.z` removes at one opcode point. This is the VEX lesson applied as an available
semantic rather than as the only one, and it generalizes into invariant 10.

---

**O-22 — Format B′/B″ predicate qualifier position — resolved in 1.4.**

Invariant 8 fixes the predicate qualifier at `[29:27]` and the predicate destination at
`[31:30]`, names B/B′/B″ among the formats it governs, and states that where a large
immediate would collide with the qualifier the *immediate* is split around it rather than
the qualifier being moved. B′ and B″ did the opposite: qualifier at `[21:19]`, and in B″ the
predicate destination at `[23:22]`.

This was not cosmetic. Register fields were never the whole point of invariant 8 — the
qualifier feeds the **predicate RAT**, which invariant 5 keeps as a separate namespace with
its own rename path. With B′/B″ at `[21:19]` and every other predicated format at `[29:27]`,
that path needed a format-dependent mux: precisely the cost the invariant exists to avoid,
and the reason D′ went to the trouble of splitting its offset in O-10.

The fix is the technique the document already contained, applied one format further:

| | Layout | Immediate |
|---|---|---|
| B′ | `imm[7:0]` at `[26:19]`, `pq` at `[29:27]`, `imm[9:8]` at `[31:30]` | 10 bits, MSB at 31 — unchanged |
| B″ | `imm[7:0]` at `[26:19]`, `pq` at `[29:27]`, `pd` at `[31:30]` | 8 bits, MSB at 26 — unchanged |

No immediate loses a bit. B″'s sign bit moves from 31 to 26, joining C′ rather than forming
a third position, and B″'s field layout becomes **identical to C′'s** — a consistency the
previous arrangement forwent for no gain.

**How it was found, and why that matters.** Not by reading. The §3 tables were transcribed
into a TableGen target description, and a checker compared every field's bit span against
invariant 8's canonical positions. Three deviations came back, all in B′/B″. The proposed
fix was then verified the same way: build both layouts, re-run the checker, confirm zero
deviations, confirm immediate widths unchanged, confirm the generated encoder and
disassembler still build. Prose review had passed this encoding across three revisions.

---

**O-23 — Kernel-pointer alignment — settled as a per-argument attribute.**

§5.6 shows a 2^16-aligned pointer argument costing one GPR instead of two, removing the
in-window offset fold, and re-enabling O-7's index scaling: 16 instructions and 5 live GPRs
against 23 and 8. The question was how a kernel comes to know.

**Rejected: a blanket ABI requirement** that every device pointer be 2^16-aligned. Framework
sub-allocators would have to pad every tensor to 64 KiB, which is untenable when a model
holds thousands of small ones.

**Rejected: a runtime check with two code paths.** It sounds like it gets both cases, and it
gets neither. Register allocation is static and occupancy is set by a kernel's *maximum*
register count, so a kernel carrying both paths pays the unaligned peak regardless of which
path runs. The saving that matters is not recovered.

**Adopted: alignment is a property of each kernel pointer parameter.** The frontend marks
the arguments the runtime can vouch for — clang's existing `align_value` attribute lowers to
LLVM's `align` parameter attribute — and the backend emits the one-register form for exactly
those. Mixed kernels degrade per argument rather than per kernel.

Three consequences worth fixing here rather than leaving to the ABI document:

- **The launch block layout does not change.** A pointer argument occupies two 32-bit slots
  whether or not it is aligned, and the runtime always writes `addr >> 16` and
  `addr & 0xFFFF`. The attribute changes only what the *prologue loads*: an aligned argument
  skips the second load because the value is known zero. Keeping the layout
  attribute-independent means the runtime never needs to know which kernels declared what.
- **The backend should not read the attribute directly.** It should ask whether the address's
  low 16 bits are known zero, which is the standard alignment query and is strictly more
  general — it also fires where alignment is provable for other reasons, and it inherits
  LLVM's existing propagation through `getelementptr`. The attribute is one source of that
  knowledge, not the mechanism.
- **A false attribute is a silent wrong answer**, not a fault: the low bits are simply
  ignored and the access lands elsewhere. This is the failure mode that warrants a
  validation harness rather than a compile-time check — the runtime can verify declared
  alignment at launch, cheaply, and compile the check out of release builds.

---

**O-24 — Every compare is predicated, so a kernel must manufacture a true predicate.**

Found by executing a kernel rather than by reading one.

Formats C and C′ both carry a **mandatory** predicate qualifier at `[29:27]`, and the format
tag table has no unpredicated compare. So every compare is guarded. Combined with §1's "no
hardwired always-true predicate," the first compare in a kernel has nothing valid to be
guarded by — the predicate file's contents at kernel entry are undefined, and there is no
`PT`.

This is a real gap in §1's own rule. That rule says every predicated operation requires a
distinct unpredicated encoding, which is why the A and B ladders and the D/D′ pair exist.
C/C′ are the exception: there is no unpredicated compare, and the tag space is full, so
there cannot be one.

**It resolves without an encoding change, because compressed forms are never predicated.**
`por pd, !ps, ps` is all-ones whatever `ps` holds, in 16 bits, and Format K carries no
qualifier to need satisfying. One instruction per kernel.

Worth noting what this cost before 1.3. The only constant-to-predicate path was `pmov`,
which exists **only at 48 bits** (Format I, O-13). Every kernel would have opened with a
48-bit instruction to manufacture something the machine could have hardwired. The Format K
predicate logic added in O-20 was justified on if-conversion pressure; that it also makes
the kernel prologue viable was not noticed until a kernel was run.

**Alternatives considered and rejected.** An unpredicated compare format needs a tag, and
all sixteen are allocated. Reserving `P3` as architecturally all-ones at entry is a soft
`PT` that spends a quarter of a four-entry file to save one 16-bit instruction per kernel.
Neither is worth it: the idiom is cheap, and it is now documented rather than something each
compiler author rediscovers.

**Addendum, 1.5 — it is once per compare, not once per kernel, and the destination matters.**

Every *semantically unpredicated* compare needs a true guard, not just the first one:
compares inside loops, and everything if-conversion emits, all need one. So a true predicate
held live across a compare-heavy region would occupy a quarter of the file throughout —
effectively three usable predicates, not four.

Two properties rescue it, and the order matters. **The primary strategy is the
self-guarding form: guard and destination the same predicate.** The compare consumes
the all-true value as its qualifier and overwrites that same register with its result,
so the idiom costs **no additional predicate at all**:

```
    por        P0, !P0, P0        ; 16   P0 = all ones, whatever it held
    @P0 setp.lt P0, R1, R4        ; 32   guard on P0, overwrite P0
```

The compare reads its guard and writes its destination, so naming the same predicate for
both is free under renaming — the same read-write pattern `packi` and Format K's destructive
forms already have. **One predicate, not two, and the effective file stays at four.**

Verified on the simulator, including the case that matters: re-materializing from a register
already holding a *mixed* mask, which is what a second compare in a loop body faces. Lanes
false in the prior mask are correctly restored to true.

**Allocator guidance, in order.** Prefer the self-guarding form: where the source
predicate is dead after the compare — which is every semantically unpredicated compare —
reuse it as the destination. **Rematerialization is the fallback for when it is not
dead**, not the primary strategy; the idiom has no input dependencies, so it is freely
rematerializable wherever the self-guarding form does not apply. Hoisting it as a
loop invariant is wrong in both cases: it costs a quarter of the predicate file across
the whole body for no benefit.

The compiler emits the self-guarding form today — see §5.5 and §5.6, and
`docs/walkthrough.md`, where it is read back out of the compiled binary.

---

**O-25 — GPR count — settled at 16.**

Carried as provisional since 1.0, pending compiler spill data. Closed without it, because
the two inputs that were missing arrived from elsewhere: the cost of changing the parameter
is now known exactly, and three of the four arguments for changing it no longer hold.

**The cost.** Widening the register field to 5 bits is not a parameter change. Format J
overruns 16 bits outright, Format A″ falls to a 1-bit opcode, and Format A's 10-bit map —
already allocating 194 points — drops to 6 bits. Recovering that needs a second compressed
encoding over a 16-register subset plus relocating conversions and SFU into a 48-bit Format
A form. Three coordinated changes. The table is in §1.

**The arguments.** Of the four §1 previously recorded: argument 1 (span/MMA aligned quads)
is **retired** — it presumes Format H names a register group with a single field, which an
undesigned 48- or 64-bit format need not do; arguments 3 and 4 are **dissolved by O-23**,
which removed the pointer work they were measuring; argument 2 (width partitioning)
**survives weakened**, binding only where three or more widths are live at once.

**What remains open is a workload question, not an encoding one.** GEMM accumulator blocking
is the real risk and the one the machine exists for: a 4×4 per-thread C tile is 16
accumulators, and at 16 GPRs the practical ceiling is nearer 2×2 or 2×4. OoO execution and
`dp4.acc`'s four-MACs-per-register both soften it, but neither helps **FP32 accumulation**.

**And the response to bad data is not more GPRs.** It is a warp-uniform register file, which
is additive rather than a reset — it reuses the existing 4-bit field width under a separate
namespace, so no settled encoding moves and Format J still fits. Recorded in §1. Deciding
that later costs nothing now; deciding the GPR count later would have cost the compressed
forms.

**Consequences for the backend**, recorded because they are what the decision buys:

- One encoding path. No second compressed encoding, and the register allocator's competing
  objectives drop from three to two — destructive-form preference (O-8) and width affinity.
- Spill must be instrumented **by cause**, not by volume: accumulator spill is the live
  question, pointer and index spill is already answered by O-23. Sweep accumulator tile size
  and report FP32 and INT8 separately, since `dp4.acc` changes the answer for one and not the
  other.
- Warp-invariance reporting should be collected while the allocator is built. LLVM's
  divergence analysis already does the work; how many warp-invariant values are simultaneously
  live at peak is the only evidence that would size a uniform register file, and it is nearly
  free to collect now.

**O-26 — Formats C and C′ share one compare opcode map; 16 points, not 18.**

§3 previously described the 5-bit compare opcode as `{6 predicates} × {signed, unsigned,
FP}` = 18 points without saying whether C (register) and C′ (immediate) draw from the same
map. The backend initially assumed two independent spaces and landed `setp.ge` (C′) on the
opcode value `setp.ne` holds in C. Both decode unambiguously — the format tag separates them
— so nothing was broken, but the two readings give different hardware.

**Decided: one map.** A mnemonic means one opcode value regardless of where its second
operand comes from, so the compare-operation decode is one table that does not depend on the
operand-source bit. That is the same argument invariant 8 makes for field positions, applied
to the opcode.

Two consequences follow.

**`gt` and `ge` need real points** even though the register forms are unreachable by the
selector, which gets them by swapping operands. `setp.ge rs0, #imm` has no such escape: an
immediate cannot be the left operand of a swapped `le`. With a shared map, defining them for
C′ defines them for C.

**The count is 16, not 18.** Integer `eq`/`ne` compare bit patterns, so they are sign-
agnostic and are not duplicated across the signed and unsigned classes. The unsigned class
needs only `lt`, `le`, `gt`, `ge`. FP needs all six, because FP equality is not bit
equality: `eq.f` is ordered-equal and `ne.f` is unordered-or-not-equal — an exact
complementary pair, so exactly one holds for any operand pair including NaN, and C's float
`!=` is one instruction.

The two points this frees matter: the materializing `set` variants need 16, and 16 + 16 is
the whole 5-bit space with nothing spare. At 18 the map would not have closed.

**Still diagnosed, not encoded:** `SETONE`, `SETUEQ`, `SETO` and `SETUO` — the orderedness
predicates that are not one of the six relations. Each needs two compares or a point the map
cannot spare. No CUDA source construct produces them directly; they arrive from explicit
`isnan`-style idioms. See F-24.

**O-27 — The barrier epoch moves into hardware, and `bar.wait` splits into two instructions.**

O-12 put the phase parity in the `bar.wait` immediate and justified it by having "the
compiler alternate the bit each time through the loop." It closed by asking for a check
against the settled barrier spec. The check came from compiling the canonical reduction, and
it fails: an immediate is fixed at assembly time, the barrier's epoch parity flips on every
completion, and a barrier executed N times therefore needs N alternating expected values out
of one encoded bit. The immediate is correct only where the barrier runs at most once.

**Decided: the per-warp arrival epoch is tracked in hardware**, and the compressed
`bar.wait #id` means *wait until the arrival I just made has retired*. It needs no phase
operand at all, and `[14]` becomes reserved. The storage O-12 objected to is one bit per
(resident warp × barrier entry) — 64 warps × 64 entries is 512 bytes per SM, which is a
different order of magnitude from the register-file costs that instinct was formed on.

**And `bar.wait.phase #id, ps` is added at Format E opcode `00100`**, taking the expected
phase from a predicate register. This is not a fallback for the above. The two instructions
answer structurally different questions, and neither subsumes the other:

- Hardware epoch tracking answers **"has my own arrival retired?"**. That is the whole of
  `__syncthreads()`, where every warp arrives at a barrier and then waits on it.
- It answers nothing about a barrier **this warp did not arrive at**. In a pipelined
  producer/consumer — the double-buffered shape every serious GEMM and every async-copy
  pipeline uses — a warp arrives at the barrier for the buffer it just filled and waits on
  the barrier for the *other* buffer:

  ```
  for (stage) {
      bar.arrive       #(stage & 1)        ; this buffer is ready
      bar.wait.phase   #((stage+1) & 1), P0 ; the other buffer has been drained
  }
  ```

  "My last arrival on that barrier" is from the previous iteration, or does not exist at
  all. The waiting warp has to *name* the phase it expects, and that expectation is dynamic,
  so it comes from a register.

This is the point of splitting arrive from wait in the first place. O-12 argued the split
follows from per-thread PCs, which is true but incomplete: a split barrier whose wait can
only ever target your own arrival is a fused barrier with extra steps. The explicit form is
what makes the decoupling mean anything.

**Costs.** One Format E opcode point of 28 free. No change to `bar.arrive`, `bar.init`, or
any field position — the barrier ID sits at `[16:11]` exactly where `bar.init` puts it. The
compressed wait gets *smaller* in operand content, not larger.

**A secondary gain.** Compressed forms are never predicated (§1), so the Format K wait
cannot be guarded. The Format E form carries the qualifier at `[29:27]` like every other
32-bit instruction, which is what warp-specialised kernels need: producer warps and consumer
warps take different paths and wait on different barriers. Note the qualifier and `ps` are
distinct fields — the qualifier decides whether the instruction executes, `ps` is data.

**What this does not settle.** Whether a barrier may be predicated at *sub-warp* granularity
is a memory-model question, not an encoding one; the encoding permits it and the ABI should
probably forbid it. And nothing in the compiler selects `bar.wait.phase` yet: CUDA C has no
source construct that produces it without the async-pipeline intrinsics. It is encodable,
assembler-reachable and round-trip tested. See F-35.

**O-28 — Opcode numbering is normative, not a backend detail.**

§4 and §3 named the operations in each opcode range and counted them — "26 of 32 used",
"points 0–23" — but never said which number each operation gets. That was fine while the
document stood alone. It is not fine now: the numbering is baked into the encoder, the
generated decoder, the assembler and the simulator, and two independent implementations
picking different orders would produce silently incompatible binaries.

**Decided: the numbering is the order the lists are written in**, which is what the four
opcodes assigned before this was noticed already assumed — Format A `add` = 0 and
`mad.lo` = 5, Format K `add` = 0, `shl` = 7, `mov` = 14, `fadd.f0` = 18. All four fall out
of list order, so nothing had to move. The tables are now written out in §3 and §4.

Two places needed a rule rather than a list:

- **Format A floating point** is `32 + 8×format + op`: each format code owns a contiguous
  block of eight operations. `ffma.f0` = 35 confirms it. The alternative — four consecutive
  points per operation — would have put `ffma.f0` at 44 and is ruled out.
- **Format K's reg-immediate range (32–47)** is a *selection* of the reg-reg operations, not
  a mirror of points 0–15: `add` = 32 with `shl` = 37 is inconsistent with mirroring, which
  would put `shl` at 39. The eight assigned are `add`, `sub`, `and`, `or`, `xor`, `shl`,
  `shr`, `sra` — the operations whose second operand is plausibly a small constant. Eight
  points stay free.

**Consequence: the launch prologue does not need a 48-bit constant.** Writing the numbering
down forced an audit of what the prologue actually materialises, and it is the *window
index* — `LAUNCH_BASE >> 16` — not the address. Format F's 32-bit form carries 17 unsigned
bits, which covers every launch block below 2^33 bytes. §5.2 and both worked listings said
`f48`, at 16 bits per kernel for range nothing will use. Both listings are 16 bits shorter
as a result: §5.5 is 640 bits and §5.6 is 464.

**O-29 — Compressed-form policy: take what is free, do not buy the rest yet.**

§6 said density "depends entirely on how often the allocator can arrange
`rd == rs0`, which is a compiler-backend question, not an ISA one." Nothing in the backend
was asking it. This settles what the backend does, and what it deliberately does not.

**Two kinds of compressed form, and they need opposite treatment.**

The one-source forms — `neg`, `not`, `abs`, `mov` at §3 points 14–17 — carry `rd` and `rs`
in *separate* fields. There is no constraint to satisfy, so they are always 16 bits and the
backend always takes them.

The two-source forms read and write `rd`, so they need `rd == rs0`. That is where the choice
is, and it is not free: making the constraint hold can cost a `mov`, which is 16 bits —
exactly what the compression saves. Paying a copy to earn a compression is a wash at best,
and a loss when it also lengthens a live range.

**So the rule is: compress what already fits, never create the fit.** `CCVCompress` runs
after register allocation and rewrites a three-operand instruction to its compressed form
only when the registers it already holds satisfy the constraint. Every rewrite is 16 bits
saved and none can cost anything.

The exception is where no three-operand form exists to fall back on. Format B defines only
`add` as a register-immediate, so a shift-by-constant has no 32-bit encoding that takes an
immediate at all: the alternatives are the compressed form plus a possible copy (32 bits) or
materialising the constant into a register first (`movi` + Format A, 64 bits). There the
tied form is selected up front, copy or no copy, because the fallback is twice the size.

**What the measurement says so far**, from `ccv-llc -ccv-compress-stats`:

| kernel | two-source candidates | already `rd == rs0` |
|---|---|---|
| §5.5 unaligned elementwise | 3 | 2 |
| §5.6 aligned elementwise | 0 | — |
| block reduction | 1 | 0 |

Two things stand out, and neither is the hit rate.

**The aligned kernel has no candidates at all.** Its three two-source `add`s are the in-window
offset folds, and O-23's alignment attribute removes them. Alignment and compression are
substitutes here, not complements — the same instructions are what each of them eliminates.

**These kernels are the wrong place to measure.** Four candidates across three kernels is not
a rate, it is an anecdote. §6's density claim rests on a GEMM inner loop, where accumulate-FMA
and pointer arithmetic dominate and Format J's accumulate form — which has the same
constraint — carries the arithmetic. Step 5 is where this number means something, and the
instrumentation now exists to collect it.

**Biasing allocation toward the tie is the open half**, and it is deliberately not done. A
two-address hint costs nothing to add and can cost a great deal to get wrong; the data that
would justify a particular bias is the GEMM measurement, not these four instructions.

**O-30 — `.local` gets a window per thread, and the frame pointer is a window index.**

Spilling needs somewhere to spill to. §5.1 named `.local` as reaching memory "through its
window" and left it there; nothing allocated a window, lowered a frame index, or carried a
stack base in the launch block. The consequence was not a missing optimisation: **the
backend could not compile a GEMM at all**, and did not say so — the allocator's spiller
called into unimplemented hooks and corrupted the heap. See F-46.

**Decided: each thread gets a whole 64 KiB window**, and thread *t*'s frame is window
`local_base + t`, where `local_base` is a CTA-wide window index in the launch block at +24.

That falls out of S=16 and is the reason to prefer it over the obvious alternative. If a
thread's frame were at a byte offset inside a shared region, the address would need a base
register *and* an index register — two of sixteen GPRs reserved forever. Making the frame
pointer a **window index** instead means the frame offset is the entire remaining address
computation, so a spill is one base+offset instruction and the frame costs **one** reserved
register:

```
    movi       R15, #LAUNCH_WINDOW
    ld.global  R15, [R15 + #LOCAL_BASE]   ; CTA's .local window
    srd        R14, 0                     ; %ctatid
    add        R15, R15, R14              ; this thread's window
    ...
    st.global  R3,  [R15 + -4]            ; a spill, one instruction
```

**What it costs.** One GPR of sixteen, reserved unconditionally — whether a function spills
is decided *during* register allocation and `getReservedRegs` is asked before. It binds only
at 16 simultaneously live values, so no kernel measured before Step 5 pays anything for it.
Format D's 13-bit signed displacement caps a frame at 4 KiB per thread, comfortably inside
the 64 KiB window. Address space is the cheap resource here: 64 KiB × 32 lanes is 2 MiB of
*virtual* space per warp, of which a real kernel touches a few hundred bytes.

**Predicates spill through `ld.pred`/`st.pred`**, which is what O-19 added them for. F-2 found
there was no path from a predicate to memory at all; without one the allocator could not
spill a predicate even in principle. §3's 4-bit predicate mask means one instruction moves
any subset, though the allocator spills one at a time.

**O-31 — Conversions and the SFU get their first points, because integer division needed
them.**

§4 reserved 128–255 for conversions and 256+ for "SFU and future extension", and left both
empty. That was not free. With no float path available, integer division fell back to a
shift-subtract loop, and the simulator put a number on it: **one `udiv` cost 97 dynamic
instructions per thread.** AMD's compiler does the same division in about ten straight-line
instructions, and the 143-versus-64 static gap on the `transpose` benchmark was almost
entirely this one operation.

**Assigned, and only what is needed:**

| point | | point | |
|---|---|---|---|
| 128 | `cvt.f32.s32` | 256 | `rcp.f32` |
| 129 | `cvt.f32.u32` | 257 | `rsqrt.f32` |
| 130 | `cvt.s32.f32` (toward zero) | 258 | `sqrt.f32` |
| 131 | `cvt.u32.f32` (toward zero) | 259–262 | `ex2`, `lg2`, `sin`, `cos` |

The four conversions are what the algorithm needs. The SFU set is assigned together rather
than one at a time because O-28 makes numbering normative — fixing it once is cheaper than
revisiting it — and because CUDA requires all of them anyway. The rest of both ranges stays
reserved; filling them in speculatively would be inventing an ISA rather than specifying one.

**Out-of-range conversion saturates, NaN gives zero.** Same contract §4 gives width
mismatches: deterministic, no interlock, a compiler-correctness matter.

**The SFU is specified as correctly-rounded**, which real units are not. That is a
deliberate simplification with a real cost, recorded here rather than buried: simulating a
1-ulp-approximate reciprocal would make results depend on a specific hardware's error table,
which does not exist yet. The division sequence below is written not to depend on more than
about one ulp, so it survives a later move to an approximate unit — but that is an argument,
not a test, until there is an error model to test against.

**The division sequence, and the one constant that matters:**

```
    e = (u32)(rcp((float)d) * 0x1.fffffcp+31)   ; NOT 2^32
    e = e + mulhi(e, -(e*d))                    ; one Newton step, fixed point
    q = mulhi(n, e)
    two conditional corrections
```

Scaling by just under 2^32 is the whole trick. The Newton step converges **only from below**:
if `e` ever exceeds 2^32/d then `e*d` wraps past 2^32 and the correction term becomes huge
instead of small, driving `e` further out. `rcp` can be an ulp high, so scaling by exactly
2^32 is not safe. This is why AMD's sequence carries the same odd constant, and getting it
wrong here produced a division that was right for `d ≤ 2` and wrong above.

Exactness is checked, not argued: `tools/check-div.sh` runs the compiled kernel on the
simulator against exact integer division over the edge cases — `d = 1`, `d = 0`, operands at
2^31 and 2^32−1, powers of two either side of a rounding boundary — and a large
pseudo-random sample. **Result: 97 dynamic instructions per thread became 32, and the code
is straight-line.**

`sdiv` and `srem` are the unsigned sequence on magnitudes with the sign restored.
`sdiv(INT32_MIN, −1)` overflows and is poison in LLVM; this returns `INT32_MIN`, as hardware
does.

**O-32 — Format C″: the compare family gets its unpredicated encoding.**

§1 states the rule plainly: with no `PT` equivalent, "an unpredicated instruction cannot be
expressed as 'predicated on true.' Every predicated operation therefore requires a distinct
unpredicated encoding." That is why A/A′/A″, B/B′/B″ and D/D′ exist as separate formats.

**The compare family broke its own rule.** It spent both of its format tags on reg-reg
versus reg-imm and left no unpredicated form, so O-24 had to manufacture a guard for every
compare — `por pd, !pd, pd`, then a self-guarding `@pd setp pd, …`. Correct, and one extra
instruction every single time.

**Measured, that was not small.** Static cost ran 4.5–8.5% of instructions in the small
kernels and 0.6% in a GEMM, but the dynamic figure is what matters and it is worse: a
compare inside a loop pays on every iteration.

| kernel | dynamic issue groups | manufactured guards | |
|---|---|---|---|
| `reduce` | 138 | 18 | **13.0%** |
| `dot` | 141 | 18 | **12.8%** |

**Decided: Format C″ at tag `1111`, 32-bit.** The tag was free — `H` is 48-bit only, and §2
makes length decodable from `[1:0]` before the tag is read, so a 32-bit `1111` and a 48-bit
`1111` cannot be confused. No existing encoding moves.

| Bits | Width | Field |
|---|---|---|
| `[1:0]` | 2 | `00` |
| `[5:2]` | 4 | `1111` |
| `[10:6]` | 5 | opcode — the **same** shared map as C and C′ (O-26) |
| `[14:11]` | 4 | `rd` |
| `[18:15]` | 4 | `rs0` |
| `[22:19]` | 4 | `rs1`, or immediate `[3:0]` |
| `[26:23]` | 4 | reserved, or immediate `[7:4]` |
| `[27]` | 1 | operand source: 0 = register, 1 = immediate |
| `[29:28]` | 2 | reserved |
| `[31:30]` | 2 | `pd` — mandatory, same position as C and C′ |

**One tag covers both operand shapes**, where the predicated forms needed two. Dropping the
qualifier frees `[29:27]`, and one of those bits selects register versus immediate. The
immediate lands at `[26:19]`, exactly where C′ puts it, so the decoder's immediate extraction
is shared. `rd`, `rs0`, `rs1` and `pd` do not move (invariant 8).

**What it costs:** one format tag, the last free 32-bit one. `H` keeps `1111` at 48 bits and
is unaffected. Two reserved bits remain at `[29:28]` for a future qualifier-shaped extension
if one is ever wanted.

**What it buys:** the `por` disappears from every compare the compiler emits. §5.5 falls from
24 instructions to 23 and §5.6 from 17 to 16; `reduce` falls from 59 to 54. The predicated
forms remain in the ISA and are what if-conversion would select — nothing selects them today.

**O-24 is not superseded, only displaced.** Its idiom is still the only way to get a constant
into a predicate without `pmov`, still correct, and still what a genuinely predicated compare
needs. It is simply no longer on the path every kernel takes.

**O-33 — Warp-uniform work runs on one lane and is broadcast.**

Half of what an addressing-heavy kernel does is warp-uniform: the same value computed
identically in all 32 lanes. The measurement is in O-25's reporting — 52–75% of instructions
in the elementwise, reduction and transpose kernels, against 14% in a GEMM.

**Decided: mask that work to lane 0 and broadcast the result.**

```
    pmov       P3, #1            ; lane 0 only -- once, in the entry block
    @P3 ld.global R1, [R0 + 48]  ; uniform work, one lane active
    @P3 mad.lo R1, R1, R3, R2
    @!P3 shfl.idx R1, R1, 0      ; lanes 1-31 read lane 0
```

**The broadcast is one instruction, not two.** The shuffle is guarded by the **negated**
mask, so lanes 1–31 read lane 0's copy while lane 0 is excluded and keeps its own value
(invariant 10). Nothing has to fix up lane 0 afterwards. It also means the source lane of a
shuffle is read whether or not that lane is *active* — being masked off stops a lane
writing, not its register being readable. That is now stated in §3 rather than left implied.

**Predication, not branching.** A branch would split the per-thread PCs (§1), and the
broadcast is a warp-collective instruction that needs its lanes co-issued. Predication keeps
every lane at the same PC, so the collective is always well-formed. This is the first place
where the per-thread-PC model constrains an optimisation rather than enabling one.

> **Amended in 1.8 (CP-2): the safety condition is co-issue, not reach.** The paragraph above
> holds only for lanes that arrive at the block together. The condition is that lane 0
> **co-issues with** the lanes that read its result. Every lane *reaching* the block is
> necessary and not sufficient: after a divergent branch, per-thread PCs with opportunistic
> reconvergence let lanes that all reach a block reach it at different times, and a group
> issuing there need not contain lane 0. Measured, not reasoned: `rope.cu` has an inner loop
> whose trip count comes from `threadIdx`; lanes 4–31 ran ahead to the outer latch while 0–3
> were still inside, the group without lane 0 read lane 0's stale counter, and the kernel
> never terminated. A collective issued by one PC group reads other lanes through that
> group's own mapping, so a lagging group's later value is never visible, which is what CUDA
> says about lanes outside the mask.
>
> The correctness fix is the compiler's and is committed: an AND-meet dataflow masks only
> where no divergent branch lies on any path from entry, or a barrier has intervened since
> the last one. What it costs is reach, and §1a.1 records the honest figure. **The lost reach
> is not recoverable by a mechanism**, recorded so it is not chased twice. Making
> `reconv.hint` functional in Phase 1 makes co-issue likelier and never guarantees it, and a
> probabilistic mechanism cannot discharge a correctness condition; it would also force the
> Phase 2 reconvergence policy that O-4 deferred. A `shfl` naming the lowest *active* lane is
> self-consistent only if the computation moves there too, and needs a lowest-active-lane
> predicate source that does not exist; synthesising one from `ballot`, lowest-set-bit and a
> `laneid` compare costs more than the masking saves. The warp-uniform register file (F-106)
> is the real answer and stays a proposal on its own merits. Predict-versus-resolve (IS-4) is
> adjacent and not the same question: `rope.cu` hung on genuine divergence, not speculation.

---

### ⚠ This is a power optimisation, and it is a claim on the RTL

**Nothing in the ISA makes masking save energy.** The saving exists only if the datapath
gates mask-off lanes — clock-gated, operand-isolated, or both. If predicated-off lanes still
burn dynamic power, this transformation costs one broadcast per region and returns
**nothing**.

Those are obligations on the implementation, recorded here because they are invisible at
this level and easy to lose between here and RTL. **There are two of them**, and the
compiler now generates code by default that depends on both:

> **1. Lane gating is required, not optional.** A predicated-off lane must not toggle its
> ALU or its ALU operand registers. Everything O-33 does rests on this. *(Restated in 1.8 by
> IS-10: under rename the buses and the write port carry the merge value in masked lanes,
> so they are not part of the obligation and not part of the saving. See §1a.1.)*
>
> **2. Predicate-file logic must be much cheaper than warp-wide logic.** A predicate is 32
> bits, one per lane (invariant 5), so `pand`/`por`/`pxor` are 32 gates against 32 lanes of
> 32-bit datapath, and the ratio should be about the width of a lane. F-58's composition —
> masking an instruction that already carries a control-flow predicate, by computing the
> conjunction with `pand` — spends one compressed instruction per guarded value on that
> assumption. If predicate logic runs through the vector path instead, that part is a loss.

The second is the cheaper one to be wrong about: it costs the `pand` composition alone, and
`-ccv-mask-compose=false` withdraws it without touching the rest. The first, if it fails,
makes the whole scheme a code-size regression and nothing else.

The measurement below is in **lane-activations** — lanes that actually did work — precisely
so that the thing the hardware must deliver is what the tooling counts. **And a counter that
measures the wrong thing hides exactly this**: predicate-file operations were being charged
32 lane-activations each, which is the cost of a vector operation, and that made the `pand`
composition read as a loss (1587 → 1685) when it is a win (1555 → 1493). See F-60. A number
defined as an energy proxy has to be audited against its own definition, not just kept
consistent.

---

**Measured**, `ccv-sim -counters`, masking on against off:

| kernel | lane-activations | | instructions | |
|---|---|---|---|---|
| | off | on | off | on |
| uniform-chain microbenchmark | 640 | **548** (−14%) | 20 | 23 |
| `transpose` | 2304 | **1809** (−21.5%) | 72 | 76 |

**It is not applied everywhere, because it does not pay everywhere.** Each masked
instruction saves 31 lane-activations and each broadcast costs 31, so a region pays only
when it contains more masked work than crossings into divergent code. The reduction kernels
have eight maskable instructions and eight crossings — every uniform value is consumed
immediately by divergent work — so the pass measures that and declines. `vadd` likewise.

**Four things bound how much can be masked.** The first version of this section named two
and sized them off a report whose "blocked: encoding" bucket was a `default: return false`
catch-all — branches, stores, `srd` and `select` all landed in it, and `select` was
simultaneously counted as maskable. F-57 split it into named buckets; these are the
measured shares in `transpose`, the kernel with the most uniform work:

| bound | `transpose` | what would fix it |
|---|---|---|
| the SFU is at §4 256+, and A′ reaches 127 | **1** | `rcp.f32` has to come *below* 128; 128–255 is Format A only, so the range O-34 freed does not help. F-56 |
| `srd` is Format K only (invariant 7) | 1 | nothing: a 16-bit instruction has no qualifier field by design |
| a barrier must not be masked | 1 | nothing: this one is semantics, not encoding |

Two rows left this table. The conversion row was 3 until O-34 moved conversions into 64–127
and gave them Format A′ twins; one `rcp.f32` is what remains of it.

**The `sel` row was 10, and it was the largest bound here — but it was not a bound at all.**
F-58 read §4 point 19's qualifier-as-selector as a field contention: an instruction already
predicated for control flow cannot also carry the lane mask, and a second predicate field is
2 bits a 32-bit format does not have. Both halves were wrong.

Every one of those ten is the shape `sel rd, a, rd` — a conditional overwrite — which is
`@q mov rd, a` under **invariant 10**, at the same instruction count and writing only the
guarded lanes instead of all 32. The compiler now emits that, and `sel` earns its opcode
point only on a general three-register select, which nothing has yet generated.

And predication composes. The qualifier names a predicate **register**, and the conjunction
of two conditions is a predicate register: §3's `pand` is a 16-bit Format K instruction that
computes exactly it. So even where the field is genuinely spent, the cost of also masking is
one compressed instruction — not a format change. It buys about 12 lane-activations per
`pand` against the 31 a plainly masked instruction saves, which made it a judgement call
rather than an obvious one; it is **on**, and the obligation it spends — a predicate-file
operation costing much less than a warp-wide one — is recorded as the second RTL property
above. But "impossible" was never the right word, and this document said it.

Plus control flow, which in the reduction kernels dominates everything above: a block not
reached by every lane cannot have work masked *to* lane 0, because lane 0 might not be one
of the lanes that got there.

The `sel` row is the interesting one, and it was invisible before F-57. Those ten are the
two division sequences' correction steps. The general statement is that **a value already
predicated for control flow cannot also be masked to lane 0** — O-33 and ordinary
predication want the same three bits. That is a deeper limit than the opcode-range one, and
it is not obviously fixable.

**Format D′ also narrows the load displacement** from 13 bits to 10, so a predicated load
needs its offset to fit. Launch-block offsets are tens of bytes, so it always does here.

An instruction with no predicated form is **not** a reason to broadcast, though — it runs on
all 32 lanes, computing from whatever the masked region left in lanes 1–31, and lane 0 stays
correct because lane 0's inputs were correct. It costs a missed saving, not a crossing.
Getting that wrong doubled the broadcast count in the first implementation.

**Cost: one predicate register**, P3, reserved unconditionally — whether a function has
uniform work is decided after `getReservedRegs` is asked. Measured predicate pressure across
every kernel here is 1–2 of 4, so the quarter of the file this takes is currently unused;
O-32 removing the manufactured guards is most of why it is free.









**O-34 — The conversion block gets an arithmetic, a format-code destination, and Format A′.**

Three things, from a compiler-side proposal (`proposals/conversion-encoding.md`) and the
design-track decision on it.

**1. It had a count and no rule.** §4 described the conversion block as a product — bases ×
source-format codes × rounding modes = 128 points — and never said which number any
conversion gets. O-28 had already settled that numbering is normative, *"two independent
implementations picking different orders would produce silently incompatible binaries"*, and
supplied rules for the two ranges where list order was not enough. Conversions are a third
such range and were missed. The backend, having nothing to read, assigned 128–131 flat.

**2. The destination is a format code, not a base — and this is a correction, not a
compression.** The eight bases (`cvt2fp32`, `cvt2fp16`, `cvt2bf16`, `cvt2e4m3`, `cvt2e5m2`,
`cvt2e2m1`, `cvt2int.s`, `cvt2int.u`) distinguished their FP members **by element width**.
That is an element-width field sitting in the opcode, and **invariant 1 says no instruction
carries one.** It also left a case the specification had no rule for: `cvt2fp16` targeting a
register whose `chwidth` is 32. Under invariant 1 the register wins, so the mnemonic is
simply wrong, and there was no clean answer available.

A 2-bit destination code read against the destination register's `chwidth` removes the case
entirely — identical mechanism to `fadd.f0`, which is already FP32, FP16 or E4M3 depending
on the register. That it also halves the block from 128 points to 64 is a consequence, not
the argument. The proposal led with the halving and with F-56; the decision was taken on
invariant 1, which stands without either.

Source codes `10`/`11` become signed and unsigned integer. Bit `[1]` then reads as "integer
rather than FP" and bit `[0]` as "the variant" — BF16/E5M2 on one side, unsigned on the
other — which extends the existing table's structure rather than sitting beside it.

**3. `dp4`/`dp8` did not have to be demoted.** The proposal posed 64–127 as a contest
between conversions and packed dot-product, with `dp` moving above 128 and losing its
predicated tier. It is not a contest: `32 + 8×format + op` generates 48–63 for FP format
codes `10` and `11`, which are reserved at every `chwidth` and hold nothing. `dp` needs
eight of those sixteen points and both ranges stay inside A′'s ceiling.

**What that actually costs is the two spare FP format codes**, which is the trade worth
arguing about rather than `dp` predication. With MXFP, FP6 and further FP8 variants active
in the field it is a real forward-compatibility cost. Accepted on the judgement that a third
FP format code is not expected within this machine's life; if that changes, `dp` moves above
128 then, and the proposal's argument for why it is the right thing to demote applies
unchanged.

**Resulting map below 128:** 0–31 integer, 32–47 FP at codes `00`/`01`, 48–63 `dp`, 64–127
conversions. Solid, with no spare. Two adjacent generating rules and no gap between them is
a hazard — an FP instruction emitted at format code `10` lands on a `dp` opcode, and both
are well-formed Format A, so the decoder accepts either without complaint. The decision
document called that a documentation wart. It is checkable, so `tools/check-encoding.py`
checks it: any instruction landing in 48–63 that is not `dp4`/`dp8` is an error, and so is
any two instructions sharing a point in 32–127.

**Effect on F-56, stated precisely.** The finding was that the division sequence's
`cvt.f32.u32`, `rcp.f32` and `cvt.u32.f32` cannot be masked to lane 0. Two of the three are
conversions and are now inside A′'s reach. **`rcp.f32` is not**: the SFU is at 256+, Format
A′ reaches 0–127, and the 128–255 range this frees is Format A only — so relocating the SFU
down one range would buy nothing. Measured on `transpose`, lane-activations fall from 1809
to 1747 and the "no A′ form" bucket goes from 3 to 1. The proposal claimed 3 to 0; that was
wrong, and the decision document was careful to say "closes for the conversion rows."

**Costs.** 64 opcode points and the FP block's two spare format codes. A `cvt` can no longer
be disassembled to a precise type without knowing `chwidth` at that program point — already
true of every FP instruction in the ISA, and it inherits the same contract: mismatching
format against contents is deterministic garbage, not a hazard.

---

**O-35 — `rcp.u32`, an integer reciprocal seed, because the fp32 round trip was never about
precision.**

O-31 built integer division on a floating-point reciprocal because §4 had no integer one.
The seed costs five instructions — `cvt.f32.u32`, `rcp.f32`, a 48-bit constant, `fmul`,
`cvt.u32.f32` — of which four exist only to cross between integer and floating point.

**The fp32 format, not the unit, is what forces the Newton step.** fp32 has a 24-bit
significand, so even a correctly-rounded `rcp.f32` leaves an error near 2⁸ once scaled to
2³². Making the floating-point reciprocal more accurate therefore buys **nothing** in this
sequence — a conclusion worth recording, because "improve the reciprocal" is the obvious
first answer and it is wrong.

What pays is a reciprocal that is not routed through a floating-point format at all.
`rcp.u32` at point 263 returns the seed directly, under the contract in §4.

**Measured, `tools/model-rcp.py`**, sweeping the required accuracy against exact integer
division:

| sequence | instructions | minimum accuracy |
|---|---|---|
| fp32 seed + Newton + 2 corrections (O-31) | **21** | — |
| `rcp.u32` + Newton + 2 corrections | **17** | **16 bits** |
| `rcp.u32`, no Newton, 2 corrections | 13 | 32 bits |
| `rcp.u32`, no Newton, 1 correction | 8 | an exact seed |
| `rcp.u32`, no Newton, no correction | 5 | never |

Sixteen bits with the Newton step retained is the choice. The rows below it are not
available at acceptable cost: skipping Newton needs a seed accurate to essentially the last
bit, which is a divider — the latency and scheduling complexity this design is explicitly
avoiding in its first implementation.

**This is an instruction-count and code-size win, not an energy one.** The four instructions
it removes are conversions, which O-34 made maskable, so in warp-uniform code they were
already costing about one lane-activation each. The `rcp` itself remains unmaskable — §4 256+
is outside Format A′'s reach — and that is unchanged: see F-56 and
`proposals/predicated-long-form.md`.

**The compiler reaches it by fusion, after instruction selection.** `CCVFuseRcpSeed` matches
the five-instruction idiom and replaces it. Matching machine instructions rather than IR
means the middle end has already run and cannot reassociate the idiom out from under the
matcher — and a failure to match is not a correctness problem, because the fp32 sequence
stands and computes the same answer four instructions more slowly. An optimisation that
cannot be wrong is worth an awkward placement. It also found its own bug: the multiply in
that idiom is selected as the *compressed* Format K `fmul`, not the 32-bit one, so a matcher
written against the obvious opcode matched nothing.

---

**O-36 — fp32 division is software, over `rcp.f32` and `ffma`, and no divider is built.**

CUDA's default `/` on floats is IEEE-correct, so a general `a/b` is a compatibility
requirement rather than an optimisation. Until now only `1.0f/x` selected, to `rcp.f32`;
everything else was a hard "cannot select" (F-49).

**No hardware divider in the first implementation.** Its latency is much longer than the
SFU's and would complicate hardware scheduling — a design-track decision, and the right one:
the quotient costs instructions instead, and instructions are the resource this machine has
most of.

The sequence, over instructions that already exist:

```
ea, eb = exponent(a), exponent(b)      am, bm = a, b with exponent forced to 0
y  = rcp(bm)                           q  = am * y
y  = fma(-bm·y + 1) refinement  ×2     r  = fma(-bm, q, am)     exact residual
                                       qm = fma(r, y, q)        one rounding
result = qm · 2^(k>>1) · 2^(k − (k>>1))            k = ea − eb
```

Two parts carry it. **The FMA residual** is what makes the result correctly rounded rather
than merely close: `fma(-b, q, a)` is the exact remainder, because an FMA rounds once.
**Forcing both exponents to zero** keeps every intermediate near 1, so nothing overflows or
goes subnormal on the way, whatever the operands' magnitudes. Scaling only the divisor was
tried and left the residual computed on a near-subnormal product; it failed 64 of 40000.

**Correctly rounded whenever the result is normal.** Measured two ways, because they catch
different things: `tools/model-fdiv.py` checks the algorithm against exact rational
arithmetic (40184/40184), and `tools/check-fdiv.sh` executes the emitted kernel on the
simulator against the same reference (10240/10240).

**Subnormal results are up to 1 ulp out.** The final scale is two multiplies and the last
one rounds a value that was already rounded; multiplies cannot fix double rounding. This is
a stated gap, not an unknown — F-62 — and the gate measures it rather than assuming it stays
at 1 ulp.

**Cost: about 30 instructions.** That is what IEEE division costs in software, and it is the
price of not building a divider. `1.0f/x` still selects to a single `rcp.f32` and is
unaffected.

**Three defects fell out of writing it, none of them about division.** They are recorded as
F-62, F-63 and F-64, and two were in code that had been exercised for weeks:

- `ffma` was **not fused** in the simulator — written `a * b + c`, two roundings, for an
  instruction whose name is the fusion. 164 of 2048 divisions came out 1 ulp wrong against a
  model that was right.
- Any i32 constant with the top bit set could not be materialised: it reached `MOVI48`
  sign-extended and the encoder's range check rejected it. `and x, 0x807FFFFF` was a hard
  compiler error.
- `add reg, imm` had no range predicate, so a constant above 4095 selected into `ADDI` and
  was rejected by the encoder — the same defect as F-43, on the line above the comment that
  describes F-43.

---

**O-37 — Format A′ gets a 48-bit sibling, and the predicated tier reaches the whole map.**

Format A′ spends `[29:27]` on the predicate qualifier, which leaves it a 7-bit opcode
reaching points 0–127. Everything above is Format A only and cannot be predicated. O-34
relocated conversions into that range to work around it and in doing so packed 0–127 solid,
so there was nowhere left to relocate anything else — the ceiling was structural and reached,
with `rcp.f32` at point 256 sitting behind it as the last instruction O-33 could not mask.

**A′'s 48-bit sibling, specified in §3.** The low 32 bits are bit-identical to a 32-bit A′
instruction and `[34:32]` carries `opcode[9:7]`, which is the same sibling rule §2 already
applies to B, D and F — except that A′ extends an **opcode** where the others extend an
**immediate**. §2's wording was amended accordingly; without that the A′ sibling reads as
irregular when it is the same rule.

**No new format tag.** Tag `0001` at length `11` was unallocated. This matters: F-54 records
that all sixteen **32-bit** tags are spoken for, and the 48-bit space under them is not.

**Invariant 7 is satisfied at minimum length.** The content is 35 bits — a 32-bit A′ plus
three opcode bits — so 48 is the shortest length available at 16-bit granularity, and the
reserved bits are a rounding artifact exactly as `pmov`'s six are. The proposal argued
instead that the qualifier "earns the length despite the waste"; that reading works but
concedes more than it needs to and invites a future reader to re-litigate it.

**`opcode[9:7]` ≠ `000`, as a constraint on the field.** The proposal did not state this and
was self-contradictory without it: at `000` the long form encodes points 0–127, which the
32-bit A′ already encodes. Two encodings of one instruction is what invariant 7's second
sentence forbids and what the tier rule exists to prevent. Constrained, the long form encodes
exactly points 128–1023 — non-redundant by construction, and the round trip needs no
canonicalization tie-break. Asserted in `tools/check-encoding.py`, verified by adding a
violating instruction on purpose.

**Scope is A′ alone, and the asymmetry is principled.** Format A already carries the full
10-bit opcode at 32 bits, so a 48-bit A gains nothing and invariant 7 forbids it. Format A″
reaches 0–31, which is where its bounded subset lives, so there is no pressure. A′ is the
only tier whose reach is narrower than the operations that want it. Stated in §3 so that a
later reader does not "complete the family" and add two forms invariant 7 excludes.

**Considered and rejected: a 32-bit predicated tier that drops `rs2` to buy opcode width.**
Trading `[26:23]` for four opcode bits gives an 11-bit opcode reaching the whole map in four
bytes rather than six, and every SFU operation is single-source, so it would cover the
measured case. **It fails on tag space, not on merit** — it needs a new 32-bit format tag and
all sixteen are allocated (F-54). Recorded because it is the obvious proposal and will be
raised again; if a tag ever frees up it becomes the better answer for single- and two-source
operations and the two forms could coexist. Dropping `rs2` from A′ itself is not an option:
predicated `ffma`, `mad.lo` and `sel` are among the operations most worth predicating.

**Effect.** `rcp.f32` gains a predicated form and the `no A′ form` bucket closes: on
`transpose` it goes from 1 to **0**, maskable from 46 to 47, and the F-56 finding closes with
it. Lane-activations move 1428 → 1429 — the broadcast accounting shifts by one instruction,
which is the honest number and not the point. The point is that §4's extension space is no
longer a one-way door: allocating an operation above 127 no longer forfeits its predicated
form, which had already forced one relocation and had no room to force another.

---

**O-38 — Widening a narrow register clears the bits it exposes.**

§1 says a narrow register "occupies a narrower physical slice of a row" and §3 says
`chwidth` "reinterprets the existing contents". Between them the document never said what
the bits *above* the element hold after a narrow→wide change — they are not written while
the register is narrow, so the answer was an implementation choice nobody had made. Raised
as F-65 by the first `chwidth` work, because a compiler that widens a live value is
otherwise relying on a guarantee the ISA does not give.

**Decided: they are cleared, and the reason is security rather than convenience.** A GPU
register file is partitioned between resident warps and reused across kernel launches
without being scrubbed. Bits left in the part of a row slice that a narrow register stopped
addressing belong to whatever last occupied it — another warp of the same kernel, or a
different kernel entirely. Handing them back on a width change is a cross-context read, and
the width change is an ordinary unprivileged instruction.

**This is an obligation on the implementation.** Like O-33's lane gating it cannot be
checked from the compiler side, and unlike O-33's it is not a performance assumption: a
machine that skips the clear is not slower, it leaks. §1 states it as a bullet rather than
leaving it to this log.

**The compiler side got it backwards first, for a defensible reason.** `ccv-sim` originally
preserved the stale bits, on the O-35 principle that a simulator should model the worst the
contract permits so nothing can depend on a guarantee it was never given. That principle is
right in general and wrong here — it optimises against a correctness mistake at the cost of
an information leak, and those are not the same size of problem. `test/chwidth.s` now
asserts the clear, and names what a failure would mean.

**It also makes zero-extension free.** `zext i16 → i32` is exactly "widen the register and
clear the exposed bits", which is what the width change now does, so it costs no masking
instruction — only the `chwidth` that would be needed anyway. `sext` is not free: zeros do
not replicate a sign, and it still has no lowering (F-66). And `CCVInsertChwidth` may now
insert a width change on a **live** register in either direction — narrowing is a
truncation, widening is a zero-extension — where before only definitions were safe.

---

**O-39 — `rbase` and `rindex` are read at 32 bits.**

§3 said the base+index scale comes from `rdata`'s `chwidth` and said nothing about the width
the address registers themselves are read at. Invariant 11 implies the answer — an index is
an address component and no register holds an address — but implication is not specification,
and it stopped being academic the moment a register allocator had a reason to care.

It had one immediately. Given a 16-bit indexed load, the allocator assigned a single physical
register as both the narrow destination and the 32-bit index:

```
    chwidth   r2, 1
    ld.global r2, [r3, r2, 0, 0]
```

Correct under this decision and undefined without it. The compiler worked around the gap with
an earlyclobber constraint, at the cost of one extra register per narrow load on a
sixteen-register machine — a real price for a sentence that was missing.

**Decided: 32 bits, always.** Only `rdata` participates in the element-width model. §3 now
says so, along with the consequence that `rdata` may share a register with `rbase` or
`rindex`: the address read takes all 32 bits, which a narrowing `chwidth` leaves intact
because it reinterprets rather than converts, and the narrow write then lands inside them.

---

---

## 10. Explicitly out of scope for V1

- **Format H (tensor/MMA)** — register-group operand model undesigned. The `11` length escape
  and the `1111` format tag are reserved for it.

  **Design input, recorded by O-44's review:** an MMA accumulator fragment is **4–8 registers
  per thread** depending on tile geometry — 4 for an m16n8k16-shaped output, 8 for m16n16k16.
  At 16 GPRs that is a quarter to half the architectural file for **one** fragment, and a real
  GEMM holds several. So Format H does not settle O-25; it re-poses it in a harder shape,
  because the accumulator count stops being a tiler's free choice and becomes fixed by the
  matrix unit's geometry. **Register-file capacity is a co-design input for H, not a constraint
  to fit within afterwards.**
- ~~**FP packed dot-product** (BF16×BF16 → FP32 and similar)~~ — **removed by O-44.** The
  recorded objection was that the FP case needs per-element exponent handling inside the
  reduction and is the natural companion to Format H's fragment operands. **That reasoning does
  not hold, and the reason it does not is worth keeping:** exponent handling is a property of
  the *reduction*, not of the operand model. The reduction hardware is the same whether the
  operands arrive from Format A registers or from Format H fragments. Integer `dp4` already
  established that a packed reduction lives in Format A without touching invariant 1 — the
  packing factor is in the opcode, no register is narrow, and nothing outside the instruction
  observes the packed view. See §4's points 48–63.
- **FP64** — out of scope for V1 (DA's response IS-13, 2026-10-20: "yes, I don't want to
  build FP64 in this first version"). No instruction, width code or format code names a
  64-bit float, and none is reserved for one. `double` arithmetic in device code is a
  compile-time diagnostic, not a silent software emulation, so nothing that relies on FP64
  results compiles and runs with different numbers. What lost: hardware FP64, and emulating
  it in software. 64-bit *integers* are a separate question (IS-13 item 2): they lower to
  32-bit pairs.
- **Texture / surface operations** — likely permanently out of scope for an AI/ML target.
- **Instruction fetch alignment and bundle crossing** — RTL-level, deferred by prior
  agreement, but note the compressed forms make this more load-bearing: with 16-bit
  granularity actually exercised (rather than merely permitted), instruction boundaries no
  longer align to 32-bit fetch words, and the decoder must handle a 48-bit instruction
  straddling a fetch boundary in the common case rather than the rare one.
- **Compressed predicated forms.** Deliberately excluded — 3 bits of qualifier out of 14 is
  too steep. Revisit only if compiler output shows predicated ALU ops are hot enough to
  justify a third compressed class code, which would mean giving up the 48-bit form's clean
  2-bit decode.
- **Span / multi-register transfers** (`ld.global.v2` / `.v4` equivalents). **Deferred.**
  Three reasons, in descending order of confidence:
  1. The usual justification is weaker here. On an in-order machine `.v4` is how you get
     four loads' worth of memory-level parallelism from one instruction. This machine gets
     MLP from the OoO window — four independent scalar loads are already in flight. What
     `.v4` still buys is front-end bandwidth, AGU throughput and load-buffer entries: one of
     each instead of four. Real, but second-order rather than the first-order win it is on
     an in-order GPU.
  2. `chwidth` already covers the narrow-data case. A 32-bit register at `chwidth`=8 holds
     four INT8 elements, so a quantized kernel's vector load is an ordinary scalar load.
     Span only matters for FP32-width data.
  3. At 16 GPRs the register group is structurally awkward — see the GPR-count note in §11.

  Format D opcode points `01110`+ stay reserved (`01100`–`01101` went to O-45's launch-slot form) — re-based from `01000`+ in 1.3, since
  `01000`–`01011` now carry predicate transfer (O-19). Span was unspecified, so re-basing
  its reservation cost nothing. Register-group addressing is the same
  mechanism Format H needs for MMA fragment operands; if span is ever revived it should
  reuse whatever H defines rather than inventing a parallel scheme.

---

## 11. Carried deferred items (not encoding-blocking)

- Wake-broadcast timing relative to epoch increment
- Drain FIFO depth vs. wake width
- Formal property for the N+1 arrival race window
- **Predicate count (4)** — still provisional. O-19 made the file spillable and O-24's
  addendum keeps the effective count at four rather than three, so this is now a performance
  parameter that data can settle rather than a structural ceiling. The GPR count is no longer
  carried here: settled at 16, see O-25.
- SMT-4 checkpoint drain mechanics
- Sub-row-granular scoreboarding (GPRs and predicates)
- ~~Narrow-width coalescing strategy (hybrid TLP/ILP), decoupled from SMT width~~ —
  **superseded by O-48.** Narrow throughput is section co-issue over warp-private rows; the
  open strategy question is now placement, measured as footprint width (§1a.4).
- Physical row subdivision / anti-fragmentation allocation
- Speculative exclusive-ownership contention between concurrent atomics
- **Launch-block layout** — the byte-level contract for the block described in §5.2: header
  field offsets, the argument area, alignment, and the reciprocal-constant slots. An ABI
  document, not an encoding question. Blocked on nothing.
- **Kernel-pointer alignment — settled in 1.4 as a per-argument attribute (O-23).** What
  remains is the ABI document's job: naming the attribute spelling kernels should use, and
  specifying the launch-time validation that catches a false declaration. Neither is
  encoding-blocking. The measurement consequence stands: register-pressure data has to
  report aligned and unaligned kernels separately, since the two shapes differ by three live
  registers on the simplest kernel there is.

- **Carry-producing add.** §4's integer range has 6 unallocated points in the low 32, which
  is the A″-reachable range where a carry-out predicate destination would live. Only needed
  if window-crossing pointer arithmetic (§5.1) shows up hot. Deferred pending codegen data.

---

## 12. Fault model

Adopted in 1.9 as O-57, from `fault-model-spec.md` (IS-2), with the corrections listed in the
Changes section. Normative throughout.

### 12.1 Principle

> **Every encoding, and every combination of an encoding with architectural state, has
> defined behaviour: a result, or a defined fault. Nothing is undefined.** (Invariant 12.)

It generalises invariant 3 to the whole instruction set. The reason is O-38's: this machine
runs mutually distrusting contexts, and the RTL receives whatever an instruction stream
contains. A statement that the compiler never emits something constrains nothing the hardware
can be handed.

**Undefined is forbidden; bounded nondeterminism is not.** An outcome that is one of an
explicitly specified set, every member of which is legitimate, is permitted. A parallel machine
cannot avoid it: two warps racing to store to one address leave one of the two values, never a
blend. Where this section admits such a set, it names it.

**Why fault rather than assign a value.** A faulting encoding can be given meaning later
without breaking any working program, because no working program ever executed it. An encoding
assigned a result today becomes behaviour someone depends on. So encodings that name nothing
fault. A *well-formed* instruction meeting a mismatched operand keeps invariant 3's
deterministic result wherever that result is safe and forecloses nothing.

### 12.2 Detection stages

| Stage | Detected from | Granularity | Gated by predicate? |
|---|---|---|---|
| **Fetch** | The selected PC | Lanes at that PC (the issue mask) | No — nothing is decoded yet |
| **Decode** | Encoding bits alone | Whole instruction | No |
| **Dispatch** | Encoding plus committed register state | Whole instruction | **No** |
| **Execute** | Per-lane operand values | **Per lane** | **Yes** — issue mask ∩ predicate |

**Dispatch-stage faults are predicate-independent** because the predicate is a renamed source
operand whose value arrives at execute, while `chwidth` is committed before anything downstream
observes it (invariant 2). Dispatch checks exactly the state available there.

**Execute-stage faults are raised only for lanes in issue mask ∩ predicate.** This is the rule
most likely to be implemented wrong and the one with the largest blast radius. Predication is
how kernels guard out-of-bounds accesses:

```
    setp.lt   P0, R1, R4        ; i < n
    @P0 ld.global R5, [R2, R1]  ; lanes with i >= n carry a garbage address
```

The masked-off lanes compute addresses past the buffer's end. If they faulted, every
bounds-guarded load would fault on its tail. A lane predicated off, or at another PC, never
raises an execute-stage fault, whatever its operand values.

### 12.3 Causes

| Code | Stage | Cause |
|---|---|---|
| `F-FETCH` | Fetch | Selected PC outside the kernel's code image, or not 16-bit aligned (including a `ret` to an odd offset, §3 Format E) |
| `F-ILLEGAL` | Decode | Reserved opcode point; reserved field bit nonzero; reserved value in a defined field; non-canonical encoding |
| `F-WIDTH` | Dispatch | Memory access (Formats D, D′, M, M′) whose `rdata` is at `chwidth`=4 |
| `F-FORMAT` | Dispatch | FP or `cvt` format code reserved at its operand register's `chwidth` |
| `F-ALIGN` | Execute | A lane's effective address not a multiple of its transfer size (O-58) |
| `F-ADDR` | Execute | Effective address not mapped, or not permitted for the context |
| `F-SHARED` | Execute | `.shared` access outside the CTA's allocation |
| `F-RO` | Execute | Store or atomic any byte of which lies in read-only memory: the launch block and `.const` (§5.2, O-51) |
| `F-BARRIER` | Dispatch | Barrier ID (`bar.arrive`, `bar.wait`, `bar.init`, `bar.wait.phase`) at or above the CTA's allocated barrier count (O-59) |

**`F-ILLEGAL` covers every encoding that names no operation.** Reserved opcode points (Format K
29–31, §4 integer 26–31, `dp` 60–63, Format D `01110`+, Format E `00101`+, any tag at a length it
has no form for); reserved field bits nonzero (Format I `[47:37]`, `bar.wait`'s `[14:15]`, and
every other field §3 marks reserved); reserved values in defined fields (`srd` selectors 2–15,
the meaningless-rounding points of the conversion product); and non-canonical encodings (A′ long
with `opcode[9:7]` = `000`, O-37). Must-be-zero rather than ignored: an ignored field can never
be given meaning, because code that happened to set it would change behaviour.

**`F-WIDTH`, `F-FORMAT` and `F-BARRIER` are the well-formed instructions whose state names
nothing.** `F-BARRIER` checks the barrier ID, an immediate, against the CTA's allocated count,
which OOE holds per tier-1 slot from RAU; the barrier instructions are unpredicated, so the
dispatch check is exact, and a faulting reference never reaches SYU (AR's IS-16 response). A memory access has no 4-bit transfer (§1). A format code that is reserved at its
register's width (codes `10`/`11` at every width in the FP block; `01` at 32 and 4 bits) means
nothing there, and O-34 names `01` at 32 bits as TF32's home if it is ever wanted, so faulting
keeps it open. Distinct from a format *mismatch*: a defined code against differently formatted
data keeps its deterministic result (§4).

**`F-RO` resolves an earlier review finding**: the walkthrough's second listing stored into the
launch block. Under this model that store faults rather than silently corrupting a region other
warps have cached.

### 12.4 Precision and speculation

**All faults are precise and taken at retirement.** A fault is recorded on the instruction's
ROB entry at the stage that detects it and taken when that entry retires. Every older
instruction has committed; no younger one has affected architectural state; the faulting
instruction has no architectural effect. **Speculative faults are therefore discarded**: a
mispredicted path's garbage address marks an entry that is squashed before it retires.

**Stores** commit at retirement, so a faulting store is dropped; older stores have retired and
remain. **Atomics** release any ownership they acquired and commit nothing. **Per-thread PCs**
keep per-lane program order in the ROB even when PC groups interleave, so precision holds per
lane.

### 12.5 Priority

**Within one lane**, earlier stages win:
`F-FETCH` > `F-ILLEGAL` > `F-WIDTH` / `F-FORMAT` / `F-BARRIER` > `F-ALIGN` > `F-ADDR` / `F-SHARED` > `F-RO`.
`F-ALIGN` precedes the address checks because it is decidable from the address alone; `F-RO`
follows `F-ADDR` because read-only-ness is a property of a mapping.

**Across lanes of one instruction**, the record reports the highest-priority cause among the
faulting lanes and the address of the lowest-numbered lane raising it.

### 12.6 Delivery — V1 faults are fatal to the context

**Every V1 fault terminates the faulting context** (DA's response IS-2, 2026-10-20). There is
no in-kernel handler and no resumption. Every grid of the context stops: every resident and
parked warp of the context stops issuing, and no further launch of the context starts. This is
CUDA's model for an illegal address or instruction: fatal to the context, reported to the host
as a sticky error. What lost: terminating only the faulting grid, which keeps the context's
other grids running but can turn a fault into a hang, because a surviving grid waiting on the
dead one never finishes and the host's sync never returns.

**The fault record** is one per context, written by the first fault taken and **sticky**: later
faults do not overwrite it.

| Field | Contents |
|---|---|
| Cause | One of §12.3's codes |
| PC | The faulting instruction's address |
| Lane mask | Fetch, decode, dispatch: the issue mask. Execute: issue mask ∩ predicate ∩ faulting lanes |
| Address | Execute-stage memory causes: the address of the lowest lane raising the reported cause, as generated, in full — including any bits above 48 that made it non-canonical (`F-ADDR`) |
| CTA ID, warp ID | The faulting warp's location |

The record is visible only to the context's owning host process. Whether it lives in MMIO
registers or a host-visible memory region is the driver interface's choice; its content,
containment and stickiness are architectural.

**Bounded nondeterminism at termination.** In-flight instructions of the context's other warps
may retire or be discarded. Stores they retire before stopping are visible; stores they do not
are not, and stores already handed to the memory side stay. The host treats the context's
output as indeterminate within that set, which is CUDA's contract for a faulted context, stated
rather than assumed.

### 12.7 Containment (O-38)

1. **Other contexts' warps are unaffected**, including warps co-resident on the same SM under
   spatial sharing. Terminating one context's warps must not stall, drain or perturb another's.
2. **The fault record is visible only to the owning context.**
3. **No state crosses a context boundary on teardown.** A terminated context's register-file
   partition, predicate state and barrier-table entries are cleared before reallocation, the
   obligation O-38 already places on widening, applied to the whole partition.

**Concurrent faults:** which one the record captures is bounded-nondeterministic. It is always
one that occurred, never a merge and never garbage. A deterministic choice would need a global
order of fault detection across SMs, which the hardware does not have.

### 12.8 What is not a fault

- **FP exceptions never fault.** Overflow, underflow, invalid and inexact produce the format's
  result: IEEE defaults at 16 and 32 bits, saturation at 8 and 4 bits (O-56). Subnormals are
  kept, never flushed. CCV has no FP status flags.
- **Integer overflow wraps**, two's complement. There is no integer divide and no division by
  zero; `rcp.u32` of zero returns `0xFFFFFFFF` (§4).
- **Width and format mismatches on well-formed instructions** keep invariant 3's deterministic
  result, except `F-WIDTH` and `F-FORMAT`.
- **A non-uniform `rbase` for `ld.pred` / `st.pred`** keeps its defined behaviour: the address
  is lane 0's.
- **A `ret` to another code window** lands at the same offset in the `ret`'s own window (§3
  Format E); it faults only if that location is outside the image or misaligned (`F-FETCH`).

### 12.9 Implementation obligations

- **Every reserved field is checked at decode.** Every reserved bit is a comparator input to the
  `F-ILLEGAL` condition, which is a real decoder cost.
- **The dispatch checks read `chwidth` from committed state.** No new state; invariant 2 makes it
  available and non-speculative.
- **The execute checks receive the predicate and issue mask**, which already reach the lanes'
  gating logic.
- **The memory pipe's fault path is shared** by `F-ALIGN`, `F-ADDR`, `F-SHARED` and `F-RO`; it
  must exist for unmapped addresses regardless.

### 12.10 Deferred, and not foreclosed

**Replayable memory faults.** Unified Memory (`cudaMallocManaged`) depends on replayable page
faults. V1 has no replayable class, service path or replay mechanism, but precise
retirement-time faults are what replay requires, and **no further mechanism is needed in the
ROB**. Replaying a faulted memory instruction is a squash to it in ROB order, which is
contiguous (OA's IS-4 response). Nothing younger has retired and stores commit only at
retirement, so re-executing another PC group's unretired work discards and refetches it rather
than duplicating it. Each group resumes at its oldest unretired entry, the mechanism demotion
already uses, which needs only each ROB entry's PC and group mask (A-69). *(The adopted
document named a stream-tagged, non-contiguous squash as the obstacle to replay. That was
wrong, and is struck.)*

**Trap handler and debugger.** Breakpoints, single-step and live-warp inspection need a
non-fatal delivery path beside §12.6's fatal one. Out of scope for V1 and not foreclosed.
