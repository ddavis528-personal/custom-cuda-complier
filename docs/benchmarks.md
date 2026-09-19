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
| **NVIDIA SASS** | `ptxas -O3 -arch=sm_70` — the **real machine encoding of the compatibility target** | yes |
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

**SASS is measured now, and it was the comparison that mattered most.** For four
revisions this section said it could not be produced here. It can: `ptxas` is a
*host* compiler and needs no GPU, NVIDIA ships it as a pip wheel, and
`tools/fetch-ptxas.sh` is the whole install. No disassembler is needed and none
is published — the cubin's `.text.<kernel>` section **is** the SASS.

§6 of the ISA document states that Volta-and-later SASS is 128 bits per
instruction, 64 of instruction and 64 of compiler-scheduled control, and carried
that as an unverified citation. **It measures 128.0 bits per instruction
exactly, on every kernel, from Volta through Blackwell.** The citation is now a
measurement.

Pre-Volta is excluded deliberately: sm_60 and earlier use a 64-bit encoding with
separate control words, which a 16-byte walk would silently miscount.

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
  vadd       |     20     62   24.8 |     13     42 |     29    152   41.9 |     21
  saxpy      |     19     64   26.9 |     14     48 |     25    136   43.5 |     19
  vadd16     |     21     68   25.9 |     14     48 |     29    152   41.9 |     21
  vadd_loop  |     24     74   24.7 |     16     50 |     35    184   42.1 |     23
  vadd16_loop |     25     80   25.6 |     17     56 |     35    184   42.1 |     23
  dot        |     52    162   24.9 |     43    134 |     60    300   40.0 |     46
  reduce     |     48    150   25.0 |     41    128 |     54    268   39.7 |     41
  transpose  |     60    210   28.0 |     52    184 |     64    308   38.5 |     43

```

**Dynamic — instructions actually issued, per thread of work.**

```
  kernel          CCV   SIMT     AMDGCN |  lane-act  of issued   how AMDGCN was obtained
  ----------------------------------------------------------------------------------------------
  vadd           13.0   100%         29 |       416       100%   exact: no backward branch
  saxpy          14.0   100%         25 |       448       100%   exact: no backward branch
  vadd16         14.0   100%         29 |       448       100%   exact: no backward branch
  vadd_loop      65.0   100%         -- |      2080       100%   has 1 loops; not modelled
  vadd16_loop     66.0   100%         -- |      2112       100%   has 1 loops; not modelled
  dot            74.9    66%         -- |      2397       100%   has 3 loops; not modelled
  reduce         72.9    66%         -- |      2333       100%   has 3 loops; not modelled
  transpose      52.0   100%         64 |      1127        68%   exact: no backward branch

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
  kernel                 CCV        NV SASS    GCN5 / Vega          RDNA2          RDNA3          RDNA4  CDNA3 / MI300
                                      sm_70           2017           2020           2022           2024           2023
  --------------------------------------------------------------------------------------------------------------------
  vadd                  24.8          128.0           41.9           48.6           46.0           48.0           48.7
  saxpy                 26.9          128.0           43.5           47.3           44.6           46.9           47.2
  vadd16                25.9          128.0           41.9           49.8           47.0           49.0           48.7
  vadd_loop             24.7          128.0           42.1           42.9           41.8           45.9           45.2
  vadd16_loop            25.6          128.0           42.1           43.6           42.4           46.8           45.2
  dot                   24.9          128.0           40.0           41.5           40.9           42.3           42.1
  reduce                25.0          128.0           39.7           42.9           39.2           41.4           40.2
  transpose             28.0          128.0           38.5           41.1           39.6           39.2           38.7
  --------------------------------------------------------------------------------------------------------------------
  pooled                25.9          128.0           40.7           43.7           41.8           43.8           43.1

```

**Instruction counts, same sweep — the control:**

```
  kernel                 CCV        NV SASS    GCN5 / Vega          RDNA2          RDNA3          RDNA4  CDNA3 / MI300
  --------------------------------------------------------------------------------------------------------------------
  vadd                    20             17             29             27             32             32             23
  saxpy                   19             16             25             23             28             28             21
  vadd16                  21             17             29             27             32             32             23
  vadd_loop               24             20             35             44             49             39             29
  vadd16_loop              25             20             35             44             49             39             29
  dot                     52             42             60             64             68             62             54
  reduce                  48             39             54             50             71             58             51
  transpose               60             53             64             60             76             76             62

