; expect: 64-bit atomic
; A 64-bit atomic: Format M's atomics are one word (O-72), and there is no
; 64-bit compare-and-swap to build one from. It must be diagnosed, not left to
; AtomicExpand, which would make it a library call nothing defines.
define void @k(ptr addrspace(1) %p, i64 %v) {
  %old = atomicrmw add ptr addrspace(1) %p, i64 %v monotonic, align 8
  ret void
}
