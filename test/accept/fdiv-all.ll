; Software fp32 division (F-49, O-36), driven from memory so that
; tools/check-fdiv.sh can feed adversarial operands.
;
; The claim under test is "correctly rounded whenever the result is normal",
; which is a bit-exact claim about every input, not an error bound. The cases
; that break a divide sequence are not the obvious ones: operands at opposite
; ends of the exponent range, where an intermediate overflows or goes subnormal,
; and quotients that land a hair either side of a rounding boundary. Neither is
; reachable by dividing small round numbers.
declare i32 @llvm.nvvm.read.ptx.sreg.tid.x()
define void @k() {
entry:
  %t   = call i32 @llvm.nvvm.read.ptx.sreg.tid.x()
  %wb  = load i32, ptr addrspace(4) inttoptr (i64 131104 to ptr addrspace(4)), align 4, !invariant.load !0
  %e   = zext i32 %wb to i64
  %w   = shl nuw nsw i64 %e, 16
  %p   = inttoptr i64 %w to ptr

  %zt  = zext i32 %t to i64
  %pa  = getelementptr inbounds float, ptr %p, i64 %zt
  %a   = load float, ptr %pa, align 4
  %i2  = add i32 %t, 256
  %z2  = zext i32 %i2 to i64
  %pb  = getelementptr inbounds float, ptr %p, i64 %z2
  %b   = load float, ptr %pb, align 4

  %q   = fdiv float %a, %b

  %i3  = add i32 %t, 512
  %z3  = zext i32 %i3 to i64
  %g   = getelementptr inbounds float, ptr %p, i64 %z3
  store float %q, ptr %g, align 4
  ret void
}
!0 = !{}