```

**The objection does not land.** AMD's density is flat across eight years and two
encoding families — 40.7 to 43.8 bits per instruction pooled, with no trend — and
CCV's 27.3 is **0.62× to 0.66× of every one of them**. The ratio against RDNA4
(2024) is the same as against Vega (2017). Whatever the variable-length encoding
is buying, it is not an artifact of an obsolete baseline.

#### What SASS does that CCV does not

`nvdisasm` reads the cubin, so the five-instruction gap on the complex kernels
can be looked at rather than guessed. Three hypotheses, settled:

**They do not have an integer divide.** `transpose`'s runtime division in SASS
is `I2F.U32.RP` → `MUFU.RCP` → `F2I` → `IMAD` → two `IMAD.HI.U32` Newton steps →
`ISETP`/`IADD3` correction, twice → a `LOP3` for the divide-by-zero case. That is
**O-31/O-35's algorithm, step for step**: a float reciprocal seed from the SFU,
integer Newton refinement, `mul.hi` for the quotient, two conditional
corrections. NVIDIA expands division exactly as this project does, and the
instruction counts are comparable. Nothing was skipped.

**Predicated control flow is not the gap either.** SASS uses `@P0 EXIT` where CCV
branches over the body, and predicates its correction steps (`@P0 IADD3`,
`@!P2 LOP3`) — all of which Format A′ already provides.

**Four things are real, and all four are encoding rather than architecture.**

| | what SASS has | cost to CCV |
|---|---|---|
| **Zero register** | `RZ` as any operand — `IMAD R7, R7, R3, RZ` | **5 `movi` across the suite**, purely to materialize 0 |
| **Reg-immediate at three addresses** | `LOP3.LUT R4, R8, 0xf, R13, …`, `SHF.R.S32.HI R3, RZ, 0x1f, R0` | **3 `movi`** |
| **Three-source with an immediate** | `IMAD R11, R5, 0x44, R9` | **1 `movi`** |
| **Uniform registers** | `S2UR UR4, SR_CTAID.X`; vector ops take `UR` operands | not instruction count — see below |

**9 of the 19 `movi` in the whole benchmark exist only because an immediate has
nowhere to go.** On `transpose` that is 5, which is the entire 58-vs-53 gap.

The second row is the striking one, because **the encoding space is already
reserved and mostly empty**. Format B is the 32-bit register-immediate format
with a 5-bit opcode — 32 points — and three are used: `addi`, `packi`,
`unpacki`. Meanwhile the *16-bit compressed* Format K has eight immediate forms
(`C_ANDI`, `C_ORI`, `C_XORI`, `C_SHLI`, `C_SHRI`, `C_SRAI`, `C_SUBI`, `C_ADDI`).
So `rd = rd & 15` is one 16-bit instruction and `rd = rs & 15` is two 32-bit
ones, for want of an opcode point in a format with 29 free.

**And one thing CCV does that SASS cannot.** `ld.global r2, [r2, r1, 1, 0]`
computes `base + index × scale` and loads in **one** instruction; SASS needs
`IMAD.WIDE.U32` and then `LDG.E`. Every memory access in the SASS listings is
two instructions where CCV's is one — which is why CCV is *ahead* on `vadd` and
`vadd_loop` despite everything above.

**The uniform register file is the architectural finding, and it is NVIDIA's.**
`S2UR UR4, SR_CTAID.X` reads the CTA index into a *uniform* register — one value
for the warp, not 32 copies — and `IMAD R9, R9, UR4, R0` consumes it beside
vector operands. That is exactly what O-25 and F-52 argue for from register-file
size and redundant execution, and it is shipping in the compatibility target.
O-33's lane-0 masking is this project's software approximation of it: `transpose`
spends 3 `shfl.idx` broadcasts recovering what a uniform register would have
supplied for free.

#### And against SASS, which is the comparison that actually matters

CCV's compatibility target is CUDA, so NVIDIA's machine encoding is the one the
density argument is really written against. Pooled over all eight kernels:

| pooled over eight kernels | instructions | bytes | bits/instruction |
|---|---|---|---|
| `CCV` | 269 | 870 | **25.9** |
| `NVIDIA SASS` (sm_70) | 224 | 3584 | **128.0** |

**SASS spends 128 bits on every instruction**, and on instruction count the two
machines are now close: **CCV's unaligned build needs 1.20× the instructions and
0.24× the bytes.** The same eight kernels are 4.1× larger as SASS. That ratio
was 1.32× before O-45 removed the window loads.

**On instruction count the comparison above uses CCV's UNALIGNED build, and that
is the pessimistic one.** O-23's alignment attribute is CCV's intended ABI, and
NVIDIA passes 64-bit pointers directly because invariant 11 does not apply to
them. Compared build-for-build:

| | CCV unaligned | CCV aligned | SASS sm_70 |
|---|---|---|---|
| `vadd` | 20 | **13** | 17 |
| `saxpy` | 19 | **14** | 16 |
| `vadd16` | 21 | **14** | 17 |
| `vadd_loop` | 24 | **16** | 20 |
| `vadd16_loop` | 25 | **17** | 20 |
| `dot` | 52 | 43 | **42** |
| `reduce` | 48 | 41 | **39** |
| `transpose` | 60 | **52** | 53 |
| total | 269 | **210** | 224 |

**CCV aligned is 0.94× SASS — fewer instructions, not more.** That is a reversal
and it is worth stating plainly, because this document has carried the opposite
claim in three revisions: 1.32×, then 1.06× after O-41 and `mul.lo`, then 1.05×,
and now below parity. **O-45 is what moved it.** Launch-slot addressing removes
the window load from every global access, and a windowed load was two
instructions where NVIDIA's is one — so the gap that remained was mostly this one
thing. The three complex kernels are still behind (`dot` 43 against 42, `reduce`
41 against 39); the five simple ones are now ahead by 3–4 instructions each.

That is the variable-length encoding doing exactly what §6 designed it to do,
against the machine it was designed against. It is also the cleanest statement
of the trade this document keeps returning to: NVIDIA buys scheduling
determinism and issue efficiency with 64 bits of control per instruction, and
CCV declines to spend them. Whether that is the right call is a hardware
question — a fetch-bound design prefers CCV's side, an issue-bound one prefers
NVIDIA's — but it is no longer an unmeasured one.

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
counts are within 30% everywhere and CCV is *lower* on seven of eight:

| | vadd | saxpy | vadd16 | vadd_loop | vadd16_loop | dot | reduce | transpose |
|---|---|---|---|---|---|---|---|---|
| CCV | 20 | 19 | 21 | 24 | 25 | 52 | 48 | 60 |
| GCN | 29 | 25 | 29 | 35 | 35 | 60 | 54 | 64 |

So the density is not bought with instruction count. **Code size lands below
GCN on seven of eight kernels** — 166 against 268 bytes on the reduction, and
with the alignment attribute `vadd` is 56 bytes against 152, which is 2.7×.

**This table is not a fair comparison, and the next section is the fair one.**
Both rows count instructions issued *per warp*, and the warps are not the same
size: a CCV warp is 32 lanes, a gfx900 wavefront is 64. The document has said
exactly this about SIMT efficiency since 1.4 and never applied it here. Read
normalized, 23 against 29 is not a 1.3× win — it is a loss.

### Work: instructions to finish the kernel, per 1024 elements

The question the table above cannot answer is how many instructions each machine
issues *to do the same work*. One thread handles one element in four of the six
kernels, so a machine covers `warp width` elements per instruction it issues,
and the count that matters is `1024 × instructions ÷ warp width`. `dot` and
`reduce` are excluded: a thread there consumes several elements and then joins a
tree reduction, so there is no such constant, and both loop on both machines so
AMD's dynamic count is unknown anyway.

Warp width is read from the generated kernel descriptor, not assumed — gfx10+
emits `.amdhsa_wavefront_size32` and its absence means wave64.

```
                          CCV    GCN5 / Vega          RDNA2          RDNA3          RDNA4  CDNA3 / MI300
  warp width               32             64             32             32             32             64
  ------------------------------------------------------------------------------------------------------
  issues / 1K elem
    vadd                  416            464            864           1024           1024            368
    saxpy                 448            400            736            896            896            336
    vadd16                448            464            864           1024           1024            368
    vadd_loop             260             --             --             --             --             --
    vadd16_loop            264             --             --             --             --             --
    transpose            1664           1024           1920           2432           2432            992
  instr bytes / 1K elem
    vadd                 1344           2432           5248           5888           6144           2240
    saxpy                1536           2176           4352           4992           5248           1984
    vadd16               1536           2432           5376           6016           6272           2240
    vadd_loop             200             --             --             --             --             --
    vadd16_loop            224             --             --             --             --             --
    transpose            5888           4928           9856          12032          11904           4800

