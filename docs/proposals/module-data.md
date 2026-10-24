# Proposal — Where a module's data lives (CP-10, F-162)

**Status:** agreed 2026-10-22. IS agreed with four additions (IS's response CP-10, rev 90),
folded in below, and will write §5.2 and the decision. TI confirmed that word 28 is free and that
nothing in RTL or the skeleton decodes the launch block (TI's response CP-10, rev 108). CP
built it once §5.2 was written (O-61): `CCVModuleData`, `ccv-sim -data`, and
`tools/check-globals.sh`. A function pointer in an initializer is still diagnosed: it needs
the code layout.
**Found by:** the CoreMark-derived workload (AR-20). `core_state.c` holds its input patterns in
four constant tables of string pointers, `static ee_u8 *intpat[4] = {"5012", ...}`, and
reads them by a runtime index. Any C or CUDA source with a lookup table, a string literal
or a `__device__` variable needs the same thing.

---

## 1. What is missing

The backend has no data section at all. A kernel reaches memory only through windows
whose indices arrive in the launch block (§5.2): the CTA's `.local` base (word 24) and
the pointer arguments (words 32 onwards). A global has no window, so it has no address.

O-51 already gives MIU a `.const` base and limit per kernel, to raise `F-RO` on a store
into constant data. What is not specified is how the kernel learns where that data is.

## 2. Proposal

1. **One data image per module.** The compiler lays out every global of the closed
   module (device code has no separate compilation, F-21) in one image: constant
   globals first, writable `__device__` globals after. Each global gets a link-time
   offset from the start of the image.
2. **The runtime loads it once per module**, at a window-aligned address, so
   `base = W_d << 16`. Constants are loaded read-only and covered by O-51's `.const`
   base and limit. Writable globals are shared by every launch of the module, which is
   CUDA's semantics for `__device__` variables.
3. **Launch-block word 28 holds `W_d`** for every launch of the module's kernels. Word 28
   is unused today, between `.local` (24) and the arguments (32), so nothing moves.
4. **A global's address is the pair `(W_d, offset)`.** It is one launch-block load,
   warp-uniform and hoistable, then the ordinary Format D access. No new instruction
   and no new addressing mode are needed.
5. **Pointers inside the image are relocated at load.** A pointer in memory is the flat
   64-bit address (O-54), and an initializer like `intpat` holds addresses within the
   image itself, which are known only once `W_d` is chosen. The image carries a list of
   8-byte slots to which the loader adds `W_d << 16`. That is the ordinary loader
   relocation, and the only kind needed, since the module is closed.

### IS's additions (rev 90)

6. **Function pointers in initializers need no relocation.** A code pointer is its
   target's offset in the code window (§3 Format E), a constant of the image wherever the
   image is loaded, so a vtable or callback table is stored as is. The relocation list
   names only data pointers: 8-byte slots holding O-54's flat address, naturally aligned
   (O-58).
7. **The writable part's initial state is defined** (invariant 12, O-38). Initialized
   globals come from the image and everything else is zero, written by the loader, never
   whatever memory held before.
8. **The image is per context.** Writable globals are shared by every launch of the module
   within its context, and never across contexts.
9. **Invariance is per launch.** §5.2's cacheable, invariant contract for `.const` holds for
   a launch. The host may write `__constant__` data between launches, and the next launch
   must see it; that obligation is AR's and TI's. A device store into it raises `F-RO`.

IS also notes that MIU's CTA channel carries no `.const` range and no launch-block limit
yet, so `F-RO` cannot be checked in RTL for either. That is TI's.

## 3. Costs and alternatives

- **One load per function that touches a global**, from the launch block, which §5.2
  already makes cacheable and speculatable. Making the data window a launch *slot*
  (O-45's slot-form addressing) would save even that, but slots start at word 32, so it
  would move every argument by 8 bytes. Not worth it before a measurement says so.
- **Alternative: no relocations**, with pointers in initializers rejected. That rejects
  CoreMark and every table of strings. Rejected.
- **Alternative: per-launch copies** of the image in the launch block. That is wrong for
  writable globals, which CUDA shares across launches, and it grows the block. Rejected.

## 4. What each side would do

- **IS:** §5.2 states word 28 and the image's load rule; O-51's `.const` range is the
  image's constant part.
- **TI:** nothing in RTL. The launch block is memory, and none of the 14 core kernels has
  a global. A harness that runs a kernel with globals pokes the image, its relocations
  and word 28, as ccv-sim's would.
- **CP:** the layout, an image section and its relocation list in the object, the pair
  lowering, and ccv-sim and test support. Then the CoreMark-derived workload's state
  benchmark runs unchanged.
