; A pointer READ back out of memory -- the direction the invariant-11 group
; missed. This is `multi_tensor_apply`'s access: a by-value struct holding an
; array of tensor pointers, indexed at runtime, so a pointer is never stored
; and one is loaded on every access. F-147.
define void @k(ptr %table, i32 %i, float %v) {
  %p = getelementptr ptr, ptr %table, i32 %i
  %t = load ptr, ptr %p, align 8
  store float %v, ptr %t, align 4
  ret void
}
