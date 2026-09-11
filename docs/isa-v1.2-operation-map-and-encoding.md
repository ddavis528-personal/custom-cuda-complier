# Native ISA — Operation Map and Encoding

**Version 1.2** · 10 September 2026

The compatibility contract is at the PTX / CUDA Runtime API level, so this ISA carries no
PTX or SASS encoding constraints. A purpose-built CUDA compiler is the bridge.

All 20 bit maps in §3 have been checked for field-width mismatch, overlap and gaps. Two
parameters remain provisional pending first-pass compiler data and are marked as such in
§1. Open items are in §7; §8 is the decision log recording what was settled and why.

**Changes since 1.1.**

*Respecified.* `dp` now reads **full-width** operands and interprets each lane as packed
data, with the packing factor in the opcode (`dp4`, `dp8`, signedness per operand). V1.0 had
it reading narrow sources, which is unimplementable; deleting it outright was then considered
and rejected, at 3× the instruction count in quantized GEMM. Packing inside an opcode is
architecturally invisible; packing as a property of a register is not. See §8, O-15.

*Addition.* `packi` / `unpacki` (Format B), which move a lane's value between a narrow
register and one slot of a wide one — the only path in either direction between narrow and
wide registers. See §8, O-16.

*Carried from 1.1, for readers coming from 1.0.* `pmov` (Format I, subop `01`), a constant
32-bit lane mask written to a predicate register, with Format I regaining the 2-bit subop
field 1.0 dropped; and the correction to the `chwidth` model — a narrow register is a
**narrower slice of 32 lanes**, not a lane holding packed elements, which dropped Format G's
shuffle index from 8 bits to 5 and reworked Format C and invariant 5. See §8, O-13.

---

## 1. Settled parameters this encoding assumes

| Parameter | Value | Confidence |
|---|---|---|
| Logical GPRs | 16 (`R0`–`R15`), 4-bit field | provisional, pending compiler spill data |
| Logical predicates | 4 (`P0`–`P3`) | provisional, pending compiler data |
| Predicate qualifier field | 3 bits (2-bit address + 1 negate) | settled |
| Predicate destination field | 2 bits (no negate — write side) | settled |
| Max GPR sources | 3, all independent of dest | settled |
| Element width | per-register state via `chwidth`, **not** an instruction field | settled |
| Width codes | `00`=32b, `01`=16b, `10`=8b, `11`=4b | settled |
| FP format | per-instruction, folded into opcode space | settled |
| Warp width | 32 lanes | settled |
| Instruction length | 16 / 32 / 48 bits, 16-bit granular | settled |

**A logical GPR always holds 32 lanes.** At `chwidth`=32 that is 32×32 = 1024 bits; at
`chwidth`=8 it is 32×8 = 256 bits. Narrow registers occupy a **narrower physical slice of a
row**, they do not pack more elements into a lane. The 1024-bit datapath is kept full by
coalescing several independent 32-lane instructions, not by widening any single one. Two
consequences follow throughout this document:

- **A predicate register is 32 bits — one bit per lane — at every width.** Predicates do not
  narrow with `chwidth` and have no internal structure to address.
- **No register has sub-lane structure.** A register's elements are one per lane, always.
  Three instructions do address positions inside a lane — `packi`, `unpacki` and `dp4`/`dp8`
  — but they do so from an opcode or an immediate, on ordinary full-width registers. The
  sub-lane view exists for the duration of the instruction and is invisible to allocation,
  renaming, predicates and shuffles. That is the line: **packing may live in an instruction,
  never in a register.**

**No hardwired always-true predicate.** With only 4 logical predicates and no `PT`
equivalent, an unpredicated instruction cannot be expressed as "predicated on true."
Every predicated operation therefore requires a distinct unpredicated encoding. This is
the structural reason the A/A′/A″ and B/B′/B″ ladders, and the D/D′ pair, exist as separate
formats rather than one format with an optional field.

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
immediate bits at `[47:32]`.** Bits `[31:6]` are laid out identically. Every register field,
the opcode, the predicate qualifier and the predicate destination stay exactly where they
are in the 32-bit form, so invariant 8 holds across lengths and not just across tiers.

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
| `1111` | H | Escape / tensor — reserved; 48-bit only, see length table below |

