target datalayout = "e-i64:64-i128:128-v16:16-v32:32-n16:32:64"
target triple = "nvptx64-nvidia-cuda"

%struct.__nv_fp8_e4m3 = type { i8 }
%struct.__nv_fp8_e5m2 = type { i8 }

; Function Attrs: convergent mustprogress norecurse nounwind memory(argmem: readwrite)
define dso_local void @to_e4m3(ptr nocapture noundef writeonly %0, ptr nocapture noundef readonly %1) local_unnamed_addr #0 {
  %3 = tail call noundef i32 @llvm.nvvm.read.ptx.sreg.tid.x()
  %4 = sext i32 %3 to i64
  %5 = getelementptr inbounds float, ptr %1, i64 %4
  %6 = load float, ptr %5, align 4, !tbaa !11
  %7 = tail call i16 asm "{cvt.rn.satfinite.e4m3x2.f32 $0, $2, $1;}\0A", "=h,f,f"(float %6, float 0.000000e+00) #2, !srcloc !15
  %8 = trunc i16 %7 to i8
  %9 = getelementptr inbounds i8, ptr %0, i64 %4
  store i8 %8, ptr %9, align 1, !tbaa !16
  ret void
}

; Function Attrs: convergent mustprogress norecurse nounwind memory(argmem: readwrite)
define dso_local void @to_e5m2(ptr nocapture noundef writeonly %0, ptr nocapture noundef readonly %1) local_unnamed_addr #0 {
  %3 = tail call noundef i32 @llvm.nvvm.read.ptx.sreg.tid.x()
  %4 = sext i32 %3 to i64
  %5 = getelementptr inbounds float, ptr %1, i64 %4
  %6 = load float, ptr %5, align 4, !tbaa !11
  %7 = tail call i16 asm "{cvt.rn.satfinite.e5m2x2.f32 $0, $2, $1;}\0A", "=h,f,f"(float %6, float 0.000000e+00) #2, !srcloc !17
  %8 = trunc i16 %7 to i8
  %9 = getelementptr inbounds i8, ptr %0, i64 %4
  store i8 %8, ptr %9, align 1, !tbaa !16
  ret void
}

; Function Attrs: convergent mustprogress norecurse nounwind memory(argmem: readwrite)
define dso_local void @to_e4m3x2(ptr nocapture noundef writeonly %0, ptr nocapture noundef readonly %1) local_unnamed_addr #0 {
  %3 = tail call noundef i32 @llvm.nvvm.read.ptx.sreg.tid.x()
  %4 = shl nsw i32 %3, 1
  %5 = sext i32 %4 to i64
  %6 = getelementptr inbounds float, ptr %1, i64 %5
  %7 = load float, ptr %6, align 4, !tbaa !11
  %8 = or disjoint i32 %4, 1
  %9 = sext i32 %8 to i64
  %10 = getelementptr inbounds float, ptr %1, i64 %9
  %11 = load float, ptr %10, align 4, !tbaa !11
  %12 = tail call noundef i16 asm "{cvt.rn.satfinite.e4m3x2.f32 $0, $2, $1;}\0A", "=h,f,f"(float %7, float %11) #2, !srcloc !18
  %13 = sext i32 %3 to i64
  %14 = getelementptr inbounds i16, ptr %0, i64 %13
  store i16 %12, ptr %14, align 2, !tbaa !19
  ret void
}

; Function Attrs: convergent mustprogress norecurse nounwind memory(argmem: readwrite)
define dso_local void @from_e4m3(ptr nocapture noundef writeonly %0, ptr nocapture noundef readonly %1) local_unnamed_addr #0 {
  %3 = tail call noundef i32 @llvm.nvvm.read.ptx.sreg.tid.x()
  %4 = sext i32 %3 to i64
  %5 = getelementptr inbounds %struct.__nv_fp8_e4m3, ptr %1, i64 %4
  %6 = load i8, ptr %5, align 1, !tbaa !21
  %7 = zext i8 %6 to i16
  %8 = tail call i32 asm "{cvt.rn.f16x2.e4m3x2 $0, $1;}\0A", "=r,h"(i16 %7) #2, !srcloc !23
  %9 = trunc i32 %8 to i16
  %10 = tail call contract noundef float asm "{cvt.f32.f16 $0, $1;}\0A", "=f,h"(i16 %9) #2, !srcloc !24
  %11 = getelementptr inbounds float, ptr %0, i64 %4
  store float %10, ptr %11, align 4, !tbaa !11
  ret void
}

