; All four division forms, driven from memory so a test script can feed
; adversarial operands. Used by tools/check-div.sh, which compares against
; exact integer division over edge cases and a large pseudo-random sample --
; the float-reciprocal sequence is only worth having if it is exactly right,
; and "it worked on sixteen values" is not evidence of that.
declare i32 @llvm.nvvm.read.ptx.sreg.tid.x()
define void @k() {
entry:
  %t   = call i32 @llvm.nvvm.read.ptx.sreg.tid.x()
  %wb  = load i32, ptr addrspace(4) inttoptr (i64 131104 to ptr addrspace(4)), align 4, !invariant.load !0
  %e   = zext i32 %wb to i64
  %w   = shl nuw nsw i64 %e, 16
  %p   = inttoptr i64 %w to ptr

  ; Index arithmetic stays in i32 and is widened only at the GEP -- that is the
  ; shape §5.1's addressing mode recognises (F-20).
  %zt  = zext i32 %t to i64
  %pn  = getelementptr inbounds i32, ptr %p, i64 %zt
  %n   = load i32, ptr %pn, align 4
  %i2  = add i32 %t, 256
  %z2  = zext i32 %i2 to i64
  %pd  = getelementptr inbounds i32, ptr %p, i64 %z2
  %d   = load i32, ptr %pd, align 4

  %q   = udiv i32 %n, %d
  %r   = urem i32 %n, %d
  %sq  = sdiv i32 %n, %d
  %sr  = srem i32 %n, %d

  %i3  = add i32 %t, 512
  %z3  = zext i32 %i3 to i64
  %g1  = getelementptr inbounds i32, ptr %p, i64 %z3
  store i32 %q, ptr %g1, align 4
  %i4  = add i32 %t, 768
  %z4  = zext i32 %i4 to i64
  %g2  = getelementptr inbounds i32, ptr %p, i64 %z4
  store i32 %r, ptr %g2, align 4
  %i5  = add i32 %t, 1024
  %z5  = zext i32 %i5 to i64
  %g3  = getelementptr inbounds i32, ptr %p, i64 %z5
  store i32 %sq, ptr %g3, align 4
  %i6  = add i32 %t, 1280
  %z6  = zext i32 %i6 to i64
  %g4  = getelementptr inbounds i32, ptr %p, i64 %z6
  store i32 %sr, ptr %g4, align 4
  ret void
}
!0 = !{}
