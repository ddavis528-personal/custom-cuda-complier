# F-20 — pointers with no register to hold them: resolved, no 64-bit class needed

**Status:** resolved. The first write-up of this finding was wrong about the
severity and wrong about the fix; both are corrected below.
**Bottom line:** invariant 11 costs the backend one DAGCombine, not a register
class. No 64-bit register is ever declared, allocated, or emitted.

---

## The collision, restated correctly

Invariant 11 says no register holds an address: an address is 48 bits, formed
inside the AGU from two 32-bit registers (§5.1).

LLVM requires the pointer operand of a load or store to be a **legal type**, and
a pointer cannot be split the way an integer can — the node takes one address
operand, so there is nothing to expand it into. With `p:64:64` and no 64-bit
register class, type legalization gives up before instruction selection.

## The fix: consume the address before type legalization

LLVM runs a DAGCombine round at `BeforeLegalizeTypes`, ahead of the type
legalizer. Matching the address there and rewriting the memory operation to a
target node that takes **two i32 operands** means the 64-bit value is dead before
anything tries to legalize it.

`CCVTargetLowering::PerformDAGCombine` handles two shapes, which are exactly the
two Format D addressing modes:

| IR shape | Target node | Selected to |
|---|---|---|
| `(rbase << 16) + idx` | `CCVISD::LD/ST_BASEIDX` | Format D base+index |
| a constant address | `CCVISD::LD/ST_BASEOFF` | Format D base+offset |

The second is the launch block, whose base the prologue materialises with a
48-bit Format F constant (§5.2).

**Verified.** From IR in the shape `CCVLowerKernelArgs` produces:

```
	f48        r0, 2                ; launch base >> 16
	ld.global  r1, [r0 + 32]        ; a.rbase
	srd        r2, 0                ; %ctatid
	ld.global  r1, [r1, r2, 1, 0]   ; a[i] -- (rbase<<16) + (idx<<scale)
	ld.global  r0, [r0 + 40]        ; c.rbase
	st.global  r1, [r0, r2, 1, 0]   ; c[i]
	exit
```

That is §5.6's aligned shape, and **no register holds an address at any point**.
Invariant 11 survives all the way down.

## Corrections to the first write-up

**A 64-bit register class over GPR pairs is not needed and should not be added.**
It was proposed to satisfy the type legalizer. Consuming the address earlier
removes the requirement entirely, so there is nothing to police, nothing to mark
un-allocatable, and no failure mode to guard against. The strongest guarantee
that an unencodable register class is never emitted is not to declare one.

Had it been added, it would have needed all of: `isAllocatable = 0` so allocation
cannot assign it; a post-ISel check rejecting any surviving vreg of that class
with a legible message rather than an opaque allocator failure; and a
`copyPhysReg` that reports a fatal error rather than emitting a 32-bit move for a
64-bit copy — that last one being the only path that could silently miscompile.
All avoided.

**The severity was overstated.** "Blocks the memory half of Step 3" was wrong.
Memory works. What actually blocked the kernel was control flow, and the reason
the diagnosis went wrong is worth recording: every isolation test used inline asm
to keep values live, and **inline asm was itself unsupported**. Its failure —
identical in wording to the pointer failure — masked the fact that loads and
stores had started working. Reaching for an anchor that was not itself tested
produced a confident wrong conclusion.

## What invariant 11 actually costs

One DAGCombine hook, roughly forty lines, plus the matching selection. That is
cheap, and it is paid once in the backend rather than in the encoding — the trade
invariant 11 was making.

The observation worth keeping for the architecture side is unchanged in kind but
much smaller in degree: **every other LLVM target with 64-bit pointers has 64-bit
registers**, so this machine is outside the shape LLVM's type system assumes. The
consequence is that address arithmetic must be recognised and consumed early
rather than legalized. That is a constraint on how the backend is written, not a
defect in the ISA, and not a cost that shows up in generated code.

## Genuinely remaining, and unrelated

- **Compares and branches.** `i1` now lives in `PR` (invariant 5: predicates are
  their own namespace with their own RAT), which is enough to type-legalize a
  branch. Selection patterns for `br`, `brcond` and `setcc` are not written.
  `setcc` is the interesting one: the predicate qualifier is an immediate *field*
  in the encoding but semantically a **register read**, so for codegen it has to
  be a register operand with a custom encoder — and O-24's bootstrap means every
  compare needs a guard, which the self-guarding form supplies by tying the guard
  operand to the predicate destination.
- **Inline asm** needs more than a constraint mapping.
- **Value-returning device functions** (F-21), which kernels do not need.
