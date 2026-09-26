; `chwidth.multi` earns its format only when several registers change width at
; one point (§3, O-6: "a kernel entering a packed section typically reconfigures
; several at once. Setting them in one instruction collapses N drain events into
; one").
;
; Four 16-bit loads from one shared base at immediate offsets: four narrow
; definitions with no 32-bit use of those registers between them, so hoisting
; can bring all four width changes together and one `chwidth.multi` replaces
; them.
;
; The contrast is test/bench/vadd16.cu, where the transitions are separated by
; address arithmetic on the very registers being narrowed and NO amount of
; hoisting can merge them. Both shapes are real; F-69 records that only this one
; pays.
target triple = "ccv"

define void @k(ptr addrspace(3) %p, ptr addrspace(3) %out) {
entry:
  %g0 = getelementptr inbounds i16, ptr addrspace(3) %p, i32 0
  %g1 = getelementptr inbounds i16, ptr addrspace(3) %p, i32 1
  %g2 = getelementptr inbounds i16, ptr addrspace(3) %p, i32 2
  %g3 = getelementptr inbounds i16, ptr addrspace(3) %p, i32 3
  %a = load i16, ptr addrspace(3) %g0, align 2
  %b = load i16, ptr addrspace(3) %g1, align 2
  %c = load i16, ptr addrspace(3) %g2, align 2
  %d = load i16, ptr addrspace(3) %g3, align 2
  %s0 = add i16 %a, %b
  %s1 = add i16 %c, %d
  %s = add i16 %s0, %s1
  store i16 %s, ptr addrspace(3) %out, align 2
  ret void
}
