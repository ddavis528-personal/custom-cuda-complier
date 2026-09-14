# Compiler-side findings — the v1.4 review

> **Historical.** This is the report written at the v1.4 review and it is kept
> as written, at that point in time. Several things in it have since changed —
> §3's manufactured compare predicate was removed by O-32, and the "open items
> are down to four" count is a v1.4 count. The current report is
> [`compiler-findings-v1.5.md`](compiler-findings-v1.5.md).

**Covers:** everything since the v1.3 review, up to v1.4. Written for the
architecture side, so it is organised by what the compiler work found about the
ISA, not by what was built.

**Spec at the time:** `isa-v1.4-operation-map-and-encoding.md`.

---

## 1. The two corrections you flagged are applied, and made mechanical

The §5.5 arithmetic was wrong in three places, not two. You caught the
instruction count and the density figure; recomputing liveness properly showed
the register figure was also overstated.

| | Was | Is |
|---|---|---|
| Instructions | 22 | 24 |
| Bits per instruction | 28.4 | 26.7 |
| Fixed-32 comparison | 704 | 768 |
| Peak live GPRs | "roughly ten" | **8** |

The bit total, 624, was right; it is now 640 because the listing gained an
instruction (see O-24 below). Density is 17% better than fixed-32, not 12%.

These were arithmetic errors that survived prose review across two revisions, so
the fix is a checker rather than a promise. `tools/check-listings.py` re-derives
instruction count, bit total, bits/instruction, fixed-32 equivalent and peak live
registers from the listings themselves and fails if the prose disagrees. Run
against v1.3 it reports all three errors and exits non-zero. It caught a
half-applied edit to these same listings later the same day.

## 2. Your alignment contingency was right, and stronger than stated — O-23

You flagged that the §5.5 prologue's register count rests on the unaligned case,
and that this weakens two of the four GPR arguments. That is correct. Working it
through, the aligned case is better than the estimate:

| | Instructions | Bits | Peak live GPRs | GPRs per pointer |
|---|---|---|---|---|
| Unaligned (§5.5) | 24 | 640 | **8** | 2 |
| Aligned (§5.6) | 17 | 480 | **5** | 1 |

The extra saving is that the explicit `shl` disappears. With no in-window offset
to absorb, the index register carries an *element* index rather than a byte
offset, so scale-enable can be set.

**Which means O-7 only pays off on aligned pointers.** Chwidth-derived index
scaling was justified by "`A[i]` is one instruction whether `A` is FP32, FP16 or
INT8." Unaligned, the effective address wants four addends against a three-input
AGU, so the offset has to be folded into the index and scale-enable stays clear.
That connection was not visible until a prologue was written out.

**Settled as a per-argument attribute** rather than a blanket ABI requirement.
Recorded as O-23, with three things pinned down in the spec rather than deferred:

- **The launch block layout does not vary with the attribute.** A pointer is two
  slots either way; an aligned one simply has zero in the second, and the
  prologue skips the load. So the runtime never needs to know which kernels
  declared what, and a layout mismatch cannot arise.
- **The backend queries alignment, not the attribute** — whether the low 16 bits
  are known zero. Strictly more general, and it inherits LLVM's existing
  propagation.
- **A false declaration is a silent wrong answer.** That is the failure class
  that wants a launch-time validation harness, not a compile-time check.

Rejected: a blanket requirement (sub-allocators would pad every tensor to 64 KiB)
and a runtime check with two code paths (occupancy is set by a kernel's *maximum*
register count, so carrying both paths pays the unaligned peak regardless — it
recovers nothing).

**Consequence for the GPR decision.** Arguments 1 and 2 — span/MMA fragment
groups and `chwidth` width partitioning — are structural and survive either way.
Argument 3 is alignment-dependent: two GPRs per pointer becomes one. Argument 4
did not survive measurement at all — both listings are now generated from real
codegen, and the peaks are **5 of 16 unaligned, 4 of 16 aligned**, not the 8 the
argument was built on. The hand-written listing held all six pointer halves live
simultaneously; the allocator loads each base only when the fold consuming it is
ready. So the 32-GPR case rests on two arguments rather than four regardless of
how aligned real kernels turn out to be.

## 3. O-24 — every compare is predicated, and a kernel cannot open with one

Found by executing a kernel, not by reading one. The elementwise kernel would not
assemble.

Formats C and C′ both carry a **mandatory** predicate qualifier at `[29:27]`, and
the format tag table has no unpredicated compare. Every compare is guarded.
Combined with §1's "no hardwired always-true predicate," **the first compare in a
kernel has nothing valid to be guarded by** — predicate contents at entry are
undefined and there is no `PT`.

