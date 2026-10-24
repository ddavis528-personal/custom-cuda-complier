; expect: a kernel's pointer argument
; A kernel whose pointer argument is still an argument: ccv-lower-kernel-args
; was not run, so the 64-bit pointer reached LLVM's store expansion, which
; crashed rather than diagnosing anything (F-186's open item).
define void @k(ptr addrspace(1) %p, i32 %a, i32 %b) {
  %s = xor i32 %a, %b
  store i32 %s, ptr addrspace(1) %p
  ret void
}
