# Proposal — The device-function calling sequence (F-21, F-22)

**Status:** proposed 2026-10-19; direct calls built the same day (§7). The compiler-side
mechanics (§2–§5) are CP's. Two choices are ABI decisions and wait on IS or Daniel: §6's callee-saved set and
§4's link-value definition. Each is one line to change, and is built provisionally as
recommended here.
**Addresses:** F-21 and F-22 in `../roadmap.md`. AR-20 (CoreMark) waits on this.
**Companion:** `pointer-representation.md` (CP-3: a pointer in memory).

---

## 1. What is missing, verified in the tree

| Piece | State |
|---|---|
| `call rd, off` (Format E `00010`), `ret rs` (Format K 53) | encoded, assembled and round-tripped; **nothing selects them** |
| `LowerFormalArguments`, `LowerReturn`, `CC_CCV` / `RetCC_CCV` | exist: arguments in R1–R6, then the stack; returns in R1–R2 |
| `LowerCall` | **absent**: any call that clang does not inline aborts |
| A value-returning `ret` | `report_fatal_error` at `CCVISelDAGToDAG.cpp` (the `CCVISD::RET` case) |
| `CSR_CCV` | `(add)`: empty, so every live value is spilled at every call site |
| A pointer argument | refused by `CCVCheckIR` (`test/reject/ptr-in-call.ll`), F-22 |
| `ccv-sim` | executes **neither** `call` nor `ret` |
| A stack | **none**. R15 holds the thread's `.local` **window index** (O-30), not a byte pointer |

The last row decides the shape of everything else. A conventional stack bumps a byte
pointer on entry and exit. R15 cannot be bumped by bytes, because R15 + 1 is the next
thread's window. Frames also cannot advance a window per call depth, because thread
t's window is `local_base + t`, so depth d of thread t would land on thread t + d's frame.

## 2. Frames: a static, whole-program layout, with no stack pointer

A CUDA kernel without `-rdc` is one module: every device function and every call to it is
visible at once. So each function's frame can be placed at a **fixed offset in the
thread's window**, chosen at compile time. This is the compiled-stack scheme of
small-RAM microcontrollers, and it fits this machine for the same reason: the address
space for frames is plentiful and the registers are not.

- **Placement.** A leaf's frame starts at offset 0. A caller's frame starts above the
  highest frame any callee reaches: `base(f) = max over callees g of (base(g) + size(g))`.
  Siblings overlap, which is correct because they are never live together.
- **Cost.** Nothing at run time. R15 is set once in the kernel prologue, exactly as now, and
  no function touches it. A spill stays one `st.global [R15 + off]`. There is no
  prologue or epilogue adjustment, and no register beyond R15.
- **Reach.** Format D's 13-bit signed displacement reaches 4 KiB at one sign. The frames
  of the deepest call chain must fit in that, or the compiler diagnoses it. CoreMark's
  deepest chain spills a few hundred bytes at most. Its 2 KB `stack_memblock` is a
  `main` local, which the port moves to global memory, as every GPU port does.
- **Recursion** is refused with a diagnostic. A cycle in the call graph has no static
  layout. Neither CoreMark nor any kernel in the corpus recurses.
- **Indirect calls** are treated as calling every address-taken function whose type
  matches. That set is known in a closed module.

**Compiler mechanics.** LLVM emits callees before callers when IPRA ordering is on, so a
caller's callee frame sizes are known when its own frame indices are eliminated. An
indirect callee may not have been emitted yet. In that case the frame base is a
symbolic constant the assembler resolves after all functions are emitted
(`.set __ccv_frame_f, …`). That is ordinary MC fixup work, and it is the fallback whenever
the order is unknown.

## 3. Arguments and returns

These are unchanged from what `CC_CCV` already says: R1–R6 for `i32`/`f32`, the rest on the
callee's frame (static, so a caller writes the outgoing argument at the callee's known
base), returns in R1–R2. `i1`/`i8`/`i16` are promoted. Kernels stay as they are: their
arguments are launch-block loads (§5.2), and this convention covers device functions only.

