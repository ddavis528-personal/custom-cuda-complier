# Proposal — Launch ABI via a Memory-Resident Launch Block

**Status:** direction settled (memory-resident launch block, implemented as
memory-mapped registers). This records what that collapses, what it leaves, and
the two things it must not be.
**Addresses:** F-1a (partly), F-1b, F-1c in `../roadmap.md`.

---

## 1. What the decision settles

A CTA-private block of read-only memory, populated by the launch mechanism,
carrying the launch parameters and the kernel arguments in one contiguous layout.
Three of the four F-1 gaps close at once, and **none of them costs an opcode**:

| Gap | Resolution |
|---|---|
| F-1a, uniform half — `%ntid`, `%ctaid`, `%nctaid`, grid dims | ordinary loads from fixed offsets in the block |
| F-1b — kernel arguments, no `.param` equivalent | arguments are part of the same block, after the launch header |
| F-1c — entry register state | dissolves; see §3 |

The whole surface reduces to "the prologue loads from a known address." That is
the right shape for a machine whose ISA has deliberately stayed clear of ABI
(explicit link registers over a hardware call stack, §3 Format E).

## 2. What it cannot settle — MMIO supplies values, not identity

The limit is structural, not an implementation detail:

> A memory location can supply any value that is **uniform across its readers**.
> It cannot supply a value that **distinguishes** its readers.

Launch parameters are CTA-uniform, so the block serves them perfectly. Thread
identity is by definition not uniform, so the block cannot serve it under any
implementation:

- **`%laneid`** — 32 lanes read one address and must get 32 different values.
- **`%warpid`** — every warp in the CTA reads the same CTA-private block, so a
  single location cannot distinguish them. Reading a *different* address per warp
  requires already knowing which warp you are. Circular.
- **`%tid`** — follows from either of the above.

So exactly one irreducible primitive remains, and it must be an instruction (or a
structural wire), not a load.

**Minimal form: one flat per-thread index within the CTA.** Call it `%ctatid`,
in `[0, ntid.x·ntid.y·ntid.z)`. Everything else derives:

| Wanted | From `%ctatid` |
|---|---|
| `%laneid` | `T & 31` |
| `%warpid` | `T >> 5` |
| `%tid.x` (1-D block) | `T` — free |
| `%tid.x` (n-D) | `T % ntid.x` |
| `%tid.y` | `(T / ntid.x) % ntid.y` |
| `%tid.z` | `T / (ntid.x · ntid.y)` |

One value instead of a special-register file. 1-D blocks — which is all three
bootstrap kernels in `backend-context.md` §3 — get `%tid.x` for free.

**The n-D case needs a divide the ISA does not have.** Format A's integer range
(§4) has `mul.lo`, `mul.hi.s/u`, `mad.*`, shifts, and no division. Dividing by
`ntid.x` is dividing by a *runtime* value, so the usual compile-time reciprocal
trick does not apply directly.

It applies indirectly, and this is where the memory-resident choice pays off a
second time: **the host knows `ntid` at launch, so the launch block can carry
precomputed magic multiplier/shift pairs alongside the dimensions.** Decomposition
becomes `mul.hi` + shift + `mad.lo`, using instructions that already exist. Zero
ISA cost, trivial runtime cost, and it is only possible because the block is
memory the runtime writes rather than a hardware register file. Worth reserving
the slots in the layout now even if the first kernels never read them.

## 3. F-1c dissolves — fixed address, no entry-state convention

To read the block you need its address, which looked like it forced an entry-state
convention. It does not.

Put the block at a **fixed architectural address**, CTA-private by windowing
(§4). The prologue materializes the constant:

```
    f48   R0, #LAUNCH_BASE        ; 48-bit Format F, any 32-bit constant, 1 instruction
    ld.global R1, [R0 + #NTID_X]
    ld.global R2, [R0 + #CTAID_X]
```

Register state at kernel entry stays **undefined**. No register is burned on an
ABI pointer, no hardware convention is baked in, and the ISA stays ABI-free —
consistent with the reasoning in §3 Format E that chose explicit link registers
precisely to avoid this. One 48-bit constant materialization per kernel is
nothing, and §3 notes the 48-bit Format F form covers any 32-bit constant in one
instruction, which is exactly this case.