**Which tags have which lengths:**

| Tag | 32-bit | 48-bit |
|---|---|---|
| `0000`–`0010` | A / A′ / A″ | — (no immediate to widen) |
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
| `1111` | reserved | H — carries its own length in `[9:6]` |

Nine of sixteen tags have a 48-bit form and none of them needed a new tag to get one. The
formats with no immediate (A family, C, E, G, I) have nothing to widen and so have no
48-bit rendering at all — consistent with invariant 7.

---

## 3. Format bit maps

Bit 0 is LSB. Formats are 32-bit unless the heading says otherwise. Every table below is
self-contained — the header fields are repeated rather than implied.

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
| 28–31 | reserved | — |
| 32–47 | destructive ALU reg-imm, `rd = rd OP imm4` | `imm4` |
| 48 | `chwidth rd, width` | `[13:12]` = width code |
| 49 | `bra.short` | `[15:8]` = 8-bit signed halfword offset |
| 50 | `call.short` | `[15:8]` = 8-bit signed halfword offset; **implicit** link register |
| 51 | `bar.arrive #id` | `[13:8]` = 6-bit barrier ID |
| 52 | `bar.wait #id, phase` | `[13:8]` = barrier ID, `[14]` = phase parity |
| 53 | `ret rs` | `[15:12]` = `rs`, link-register source |
| 54 | `exit` | unused |
| 55 | `reconv.hint` | `[11:8]` = alt-path length, `[14:12]` = nesting depth, `[15]` = post-dominator |
| 56 | `fence` | `[10:8]` = scope, `[12:11]` = ordering |
| 57–58 | `vote.any`, `vote.all` | `[10:8]` = `ps`, `[12:11]` = `pd` |
| 59 | `ballot rd` | `[10:8]` = `ps`, `[15:12]` = `rd` |
| 60–63 | reserved | — |

Points 0–23: `add`, `sub`, `mul.lo`, `and`, `or`, `xor`, `andn`, `shl`, `shr`, `sra`,
`min.s`, `min.u`, `max.s`, `max.u`, `mov`, `neg`, `not`, `abs`, `fadd.f0`, `fadd.f1`,
`fmul.f0`, `fmul.f1`, `fmin`, `fmax`.

Points 24–27: `ld.global`, `st.global`, `ld.shared`, `st.shared`, all with implicit zero
offset (`rd` = data, `rs` = base). Precomputed-address access is common enough in
coalesced kernels to be worth four opcode points.

Points 32–47: `add`, `sub`, `and`, `or`, `xor`, `shl`, `shr`, `sra`, `min.s`, `max.s`,
`mov` (small constant materialization), and 5 reserved. Immediate signedness is
opcode-defined, as in Format B.

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
the offset. So `call.short` uses the ABI-conventional link register implicitly, and any
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

Same treatment as the A family: fixed register and opcode-low positions, fixed predicate
qualifier position, immediate growing downward from bit 31.

| Bits | Width | B | B′ | B″ |
|---|---|---|---|---|
| `[1:0]` | 2 | `00` | `00` | `00` |
| `[5:2]` | 4 | fmt `0011` | fmt `0100` | fmt `0101` |
| `[10:6]` | 5 | `opcode[4:0]` | `opcode[4:0]` | `opcode[4:0]` |
| `[14:11]` | 4 | `rd` | `rd` | `rd` |
| `[18:15]` | 4 | `rs0` | `rs0` | `rs0` |
| `[21:19]` | 3 | *immediate* | **pred qualifier** | **pred qualifier** |
| `[23:22]` | 2 | *immediate* | *immediate* | **pred dest** |
| `[31:24]` | 8 | *immediate* | *immediate* | *immediate* |

The immediate is contiguous in every tier, occupying the top of the word with its **MSB
always at bit 31**: `[31:19]` = 13 bits in B, `[31:22]` = 10 bits in B′, `[31:24]` = 8 bits
in B″. Sign-extension logic therefore takes its sign bit from a fixed wire; only the
magnitude width varies by format.

