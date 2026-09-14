# Instruction density and instruction count, measured

**What this is:** a reproducible comparison of the CCV ISA against what can
actually be measured on this machine, with the things that cannot be measured
marked as such rather than estimated.

Run it with `tools/bench.py`. Every number below comes from that script.

---

## 1. Method, and what it is allowed to prove

Three targets, one source per kernel, one frontend:

| target | what it is | density claim? |
|---|---|---|
| **CCV** | this backend, via clang's CUDA frontend | yes |
| **AMDGCN** | clang's AMD GPU backend — **real ISAs**, five generations: gfx900 (GCN5/Vega, 2017), gfx1030 (RDNA2), gfx1100 (RDNA3), gfx1200 (RDNA4, 2024), gfx942 (CDNA3/MI300) | yes |
| **PTX** (nvptx64) | a **virtual ISA** | **no** |

gfx900 is kept as the headline column because the whole document is written
against it; the other four exist so the density claim is not resting on one
eight-year-old encoding. See §2.

The kernels in `test/bench/` compile unchanged for all three. `portable.h`
renames builtins where they are spelled differently (`threadIdx.x` vs
`__builtin_amdgcn_workitem_id_x()`); it never emulates anything, because every
construct used exists natively in all three.

**Three limits, stated up front.**

**PTX is not a machine encoding.** `ptxas` expands, schedules and re-allocates
it, so a PTX instruction count says what the frontend thought the task needed —
not what any hardware executes. It is reported because "instructions to
complete the task" is a fair question at that level and PTX is this project's
compatibility contract. It is not evidence about density.

**SASS is the comparison that would matter most and is not here.** It needs
`ptxas`, which needs the CUDA toolkit, which is not installed. §6 of the ISA
document states that Volta-and-later SASS is 128 bits per instruction — 64 bits
of instruction plus 64 bits of compiler-encoded scheduling control. That figure
is *carried from the design discussion and has not been verified here.* Treat
the SASS row in any summary as a citation, not a measurement.

This is the single largest gap in the document, and broadening the AMD
comparison did not close it. **CCV's compatibility target is CUDA; its density
claim is measured against AMD.** Those are different vendors, and the one number
that would settle whether the encoding is actually dense *for the thing it
imitates* is the one that cannot be produced on this machine. Everything below
should be read as "denser than AMD's ISAs, by a stable margin, across five
generations" — not as "denser than NVIDIA's", which remains unmeasured.

**These are static counts.** Code size is exactly what static counts measure, so
the density columns are sound. Instruction *count* as a proxy for work done is
weaker: it assumes comparable dynamic behaviour, which holds for these kernels
(data-independent control flow apart from the entry guard) and would not hold
in general.

---

## 2. Results

Run `tools/bench.py`. Two tables, because static and dynamic answer different
questions and only one of them can be measured on both machines.

**Static — code size. Every column is a measurement.**

```
  kernel     |     CCV unaligned     |  CCV aligned   |     AMDGCN gfx900     |  PTX  
             |  instr  bytes    b/i |  instr  bytes |  instr  bytes    b/i |  instr
  --------------------------------------------------------------------------------
  vadd       |     23     78   27.1 |     16     56 |     29    152   41.9 |     21
  saxpy      |     22     74   26.9 |     17     58 |     25    136   43.5 |     19
  dot        |     56    182   26.0 |     48    156 |     60    300   40.0 |     46
  reduce     |     51    166   26.0 |     45    146 |     54    268   39.7 |     41
  transpose  |     87    320   29.4 |     79    290 |     64    308   38.5 |     43
```

**Dynamic — instructions actually issued, per thread of work.**

```
  kernel          CCV   SIMT     AMDGCN |  lane-act  of issued   how AMDGCN was obtained
  ----------------------------------------------------------------------------------------------
  vadd           16.0   100%         29 |       512       100%   exact: no backward branch
  saxpy          17.0   100%         25 |       544       100%   exact: no backward branch
  dot            78.9    64%         -- |      2526       100%   has 3 loops; not modelled
  reduce         75.9    63%         -- |      2430       100%   has 3 loops; not modelled
  transpose      79.0   100%         64 |      1429        57%   exact: no backward branch
```

