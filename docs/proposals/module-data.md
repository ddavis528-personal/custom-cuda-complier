# Proposal — Where a module's data lives (CP-10, F-162)

**Status:** proposed 2026-10-22, for IS (ISA v1.9 §5.2, the launch ABI) and TI (the launch
block). Nothing is built until they answer; the compiler diagnoses a global today.
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