```

**Two results, and they point opposite ways.**

**CCV loses the issue-count comparison to every wave64 machine.** On `vadd`,
CDNA3 issues 368 instructions per 1024 elements against CCV's 512 — 0.72× — and
gfx900 issues 464. A wave64 machine finishes twice the elements per instruction,
and that advantage is larger than anything the encoding recovers. Against the
wave32 parts, which are the like-for-like comparison, CCV wins decisively: RDNA3
issues 1024 against CCV's 512, exactly 2×.

**CCV wins the instruction-bytes comparison against everything except CDNA3 on
`transpose`.** On `vadd` it fetches 1792 bytes per 1024 elements against
gfx900's 2432 (0.74×) and RDNA3's 5888 (0.30×). So on the same kernel CCV issues
**10% more instructions than gfx900 while fetching 26% fewer instruction
bytes** — which is the encoding doing precisely what it was designed to do, and
is invisible in any table that counts instructions alone.

Whether that trade is good is a hardware question this benchmark cannot answer:
it exchanges instruction-fetch bandwidth and I-cache footprint, which CCV wins,
for issue slots and scheduler bandwidth, which wave64 wins. A design that is
fetch-bound prefers CCV's side; one that is issue-bound prefers wave64's. **The
honest statement is that CCV's encoding beats wave32 prior art outright and
trades against wave64 prior art**, and the previous table's "lower on five of
six" overstated it by ignoring warp width.

`transpose` is the worst case on both columns — 2528 issues against gfx900's
1024 — for the reasons §2 already gives: AMD does the division on the scalar
unit, one instruction for the whole wavefront.

**`transpose` was the one kernel above GCN on instruction count, and is no
longer**, and it now
grew to **60 instructions and 210 bytes** against GCN's 64 and 308 — below on
both again after O-45 removed its window loads, and below on issued work at 52
per thread against 64. For most of this project's life it was far worse
than that and the explanation on file was wrong, which is worth recording
because the wrong explanation was plausible for two revisions. See
"`transpose` was not what it looked like" below.

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

### `vadd16`: what the narrow element widths actually cost

v1.6's headline capability is `chwidth` and the sub-32-bit element model, and
until this revision no benchmark kernel touched it. `vadd16` is `vadd` at half
the element width and otherwise identical, so the two are directly comparable.

| | instrs (aligned) | bytes | issued/thread | issues / 1K elem |
|---|---|---|---|---|
| `vadd` (f32) | 16 | 56 | 16.0 | 512 |
| `vadd16` (i16) | 18 | 62 | 18.0 | 576 |

**The narrow form costs two instructions and buys nothing in issue count.** At
one element per thread there is no packing to exploit: a 16-bit element occupies
a 32-bit lane exactly as a float does, so the same number of lanes does the same
number of adds. What it buys is elsewhere — **half the memory traffic**, and
stores that write two bytes instead of four, which is the correctness bug F-67
was.

The two instructions are three `chwidth` transitions net of one saving, and the
third is the interesting one:

```
	add r2, r1
	chwidth r2, 1          ; narrow, for the load's destination
	ld.global r2, [r3, r2, 0, 0]
	...
	add r2, r3, r2         ; the 16-bit add
	chwidth r3, 0          ; widen r3 BACK -- r3 is about to hold a 32-bit value
	ld.global r3, [r0 + 36]
```

That last `chwidth` is not dead code: §3 takes transfer size from the
destination register's width, so the 32-bit load into `r3` would write two bytes
if `r3` were left narrow. It is also **entirely avoidable** — eleven registers
were free, and the allocator chose to reuse the one it had just narrowed. This
is the width-affinity allocator objective F-3 left open, and `vadd16` puts a
number on it for the first time: **one instruction in eighteen, 5.6%.**

`ld.global r2, [r3, r2, 0, 0]` is also worth noting as O-39 in the generated
code: `r2` is the index *and* the destination. The address read takes all 32
bits regardless of `r2`'s narrowed width, which is exactly the consequence O-39
records, and it is what lets the sequence avoid a second register.

**AMD gets narrow types for free and gains nothing either.** gfx900's `vadd16`
is 29 instructions and 152 bytes — identical to its `vadd`, and genuinely
16-bit (`global_load_ushort`, `v_add_u16_e32`, `global_store_short`). GCN
encodes 16-bit operations in the same instruction formats as 32-bit ones, so the
width is free and also worthless at the instruction level. CCV is the machine
that *pays* for narrow types here.

So the feature does not earn its instructions on this shape, and **no kernel
shape makes it earn them in issue count.** A lane holds one element at every
width (invariant 1), so N elements need N lanes whatever the width: a narrow
kernel issues exactly as many element-work instructions as its 32-bit twin, by
construction. What narrow width buys is **half the memory traffic** and O-40's
higher retire rate on the instructions that are narrow — and what raises the
share of the stream that qualifies is removing the work that is *not* element
work. The next section is that, measured.

#### What amortizes, and what does not

`vadd16` is straight-line: one element per thread, every width transition and
every argument load paid once per element. That measures the **prologue** and
calls it the kernel. A real 16-bit kernel runs many elements per thread, and the
expectation — reasonably — is that the width-handling overhead approaches zero
as iterations grow. `vadd_loop` and `vadd16_loop` are the same two kernels with
a grid-stride loop, measured on the simulator across iteration counts.

It did not, in the revision that first measured it. Two width transitions sat
**inside** the loop body and re-executed every iteration, so the i16 kernel cost
2 instructions per element more than the f32 one at every iteration count — a
gap that got *worse* as a fraction the longer the loop ran, because the prologue
amortized and the transitions did not.

Both were compiler artifacts and both are now fixed. The steady-state bodies:

```
vadd_loop (f32), 7 per element        vadd16_loop (i16), 7 per element
  ld.global r6, [r2, r1, 1, 0]          ld.global r6, [r3, r1, 1, 0]
  ld.global r7, [r3, r1, 1, 0]          ld.global r7, [r2, r1, 1, 0]
  fadd r7, r6                           add r6, r7, r6
  st.global r7, [r4, r1, 1, 0]          st.global r6, [r4, r1, 1, 0]
  add r1, r0                            add r1, r0
  setp.lt.u p0, r1, r5                  setp.lt.u p0, r1, r5
  @p0 bra LBB0_1                        @p0 bra LBB0_1
