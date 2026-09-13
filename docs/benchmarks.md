# Instruction density and instruction count, measured

**What this is:** a reproducible comparison of the CCG ISA against what can
actually be measured on this machine, with the things that cannot be measured
marked as such rather than estimated.

Run it with `tools/bench.py`. Every number below comes from that script.

---

## 1. Method, and what it is allowed to prove

Three targets, one source per kernel, one frontend:

| target | what it is | density claim? |
|---|---|---|
| **CCG** | this backend, via clang's CUDA frontend | yes |
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

```
  kernel        CCG    CCGb   b/i  align    alnb    GCN    GCNb   b/i    PTX  dyn/thr   SIMT
  --------------------------------------------------------------------------------------------
  vadd           24      80  26.7     17      58     29     152  41.9     21     17.0   100%
  saxpy          23      76  26.4     18      60     25     136  43.5     19     18.0   100%
  dot            61     192  25.2     53     166     60     300  40.0     46     91.9    65%
  reduce         56     174  24.9     50     156     54     268  39.7     41     88.9    64%
  transpose      83     294  28.3     77     274     64     308  38.5     43     77.0   100%
```

`CCG`/`CCGb` are instructions and bytes with ordinary unaligned pointers — the
general case. `align` is the same kernel with O-23's alignment attribute. `GCN`
is AMD gfx900, instructions and bytes both taken from the **assembled object**,
because GCN mixes 4- and 8-byte encodings and a line count of the `.s` would say
nothing about size. `dyn/thr` is lane-instructions per thread, **executed on the
simulator**; `SIMT` is lanes active per issue.

### Density: 25–28 bits per instruction against GCN's 38–44

This is the headline and it holds across every kernel: **CCG encodes at roughly
0.65× the bits per instruction of a real contemporary GPU ISA.** The variable
16/32/48 encoding is doing what §6 claimed it would.

### The control that matters: instruction counts are comparable

A denser encoding that needs twice the instructions has gained nothing. The
counts are within 30% everywhere and CCG is *lower* on two kernels:

| | vadd | saxpy | dot | reduce | transpose |
|---|---|---|---|---|---|
| CCG | 24 | 23 | 61 | 56 | 83 |
| GCN | 29 | 25 | 60 | 54 | 64 |

So the density is not bought with instruction count, and **code size lands
below GCN on every kernel** — 174 against 268 bytes on the reduction, 294
against 308 on the transpose. With the alignment attribute `vadd` is 58 bytes
against 152, which is 2.6×.

Two structural reasons, both from the design record rather than discovered here:
GCN carries 64-bit pointers in register pairs where invariant 11 keeps addresses
out of registers entirely (§5.1), and GCN's scalar/vector split costs
`s_waitcnt` and `s_and_saveexec` instructions that a per-thread-PC machine does
not need (§1).

### Static and dynamic agree — now

`vadd`, `saxpy` and `transpose` execute exactly their static aligned instruction
count, because they are straight-line. `dot` and `reduce` run about 1.7× their
static size, which is the reduction loop, and their SIMT efficiency of 64–65%
is the tree structure idling half the lanes each round.

**That agreement is new, and it is the reason this column exists.** Before
O-31, `transpose` was 143 static instructions and its two integer divisions
each cost a 32-iteration loop. The static number understated it by roughly
three times, and a benchmark that reported only static size would have called
the division problem a 2× gap when it was closer to 9×.

### The division result

Measured on the simulator, one `udiv`:

| | static | dynamic per thread | shape |
|---|---|---|---|
| shift-subtract (before) | 63 | **97.2** | loop, up to 32 iterations |
| float reciprocal (O-31) | 35 | **32.0** | straight-line |

`transpose` fell from 143 instructions and 482 bytes to 83 and 294. §4 had
reserved the conversion and SFU opcode ranges and left them empty; filling in
six points closed the entire gap. See O-31 for the algorithm and the one
constant that makes it exact.

---

## 3. GEMM: where the register file binds

`tools/sweep-tiles.sh`, on the tiled SGEMM with a TM×TN per-thread accumulator
tile:

```
  tile  accs    instrs     bits b/instr  spills    fma sp/fma    K-hit
  1x1   1          173     4832    27.9      31     17   1.82      16%
  1x2   2          256     7056    27.6      57     33   1.73      19%
  2x2   4          370    10000    27.0      89     65   1.37      17%
  2x4   8          629    16736    26.6     177    129   1.37      13%
  4x4   16        1142    30096    26.4     420    257   1.63      14%
```

`sp/fma` — memory traffic the register file forced, per unit of arithmetic it
bought — has a **minimum at 2×4** and rises again at 4×4, where sixteen
accumulators are the whole file and everything else spills. At 16 GPRs the
practical ceiling is 2×4, which is what §1 guessed before there was anything to
measure.

Density holds up under pressure: 26.4–27.9 bits per instruction across a 6.6×
range of kernel size.

**The compressed-form hit rate stays low and drifts down under pressure** —
19% at 1×2 down to 13–14% at the largest tiles. Register pressure and Format K compression work against each other, because
the allocator lands `rd == rs0` less often when it has less freedom. O-29's
proposed "bias allocation toward the tie" would therefore be worth least exactly
where code size matters most.

---

## 4. What would strengthen this

- **SASS.** The comparison the project's density argument is actually written
  against, and the one missing. Needs `ptxas`.
- **Dynamic counts for GCN.** CCG's are measured; AMD's are not, because there
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
