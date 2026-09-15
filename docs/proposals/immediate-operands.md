# Proposal — where an immediate goes when the destination is not a source

**Status:** three cases, three different answers. One is a real ask, one is weak
and recommended for deferral, one is **withdrawn on inspection** — the evidence
that prompted it did not survive checking.
**Addresses:** F-103, F-104 in `../roadmap.md`. Prompted by the first SASS
comparison (F-99).
**Touches:** §3 Format B, §4 points 0–31.

---

## 0. Summary and strength of ask

| | ask | strength | benchmark cost today |
|---|---|---|---|
| **1. Three-address reg-immediate ALU** (`andi`, `shri`, `srai`, …) | 7 opcode points in Format B (9 if the rule is applied whole) | **strong** | 3 instructions |
| **2. Three-source with an immediate** (`mad.lo rd, rs0, #imm, rs2`) | a field layout that does not exist | **weak — recommend deferring** | 1 instruction |
| **3. A hardwired zero register** | one of 16 GPRs | **withdrawn** | 0 — the evidence was wrong |

Separately, and needing **no ISA change at all**, three instructions come back
from compiler work against encoding the ISA already specifies (§5).

**This is a small ask in absolute terms** — 4 instructions across an eight-kernel
suite — and it is offered as encoding hygiene rather than as a performance case.
The reason to take it seriously is §2: the gap is structural, not incidental,
and it will widen as kernels get more arithmetic.

---

## 1. How this came up

`ptxas` turns out to be a host compiler that needs no GPU, so the SASS
comparison the project had deferred for four revisions is now measurable, and
`nvdisasm` reads the cubin. Against NVIDIA's machine encoding, build-for-build
with O-23 alignment on both sides:

| | CCV aligned | SASS sm_70 |
|---|---|---|
| instructions | 238 | 224 |
| bytes | — | 3584 |
| bits/instruction | 27.3 | 128.0 |

CCV is at **1.06× the instruction count** and roughly a quarter of the bytes.
The instruction gap is concentrated in the three arithmetic-heavy kernels at
five instructions each, and disassembly says where those five go.

**Two hypotheses were checked and rejected.** NVIDIA has **no integer divide**:
`transpose`'s runtime division in SASS is `I2F.U32.RP` → `MUFU.RCP` → `F2I` →
Newton via two `IMAD.HI.U32` → two `ISETP`/`IADD3` corrections, which is
O-31/O-35's algorithm step for step. And predicated control flow is not it
either — `@P0 EXIT`, `@!P2 LOP3` are all things Format A′ already provides.

What is left is immediates. **9 of the 19 `movi` in the whole benchmark exist
only to put a constant somewhere an instruction can reach it.** On `transpose`
that is 5, which is the entire 58-vs-53 gap.

---

## 2. The structural observation, which is the actual argument

CCV's **16-bit compressed** format carries eight register-immediate ALU
operations:

> `C_ADDI`, `C_SUBI`, `C_ANDI`, `C_ORI`, `C_XORI`, `C_SHLI`, `C_SHRI`, `C_SRAI`

CCV's **32-bit** register-immediate format carries **one**: `addi`. (Format B
also holds `packi`/`unpacki`, which are immediate-only and not ALU operations.)

Format K is two-address by construction — `rd = rd op #imm` — and its immediate
is `uimm4`. So an operation is encodable only when the destination *is* the
source **and** the constant is 0–15. Outside that box there is no
register-immediate form at all, and the compiler emits `movi` plus a reg-reg
operation.

```
    rd = rd & 15        one 16-bit instruction      (C_ANDI)
    rd = rs & 15        two 32-bit instructions     (movi + and)
    rd = rd >> 28       two 32-bit instructions     (28 > uimm4)
```

**Format B has a 5-bit opcode — 32 points — and four are used**: `addi` at 0
and `packi`/`packi.z`/`unpacki` at 20–22. The encoding space for the missing
forms is already reserved, already decoded, and empty.

That is the whole of case 1. It is not a new capability; it is the 32-bit
format catching up with the 16-bit one.

---

## 3. Case 1 — three-address register-immediate ALU. **Strong.**

