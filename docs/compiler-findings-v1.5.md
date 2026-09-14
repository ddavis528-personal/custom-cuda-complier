# Compiler-side findings — the v1.5 review

**Covers:** everything since the v1.4 review — Steps 4, 5 and the part of Step 6
done so far. Written for the architecture side, so it is organised by what the
compiler work found about the ISA, not by what was built.

**Current spec:** `isa-v1.5-operation-map-and-encoding.md`. The previous report
is [`compiler-findings-v1.4.md`](compiler-findings-v1.4.md).

---

## 1. One thing to carry into RTL, and it is not optional

O-33 makes the compiler emit code whose entire value rests on a hardware
property that does not exist yet:

> **A predicated-off lane must not toggle its ALU operands, its register-file
> write port, or its result bus.**

The pass finds warp-uniform work — values every lane computes identically — masks
it to lane 0 with a reserved predicate, and broadcasts the result with a
`shfl.idx` under the negated mask. On `transpose` that turns 2304 lane
activations into 1809 — a 21.5% cut — at a cost of 128 extra issued lane slots,
four broadcast instructions across 32 lanes.

If the RTL gates only the *write* and still drives operands into the ALU, the
saving is zero and the 128 extra slots are pure loss. Nothing in the
compiler can detect that; the number in `docs/benchmarks.md` would simply be
wrong. This is the one finding in this report that constrains the design rather
than describing it.

## 2. The encoding limit that matters most is not the one we expected

O-33 needs the predicate qualifier field at `[29:27]` to carry its lane mask.
Measuring what it could not reach, on `transpose`:

| blocked because | count | fixable? |
|---|---|---|
| `sel` reads `[29:27]` as its selector (§4 point 19) | **10** | not cheaply — a second predicate field is 2 bits the format does not have |
| conversions at 128+ and SFU at 256+ are Format A only | 3 | yes — relocate into the 64–127 hole |
| `srd` is Format K only (invariant 7) | 1 | no, and correctly so |
| a barrier must not be masked | 1 | no — semantics |

The general statement behind the first row: **a value already predicated for
control flow cannot also be masked to lane 0.** Ordinary predication and O-33
want the same three bits. Those ten instructions are the division sequence's own
correction steps (`q += ge`, `rem -= ge*d`), so the two blockers are the same
code.

Recorded as F-58. It has no obvious encoding fix and it is larger than F-56,
which is the one we went looking for.

## 3. The warp-uniform register file now has a measured case, not an argued one

§1 named a warp-uniform file as the fallback if GEMM register pressure came back
bad. The pressure data did not force it; **redundant execution did.**

`ccg-llc -ccg-uniformity-stats` reports, per kernel, the share of instructions
that are warp-uniform and the peak number of uniform values simultaneously live:

| kernel | warp-uniform | peak uniform live |
|---|---|---|
| vadd | 68% | 5 |
| saxpy | 60% | 5 |
| dot | 62% | 7 |
| reduce | 61% | 6 |
| transpose | 79% | 10 |

**Peak live is 5–10, against the 16-entry file §1 guessed at.** That is the
number the guess was missing. A uniform file of 8 would hold every kernel here
except `transpose`, which is the kernel with two divisions in it.

O-33 is the cheap half of this — it removes the *energy* of redundant execution
without removing the *issue slots*. A scalar unit removes both. The remaining
gap against AMDGCN on `transpose` (76 issued against 64) is entirely that: their
compiler puts the uniform division on `s_mul_i32`/`s_sub_i32`/`s_cselect_b32`,
one instruction for the whole wavefront.

The uniform-operand encoding bit (option C in `proposals/warp-uniform.md`)
remains undecided and is the cheaper of the two shapes. F-52.

## 4. Where the opcode map is now tight

**All sixteen 32-bit format tags are allocated.** O-32 took the last one for
Format C″. A future format needs either a sub-encoding inside an existing tag —
as `bar.wait.phase` did with a Format E opcode point — or a 48-bit-only home.
Worth knowing before the next format is proposed. F-54.

**Format A's map is not tight, contrary to a claim this report's first draft
made.** 64–127 is reserved for packed dot-product and holds 8 points of 64;
0–31 has 6 free. That is ~62 free points reachable from A′, which is where a
predicated conversion would have to live. The relocation F-56 wants is
affordable.

**But §4's conversion scheme has no encoding for an integer source.** It reads
`base × 4 source-format codes × 4 rounding modes`, where the source-format code
is the 2-bit *FP* format. `cvt.f32.u32` — the one integer division needs — has
no slot in it, while `CCGInstrInfo.td` assigns it point 128 anyway. This has to
be settled before anything is relocated. F-59.

