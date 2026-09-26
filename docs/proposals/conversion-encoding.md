# Conversion encoding — give §4's `cvt` block an arithmetic, and halve it

**Status:** RESOLVED — accepted as O-34, with two changes from the design track
and one error of mine corrected. Implemented; `tools/verify.sh` is green.

> **Decided differently in two places, and read the spec rather than this
> document for what shipped:**
>
> 1. **Field order is `64 + 16×dest + 4×src + round`**, not `4×round + src`.
>    This document put `src` in the low bits to honour a §4 sentence written
>    about the FP block, which has one format dimension. Conversions have two,
>    and `dest`/`src` adjacent form a 4-bit field naming the conversion path —
>    which is what a converter datapath selects on.
> 2. **`dp4`/`dp8` keep their predicated encoding.** §6 below poses 64–127 as a
>    contest and it is not one: `32 + 8×format + op` generates 48–63 for FP
>    format codes `10`/`11`, which are reserved at every `chwidth`. `dp` moved
>    there. The real cost is the two spare FP format codes, not `dp`
>    predication — a better trade and one this document did not identify.
>
> **And the argument here is the weaker one.** §5 leads with compression and
> F-56. The decision was taken on invariant 1: `cvt2fp32` versus `cvt2fp16`
> differ only in element width, so the eight-base scheme put an element-width
> field in the opcode, and left `cvt2fp16` targeting a 32-bit register with no
> defined meaning. That stands without F-56 entirely.
>
> **One error of mine:** §7 claims `transpose`'s "no A′ form" bucket goes from 3
> to 0. It goes to **1**. Two of the three are conversions; the third is
> `rcp.f32` at §4 point 256, and Format A′ reaches 127. Measured after
> implementation: 3 → 1, lane-activations 1809 → 1747.

**Against:** ISA v1.5 (`isa-v1.5-operation-map-and-encoding.md`), §3 Formats
A/A′/A″, §4 opcode map, O-2, O-28, O-31, O-33.

**Self-contained:** the ISA facts this argument needs are restated in §1 below,
so this can be read without the specification open.

---

## 0. Summary

Three things, in increasing order of how much they change:

1. **Editorial, and a straight bug.** §4 gives the conversion block a *count* —
   8 bases × 4 source-format codes × 4 rounding modes = 128 points — but never an
   *arithmetic*. O-28 made opcode numbering normative and supplied rules for the
   two ranges that needed one; the conversion block is a third such range and was
   missed. There is currently no fact of the matter about what `cvt.f32.u32` is,
   which is why the backend assigned 128–131 flat and no checker objected.

2. **Allocation, and already latent in the design.** An integer *source* needs no
   new mechanism. The 2-bit format code selects an interpretation to be read at
   the register's `chwidth`, and codes `10`/`11` are unallocated at every
   `chwidth`. Give them to signed and unsigned integer. §4's count already
   budgets for four source codes.

3. **Structural, and the one worth arguing about.** If the *source* format is a
   2-bit code read against the source register's `chwidth`, the *destination*
   should be too. That replaces eight destination bases with a 2-bit destination
   code and takes the block from **128 points to 64**, at no loss of
   expressiveness — the six FP bases are spending opcode space on width
   distinctions `chwidth` already makes.

64 points is exactly the range 64–127, which is the last contiguous space
reachable from Format A′ — the predicated tier. Taking it resolves a measured
finding (F-56) and costs `dp4`/`dp8` their predicated encoding.

---

## 1. The ISA facts this rests on

**Element width is register state, not an instruction field.** Invariant 1: *"No
instruction carries an element-width field. Width is per-logical-register
state."* A GPR is 32 lanes with one element per lane; `chwidth` sets that
element's width (32/16/8/4-bit) for a logical register.

**The 2-bit "format code" selects an interpretation, not a width.** From §4's
floating-point section:

| Register `chwidth` | Format `00` | Format `01` | `10` / `11` |
|---|---|---|---|
| 32-bit | IEEE FP32 | — | reserved |
| 16-bit | IEEE FP16 | BF16 | reserved |
| 8-bit | E4M3 | E5M2 | reserved |
| 4-bit | E2M1 | reserved | reserved |

So `fadd.f0` is an FP32 add, an FP16 add or an E4M3 add depending on the
registers' `chwidth`. **Codes `10` and `11` are unallocated in every row** — two
of the four values, at every width, are free.

