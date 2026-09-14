# Proposal — Predicate Transfer and Predicate Logic

**Status:** RESOLVED — adopted as O-19 and O-20. `ld.pred`/`st.pred` are Format D opcodes `01000`–`01011` (global and shared, 4-bit mask), `pand`/`por`/`pxor`/`pmov` are Format K points, and `unballot` is Format G point 9; all are in `CCGInstrInfo.td`, and O-30 spills predicates through them. F-2 in `../roadmap.md` is closed. This document records the argument, not the current state.
**Scope:** closes the predicate spill/reload hole, and the two adjacent gaps that
turned up while designing it.

Three additions, no new formats, no new fields, nothing above 32 bits:

| Addition | Format | Cost |
|---|---|---|
| `ld.pred` / `st.pred` with a 4-bit predicate mask | D | 4 opcode points |
| `pand` / `por` / `pxor` / `pmov`, dual-negate sources | K | 4 opcode points |
| `packi.z` — clearing variant of `packi` | B | 1 opcode point |
| `unballot pd, rs` (O-14, unchanged from the spec's own sketch) | G | 1 opcode point |

---

## 1. `ld.pred` / `st.pred` — encoding

A predicate is 32 bits at every `chwidth` (invariant 5), so a transfer is one
aligned word per predicate. The whole architectural predicate file is 4 × 32 =
**128 bits**, which is the fact the rest of this proposal leans on.

The `rdata` field at `[14:11]` is 4 bits and the predicate file has 4 entries.
That is not a coincidence worth passing up: reinterpret `rdata` as a **predicate
bitmask** and the instruction is bit-for-bit the existing Format D base+offset
skeleton.

| Bits | Width | Field |
|---|---|---|
| `[1:0]` | 2 | length = `00` |
| `[5:2]` | 4 | fmt = `1000` (D) |
| `[10:6]` | 5 | opcode |
| `[14:11]` | 4 | **predicate mask** — one bit per `P0`–`P3` |
| `[18:15]` | 4 | `rbase` |
| `[31:19]` | 13 | signed offset |

Every field in its canonical invariant-8 position, sign bit at 31, same 13-bit
offset as the GPR form, and the 48-bit sibling comes free under the same tag for
a 29-bit offset. Nothing moves, nothing is reserved.

Assembly reads with the mask as a set, so the single case stays natural:

```
    st.pred  {P0}, [R5+16]            ; one predicate, one word
    st.pred  {P0,P1,P2,P3}, [R5+16]   ; whole file, one 16-byte access
    ld.pred  {P0,P2}, [R5+16]
```

**Opcode points.** Four, base+offset only: `ld.pred.global`, `st.pred.global`,
`ld.pred.shared`, `st.pred.shared`. No base+index form — spill slots are
base-plus-constant, and invariant 7 says do not encode what is not needed. No
`D′` (predicated) form for the same reason.

These have to come out of Format D's `01000`+ range, currently reserved for span.
Span is deferred and unspecified, so re-basing its reservation to `01100`+ costs
nothing.

**Frame layout is positional, not packed.** Word *i* of the 16-byte frame always
holds `Pi`, regardless of mask. A packed layout (N words for N mask bits) is
denser but makes the effective address depend on mask popcount and makes
save/restore masks non-composable — save `{P0,P2}` then restore `{P2}` lands on
the wrong word. Positional costs a fixed 16 bytes of frame, which is nothing,
and gives one aligned 16-byte transaction for any mask.

## 2. Why the multi-register form is right here when span was deferred for GPRs

ISA spec §9 defers span transfers for three reasons. All three either invert or
fall away for predicates.

| Span deferral reason (§9) | For predicates |
|---|---|
| 1. OoO window already supplies MLP; `.v4` only buys front-end bandwidth | Not the point. Save/restore is one aligned 16-byte access replacing four 4-byte ones — a transaction-count argument, not an MLP one. |
| 2. `chwidth` already covers the narrow-data case | Does not apply. Predicates are 32 bits at every width (invariant 5). |
| 3. A 4-register group at 16 GPRs leaves four legal aligned destinations, each a quarter of the file | **Inverts completely.** A 4-bit mask over a 4-entry file has no alignment constraint at all. All 16 combinations are legal. There is no group structure to be awkward about. |

The mask field is also free — `[14:11]` is there whether it carries a mask or
four reserved bits.

**On the microarchitectural cost.** A mask with N bits set is N predicate writes
(or reads) from one instruction. The usual objection is that multi-destination
instructions want a decode-cracking sequencer, and this machine may not otherwise
have one — atomics and CAS are both explicitly single-ROB-entry.

It does not need one. The predicate RAT is **4 entries**. Writing all four is a
4-bit write enable on a flop array, not a sequence; the same for four reads.
Single ROB entry, single AGU operation, single 16-byte memory access, four RAT
ports. That is almost certainly cheaper than the sequencer it avoids, and it is
cheap *specifically because the file is tiny* — which is exactly the asymmetry
with GPRs that makes span hard and this easy.

## 3. The actual hard part — where does the address come from

The encoding is easy. This is not.

A predicate is **warp-scoped**: 32 bits describing 32 lanes, one object per warp.
`rbase` is a GPR, which is **32 lanes wide** — 32 different addresses. A
predicate transfer needs one. The machine has no scalar/uniform register file to
take it from.

Three options:

1. **`rbase` warp-uniform by compiler contract, address taken from lane 0,
   non-uniform `rbase` produces a deterministic result.** This is not a new
   policy — it is invariant 3 applied to a new case, the same contract already
   governing width mismatch, FP format mismatch, and out-of-range `packi` slot
   indices. Consistent with house style.
2. **Name lane 0 in the semantics outright.** Same behaviour, but it makes a lane
   index architectural, which nothing else in the ISA does.
3. **Implicit ABI base register**, like `call.short`'s implicit link register.
   Sidesteps the question but hardcodes ABI into the ISA, which the spec
   deliberately avoided when it chose *explicit* link registers.

Option 1 is recommended. But it has a consequence that needs deciding alongside:

**The predicate spill region must be warp-scoped, and no such region exists.**
`.local` is thread-private by windowing convention, so a stack-allocated slot
gives a *different* address in every lane — precisely the non-uniform `rbase`
option 1 forbids. Shared memory is CTA-scoped and spending it costs occupancy
directly.

The cheap fix is a **warp-local window** alongside the existing thread-local one
— the same convention `.local` already uses, layered on `.global`, requiring zero
new ISA surface. The compiler computes the warp-uniform base once in the
prologue.

**This creates a dependency on F-1.** Computing a warp-local base needs a warp
index, i.e. `%tid.x >> 5`, i.e. a readable `%tid.x`. So the clean F-2 fix
presumes the F-1 encoding exists. F-2 is the easier *decision*; it is not
independent of F-1, and F-1 should still land first.

## 4. `unballot` is not made redundant by this

Worth stating explicitly, because it looks like it should be. The two solve
different problems and neither substitutes for the other:

| Problem | Instrument |
|---|---|
| Spill and reload of live predicate state (register allocation) | `ld.pred` / `st.pred` — one instruction, no GPR pressure, mask form |
| A *computed* lane mask becoming a predicate — a ballot result manipulated arithmetically, an active-lane set narrowed by a loop counter | `unballot pd, rs` — a register move, no memory round-trip |

`ld.pred`/`st.pred` is strictly the better answer for spilling and makes the
`ballot`-store-load-synthesize sequence in F-2 unnecessary. It does nothing at
all for O-14's original case, which stays open. Per ISA spec O-14, `unballot`
fits the existing Format G layout with no new fields — `rs` at `[18:15]`, `pd` at
`[31:30]`, both canonical.

## 5. The instruction that actually reduces spilling — predicate logic

The question that prompted this — is there something structural, the way an
explicit link register is for GPRs — has a better answer than a faster spill.
The link register does not make spilling cheaper; it makes a two-deep call chain
**not spill at all**. The predicate analogue is not a transfer instruction.

**There is currently no predicate-to-predicate operation of any kind.** Every
predicate write in the ISA comes from a compare (C/C′), a vote (G), a
status-producing ALU op (A″/B″), or a constant (`pmov`). No move, no `and`, no
`or`. Predicates can be consumed only as a guard qualifier.

That is the thing driving pressure. Predicate combining is the fundamental
operation of if-conversion: `if (a && b)` and nested divergent regions both want
`P2 = P0 AND P1`. Without it, a combined predicate has to be re-derived by
running a *predicated compare*, which keeps both the source predicate and the
compare's GPR operands live across the region. Combine-and-free is what keeps a
4-entry file viable at nesting depth 3+; without it, depth 3 is already at the
ceiling.

**Eight bits of operand, which is exactly Format K's payload.** `pd` (2) +
`ps0` (2 addr + 1 negate) + `ps1` (2 addr + 1 negate) = 8, against the 8 bits at
`[15:8]` that Format K leaves after its 6-bit opcode. An exact fit, at 16 bits
per instruction.

| Bits | Width | Field |
|---|---|---|
| `[1:0]` | 2 | class = `10` (K) |
| `[7:2]` | 6 | opcode — `pand` / `por` / `pxor` |
| `[9:8]` | 2 | `pd` |
| `[12:10]` | 3 | `ps0` — 2-bit address + negate |
| `[15:13]` | 3 | `ps1` — 2-bit address + negate |

**Three opcode points cover the complete set**, because independently negatable
sources do the rest:

| Wanted | Encoded as |
|---|---|
| `and`, `or`, `xor` | direct |
| `andn`, `orn` | negate `ps1` |
| `nor` | `pand` with both negated |
| `nand` | `por` with both negated |
| `xnor` | `pxor` with one negated |
| `pmov pd, ps` | `pand pd, ps, ps` |
| `pnot pd, ps` | `pand pd, !ps, !ps` |
| **all-zeros** | `pand pd, ps, !ps` |
| **all-ones** | `por pd, ps, !ps` |

**The set is complete.** All sixteen two-input boolean functions are reachable,
verified by enumeration — including both constants, which fall out of the negate
bit without a dedicated opcode. Dropping `pxor` would cost exactly `XOR` and
`XNOR`, which nothing else reaches; it earns its point.

Two consequences worth recording:

- **Constant predicates drop from 48 bits to 16.** `pmov pd, #lanemask`
  (Format I) is 48-bit-only and is currently the sole path from a constant to a
  predicate. `pand pd, ps, !ps` and `por pd, ps, !ps` give the two constants that
  actually matter at 16 bits. This does **not** undo §1's "no hardwired
  always-true predicate" — an unpredicated instruction still cannot be expressed
  as predicated-on-true, because the encodings differ — but it does make a
  materialized all-true predicate cheap enough to serve as the identity element
  when combining predicates in if-conversion.
- **Both idioms need dependency breaking at rename.** `pand pd, ps, !ps` reads
  `ps` only to ignore it; without recognition it inherits a false dependency on
  whatever last wrote `ps`. This is the x86 `xor eax, eax` case exactly, and the
  same fix applies: recognize the both-fields-equal-with-opposite-negate pattern
  at decode and break the dependency. Cheap — it is a 2-bit comparator plus an
  XOR of the negate bits, on a path that already decodes the opcode.

**One further point is worth spending: `pmov pd, ps` as its own opcode.** Not for
functional coverage — `pand pd, ps, ps` already covers it — but because a
predicate-to-predicate move is a **rename-time no-op**, the same argument ISA
spec §3 makes for the compressed GPR `mov`. For the renamer to elide it, it has
to recognize it, and recognizing `pand pd, ps, ps` means comparing two source
fields *and* checking both negate bits are clear *and* checking the opcode. A
dedicated point makes it a single opcode compare. Copy coalescing does not
eliminate every move, so this fires on real code.

No mnemonic collision with Format I's `pmov pd, #lanemask`: register-operand and
immediate-operand forms of one mnemonic are standard, and Format K already does
exactly this for `mov`, which appears in both the reg-reg (0–23) and reg-imm
(32–47) ranges.

**Recommend stopping there — four points, not more.** The hardware argument for
filling out the set is sound in isolation: predicate bitwise logic is 32 gates
and the ALU cost of another function is nil. But the scarce resource is not gate
area, it is **Format K opcode points**. K has 64 total, carrying the entire
compressed ALU set, compressed load/store, short branches, calls, barriers,
fences, votes and `reconv.hint` — the highest-value encoding real estate in the
ISA. Free points are 28–31, 60–63, and five inside the reg-imm range: thirteen,
and they are the only headroom the compressed forms have. Spending them on
functions already reachable in one instruction buys nothing and forecloses
compressed forms not yet designed.

A three-input predicate op (`if (a && b && c)` wants `P3 = P0 & P1 & P2`) is the
one genuinely unreachable shape, and it should also be declined: `pd` plus three
qualifier-style sources is 11 bits against Format K's 8, so it would need a
32-bit Format I encoding — which is exactly break-even against two 16-bit
two-input ops. Invariant 7 says no.

The field positions do not align with Format K's GPR geometry (`rd` at `[11:8]`,
`rs` at `[15:12]`) because the 8-bit budget is exact and leaves no freedom. That
is consistent with invariant 8 rather than an exception to it: predicates have a
separate RAT (invariant 5), so the predicate rename path reads its own fixed
wires, and these positions are fixed across all three ops.

