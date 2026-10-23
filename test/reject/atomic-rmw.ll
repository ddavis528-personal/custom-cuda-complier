; An atomic read-modify-write: Format M addresses .global as (rbase << 16)
; plus an immediate, with no index register, so atomicAdd(&bins[b], 1) has no
; encoding (CP-26). It must be diagnosed; before the rule, the type legalizer
; aborted ("Do not know how to expand this operator's operand").
define void @k(ptr addrspace(1) %bins, i32 %x) {
  %b = and i32 %x, 63
  %i = zext i32 %b to i64
  %p = getelementptr i32, ptr addrspace(1) %bins, i64 %i
  %old = atomicrmw add ptr addrspace(1) %p, i32 1 monotonic, align 4
  ret void
}
