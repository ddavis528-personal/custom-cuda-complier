# 64-bit addressing — how it is specified, lowered, and verified

**For:** the ISA design track. Self-contained.
**Covers:** ISA v1.5 O-17 (address model), O-23 (pointer alignment), and F-20
(what it costs the backend).
**Status:** specified, implemented, and producing correct code. No open ISA
question.

---

## 1. The decision

64-bit width exists **only in the computed effective address**, never in a
register. For `.global` the AGU computes

```
    (rbase << 16) + (rindex << scale) + disp
```

from two ordinary 32-bit registers, giving 48 bits of reach. The base shift is a
property of the **address space**, which is already in the opcode, so no bit map
changed and no field moved — `.shared` does not shift, because a CTA's shared
memory is hundreds of kilobytes and 64-bit reach there is meaningless.

This is recorded as **invariant 11: no register holds an address.**

### Why the alternatives were rejected

| Alternative | Problem |
|---|---|
| 64-bit register pairs | needs a pairing mechanism, which is span — deferred, and structurally awkward at 16 GPRs |
| A 64-bit `chwidth` code | the width-code table is full, and 32 lanes × 64 bits breaks the 1024-bit row |
| A separate address register file | new architectural state and a new rename namespace |

The adopted model adds none of the three. Invariant 1 is untouched, the register
file is unchanged, and the AGU already had a three-input add with a shifter.

### Why the shift is 16

With a 32-bit `rbase` and 32-bit index, the reachable window is 4 GiB wide,
placed at a multiple of 2^S:

| S | reach | window stride | largest allocation from one `rbase` |
|---|---|---|---|
| 12 | 44 bits | 4 KiB | 4.0000 GiB |
| **16** | **48 bits** | **64 KiB** | **3.9999 GiB** |
| 20 | 52 bits | 1 MiB | 3.9990 GiB |
| 24 | 56 bits | 16 MiB | 3.9844 GiB |
| 32 | 64 bits | 4 GiB | **0** |

`S = 32` is degenerate: windows become disjoint, so an allocation is reachable
from one `rbase` only if it is exactly 4 GiB-aligned, and everything else needs
carry propagation from the offset into the base — which the ISA cannot express,
since §4's integer map has no add-with-carry and no carry flag.

For any `S < 32` the windows **overlap** and that problem disappears entirely.
16 puts reach at 48 bits, matching canonical x86-64 and current GPU VA widths.

## 2. Alignment is a per-argument property (O-23)

An allocation aligned to the 2^16 window stride has a zero in-window offset, and
three things follow at once:

| | Unaligned | Aligned |
|---|---|---|
| GPRs per live pointer | 2 | **1** |
| Launch-block slots loaded | 2 | **1** |
| In-window offset fold | one `add` per pointer | **none** |
| Index register carries | bytes | **elements** |
| `chwidth`-derived scaling (O-7) | unusable | **fires** |

The last row is the one that is easy to miss. Unaligned, the wanted address has
**four** addends against a three-input AGU, so the in-window offset must be
folded into the index register, which then carries bytes and leaves scale-enable
clear. **O-7's whole justification — that `A[i]` is one instruction at any
element width — holds only for aligned pointers.**

Settled as an **alignment attribute per kernel pointer parameter**, not a blanket
ABI requirement (which would make sub-allocators pad every tensor to 64 KiB) and
not a runtime check with two code paths (which recovers nothing, because
occupancy is set by a kernel's *maximum* register count, so carrying both paths
pays the unaligned peak regardless).

Three consequences pinned down in the spec rather than left to the ABI document:

- **The launch block layout does not vary with the attribute.** A pointer is two
  slots either way; an aligned one simply has zero in the second, and the
  prologue skips loading it. The runtime therefore never needs to know which
  kernels declared what, and a layout mismatch cannot arise.
- **The backend queries alignment, not the attribute** — whether the low 16 bits
  are known zero. Strictly more general, and it inherits LLVM's existing
  propagation through `getelementptr`.
- **A false declaration is a silent wrong answer**, which is the failure class
  that wants a launch-time validation harness rather than a compile-time check.

## 3. How it is lowered

Two stages, and the division between them is deliberate.

**Stage 1 — IR.** `CCVLowerKernelArgs` rewrites kernel parameters into invariant
loads from the launch block and materialises the address model as **explicit IR
arithmetic**: `(zext rbase << 16) + zext roffset`.

Putting it in IR rather than the backend has a payoff that was not planned: for
an aligned pointer the in-window offset is a constant zero, so **the add
constant-folds away on its own**. The one-register form arrives from the
optimiser with no backend special case at all. O-23 falls out rather than being
implemented.

Measured on real clang output — three pointers and a scalar:

```
  PASS  kernel args lowered to launch block (unaligned 7 slots, aligned 4)
  PASS  aligned pointers carry no in-window offset (O-23)
```

**Stage 2 — backend.** LLVM requires a load's pointer operand to be a legal type,
and a pointer cannot be split the way an integer can — the node takes one address
operand, so there is nothing to expand it into. Invariant 11 therefore collides
with LLVM's type system directly.

Resolved by consuming the address in a **DAGCombine at `BeforeLegalizeTypes`**,
ahead of the type legalizer, rewriting the memory operation to a target node
taking two `i32` operands. The 64-bit value is dead before anything tries to
legalize it. Two shapes, matching the two Format D addressing modes:

| IR shape | Selected to |
|---|---|
| `(rbase << 16) + idx` | Format D base+index |
| a constant address | Format D base+offset — the launch block |

## 4. Verification

Real output from the backend, on IR in the shape the pass produces:

