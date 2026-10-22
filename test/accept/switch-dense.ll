; A dense switch with an unreachable default became a jump table, indexed at
; the pointer's width, and stopped the type legalizer (the CoreMark-derived
; port's state machine). There are no jump tables: compares and bit tests.
define void @k() {
entry:
  %x = load i32, ptr addrspace(4) inttoptr (i64 131128 to ptr addrspace(4)), align 4
  switch i32 %x, label %u [
    i32 0, label %j
    i32 1, label %j
    i32 2, label %j
    i32 3, label %a
    i32 4, label %a
    i32 5, label %b
    i32 6, label %b
    i32 7, label %c
  ]
a:
  br label %j
b:
  br label %j
c:
  br label %j
u:
  unreachable
j:
  %v = phi i32 [ 9, %c ], [ 5, %b ], [ 3, %a ], [ 1, %entry ], [ 1, %entry ], [ 1, %entry ]
  store i32 %v, ptr addrspace(1) inttoptr (i64 196608 to ptr addrspace(1)), align 4
  ret void
}
