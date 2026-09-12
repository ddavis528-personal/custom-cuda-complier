# Proposal — `srd`, the Identity Primitive (F-1a)

**Status:** proposal. Last open ISA question before Step 1.
**Depends on:** `launch-abi.md` (which values the block can carry),
`address-model.md` (S = 16, settled).

---

## 1. What is actually needed

Per `launch-abi.md` §2, the launch block can supply any value uniform across its
readers but cannot supply one that distinguishes them. The residue needs an
instruction.

**Correction to `launch-abi.md` §2: `%ctaid` is in the residue, not the block.**
That section assumed CTA index could be read from the CTA-private window. It
cannot, without the runtime materializing a separate block per CTA — which for a
100,000-CTA grid means 100,000 blocks written at launch, for state the dispatcher
assigns dynamically as SMs free up. CTA index is **dispatch-time** state, not
launch-time state.

The dividing line is therefore not uniform-vs-identity. It is:

> **Known when the runtime prepares the launch** → launch block.
> **Assigned when work is dispatched or executed** → instruction.

| Value | Determined | Source |
|---|---|---|
| grid dims, block dims, kernel arguments, reciprocal constants | launch | block |
| CTA index within grid | dispatch | **instruction** |
| thread index within CTA | execution | **instruction** |

Two primitives, not one.

A CTA-private window *could* be made to return CTA index as a genuine
hardware-backed memory-mapped register, and that reading of "memory-mapped
registers" is available. It should be declined for two reasons: it costs memory
latency on the critical path of every CTA prologue where an instruction costs ALU
latency on state the warp context already holds; and it puts two different access
mechanisms behind one window, which undermines the clean cacheable / speculatable
/ invariant contract argued in `launch-abi.md` §5.

## 2. Encoding — Format K, one opcode point, 4-bit selector

Content is an opcode plus a 4-bit destination. That is 4 bits of operand against
Format K's 8, so **invariant 7 requires it to be 16-bit**: "if an operation's
entire content fits in 16 bits, it has no 32-bit encoding." Same argument that
removed the 32-bit `ret`, `exit`, `fence` and `reconv.hint`.

| Bits | Width | Field |
|---|---|---|
| `[1:0]` | 2 | class = `10` (K) |
| `[7:2]` | 6 | opcode = `srd` |
| `[11:8]` | 4 | `rd` — canonical Format K destination position |
| `[15:12]` | 4 | **selector** |

The four bits at `[15:12]` would otherwise be reserved, which invariant 7 calls a
bug. Spending them as a selector means **one opcode point covers sixteen values**,
which matters because Format K points are the scarcest encoding resource in the
ISA (see `predicate-transfer.md` §5).

| Selector | Value | Notes |
|---|---|---|
| `0` | `%ctatid` — flat thread index within CTA | 10 bits (max 1024 threads/CTA) |
| `1` | `%ctaid` — flat CTA index within grid | |
| `2–15` | reserved | `%smid`, `%clock`, `%globaltimer` when a workload needs them |

Recommended placement: point 28, in K's reserved 28–31 block, adjacent to the
compressed load/store range. Budget after this proposal and `predicate-transfer.md`:
28 is spent here, 29–31 and 60–63 stay free, plus five in the reg-imm range.

**Everything else derives**, using values the launch block already carries:

| Wanted | Derivation | Cost |
|---|---|---|
| `%tid.x`, 1-D block | `%ctatid` | free |
| `%laneid` | `%ctatid & 31` | one 16-bit reg-imm `and` |
| `%warpid` | `%ctatid >> 5` | one 16-bit reg-imm `shr` |
| `%ctaid.x`, 1-D grid | `%ctaid` | free |
| `%tid.y/.z`, `%ctaid.y/.z` | `mul.hi` + shift against block-carried reciprocals | ~4 instructions each |

## 3. Semantics

**The only lane-varying instruction with no lane-varying source.** Every other
instruction is either lane-wise from lane-wise sources, or a broadcast — §3 Format
F states immediates are "warp-uniform (broadcast to all lanes)." `srd #0` writes
lane *n* with `warp_base + n`. In hardware this is a broadcast of the warp's base
index ORed with a per-lane wire; selector 1 is a plain broadcast.

**`chwidth`:** writes the destination at its current width, truncating below 16
bits per invariant 3. A CTA holds at most 1024 threads, so `%ctatid` needs 10
bits and `chwidth`=16 suffices. Compiler contract, no interlock, consistent with
every other width mismatch.

**Not predicated**, like every compressed form.

## 4. Worked prologue — all five decisions together

The Phase 1 validator kernel, fully lowered. This is the first artifact that
exercises the launch block, the address model, `srd`, and the compressed forms at
once.

