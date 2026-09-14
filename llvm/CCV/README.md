# CCV — TableGen machine description

Target description for the ISA in
[`../../docs/isa-v1.6-operation-map-and-encoding.md`](../../docs/isa-v1.6-operation-map-and-encoding.md).

**CCV — Custom CUDA Vector processing unit.** The name is settled. It appears as
the LLVM target name, a namespace, a def prefix and the tool prefix (`ccv-llc`,
`ccv-sim`, `ccv-roundtrip`); renaming is still mechanical if it ever needs to
change — `git grep -l CCV | xargs sed -i 's/CCV/<NewName>/g'`, then rename the
paths — but it should not need to.

It was `CCG` until the v1.5 audit, on a "G" for GPU that was never written down
anywhere and was wrong on the merits: this is a vector processing unit, not a
graphics part, and nothing in the ISA serves rasterization, texture or
fixed-function graphics.

## What is here

**Machine description (TableGen):**

| File | Contents |
|---|---|
| `CCV.td` | top-level target |
| `CCVRegisterInfo.td` | GPRs, predicates, register classes |
| `CCVInstrFormats.td` | one class per §3 bit map — the transcription of the spec |
| `CCVInstrInfo.td` | instruction definitions |
| `CCVInstrPatterns.td` | ISel patterns |
| `CCVCallingConv.td` | calling convention |

**Codegen:** `CCVTargetMachine`, `CCVSubtarget`, `CCVISelLowering`,
`CCVISelDAGToDAG`, `CCVInstrInfo`, `CCVRegisterInfo`, `CCVFrameLowering`,
`CCVAsmPrinter`, `CCVTargetTransformInfo` (warp-scoped divergence — LLVM's stock
NVPTX answer calls `ctaid` divergent, which is right across a grid and wrong
across a warp).

**Target-specific passes**, each with a finding behind it:

| Pass | Why |
|---|---|
| `CCVLowerShared` | §5.1 makes `.shared` flat 32-bit, so layout is the whole lowering (F-31) |
| `CCVExpandDivision` | no divide in §4 and no runtime library; float-reciprocal sequence (O-31) |
| `CCVUniformity` | reports what O-25 asked for; buckets what cannot be masked, and why (F-57) |
| `CCVWindowRemat` | clones §5.1 window chains per block so the addressing DAGCombine sees them locally (F-32) |
| `CCVMaskUniform` | runs warp-uniform work on lane 0 and broadcasts (O-33) |
| `CCVExpandPseudos` | predicate registers become qualifier immediates, post-RA |
| `CCVCompress` | Format K compression of what already satisfies `rd == rs0` (O-29) |
| `CCVCheckIR` | diagnoses what invariant 11 forbids rather than miscompiling it (F-22) |

**MC layer:** `MCTargetDesc/` — code emitter, instruction printer, asm backend
with branch relaxation (F-28) and an ELF object writer; `Disassembler/`.

`CCVInstrFormats.td` is the load-bearing file. Every `let Inst{hi-lo} =` is a row
of a §3 table, and field positions are architectural (invariant 8) rather than
stylistic. Do not tidy them.

## Building

```
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

Out-of-tree against an installed LLVM 18 — the target is not registered with
LLVM's build system, so TableGen is invoked directly and the generated `.inc`
files land in `build/generated/`. Needs `llvm-18-dev` (for
`llvm/Target/Target.td`; `llvm-tblgen` alone is not enough) and `libzstd-dev`
(LLVMSupport's link interface requires it).

Builds `libCCVMC.a` — target registration, code emitter, instruction printer,
disassembler — plus `ccv-llc` (the compiler), `ccv-sim` (the simulator),
`ccv-roundtrip`, and `CCVLowerKernelArgs.so`, an opt plugin that rewrites kernel
arguments into launch-block loads (§5.2).

## Verifying

```
tools/verify.sh
```

Runs every TableGen backend, then `tools/check-encoding.py`, then the round trip
if `build/ccv-roundtrip` exists.

The checks are complementary:

- **TableGen** rejects a double-assigned bit, and `-gen-disassembler` fails if
  the encoding is not uniquely decodable. That second one is the real prize —
  it is not a property anyone establishes by reading bit maps.
- **`check-encoding.py`** rejects what TableGen does not look for: gaps
  (unassigned bits), a length/class field disagreeing with the instruction size,
  and any field sitting off its invariant-8 canonical position.
- **`ccv-roundtrip`** builds an `MCInst` per instruction with random operands
  that fill their encoded fields, encodes it, decodes the bytes back, and
  requires a match. The encoder and the disassembler are produced by *different*
  TableGen backends from the same description, so a disagreement means the
  encoding is ambiguous or the tables are inconsistent. 64 operand sets per
  instruction by default; `-trials`, `-seed` and `-v` are available.

Current state: **0 errors, 0 invariant-8 deviations, 13376/13376 round trips
clean** across 209 instructions. The three Format B′/B″ deviations this
description originally surfaced were genuine and are fixed in ISA v1.4 (O-22);
the spec and this description now agree, and `verify.sh` is what proves it.

## Coverage

209 instructions, at least one per format and per predicated tier. This is still
not full opcode-map coverage — §4's conversion matrix and most of the SFU range
exist in the spec and not here — but every *encoding shape* is exercised, which
is what the checks test. Opcode points not fixed by the spec are marked
`ASSIGNED` in `CCVInstrInfo.td`.

## Not here yet

- **No MC asm parser.** `ccv-roundtrip` drives `MCInst`s programmatically rather
  than parsing text, so `-gen-asm-matcher` is not wired up. `tools/ccv-as.py` is
  a minimal assembler driven from the same TableGen JSON, and `verify.sh` checks
  it against the generated encoder — two independent encoders agreeing. A real
  parser is still wanted; nothing is blocked on it.
- **`chwidth`=4 has no value type.** LLVM has no `v32i4` MVT, so `GPR` carries
  `v32i32`/`v32i16`/`v32i8` only. Deferred; it affects nothing until 4-bit
  kernels exist.
- **`chwidth` insertion is built** (`CCVInsertChwidth.cpp`, post-RA). Forward
  width dataflow over physical registers, transitions placed at definitions, and
  — since F-87 — on CFG **edges** where predecessors disagree, which is what
  keeps a loop-invariant width change out of a loop body. Runs of the same width
  merge into `chwidth.multi` (O-6). Two flags: `-ccv-chwidth-cross-block=false`
  restores the intra-block placement, `-ccv-chwidth-stats` reports where every
  transition went and why.
- **Width affinity lives in the allocation order.** `GPR16` allocates descending
  where `GPR` allocates ascending — the same sixteen registers, opposite
  preference — so narrow and wide values cluster apart and a register does not
  change width mid-loop. It is the only width signal the allocator has, since
  `chwidth` names physical registers and width is otherwise post-RA (F-80).
- **No scheduler.** `mayLoad`/`mayStore` are set correctly (F-50) so one could be
  enabled, but none is, and the dynamic counts assume in-order issue.
- **32 GPRs are gone, not disabled.** `GPRC` and R16–R31 were removed outright
  when O-25 settled the count at 16 — a 32-GPR machine is a different encoding,
  not a subtarget flag. See roadmap F-12.
