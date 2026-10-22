; A predicate that is true in every lane: `pmov p, 0xffffffff`. Selection
; sign-normalizes the i32 immediate to -1, which the encoder's fit check
; refused for a 32-bit field until the accept suite built objects.
define void @k() {
e:
  %n = load i32, ptr addrspace(4) inttoptr (i64 131128 to ptr addrspace(4)), align 4
  br label %l
l:
  %i = phi i32 [ 0, %e ], [ %i1, %l ]
  %f = phi i1 [ true, %e ], [ %c, %l ]
  %v = select i1 %f, i32 5, i32 7
  store volatile i32 %v, ptr addrspace(1) inttoptr (i64 196608 to ptr addrspace(1))
  %i1 = add i32 %i, 1
  %c = icmp slt i32 %i1, 3
  %d = icmp slt i32 %i1, %n
  br i1 %d, label %l, label %x
x:
  ret void
}