```
;  __global__ void add(float* c, const float* a, const float* b, int n)
;  { int i = blockIdx.x*blockDim.x + threadIdx.x; if (i<n) c[i] = a[i] + b[i]; }

    f48        R0,  #LAUNCH_BASE        ; 48  launch block base, CTA-private window
    srd        R1,  #CTATID             ; 16  tid.x      (1-D block)
    srd        R2,  #CTAID              ; 16  blockIdx.x (1-D grid)
    ld.global  R3,  [R0 + #NTID_X]      ; 32  blockDim.x
    mad.lo     R1,  R2, R3, R1          ; 32  i = ctaid*ntid + tid
    ld.global  R4,  [R0 + #ARG_N]       ; 32  n
    setp.ge    P0,  R1, R4              ; 32
    @P0 bra    Lexit                    ; 32
    ld.global  R5,  [R0 + #ARG_C + 0]   ; 32  c.rbase
    ld.global  R6,  [R0 + #ARG_C + 4]   ; 32  c.roffset
    ld.global  R7,  [R0 + #ARG_A + 0]   ; 32
    ld.global  R8,  [R0 + #ARG_A + 4]   ; 32
    ld.global  R9,  [R0 + #ARG_B + 0]   ; 32
    ld.global  R10, [R0 + #ARG_B + 4]   ; 32
    shl        R1,  R1, #2              ; 16  element index -> byte offset
    add        R6,  R6, R1              ; 16  fold into each roffset
    add        R8,  R8, R1              ; 16
    add        R10, R10, R1             ; 16
    ld.global  R11, [(R7<<16) + R8]     ; 32  a[i]
    ld.global  R12, [(R9<<16) + R10]    ; 32  b[i]
    fadd       R11, R11, R12            ; 16  destructive, rd == rs0
    st.global  R11, [(R5<<16) + R6]     ; 32
Lexit:
    exit                                ; 16
```

22 instructions, 624 bits — **28.4 bits per instruction**, against a fixed-32
encoding's 704. The compressed forms fire on the four offset folds, the `fadd`,
and `exit`, all naturally.

## 5. Two things this surfaces

**a. The index register carries bytes, not elements — so `chwidth`-derived scaling
does not fire on the main pointer path.** This corrects the claim in
`address-model.md` §3 that the model "composes with O-7 exactly."

The effective address wanted is `(rbase << 16) + roffset + (i << 2)` — **four**
addends. The AGU has three. So `roffset` and `rindex` must be the *same operand*:
the compiler folds the allocation's low bits into the induction variable, which
then holds a byte offset, and the scale-enable bit at `[23]` is left clear.

O-7's chwidth-derived scaling is not wasted — it still fires for `.shared` (flat,
small, naturally aligned bases) and wherever `roffset` is zero. But the general
global-pointer case is scale-disabled, and O-9's density work should expect that
shape rather than the element-indexed one.

There is a fast path worth recording for the ABI: **if a device allocation is
2^16-aligned, its `roffset` is zero**, the pointer costs one register instead of
two, the fold disappears, and the base+index form with `chwidth` scaling applies
exactly. Framework sub-allocators break the guarantee for suballocated pointers,
so the compiler cannot assume it — but a `cudaMalloc`-level alignment guarantee
would make the common case measurably cheaper, and that is an ABI decision
available for free right now.

**b. Peak register pressure on the simplest possible CUDA kernel is ~10 of 16.**
`R0` (block base) is live across the whole argument load sequence, six registers
hold three pointers, and two hold the loaded values. This is an elementwise add
with no tiling, no unrolling, no shared memory, and no reuse.

That is the **fourth** independent argument toward 32 GPRs, and unlike the other
three it is not a projection — it is a count off a fully lowered kernel:

| Argument | Source | Visible in spill counts? |
|---|---|---|
| Span / MMA fragment operands need register groups | ISA spec §10 | no |
| Width-affinity partitioning under `chwidth` | roadmap F-3 | no |
| Two warp-uniform GPRs per live pointer | `address-model.md` §6 | partly |
| **~10/16 live on the trivial kernel** | **this, §4** | **yes — it is the spill precursor** |

The GEMM tile at Step 5 will settle it with data. The prediction from this
prologue is that it will not be close.

## 6. What this closes

With `srd` settled, **no ISA question blocks Step 1.** The full ledger:

| Finding | Resolution |
|---|---|
| F-1a identity primitive | `srd rd, #sel`, Format K, 1 point, 16 selectors |
| F-1b kernel parameters | launch block, pointer = two 32-bit slots |
| F-1c entry register state | undefined; fixed address + Format F materialization |
| F-2 predicate spill path | `ld.pred`/`st.pred` with 4-bit mask, Format D |
| F-8 predicated predicate-dest writes | preserve, consistent with the other two partial-write sites |
| F-9 stale Format D opcode map | delete the second map |
| F-10 `packi` partial writes | preserve + `packi.z` |
| F-11 address width | `(rbase << 16) + roffset`, 64 bits only in the AGU |

Total encoding cost across all of it: 4 Format D points, 5 Format K points, 1
Format G point, 1 Format B point. No new formats, no moved fields, nothing above
32 bits.