**Format A's opcode is 10 bits; the predicated tiers are narrower.** §3 gives
Format A a 10-bit opcode (`[31:27]` ++ `[10:6]`, 1024 points). Format A′ —
predicated — spends `[29:27]` on the predicate qualifier and has **7 bits, so it
reaches points 0–127 only**. Format A″ has 5 bits and reaches 0–31. The tier rule
is that A′'s space *is* A's low 128: same point, same mnemonic, reachable with or
without a qualifier depending on which tier is encoded.

**Current §4 allocation:**

| Range | Contents | Reachable from | Actually used |
|---|---|---|---|
| 0–31 | integer, bitwise, misc | A, A′, A″ | 26 of 32 |
| 32–63 | floating point, `32 + 8×format + op` | A, A′ | 32 of 32 nominally; codes `10`/`11` (points 48–63) hold nothing |
| 64–127 | packed dot-product-accumulate | A, A′ | **1 of 64** (`dp4.ss`); 8 mnemonics planned |
| 128–255 | conversions | A only | 4 of 128 |
| 256–1023 | SFU and future extension | A only | 7 of 768 |

**O-2 settled the two-format problem** by putting the destination format in the
opcode and the source format in the opcode's low bits, so the two never share a
field. This proposal keeps that resolution and changes only how the destination
half is spelled.

---

## 2. Finding 1 — the block has a count but no arithmetic

§4 says, in full:

> The destination format is **part of the opcode**; the source format rides in
> the low 2 bits of the opcode as it does for every other FP operation. […] Each
> base × 4 source-format codes × 4 rounding modes = 128 points.

That fixes the shape and the size. It does not fix:

- the ordering of the eight bases,
- which bit positions carry the rounding mode,
- the encoding of the four rounding modes,
- consequently, the opcode of any actual conversion.

O-28 anticipated exactly this class of gap — *"two independent implementations
picking different orders would produce silently incompatible binaries"* — and
resolved it by making list order normative, with explicit rules for the two
ranges where a list was not enough (Format A floating point, Format K's
reg-immediate range). The conversion block is a three-dimensional product and
needs a rule for the same reason Format A floating point did. It did not get one.

The consequence in the implementation: `CCVInstrInfo.td` assigns

```
cvt.f32.s32 = 128    cvt.f32.u32 = 129
cvt.s32.f32 = 130    cvt.u32.f32 = 131
```

flat, in the order the backend happened to need them. Under any product layout
consistent with §4's own sentence, none of those four is correct. Nothing caught
it because there was nothing to check against.

**This must be fixed regardless of which of the two layouts below is chosen.**

---

## 3. Finding 2 — an integer source is already encodable

§4's conversion table lists `cvt2int.s` / `cvt2int.u` as destination bases, so an
integer *destination* is covered. It says nothing about an integer *source*, and
the format-code table marks `10`/`11` reserved everywhere.

The fix is an allocation, not a mechanism:

| Source format code | Meaning |
|---|---|
| `00` | FP format 0 at the source's `chwidth` — FP32 / FP16 / E4M3 / E2M1 |
| `01` | FP format 1 at the source's `chwidth` — BF16 / E5M2 |
| `10` | **signed integer** at the source's `chwidth` — s32 / s16 / s8 / s4 |
| `11` | **unsigned integer** at the source's `chwidth` — u32 / u16 / u8 / u4 |

Width comes from `chwidth`, as everywhere else; the instruction still names no
width, so invariant 1 holds unchanged. §4's "4 source-format codes" already
counts these two.

This alone makes `cvt.f32.u32` expressible in the spec's own scheme, which it is
not today.

---

## 4. Proposal A — keep eight bases, specify the arithmetic

The conservative option. Keep the block at 128 points and give it a rule.

```
opcode = 128 + 16×base + 4×round + src
```

- `base` — 3 bits, list order: `cvt2fp32` 0, `cvt2fp16` 1, `cvt2bf16` 2,
  `cvt2e4m3` 3, `cvt2e5m2` 4, `cvt2e2m1` 5, `cvt2int.s` 6, `cvt2int.u` 7
- `round` — 2 bits: `rn` 0, `rz` 1, `rm` 2, `rp` 3 (PTX's four modes, PTX's order)
- `src` — 2 bits, the source format code from §3 above

Source in the low 2 bits, as §4 already states. Each base owns a contiguous block
of 16, matching how each FP format code owns a contiguous block of 8.

The four conversions the backend needs become 130, 131, 228, 244.

