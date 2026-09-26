; O-33: a long warp-uniform chain feeding one divergent use. Every `a` below
; depends only on `n`, which comes from the launch block and is CTA-wide, so
; the whole chain runs on lane 0 and one broadcast distributes the result.
;
; tools/check-mask.sh executes this with masking on and off and requires the
; results to be identical -- the transformation is a power optimisation and
; must be invisible in the answer.
declare i32 @llvm.nvvm.read.ptx.sreg.tid.x()
define void @k() {
entry:
  %t  = call i32 @llvm.nvvm.read.ptx.sreg.tid.x()
  %n  = load i32, ptr addrspace(4) inttoptr (i64 131120 to ptr addrspace(4)), align 4, !invariant.load !0
  ; --- warp-uniform chain: depends on %n only ---------------------------
  %a1 = mul i32 %n,  3
  %a2 = add i32 %a1, 1
  %a3 = lshr i32 %a2, 2
  %a4 = xor i32 %a2, %a3
  %a5 = add i32 %a4, 7
  %a6 = mul i32 %a5, 5
  %a7 = lshr i32 %a6, 3
  %a8 = xor i32 %a6, %a7
  %a9 = add i32 %a8, 11
  ; --- crossing: uniform value meets the lane index ----------------------
  %r  = add i32 %a9, %t
  %wb = load i32, ptr addrspace(4) inttoptr (i64 131104 to ptr addrspace(4)), align 4, !invariant.load !0
  %e  = zext i32 %wb to i64
  %w  = shl nuw nsw i64 %e, 16
  %p  = inttoptr i64 %w to ptr
  %zt = zext i32 %t to i64
  %g  = getelementptr inbounds i32, ptr %p, i64 %zt
  store i32 %r, ptr %g, align 4
  ret void
}
!0 = !{}