## 4. One windowing mechanism, three scopes

The spec already has address windowing: "`.local` maps to `ld.global`/`st.global`
via the thread-private windowing convention" (§3, Format D opcode map). A
CTA-private launch block at a fixed address is the same mechanism at a different
scope.

Generalizing the window base to three scopes covers everything currently
outstanding:

| Scope | Serves | Status before this |
|---|---|---|
| Thread-private | `.local` | already specified |
| **Warp-private** | predicate spill region | open question in `predicate-transfer.md` §3 |
| **CTA-private** | launch block + kernel arguments | this proposal |

**This retroactively answers the open question in the predicate-transfer
proposal.** The warp-local window proposed there for `ld.pred`/`st.pred` is not a
new mechanism — it is the middle row of a table the machine needs anyway. That
removes the one piece of that proposal that asked for something structurally new.

## 5. Two things the launch block must not be

Both are about the word "memory-mapped register," which is an accurate
implementation description and a dangerous specification.

**It must not carry MMIO memory semantics.** Device registers are conventionally
uncacheable, non-speculatable and strongly ordered. Apply that here and every
kernel prologue becomes a serialization point:

- **Cacheable.** Every warp in the CTA reads the same lines. Uncacheable means an
  8-warp CTA pays full memory latency eight times over for identical data.
- **Speculatable and reorderable.** These are read-only for the kernel's lifetime
  and have no side effects. Blocking speculation puts a non-speculative load at
  the head of every kernel, in a machine whose entire premise is OoO execution.
- **Invariant.** The compiler must be free to CSE them, hoist them out of loops,
  and *rematerialize rather than spill* them. At 16 GPRs that last one matters:
  `blockDim` recomputed from a constant-address load is far cheaper than
  `blockDim` spilled and reloaded.

The ISA already has the right concept — `.const`, "`ld.global` with a read-only
compiler contract, no dedicated opcode or hardware in this pass" (§3). **The
launch block should be specified as `.const`**, not as a device-register space.
Same encoding, right semantics, nothing new.

**It must not be writable.** Read-only is what makes the invariance contract
above sound.

## 6. Backend consequences

Good news, and there is direct prior art to copy.

- **NVVM intrinsic lowering becomes trivial.** `llvm.nvvm.read.ptx.sreg.ntid.x`
  and friends lower to a load from a constant address — a plain ISel pattern, no
  custom lowering. Only the `%ctatid` primitive from §2 needs a real instruction.
- **Kernel arguments have an upstream model.** AMDGPU does exactly this: kernel
  arguments live in a "kernarg segment" read through constant loads, and
  `AMDGPULowerKernelArguments` rewrites argument uses into loads from the kernarg
  pointer. That pass is the template; this decision makes it directly applicable
  rather than something to invent.
- **Mark the loads `!invariant.load`.** This is what buys the CSE, hoisting and
  rematerialization in §5, and it is one metadata node.

## 7. Still blocked — F-11 gates the implementation of F-1b

The decision is right and cannot be fully implemented yet.

Kernel arguments are **64-bit device pointers** — `cudaMalloc` returns one, and
clang's CUDA frontend emits 64-bit pointers for every target since sm_20. A
load's transfer size is inherited from `rdata`'s `chwidth` (§3, Format D), which
tops out at 32 bits, and a GPR lane holds one element. So a 64-bit pointer cannot
be loaded in one instruction and has nowhere to live once loaded.

The launch block is the right *place* for kernel arguments regardless of how F-11
resolves. But the layout cannot be fixed — argument slot widths, alignment, and
whether a pointer occupies one slot or two — until address width is settled. See
F-11 in `../roadmap.md`.

## 8. Open items this leaves

| Item | Kind |
|---|---|
| Encoding for the `%ctatid` identity primitive | ISA — the only opcode F-1 still needs |
| Launch block layout (header fields, offsets, argument area, reciprocal slots) | ABI document, blocked on F-11 |
| Window base scoping — thread / warp / CTA | microarchitecture, shared with `predicate-transfer.md` §3 |
| Address width | F-11, blocks the above |