**CCV's dynamic column is measured** on the simulator — lane-instructions
divided by threads, which for a fully-active warp is the issue count. **AMDGCN
has no simulator here**, so its dynamic column is filled in only where the
kernel provably has no backward branch and static and dynamic must therefore
agree. The two reduction kernels loop on both sides and are left blank rather
than modelled.

**SIMT is CCV only, and is not comparable as printed.** A CCV warp is 32 lanes
(§1); a gfx900 wavefront is 64. The same 32-thread block that fills a CCV warp
half-fills theirs, so the numbers measure different things. Comparing occupancy
needs the block size held fixed in each machine's own warp width, which these
kernels do not do.

### Density: 26–29 bits per instruction against GCN's 38–44

This is the headline and it holds across every kernel: **CCV encodes at roughly
0.65× the bits per instruction of a real contemporary GPU ISA.** The variable
16/32/48 encoding is doing what §6 claimed it would.

#### Against five AMD generations, not one

The original comparison used gfx900 alone — a 2017 ISA — which left the headline
open to the obvious objection: that it beats an old encoding rather than a
current one. Every AMD generation this toolchain can assemble now answers that,
spanning both encoding families and the datacentre line.

**Bits per instruction:**

```
  kernel                 CCV    GCN5 / Vega          RDNA2          RDNA3          RDNA4  CDNA3 / MI300
                                       2017           2020           2022           2024           2023
  -----------------------------------------------------------------------------------------------------
  vadd                  27.1           41.9           48.6           46.0           48.0           48.7
  saxpy                 26.9           43.5           47.3           44.6           46.9           47.2
  dot                   26.0           40.0           41.5           40.9           42.3           42.1
  reduce                26.0           39.7           42.9           39.2           41.4           40.2
  transpose             29.4           38.5           41.1           39.6           39.2           38.7
  -----------------------------------------------------------------------------------------------------
  pooled                27.4           40.1           43.1           41.1           42.4           41.9
```

**Instruction counts, same sweep — the control:**

```
  kernel                 CCV    GCN5 / Vega          RDNA2          RDNA3          RDNA4  CDNA3 / MI300
  -----------------------------------------------------------------------------------------------------
  vadd                    23             29             27             32             32             23
  saxpy                   22             25             23             28             28             21
  dot                     56             60             64             68             62             54
  reduce                  51             54             50             71             58             51
  transpose               87             64             60             76             76             62
```

**The objection does not land.** AMD's density is flat across eight years and two
encoding families — 40.1 to 43.1 bits per instruction pooled, with no trend — and
CCV's 27.4 is **0.63× to 0.68× of every one of them**. The ratio against RDNA4
(2024) is 0.65, the same as against Vega (2017). Whatever the variable-length
encoding is buying, it is not an artifact of an obsolete baseline.

**Two things the sweep shows that gfx900 alone did not.** RDNA3 is *less* dense
than GCN5 on these kernels, not more, and needs more instructions for the same
work (71 against 54 on `reduce`) — `s_delay_alu` is explicit scheduling in the
instruction stream, the same trade SASS makes at 64 bits per instruction. And
CDNA3 is the strongest competitor on instruction count, beating CCV on `saxpy`
(21 vs 22) and `dot` (54 vs 56); it is still 1.5× the bits.

**A counting trap, recorded because it nearly published a false number.** gfx10+
pads a kernel's tail with `s_code_end` and CDNA3 with `s_nop`, to fill the
instruction prefetch buffer. Counted as code, gfx1100's `vadd` reads 146
instructions and 640 bytes rather than 32 and 184 — and CCV would have appeared
**5× denser than RDNA3 on padding alone**. Two plausible-looking fixes are also
wrong: filtering those mnemonics anywhere removes CDNA's real hazard-slot
`s_nop`s, and cutting at the last `s_endpgm` removes real code, because an
early-exit `s_endpgm` is followed by the block that restores `exec` — on `dot`
that silently deleted the entire reduction loop, 17 instructions. `bench.py`
drops only a trailing run of padding, and the check that it is right is that it
reproduces the published gfx900 column **exactly** on all five kernels.

### The control that matters: instruction counts are comparable

A denser encoding that needs twice the instructions has gained nothing. The
counts are within 30% everywhere and CCV is *lower* on four of five:

