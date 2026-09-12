# Proposal — 64-bit Addressing Without 64-bit Registers

**Status:** direction settled — 64-bit width exists only in the computed effective
address, never in a register. Effective address is `(rbase << S) + roffset`.
**Addresses:** F-11 in `../roadmap.md`. Unblocks the argument-area layout in
`launch-abi.md` §7.

---

## 1. Why this is the right shape

It avoids all three problems the alternatives carried:

| Alternative | Problem | Avoided? |
|---|---|---|
| 64-bit register pairs | needs a pairing mechanism = span, deferred, and structurally awkward at 16 GPRs (§9) | yes — no architectural pairing |
| A 64-bit `chwidth` code | width-code table is full; 32 lanes × 64b breaks the 1024-bit row | yes — `chwidth` untouched |
| A separate 64-bit address register file | new architectural state, new rename namespace | yes — no new state |

Invariant 1 is untouched (no width field anywhere), the register file is
unchanged, and span stays deferred. **The AGU already has this structure** — §3
Format D computes `rbase + (rindex << scale) + disp`, a three-input add with a
shifter. This moves the shift to the base operand and widens the result path to
64 bits. No new AGU topology.

## 2. The shift amount is the load-bearing choice

`S` is not a free parameter. It decides which of two very different compiler
models this is.

With a 32-bit `rbase` and 32-bit `roffset`, the reachable window is
`[rbase<<S, rbase<<S + 2^32)` — 4 GiB wide, placed at a multiple of `2^S`:

| S | reach | window stride | largest allocation reachable from one `rbase` |
|---|---|---|---|
| 0 | 32 bits | 1 B | 4 GiB |
| 12 | 44 bits | 4 KiB | 4 GiB |
| **16** | **48 bits** | **64 KiB** | **4 GiB − 64 KiB** |
| 24 | 56 bits | 16 MiB | 4 GiB − 16 MiB |
| 32 | 64 bits | 4 GiB | **0** |

**`S = 32` is degenerate and should be rejected.** At `S = 32` the windows are
disjoint, so an allocation is reachable from a single `rbase` only if it is
exactly 4 GiB-aligned. Every other allocation straddles a window boundary and
needs carry propagation from `roffset` into `rbase` — and the ISA has **no
add-with-carry**: §4's integer range is `add, sub, mul.lo, mul.hi.s/u, mad.lo,
mad.hi, and, or, xor, andn, shl, shr, sra, min, max, mov, sel, abs, neg, popc,
clz, brev, prmt`, with no carry-producing add and no carry flag. Synthesizing it
costs a compare and a predicated increment per pointer add, in the inner loop.

**For any `S < 32` the windows overlap, and the problem disappears entirely.**
Pick `rbase = addr >> S` for any address and the allocation starts at
`roffset < 2^S`, so anything up to `2^32 − 2^S` is reachable without ever
touching `rbase`. No alignment constraint on the allocator, no carry, no
renormalization in the common case.

**Recommend `S = 16`.** 48 bits of reach matches the canonical x86-64 VA width
and current GPU VA widths, the window stride is 64 KiB (finer than any plausible
allocation granularity), and the usable allocation size is 4 GiB less 64 KiB. If
more reach is wanted later, `S = 20` costs 1 MiB of allocation headroom for
another 4 bits.

## 3. It composes with O-7 better than either decision anticipated

O-7 derived the index scale from `chwidth` on the argument that "the index a
kernel computes is almost always an *element* index, not a byte index." Under
this address model that argument gets stronger, because the two operands now have
exactly the meanings CUDA code produces:

```
    A[i]  ->  (allocation_window << S) + (i << log2(sizeof(elem)))
               \__ rbase, from a kernel argument __/  \__ roffset, the loop IV __/
