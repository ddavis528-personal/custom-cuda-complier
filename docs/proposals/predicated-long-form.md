# A 48-bit predicated Format A — reaching the whole opcode map from A′

**Status:** proposal, for decision. Raised by compiler work on CCV (the LLVM
backend); nothing is implemented against it.

**Against:** ISA v1.5 (`isa-v1.5-operation-map-and-encoding.md`), §2 length
escape, §3 Formats A/A′/A″, §4 opcode map, invariants 7 and 8, O-33, O-34.

**Self-contained:** the ISA facts the argument needs are restated in §1, so this
reads without the specification open.

---

## 0. Summary

Format A′ — the predicated ALU tier — has a **7-bit opcode**, so it reaches
opcode points 0–127 and no further. Everything above is Format A only and cannot
carry a predicate qualifier. After O-34 packed 0–127 solid, there is no room to
relocate anything else down.

**Define a 48-bit rendering of Format A′.** It costs no new format tag (tag
`0001` at length `11` is unallocated), preserves every invariant-8 field
position, and carries a **full 10-bit opcode** — so it predicates the entire
1024-point Format A space in one move rather than buying one instruction at a
time.

Invariant 7 does not merely permit this; it names the justification:

> A longer form must earn its length by carrying something the shorter one
> cannot — more offset range, an explicit register, **a predicate qualifier**, a
> predicate destination.

A 32-bit Format A `rcp.f32` cannot carry a qualifier. A 48-bit form that does,
earns its length by the invariant's own list.

---

## 1. The facts this rests on

**Format A's opcode is 10 bits; the predicated tiers are narrower.** The three
tiers share one field skeleton and differ in what the high bits do:

| | opcode bits | reach | what it gives up |
|---|---|---|---|
| A | `[31:27]` ++ `[10:6]` = 10 | 0–1023 | — |
| A′ | `[31:30]` ++ `[10:6]` = 7 | **0–127** | `[29:27]` → predicate qualifier |
| A″ | `[10:6]` = 5 | 0–31 | `[31:30]` → predicate destination |

The tier rule is that A′'s space *is* A's low 128: same opcode point, same
mnemonic, reachable with or without a qualifier depending on which tier is
encoded. So predication is decided entirely by where an operation sits in §4's
map.

**§4's map below 128 is now full.** O-34 packed it: 0–31 integer (26 of 32
used), 32–47 floating point at format codes `00`/`01`, 48–63 `dp4`/`dp8`, 64–127
conversions. The only free space below 128 is six integer points at 26–31 and
eight spare in `dp`'s range. Above 128: conversions vacated 128–255, and the SFU
sits at 256+.

**Length is decodable before the format tag.** §2: bits `[1:0]` give the length
(`00` = 32-bit, `11` = 48-bit) and are read before `[5:2]`'s format tag. That is
what lets tag `1111` carry a 32-bit C″ and a 48-bit H without ambiguity.

**Tag `0001` at 48 bits is unallocated.** §2's escape table gives 48-bit
renderings to tags `0011`–`0101` (B/B′/B″), `0111` (C′), `1000` (D), `1001`
(M′), `1011` (F48), `1101` (D′), `1110` (`pmov`) and `1111` (H). Tags `0000`,
`0001`, `0010`, `0110`, `1010` and `1100` have none. This matters because F-54
records that all sixteen **32-bit** tags are spoken for — the 48-bit space under
them is not.

---

## 2. The problem, measured

O-33 runs warp-uniform work on lane 0 under a reserved predicate and broadcasts
the result, which cuts lane-activations by about a third on an addressing-heavy
kernel. An instruction with no predicated form cannot participate: it runs in all
32 lanes however redundant it is.

Measured on a transpose kernel, after O-34 and F-58 removed the other causes,
exactly **one** instruction remains blocked for want of a predicated encoding:

```
    blocked: no A′ form     : 1     rcp.f32, §4 point 256
    blocked: 16-bit only    : 1     srd -- Format K, invariant 7, no fix wanted
    blocked: semantics      : 1     a barrier must not be masked
```

That `rcp.f32` is the head of the integer-division sequence, on a divisor that is
uniform across the warp. It costs 31 lane-activations per uniform division.

**One instruction is a thin basis for a format change, and this proposal does not
rest on it.** The general statement is that §4's entire extension space — 256–1023
for the SFU, 128–255 freed by O-34, and any future allocation — is permanently
unpredicable under the current encoding, and there is no longer anywhere below
128 to relocate anything to. That is a structural ceiling, reached, and `rcp` is
simply the first operation to hit it.

---

## 3. The encoding