```

**The loop bodies are now identical in length**, and the entire width cost is in
the prologue, where it amortizes. Measured: `issues = 12 + 7n` for fp32 and
`14 + 7n` for i16 — two instructions, once per thread, for the whole kernel.

What the two transitions were:

**One was a mode switch for a register nobody reads.** O-32's unpredicated
compare writes a materialization destination `rd` beside its predicate, and on a
loop's back-edge test that destination is dead. The allocator gave it a register
the body had narrowed, so the pass emitted a widening `chwidth` to accommodate a
value no instruction reads — every iteration. A dead definition needs no width at
all, and `chwidth` is not free even for a dead one: §3 has it drain in-flight
dependents. (F-89.)

**The other was the cross-block problem proper.** `r6`/`r7` were narrowed at the
top of the body because the preheader left them at 32 and the back-edge brought
them back at 16, so the dataflow marked the loop header's entry width Unknown and
the pass resolved it *inside* the block. The width is loop-invariant and its
natural home is the preheader. `CCVInsertChwidth` now places the transition on
the **incoming edges** when predecessors disagree, under three conditions: no
back-edge may need the insert — otherwise the instruction has merely moved from
the top of the loop to the bottom; the register must be dead on the
predecessor's other edges, because a terminator's `chwidth` runs whichever way
the branch goes; and the insert goes before the first terminator so the width is
established on every path out. (F-87.)

**Both were compiler limitations, not ISA properties** — `chwidth` here is
loop-invariant and nothing in §3 prevented hoisting it.

**The unaligned build needed a third fix, in the register allocator.** Edge
placement cannot lift a transition out of a body where the width genuinely
changes, and in the unaligned form it did: the allocator gave one register the
in-window address arithmetic *and* the narrow data it loaded, so `r10` went
32-bit, narrow, 32-bit every iteration. O-39 is what allows that sharing —
`rdata` may share with `rbase`/`rindex` because the address read takes all 32
bits — and it saves a register at the cost of a width change.

Element width is per-register state, so the allocator is the only pass that can
prevent the handover, and **the register class is the only width information it
has**: `chwidth` names physical registers, so width is otherwise entirely a
post-RA concept. GPR16 therefore now allocates **descending** where GPR
allocates ascending. Same sixteen registers — the set has to match or a
cross-class COPY would not be the no-op §1 says it is — with 32-bit values
clustering from R0 up and 16-bit values from R14 down, so under low pressure
they never meet and there is no handover to pay for. Under pressure they meet in
the middle and share exactly as before; sharing is still far cheaper than
spilling to keep them apart.

The unaligned loop body went from three width transitions to **none**, 15
instructions to 12. It also made O-6's merging fire on `vadd16` for the first
time: the two narrow registers are now adjacent, so their transitions are
adjacent and collapse into one `chwidth.multi`. F-69 measured that as merging 0
of 3 on this kernel and concluded the shape was wrong for it; the shape was
right and the allocation was wrong.

One thing this does **not** establish: no benchmark kernel exercises the
pressure case. `sgemm` is fp32 throughout, so GPR16 never appears in the tile
sweep and its numbers are unchanged to the instruction. The graceful-degradation
argument above is reasoning, not measurement (F-92).

`tools/check-narrow-loop.sh` holds this down: it runs 256 elements over eight
iterations per thread and checks **every** element, not just the first, because
the saving is precisely that the loop never re-establishes the mode — so if the
width did not survive the back edge, iteration two onward would be wrong while
iteration one stayed right. It also asserts the body contains no `chwidth` at
all, since a regression there is invisible in the results, and it now checks the
unaligned build to the same standard.


#### The instruction count is not the whole cost: O-40's retire rate

The instruction-count deficit above is answered by IPC, not by instruction
count. **O-40 splits the datapath allocation so that 16-bit element work retires
at twice the 32-bit rate** — which is the entire return on making element width
per-register state (invariant 1) rather than an opcode field: a narrow
instruction is the *same* instruction against a *narrower slice*, so two of them
share one 32-bit allocation.

What that is worth is bounded by how much of the stream is narrow, and nothing
had measured that. The simulator now counts it:

```
  kernel        issues  elem work  narrow    frac  cycles @2x   vs f32
  --------------------------------------------------------------------
  vadd              13         11       0   0.000        13.0   1.000x
  saxpy             14         12       0   0.000        14.0       --
  vadd16            14         11       4   0.364        12.0   1.083x
  vadd_loop         65         55       0   0.000        65.0   1.000x
  vadd16_loop       66         55      32   0.582        50.0   1.300x
  dot              113         92       0   0.000       113.0       --
  reduce           111         90       0   0.000       111.0       --
  transpose         52         49       0   0.000        52.0       --

