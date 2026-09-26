; The window arithmetic is formed in one block and used in another. Before
; CCVWindowRemat this reached the type legalizer as a cross-block i64 and
; aborted with "Do not know how to expand this operator's operand" -- no
; diagnostic, just a crash. Any kernel with control flow hits this; vadd only
; escaped it by being a single basic block.
define void @k(i32 %i, i32 %n) {
entry:
  %rb = load i32, ptr addrspace(4) inttoptr (i64 131104 to ptr addrspace(4)), align 4, !invariant.load !0
  %e  = zext i32 %rb to i64
  %w  = shl nuw nsw i64 %e, 16
  %p  = inttoptr i64 %w to ptr
  %c  = icmp slt i32 %i, %n
  br i1 %c, label %body, label %exit
body:
  %zi = zext i32 %i to i64
  %g  = getelementptr inbounds float, ptr %p, i64 %zi
  store float 0.000000e+00, ptr %g, align 4
  br label %exit
exit:
  ret void
}
!0 = !{}