### Proposed encoding

No new format, no new field, no change to any bit position. Format B's existing
layout carries all of it:

| Bits | Width | Field |
|---|---|---|
| `[1:0]` | 2 | length `00` |
| `[5:2]` | 4 | fmt `0011` |
| `[10:6]` | 5 | opcode |
| `[14:11]` | 4 | `rd` |
| `[18:15]` | 4 | `rs0` |
| `[31:19]` | 13 | immediate (`[26:19]` ++ `[29:27]` ++ `[31:30]`) |

### Proposed numbering rule

> **Format B point *n* is Format A point *n* with the second source replaced by
> the immediate.**

This is already true: `addi` is Format B point 0 and `add` is Format A point 0.
Stating it as a rule rather than a coincidence gives:

| pt | | pt | | pt | |
|---|---|---|---|---|---|
| 1 | `subi` | 9 | `xori` | 12 | `shri` |
| 2 | `muli` | 10 | `andni` | 13 | `srai` |
| 7 | `andi` | 11 | `shli` | | |
| 8 | `ori` | | | | |

Seven points cover the measured need (`andi`, `ori`, `xori`, `shli`, `shri`,
`srai`, `subi`); `muli` and `andni` are the same rule applied and cost nothing
extra to specify. Format B uses 4 of 32 points today; all nine would take it to
13, leaving **19 free**.

### One wrinkle the rule has to state

`packi`/`unpacki` already sit at Format B points 20–22, where the rule would put
`abs`/`neg`/`popc`. Those are **unary** — they have no second source to replace —
so the rule is well-formed as:

> Where Format A point *n* names a binary operation, Format B point *n* is that
> operation with the second source replaced by an immediate. Points whose
> Format A operation is unary carry no immediate form and are free for
> immediate-only operations.

That is consistent with O-28's "numbering is normative" and adds no table to
remember: the Format B map becomes a projection of §4's, which a decoder can
share.

### Justification

- **Measured:** 3 instructions in the benchmark today, all in `transpose`
  (`sra rd, rs, #31`, `shr rd, rs, #28`, `and rd, rs, #15`). Each is destination
  ≠ source, immediate > 15, or both.
- **Structural:** the asymmetry between the 16-bit and 32-bit formats is
  arbitrary rather than designed, and it penalises exactly the code that does
  not fit the compressed form — which is the code that matters as kernels grow.
- **Cheap:** 7 of 29 free points, no field moves, no new decode path, invariant 8
  untouched. The 48-bit sibling comes free under the existing rule.
- **Symmetric with what exists:** `addi` already demonstrates the shape.

### Strength: **strong.** Low cost, reserved space, and it removes an asymmetry
rather than adding a feature.

---

## 4. Case 2 — three-source with an immediate. **Weak; recommend deferring.**

SASS writes `IMAD R11, R5, 0x44, R9` — `rd = rs0 × imm + rs2` — where CCV needs
`movi` plus `mad.lo`.

### Why there is no clean encoding

Format A's four register fields occupy `[14:11]`, `[18:15]`, `[22:19]`,
`[26:23]`, with the opcode split across `[10:6]` and `[31:27]`. There is no
13-bit hole. The options are all bad:

| Option | Problem |
|---|---|
| New format tag | all 16 tags are allocated; this needs one of them |
| Shrink Format B's immediate and add `rs1` at `[22:19]` | the immediate would start at `[23]` in this opcode and `[19]` in every other Format B opcode — a field whose position depends on the opcode, which is exactly what invariant 8 forbids |
| Use the 48-bit A′ long form | O-37 spent that halfword on opcode extension; reopening it re-litigates a settled decision |
| A 48-bit Format B sibling with `rs1` in the high halfword | works, but costs 48 bits to save one 32-bit `movi` — no gain |

### Justification for deferring

It is worth **one instruction** in the current benchmark, against an encoding
cost that is either a format tag or an invariant-8 exception. The asymmetry
argument that carries case 1 does not apply here: no format of any length
provides this today, so nothing is "catching up".