Two side effects of the realignment, both favourable: B and B′ each gain an immediate bit
(12 → 13 and 9 → 10) by recovering the bit the old 6-bit opcode was consuming, and all three
tiers now share a 5-bit opcode. Thirty-two points is ample for reg-immediate ALU — most of
Format A's opcode map (SFU, conversions, three-source ops, bit-manipulation) has no
immediate form at all.

Immediate signedness remains opcode-defined.

**Tier allocation, as in the A family.** The three tiers share one 5-bit opcode space, and
B″ is a bounded subset of it — only status-producing arithmetic has any use for a predicate
destination. `packi`/`unpacki` exist in B and B′ and have no B″ form.

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

The 5-bit opcode covers `{6 comparison predicates} × {signed int, unsigned int, FP}` = 18
points for `setp`, plus the materializing `set` variants, inside 32. `rd` is always
allocated and the opcode selects whether it is written.

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
| `01000`+ | — | reserved (span/wide transfers) — deferred, see §9 |

Transfer size is inherited from `rdata`'s `chwidth` — no size field. Address space is in
the opcode.

Effective address in the base+index modes is `rbase + (rindex << scale) + disp`, where
`scale` is `log2(element_size)` taken from `rdata`'s current `chwidth` when bit `[23]` is
set, and zero when it is clear.

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

**Opcode map (5 bits, 32 points):**

| Opcode | Mnemonic |
|---|---|
| `00000` / `00001` | `ld.global` / `ld.global.pred` |
| `00010` / `00011` | `st.global` / `st.global.pred` |
| `00100` / `00101` | `ld.shared` / `ld.shared.pred` |
| `00110` / `00111` | `st.shared` / `st.shared.pred` |
| `01000`–`01111` | base+index variants of the above (`opcode[0]` = predicated, as above) |
| `10000`+ | reserved (span/wide transfers) — deferred, see §9 |

`.local` maps to `ld.global`/`st.global` via the thread-private windowing convention.
`.const` maps to `ld.global` with a read-only compiler contract — no dedicated opcode or
hardware in this pass.

### Formats M / M′ — Atomics

Single ROB entry. Normal ALU execution on the buffered old value; existing load buffer
(with exclusive-ownership request) and store buffer handle the memory side.

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
| `[16:11]` | 6 | barrier ID (64 entries — matches the 4×16 table) |
| `[26:17]` | 10 | expected arrival count |
| `[31:27]` | 5 | reserved |

`bar.arrive` and `bar.wait` have **no 32-bit form** — both are fully expressed in Format K.
Only initialization needs 32 bits, because a barrier ID plus a 10-bit expected count is 16
bits of operand and the compressed forms have 8. See O-12.

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
| `00100`+ | reserved | |

`ret`, `exit`, `reconv.hint`, `fence`, `bar.arrive` and `bar.wait` have no 32-bit encoding —
all six are fully expressed in Format K.

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
| B′ | 10 | **26** | `[31:22]` | `[47:32]` |
| B″ | 8 | **24** | `[31:24]` | `[47:32]` |
| C′ | 8 | **24** | `[26:19]` | `[47:32]` |
| D (base+offset) | 13 | **29** | `[31:19]` | `[47:32]` |
| D (base+index) | 8 | **24** | `[31:24]` | `[47:32]` |
| D′ (base+offset) | 10 | **26** | `[31:30]`,`[26:19]` | `[47:32]` |
| D′ (base+index) | 5 | **21** | `[31:30]`,`[26:24]` | `[47:32]` |
| F | 18 | **34** | `[31:14]` | `[47:32]` |

The sign bit sits at 47 in every 48-bit form and at 31 in every 32-bit one — two fixed
wires selected by a signal available at bit 0.

**This resolves O-5.** The tight immediates that prompted it (B″ and C′ at 8 bits, D′
base+index at 5) are no longer a ceiling, they are just the short encoding. The compiler
picks per-instruction and pays 16 bits only where it needs them.

Note what this replaces. Without the sibling, an over-range immediate costs a Format F
materialization plus a register plus a reg-reg instruction — 64 to 80 bits and one register
of pressure, on a machine with only 16. The sibling costs 16 bits and no register. It also
means B/B′/B″ do not need generous 32-bit immediates "just in case," which is what let the
short forms stay tight enough to fit the field-alignment scheme in the first place.

