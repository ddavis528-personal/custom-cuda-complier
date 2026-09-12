# Finding F-20 — LLVM wants a pointer in a register; invariant 11 says there isn't one

**Status:** open. Blocks the memory half of Step 3.
**Found by:** building the `TargetMachine` and running codegen on real IR.

---

## The collision

Invariant 11 says no register holds an address: an address is 48 bits, formed
inside the AGU from two 32-bit registers (§5.1). That is what makes 64-bit
addressing free — no register pairing, no width code, no address register file.

LLVM's SelectionDAG requires the pointer operand of a load or store to have a
**legal type**, which means a type with a register class. With `p:64:64` and no
64-bit register class, type legalization gives up before instruction selection
is reached:

```
LLVM ERROR: Do not know how to expand the result of this operator!
```

**Confirmed by experiment, not inferred.** Temporarily declaring `p:32:32`
makes that error disappear completely and loads and stores reach selection,
failing only on the missing patterns:

```
LLVM ERROR: Cannot select: store<(store (s32) into %ir.q)> ...
```

So the blocker is exactly the pointer width, and nothing else in the pipeline.

## Why the obvious answers are wrong

**Declaring 32-bit pointers** is not available: a 32-bit pointer addresses one
4 GiB window, and a kernel touches several allocations in different windows. The
window index has to be somewhere.

**A segmented model** — 32-bit pointer holding the in-window offset, window base
carried alongside — is what the hardware actually does, and LLVM has no
first-class support for it. The base would have to be recovered by walking the
pointer's defining chain at selection time. This is the x86 segmentation lesson:
the representation is not the problem, the fact that no optimizer pass
understands it is.

## What should work

**Declare a 64-bit register class over GPR pairs, purely to make `i64` legal,
and rely on the address matcher to consume addresses before any pair is
allocated.**

The key point is that legality and allocation are separate. The matcher in
`CCGISelDAGToDAG::selectAddrBaseIdx` already recognises `(rbase << 16) + idx`
and rewrites it to Format D base+index, so a pointer normally never reaches
register allocation as a value. The pair class exists to satisfy the type
legalizer and as the correctness fallback for an `i64` that genuinely escapes —
stored to memory, phi'd, or compared.

Two things make this less alarming than it first looks:

- **Pairs need not be aligned.** AMDGPU's `VReg_64` allows unaligned consecutive
  pairs, so this does **not** reintroduce the four-legal-quads constraint that
  O-25 retired for span. All fifteen consecutive pairs are available.
- **It does not cost O-23 its saving.** An aligned pointer's in-window offset is
  a constant zero, and the matcher consumes the address before allocation, so
  the one-register form still falls out. A pair is only materialised where a
  pointer escapes as a value, which is rare in kernel code.

## Recorded because it is an ISA-level observation, not just a plumbing one

Invariant 11 is a good decision — it is what let 64-bit addressing land without
register pairing, a width code, or a new namespace. But it puts the machine in a
class LLVM does not have a target for: **every LLVM target with 64-bit pointers
has 64-bit registers.** The workaround above is sound, and it is a workaround.

The thing worth carrying back to the architecture side is that the cost of
invariant 11 is not zero — it is paid in the backend, once, as a register class
that exists only to satisfy a type system. That is a much better place to pay it
than in the encoding, which is the trade invariant 11 was making. But it should
be recorded as a cost rather than as free.

## Also open, and unrelated to the above

- **`bitcast` between `i32` and `f32` has no pattern.** It is a register-to-
  register no-op and needs a `COPY_TO_REGCLASS`-style pattern. Trivial, just
  not written.
- **Value-returning device functions.** `CCGISD::RET` is selected in C++ and
  currently handles the void case only; carrying return registers through
  needs a variadic pseudo instruction rather than a fixed-shape one. Kernels
  return void, so this does not block Step 3. Recorded as F-21.
