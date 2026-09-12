# Custom CUDA-Compatible Compiler

LLVM backend targeting a custom GPU-class native ISA, with the compatibility
contract held at the **PTX / CUDA Runtime API level** rather than at the
hardware ISA level. The native ISA carries no PTX or SASS encoding constraints;
this compiler is the bridge.

Companion to the processor design work. This repository holds the compiler
only — the ISA specification lives here as the design contract, not as
generated documentation.

## Documents

| File | Role |
|---|---|
| [`docs/isa-v1.3-operation-map-and-encoding.md`](docs/isa-v1.3-operation-map-and-encoding.md) | **Current.** Ground truth for encoding. Formats, opcode maps, execution environment and launch ABI, design invariants, open items. |
| [`docs/isa-v1.2-operation-map-and-encoding.md`](docs/isa-v1.2-operation-map-and-encoding.md) | Superseded by 1.3. Kept for the decision trail. |
| [`docs/backend-context.md`](docs/backend-context.md) | Ground truth for *why the backend is built the way it is*. Target strategy, bring-up phasing, the open ISA items that compiler output is meant to resolve. |
| [`docs/roadmap.md`](docs/roadmap.md) | Bring-up plan, sequencing, and the ISA findings that the compiler-side review has surfaced so far. |

Read the ISA spec for encoding questions and the backend context for scope
questions. `roadmap.md` tracks what is actually being built next and what the
build is expected to prove.

## Strategy

- **Frontend:** clang's existing CUDA frontend, unmodified. Device code is
  lowered to NVVM-flavoured LLVM IR and retargeted; no CUDA parser is written
  here.
- **Backend:** custom LLVM target (TableGen description, ISel, register
  allocation, scheduling, MC layer) emitting the native ISA.
- **Success criterion:** a validated pipeline that generates real signal for
  open ISA decisions. Coverage is explicitly not the near-term goal.

## Status

Phase 0 complete — no ISA question blocks backend work. ISA v1.3 incorporates
every finding from the first compiler-side pass; the proposals behind each are
in `docs/proposals/`. Next is the TableGen machine description and MC layer.
See `docs/roadmap.md`.