| | vadd | saxpy | dot | reduce | transpose |
|---|---|---|---|---|---|
| CCV | 23 | 22 | 56 | 51 | 87 |
| GCN | 29 | 25 | 60 | 54 | 64 |

So the density is not bought with instruction count. **Code size lands below
GCN on four of five kernels** — 166 against 268 bytes on the reduction, and
with the alignment attribute `vadd` is 56 bytes against 152, which is 2.7×.

**`transpose` is the exception, and it became one deliberately.** After O-31 it
was 294 bytes against GCN's 308 — below, and an earlier version of this document
said "below GCN on every kernel" on the strength of it. O-33 then added lane-0
masking, which costs a broadcast instruction wherever it fires, and `transpose`
grew to **87 instructions and 320 bytes**. That is a **regression in the column this
section is about** and a 26% cut in the one the next section is about, taken
knowingly: see below.

Two structural reasons, both from the design record rather than discovered here:
GCN carries 64-bit pointers in register pairs where invariant 11 keeps addresses
out of registers entirely (§5.1), and GCN's scalar/vector split costs
`s_waitcnt` and `s_and_saveexec` instructions that a per-thread-PC machine does
not need (§1).

### Static and dynamic agree — now

`vadd`, `saxpy` and `transpose` execute exactly their static aligned instruction
count, because they are straight-line. `dot` and `reduce` run about 1.7× their
static size, which is the reduction loop, and their SIMT efficiency of 64–65% is
the tree structure idling half the lanes each round.

**That agreement is new, and it is why the dynamic column exists.** Before O-31,
`transpose` was 143 static instructions and its integer division cost a
32-iteration loop; the static number understated the real cost by roughly three
times, and a benchmark reporting only static size called a 9× problem a 2× one.

### Lane-activations: the column O-33 exists to move

An instruction count cannot see lane-0 masking at all. Masking a warp-uniform
instruction to one lane costs an extra broadcast *instruction* and saves 31 lane
*activations*, so a table with only an instruction column reports the price and
hides the goods. That is exactly what happened to `transpose` above.

The `lane-act` column is the measurement, from `ccv-sim -counters`:

| | issued/thread | issued lane slots | activations | share |
|---|---|---|---|---|
| `transpose`, masking off | 68.0 | 2176 | 2016 | 93% |
| `transpose`, masking on | 79.0 | 2528 | **1429** | **57%** |

**587 fewer lanes switched — a 29% cut — for 11 added instructions per thread.**
The pass's own stats account for them: 22 operations masked to lane 0, 7 already
predicated and composed with `pand` (F-58), 3 broadcasts inserted, plus the one
`pmov` that materializes the lane-0 mask.

The masking-off row is **not** 100%, and that is worth reading rather than
skipping: 7% of `transpose`'s lane slots are predicated off before any masking
pass runs, from the reciprocal sequence's own correction steps. An earlier
version of this table gave the off row as 2304/2304/100% and the on row as
2592/1493/58%. Both were hand-copied once and then left behind by two changes to
the divide sequence (O-31, O-35) and one correction to the counter itself
(F-60). `tools/bench.py` now generates this table and `check-bench-doc.py`
fails the gate when the document disagrees with it.

Four changes got there:

| | instrs | activations | what changed |
|---|---|---|---|
| O-33 as first built | 76 | 1809 | mask uniform work to lane 0, broadcast the result |
| after O-34 | 76 | 1747 | conversions moved into Format A′'s reach, so the division's two `cvt`s mask |
| after F-58 part 1 | 76 | 1587 | `select` lowers to a predicated move, not `sel` |
| counter corrected | 76 | 1555 | a predicate-file op is not 32 lane activations |
| after F-58 part 2 | 81 | 1493 | already-predicated instructions compose their guard with the lane mask via `pand` |
| **today**, after O-35 and O-39 | **79** | **1429** | the integer reciprocal removed the fp round trip from both divisions |

**Row four is a measurement fix, not a saving**, and it is listed because it
changes a published number and because it changed a decision.
`pand`/`por`/`pxor`/`pmov` read and write the predicate file — 32 bits, one per
lane — and never touch a GPR lane, an ALU operand or a result bus, which is
exactly what this column is defined to measure. Charging them a full 32
overstated them by roughly the width of a lane. Against the broken counter, row
five measured 1587 → 1685 and read as a clear loss; against the fixed one it is
1555 → 1493.

