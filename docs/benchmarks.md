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
| **AMDGCN** (gfx900) | clang's AMD GPU backend — a **real ISA** | yes |
| **PTX** (nvptx64) | a **virtual ISA** | **no** |

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

### The control that matters: instruction counts are comparable

A denser encoding that needs twice the instructions has gained nothing. The
counts are within 30% everywhere and CCV is *lower* on four of five:

| | vadd | saxpy | dot | reduce | transpose |
|---|---|---|---|---|---|
| CCV | 23 | 22 | 56 | 51 | 84 |
| GCN | 29 | 25 | 60 | 54 | 64 |

So the density is not bought with instruction count. **Code size lands below
GCN on four of five kernels** — 166 against 268 bytes on the reduction, and
with the alignment attribute `vadd` is 56 bytes against 152, which is 2.7×.

**`transpose` is the exception, and it became one deliberately.** After O-31 it
was 294 bytes against GCN's 308 — below, and an earlier version of this document
said "below GCN on every kernel" on the strength of it. O-33 then added lane-0
masking, which costs a broadcast instruction wherever it fires, and `transpose`
grew to 84 instructions and 316 bytes. That is a **regression in the column this
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

| | issued lane slots | activations | share |
|---|---|---|---|
| `transpose`, masking off | 2304 | 2304 | 100% |
| `transpose`, masking on | 2592 | **1493** | **58%** |

**811 fewer lanes switched — a 35% cut — for nine added instructions**, four
broadcasts and five `pand`.

Four changes got there:

| | instrs | activations | what changed |
|---|---|---|---|
| O-33 as first built | 76 | 1809 | mask uniform work to lane 0, broadcast the result |
| after O-34 | 76 | 1747 | conversions moved into Format A′'s reach, so the division's two `cvt`s mask |
| after F-58 part 1 | 76 | 1587 | `select` lowers to a predicated move, not `sel` |
| counter corrected | 76 | 1555 | a predicate-file op is not 32 lane activations |
| after F-58 part 2 | **81** | **1493** | already-predicated instructions compose their guard with the lane mask via `pand` |

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

76 instructions issued against 64 — the only kernel where CCV issues more. Two
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
divisions, that is 89 → 86 static instructions and 1493 → 1428 lane-activations.

**The fp32 round trip was never about precision.** `tools/model-rcp.py` measures what the
sequence actually needs: 16 bits of reciprocal, against the ~23 an fp32 unit supplies. Making
`rcp.f32` more accurate would have saved nothing, because fp32's 24-bit significand is what
forces the Newton step, not the unit's error. See O-35.

`transpose` fell from 143 instructions and 482 bytes to 83 and 294 (84 and 316
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
  this toolchain — though a scalar CPU comparison needs its own argument about
  what is comparable.
