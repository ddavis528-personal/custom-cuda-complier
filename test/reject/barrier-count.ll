; expect: named barrier with a variable or out-of-range operand
; bar.sync a, b with a thread count known only at run time: bar.init's count
; is an immediate (O-74), so there is nothing to encode it in.
define void @k(i32 %n) {
  call void @llvm.nvvm.barrier.sync.cnt(i32 1, i32 %n)
  ret void
}
declare void @llvm.nvvm.barrier.sync.cnt(i32, i32)
