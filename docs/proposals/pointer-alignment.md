# Proposal — Per-Argument Pointer Alignment

**Status:** settled as ISA v1.4 O-23. This records the backend-side mechanism and
what it means for the Step 5 measurement.
**Resolves:** F-18 in `../roadmap.md`.

---

## 1. What it buys

Under the address model of v1.4 §5.1 a pointer is `(rbase << 16) + roffset`. When
an allocation is 2^16-aligned, `roffset` is zero, and three things follow at once:

| | Unaligned | Aligned |
|---|---|---|
| GPRs per live pointer | 2 | **1** |
| Launch-block loads per pointer | 2 | **1** |
| In-window offset fold | one `add` per pointer | **none** |
| Index register carries | bytes | **elements** |
| `chwidth`-derived scaling (O-7) | unusable | **fires** |

On the elementwise kernel (v1.4 §5.5 vs §5.6) that is 23 instructions and 8 live
GPRs against 16 and 5.

The fourth row is the one that is easy to miss. Unaligned, the index register has
to carry a byte offset in order to absorb `roffset` — the effective address wants
four addends against a three-input AGU — so scale-enable stays clear. **O-7's
whole justification, that `A[i]` is one instruction at any element width, only
holds for aligned pointers.**

## 2. The mechanism

**Source of truth: an alignment attribute on each kernel pointer parameter.**
clang already has `align_value`, which lowers to LLVM's `align` parameter
attribute, so nothing new is needed at the frontend:

```cuda
__global__ void add(float *__attribute__((align_value(65536))) c, ...)
```

**The backend should not read the attribute.** It should ask whether the address's
low 16 bits are known zero — the ordinary alignment query. That is strictly more
general: it inherits LLVM's propagation through `getelementptr`, and it fires
wherever alignment is provable for some other reason, not only where it was
declared. The attribute is one input to that question, not the mechanism.

Concretely, at address lowering: if `computeKnownBits` shows the low 16 bits
clear, emit `(rbase << 16) + (rindex << scale)` with scale-enable set and load one
slot; otherwise load both, fold, and leave scale-enable clear.

## 3. The launch block does not change

A pointer argument occupies **two 32-bit slots regardless**, and the runtime always
writes `addr >> 16` and `addr & 0xFFFF`. An aligned argument simply has zero in the
second slot, and the prologue skips loading it.

This matters more than it looks. If the layout varied with the attribute, the
runtime would have to know which kernels declared what, and a mismatch between the
runtime's idea of the layout and the compiler's would be a silent corruption.
Keeping the layout attribute-independent means **the runtime never needs to know**
— the attribute is purely a codegen input.

## 4. Rejected alternatives

**A blanket ABI requirement** that all device pointers be 2^16-aligned. Framework
sub-allocators would have to pad every tensor to 64 KiB; a model with thousands of
small tensors pays that thousands of times.

**A runtime check selecting between two code paths.** This sounds like it captures
both cases and it captures neither. Register allocation is static, and occupancy is
set by a kernel's *maximum* register count — so a kernel carrying both paths pays
the unaligned peak whichever path executes. The saving that matters is exactly the
one this does not recover. Worth recording because the idea is superficially
attractive.

## 5. The failure mode, and why it needs a harness

A false declaration is not a fault. The low bits are ignored, the access lands at
the wrong address, and the kernel produces wrong answers quietly.

That is the class of failure `backend-context.md` §5.1 singles out for Phase 3 —
"mismatches here cause *silent* failures rather than compile errors" — and the
response it prescribes is a validation harness rather than a compile-time check.
The runtime can verify declared alignment at launch with one test per pointer,
compiled out of release builds. Cheap, and it converts a silent wrong answer into
a loud one.

## 6. Consequence for the Step 5 measurement

**Register-pressure data must report aligned and unaligned kernels separately.**
Two of the four GPR-count arguments in v1.4 §1 rest on the unaligned shape, and on
the simplest kernel there is the two shapes differ by three live registers. A GEMM
tile measured without distinguishing them produces a number that cannot be
interpreted.

The honest framing for the 16-vs-32 experiment:

| GPR argument | Depends on alignment? |
|---|---|
| 1 — span / MMA fragment groups need aligned register quads | no |
| 2 — `chwidth` width partitioning | no |
| 3 — GPRs per live pointer | **yes: 2 unaligned, 1 aligned** |
| 4 — peak live on the trivial kernel | **yes: 8 unaligned, 5 aligned** |

Arguments 1 and 2 are structural and survive either way. If real kernels turn out
to be predominantly aligned, the GPR case rests on those two alone — which is a
materially weaker case than the four-argument version, and worth knowing before
the tile is written rather than after.