**Pointers (F-22).** A pointer crosses a call as **two i32 values, `(rbase, roffset)`**,
in consecutive argument registers, or R1:R2 for a returned pointer. That is exactly the
pair the AGU consumes, so invariant 11 holds: no register holds a 48-bit address, and
the pair is formed and consumed the way a kernel pointer argument already is. A
module pass rewrites each pointer parameter of an internal function into the pair:

- the callee rebuilds `inttoptr((zext rbase << 16) + zext roffset)`, the form
  `CCVLowerKernelArgs` already produces and the address combine already matches;
- the caller decomposes its pointer into that same pair, which is what it was built from.

`roffset` is the unnormalized in-window offset, so the pair inherits F-23's
one-allocation precondition. A pointer read from **memory** is CP-3's representation
(flat 64-bit, split into a pair on load), and it becomes this pair once in registers. This
is built in `CCVPointerPairs`, which runs before `CCVCheckIR`. A pointer it cannot split is
still diagnosed, as is a call to a function the module only declares (`ptr-in-call.ll`).

## 4. Call, return, and the link register

- **The link register is R14 by convention.** `call.short` uses it implicitly, per §3's
  compressed-form paragraph, which names "the ABI-conventional link register" without
  fixing it. This fixes it.
- **The return address is a live-in value, not a reserved register.** A function copies
  R14 into a virtual register at entry and returns through it with `ret`. A leaf keeps
  it in R14 at no cost. A non-leaf gets the allocator's choice: another register
  (§3's "`call R14, f` inside `call R13, g`, with no spill at all" falls out by itself) or
  a spill when pressure says so. It goes back into R14 for the `ret`: the epilogue restores
  callee-saved registers just before the return, so a link value left in one of them would
  be overwritten by the caller's value first. A leaf pays nothing for this; a function that
  calls pays at most one `mov`. R14 is otherwise an ordinary caller-saved register.
- **What `call` writes, and what `ret` reads: ruled in ISA v1.8 §3 Format E (3013036).**
  `call` writes **the low 32 bits of the next instruction's address**, and `ret rs` sets
  each lane's PC to `{PC[47:32] of the ret, rs}`, a concatenation under the ret's own
  aligned 4 GiB code window, which holds a kernel's image and everything it calls. No
  image base reaches RCU or OOE and no adder is needed (AR-22), and a function pointer
  is its low 32 bits, fixed at link time. Code addresses are not data addresses, so
  invariant 11, now scoped to data addresses, is untouched. The row history: CP first
  built an image offset, IS first wrote a zero-extended absolute address, and AR's
  concatenation is the form under which both coincide.
- **Indirect calls need no new instruction.** A function pointer is a code address, a
  `movi` of a relocated constant. An indirect call is a `call R14, stub` to a one-instruction
  local stub `ret rF`, where rF holds the target: `call` sets the link register and `ret`
  jumps to the target. The cost is one extra redirect per indirect call. AR-20 already
  expects that, and flags the missing return-address predictor as the likely perf
  finding. A `call rd, rs` form would save the redirect if the trace says it matters.
- **Divergence.** PCs are per thread (§1), so the link value is per lane and `ret` is a
  per-lane indirect jump. A divergent call, or lanes returning to different sites after
  an indirect call, needs nothing more than a divergent branch does.

## 5. ccv-sim

**Built** (`test/call.s`, `run-tests.sh`). `call` writes the low 32 bits of `PC + Size`
to `rd` in every active lane and branches; `ret rs` sets each active lane's PC to
`{PC[47:32], rs}`, its own lane's. ccv-as
gained `@label`, a label's code address at the image's load address (0x1000, ccv-sim's
default), so the test can hand-write an indirect call. What remains of this section is for when the backend emits calls: The executed checks run a value-returning call, a
two-deep chain, an indirect call, a pointer argument and a callee-saved value across a
call against references. Each check is proved by mutation, per the gate's practice:
a wrong link value, a clobbered callee-saved register, or crossed pointer halves must
each fail.

## 6. The callee-saved set: the decision this needs

With 16 GPRs and R15 reserved, the choice is how many of the remaining 15 survive a call.

| Option | Callee-saved | Caller-saved | For | Against |
|---|---|---|---|---|
| A: none (today) | — | R0–R14 | simplest; a leaf never saves | every value live across a call spills at every call site; CoreMark would measure this choice, not the machine |
| **B: six (recommended)** | **R8–R13** | R0–R7 (args R1–R6), R14 (link) | loop counters and pointers in call-heavy loops (CoreMark's list walk, the matrix and state benchmarks) survive calls; a leaf uses R0–R7 and R14 and saves nothing | a non-leaf that needs more than 8 registers saves what it uses beyond them, into its static frame, one store per register |
| C: eight | R0, R7–R13 | R1–R6 (args), R14 (link) | the most a convention can keep without a callee preserving its own arguments | a leaf has only the six argument registers and R14 free; most CoreMark callees are small leaves, which would start saving |

**B, provisionally, plus IPRA.** RISC-V and AArch64 both settle near half the file callee-saved, and
B is the nearest equivalent for a file of 15. More important here: the module is closed,
so LLVM's interprocedural register allocation can use each **direct** callee's actual
clobber set instead of the convention. For direct calls the convention then matters only
at the recursion and indirect-call boundaries, and the CSR set governs mainly indirect calls
(CoreMark's comparators). The set is a `cl::opt` in the backend, so the CoreMark port can
sweep A, B and C (`-ccv-csr=none|six|eight`) and report spill transfers and instruction counts per option. **The
measurement decides the set; B is what is built until it does.**

## 6a. What building it found

Four defects, each of which compiled, assembled and ran, and computed the wrong answer.
Each is now a control in `tools/check-calls.sh` or a fix the check exercises.

- **Device functions were global ELF symbols**, so MC left every `call` as a relocation.
  The image is bare `.text`, so each call encoded offset 0 and fell through to the next
  instruction. `CCVInternalize` gives device functions internal linkage. Device code is one
  closed module, and only kernels are entry points.
- **O-33's lane-0 masking ran inside device functions.** It treated their arguments as
  launch-block values, so every lane got lane 0's answer. Masking is now off in device
  functions. In a kernel, a call result counts as divergent, and a call ends co-issue,
  because a callee's lanes return one group at a time after its own divergent branches.
- **The link value could sit in a callee-saved register**, which the epilogue restores just
  before `ret` (§4). It is copied back to R14 for the return.
- **A callee could return with a register still narrow.** Every GPR is now 32 bits wide at
  a call and at a return, and `CCVInsertChwidth` widens before each.

The kernel is no longer at image offset 0, because callees are emitted first. A launch
names its entry point, and `ccv-sim -entry` takes it.

## 7. Order of work

1. `ccv-sim`: `call` and `ret`, with the executed check and its mutations. **Done.**
2. `LowerCall`, the value-returning `RET`, R14 as a live-in, IPRA on, and `CSR_CCV` = B.
   **Done**, with the static frame layout and the recursion diagnostic from step 3.
   `tools/check-calls.sh` executes it.
3. Outgoing stack arguments (more than six). **Done** (2026-10-22). Argument k past the
   sixth sits at `-(base(callee) + 4k + 4)` below R15, the top of the callee's frame: the
   callee declares it as a fixed frame object, so its locals are laid out beneath, and the
   caller, which is compiled after the callee and so knows its base, stores to `[R15 + d]`
   directly. `check-calls.sh` executes nine arguments with a short among them, a function
   that passes stack arguments on while its own are live, and a pointer pair split across R6
   and the stack, with a control that writes them ignoring the callee's base.
4. F-22: pointer parameters as pairs. **Done** (`CCVPointerPairs`), returns included:
   pointers are read through, forwarded with an offset, and returned in `check-calls.sh`,
   with a control that drops the offset. `ptr-in-call.ll` stays a reject, because its
   callee is only declared, and a pointer the pass cannot split is still diagnosed.
5. Indirect calls via the `ret` stub.
6. The CoreMark port (AR-20), then the CSR sweep, which settles §6.

Steps 1–4 unblock the direct-call CoreMark kernels. Step 5 unblocks `core_list_mergesort`'s
comparators.
