; IEEE sqrtf and 1.0f/x over an approximate SFU (IS-12), driven from memory so
; that tools/check-fdiv.sh can feed every class of operand: x at [t], sqrt(x)
; at [t + 256] and 1/x at [t + 512].
declare i32 @llvm.nvvm.read.ptx.sreg.tid.x()
declare float @llvm.sqrt.f32(float)
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
  %s   = call float @llvm.sqrt.f32(float %a)
  %r   = fdiv float 1.0, %a
  %i2  = add i32 %t, 256
  %z2  = zext i32 %i2 to i64
  %ps  = getelementptr inbounds float, ptr %p, i64 %z2
  store float %s, ptr %ps, align 4
  %i3  = add i32 %t, 512
  %z3  = zext i32 %i3 to i64
  %pr  = getelementptr inbounds float, ptr %p, i64 %z3
  store float %r, ptr %pr, align 4
  ret void
}
!0 = !{}
