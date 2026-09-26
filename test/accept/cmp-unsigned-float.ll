; F-24: unsigned and FP compares. gt/ge come from swapping operands, so only
; lt/le need opcode points per class; `une` is what C's float `!=` produces and
; maps to setp.ne.f, the exact complement of setp.eq.f.
define void @k(i32 %a, i32 %b, float %x, float %y, ptr addrspace(4) %sink) {
entry:
  %u1 = icmp ult i32 %a, %b
  br i1 %u1, label %b1, label %b2
b1:
  %u2 = icmp uge i32 %a, %b
  br i1 %u2, label %b2, label %b3
b2:
  %f1 = fcmp olt float %x, %y
  br i1 %f1, label %b3, label %b4
b3:
  %f2 = fcmp une float %x, %y
  br i1 %f2, label %b4, label %b5
b4:
  %f3 = fcmp oeq float %x, %y
  br i1 %f3, label %b5, label %b5
b5:
  ret void
}