```
k:
	f48        r0, 2                ; launch base >> 16
	ld.global  r1, [r0 + 32]        ; a.rbase
	srd        r2, 0                ; %ctatid
	ld.global  r1, [r1, r2, 1, 0]   ; a[i] -- (rbase<<16) + (idx<<scale)
	ld.global  r0, [r0 + 40]        ; c.rbase
	st.global  r1, [r0, r2, 1, 0]   ; c[i]
	exit
```

and the pure base+offset case — reading the launch block in `.const` and
writing to a `.global` window:

```
k:
	f48        r0, 2                ; .const window: the launch block
	ld.global  r0, [r0 + 56]
	f48        r1, 3                ; a different, writable window
	st.global  r0, [r1 + 8]
	exit
```

An earlier version of this listing stored back into the launch block at
`0x2003C`. That was a hand-written test of the base+offset *store* path and not
output from kernel-argument lowering, but it should not have been shown as
verification: §5.2 maps the launch block to `.const`, so it was a write to
read-only memory. **The backend now rejects that at compile time** — see §5.

**No register holds an address at any point.** Invariant 11 survives from the
encoding through to generated code.

## 5. Failure modes, and what the compiler refuses

The DAGCombine is a **whitelist of two IR shapes**, and invariant 11 means there
is nothing to materialise a pointer into when it escapes an addressing mode. Both
are real limits, and both were previously **crashes** — SIGSEGV, or a
stack-smashing abort, with no diagnostic, because a live `i64` reached a type
legalizer with no register class to expand into.

A crash is not an acceptable failure mode: it is indistinguishable from a bug in
the compiler and tells the user nothing. `CCVCheckIR` now runs before codegen and
turns each into a diagnostic naming the construct and the reason:

| Construct | Now reports |
|---|---|
| pointer stored to memory (an array of pointers) | invariant 11: no register holds an address |
| pointer compared against a pointer | would need both halves materialised, two compares |
| pointer passed across a call | the calling convention cannot pass an address |
| pointer `phi` across a merge | cannot live in a register across control flow |
| an address outside the whitelist | not `(rbase << 16) + index` or a constant |
| store to `addrspace(4)` | `.const` is read-only by contract (§3, §5.2) |

`test/reject/` asserts each is a diagnostic rather than a crash, and
`test/accept/` asserts the supported shapes still compile. These run in
`tools/run-tests.sh`, so the property is checked rather than believed.

**The escaping-pointer cases are a real gap, not just a diagnostic.** Each needs a
lowering convention that does not exist yet: the `(rbase, roffset)` pair as two
32-bit values, with comparison lowered to two compares and the pair passed in two
argument registers. Arrays of pointers and any non-inlined call both hit it.
Tracked as **F-22**; no kernel in the bootstrap set reaches it.

### The precondition that makes the missing add-with-carry a non-issue

The model reaches **4 GiB − 64 KiB from a single `rbase`**, so any allocation
smaller than that never needs the base recomputed — which is exactly why §11's
absent carry-producing add has not bound on anything. That is a **precondition,
not a property**: a buffer at or above 4 GiB would need the base touched
mid-access, and the ISA cannot express the carry.

Written down here because it is currently implicit in the lowering, and an
implicit precondition is invisible on the day someone maps a larger buffer. The
compiler cannot check it — allocation sizes are not known at compile time — so
it belongs with the launch-time validation that O-23 already calls for.

## 6. What it cost, honestly

**In the encoding: nothing.** No bit map changed, no field moved, no format was
added. The base+index form is unchanged from v1.2; only its semantics widened,
per address space.

**In the backend: one DAGCombine hook**, roughly forty lines plus the matching
selection. Paid once, invisible in generated code.

**A 64-bit register class was proposed and is not needed.** The first analysis
concluded that `i64` had to be made legal via a class over GPR pairs, with the
address matcher consuming addresses before any pair was allocated. Consuming the
address *earlier* removes the requirement entirely — which is a better guarantee
than policing a class that cannot be encoded. Had it been added it would have
needed `isAllocatable = 0`, a post-ISel check rejecting surviving values of that
class, and a `copyPhysReg` that reports a fatal error rather than emitting a
32-bit move for a 64-bit copy — that last being the only path that could silently
miscompile.

## 7. The one observation worth carrying back

**Every other LLVM target with 64-bit pointers has 64-bit registers.** This
machine is outside the shape LLVM's type system assumes, and the consequence is
that address arithmetic must be *recognised and consumed early* rather than
legalized.

**AMDGPU is the near-miss, and it sharpens the point.** It also has 64-bit
pointers over 32-bit physical registers, and it solved this the orthodox way —
64-bit register classes over register pairs. What made that available is that
AMDGPU has real 64-bit *instructions* to build on: 64-bit moves, `flat_load_dwordx2`,
64-bit address arithmetic. A pair class there is something instructions can
consume.

Here there is no 64-bit instruction at all — span and multi-register transfers
are deferred (§10) — so a pair class would have nothing to operate on it. Every
operation would decompose into sub-register operations, which is another way of
saying the class would exist only to satisfy the type system. **The divergence
from the orthodox approach is forced by the ISA, not chosen for style.** That is
a stronger statement than the first draft of this section made, and it is the
right one.

That is a constraint on how the backend is written, not a defect in the ISA, and
it does not appear in generated code. But it is the kind of thing that would have
been expensive to discover after more of the backend depended on the ordinary
path — and it is worth knowing that invariant 11's cost, while small, is not
zero and is paid entirely on the compiler side. That is the trade the invariant
was making, and it came out favourably.
