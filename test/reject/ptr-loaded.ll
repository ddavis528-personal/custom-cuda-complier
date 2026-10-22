; A pointer read from memory ATOMICALLY. A pointer in memory is the host's
; flat 64-bit address (ISA v1.9 §5.7), read as two 32-bit loads, and two loads
; are not one atomic access, so this is diagnosed rather than torn. The plain
; load -- `multi_tensor_apply`'s table, F-147 -- is built and executed by
; tools/check-ptrmem.sh.
define void @k(ptr %table, i32 %i, float %v) {
  %p = getelementptr ptr, ptr %table, i32 %i
  %t = load atomic ptr, ptr %p monotonic, align 8
  store float %v, ptr %t, align 4
  ret void
}
