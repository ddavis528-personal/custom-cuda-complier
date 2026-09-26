; O-32: Format C" is an unpredicated compare. Before it, every compare had to
; manufacture its guard first (`por pd, !pd, pd`, O-24) because Formats C and C'
; carry a mandatory qualifier and §1 has no always-true predicate. That was 13%
; of dynamically issued instructions in the reduction kernels.
;
; This exercises all three operand classes -- signed, unsigned and FP -- so the
; shared opcode map (O-26) is covered in the new format too.
define void @k(i32 %a, i32 %b, float %x, float %y, ptr addrspace(3) %p) {
entry:
  %c1 = icmp slt i32 %a, %b
  br i1 %c1, label %t1, label %t2
t1:
  %c2 = icmp ult i32 %a, %b
  br i1 %c2, label %t2, label %t3
t2:
  %c3 = fcmp olt float %x, %y
  br i1 %c3, label %t3, label %t4
t3:
  %c4 = fcmp une float %x, %y
  br i1 %c4, label %t4, label %t4
t4:
  store i32 %a, ptr addrspace(3) %p
  ret void
}