Formats with no immediate — A, A′, A″, C, E, G — have no 48-bit rendering. There would be
nothing to put in the extra halfword, and invariant 7 forbids reserved-bit padding.

Two qualifications. Format I is absent from the table but *does* have a 48-bit form: `pmov`
carries a 32-bit lane mask and exists only at that length, while `chwidth.multi` exists only
at 32 — the two subops sit at different lengths rather than being siblings. And within
Format B, `packi`/`unpacki` do not take the sibling: a 3-bit slot index has nothing to widen,
so those opcodes are 32-bit only.

### Format G — Warp-collective (32-bit)

| Bits | Width | Field |
|---|---|---|
| `[1:0]` | 2 | length = `00` |
| `[5:2]` | 4 | fmt = `1100` |
| `[10:6]` | 5 | opcode |
| `[14:11]` | 4 | `rd` (ballot dest / shuffle dest) |
| `[18:15]` | 4 | `rs` (shuffle source) |
| `[23:19]` | 5 | shuffle lane index — or `ps` at `[21:19]` for vote/ballot |
| `[26:24]` | 3 | reserved |
| `[29:27]` | 3 | **pred qualifier** |
| `[31:30]` | 2 | `pd` (vote dest) / reserved |

**Opcode map:** `shfl.idx`, `shfl.up`, `shfl.down`, `shfl.bfly`, each with an
immediate/register index-source bit, plus predicated `vote.any`, `vote.all`, `ballot`.

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
| 32–63 | floating point (8 ops × 4 format codes) | A, A′ |
| 64–127 | packed dot-product-accumulate | A, A′ |
| 128–255 | conversions | A only |
| 256–1023 | unallocated — SFU and future extension | A only |

Per the tier allocation rule, A′'s 7-bit opcode reaches the low 128 and A″'s 5-bit opcode
the low 32. Operations that want predication therefore have to live low, which is why the
ordering above is a constraint on the map rather than a description of it.

### Integer / bitwise / misc — points 0–31

`add`, `sub`, `mul.lo`, `mul.hi.s`, `mul.hi.u`, `mad.lo`, `mad.hi`, `and`, `or`, `xor`,
`andn`, `shl`, `shr`, `sra`, `min.s`, `min.u`, `max.s`, `max.u`, `mov`, `sel`,
`abs`, `neg`, `popc`, `clz`, `brev`, `prmt`
— **26 of 32 used.**

### Floating point — points 32–63

8 operations × 4 format codes:

`fadd`, `fsub`, `fmul`, `ffma`, `fmin`, `fmax`, `fneg`, `fabs`

FP format is encoded in the **low 2 bits of the FP opcode sub-range** rather than as a
separate field — per-instruction, as settled, but at zero additional field cost:

| Register `chwidth` | Format `00` | Format `01` | `10` / `11` |
|---|---|---|---|
| 32-bit | IEEE FP32 | — | reserved |
| 16-bit | IEEE FP16 | BF16 | reserved |
| 8-bit | E4M3 | E5M2 | reserved |
| 4-bit | E2M1 | reserved | reserved |

Mismatching format against a register's actual contents produces deterministic garbage,
not a hazard — compiler-correctness contract, no interlock, consistent with the policy
applied to width mismatches generally.

---

### Packed dot-product-accumulate — points 64–127

| Opcode | Operation |
|---|---|
| `dp4.ss` / `dp4.su` / `dp4.us` / `dp4.uu` | 4×INT8 per lane → INT32, signedness per operand |
| `dp8.ss` / `dp8.su` / `dp8.us` / `dp8.uu` | 8×INT4 per lane → INT32 |

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

Living at 64–127 makes these reachable from A′ (predicated) but not A″, which is correct —
a dot product has no status output to write.

**`mad.lo` remains the alternative**, with `rs0`/`rs1` at narrow `chwidth` and `rs2`/`rd`
wide: one MAC per lane, no packing anywhere. It costs roughly 3× the instructions of `dp4`
for the same work and is the right choice when the narrow data is already register-resident.
See O-15.

