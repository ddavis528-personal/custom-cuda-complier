; expect: double-precision (FP64) arithmetic
; FP64 is out of scope for V1 (DA's response IS-13; ISA v1.8 section 10).
; `double` in device code must be diagnosed, not emulated. Before the rule,
; this aborted in the type legalizer with no diagnostic.
define void @k(ptr addrspace(1) %p, float %x) {
  %d = fpext float %x to double
  %m = fmul double %d, 1.000000001
  %f = fptrunc double %m to float
  store float %f, ptr addrspace(1) %p
  ret void
}
