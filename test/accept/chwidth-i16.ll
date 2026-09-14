; 16-bit element width, compiler-generated (F-3).
;
; The point is not the arithmetic, it is the mode switches around it. §1 makes
; element width per-register STATE, so `add` at 16 bits is the same opcode as
; `add` at 32 and the difference lives in `chwidth` instructions that
; CCVInsertChwidth has to place. Three of them for one add is the honest cost,
; and it is the number F-3 asked for.
;
; Also pins that the store's BASE ADDRESS stays 32-bit: §3 takes transfer size
; from `rdata`'s chwidth alone, and an address is never narrow (invariant 11).
target triple = "ccv"

define void @k(ptr addrspace(3) %out, i16 %a, i16 %b) {
entry:
  %s = add i16 %a, %b
  store i16 %s, ptr addrspace(3) %out, align 2
  ret void
}

; zext is free under O-38: widening clears the exposed bits, which is what a
; zero-extension is. The only instruction it costs is the `chwidth` that the
; width change needs anyway.
define void @zext_is_free(ptr addrspace(3) %out, i16 %a, i16 %b) {
entry:
  %s = add i16 %a, %b
  %w = zext i16 %s to i32
  store i32 %w, ptr addrspace(3) %out, align 4
  ret void
}
