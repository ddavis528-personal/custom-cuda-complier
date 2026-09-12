# CCG — TableGen machine description

Target description for the ISA in
[`../../docs/isa-v1.4-operation-map-and-encoding.md`](../../docs/isa-v1.4-operation-map-and-encoding.md).

`CCG` is a placeholder name. Renaming is mechanical — the string appears only as
a namespace and a def prefix:
`git grep -l CCG | xargs sed -i 's/CCG/<NewName>/g' && git mv llvm/CCG llvm/<NewName>`.

## What is here

| File | Contents |
|---|---|
| `CCG.td` | top-level target |
| `CCGRegisterInfo.td` | GPRs, predicates, register classes |
| `CCGInstrFormats.td` | one class per §3 bit map — the transcription of the spec |
| `CCGInstrInfo.td` | instruction definitions |

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
disassembler — and `ccg-roundtrip`.

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

Current state: **0 errors, 0 invariant-8 deviations, 4160/4160 round trips
clean** across 25 compressed, 36 32-bit and 4 48-bit instructions. The three Format B′/B″
deviations this description originally surfaced were genuine and are fixed in ISA
v1.4 (O-22); the spec and this description now agree, and `verify.sh` is what
proves it.

## Coverage

65 instructions, at least one per format, plus everything the §5.5 worked
prologue needs. This is deliberately not full opcode-map coverage: the goal is
to exercise every *encoding shape*, since that is what the checks test. Opcode
points not fixed by the spec are marked `ASSIGNED` in `CCGInstrInfo.td`.

## Not here yet

- **No asm parser.** `ccg-roundtrip` drives `MCInst`s programmatically rather
  than parsing text, so `-gen-asm-matcher` is not yet wired up. Programmatic
  round-tripping is the stronger ISA check — 64 randomized operand sets per
  instruction cover far more of the encoding space than hand-written assembly
  would — but text assembly is still wanted, and is the next MC increment.
- **No object emission.** No `MCAsmBackend`, no ELF writer, no streamer. Nothing
  needs them until there is codegen to emit.
- **No instruction selection.** Step 3.
- **`chwidth`=4 has no value type.** LLVM has no `v32i4` MVT, so `GPR` carries
  `v32i32`/`v32i16`/`v32i8` only. Deferred; it affects nothing until 4-bit
  kernels exist.
- **R16–R31 are defined but unallocatable.** Not an oversight — see roadmap
  F-12. A 32-GPR machine is a different encoding, not a subtarget flag, so
  `GPR` cannot simply be widened here.
