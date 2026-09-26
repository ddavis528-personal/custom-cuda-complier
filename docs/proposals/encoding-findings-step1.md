# Findings — Step 1 machine description

**Status:** five findings from transcribing §3 of ISA v1.3 into TableGen.
**Source:** `llvm/CCV/`, verified by `tools/verify.sh`.

The value of writing a machine description is not the description. It is that a
bit map which reads correctly in prose has to be *exactly* right in a form a
machine consumes, and four of these five were invisible on the page.

---

## F-12 — 32 GPRs is an encoding fork, not a subtarget flag

The roadmap said to make the GPR count a subtarget feature "so the 16-vs-32
experiment is a flag flip rather than a fork." **That is not possible.** A 32-GPR
file needs 5-bit register fields, and the encoding has no room:

| Format | opcode bits at 4-bit regs | at 5-bit regs |
|---|---|---|
| A | 10 | 6 |
| A′ | 7 | 3 |
| A″ | 5 | **1** |
| K (reg-reg) | 6 | 4 |
| J | — (2-bit subop) | **overruns 16 bits by 3** |

Format J carries three register fields in the twelve bits left after the class
code and subop; at five bits each that is nineteen bits in a sixteen-bit
instruction. It does not degrade, it fails to exist. Format A″ falls to a 1-bit
opcode — two points, against the 32 it needs. Format K's reg-reg range currently
uses 24 opcode points and would have 16 total.

So the compressed forms — the entire density argument in §6, and the claim that a
GEMM inner loop encodes at close to 16 bits per instruction — **cannot address a
32-register file.**

**This does not kill 32 GPRs.** The standard resolution is RISC-V's: compressed
instructions address a 16-register subset (RVC uses x8–x15). Applied here, J and
K keep 4-bit fields naming R0–R15 while the 32-bit formats widen. But that is a
real ISA fork with real consequences:

- The 32-bit formats lose 4 opcode bits each. A survives comfortably (6 bits,
  64 points, against 64 currently allocated — exactly full, with the entire SFU
  and conversion extension space gone). A″ does not survive at 1 bit and would
  need restructuring or deletion.
- The register allocator gains a **third** objective: prefer R0–R15 for
  compressed-eligible operations, alongside destructive-form preference (O-8)
  and width affinity (F-3). Three competing preferences on one assignment
  decision.

**What this changes about the experiment.** Spill counts can still be measured at
16 versus 32 by restricting allocation order — that part is a flag. But a working
32-GPR machine is a second encoding, and the decision has to price that in
alongside the spill data. `GPR` in `CCVRegisterInfo.td` therefore contains R0–R15
only, with R16–R31 defined but unallocatable, and `GPRC` exists as a separate
class so the compressed-form constraint stays expressed rather than implied.

---

## F-14 — Format B′/B″ violate invariant 8, and the fix is free

**The one genuine design finding of the five.**

Invariant 8 says the predicate qualifier sits at `[29:27]` and the predicate
destination at `[31:30]`, names B/B′/B″ among the formats it covers, states that
where a large immediate would collide with the qualifier "the immediate is split
around it (D′, `bra.pred`) **rather than the qualifier being moved**," and closes
with "**There are no exceptions among the 32/48-bit formats.**"

§3's Format B table does exactly what the invariant says does not happen:

| Field | B′ / B″ | Invariant 8 |
|---|---|---|
| predicate qualifier | `[21:19]` | `[29:27]` |
| predicate destination | `[23:22]` (B″) | `[31:30]` |

This is not cosmetic. The qualifier feeds the **predicate RAT**. With B′/B″ at
`[21:19]` and every other predicated format at `[29:27]`, the predicate rename
path needs a format-dependent mux — precisely the cost invariant 8 exists to
avoid, and the reason D′ went to the trouble of splitting its offset (O-10).

**The fix costs nothing, and the spec already contains the technique.** Apply
D′'s treatment to B′ and C′'s layout to B″:

| | Proposed | Immediate |
|---|---|---|
| B′ | `imm[7:0]` at `[26:19]`, `pq` at `[29:27]`, `imm[9:8]` at `[31:30]` | 10 bits, MSB at 31 — unchanged |
| B″ | `imm[7:0]` at `[26:19]`, `pq` at `[29:27]`, `pd` at `[31:30]` | 8 bits, MSB at 26 — unchanged |

Verified by building both layouts and re-running the checks: zero invariant-8
deviations, immediate widths identical, `-gen-emitter` and `-gen-disassembler`
still clean. B″ becomes **bit-identical to C′**, which is a consistency gain the
current layout forgoes.

No bits are lost. The qualifier reaches its canonical position in every
predicated format. Recommend adopting in v1.4.

---

## F-13 — Format G is three field layouts presented as one

§3's Format G table carries "or" clauses: `[23:19]` is a shuffle lane index "or
`ps` at `[21:19]` for vote/ballot," and `[31:30]` is a vote destination "or
reserved." Those are not one layout with flexible fields — they are three
distinct layouts sharing a tag, and a fourth once `unballot` is added.

TableGen rejected the single-class transcription outright, which is how this
surfaced. Split in `CCVInstrFormats.td` into `FormatGshfl`, `FormatGvote`,
`FormatGballot` and `FormatGunballot`.

Editorial, but worth fixing in the spec: a decoder implementer reading the merged
table has to reconstruct the split themselves, and may reconstruct it differently.

**Side benefit:** O-14 claimed `unballot` "fits the existing G layout without new
fields." Now mechanically confirmed — `rs0` at `[18:15]`, `pd` at `[31:30]`, both
canonical, nothing added.

---

## F-15 — Invariant 8 states a J/K compressed geometry that does not exist

Invariant 8: "The compressed forms have their own internal geometry — `rd` at
`[11:8]`, `rs` at `[15:12]` — equally fixed **within class J/K**."

Format J's own bit map says `rd` at `[7:4]`, `rs0` at `[11:8]`, `rs1` at
`[15:12]`. J and K do not share a geometry and cannot: J carries three register
fields in the twelve bits after the class code and subop, so its `rd` must sit
lower than K's.

J's layout is forced and correct. The invariant's description of it is wrong.
Suggested wording: each of J and K has a fixed internal geometry, but they
differ — K is `rd[11:8]` / `rs[15:12]`, J is `rd[7:4]` / `rs0[11:8]` /
`rs1[15:12]`.

---

## F-16 — "No exceptions among the 32/48-bit formats" does not cover Format I

Invariant 8 enumerates A/A′/A″, C/C′, B/B′/B″, D/D′ and M/M′, then makes the
broader claim. Format G conforms. Format I does not — `pmov` puts `pd` at
`[9:8]`, and `chwidth.multi` has no canonical slots at all.

Format I is metadata with a deliberately different shape and there is no reason
to change it. The blanket sentence should name its exclusions rather than assert
a universal that two instructions contradict. They are listed explicitly in
`tools/check-encoding.py` as `EXEMPT` so the gap stays visible rather than being
silently skipped.