```

**`vadd16` is exactly break-even.** 18 issued instructions, 4 of them narrow
element work, gives `14 + 4/2 = 16.0` cycles against `vadd`'s 16.0. The 2× rate
recovers the two instructions the narrow form costs and returns nothing beyond
them — while still delivering half the memory traffic, which no cycle column
shows.

Three things follow, and the first is the one that should shape the hardware:

**1. The narrow work here is memory, not ALU.** Of `vadd16`'s four narrow
instructions, **one is an ALU operation and three are loads and stores**. So the
split allocation has to reach the memory pipe to pay:

| what dual-issues | cycles | vs `vadd` |
|---|---|---|
| ALU and memory both | 16.0 | 1.000× |
| memory only | 16.5 | 0.970× |
| ALU only | 17.5 | **0.914×** |
| neither (retire 1×) | 18.0 | 0.889× |

A split allocation that widens the ALU and leaves the memory path alone makes
this kernel **slower than its 32-bit equivalent**. That is not an obvious
outcome, and it is the opposite of where a designer's attention naturally goes.

**2. The break-even sits exactly at the margin.** One more narrow instruction
tips it — `N=5` gives 15.5 cycles. And **F-80's wasted `chwidth` restore is
exactly one instruction**: removing it gives 17 issued and 4 narrow, or 15.0
cycles, a **1.067×** win. The width-affinity allocator objective is therefore not
a tidiness item; it is what converts this kernel from break-even to a gain.

**3. The ratio the ISA asks for has no margin at today's narrow fraction.** At
1.5× rather than 2×, `vadd16` is 16.7 cycles and loses. 28.6% narrow is not
enough for the retire rate to carry the feature on its own, and **the only way
to raise the fraction is to remove work that is not element work.** A lane holds
one element at every width (invariant 1), so a narrow kernel issues exactly as
many element-work instructions as its 32-bit twin; what varies is how much
prologue, addressing and width-transition overhead sits beside them. That is
F-80 and F-87, and the loop kernels below show what it is worth.

#### Steady state, where the feature was supposed to pay

The straight-line break-even is not an artifact of the prologue. Applying the
same model to the loop bodies:

Measured over eight iterations per thread, whole-kernel:

| | issues | element work | narrow | narrow frac | cycles @2× | vs f32 |
|---|---|---|---|---|---|---|
| `vadd_loop` (f32) | 68 | 58 | 0 | 0.000 | 68.0 | 1.000× |
| `vadd16_loop` (i16) | 69 | 58 | 32 | **0.552** | **53.0** | **1.283×** |

**This is where the element-width model pays.** The narrow fraction reaches 55%
— against `vadd16`'s 28.6% — because the loop body is nothing *but* element work
once the prologue and the width transitions are out of it. At O-40's 2× retire
rate that is 53.0 cycles against the fp32 kernel's 68.0: **a 1.28× speedup for
the same kernel at half the element width**, on top of half the memory traffic.

The contrast with the straight-line kernel is the lesson. `vadd16` is 1.07× at
28.6% narrow; `vadd16_loop` is 1.28× at 55%. **Nothing about the ISA differs
between them** — the same instructions, the same retire rate. What differs is how
much of the issued stream is element work rather than prologue, and that is a
property of the kernel, which is the same conclusion O-6's `chwidth.multi`
measurement reached from the other direction (F-69).

**A correction, because these numbers were published wrong once.** An earlier
revision reported this row as 40 narrow, a 0.690 fraction and **1.360×**. The
counter was taking the narrowest of *all* an instruction's GPR operands, and
Format C's materialization destination `rd` is a GPR operand the compare never
writes — so when the allocator gave a loop's back-edge test a `rd` in a narrowed
register, a plainly 32-bit comparison was counted as narrow element work, once
per iteration. The fraction and the speedup were both overstated. The counter
now skips that operand (F-91), and the figures above are what the corrected
counter gives for the same code.

**The cycles column is a model and is labelled as one everywhere it appears.**
The simulator retires one instruction per step; the column applies O-40's
claimed rate to the narrow instructions the simulator counted. The narrow counts
themselves are measured. This is the same discipline as the lane-activation
column, and O-40 is now the fourth entry in the ISA document's §1a list of
properties the compiler depends on and cannot verify.

### Lane-activations: the column O-33 exists to move

An instruction count cannot see lane-0 masking at all. Masking a warp-uniform
instruction to one lane costs an extra broadcast *instruction* and saves 31 lane
*activations*, so a table with only an instruction column reports the price and
hides the goods. That is exactly what happened to `transpose` above.

The `lane-act` column is the measurement, from `ccv-sim -counters`:

| | issued/thread | issued lane slots | activations | share |
|---|---|---|---|---|
| `transpose`, masking off | 45.0 | 1440 | 1344 | 93% |
| `transpose`, masking on | 52.0 | 1664 | **1127** | **68%** |

**217 fewer lanes switched — a 16% cut — for 7 added instructions per thread.**
The pass's own stats account for them: 14 operations masked to lane 0, 1 already
predicated and composed with `pand` (F-58), 7 broadcasts inserted, plus the one
`pmov` that materializes the lane-0 mask. The broadcast count rose and the
saving fell when F-134 fixed the pass: a value consumed by an instruction that
is NOT masked needs broadcasting however uniform it is, and compares -- which
are never maskable -- were being treated as if they were in the region. F-111 widened this: O-41's Format B
immediate forms were added without extending the masking pass's table, so every
`add rd, rs, #k` in uniform code — most of the addressing arithmetic O-33 exists
to gate — was unmaskable. The masked count went *down* and the saving went *up*,
because the immediate forms replace several instructions each.

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

### `transpose` was not what it looked like

`transpose` was the outlier on every column for two revisions, and the
explanation on file — O-33's broadcasts plus AMD's scalar unit — accounted for a
fraction of it. Taking the kernel apart instruction by instruction found two
compiler defects worth **21 of its 79 issued instructions**, and neither had
anything to do with masking:

| | issued | vs GCN5's 64 |
|---|---|---|
| as measured for two revisions | 79 | +23% |
| after F-93 — stop expanding constant divisors | 60 | −6% |
| after F-94 — collect the dead reciprocal seed | 58 | −9% |
| after O-41 and `mul.lo` — immediates have somewhere to go | **54** | **−16%** |

52 instructions issued against GCN5's 64 is where it lands.

**F-93 is the large one, and it hid behind a comment.** `CCVExpandDivision`
opened with "constant divisors never reach here — instcombine turns those into a
shift". That is true for *unsigned* and false for *signed*: instcombine reduces
`udiv x, 16` to `lshr` and leaves `sdiv x, 16` alone, because rounding toward
zero costs three extra instructions and that is a CodeGen trade rather than a
canonicalisation. `transpose` computes `n / T` with `T` a compile-time 16 and
`n` an `int` — so its constant divisor went through the **full runtime-divisor
expansion**, Newton iteration and all. Skipping constant divisors and letting
DAGCombiner's `BuildSDIV` strength-reduce them takes the kernel from 79 to 60.

It was invisible for a specific reason: `rcp.u32` of a constant **folds**, so
the generic expansion of a *constant* divisor emits no reciprocal at all. Every
Newton and correction step was there, with nothing in the listing to say which
division they belonged to.

**F-94 is smaller and simpler.** `CCVFuseRcpSeed` replaces the fp32 reciprocal
chain with `rcp.u32` and left the chain behind for "the generic
dead-machine-instr elimination that follows". No such elimination removed it, so
every division carried a dead `cvt.f32.u32` and `rcp.f32`. Neither is marked
with side effects; nothing was protecting them, they simply outlived the pass
meant to collect them.

**What remains is the structural part, and it is now small.** AMD does the
division on the scalar unit: the divisor is warp-uniform, so their sequence is
`s_mul_i32`, `s_sub_i32`, `s_cselect_b32` — one instruction per operation *for
the whole wavefront*. CCV issues it to all 32 lanes and, since O-33, activates
only one of them for the part that can be masked. That closes the energy gap
partway and none of the issue-bandwidth gap: a scalar unit does not issue to the
vector pipe at all.

**Masking was never the main cost, and the A/B always said so.** It is 6
instructions of the 53 — `transpose` runs 47 issued with masking off and 53 with
it on. The explanation on file attributed the outlier to it anyway, which is the
lesson worth keeping: a plausible cause that is present in the code will absorb
an unexplained cost indefinitely if nobody measures the parts.