Every field sits where invariant 8 puts it — `rd` at `[14:11]`, `rs0` at
`[18:15]`, `rs1` at `[22:19]`, `rs2` at `[26:23]`, the qualifier at `[29:27]`,
`opcode[4:0]` at `[10:6]` — so the first 32 bits are **bit-identical to a 32-bit
Format A′ instruction**, and the extension is entirely in the third halfword.

| Bits | Width | Field |
|---|---|---|
| `[1:0]` | 2 | length = `11` (48-bit) |
| `[5:2]` | 4 | fmt = `0001` (same tag as 32-bit A′) |
| `[10:6]` | 5 | `opcode[4:0]` |
| `[14:11]` | 4 | `rd` |
| `[18:15]` | 4 | `rs0` |
| `[22:19]` | 4 | `rs1` |
| `[26:23]` | 4 | `rs2` |
| `[29:27]` | 3 | **predicate qualifier** |
| `[31:30]` | 2 | `opcode[6:5]` |
| `[34:32]` | 3 | **`opcode[9:7]`** — the extension |
| `[47:35]` | 13 | reserved |

The decoder for the first 32 bits is unchanged; the opcode is a three-piece
splice instead of two. Register fields, which are on the rename path, do not
move.

**Variant worth considering.** Invariant 7 names a predicate *destination* as a
second thing that earns length. A″ has one but only a 5-bit opcode; A′ has a
qualifier but no destination. Spending two of the thirteen reserved bits on `pd`
at `[36:35]` would give a form carrying **a full 10-bit opcode, a qualifier and a
predicate destination at once** — a combination no existing tier can express.
Whether anything wants it is a question for the design track; the compiler has no
case for it today.

---

## 4. Costs

**Thirteen reserved bits.** This is the one place the proposal brushes against
invariant 7's "reserved bits in a long form where a short form exists are a bug,
not headroom." The reading offered here is that the sentence governs forms that
do not earn their length, and this one earns it by the same clause's own list.
Precedent: `pmov pd, #lanemask` is 48-bit with six reserved bits at `[15:10]` and
earns its length by carrying a 32-bit immediate.

If that reading is rejected, the fallback is §6.

**Six bytes instead of four**, and only on instructions that take the form. An
unpredicated `rcp` stays 32-bit. The compiler emits the long form only where
masking pays, which its cost model already decides per region.

**A third length class in the A-family decoder.** Formats A/A′/A″ are currently
32-bit only, so their decode path has no length dispatch at all. This adds one.

---

## 5. What it buys beyond `rcp`

- **The entire SFU range** (256+) becomes predicable: `rsqrt`, `sqrt`, `ex2`,
  `lg2`, `sin`, `cos`.
- **128–255**, freed by O-34, becomes usable for operations that want
  predication, removing the pressure that made §4's sub-128 packing necessary in
  the first place.
- **Future extension is no longer a one-way door.** Today, allocating an
  operation above 127 permanently forfeits its predicated form, which is a
  constraint on the opcode map that has already forced one relocation (O-34) and
  has no room to force another.

---

## 6. Alternatives, and why they are worse

**Relocate `rcp.f32` below 128.** Four bytes rather than six, and no new length
class. But the only homes are the six free integer points at 26–31 — which are
A″-reachable space, wasted on an operation with no status output — or `dp`'s
eight spare at 48–63, which puts an SFU point inside the packed-dot-product
block. It solves one instruction and leaves the ceiling where it is. If a second
SFU operation ever wants predication, the same argument runs again with less
room.

**Widen A′'s opcode by shrinking something else.** There is nothing to shrink.
Register fields are fixed by invariant 8, the qualifier is three bits by
definition, and A′ already spends its high bits on the qualifier.

**Accept it.** `rcp` runs in 32 lanes; the cost is 31 lane-activations per
warp-uniform division. Defensible today at one instruction. The reason to decide
now rather than later is that the ceiling is structural and §4 has no room left
to absorb the next case.

---

## 7. Questions for the ISA design track

1. **Does a 48-bit form with thirteen reserved bits satisfy invariant 7?** The
   argument here is that the qualifier is what earns the length and the reserved
   bits are a consequence of the 16-bit length granularity, with `pmov` as
   precedent. This is the decision the proposal turns on.
2. **Opcode bit placement.** `opcode[9:7]` at `[34:32]` keeps the low 32 bits
   bit-identical to 32-bit A′. Is a contiguous `opcode[9:5]` somewhere in the
   third halfword better for the decoder, at the cost of that identity?
3. **Include a predicate destination?** §3's variant. Two bits, and it yields a
   combination no current tier offers.
4. **Should the 48-bit form be defined for the whole A family** (a 48-bit A″ with
   a full opcode and a predicate destination), or only for A′? The compiler wants
   only A′.
