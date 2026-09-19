# Proposal — the launch-slot field reaches eight pointers; re-scale it rather than widen it

**Status:** OPEN — for external review.
**Touches:** O-23, O-45, F-129, F-139, F-140, F-143, and §3's Format D launch-slot map.
**Companion:** `launch-abi.md` (the argument-area layout this depends on) and
`ai-ml-relevance.md` §5, whose ask 2 became O-45.

---

## 0. Summary and strength of ask

| # | Ask | Strength |
|---|---|---|
| 1 | **Re-scale the existing 4-bit slot index from a 4-byte stride to an 8-byte stride**, so slot *k* names the *k*-th pointer argument's window word rather than the *k*-th launch-block word. Reach goes from pointer arguments 0–7 to 0–15. **No encoding change.** | **Medium — free, measured, and §5 gives it a workload shape that is not synthetic** |
| 2 | **An ABI rule that pointer arguments occupy the front of the argument area**, which ask 1 requires in order to be well defined | **Follows from 1; no cost measured** |
| 3 | ~~Widen the slot field~~ | **Withdrawn. Do not spend encoding bits on this.** |

**The one-sentence version:** F-140 asked whether to spend more encoding bits on the slot
index; the answer is that **half the slot space is currently unaddressable by construction**,
so the reach doubles for free — and the corpus that was supposed to justify spending the bits
says no real kernel needs even the reach we already have.

---

## 1. What F-140 recorded, and what has changed since

F-140 observed that O-45's slot *k* is the launch-block word at byte offset `32 + 4k`, so
sixteen slots cover 64 bytes; §5.2 gives a pointer argument 8 bytes (window plus in-window
offset); therefore the form reaches **pointer arguments 0–7 and no further**. `fused.cu` at
NT=16 has eighteen pointer arguments, gets exactly 8 slot-form accesses, and the 9 spill
transfers left after O-45 are that limit rather than residual register pressure. It closed
with: *"if fused kernels routinely exceed eight tensors the slot field is the thing to widen"*,
and noted that the compiler side had one synthetic kernel behind it.

Two things have changed.

**First, the corpus exists (F-143).** `test/cuda/fusion/` holds eight kernels written from the
published shape of ones that actually run, with every pointer count forced by the kernel's own
mathematics rather than swept. Their pointer counts are:

| kernel | pointers | kernel | pointers |
|---|---|---|---|
| `silu_and_mul` (SwiGLU) | 2 | `adamw` | 4 |
| `rmsnorm` | 3 | `dequant` (INT8 epilogue) | 6 |
| `add_rmsnorm` | 3 | `layernorm` (+ saved statistics) | 6 |
| `rope` | 4 | `attn_combine` (flash decoding) | 4 |

**Two to six.** The premise of F-140's ask — that fused kernels routinely exceed eight
tensors — is not supported. The kernel that most tempts one to assume otherwise is SwiGLU:
the obvious way to write the gated MLP activation takes three pointers, and the way it is
actually written takes **two**, because the gate and up projections are the two halves of one
allocation produced by one matrix multiply. A kernel parameterised on "number of tensors"
cannot produce that shape, and `fused.cu` did not.

**Second, the limit turns out not to be a shortage of bits.**

---

## 2. Half the slot space cannot name anything

The slot field supplies the AGU a **window index** — the `rbase` input that §5.1 shifts left by
16. The only launch-block words that hold a window index are pointer arguments' window words.
§5.2 gives a pointer 8 bytes: the window word, then the in-window offset (zero for an aligned
pointer, O-23). So with a 4-byte stride, **every odd slot names either an in-window offset or a
scalar argument, and neither is ever a legal `rbase`.**

Eight of the sixteen encodable slots are dead by construction. The field is not too narrow; it
is addressing at the wrong granularity.

Re-scaling to an 8-byte stride — slot *k* is the word at `32 + 8k` — makes every slot name a
pointer and doubles the reach to sixteen pointer arguments. In hardware this is the difference
between a shift by 2 and a shift by 3 in the slot decode. **There is no encoding change at all**:
the field stays 4 bits at `[18:15]`, the two opcodes stay `01100`/`01101`, and no instruction
that assembles today stops assembling.

The one thing it requires is that a pointer's window word actually be at `32 + 8j` for the
*j*-th pointer, which is ask 2: lay the argument area out with pointers first. That is an ABI
choice and not an encoding one — the layout is already described that way where it is
implemented, and it is recorded per kernel in the `ccv-arg-layout` attribute, so nothing
outside the compiler has to infer it. Every kernel in this repository already declares its
pointers first, which is CUDA convention rather than a guarantee; the rule makes it one.

---

## 3. What it buys, measured

Both columns below are `test/cuda/fused.cu` as a grid-strided loop — the shape F-129 measured
and the one O-45 was adopted for — at four tensor counts. The kernel has eighteen pointer
arguments at every setting; `NT` selects how many it reads.

| NT | slot-form accesses | | instructions | | spill transfers | |
|---|---|---|---|---|---|---|
| | **4-byte** | **8-byte** | **4-byte** | **8-byte** | **4-byte** | **8-byte** |
| 4 | 6 | 6 | 42 | 42 | 0 | 0 |
| 8 | 8 | 10 | 60 | 58 | 0 | 0 |
| 12 | **8** | 14 | 80 | 74 | 0 | 0 |
| 16 | **8** | 16 | 114 | **92** | 9 | **0** |

