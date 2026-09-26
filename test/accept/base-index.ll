define void @k() {
  %rb  = load i32, ptr addrspace(4) inttoptr (i64 131104 to ptr addrspace(4)), align 4
  %rc  = load i32, ptr addrspace(4) inttoptr (i64 131112 to ptr addrspace(4)), align 4
  %tid = call i32 @llvm.nvvm.read.ptx.sreg.tid.x()
  %zb  = zext i32 %rb to i64
  %wb  = shl i64 %zb, 16
  %zi  = zext i32 %tid to i64
  %ab  = add i64 %wb, %zi
  %pb  = inttoptr i64 %ab to ptr
  %v   = load float, ptr %pb, align 4
  %zc  = zext i32 %rc to i64
  %wc  = shl i64 %zc, 16
  %ac  = add i64 %wc, %zi
  %pc  = inttoptr i64 %ac to ptr
  store float %v, ptr %pc, align 4
  ret void
}
declare i32 @llvm.nvvm.read.ptx.sreg.tid.x()