## 5. Two decisions the compiler forced

**O-31 — conversions and the SFU got their first points because division needed
them.** §4 had reserved both ranges and left them empty. One `udiv` was 97
dynamic instructions per thread as a shift-subtract loop; as a float-reciprocal
sequence it is 32, straight-line. `transpose` fell from 143 static instructions
to 83.

The one detail worth carrying: the reciprocal is scaled by `0x4F7FFFFE`, which
is 2³²(1−2⁻²³), **not** 2³². The Newton step converges only from below, and
`rcp` can be an ulp high; scaling by exactly 2³² makes `e·d` wrap and the
correction term explode. AMD's sequence carries the same odd constant for the
same reason. Exactness is checked against integer division over the edge cases
and a large sample rather than argued.

**O-32 — the compare family got its unpredicated encoding.** §1's own rule is
that every predicated operation needs a distinct unpredicated encoding, which is
why A/A′/A″ and D/D′ exist. Compares were the exception: they had spent both
tags on reg-reg versus reg-imm, so every compare carried a mandatory qualifier
and a kernel had to manufacture a true predicate to open with. That cost 13% of
dynamically issued instructions in the reduction kernels. Format C″ at tag
`1111` removed it; one tag covers both operand shapes because dropping the
qualifier frees three bits.

## 6. Density holds, and the instruction-count control holds with it

Measured, not cited — `tools/bench.py`, full tables and caveats in
`docs/benchmarks.md`:

| | vadd | saxpy | dot | reduce | transpose |
|---|---|---|---|---|---|
| CCG bits/instr | 27.1 | 26.9 | 26.0 | 26.0 | 30.1 |
| AMDGCN gfx900 | 41.9 | 43.5 | 40.0 | 39.7 | 38.5 |
| CCG instructions | 23 | 22 | 56 | 51 | 84 |
| AMDGCN instructions | 29 | 25 | 60 | 54 | 64 |

**Roughly 0.65× the bits per instruction of a real contemporary GPU ISA, at
comparable instruction counts.** Under GEMM register pressure it holds at
26.4–28.1 across a 6.5× range of kernel size.

Two caveats stated plainly because they limit the claim: SASS is the comparison
that would matter most and is not here (no `ptxas` in this environment; the
128-bits-per-instruction figure in §6 of the spec is **carried from the design
discussion and unverified**). And PTX is a virtual ISA, so its column is task
complexity, never density.

`transpose` is now *above* GCN on code size — 316 bytes against 308 — because
O-33's broadcasts cost instructions. That is the trade in §1 of this report,
taken knowingly.

## 7. What is now mechanically checked

Every green check in this project that turned out to be green because it was not
looking became a checker. The list is longer than it was at v1.4, and every
addition has a specific failure behind it:

| Check | The failure that created it |
|---|---|
| `check-spec-vs-codegen.py` | §5.5 and §5.6 were hand-written and had drifted from the compiler |
| `!test/**` in `.gitignore` | every `.ll` regression case was silently untracked; a fresh clone had no suite |
| `gen-dag-isel` in the gate | two `.td` files were missing from CMake `DEPENDS`, so pattern edits reused stale tables |
| round trip compares immediates | it had been comparing opcodes only |
| `check-mask.sh` fails if nothing was masked | the masking test passed with the pass doing nothing |
| `check-uniformity-buckets.sh` | a `default: return false` printed unrelated instructions under an encoding-limit label, and F-56 was sized off the total |
| `check-bench-doc.py` | four stale figures in `docs/benchmarks.md`, one contradicting its own table |

Current state: 13376/13376 round trips clean across 209 instructions, 0
invariant-8 deviations, all listings match codegen, all simulator tests pass.

## 8. Open questions for the architecture side

1. **Lane gating** (§1 above). The one that blocks nothing today and invalidates
   a measured result if it goes the wrong way.
2. **F-58** — is a second predicate field worth a format change, or does the
   warp-uniform file make the question moot? These are alternatives, not
   complements.
3. **F-59** — how are integer-source conversions encoded? Blocks F-56.
4. **Predicate count (4)** — still provisional per §11. Measured pressure is 1–2
   of 4 across every kernel written, which is what made O-33's unconditional
   reservation of P3 affordable. If a fifth predicate were ever wanted, O-33 is
   the first thing that would want it.
5. **O-12's barrier phase parity** — unchanged since 1.2 and still the one open
   item that depends on a document the compiler side does not have. O-27 added
   `bar.wait.phase` on the assumption; F-35 notes that CUDA C produces nothing
   that selects it, so it is encodable and untested by real code.
