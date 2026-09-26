define void @k() {
  %v = load i32, ptr addrspace(4) inttoptr (i64 131128 to ptr addrspace(4)), align 4
  store i32 %v, ptr addrspace(1) inttoptr (i64 196616 to ptr addrspace(1)), align 4
  ret void }