## 6. `packi` — preserve the unwritten slots, and add a clearing variant

Separate question, same shape: on a **partial write**, is the untouched part of
the destination preserved (making `rd` an implicit source) or cleared?

The general instinct is right, and the canonical evidence is on the x86 side:
legacy SSE writes to `xmm` preserve the upper `ymm` bits and create a
partial-register dependency, VEX-encoded writes zero them and do not, and the
`AL`-writes-into-`EAX` partial-register stalls were bad enough to be worth
architectural surgery. Preserve semantics on a partial write are a known trap.

**It does not apply here, for three reasons.**

*One — the machine already pays for dest-as-implicit-source universally, because
predication requires it.* For `@P0 add R1, R2, R3`, lanes where `P0` is false
must leave `R1` unchanged; that is what predication *is*. So every instruction in
A′, A″, B′, B″, C, C′, D′ and G already reads its destination. Format K's
destructive range adds 24 more reg-reg points and 16 reg-imm. `packi` reading
`rd` introduces no mechanism the machine does not already have everywhere.

*Two — `packi` is not a partial physical write.* The x86 problem was a genuinely
narrow physical write into a wider architectural register, needing either a merge
uop or partial-register tracking. `packi` is read-full-lane, merge in the ALU,
write-full-lane — an ordinary two-source ALU op with a full-width result. There
is no partial-register hazard to avoid because there is no partial write. The
rename cost is one RAT read port on a rare instruction, and ISA spec §3 already
notes the renamer takes this from the opcode it decodes anyway.