Shifts are uniform-amount only: one shift count broadcast across all packed elements, no
cross-element bit movement.

### Conversions — points 128+ (extension space)

The destination format is **part of the opcode**; the source format rides in the low 2 bits
of the opcode as it does for every other FP operation. Widths come from the source and
destination registers' `chwidth` as usual, so the instruction never names a width.

| Opcode base | Destination |
|---|---|
| `cvt2fp32` | IEEE binary32 |
| `cvt2fp16` | IEEE binary16 |
| `cvt2bf16` | BF16 |
| `cvt2e4m3` | FP8 E4M3 |
| `cvt2e5m2` | FP8 E5M2 |
| `cvt2e2m1` | FP4 E2M1 |
| `cvt2int.s` / `cvt2int.u` | signed / unsigned integer |

Each base × 4 source-format codes × 4 rounding modes = 128 points, sitting well inside the
extension space. **This resolves O-2** — the two-format problem disappears because the two
formats never have to share one field: one is the opcode, the other is the opcode's low
bits. No new format, no new field.

Conversions live above point 128 and are therefore not reachable from A′ or A″. Predicated
conversions would need a `mov` under predication instead, which is the right trade for an
operation this rare.

## 5. Encoding density

Three lengths: 16, 32, 48. The 16-bit forms cover the two highest-frequency shapes in ML kernel code
— accumulate-form FMA and two-operand destructive ALU — plus the small-content operations
(`chwidth`, `reconv.hint`, `ret`, `exit`, zero-offset load/store, short branch). Everything
else is 32 bits by default, with the 48-bit sibling available per-instruction wherever an
immediate does not fit. Only CAS requires 48 unconditionally.

A GEMM inner loop consisting mostly of accumulate-FMA and pointer arithmetic should
encode at close to 16 bits per instruction. How close depends entirely on how often the
allocator can arrange `rd == rs0`, which is a compiler-backend question, not an ISA one.

For reference, Volta-and-later SASS uses 128 bits per instruction — 64 bits of instruction
plus 64 bits of compiler-encoded scheduling control (stall counts, barrier masks, reuse
flags). Roughly 4× density is available here, but the comparison is not free: that control
payload is buying NVIDIA static scheduling, which this design replaces with hardware OoO.
The density win and the OoO hardware cost are the same trade viewed from two directions.

---

## 6. Design invariants

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
   produce deterministic results, never undefined behavior. Same for FP format mismatches.
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
8. **Register fields sit at fixed positions across format tiers *and lengths*.** `rd` at `[14:11]`,
   `rs0` at `[18:15]`, `rs1` at `[22:19]`, `rs2` at `[26:23]`, predicate qualifier at
   `[29:27]`, predicate dest at `[31:30]` — held constant across A/A′/A″, C/C′ and, for the
   fields they use, B/B′/B″, D/D′ and M/M′ — and identically in the 48-bit rendering of any
   of them, since a 48-bit instruction is its 32-bit sibling plus a high halfword. Rename
   lookup starts from fixed wires before format decode resolves, and before length is even
   relevant. Surplus opcode bits go *up* into high positions rather than being carved out of
   the middle, and where a large immediate would collide with the qualifier the immediate is
   split around it (D′, `bra.pred`) rather than the qualifier being moved. **There are no
   exceptions among the 32/48-bit formats.** The compressed forms have their own internal
   geometry — `rd` at `[11:8]`, `rs` at `[15:12]` — equally fixed within class J/K but
   deliberately distinct, since they are a separate decode path.

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

---

## 7. Open items

Five items remain open. Two are blocked on the first-pass compiler, one is a check
against the existing barrier spec, one is a compiler-experimentation question worth
answering early, and one is a gap with no forcing workload yet. None blocks RTL work on
the settled formats.

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
- **`bar.wait #id, phase`** needs the ID plus one phase-parity bit. Seven bits, comfortably
  compressed.

**The assumption to check against the barrier design:** that the wait's phase parity is
**software-tracked** — the compiler alternates the bit each time through the loop, and the
comparator matches it against the table entry's epoch parity. This is what keeps `wait` at
seven bits of operand and, more importantly, keeps **all** per-warp barrier state out of the
machine: nothing has to remember which epoch a given warp arrived in, because the
instruction stream carries it.

