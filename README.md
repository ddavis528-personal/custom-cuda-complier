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
| [`docs/isa-v1.5-operation-map-and-encoding.md`](docs/isa-v1.5-operation-map-and-encoding.md) | **Current.** Ground truth for encoding. Formats, opcode maps, execution environment and launch ABI, design invariants, open items. |
| [`docs/isa-v1.3-operation-map-and-encoding.md`](docs/isa-v1.3-operation-map-and-encoding.md) | Superseded by 1.4. Kept for the decision trail. |
| [`docs/isa-v1.2-operation-map-and-encoding.md`](docs/isa-v1.2-operation-map-and-encoding.md) | Superseded by 1.3. |
| [`llvm/CCG/`](llvm/CCG/) | TableGen machine description. `tools/verify.sh` checks it against the invariants above. |
| [`docs/backend-context.md`](docs/backend-context.md) | Ground truth for *why the backend is built the way it is*. Target strategy, bring-up phasing, the open ISA items that compiler output is meant to resolve. |
| [`docs/walkthrough.md`](docs/walkthrough.md) | **Start here.** One kernel traced from CUDA source through IR, assembly, binary, disassembly and execution, with every listing generated rather than transcribed. |
| [`docs/64-bit-addressing-summary.md`](docs/64-bit-addressing-summary.md) | How 64-bit addressing is specified, lowered and verified — self-contained, for the architecture track. |
| [`docs/compiler-findings-summary.md`](docs/compiler-findings-summary.md) | Standalone summary of what the compiler work found about the ISA, written for the architecture track. |
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

**Phase 1 complete** — a CUDA kernel compiles from source and executes
correctly on the simulator (`tools/run-e2e.sh`;
[walkthrough](docs/walkthrough.md)). Phase 0 before it settled every ISA
question that blocked backend work. ISA v1.3 incorporates
every finding from the first compiler-side pass; the proposals behind each are
in `docs/proposals/`. Next is the TableGen machine description and MC layer.
See `docs/roadmap.md`.