*Three — clearing costs `packi` its only break-even use case.* With preserve,
composing a packed FP8 lane is four dependent `packi` and a store. With clearing,
each `packi` wipes its predecessor, so composition becomes four independent
`packi` into four temporaries plus a three-deep OR tree:

| | Instructions | Temporaries | Dependency depth |
|---|---|---|---|
| Preserve | 4 `packi` + 1 store | 1 | 4 |
| Clear | 4 `packi` + 3 `or` + 1 store | 4 | 3 |
| Four narrow stores (the alternative) | 4 stores | — | 1 |

O-16 already rates packing-for-a-wide-store "a wash" at 5 instructions against 4
narrow stores. At 8 instructions and 4 live temporaries it is a clear loss, on a
16-GPR machine, in an epilogue where pressure is already highest. Clearing would
leave `packi` with no profitable use at all — and O-16 keeps it on type-system
completeness grounds, not performance ones, so removing its last break-even case
is worse than it sounds.

**Recommendation: preserve, plus a `packi.z` variant that clears the other
slots.** One Format B opcode point, out of a 5-bit space the spec itself calls
ample. It buys the one thing preserve genuinely costs:

The *first* `packi` of a full-lane compose reads an `rd` whose contents are all
about to be overwritten, so it carries a false dependency on `rd`'s previous
writer. The compiler knows the lane will be fully written; the hardware cannot.
`packi.z` lets the compiler say so — head the chain with `packi.z`, follow with
three ordinary `packi`, and the chain starts clean:

```
    packi.z  rd, ra, #0        ; clears slots 1-3, no dependency on old rd
    packi    rd, rb, #1
    packi    rd, rc, #2
    packi    rd, rd_src, #3
```

Same instruction count as preserve-only, no extra temporaries, and the false
dependency gone. This is the VEX-zeroing lesson applied where it actually helps —
as an *available* semantic rather than the only one. `packi.z rd, rs, #0` is also
independently useful as a raw zero-extending narrow-to-wide placement, which
nothing else expresses (`cvt` converts format, not bit position).

`unpacki` needs no such treatment: its destination is a narrow register written
in full, so it is already a clean single-source op. ISA spec §8 O-16 is right
that `packi` is the only `rd`-as-source deviation in Format B.

## 7. The general rule this implies — answer partial-write semantics once

Three places in the ISA ask the same question and it should get one deliberate
answer, not three incidental ones:

| Site | Partial write | Current spec |
|---|---|---|
| Predicated write to a GPR destination | lanes where the guard is false | **must preserve** — this is what predication means |
| `packi` slots | slots not named by the immediate | preserve (§8 O-16) |
| Predicated write to a *predicate* destination | lanes where the guard is false | **unstated** — see below |

The first is forced and the second is recommended above, so **preserve** is
already the machine's rule in two of three sites. Consistency argues the third
should follow, and the objection recorded below dissolves once the predicate
logic ops exist.

