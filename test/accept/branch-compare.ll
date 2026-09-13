define void @k() {
  %n   = load i32, ptr addrspace(4) inttoptr (i64 131128 to ptr addrspace(4)), align 4
  %tid = call i32 @llvm.nvvm.read.ptx.sreg.tid.x()
  %c   = icmp slt i32 %tid, %n
  br i1 %c, label %t, label %e
t:
  store i32 %tid, ptr addrspace(1) inttoptr (i64 196616 to ptr addrspace(1)), align 4
  br label %e
e:
  ret void
}
declare i32 @llvm.nvvm.read.ptx.sreg.tid.x()