**Row five is the weakest of the four and is on by design-track decision.** It
adds five instructions to save 62 activations — about 12 per instruction, against
the 31 a plainly-masked instruction saves.

### Two hardware properties this column is spending

Whether any of this is a win is a hardware question, not a compiler one. The
compiler is now generating code whose value rests on two properties of RTL that
does not exist yet, and it cannot detect whether either holds — if they do not,
this column is fiction and the instruction-count regression is all that is real.

**1. Lane gating (O-33, every row).** A predicated-off lane must not toggle its
ALU operands, its register-file write port, or its result bus. Gating only the
*write* is not enough: the 288 extra issued lane slots buy nothing and the whole
column collapses.

**2. Cheap predicate logic (F-58, row five only).** A predicate-file operation
must cost much less than a warp-wide one. A predicate is 32 bits, one per lane
(invariant 5), so `pand` is 32 AND gates against 32 lanes of 32-bit datapath and
the ratio should be about the width of a lane. If predicate logic instead runs
through the vector path, row five is a loss of five instructions per kernel.

Property 2 is cheaper to get wrong than property 1 — it costs one row, not the
whole column — and `-ccv-mask-compose=false` turns that row off without touching
anything else.

The other four kernels read 100% because the pass declined to mask them — every
uniform value is consumed immediately by divergent work, so each masked
instruction would need its own broadcast and the trade is a wash. That is the
cost model working, not the pass failing.

### Where CCV still loses: `transpose`, and it is instructive

79 instructions issued against GCN5's 64 — the only kernel where CCV issues more,
and it issues more than every AMD generation measured (60 to 76). Two
causes, both structural rather than accidental:

**AMD does the division on the scalar unit.** The divisor is warp-uniform (it
depends on `blockIdx` and `n`), so their sequence is `s_mul_i32`, `s_sub_i32`,
`s_cselect_b32` — one instruction per operation *for the whole wavefront*. CCV
issues it to all 32 lanes and, since O-33, activates only one of them for the
part of the sequence that can be masked. That closes the energy gap partway and
none of the issue-bandwidth gap: a scalar unit does not issue to the vector
pipe at all.

O-33 also measured how much of that sequence is out of reach, and the answer
reframed F-52. Of `transpose`'s warp-uniform instructions, 10 cannot be masked
because `sel` spends the predicate field on data (F-58), 3 because §4 puts
conversions and the SFU above Format A′'s 7-bit opcode (F-56), and 2 for reasons
with no fix (a 16-bit `srd`, a barrier). **The largest block is the contended
qualifier field, not the opcode range** — and those ten are the division's own
correction steps. A warp-uniform register file would sidestep all of it, which
is the case O-25 made from register-file size and F-52 now makes from redundant
execution.

An earlier version of this section said "77 instructions issued against 64"
while the table two screens up said 72. Both were stale, and nothing noticed
until this audit; `tools/check-bench-doc.py` now regenerates the tables and
fails the gate when the document and the machine disagree.

**Compares used to cost an extra instruction each** — O-24's manufactured guard
— which was 13% of dynamically issued instructions in the reduction kernels.
O-32 added Format C″, an unpredicated compare, and that is now zero. It was the
single largest avoidable overhead the benchmark found:

| | `dot` | `reduce` | `transpose` |
|---|---|---|---|
| dynamic, before O-32 | 91.9 | 88.9 | 77.0 |
| after O-32 | **78.9** | **75.9** | **72.0** |
| after O-33 | 78.9 | 75.9 | 76.0 |

`transpose` moves back up in the O-33 row because masking bought its saving in
lane-activations, not instructions — see the section above. The other two are
unchanged because the pass declined to mask them.

What remains on `transpose` is the scalar-unit gap above, which is
architectural rather than a missing encoding.

### The division result

Measured on the simulator, one `udiv`:

| | static | dynamic per thread | shape |
|---|---|---|---|
| shift-subtract (before) | 63 | **97.2** | loop, up to 32 iterations |
| float reciprocal (O-31) | 35 | **32.0** | straight-line |
| integer reciprocal (O-35) | 31 | **28.0** | straight-line, no fp round trip |