## 8. Open question — predicated writes to a predicate destination

Underspecified in the current spec, and it has to be answered before if-conversion
can be implemented either way.

Formats A″, B″, C and C′ all carry both a predicate qualifier at `[29:27]` and a
predicate destination at `[31:30]`. For `@P0 setp P1, Ra, Rb` — in lanes where
`P0` is false, is `P1`'s bit **preserved** or **cleared**?

- **Preserved** gives a per-lane merge: `P1 = P0 ? (Ra<Rb) : P1_old`. Useful, but
  it is a select, not an AND — getting `P0 & (Ra<Rb)` still requires pre-clearing
  `P1`, and the only instruction that writes a constant predicate is `pmov`,
  which is **48-bit only**. A 48-bit instruction to clear a register before every
  combine is a bad trade.
- **Cleared** gives `P1 = P0 & (Ra<Rb)` directly, which is what if-conversion
  wants, but destroys any merge idiom.

**The pre-clear objection dissolves.** It rested on `pmov` being the only constant
write and 48 bits wide. With `pand pd, ps, !ps` clearing a predicate in 16 bits,
the AND-combine under preserve semantics costs a 16-bit clear plus a 32-bit
predicated compare — 48 bits, identical to an unpredicated 32-bit compare
followed by a 16-bit `pand`. The two readings are now cost-equivalent for the
combining idiom, and preserve additionally gives the per-lane merge, which clear
cannot express at all.

**Recommend preserve**, consistent with §7. It is free — the predicate RAT
already handles dest-as-source for every predicated GPR write — it matches the
rule at the other two sites, and it is strictly more expressive at equal cost.

The point stands that the semantics are currently unstated, and the compiler
cannot proceed on either reading without knowing which.

## 7. Editorial — Format D has two contradictory opcode maps

Not part of the proposal, but found while placing these opcodes.

The Format D section carries two opcode maps. The first
(`isa-v1.2-operation-map-and-encoding.md` line 454, "identical for D and D′")
allocates `00000`–`00011` to base+offset and `00100`–`00111` to base+index, with
predication by format tag. The second (line 488) allocates `opcode[0]` as a
predication bit — `ld.global` / `ld.global.pred` and so on.

The second map is stale, from before O-1 resolved predication to be signalled by
format tag. It contradicts invariant 4 ("never a universal guard operand and
never an opcode bit"), O-1, and the existence of the D/D′ tag pair. It also
reserves `10000`+ for span where the first map reserves `01000`+, which is what
made the free-opcode count ambiguous when placing the instructions above.

The first map is the correct one. The second should be deleted.
