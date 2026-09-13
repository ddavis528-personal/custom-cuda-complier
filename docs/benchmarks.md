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
  kernel        CCG    CCGb   b/i  align    alnb    GCN    GCNb   b/i    PTX
  ----------------------------------------------------------------------------
  vadd           24      80  26.7     17      58     29     152  41.9     21
  saxpy          23      76  26.4     18      60     25     136  43.5     19
  dot            61     192  25.2     53     166     60     300  40.0     46
  reduce         56     174  24.9     50     156     54     268  39.7     41
  transpose     143     482  27.0    137     464     64     308  38.5     43
```

`CCG`/`CCGb` are instructions and bytes with ordinary unaligned pointers — the
general case. `align` is the same kernel with O-23's alignment attribute. `GCN`
is AMD gfx900, instructions and bytes both taken from the **assembled object**,
because GCN mixes 4- and 8-byte encodings and a line count of the `.s` would say
nothing about size.

### Density: 25–27 bits per instruction against GCN's 38–44

This is the headline and it holds across every kernel: **CCG encodes at roughly
0.62× the bits per instruction of a real contemporary GPU ISA.** The variable
16/32/48 encoding is doing what §6 claimed it would.

### The control that matters: instruction counts are comparable

A denser encoding that needs twice the instructions has gained nothing. On four
of five kernels the counts are within 20%, and on two of them CCG is *lower*:

| | vadd | saxpy | dot | reduce |
|---|---|---|---|---|
| CCG | 24 | 23 | 61 | 56 |
| GCN | 29 | 25 | 60 | 54 |

So the density is not bought with instruction count. **Code size lands at
roughly half**: 80 vs 152 bytes on `vadd`, 76 vs 136 on `saxpy`, 174 vs 268 on
`reduce`. With the alignment attribute, `vadd` is 58 bytes against 152 — 2.6×.

Two structural reasons, both already in the design record rather than
discovered here: GCN carries 64-bit pointers in register pairs, where invariant
11 keeps addresses out of registers entirely (§5.1); and GCN's scalar/vector
split costs `s_waitcnt` and `s_and_saveexec` instructions that a per-thread-PC
machine does not need (§1).

### `transpose` is the exception, and it is not an ISA result

143 instructions against GCN's 64. The whole difference is **integer division**:
`transpose` divides by a runtime value twice, and the two compilers expand it
very differently.

| | approach | shape |
|---|---|---|
| CCG | LLVM's generic shift-subtract | ~35 instructions **plus a loop of up to 32 iterations** |
| GCN | float reciprocal — `v_cvt_f32_u32`, `v_rcp_iflag_f32`, `v_mul_f32`, `v_cvt_u32_f32`, Newton correction | ~10 instructions, straight-line |

The ISA is not the limitation: §4 has `fmul`, and points 128+ are conversions.
This is a compiler choice that has not been made yet. It costs more dynamically
than statically — a 32-iteration loop against ten straight-line instructions —
so the static row understates it. See **F-48**.

---

## 3. GEMM: where the register file binds

`tools/sweep-tiles.sh`, on the tiled SGEMM with a TM×TN per-thread accumulator
tile:

```
  tile  accs    instrs     bits b/instr  spills    fma sp/fma    K-hit
  1x1   1          204     5584    27.4      35     16   2.19      23%
  1x2   2          293     7936    27.1      60     32   1.88      22%
  2x2   4          397    10640    26.8      88     64   1.38      21%
  2x4   8          653    17312    26.5     174    128   1.36      17%
  4x4   16        1169    30800    26.3     420    256   1.64      16%
```

`sp/fma` — memory traffic the register file forced, per unit of arithmetic it
bought — has a **minimum at 2×4** and rises again at 4×4, where sixteen
accumulators are the whole file and everything else spills. At 16 GPRs the
practical ceiling is 2×4, which is what §1 guessed before there was anything to
measure.

Density holds up under pressure: 26.3–27.4 bits per instruction across a 6×
range of kernel size.

**The compressed-form hit rate falls as pressure rises** — 23% at 1×1 to 16% at
4×4. Register pressure and Format K compression work against each other, because
the allocator lands `rd == rs0` less often when it has less freedom. O-29's
proposed "bias allocation toward the tie" would therefore be worth least exactly
where code size matters most.

---

## 4. What would strengthen this

- **SASS.** The comparison the project's density argument is actually written
  against, and the one missing. Needs `ptxas`.
- **Dynamic counts.** The simulator already counts issue groups; wiring that
  into the benchmark would turn instruction count from a proxy into a
  measurement, and would make the `transpose` division result ten times more
  damning than it looks statically.
- **More kernels, and unfriendly ones.** Five kernels with regular control flow
  is a narrow base. Anything branch-heavy or with irregular access would test
  the parts of the encoding these do not reach.
- **RVC as a second density reference.** RISC-V's compressed extension is the
  closest published analogue to the 16/32 mix, and `riscv64` is available in
  this toolchain — though a scalar CPU comparison needs its own argument about
  what is comparable.
