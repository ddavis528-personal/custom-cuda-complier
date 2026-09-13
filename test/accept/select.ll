; F-42: `select` hung the compiler. SELECT was Expand, which expands to
; SELECT_CC, which was also Expand and expands back to SELECT -- an infinite
; legalization loop, so ccg-llc spun rather than failing. Latent since Step 3:
; no kernel produced a select until the division expansion did, because every
; conditional until then became real control flow. §4 point 19 is `sel`.
define void @k(i32 %a, i32 %b, float %x, float %y, ptr addrspace(3) %p) {
  %c = icmp eq i32 %a, 0
  %i = select i1 %c, i32 %a, i32 %b
  %f = select i1 %c, float %x, float %y
  store i32 %i, ptr addrspace(3) %p
  %q = getelementptr i32, ptr addrspace(3) %p, i32 1
  store float %f, ptr addrspace(3) %q
  ret void
}