This is a genuine gap in §1's own rule. That rule says every predicated operation
requires a distinct unpredicated encoding, which is precisely why the A and B
ladders and the D/D′ pair exist. C/C′ are the exception, and the tag space is
full, so there cannot be one.

**It resolves with no encoding change**, because compressed forms are never
predicated: `por pd, !ps, ps` is all-ones whatever `ps` holds, in 16 bits, and
Format K carries no qualifier to satisfy. One instruction per kernel, now the
opening line of both worked listings.

Worth noting what this would have cost before 1.3. The only constant-to-predicate
path was `pmov`, which exists **only at 48 bits**. Every kernel would have opened
with a 48-bit instruction to manufacture something the machine could have
hardwired. The Format K predicate logic added in O-20 was justified purely on
if-conversion pressure; that it also makes the kernel prologue viable was not
noticed until a kernel ran.

Alternatives rejected: an unpredicated compare format needs a tag and all sixteen
are allocated; reserving `P3` as architecturally all-ones is a soft `PT` that
spends a quarter of a four-entry file to save one 16-bit instruction per kernel.

## 4. Two properties now confirmed by execution rather than by argument

**Opportunistic reconvergence works as §1 describes.** Under divergence the issue
mask narrows to the active lanes for the guarded body and returns to `ffffffff`
at `exit` — lanes regroup because their PCs coincide, with no bracket instruction
and nothing forcing it. The simulator models per-thread PCs directly; there is no
mask stack.

```
  001c  mask=ffffffff   @4 bra 13
  0020  mask=000fffff   ld.global r5, [r0 + 8]
   ...
  003a  mask=ffffffff   exit
```

**Instruction length is decodable from bits `[1:0]` alone.** §2 asserts this; the
disassembler's length dispatch never inspects the format tag, and 4160 round
trips over all three lengths confirm it holds in practice.

## 5. State of the encoding

Everything the compiler needed is in v1.4. Total cost of all additions since 1.2:
**4 Format D points, 5 Format K, 1 Format G, 1 Format B.** No new formats, no
moved fields, nothing above 32 bits.

New instructions: `srd`, `ld.pred`/`st.pred` (4-bit predicate mask),
`pand`/`por`/`pxor`/`pmov`, `unballot`, `packi.z`.

Decision log entries added: O-17 (address width), O-18 (launch ABI), O-19
(predicate transfer), O-20 (predicate logic), O-21 (`packi` partial writes), O-22
(Format B′/B″ qualifier position), O-23 (pointer alignment), O-24 (compare
bootstrap). O-14 closed.

**Open items are down to four**, none blocking compiler work: O-4 (`reconv.hint`
join-PC pairing), O-8 (compressed density), O-9 (compressed load/store offset),
O-12 (barrier phase parity). O-8 and O-9 need the register allocator, which is
Step 5.

## 6. What is now mechanically checked

The encoding is no longer verified by reading. `tools/verify.sh` runs on every
change:

| Check | What it catches |
|---|---|
| Five TableGen backends | double-assigned bits; **`-gen-disassembler` fails if the encoding is not uniquely decodable** |
| `check-encoding.py` | gaps, length/size disagreement, any field off its invariant-8 position |
| `check-listings.py` | worked-listing arithmetic disagreeing with the prose |
| `ccg-roundtrip` | 4160 encode→decode round trips; encoder and decoder come from *different* generators |
| `run-tests.sh` | kernels execute and produce correct results, at three divergence levels |

Current state: 0 errors, 0 invariant-8 deviations, all figures match, 4160/4160
round trips clean, all simulator tests pass.

That gate is what caught F-14 — the three Format B′/B″ deviations that survived
prose review across three revisions, all on the one field that feeds the
predicate RAT.

## 7. Two open questions for the architecture side

**O-12's barrier phase-parity assumption** still wants checking against the
settled barrier spec. Not encoding-blocking, and unchanged since 1.2, but it is
the one open item that depends on a document the compiler side does not have.

**The GPR count is an encoding fork, not a parameter.** Recorded in §1 and §11.
At 5-bit register fields Format J overruns 16 bits by three and Format A″ falls
to a 1-bit opcode, so the compressed forms cannot address 32 registers and §6's
density argument does not survive the widening. RISC-V's resolution applies —
compressed forms name a 16-register subset — but that is a second encoding, and
it gives the register allocator a third competing objective alongside
destructive-form preference and width affinity. Worth pricing before the spill
data arrives, since the data alone will not surface it.
