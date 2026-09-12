# CCG — TableGen machine description

Target description for the ISA in
[`../../docs/isa-v1.3-operation-map-and-encoding.md`](../../docs/isa-v1.3-operation-map-and-encoding.md).

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

## Verifying

```
tools/verify.sh
```

Runs every TableGen backend and then `tools/check-encoding.py`. Requires
`llvm-18-dev` (for `llvm/Target/Target.td`); `llvm-tblgen` alone is not enough.

The checks are complementary:

- **TableGen** rejects a double-assigned bit, and `-gen-disassembler` fails if
  the encoding is not uniquely decodable. That second one is the real prize —
  it is not a property anyone establishes by reading bit maps.
- **`check-encoding.py`** rejects what TableGen does not look for: gaps
  (unassigned bits), a length/class field disagreeing with the instruction size,
  and any field sitting off its invariant-8 canonical position.

Current state: **0 errors, 3 invariant-8 deviations**, all three in Format B′/B″
and all three genuine — see roadmap F-14.

## Coverage

65 instructions, at least one per format, plus everything the §5.5 worked
prologue needs. This is deliberately not full opcode-map coverage: the goal is
to exercise every *encoding shape*, since that is what the checks test. Opcode
points not fixed by the spec are marked `ASSIGNED` in `CCGInstrInfo.td`.

## Not here yet

- **No C++ MC layer.** The generated `.inc` files are produced and validated but
  not compiled into an `MCTargetDesc`. That is the next increment and needs the
  target registration scaffolding.
- **No instruction selection.** Step 3.
- **`chwidth`=4 has no value type.** LLVM has no `v32i4` MVT, so `GPR` carries
  `v32i32`/`v32i16`/`v32i8` only. Deferred; it affects nothing until 4-bit
  kernels exist.
- **R16–R31 are defined but unallocatable.** Not an oversight — see roadmap
  F-12. A 32-GPR machine is a different encoding, not a subtarget flag, so
  `GPR` cannot simply be widened here.
