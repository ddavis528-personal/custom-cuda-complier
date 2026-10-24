; F-195: a truncation to 16 bits whose source has its high half set, read
; back at 32 bits. The 16-bit shift right is selected through the 32-bit one,
; which is right only if the truncation cleared bits 16 to 31.
;
; Written by hand, in the shape clang emits, because instcombine rewrites the
; C equivalent, `(unsigned short)(x >> 5) >> (t & 7)`, at 32 bits, and
; tools/check-trunc16.sh lowers the kernel arguments without it. Each piece
; keeps the DAG from doing the same: the source is a shift, since a truncated
; load becomes a 16-bit load, and the amount is the thread's, since constant
; shifts combine.
target datalayout = "e-i64:64-i128:128-v16:16-v32:32-n16:32:64"
target triple = "nvptx64-nvidia-cuda"

define dso_local void @trunc16(ptr noundef writeonly %0, ptr noundef readonly %1) #0 {
  %3 = tail call noundef i32 @llvm.nvvm.read.ptx.sreg.tid.x()
  %4 = sext i32 %3 to i64
  %5 = getelementptr inbounds i32, ptr %1, i64 %4
  %6 = load i32, ptr %5, align 4
  %7 = lshr i32 %6, 5
  %8 = trunc i32 %7 to i16
  %9 = trunc i32 %3 to i16
  %10 = and i16 %9, 7
  %11 = lshr i16 %8, %10
  %12 = zext i16 %11 to i32
  %13 = getelementptr inbounds i32, ptr %0, i64 %4
  store i32 %12, ptr %13, align 4
  ret void
}

declare noundef i32 @llvm.nvvm.read.ptx.sreg.tid.x() #1

attributes #0 = { nounwind "target-cpu"="sm_89" "target-features"="+ptx83,+sm_89" }
attributes #1 = { nounwind readnone }

!nvvm.annotations = !{!0}
!0 = !{ptr @trunc16, !"kernel", i32 1}
