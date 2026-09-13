; F-31: `.shared` is flat 32-bit (§5.1) -- no window, no launch-block
; indirection -- so a shared object's address is its offset in the CTA's
; allocation, known at compile time. CCGLowerShared lays them out and replaces
; each global with an inttoptr constant; ordinary patterns select the access.
; The DAGCombine that folds windowed addresses must NOT see these: it matches
; any constant address, so sdata[0] would become an ld.global of the offset.
@sd = internal addrspace(3) global [256 x float] undef, align 4
define void @k(i32 %t, float %v, i32 %n) {
entry:
  %z = zext i32 %t to i64
  %g = getelementptr inbounds [256 x float], ptr addrspace(3) @sd, i64 0, i64 %z
  store float %v, ptr addrspace(3) %g, align 4
  %c = icmp slt i32 %t, %n
  br i1 %c, label %body, label %exit
body:
  %l = load float, ptr addrspace(3) %g, align 4
  %a = fadd float %l, %v
  store float %a, ptr addrspace(3) %g, align 4
  br label %exit
exit:
  ret void
}