The alternative — the barrier table tracking a per-warp arrival epoch so `wait` can be
implicit — costs storage proportional to (resident warps × barrier entries), which is
exactly the kind of small-state-times-large-multiplicity cost the GPR and predicate counts
were kept lean to avoid. It also would not change the encoding, since the ID alone would
then suffice. So the encoding is safe either way; the phase bit is cheap insurance and can
be ignored by hardware that does not need it.

Both readings are consistent with epoch-tagged retirement and comparator-driven wake. Worth
a check against the settled barrier spec, but not a blocker for the encoding.

---

**O-14 — No path from a GPR lane mask back to a predicate.** `ballot` writes a warp-wide
mask into a GPR; nothing reverses it. A mask that is computed rather than constant — a
ballot result manipulated arithmetically, an active-lane set narrowed by a loop counter —
cannot be returned to the predicate file at all. `pmov` covers only the constant case.

The natural fix is a register-sourced companion in Format G, `unballot pd, rs`, which is the
exact inverse of `ballot` and fits the existing G layout without new fields. Not added here
because it was surfaced by writing up O-13 rather than by a workload, and because it is the
kind of thing first-pass compiler output will either justify immediately or not at all.

---

## 8. Decision log — resolved during specification

Recorded because the reasoning matters more than the outcome if any of these is revisited.

**O-1 — Predication mechanism — resolved.** Predication is signalled by **format tag**
everywhere: A/A′/A″, B/B′/B″, D/D′. Format D got tag `1101`, freed by the invariant-7
deletions. Consequence: the prime suffix now means "predicated" consistently, so the old
Format D′ (atomics) was renamed **Format M**, with the 48-bit CAS form as M′.

**O-2 — `cvt` two format specifiers — resolved.** Destination format is the opcode
(`cvt2e4m3`, `cvt2bf16`, …); source format is the opcode's low 2 bits, exactly as for every
other FP operation. Widths come from `chwidth` on each register. The two formats never
share a field, so there is nothing to disambiguate. See §4.

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

## 9. Explicitly out of scope for V1

- **Format H (tensor/MMA)** — register-group operand model undesigned. The `11` length escape
  and the `1111` format tag are reserved for it.
- **FP packed dot-product** (BF16×BF16 → FP32 and similar). `dp4`/`dp8` are integer-only.
  The FP case needs per-element exponent handling inside the reduction rather than a simple
  product sum, and it is the natural companion to Format H's fragment operands — design it
  there.
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
  3. At 16 GPRs the register group is structurally awkward — see the GPR-count note in §10.

  Format D opcode points `01000`+ stay reserved. Register-group addressing is the same
  mechanism Format H needs for MMA fragment operands; if span is ever revived it should
  reuse whatever H defines rather than inventing a parallel scheme.

---

## 10. Carried deferred items (not encoding-blocking)

- Wake-broadcast timing relative to epoch increment
- Drain FIFO depth vs. wake width
- Formal property for the N+1 arrival race window
- 16 vs. 32 GPRs; 4 predicate registers — both pending compiler spill data. **Carry one
  forward risk into that decision:** span transfers were deferred partly because a
  four-register group at 16 GPRs leaves exactly four legal aligned destinations, each eating
  a quarter of the architectural file. That is a structural limit, not a statistical one,
  and spill data will not surface it. If the spill numbers come back ambiguous between 16
  and 32, the prospect of later wanting span or MMA fragment operands is the tiebreaker
  toward 32.
- SMT-4 checkpoint drain mechanics
- Sub-row-granular scoreboarding (GPRs and predicates)
- Narrow-width coalescing strategy (hybrid TLP/ILP), decoupled from SMT width
- Physical row subdivision / anti-fragmentation allocation
- Speculative exclusive-ownership contention between concurrent atomics
- **Special-register / launch-ABI surface** — thread index, CTA index, block dimensions and
  similar are read somehow, and this document has never said how. Not encoding-blocking so
  far, but O-13 is the first decision that leaned on its absence, and a lane-index source
  would change the answer on lane-granular masks.