```

`rbase` is the allocation. `roffset` is the element index. That is the natural
decomposition of every array access in a CUDA kernel, and it falls out of the two
decisions independently.

## 4. Encoding cost: zero, if the shift comes from the address space

`S` should **not** be an instruction field. Field-counting the base+index form
leaves no room: opcode(5) + `rdata`(4) + `rbase`(4) + `roffset`(4) + header(6) =
23, leaving 9 bits for a shift field *and* a displacement.

It does not need to be encoded, because the address space is already in the
opcode (§3 Format D) and the shift is a property of the address space:

| Space | Shift | Rationale |
|---|---|---|
| `.global` (and `.const`, `.local` via windowing) | `<< S` | needs 64-bit reach |
| `.shared` | none, 32-bit flat | a CTA's shared memory is hundreds of KiB; 64-bit reach is meaningless |

So Format D's base+index form is **unchanged bit-for-bit** — same fields, same
positions, same length — and only its semantics widen, per address space. The
base+offset form keeps 32-bit flat semantics and remains the right encoding for
`.shared` and for in-window access with a constant displacement.

One consequence worth stating: **the two-register form becomes the primary global
addressing mode.** Essentially every global access will be base+index, where
base+offset was previously the default shape. That is not a cost, but it changes
which form the density work in O-9 should be measuring.

## 5. Compiler costs — honest accounting

Four real ones. None is a blocker; two are free in the common case.

**a. Pointer representation is non-canonical, so pointer *comparison* is not a
register compare.** When `S < 32` windows overlap, so one address has many
`(rbase, roffset)` representations. Two mitigations cover nearly everything:

- Comparing pointers **derived from the same allocation** — the overwhelmingly
  common case, and the only case C/C++ defines for relational operators — have
  identical `rbase`, so comparing `roffset` is exact.
- `ptrtoint` for **alignment tests** (`(uintptr_t)p & 15`) touches only low bits,
  which live entirely in `roffset` since `rbase` contributes only bits ≥ S. Free.

Full cross-allocation equality needs a materialized 64-bit compare. Rare; the
predicated-compare sequence is acceptable there.

**b. No add-with-carry.** Only matters when an access crosses out of a window,
which under `S = 16` means a single access more than ~4 GiB from its allocation
base. The compiler can detect the statically-large-offset case and renormalize
`rbase`. If this ever shows up as hot, §4's integer range has **6 free points in
the low 32**, which is the A″-reachable range where a carry-out predicate
destination would live.

**c. Generic address space.** CUDA unified addressing lets a generic pointer
name global, shared or local, resolved by range. Under a windowed model that
cannot be decided from `(rbase, roffset)` without materializing the full address.
Standard fix, same as NVPTX: run LLVM's `InferAddressSpaces` to resolve generic
pointers statically. Residual generic pointers need a slow path; in practice
almost none survive the pass.

**d. Every pointer costs two GPRs, and both are warp-uniform.** This is the
expensive one and it is a register-pressure finding, not a correctness one — see
§6.

## 6. Why this is a net win for codegen, and one thing it makes worse

**The win.** `getelementptr inbounds` — which clang emits for every array access
in CUDA — guarantees the result stays within the allocated object. That is
*exactly* the property the windowed model needs. It means:

- `rbase` is **loop-invariant** for every access derived from one allocation.
- `rbase` is loaded once in the prologue from the launch block and never
  recomputed.
- The inner loop touches only `roffset`, with ordinary 32-bit arithmetic, usually
  as the induction variable after strength reduction.

So **no 64-bit arithmetic ever appears in generated code.** The 64 bits exist
only inside the AGU. That is a better outcome than a flat 64-bit register model,
which would put 64-bit adds in every address computation.

**What it makes worse.** Each live pointer now occupies **two** GPRs. The
elementwise bootstrap kernel has three pointer arguments — six of sixteen GPRs
consumed before any computation, alongside the loop induction variable, the
loaded values, and the launch-block base.

And both halves are **warp-uniform**: a kernel argument is the same value in all
32 lanes, so each occupies a full 1024-bit register row to hold 32 bits of real
information. Pointer bases are now the single largest source of wasted register
capacity in a kernel, and this model doubles their count.

This does not argue for a scalar register file — that is a large architectural
addition and out of scope here. It does argue, for the **third independent
reason**, toward 32 GPRs:

| Argument | Source | Visible in spill counts? |
|---|---|---|
| Span / MMA fragment operands need register groups | ISA spec §10 | no — structural |
| Width-affinity partitioning under `chwidth` | roadmap F-3 | no — transition counts, not spills |
| **Two warp-uniform GPRs per live pointer** | this proposal | **partly — it inflates them** |

Per `backend-context.md` §4, ambiguous spill data tips toward 32. Two of the
three arguments are invisible to spill counting, so the Step 5 experiment should
report pointer-base residency alongside spill and width-transition counts.

## 7. Unblocks the launch block argument area

`launch-abi.md` §7 could not fix the argument-area layout until address width was
settled. It now can: a pointer argument occupies **two 32-bit slots** —
`rbase` and the initial `roffset` — and is loaded into two registers in the
prologue with two ordinary loads. Scalar arguments occupy one slot each.

The runtime performs the `addr >> S` / `addr & (2^S − 1)` split once at launch
when it writes the block, so the kernel never does it. Nothing in the prologue
computes a shift.

## 8. Open items this leaves

| Item | Kind |
|---|---|
| Fix `S` (recommend 16) | ISA parameter |
| Confirm `.shared` stays 32-bit flat | ISA, §4 |
| Whether `addc` (carry-out to predicate) is worth one of the 6 free low-32 points | deferred — needs codegen data |
| Pointer-base register residency as a Step 5 measurement | backend |