; Function Attrs: convergent mustprogress norecurse nounwind memory(argmem: readwrite)
define dso_local void @from_e5m2(ptr nocapture noundef writeonly %0, ptr nocapture noundef readonly %1) local_unnamed_addr #0 {
  %3 = tail call noundef i32 @llvm.nvvm.read.ptx.sreg.tid.x()
  %4 = sext i32 %3 to i64
  %5 = getelementptr inbounds %struct.__nv_fp8_e5m2, ptr %1, i64 %4
  %6 = load i8, ptr %5, align 1, !tbaa !25
  %7 = zext i8 %6 to i16
  %8 = tail call i32 asm "{cvt.rn.f16x2.e5m2x2 $0, $1;}\0A", "=r,h"(i16 %7) #2, !srcloc !27
  %9 = trunc i32 %8 to i16
  %10 = tail call contract noundef float asm "{cvt.f32.f16 $0, $1;}\0A", "=f,h"(i16 %9) #2, !srcloc !24
  %11 = getelementptr inbounds float, ptr %0, i64 %4
  store float %10, ptr %11, align 4, !tbaa !11
  ret void
}

; Function Attrs: convergent mustprogress norecurse nounwind memory(argmem: readwrite)
define dso_local void @from_e5m2x2(ptr nocapture noundef writeonly %0, ptr nocapture noundef readonly %1) local_unnamed_addr #0 {
  %3 = tail call noundef i32 @llvm.nvvm.read.ptx.sreg.tid.x()
  %4 = sext i32 %3 to i64
  %5 = getelementptr inbounds i16, ptr %1, i64 %4
  %6 = load i16, ptr %5, align 2, !tbaa !19
  %7 = tail call i32 asm "{cvt.rn.f16x2.e5m2x2 $0, $1;}\0A", "=r,h"(i16 %6) #2, !srcloc !27
  %8 = getelementptr inbounds i32, ptr %0, i64 %4
  store i32 %7, ptr %8, align 4, !tbaa !28
  ret void
}

; Function Attrs: convergent mustprogress norecurse nounwind memory(argmem: readwrite)
define dso_local void @half_round_trip(ptr nocapture noundef writeonly %0, ptr nocapture noundef readonly %1) local_unnamed_addr #0 {
  %3 = tail call noundef i32 @llvm.nvvm.read.ptx.sreg.tid.x()
  %4 = sext i32 %3 to i64
  %5 = getelementptr inbounds float, ptr %1, i64 %4
  %6 = load float, ptr %5, align 4, !tbaa !11
  %7 = tail call i16 asm "{  cvt.rn.f16.f32 $0, $1;}\0A", "=h,f"(float %6) #2, !srcloc !30
  %8 = tail call contract noundef float asm "{  cvt.f32.f16 $0, $1;}\0A", "=f,h"(i16 %7) #2, !srcloc !31
  %9 = getelementptr inbounds float, ptr %0, i64 %4
  store float %8, ptr %9, align 4, !tbaa !11
  ret void
}

; Function Attrs: mustprogress nocallback nofree nosync nounwind speculatable willreturn memory(none)
declare noundef i32 @llvm.nvvm.read.ptx.sreg.tid.x() #1

attributes #0 = { convergent mustprogress norecurse nounwind memory(argmem: readwrite) "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="sm_89" "target-features"="+ptx83,+sm_89" "uniform-work-group-size"="true" }
attributes #1 = { mustprogress nocallback nofree nosync nounwind speculatable willreturn memory(none) }
attributes #2 = { convergent nounwind memory(none) }

!nvvm.annotations = !{!0, !1, !2, !3, !4, !5, !6}
!llvm.module.flags = !{!7, !8, !9}
!llvm.ident = !{!10}

!0 = !{ptr @to_e4m3, !"kernel", i32 1}
!1 = !{ptr @to_e5m2, !"kernel", i32 1}
!2 = !{ptr @to_e4m3x2, !"kernel", i32 1}
!3 = !{ptr @from_e4m3, !"kernel", i32 1}
!4 = !{ptr @from_e5m2, !"kernel", i32 1}
!5 = !{ptr @from_e5m2x2, !"kernel", i32 1}
!6 = !{ptr @half_round_trip, !"kernel", i32 1}
!7 = !{i32 1, !"wchar_size", i32 4}
!8 = !{i32 4, !"nvvm-reflect-ftz", i32 0}
!9 = !{i32 7, !"frame-pointer", i32 2}
!10 = !{!"Ubuntu clang version 18.1.3 (1ubuntu1)"}
!11 = !{!12, !12, i64 0}
!12 = !{!"float", !13, i64 0}
!13 = !{!"omnipotent char", !14, i64 0}
!14 = !{!"Simple C++ TBAA"}
!15 = !{i64 12166880}
!16 = !{!13, !13, i64 0}
!17 = !{i64 12166731}
!18 = !{i64 12168270}
!19 = !{!20, !20, i64 0}
!20 = !{!"short", !13, i64 0}
!21 = !{!22, !13, i64 0}
!22 = !{!"_ZTS13__nv_fp8_e4m3", !13, i64 0}
!23 = !{i64 12176415}
!24 = !{i64 12168999}
!25 = !{!26, !13, i64 0}
!26 = !{!"_ZTS13__nv_fp8_e5m2", !13, i64 0}
!27 = !{i64 12176323}
!28 = !{!29, !29, i64 0}
!29 = !{!"int", !13, i64 0}
!30 = !{i64 2154357176}
!31 = !{i64 2154421916}
