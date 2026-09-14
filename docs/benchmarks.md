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
  vadd16     |     26     86   26.5 |     18     62 |     29    152   41.9 |     21
  vadd_loop  |     27     94   27.9 |     19     66 |     35    184   42.1 |     23
  vadd16_loop |     30    104   27.7 |     21     74 |     35    184   42.1 |     23
  dot        |     55    178   25.9 |     47    152 |     60    300   40.0 |     46
  reduce     |     50    162   25.9 |     44    142 |     54    268   39.7 |     41
  transpose  |     87    320   29.4 |     79    290 |     64    308   38.5 |     43
```

**Dynamic — instructions actually issued, per thread of work.**

```
  kernel          CCV   SIMT     AMDGCN |  lane-act  of issued   how AMDGCN was obtained
  ----------------------------------------------------------------------------------------------
  vadd           16.0   100%         29 |       512       100%   exact: no backward branch
  saxpy          17.0   100%         25 |       544       100%   exact: no backward branch
  vadd16         18.0   100%         29 |       576       100%   exact: no backward branch
  vadd_loop      68.0   100%         -- |      2176       100%   has 1 loops; not modelled
  vadd16_loop     84.0   100%         -- |      2688       100%   has 1 loops; not modelled
  dot            79.9    66%         -- |      2556       100%   has 3 loops; not modelled
  reduce         76.9    65%         -- |      2460       100%   has 3 loops; not modelled
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
  vadd16                26.5           41.9           49.8           47.0           49.0           48.7
  vadd_loop             27.9           42.1           42.9           41.8           45.9           45.2
  vadd16_loop            27.7           42.1           43.6           42.4           46.8           45.2
  dot                   25.9           40.0           41.5           40.9           42.3           42.1
  reduce                25.9           39.7           42.9           39.2           41.4           40.2
  transpose             29.4           38.5           41.1           39.6           39.2           38.7
  -----------------------------------------------------------------------------------------------------
  pooled                27.4           40.7           43.7           41.8           43.8           43.1
```

**Instruction counts, same sweep — the control:**

```
  kernel                 CCV    GCN5 / Vega          RDNA2          RDNA3          RDNA4  CDNA3 / MI300
  -----------------------------------------------------------------------------------------------------
  vadd                    23             29             27             32             32             23
  saxpy                   22             25             23             28             28             21
  vadd16                  26             29             27             32             32             23
  vadd_loop               27             35             44             49             39             29
  vadd16_loop              30             35             44             49             39             29
  dot                     55             60             64             68             62             54
  reduce                  50             54             50             71             58             51
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
counts are within 30% everywhere and CCV is *lower* on seven of eight:

| | vadd | saxpy | vadd16 | vadd_loop | vadd16_loop | dot | reduce | transpose |
|---|---|---|---|---|---|---|---|---|
| CCV | 23 | 22 | 26 | 27 | 30 | 55 | 50 | 87 |
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
    vadd                  512            464            864           1024           1024            368
    saxpy                 544            400            736            896            896            336
    vadd16                576            464            864           1024           1024            368
    vadd_loop             272             --             --             --             --             --
    vadd16_loop            336             --             --             --             --             --
    transpose            2528           1024           1920           2432           2432            992
  instr bytes / 1K elem
    vadd                 1792           2432           5248           5888           6144           2240
    saxpy                1856           2176           4352           4992           5248           1984
    vadd16               1984           2432           5376           6016           6272           2240
    vadd_loop             264             --             --             --             --             --
    vadd16_loop            296             --             --             --             --             --
    transpose            9280           4928           9856          12032          11904           4800
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

So the feature is not yet earning its instructions on this shape. The kernel
that would show a win is one where a thread handles two adjacent 16-bit
elements in a single 32-bit lane; that is what the packed form exists for, and
no benchmark kernel does it. Recorded as F-79.

#### What amortizes, and what does not

`vadd16` is straight-line: one element per thread, every width transition and
every argument load paid once per element. That measures the **prologue** and
calls it the kernel. A real 16-bit kernel runs many elements per thread, and the
expectation — reasonably — is that the width-handling overhead approaches zero
as iterations grow. `vadd_loop` and `vadd16_loop` are the same two kernels with
a grid-stride loop, measured on the simulator across iteration counts:

| elements/thread | `vadd_loop` issues/elem | `vadd16_loop` issues/elem |
|---|---|---|
| 1 | 19.00 | 21.00 |
| 2 | 13.00 | 15.00 |
| 4 | 10.00 | 12.00 |
| 8 | 8.50 | 10.50 |
| 16 | 7.75 | 9.75 |
| 32 | 7.38 | 9.38 |
| **∞ (loop body)** | **7** | **9** |

Both fit `issues = 12 + iterations × body` exactly, so the prologue is 12
instructions and amortizes away cleanly. **The width overhead does not.** The
gap between the two columns is 2.0 instructions per element at every iteration
count, and as a *fraction* it gets worse as the prologue amortizes — 10.5% at
one element per thread, **22% in steady state**.