**What this does not do:** the block stays at 128–255, above Format A′'s 7-bit
ceiling, so conversions remain unpredicable and F-56 stands.

---

## 5. Proposal B — collapse the destination to a format code

**Recommended.**

Eight destination bases re-encode information the destination register already
holds. `cvt2fp32` versus `cvt2fp16` versus `cvt2e4m3` is a width distinction, and
width is `chwidth`. What actually needs naming is *which interpretation at that
width* — which is a 2-bit code, exactly as on the source side.

```
opcode = 64 + 16×dest + 4×round + src
```

- `dest` — 2 bits, the format code read against the **destination** register's `chwidth`
- `round` — 2 bits, as above
- `src` — 2 bits, the format code read against the **source** register's `chwidth`

2 + 2 + 2 = 6 bits = **64 points**, occupying 64–127 exactly.

### It loses nothing

Per `chwidth`, the destination code yields:

| `chwidth` | `00` | `01` | `10` | `11` |
|---|---|---|---|---|
| 32-bit | FP32 | — | s32 | u32 |
| 16-bit | FP16 | BF16 | s16 | u16 |
| 8-bit | E4M3 | E5M2 | s8 | u8 |
| 4-bit | E2M1 | — | s4 | u4 |

Every destination the eight-base scheme reaches, this reaches: `cvt2int.s` and
`cvt2int.u` already take their width from `chwidth`, so narrow integer
destinations were always nameable. The difference is on the FP side, where six
bases are spending opcode space on width distinctions the destination register
already makes. **The gain is the halving, not new reachability** — worth stating
plainly, because "more expressive" would be a nicer argument and it is not the
true one.

### Worked cases

| | dest `chwidth` + code | src `chwidth` + code | round | opcode |
|---|---|---|---|---|
| `cvt.f32.s32` | 32, `00` → FP32 | 32, `10` → s32 | `rn` | 64 + 0 + 0 + 2 = **66** |
| `cvt.f32.u32` | 32, `00` → FP32 | 32, `11` → u32 | `rn` | 64 + 0 + 0 + 3 = **67** |
| `cvt.s32.f32` | 32, `10` → s32 | 32, `00` → FP32 | `rz` | 64 + 32 + 4 + 0 = **100** |
| `cvt.u32.f32` | 32, `11` → u32 | 32, `00` → FP32 | `rz` | 64 + 48 + 4 + 0 = **116** |
| `cvt.bf16.f32` | 16, `01` → BF16 | 32, `00` → FP32 | `rn` | 64 + 16 + 0 + 0 = **80** |
| `cvt.e4m3.f16` | 8, `00` → E4M3 | 16, `00` → FP16 | `rn` | 64 + 0 + 0 + 0 = **64** |
| `cvt.s32.s8` (sign-extend) | 32, `10` → s32 | 8, `10` → s8 | — | 64 + 32 + 0 + 2 = **98** |

All inside 64–127, therefore all reachable from Format A′ and predicable.

The last row is worth noting: widening an integer is a real conversion on this
machine, because `chwidth` reinterprets a register's elements rather than
extending them. Mixed-`chwidth` operands are already established practice — §4's
`mad.lo` discussion has `rs0`/`rs1` narrow and `rs2`/`rd` wide.

### Costs

**A `cvt` cannot be disassembled to a precise type without knowing `chwidth` at
that program point.** This is real and it is a debugging cost. It is also already
true of every FP instruction in the ISA — the disassembler prints `fadd.f0`, not
`fadd.f32` — so it is the machine's existing rule rather than a new exception,
and it inherits the same contract: *"mismatching format against a register's
actual contents produces deterministic garbage, not a hazard."*

**Some rounding codes are meaningless.** Integer-to-integer conversion has
nothing to round. Rather than carve exceptions, leave those points reserved; the
block is a product and 2 bits of rounding on every combination is the cheap
choice.

**Two destination codes are unused at 32-bit and 4-bit `chwidth`** (`01` in both
rows). Same dead space the FP block already has, and it is where a future 32-bit
format such as TF32 would land.

**O-2's write-up changes.** Its resolution — *"destination format is the opcode,
source format is the opcode's low 2 bits"* — stays true; "the opcode" becomes a
code within the opcode rather than a base. Worth an amendment, not a reversal.

---

## 6. What Proposal B does to F-56, and what it costs

### The finding

F-56, from the compiler side: conversions at 128+ and the SFU at 256+ are Format
A only, so they cannot carry a predicate qualifier. This became load-bearing with
O-33, which runs warp-uniform work on lane 0 and broadcasts the result — an
instruction with no predicated form cannot be masked, so it burns all 32 lanes
however redundant it is.

