; `sext i16 -> i32` is ONE instruction (F-66, via O-34's conversion block).
;
; Both of O-34's format codes here are "signed integer" and the widths come from
; the registers' `chwidth`, so §4 point 104 is s8→s32, s16→s32 and s4→s32 alike.
; The obvious lowering is three instructions -- widen, shift left, shift
; arithmetic right -- and §3's shift-immediate forms carry four bits, so a shift
; by 16 needs a register too.
;
; Widening alone is a ZERO-extension after O-38, which is why the sign needs an
; instruction at all.
target triple = "ccv"
declare i32 @llvm.nvvm.read.ptx.sreg.tid.x()

define void @k(ptr addrspace(3) %out, i16 %a) {
entry:
  %w = sext i16 %a to i32
  store i32 %w, ptr addrspace(3) %out, align 4
  ret void
}