At sixteen tensors the re-scaling removes **every remaining spill** and 22 instructions, 19% of
the kernel. The 8-slot plateau in the left column is F-140's limit, visible directly.

The 8-byte column was produced by patching the three places that have to agree — the argument
layout, the ISel matcher and the simulator's AGU — and running the full gate, including
`check-fusion.py`, `check-sgemm.sh`, `check-sfu.sh` and `check-dp4.sh`, all of which execute.
Everything passed. The patch was then reverted: the tree does not carry an unapproved change
to what an encoded field means.

**And on the real corpus it changes nothing at all.** Every row of `sweep-fusion.sh` is
byte-identical under both scalings, because no kernel in it has more than six pointers. That
is the honest headline: the re-scaling is free, it is correct, it is a strict improvement, and
**the only kernel it currently helps is the synthetic one.**

---

## 4. Why not widen the field

Because there is nothing to buy with the bits.

Widening to 5 bits costs one bit in Format D's 32-bit word, which has none spare — `rdata`,
`rbase`, `rindex`, `scale` and an 8-bit `disp` account for all of `[31:11]`, and F-142 has just
established that the `disp` field is load-bearing rather than decorative. It would have to come
out of `disp`, halving the constant displacement reach, on the same day that field turned out
to be what `out[i + 1]` needs. And it would buy reach past sixteen pointers, which not even
`fused.cu` at its top setting asks for.

If the reach ever does bind past sixteen, a wider field is not the answer there either — but
nor is a new addressing mode, and an earlier draft of this document implied otherwise. The
runtime-indexed case wants a window index the compiler cannot name at compile time, and that
is the **ordinary Format D base+index access**: load the window word into a register and use it
as `rbase`. It is the pre-O-45 path, it still works, and the slot form is a constant-index
optimisation that falls back to it gracefully. No width of immediate field reaches a runtime
index, and none needs to.

What blocks the runtime-indexed case is something else entirely, and §5 says what.

---

## 5. `multi_tensor_apply`, and what a compiler emits for it

The natural objection to ask 1 is the one §3 makes against itself: the only kernel it helps is
the synthetic one. The many-pointer shape that is not synthetic is the multi-tensor optimiser
step — one launch applying an elementwise update across a list of hundreds of parameter
tensors, because a launch per tensor is all launch overhead.

**Written by hand, it does not have this shape.** Apex's and PyTorch eager's
`multi_tensor_apply` packs the tensor pointers into a by-value metadata struct and indexes it
at runtime by a chunk-to-tensor map. One kernel, any list length, one pointer argument.

**Generated by a compiler, it does.** Inductor emits foreach kernels for the `_foreach_*` ops —
the same fusion, as Triton — and Triton kernels take individual pointer arguments, so the
generated form is **one pointer argument per tensor**, split across several launches once the
argument count outgrows the parameter space. The by-value struct is an artifact of hand-writing
one kernel that must work for any length; a compiler re-specialises per call site and has no
reason to pay for the indirection.

That matters here for two reasons.

**It gives ask 1 a real shape.** Nothing in F-143's corpus exceeds six pointers, and this
document has said so plainly. A compiler-generated foreach kernel over eight or twelve
parameter tensors is a workload that exists, is emitted by a shipping compiler, and wants
exactly the reach ask 1 provides for free. It does not change the recommendation; it changes
the strength of the evidence from "free but unmotivated" to "free and motivated".

**It relocates the hand-written form's blocker.** Lowering the by-value form is not an
addressing problem at all. Two things stood in the way and F-147 addressed the first: a by-value
aggregate argument was classified as a pointer and **silently miscompiled** — it read every
field from whatever window the struct's first four bytes named, and it compiled, assembled and
round-tripped. It now lowers correctly, as an object resident in the launch block.

The second is not a compiler question. A struct of tensor pointers means **loading a pointer
out of memory**, and §5.1 gives an address a window index and an in-window offset while
invariant 11 keeps the pair out of the register file. Nothing says what that pair looks like as
a value *in* memory. That is `pointer-representation.md`'s question, it is the real blocker for
the hand-written form, and it is **not asked for here** — but the review should know that the
runtime-indexed multi-tensor kernel is on the other side of it, and that the encoding
question this document is about is not what stands between the two.

---

## 6. Recommendation

**Adopt ask 1 and ask 2, on the grounds that they cost nothing** — no encoding change, no
hardware beyond one bit of shift in the slot decode, and a measured strict improvement on the
one kernel large enough to notice.

**Do not adopt ask 3.** F-140 proposed it and the evidence that arrived since argues against
it; this document withdraws it rather than leaving it open.

Two caveats the review should apply, in the spirit of `ai-ml-relevance.md` §1:

- The corpus is eight kernels. It is drawn from what published inference and training kernels
  look like, which is a much better basis than one kernel with a knob, and it is still eight
  kernels. §5's compiler-generated foreach shape is the one thing here that exceeds it, and
  that is an argument from how another compiler emits code rather than from a kernel measured
  on this one. If a workload shows up with a fused epilogue over ten tensors, the measurement
  here is what tells you the reach is already sixteen and not eight.
- The "free" claim is free *in the ISA*. It does move an ABI that `launch-abi.md` settled, and
  the runtime that populates the launch block has to lay pointers out first. That is a real
  change to a real interface, and it is cheap only because nothing has been built against the
  old order yet.