The steady-state loop bodies say why:

```
vadd_loop (f32), 7 per element        vadd16_loop (i16), 9 per element
  ld.global r6, [r2, r1, 1, 0]          chwidth.multi 192, 1        <-- overhead
  ld.global r7, [r3, r1, 1, 0]          ld.global r6, [r3, r1, 1, 0]
  fadd r7, r6                           ld.global r7, [r2, r1, 1, 0]
  st.global r7, [r4, r1, 1, 0]          add r6, r7, r6
  add r1, r0                            st.global r6, [r4, r1, 1, 0]
  setp.lt.u p0, r1, r5                  chwidth r6, 0               <-- overhead
  @p0 bra LBB0_1                        add r1, r0
                                        setp.lt.u p0, r1, r5
                                        @p0 bra LBB0_1
```

**The two width transitions are loop-carried and pure artifact.** `r6` and `r7`
are narrowed at the top of the body and `r6` is widened back at the bottom, so
that the width state at the back-edge matches the state at loop entry. Nothing
in the loop needs `r6` wide — the restore exists only to satisfy a fixed point
the dataflow chose. **Had the dataflow chosen "narrow at loop entry", both
transitions would hoist into the preheader and the body would be 7 instructions,
identical to the fp32 kernel.**

The compiler cannot make that choice today. `CCVInsertChwidth` hoists within a
block and stops at block entry — "hoisting across a block boundary would need
the dataflow to agree on every predecessor, which is a separate problem," as the
pass says of itself. For a straight-line kernel that ceiling costs nothing. For
a loop it converts a one-time cost into a per-iteration one, permanently.

**This is a compiler limitation, not an ISA property.** `chwidth` here is loop-
invariant and belongs in the preheader; nothing in §3 prevents that. Recorded as
F-87, with the payoff measured below.

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
  vadd              16         14       0   0.000        16.0   1.000x
  saxpy             17         15       0   0.000        17.0       --
  vadd16            18         14       4   0.286        16.0   1.000x
  vadd_loop         68         58       0   0.000        68.0       --
  vadd16_loop       84         58      32   0.552        68.0       --
  dot              122        101       0   0.000       122.0       --
  reduce           119         98       0   0.000       119.0       --
  transpose         79         72       0   0.000        79.0       --
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
enough for the retire rate to carry the feature on its own; the fraction has to
rise, which is F-79 (pack two elements per lane) and F-80 (stop spending
instructions on avoidable transitions).

#### Steady state, where the feature was supposed to pay

The straight-line break-even is not an artifact of the prologue. Applying the
same model to the loop bodies:

| | instrs/elem | narrow | cycles @2× | vs f32 |
|---|---|---|---|---|
| `vadd_loop` (f32) | 7 | 0 | 7.0 | 1.000× |
| `vadd16_loop` (i16), today | 9 | 4 | **7.0** | **1.000×** |
| `vadd16_loop`, with F-87 | 7 | 4 | **5.0** | **1.400×** |

**In steady state the narrow kernel is again exactly break-even** — the 2× retire
rate pays for the two loop-carried `chwidth` instructions and nothing else, the
same arithmetic as the straight-line case and for the same reason.

The third row is the point. Four of the nine instructions in that loop body are
narrow element work — two loads, the add, the store — which is a 44% narrow
fraction, well above `vadd16`'s 28.6%. **With the two loop-carried transitions
hoisted into the preheader, the body drops to seven instructions and the model
gives 5.0 cycles against fp32's 7.0: a 1.40× speedup per element.** That is the
return O-40 was designed to deliver, and it is currently being spent, in full,
on two instructions the compiler does not need to emit.

So the honest summary of the element-width model as it stands: **the ISA side
works and the compiler is giving the whole benefit back.** F-87 is the single
change with the largest measured payoff anywhere in this document.

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
  1x1   1          182     4992    27.4      37     16   2.31      23%
  1x2   2          261     7136    27.3      61     32   1.91      23%
  2x2   4          382    10304    27.0     102     64   1.59      24%
  2x4   8          639    17008    26.6     186    128   1.45      12%
  4x4   16        1118    29296    26.2     407    256   1.59      14%
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

- **A kernel that packs two narrow elements into one lane.** `vadd16` is now in
  the tables, and it shows the narrow-width model costing two instructions and
  returning nothing in issue count — because at one element per thread there is
  no packing to exploit. The kernel that would show a win puts two adjacent
  16-bit elements in a single 32-bit lane, halving the issue count for the same
  element count. No benchmark kernel does that, so the tables currently show the
  cost of O-6's element model and none of its benefit. F-79.

- **Dynamic counts for the reduction kernels, work-normalized.** The work table
  covers four of six kernels. `dot` and `reduce` are excluded because a thread
  consumes several elements and then joins a tree reduction, so there is no
  constant elements-per-thread, and both loop on both machines. Getting them in
  needs either an AMD simulator or an argument that their loop trip counts match.