Measured on a transpose kernel, of the warp-uniform instructions that could not
be masked:

| blocked because | count |
|---|---|
| `sel` reads `[29:27]` as its selector, so the field is taken | 10 |
| **conversions at 128+ and SFU at 256+ have no A′ form** | **3** |
| `srd` is Format K only (invariant 7) | 1 |
| a barrier must not be masked | 1 |

The three are `cvt.f32.u32`, `rcp.f32` and `cvt.u32.f32` — the head of the
integer-division sequence O-31 introduced, on a divisor that is uniform across
the warp.

Three is not a large number. It is, however, the only one of the four rows with a
cheap fix, and it scales with how much integer division appears in uniform code.

### The trade

Proposal B's 64 points land exactly on 64–127, which §4 reserves for packed
dot-product-accumulate. That range currently holds **one defined instruction**
(`dp4.ss`) against a planned eight (`dp4`/`dp8` × four signedness combinations).
Taking it means `dp4`/`dp8` move above 128 and lose their predicated encoding.

§4 currently argues the other way: *"Living at 64–127 makes these reachable from
A′ (predicated) but not A″, which is correct — a dot product has no status output
to write."* That argument predates O-33 and reads to me as being about A″ rather
than about predication having a use.

**The case for the swap:** `dp4`/`dp8` is per-lane accumulation in a quantized
GEMM inner loop. Its accumulator is divergent by construction — that is the
point of it — so it is the last instruction in the ISA anyone would mask to lane
0. Conversions sit on the critical path of a warp-uniform division, which is
measured, in real generated code, today. If exactly one of the two ranges can be
predicable, conversions have the better claim.

**The case against, and it needs your judgement, not mine:** predication is not
only for O-33. `dp4` under a divergent control-flow predicate, in an inner loop
with a ragged tail, is a plausible shape I have not written or measured. I have
no INT8 GEMM in the benchmark set. If that shape matters, this trade is wrong and
Proposal A plus a targeted relocation of the five hot conversion points is the
smaller move.

### Alternative placements considered

- **26–31** (6 free in the integer range) — not contiguous enough for a 64-point
  product, and A″-reachable space is more valuable than this.
- **48–63** (the FP block's reserved format codes `10`/`11`) — 16 points, and
  reclaiming them breaks `32 + 8×format + op`, which O-28 made normative.
- **Split the block** — hot conversions low, cold ones high. Does not divide on a
  bit boundary, and produces two encodings of one operation, which is the thing
  the tier rule exists to avoid.

---

## 7. Implementation consequence

Small, and confined to files that are already generated or checked:

- `CCVInstrInfo.td` — four opcode constants change; under Proposal B they move
  into A′'s reach, so `Cvt` gains a predicated multiclass the way `AluRR` has
  `AluRRP`.
- `CCVMaskUniform.cpp` — three entries in `predicatedForm`.
- `ccv-sim` — opcode constants only; semantics unchanged.
- `tools/check-encoding.py`, `ccv-roundtrip` — pick up the change automatically.

The uniformity reporter would then count 0 in the `no A′ form` bucket for
`transpose` rather than 3, which is the measurable outcome and the thing to check
the change against.

**Nothing here is on a critical path.** No kernel miscompiles today; the four
conversions work because encoder, decoder, assembler and simulator all read the
same wrong constants from one place. It becomes urgent the moment a second
implementation exists, which is precisely O-28's argument.

---

## 8. Questions for the ISA design track

1. **Proposal A or B?** A is editorial and uncontroversial. B is a real change to
   how `cvt` is specified and should be decided on its own merits, not as a
   means to F-56.
2. **Does `dp4`/`dp8` need a predicated encoding?** This is the only question in
   the document I cannot answer from measurement, and B depends on it.
3. **Rounding-mode encoding** — is `rn`/`rz`/`rm`/`rp` = 0/1/2/3 right, or does
   the hardware want a different order? The compiler has no preference.
4. **Should the integer source codes be `10` = signed, `11` = unsigned**, or the
   reverse? No technical difference; worth fixing before two implementations
   exist.
5. **Does anything else read the conversion opcode's structure** — a decoder
   optimisation, a format-conversion datapath that wants the source code in a
   particular position? The layouts above put `src` in the low 2 bits because §4
   already says so, but that sentence may itself have been a placeholder.