**Masking did contribute, but not the way the old explanation said.** The dead
seed of F-94 was removed by the generic dead-code elimination in every
*unmasked* kernel and survived in every *masked* one — under the old passes
`transpose` carried 2 dead instructions with masking on and 0 with it off.
`CCVMaskUniform` runs after `CCVFuseRcpSeed`, and **a predicated definition is
not something the generic DCE will remove**, so an optimisation silently
disabled a later cleanup and the cost landed on the optimisation's own account.
The general shape is worth keeping: any pass that predicates instructions moves
them out of DCE's reach, so leaving dead code for "the DCE that follows" is
relying on something masking can take away (F-97).

**Scope, because "we fixed a compiler bug" invites the wrong assumption.** These
two fixes changed `transpose` and `sgemm` (639 → 637 instructions at the 2×4
tile) and **nothing else** — every other benchmark kernel is identical to the
instruction, because none of them contains a division at all (F-98).

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

`tools/sweep-tiles.sh`, on two GEMMs of identical shape — same tiling, same
staging, same TM×TN per-thread accumulator tile — differing only in arithmetic.
Both kernels are swept because `gpr-count-decision.md` credits `dp4.acc` with
making 16 GPRs sufficient under INT8 accumulator pressure, and that claim is
only testable against an FP32 kernel of the same shape (F-113, F-121):

```
  FP32 -- test/cuda/sgemm.cu
  tile  accs    instrs     bits b/instr  spills   macs sp/mac  acc-sp  ptr-sp  div/unif
  ---------------------------------------------------------------------------------
  1x1   1          185     5248    28.4      40     10   4.00       2      24     28/10
  1x2   2          275     7952    28.9      74     22   3.36       2      54     46/10
  2x2   4          360    10512    29.2     102     40   2.55       4      76     60/10
  2x4   8          579    17472    30.2     190     75   2.53      17     116     95/10
  4x4   16         916    28112    30.7     397    142   2.80     180     152    131/10
  8x8   64        2530    79664    31.5    1441    521   2.77    1133     272    282/10

  INT8 -- test/cuda/igemm.cu, four MACs per dp4
  tile  accs    instrs     bits b/instr  spills   macs sp/mac  acc-sp  ptr-sp  div/unif
  ---------------------------------------------------------------------------------
  1x1   1          182     5184    28.5      37     34   1.09       2      22     28/10
  1x2   2          271     7824    28.9      69     70   0.99       2      50     46/10
  2x2   4          368    10672    29.0     105    136   0.77       4      76     60/10
  2x4   8          589    17760    30.2     199    267   0.75      18     116     95/10
  4x4   16         914    28112    30.8     392    526   0.75     165     152    131/10
  8x8   64        2525    79584    31.5    1437   2057   0.70    1127     272    282/10

  sp/mac is the decision number: memory traffic the register file forced, per
  multiply-accumulate it bought. A bigger tile raises arithmetic intensity as
  TM*TN/(TM+TN), so it is only worth it while sp/mac does not rise faster.

  acc-sp and ptr-sp are that traffic separated by cause (F-113), which is what
  `gpr-count-decision.md` asked for: accumulator spill is the risk §1 names as
  unmitigated for FP32, and pointer/index spill is the one O-23 addresses.
  They do not sum to `spills`: a slot whose role neither a use nor a defining
  opcode establishes -- a value live across a block boundary in both
  directions, mostly -- is left unclassified rather than assigned to whichever
  column looks likelier, and the residual is visible in the pass's own output.

  div/unif is the peak number of values live at once, split by divergence. It
  is the column F-128 got wrong by looking at only half of it: an address here
  is not automatically warp-uniform, because `sgemm` indexes by `threadIdx` and
  its row and column offsets differ per lane. A uniform register file cannot
  hold a divergent value whatever its role, and the DIVERGENT peak alone is
  several times the 16-entry file at every tile -- so moving every uniform
  value out for free would not stop this kernel spilling. See sweep-decode.sh
  for the shape where it would.

```

`sp/mac` — memory traffic the register file forced, per multiply-accumulate it
bought — has a **minimum at 2×4** and rises again at 4×4, where sixteen
accumulators are the whole file and everything else spills. At 16 GPRs the
practical ceiling is 2×4, which is what §1 guessed before there was anything to
measure.

### The split the decision asked for, and what it says

`gpr-count-decision.md` asked for spill separated into **accumulator** spill,
which it calls the one live risk with no mitigation for FP32, and
**pointer/index** spill, which O-23 already addresses. Until F-113 there was
only a total, and the prose here *inferred* the split from how the total scaled
with TM×TN. The inference pointed the right way and was wrong about magnitude
at every tile that fits:

| FP32 tile | accumulator | pointer/index |
|---|---|---|
| 1×1 | 0 | 22 |
| 1×2 | 0 | 42 |
| 2×2 | 4 | 66 |
| 2×4 | 8 | 110 |
| 4×4 | 148 | 146 |

**Through 2×4 — every tile that fits 16 GPRs — spill is overwhelmingly
addressing, not accumulators.** Accumulator spill is zero until the tile has
four accumulators and stays under 8% of the total until the tile has sixteen,
at which point it explodes: the accumulators ARE the register file and there is
nothing left. So the risk §1 named is real and it is a cliff rather than a
slope, and it sits one tile beyond the practical ceiling the `sp/mac` minimum
already identified.

**`dp4.acc` earns the credit the decision gave it.** The INT8 kernel's spill
profile is nearly identical to FP32's — same addressing, same tiles, same
accumulator count — but it does four MACs per accumulator register, so `sp/mac`
lands at **0.51–1.03 against FP32's 2.07–3.78**, a factor of about four. That
is the mitigation working exactly as argued, and it is worth recording that it
was argued for two revisions before anything could emit the instruction: F-111
found `dp4.acc` unselected, and F-121 built the path.

### Against a machine that does not spill

`sweep-tiles.sh` says what a tile costs CCV. It cannot say whether that cost is
normal. `tools/nv-tile-pressure.sh` compiles **the same file, same block shape,
same tiles** to PTX for sm_70 and asks `ptxas -v`, which reports registers and
spill directly — the vendor's own allocator reporting on the vendor's own file:

```
  tile  accs  registers       spill
  -----------------------------------
  1x1   1            32     0 bytes
  1x2   2            32     0 bytes
  2x2   4            32     0 bytes
  2x4   8            32     0 bytes
  4x4   16           48     0 bytes
  8x8   64          121     0 bytes

  Zero spill at every tile, including 8x8 -- 64 accumulators, which is the tile
  a throughput SGEMM actually uses and which CCV cannot hold at all. The
  comparison is not that NVIDIA spills less; it is that NVIDIA does not spill,
  and reaches an arithmetic intensity CCV has no way to reach.
```