**Recommend recording it and revisiting if a kernel with heavy strided
addressing moves the number.** `sgemm` at larger tiles is the likely candidate
and has not been examined for this.

### Strength: **weak.** Real but small, and no cheap encoding exists.

---

## 5. Case 3 — the zero register. **Withdrawn.**

The first pass through this data reported **5 `movi rX, 0` that a hardwired zero
register would remove**, and that number was wrong. Checking what each one
actually feeds:

| where | feeds | verdict |
|---|---|---|
| `dot`, `reduce` | `setp.eq p0, r2, r3` | **Format C′ already has the immediate compare.** `SETP_EQ_I` is defined and generated — a *selection* gap |
| `dot`, `reduce` | loop accumulator (`sum = 0`) | **not removable.** The accumulator needs a writable register initialised to zero; `mov rd, RZ` costs the same instruction |
| `transpose` | `mad.lo r5, r3, r4, r2` | **§4 point 2 is `mul.lo`.** A three-address multiply is already specified; the backend never defined it — a *compiler* gap |

So of five, **two are compiler bugs against existing encoding, two are
accumulators a zero register would not help, and one is a missing instruction
definition.** None is an argument for spending a GPR.

And the cost would be real. The register file is 16 (§1), the backend already
reserves R15 for the frame pointer under O-30's `.local` window scheme, and a
hardwired zero would leave **14** general registers — on a machine whose spill
behaviour is measured in §3 of `../benchmarks.md` and whose register count is an
open question (O-25, F-12).

**Recommend: no.** Recorded here so the next person who notices the `movi rX, 0`
pattern finds the analysis rather than repeating it.

---

## 6. What needs no ISA change

Three instructions come back from compiler work alone, against encoding the ISA
already specifies:

1. **Define `mul.lo` at §4 point 2.** The ISA allocates it; `CCVInstrInfo.td`
   has `C_MUL_LO` (compressed, two-address) and `MADLO` (three-source) but no
   plain three-address multiply, so every `a * b` with a distinct destination
   becomes `movi rZ, 0` + `mad.lo`. One `def`.
2. **Select the immediate compare.** `SETP_EQ_I` and its siblings exist and are
   generated; ISel is materialising the constant instead. Two instructions.
3. **Select `C_ANDI`/`C_SHRI` where they fit.** Some of the `movi` pairs are
   within the two-address, `uimm4` box and were not matched.

These are tracked as compiler findings and need no decision from the ISA side.

---

## 7. Two observations that are not asks

**The uniform register file is real and NVIDIA has it.** The SASS carries
`S2UR UR4, SR_CTAID.X` — the CTA index in one register for the whole warp, not
32 copies — `ULDC` to load constants into it, and ordinary vector instructions
taking `UR` operands beside vector ones (`IMAD R9, R9, UR4, R0`). That is what
O-25 argued from register-file size and F-52 from redundant execution, shipping
in the compatibility target. **O-33's lane-0 masking is this project's software
approximation of it** — `transpose` spends three `shfl.idx` broadcasts
recovering what a uniform register supplies free — which reframes the masking
work as a workaround rather than an optimisation. See F-106; no proposal here,
but the case is stronger than it was.

**CCV's addressing mode already beats SASS.** `ld.global r2, [r2, r1, 1, 0]`
computes `base + index × scale` **and** loads in one instruction. Every memory
access in the SASS listings is two — `IMAD.WIDE.U32` then `LDG.E` — because a
64-bit address has to be materialised in a register pair first, which is
precisely what invariant 11 exists to avoid. This is why CCV is *ahead* of SASS
on `vadd` (16 against 17) and `vadd_loop` (19 against 20), and it is worth
stating in the positive: the windowed address model is not only a density
choice, it removes an instruction per memory access.

---

## 8. What the ISA side is being asked to decide

1. **Case 1 — adopt, modify or reject** the Format B projection rule and its
   seven points. This is the only substantive ask.
2. **Case 2 — confirm deferral**, or say which of the four bad options is least
   bad if the answer is that it should be solved now.
3. **Case 3 — confirm withdrawal**, so the `movi rX, 0` pattern is not
   re-proposed.

Everything in §6 proceeds regardless.
