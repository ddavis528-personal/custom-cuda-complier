; O-27: the barrier epoch is tracked per warp in hardware, so the compressed
; `bar.wait #id` means "wait until my own arrival has retired" and needs no
; operand -- correct at every iteration. This was previously rejected, because
; a phase immediate cannot alternate across dynamic executions (F-30).
declare void @llvm.nvvm.barrier0()
define void @k(i32 %n) {
entry:
  br label %loop
loop:
  %i = phi i32 [ 0, %entry ], [ %j, %loop ]
  call void @llvm.nvvm.barrier0()
  %j = add i32 %i, 1
  %c = icmp slt i32 %j, %n
  br i1 %c, label %loop, label %exit
exit:
  ret void
}
