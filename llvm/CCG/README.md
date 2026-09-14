# CCG — TableGen machine description

Target description for the ISA in
[`../../docs/isa-v1.5-operation-map-and-encoding.md`](../../docs/isa-v1.5-operation-map-and-encoding.md).

`CCG` is a placeholder name. Renaming is mechanical — the string appears only as
a namespace and a def prefix:
`git grep -l CCG | xargs sed -i 's/CCG/<NewName>/g' && git mv llvm/CCG llvm/<NewName>`.

## What is here

**Machine description (TableGen):**

| File | Contents |
|---|---|
| `CCG.td` | top-level target |
| `CCGRegisterInfo.td` | GPRs, predicates, register classes |
| `CCGInstrFormats.td` | one class per §3 bit map — the transcription of the spec |
| `CCGInstrInfo.td` | instruction definitions |
| `CCGInstrPatterns.td` | ISel patterns |
| `CCGCallingConv.td` | calling convention |

**Codegen:** `CCGTargetMachine`, `CCGSubtarget`, `CCGISelLowering`,
`CCGISelDAGToDAG`, `CCGInstrInfo`, `CCGRegisterInfo`, `CCGFrameLowering`,
`CCGAsmPrinter`, `CCGTargetTransformInfo` (warp-scoped divergence — LLVM's stock
NVPTX answer calls `ctaid` divergent, which is right across a grid and wrong
across a warp).

**Target-specific passes**, each with a finding behind it:

| Pass | Why |
|---|---|
| `CCGLowerShared` | §5.1 makes `.shared` flat 32-bit, so layout is the whole lowering (F-31) |
| `CCGExpandDivision` | no divide in §4 and no runtime library; float-reciprocal sequence (O-31) |
| `CCGUniformity` | reports what O-25 asked for; buckets what cannot be masked, and why (F-57) |
| `CCGWindowRemat` | clones §5.1 window chains per block so the addressing DAGCombine sees them locally (F-32) |
| `CCGMaskUniform` | runs warp-uniform work on lane 0 and broadcasts (O-33) |
| `CCGExpandPseudos` | predicate registers become qualifier immediates, post-RA |
| `CCGCompress` | Format K compression of what already satisfies `rd == rs0` (O-29) |
| `CCGCheckIR` | diagnoses what invariant 11 forbids rather than miscompiling it (F-22) |

**MC layer:** `MCTargetDesc/` — code emitter, instruction printer, asm backend
with branch relaxation (F-28) and an ELF object writer; `Disassembler/`.

`CCGInstrFormats.td` is the load-bearing file. Every `let Inst{hi-lo} =` is a row
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

Builds `libCCGMC.a` — target registration, code emitter, instruction printer,
disassembler — plus `ccg-llc` (the compiler), `ccg-sim` (the simulator),
`ccg-roundtrip`, and `CCGLowerKernelArgs.so`, an opt plugin that rewrites kernel
arguments into launch-block loads (§5.2).

## Verifying

```
tools/verify.sh
```

Runs every TableGen backend, then `tools/check-encoding.py`, then the round trip
if `build/ccg-roundtrip` exists.

The checks are complementary:

- **TableGen** rejects a double-assigned bit, and `-gen-disassembler` fails if
  the encoding is not uniquely decodable. That second one is the real prize —
  it is not a property anyone establishes by reading bit maps.
- **`check-encoding.py`** rejects what TableGen does not look for: gaps
  (unassigned bits), a length/class field disagreeing with the instruction size,
  and any field sitting off its invariant-8 canonical position.
- **`ccg-roundtrip`** builds an `MCInst` per instruction with random operands
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
`ASSIGNED` in `CCGInstrInfo.td`.

## Not here yet

- **No MC asm parser.** `ccg-roundtrip` drives `MCInst`s programmatically rather
  than parsing text, so `-gen-asm-matcher` is not wired up. `tools/ccg-as.py` is
  a minimal assembler driven from the same TableGen JSON, and `verify.sh` checks
  it against the generated encoder — two independent encoders agreeing. A real
  parser is still wanted; nothing is blocked on it.
- **`chwidth`=4 has no value type.** LLVM has no `v32i4` MVT, so `GPR` carries
  `v32i32`/`v32i16`/`v32i8` only. Deferred; it affects nothing until 4-bit
  kernels exist.
- **No `chwidth` insertion pass.** The F-3 pass, and the one piece of Step 6 not
  started. `chwidth`/`chwidth.multi` are encodable and nothing emits them.
- **No scheduler.** `mayLoad`/`mayStore` are set correctly (F-50) so one could be
  enabled, but none is, and the dynamic counts assume in-order issue.
- **32 GPRs are gone, not disabled.** `GPRC` and R16–R31 were removed outright
  when O-25 settled the count at 16 — a 32-GPR machine is a different encoding,
  not a subtarget flag. See roadmap F-12.