**Zero spill at every tile.** NVIDIA runs the tile CCV runs best (2×4) in 32
registers with nothing spilled, where CCV spills 139 times; and it runs 8×8 — 64
accumulators, the tile a throughput SGEMM actually uses — in 121 registers,
still with nothing spilled. CCV at 8×8 issues 2582 instructions and spills 1491
times, which is not a tuning point but a report that the tile does not fit.

The gap that matters is not instruction count, where CCV is competitive
(§2 puts it at 0.94× of SASS on the aligned build after O-45). It is **arithmetic
intensity**: a TM×TN tile does TM·TN MACs per TM+TN operand elements loaded, so
2×4 buys 1.33 and 8×8 buys 4.0. Three times the arithmetic per byte of operand
traffic is a bandwidth argument, and no amount of encoding density answers it.

Two things properly qualify that, and neither removes it. `dp4.acc` closes most
of it for quantized work — the INT8 kernel gets four MACs per accumulator
register, so its `sp/mac` at 2×4 is 0.51 against FP32's 2.07, and quantized
inference is a workload where CCV's 2×4 is not obviously behind. And a
throughput SGEMM is not what a 16-GPR machine is for. But FP32 GEMM is the case
`gpr-count-decision.md` itself named as having no mitigation, and this is what
that looks like measured.

**The column that matters for the next decision is `unif` — and reading it
alone gets the answer wrong.** Peak warp-uniform values live is **11 at every
tile size**; it is a property of the addressing, not of the accumulator tile.
F-128 put that beside the `ptr-sp` column and concluded that a warp-uniform
register file would hold what was spilling. **That inference was wrong, and §4
measures why:** `sgemm` indexes by `threadIdx`, so its row and column offsets
differ per lane, and a uniform file cannot hold a divergent value whatever role
it plays. At 2×4 the peak *divergent* working set is **69 values against a
16-entry file**. Move every uniform value somewhere else for free and this
kernel still spills.

Density holds up under pressure: 26.4–28.1 bits per instruction across a 6.5×
range of kernel size.

**The compressed-form hit rate stays low and drifts down under pressure** —
22% at 1×1 down to 13% at the largest tiles. Register pressure and Format K compression work against each other, because
the allocator lands `rd == rs0` less often when it has less freedom. O-29's
proposed "bias allocation toward the tie" would therefore be worth least exactly
where code size matters most.

---

## 4. Decode and fused shapes: where a uniform file would actually pay

`tools/sweep-decode.sh`. §3 is all `sgemm`, and a GEMM tile is not what most of
an inference workload is. Batch-1 GEMV is what decode does per token; a fused
elementwise epilogue — residual, scale, bias, activation, fused so the
intermediates never reach memory — is what surrounds every matrix multiply. The
two columns that decide the register-file question are the divergence split of
peak live values, and the count of warp-uniform values re-loaded from the launch
block:

```
  decode and fused shapes -- what binds when there is no tile to fill
  kernel         instrs     bits  spills  div/unif   uni-ld
  ------------------------------------------------------------
  gemv              206     6352       3       6/7       3%
  gemv8             206     6336       3       6/7       3%
  fused NT=1         24      640       0       3/5      25%
  fused NT=4         36      976       0       3/8      25%
  fused NT=8         54     1488       0      3/12      28%
  fused NT=16        94     2640       0      3/20      33%

  ...and the same fused chain as a grid-stride LOOP, which is how one is
  actually written. The bases become loop-invariant, so they are hoisted
  and have to stay live across the loop instead of for two instructions:
  ------------------------------------------------------------
  loop NT=1          30      800       0       4/7      20%
  loop NT=4          42     1136       0      4/10      21%
  loop NT=8          60     1648       0      4/14      25%
  loop NT=16        114     3168       9      4/22      28%

  For contrast, the same two columns on the GEMM this was compared against:
  ------------------------------------------------------------
  sgemm 2x2         360    10512     102     60/10       0%
  sgemm 2x4         579    17472     190     95/10       0%
  sgemm 4x4         916    28112     397    131/10       0%

  Read the div/unif column first. In `sgemm` the divergent peak alone is several
  times the 16-entry register file -- its addressing is indexed by `threadIdx`,
  so the row and column offsets differ per lane and a uniform file cannot hold
  them. In the fused kernels it is the other way round: almost everything live
  is uniform, and the divergent peak never leaves single digits.

  Then read uni-ld. The straight-line fused kernels do not spill at any tensor
  count, which is not the same as not paying: each window base is re-fetched
  from the launch block at its one use rather than kept in a register, so the
  cost lands in the instruction count -- around a third of it -- instead of in
  spill traffic.

  The grid-stride rows are the ones that decide it. Making the chain a loop
  makes the bases loop-invariant, so they are hoisted and must stay live; the
  divergent peak stays at 4 whatever the tensor count, while the uniform peak
  passes the 16-entry file and the kernel starts spilling. That is a working
  set of four divergent values spilling because twenty uniform ones are in the
  way, and it is the one shape measured here where a warp-uniform register file
  would remove essentially all of the traffic rather than some of it.

```

**Three shapes, three different answers, and only one of them supports a uniform
file.**

`gemv` does not bind at all: six divergent and seven uniform values live, eleven
spill transfers in 226 instructions. There is no reuse to tile for — every
weight is read once — so the register file has nothing to hold onto and the
kernel is bandwidth-bound by construction. Quantizing changes the bytes moved,
not the register pressure: `gemv8` is identical on every column here and does
four times the arithmetic per word loaded.

`sgemm` binds on **divergent** values, 47–99 of them against sixteen registers.
A uniform file is beside the point.

The **grid-strided fused chain** is the case. Its divergent working set is **four
values at every tensor count** — the element, the index, the loop counter, the
bound. Its uniform working set is the window bases, and it grows with the number
of tensors fused: 7, 10, 14, 22. Spill starts exactly where that crosses the
file and rises with it, to 79 transfers at sixteen tensors. **That is four
divergent values spilling because twenty-two uniform ones are in the way**, and
it is the one measured shape where a uniform register file removes essentially
all of the traffic rather than some of it.

The straight-line version does not spill, which is not the same as not paying:
each base is re-fetched from the launch block at its single use instead of being
kept in a register, so the cost lands in the instruction count — about a third
of the kernel — rather than in spill traffic. A uniform file removes that too.