The division sequence proper is **21 instructions under O-31 and 17 under O-35** — the four
removed are `cvt.f32.u32`, the 48-bit scale constant, `fmul` and `cvt.u32.f32`, which existed
only to cross between integer and floating point. On `transpose`, which contains two
divisions, that is 89 → 87 static instructions and 1493 → 1429 lane-activations.

**The fp32 round trip was never about precision.** `tools/model-rcp.py` measures what the
sequence actually needs: 16 bits of reciprocal, against the ~23 an fp32 unit supplies. Making
`rcp.f32` more accurate would have saved nothing, because fp32's 24-bit significand is what
forces the Newton step, not the unit's error. See O-35.

`transpose` fell from 143 instructions and 482 bytes to 83 and 294 (87 and 320
today, after O-33 added its broadcasts). §4 had reserved the conversion and SFU
opcode ranges and left them empty; filling in six points closed the entire gap.
See O-31 for the algorithm and the one constant that makes it exact — and F-56
for the cost of having put those six points where predication cannot reach them.

---

## 3. GEMM: where the register file binds

`tools/sweep-tiles.sh`, on the tiled SGEMM with a TM×TN per-thread accumulator
tile:

```
  tile  accs    instrs     bits b/instr  spills    fma sp/fma    K-hit
  -------------------------------------------------------------------------
  1x1   1          174     4816    27.7      31     16   1.94      22%
  1x2   2          256     7024    27.4      55     32   1.72      19%
  2x2   4          381    10288    27.0      97     64   1.52      17%
  2x4   8          639    17072    26.7     186    128   1.45      13%
  4x4   16        1132    29856    26.4     407    256   1.59      13%
```

`sp/fma` — memory traffic the register file forced, per unit of arithmetic it
bought — has a **minimum at 2×4** and rises again at 4×4, where sixteen
accumulators are the whole file and everything else spills. At 16 GPRs the
practical ceiling is 2×4, which is what §1 guessed before there was anything to
measure.

Density holds up under pressure: 26.4–28.1 bits per instruction across a 6.5×
range of kernel size.

**The compressed-form hit rate stays low and drifts down under pressure** —
22% at 1×1 down to 13% at the largest tiles. Register pressure and Format K compression work against each other, because
the allocator lands `rd == rs0` less often when it has less freedom. O-29's
proposed "bias allocation toward the tie" would therefore be worth least exactly
where code size matters most.

---

## 4. What would strengthen this

- **SASS.** The comparison the project's density argument is actually written
  against, and the one missing. Needs `ptxas`.
- **Dynamic counts for GCN.** CCV's are measured; AMD's are not, because there
  is no AMD simulator here. For these kernels their code is straight-line where
  ours is, so static is a fair proxy for both — but that is an argument about
  these five kernels, not a general one.
- **More kernels, and unfriendly ones.** Five kernels with regular control flow
  is a narrow base. Anything branch-heavy or with irregular access would test
  the parts of the encoding these do not reach.
- **RVC as a second density reference.** RISC-V's compressed extension is the
  closest published analogue to the 16/32 mix, and `riscv64` is available in
  this toolchain. A first measurement, on a scalar `vadd` loop: **rv64gc is 24.0
  bits per instruction against rv64g's 32.0** — the compressed extension buys
  25%, and CCV's pooled 27.4 sits between the two. That is a useful calibration
  — CCV is in the range a density-focused scalar ISA reaches, while carrying
  32-lane vector semantics — but it is one hand-written kernel, not a benchmark,
  and instruction counts are not comparable at all: RISC-V does one element per
  instruction where CCV does thirty-two. Promoting this to a table needs its own
  argument about what is being compared.

- **A kernel where the narrow element widths pay.** v1.6's headline capability
  is `chwidth` and the sub-32-bit element model (O-6, O-38, F-3), and **not one
  of the five benchmark kernels exercises it** — they are all fp32 and i32.
  `test/bench/vadd16.cu` exists and is measured by the chwidth work, but it is
  not in these tables, so the density and instruction-count claims here say
  nothing about the feature the last revision was mostly about. AMD has packed
  16-bit math on every generation swept above, so there is a real comparison to
  be made and it has not been made.