**So the case for F-106 rests on looping fused elementwise kernels**, the
dominant non-GEMM shape in inference, and on neither of the two arguments made
for it before this was measured: not GEMM accumulator pressure
(`gpr-count-decision.md`'s framing), and not GEMM address pressure (F-128's).

---

## 5. Real fused kernels: what the synthetic one was standing in for

`tools/sweep-fusion.sh`. §4's entire conclusion comes from `test/cuda/fused.cu`,
one kernel written for that measurement, whose tensor count `NT` is a compile
flag and whose range — 1 to 16 — was chosen here. Read the §4 table again with
that in mind: the row that carries the argument is `loop NT=16`, and there is no
claim anywhere that a real kernel fuses sixteen tensors. F-129 and F-140 were
both read off a knob at its top setting.

`test/cuda/fusion/` is the replacement: eight kernels written from the published
shape of ones that actually run in inference and training stacks. **Every
pointer count below is forced by the kernel's own mathematics.** RMSNorm has
three tensors because RMSNorm has three tensors; `silu_and_mul` has two because
the gate and up projections are halves of one allocation, which a kernel
parameterised on "number of tensors" would have counted as three.

```
  real fused kernels -- pointer counts fixed by the mathematics, not swept
  kernel         ptrs  scal  instrs    bits  slots  spills uni-sp ptr-sp acc-sp  div/unif
  ---------------------------------------------------------------------------------------
  swiglu            2     1      39    1040      3       0      0      0      0       3/7
  rmsnorm           3     2      79    2128      4       0      0      0      0       6/9
  add_rmsnorm       3     2      84    2256      6       0      0      0      0       8/9
  rope              4     4     144    4000     13      24     17      0      0     11/15
  adamw             4     8      78    2096      7      11      6      0      2      8/15
  dequant           6     1      61    1616      6       0      0      0      0      5/10
  layernorm         6     2     113    3040      7       0      0      0      0      8/14
  attn_combine      4     2     219    6352     16      11      6      0      0      3/19

  THE POINTER COUNTS ARE 2 TO 6. The synthetic `fused.cu` swept 1 to 16 and the
  conclusions drawn from it -- F-129's case for a uniform register file, F-140's
  case for widening the launch-slot field -- were both read off its top settings.
  Nothing in this corpus reaches eight pointer arguments, which is the reach of
  O-45's 4-bit slot index. On this evidence the slot field is not the constraint.

  PTR-SP IS ZERO EVERYWHERE. F-126 and F-128 argued that what a uniform register
  file would hold is the spilling window bases and indices. After O-45 there are
  no spilling window bases: every one of these kernels addresses global memory
  through the slot form or a base the allocator never has to evict.

  WHAT SPILLS IS WARP-UNIFORM SCALARS. The three kernels that spill at all spill
  their non-pointer arguments -- `rope`'s head geometry, `adamw`'s eight
  optimiser constants, `attn_combine`'s split count -- together with the CTA
  index. Each is one launch-block word, each is identical in all 32 lanes, each
  is loop-invariant, and each currently costs a lane-0 masked load plus a
  broadcast (O-33) or a spill slot. They are exactly what a warp-uniform
  register file holds, and they are NOT what either previous argument for one
  named: not GEMM accumulators, which are per-lane, and not window bases, which
  O-45 removed.
```

**The corpus reaches six pointers. The slot field reaches eight.**

F-140 recorded that O-45's 4-bit slot index covers pointer arguments 0–7, and
proposed widening it because `fused.cu` at NT=16 has eighteen pointers and gets
exactly eight slot-form accesses. Nothing in this corpus has more than six. On
this evidence the slot field is not the constraint, and widening it is work with
no measured kernel behind it — which is the same objection the warp-uniform
register file was rated weak on.

**Pointer and index spill is zero in all eight.**

F-126 and F-128 argued that what a uniform register file would hold is the
spilling window bases and indices; F-128 was retracted when the values turned out
to be `threadIdx`-derived and divergent. This closes the rest of it from the
other side: after O-45 there is no window-base spill left to hold. The
`ptr-sp` column is zero in every row, including the six-pointer kernels.

**What spills is warp-uniform scalars, and it is a third thing.**

Three kernels spill. In each, the spilled values are the kernel's non-pointer
arguments and the CTA index — `rope`'s head geometry, `adamw`'s eight optimiser
constants, `attn_combine`'s split count. Each is one launch-block word, each is
identical in all 32 lanes, each is loop-invariant, and each currently costs
either a spill slot or O-33's lane-0 masked compute plus a `shfl.idx` broadcast.

That is exactly what a warp-uniform register file holds. It is also **neither of
the two things previously argued for one**: not GEMM accumulator pressure, which
is per-lane and unreachable by any uniform mechanism (F-138), and not window
bases, which O-45 removed. The case survives its own two failed arguments,
narrower and better founded than either — and smaller, because the quantity is
3 to 17 transfers in a real kernel rather than 79 in a synthetic one.

**Four compiler defects, found on first contact.**

Worth recording beside the numbers, because it is the strongest evidence that
the corpus was measuring the machine rather than itself. Writing these kernels
found, in order: the SFU group unreachable from CUDA (F-141); `out[i + 1]`
segfaulting the compiler, with the displacement field it needed present in the
encoding and written as a literal zero (F-142); every negative float constant
unencodable, and `fdiv -1.0, x` unselectable (F-144); and O-33's lane-0 masking
unsound whenever lanes are not co-issued, which made `rope` run forever (F-145).
Not one of them was reachable by any kernel in `test/cuda/` or `test/bench/`.

---

## 6. What would strengthen this

- ~~**SASS.**~~ Done — `tools/fetch-ptxas.sh`, and the numbers are in §2. What
  remains unmeasured on the NVIDIA side is *dynamic* SASS: instruction counts
  here are static, and without a GPU or an emulator there is no issue count to
  compare against CCV's simulator figures.
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

- **A narrow kernel under register pressure.** The width-affinity allocation
  order (F-80) is argued to degrade gracefully when the two widths collide, and
  nothing here tests it: `sgemm` is fp32 throughout so GPR16 never appears, and
  the narrow kernels use three narrow registers out of sixteen. F-92.

- **Dynamic counts for the reduction kernels, work-normalized.** The work table
  covers four of six kernels. `dot` and `reduce` are excluded because a thread
  consumes several elements and then joins a tree reduction, so there is no
  constant elements-per-thread, and both loop on both machines. Getting them in
  needs either an AMD simulator or an argument that their loop trip counts match.
