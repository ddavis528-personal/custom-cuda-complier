target datalayout = "e-i64:64-i128:128-v16:16-v32:32-n16:32:64"
target triple = "nvptx64-nvidia-cuda"

%struct.__nv_fp8_e4m3 = type { i8 }
%struct.__nv_fp8_e5m2 = type { i8 }
%struct.__nv_fp8x4_e4m3 = type { i32 }
%struct.__nv_fp8x4_e5m2 = type { i32 }

; Function Attrs: convergent mustprogress norecurse nounwind memory(argmem: readwrite)
define dso_local void @to_e4m3(ptr nocapture noundef writeonly %0, ptr nocapture noundef readonly %1) local_unnamed_addr #0 {
  %3 = tail call noundef i32 @llvm.nvvm.read.ptx.sreg.tid.x()
  %4 = sext i32 %3 to i64
  %5 = getelementptr inbounds float, ptr %1, i64 %4
  %6 = load float, ptr %5, align 4, !tbaa !17
  %7 = tail call i16 asm "{cvt.rn.satfinite.e4m3x2.f32 $0, $2, $1;}\0A", "=h,f,f"(float %6, float 0.000000e+00) #2, !srcloc !21
  %8 = trunc i16 %7 to i8
  %9 = getelementptr inbounds i8, ptr %0, i64 %4
  store i8 %8, ptr %9, align 1, !tbaa !22
  ret void
}

; Function Attrs: convergent mustprogress norecurse nounwind memory(argmem: readwrite)
define dso_local void @to_e5m2(ptr nocapture noundef writeonly %0, ptr nocapture noundef readonly %1) local_unnamed_addr #0 {
  %3 = tail call noundef i32 @llvm.nvvm.read.ptx.sreg.tid.x()
  %4 = sext i32 %3 to i64
  %5 = getelementptr inbounds float, ptr %1, i64 %4
  %6 = load float, ptr %5, align 4, !tbaa !17
  %7 = tail call i16 asm "{cvt.rn.satfinite.e5m2x2.f32 $0, $2, $1;}\0A", "=h,f,f"(float %6, float 0.000000e+00) #2, !srcloc !23
  %8 = trunc i16 %7 to i8
  %9 = getelementptr inbounds i8, ptr %0, i64 %4
  store i8 %8, ptr %9, align 1, !tbaa !22
  ret void
}

; Function Attrs: convergent mustprogress norecurse nounwind memory(argmem: readwrite)
define dso_local void @to_e4m3x2(ptr nocapture noundef writeonly %0, ptr nocapture noundef readonly %1) local_unnamed_addr #0 {
  %3 = tail call noundef i32 @llvm.nvvm.read.ptx.sreg.tid.x()
  %4 = shl nsw i32 %3, 1
  %5 = sext i32 %4 to i64
  %6 = getelementptr inbounds float, ptr %1, i64 %5
  %7 = load float, ptr %6, align 4, !tbaa !17
  %8 = or disjoint i32 %4, 1
  %9 = sext i32 %8 to i64
  %10 = getelementptr inbounds float, ptr %1, i64 %9
  %11 = load float, ptr %10, align 4, !tbaa !17
  %12 = tail call noundef i16 asm "{cvt.rn.satfinite.e4m3x2.f32 $0, $2, $1;}\0A", "=h,f,f"(float %7, float %11) #2, !srcloc !24
  %13 = sext i32 %3 to i64
  %14 = getelementptr inbounds i16, ptr %0, i64 %13
  store i16 %12, ptr %14, align 2, !tbaa !25
  ret void
}

; Function Attrs: convergent mustprogress norecurse nounwind memory(argmem: readwrite)
define dso_local void @from_e4m3(ptr nocapture noundef writeonly %0, ptr nocapture noundef readonly %1) local_unnamed_addr #0 {
  %3 = tail call noundef i32 @llvm.nvvm.read.ptx.sreg.tid.x()
  %4 = sext i32 %3 to i64
  %5 = getelementptr inbounds %struct.__nv_fp8_e4m3, ptr %1, i64 %4
  %6 = load i8, ptr %5, align 1, !tbaa !27
  %7 = zext i8 %6 to i16
  %8 = tail call i32 asm "{cvt.rn.f16x2.e4m3x2 $0, $1;}\0A", "=r,h"(i16 %7) #2, !srcloc !29
  %9 = trunc i32 %8 to i16
  %10 = tail call contract noundef float asm "{cvt.f32.f16 $0, $1;}\0A", "=f,h"(i16 %9) #2, !srcloc !30
  %11 = getelementptr inbounds float, ptr %0, i64 %4
  store float %10, ptr %11, align 4, !tbaa !17
  ret void
}

; Function Attrs: convergent mustprogress norecurse nounwind memory(argmem: readwrite)
define dso_local void @from_e5m2(ptr nocapture noundef writeonly %0, ptr nocapture noundef readonly %1) local_unnamed_addr #0 {
  %3 = tail call noundef i32 @llvm.nvvm.read.ptx.sreg.tid.x()
  %4 = sext i32 %3 to i64
  %5 = getelementptr inbounds %struct.__nv_fp8_e5m2, ptr %1, i64 %4
  %6 = load i8, ptr %5, align 1, !tbaa !31
  %7 = zext i8 %6 to i16
  %8 = tail call i32 asm "{cvt.rn.f16x2.e5m2x2 $0, $1;}\0A", "=r,h"(i16 %7) #2, !srcloc !33
  %9 = trunc i32 %8 to i16
  %10 = tail call contract noundef float asm "{cvt.f32.f16 $0, $1;}\0A", "=f,h"(i16 %9) #2, !srcloc !30
  %11 = getelementptr inbounds float, ptr %0, i64 %4
  store float %10, ptr %11, align 4, !tbaa !17
  ret void
}

; Function Attrs: convergent mustprogress norecurse nounwind memory(argmem: readwrite)
define dso_local void @from_e5m2x2(ptr nocapture noundef writeonly %0, ptr nocapture noundef readonly %1) local_unnamed_addr #0 {
  %3 = tail call noundef i32 @llvm.nvvm.read.ptx.sreg.tid.x()
  %4 = sext i32 %3 to i64
  %5 = getelementptr inbounds i16, ptr %1, i64 %4
  %6 = load i16, ptr %5, align 2, !tbaa !25
  %7 = tail call i32 asm "{cvt.rn.f16x2.e5m2x2 $0, $1;}\0A", "=r,h"(i16 %6) #2, !srcloc !33
  %8 = getelementptr inbounds i32, ptr %0, i64 %4
  store i32 %7, ptr %8, align 4, !tbaa !34
  ret void
}

; Function Attrs: convergent mustprogress norecurse nounwind memory(argmem: readwrite)
define dso_local void @half_round_trip(ptr nocapture noundef writeonly %0, ptr nocapture noundef readonly %1) local_unnamed_addr #0 {
  %3 = tail call noundef i32 @llvm.nvvm.read.ptx.sreg.tid.x()
  %4 = sext i32 %3 to i64
  %5 = getelementptr inbounds float, ptr %1, i64 %4
  %6 = load float, ptr %5, align 4, !tbaa !17
  %7 = tail call i16 asm "{  cvt.rn.f16.f32 $0, $1;}\0A", "=h,f"(float %6) #2, !srcloc !36
  %8 = tail call contract noundef float asm "{  cvt.f32.f16 $0, $1;}\0A", "=f,h"(i16 %7) #2, !srcloc !37
  %9 = getelementptr inbounds float, ptr %0, i64 %4
  store float %8, ptr %9, align 4, !tbaa !17
  ret void
}

; Function Attrs: convergent mustprogress norecurse nounwind memory(argmem: readwrite)
define dso_local void @dot_e4m3(ptr nocapture noundef %0, ptr nocapture noundef readonly %1, ptr nocapture noundef readonly %2) local_unnamed_addr #0 {
  %4 = tail call noundef i32 @llvm.nvvm.read.ptx.sreg.tid.x()
  %5 = sext i32 %4 to i64
  %6 = getelementptr inbounds %struct.__nv_fp8x4_e4m3, ptr %1, i64 %5
  %7 = load i32, ptr %6, align 4, !tbaa !38
  %8 = trunc i32 %7 to i16
  %9 = lshr i32 %7, 16
  %10 = trunc i32 %9 to i16
  %11 = tail call i32 asm "{cvt.rn.f16x2.e4m3x2 $0, $1;}\0A", "=r,h"(i16 %8) #2, !srcloc !29
  %12 = trunc i32 %11 to i16
  %13 = lshr i32 %11, 16
  %14 = trunc i32 %13 to i16
  %15 = tail call contract noundef float asm "{cvt.f32.f16 $0, $1;}\0A", "=f,h"(i16 %12) #2, !srcloc !30
  %16 = tail call contract noundef float asm "{cvt.f32.f16 $0, $1;}\0A", "=f,h"(i16 %14) #2, !srcloc !30
  %17 = tail call i32 asm "{cvt.rn.f16x2.e4m3x2 $0, $1;}\0A", "=r,h"(i16 %10) #2, !srcloc !29
  %18 = trunc i32 %17 to i16
  %19 = lshr i32 %17, 16
  %20 = trunc i32 %19 to i16
  %21 = tail call contract noundef float asm "{cvt.f32.f16 $0, $1;}\0A", "=f,h"(i16 %18) #2, !srcloc !30
  %22 = tail call contract noundef float asm "{cvt.f32.f16 $0, $1;}\0A", "=f,h"(i16 %20) #2, !srcloc !30
  %23 = getelementptr inbounds %struct.__nv_fp8x4_e4m3, ptr %2, i64 %5
  %24 = load i32, ptr %23, align 4, !tbaa !38
  %25 = trunc i32 %24 to i16
  %26 = lshr i32 %24, 16
  %27 = trunc i32 %26 to i16
  %28 = tail call i32 asm "{cvt.rn.f16x2.e4m3x2 $0, $1;}\0A", "=r,h"(i16 %25) #2, !srcloc !29
  %29 = trunc i32 %28 to i16
  %30 = lshr i32 %28, 16
  %31 = trunc i32 %30 to i16
  %32 = tail call contract noundef float asm "{cvt.f32.f16 $0, $1;}\0A", "=f,h"(i16 %29) #2, !srcloc !30
  %33 = tail call contract noundef float asm "{cvt.f32.f16 $0, $1;}\0A", "=f,h"(i16 %31) #2, !srcloc !30
  %34 = tail call i32 asm "{cvt.rn.f16x2.e4m3x2 $0, $1;}\0A", "=r,h"(i16 %27) #2, !srcloc !29
  %35 = trunc i32 %34 to i16
  %36 = lshr i32 %34, 16
  %37 = trunc i32 %36 to i16
  %38 = tail call contract noundef float asm "{cvt.f32.f16 $0, $1;}\0A", "=f,h"(i16 %35) #2, !srcloc !30
  %39 = tail call contract noundef float asm "{cvt.f32.f16 $0, $1;}\0A", "=f,h"(i16 %37) #2, !srcloc !30
  %40 = fmul contract float %15, %32
  %41 = fmul contract float %16, %33
  %42 = fadd contract float %40, %41
  %43 = fmul contract float %21, %38
  %44 = fadd contract float %42, %43
  %45 = fmul contract float %22, %39
  %46 = fadd contract float %44, %45
  %47 = getelementptr inbounds float, ptr %0, i64 %5
  %48 = load float, ptr %47, align 4, !tbaa !17
  %49 = fadd contract float %48, %46
  store float %49, ptr %47, align 4, !tbaa !17
  ret void
}

; Function Attrs: convergent mustprogress norecurse nounwind memory(argmem: readwrite)
define dso_local void @dot_e5m2(ptr nocapture noundef writeonly %0, ptr nocapture noundef readonly %1, ptr nocapture noundef readonly %2) local_unnamed_addr #0 {
  %4 = tail call noundef i32 @llvm.nvvm.read.ptx.sreg.tid.x()
  %5 = sext i32 %4 to i64
  %6 = getelementptr inbounds %struct.__nv_fp8x4_e5m2, ptr %1, i64 %5
  %7 = load i32, ptr %6, align 4, !tbaa !40
  %8 = trunc i32 %7 to i16
  %9 = lshr i32 %7, 16
  %10 = trunc i32 %9 to i16
  %11 = tail call i32 asm "{cvt.rn.f16x2.e5m2x2 $0, $1;}\0A", "=r,h"(i16 %8) #2, !srcloc !33
  %12 = trunc i32 %11 to i16
  %13 = lshr i32 %11, 16
  %14 = trunc i32 %13 to i16
  %15 = tail call contract noundef float asm "{cvt.f32.f16 $0, $1;}\0A", "=f,h"(i16 %12) #2, !srcloc !30
  %16 = tail call contract noundef float asm "{cvt.f32.f16 $0, $1;}\0A", "=f,h"(i16 %14) #2, !srcloc !30
  %17 = tail call i32 asm "{cvt.rn.f16x2.e5m2x2 $0, $1;}\0A", "=r,h"(i16 %10) #2, !srcloc !33
  %18 = trunc i32 %17 to i16
  %19 = lshr i32 %17, 16
  %20 = trunc i32 %19 to i16
  %21 = tail call contract noundef float asm "{cvt.f32.f16 $0, $1;}\0A", "=f,h"(i16 %18) #2, !srcloc !30
  %22 = tail call contract noundef float asm "{cvt.f32.f16 $0, $1;}\0A", "=f,h"(i16 %20) #2, !srcloc !30
  %23 = getelementptr inbounds %struct.__nv_fp8x4_e5m2, ptr %2, i64 %5
  %24 = load i32, ptr %23, align 4, !tbaa !40
  %25 = trunc i32 %24 to i16
  %26 = lshr i32 %24, 16
  %27 = trunc i32 %26 to i16
  %28 = tail call i32 asm "{cvt.rn.f16x2.e5m2x2 $0, $1;}\0A", "=r,h"(i16 %25) #2, !srcloc !33
  %29 = trunc i32 %28 to i16
  %30 = lshr i32 %28, 16
  %31 = trunc i32 %30 to i16
  %32 = tail call contract noundef float asm "{cvt.f32.f16 $0, $1;}\0A", "=f,h"(i16 %29) #2, !srcloc !30
  %33 = tail call contract noundef float asm "{cvt.f32.f16 $0, $1;}\0A", "=f,h"(i16 %31) #2, !srcloc !30
  %34 = tail call i32 asm "{cvt.rn.f16x2.e5m2x2 $0, $1;}\0A", "=r,h"(i16 %27) #2, !srcloc !33
  %35 = trunc i32 %34 to i16
  %36 = lshr i32 %34, 16
  %37 = trunc i32 %36 to i16
  %38 = tail call contract noundef float asm "{cvt.f32.f16 $0, $1;}\0A", "=f,h"(i16 %35) #2, !srcloc !30
  %39 = tail call contract noundef float asm "{cvt.f32.f16 $0, $1;}\0A", "=f,h"(i16 %37) #2, !srcloc !30
  %40 = fmul contract float %15, %32
  %41 = fmul contract float %16, %33
  %42 = fadd contract float %40, %41
  %43 = fmul contract float %21, %38
  %44 = fadd contract float %42, %43
  %45 = fmul contract float %22, %39
  %46 = fadd contract float %44, %45
  %47 = getelementptr inbounds float, ptr %0, i64 %5
  store float %46, ptr %47, align 4, !tbaa !17
  ret void
}

; Function Attrs: convergent mustprogress norecurse nounwind memory(argmem: readwrite)
define dso_local void @add_e4m3(ptr nocapture noundef writeonly %0, ptr nocapture noundef readonly %1, ptr nocapture noundef readonly %2) local_unnamed_addr #0 {
  %4 = tail call noundef i32 @llvm.nvvm.read.ptx.sreg.tid.x()
  %5 = sext i32 %4 to i64
  %6 = getelementptr inbounds %struct.__nv_fp8_e4m3, ptr %1, i64 %5
  %7 = load i8, ptr %6, align 1, !tbaa !27
  %8 = zext i8 %7 to i16
  %9 = tail call i32 asm "{cvt.rn.f16x2.e4m3x2 $0, $1;}\0A", "=r,h"(i16 %8) #2, !srcloc !29
  %10 = trunc i32 %9 to i16
  %11 = tail call contract noundef float asm "{cvt.f32.f16 $0, $1;}\0A", "=f,h"(i16 %10) #2, !srcloc !30
  %12 = getelementptr inbounds %struct.__nv_fp8_e4m3, ptr %2, i64 %5
  %13 = load i8, ptr %12, align 1, !tbaa !27
  %14 = zext i8 %13 to i16
  %15 = tail call i32 asm "{cvt.rn.f16x2.e4m3x2 $0, $1;}\0A", "=r,h"(i16 %14) #2, !srcloc !29
  %16 = trunc i32 %15 to i16
  %17 = tail call contract noundef float asm "{cvt.f32.f16 $0, $1;}\0A", "=f,h"(i16 %16) #2, !srcloc !30
  %18 = fadd contract float %11, %17
  %19 = tail call i16 asm "{cvt.rn.satfinite.e4m3x2.f32 $0, $2, $1;}\0A", "=h,f,f"(float %18, float 0.000000e+00) #2, !srcloc !21
  %20 = trunc i16 %19 to i8
  %21 = getelementptr inbounds %struct.__nv_fp8_e4m3, ptr %0, i64 %5
  store i8 %20, ptr %21, align 1, !tbaa !22
  ret void
}

; Function Attrs: convergent mustprogress norecurse nounwind memory(argmem: readwrite)
define dso_local void @sub_e5m2(ptr nocapture noundef writeonly %0, ptr nocapture noundef readonly %1, ptr nocapture noundef readonly %2) local_unnamed_addr #0 {
  %4 = tail call noundef i32 @llvm.nvvm.read.ptx.sreg.tid.x()
  %5 = sext i32 %4 to i64
  %6 = getelementptr inbounds %struct.__nv_fp8_e5m2, ptr %1, i64 %5
  %7 = load i8, ptr %6, align 1, !tbaa !31
  %8 = zext i8 %7 to i16
  %9 = tail call i32 asm "{cvt.rn.f16x2.e5m2x2 $0, $1;}\0A", "=r,h"(i16 %8) #2, !srcloc !33
  %10 = trunc i32 %9 to i16
  %11 = tail call contract noundef float asm "{cvt.f32.f16 $0, $1;}\0A", "=f,h"(i16 %10) #2, !srcloc !30
  %12 = getelementptr inbounds %struct.__nv_fp8_e5m2, ptr %2, i64 %5
  %13 = load i8, ptr %12, align 1, !tbaa !31
  %14 = zext i8 %13 to i16
  %15 = tail call i32 asm "{cvt.rn.f16x2.e5m2x2 $0, $1;}\0A", "=r,h"(i16 %14) #2, !srcloc !33
  %16 = trunc i32 %15 to i16
  %17 = tail call contract noundef float asm "{cvt.f32.f16 $0, $1;}\0A", "=f,h"(i16 %16) #2, !srcloc !30
  %18 = fsub contract float %11, %17
  %19 = tail call i16 asm "{cvt.rn.satfinite.e5m2x2.f32 $0, $2, $1;}\0A", "=h,f,f"(float %18, float 0.000000e+00) #2, !srcloc !23
  %20 = trunc i16 %19 to i8
  %21 = getelementptr inbounds %struct.__nv_fp8_e5m2, ptr %0, i64 %5
  store i8 %20, ptr %21, align 1, !tbaa !22
  ret void
}

; Function Attrs: convergent mustprogress norecurse nounwind memory(argmem: readwrite)
define dso_local void @mul_e4m3(ptr nocapture noundef writeonly %0, ptr nocapture noundef readonly %1, ptr nocapture noundef readonly %2) local_unnamed_addr #0 {
  %4 = tail call noundef i32 @llvm.nvvm.read.ptx.sreg.tid.x()
  %5 = sext i32 %4 to i64
  %6 = getelementptr inbounds %struct.__nv_fp8_e4m3, ptr %1, i64 %5
  %7 = load i8, ptr %6, align 1, !tbaa !27
  %8 = zext i8 %7 to i16
  %9 = tail call i32 asm "{cvt.rn.f16x2.e4m3x2 $0, $1;}\0A", "=r,h"(i16 %8) #2, !srcloc !29
  %10 = trunc i32 %9 to i16
  %11 = tail call contract noundef float asm "{cvt.f32.f16 $0, $1;}\0A", "=f,h"(i16 %10) #2, !srcloc !30
  %12 = getelementptr inbounds %struct.__nv_fp8_e4m3, ptr %2, i64 %5
  %13 = load i8, ptr %12, align 1, !tbaa !27
  %14 = zext i8 %13 to i16
  %15 = tail call i32 asm "{cvt.rn.f16x2.e4m3x2 $0, $1;}\0A", "=r,h"(i16 %14) #2, !srcloc !29
  %16 = trunc i32 %15 to i16
  %17 = tail call contract noundef float asm "{cvt.f32.f16 $0, $1;}\0A", "=f,h"(i16 %16) #2, !srcloc !30
  %18 = fmul contract float %11, %17
  %19 = tail call i16 asm "{cvt.rn.satfinite.e4m3x2.f32 $0, $2, $1;}\0A", "=h,f,f"(float %18, float 0.000000e+00) #2, !srcloc !21
  %20 = trunc i16 %19 to i8
  %21 = getelementptr inbounds %struct.__nv_fp8_e4m3, ptr %0, i64 %5
  store i8 %20, ptr %21, align 1, !tbaa !22
  ret void
}

; Function Attrs: convergent mustprogress norecurse nounwind memory(argmem: readwrite)
define dso_local void @add_mixed(ptr nocapture noundef writeonly %0, ptr nocapture noundef readonly %1, ptr nocapture noundef readonly %2) local_unnamed_addr #0 {
  %4 = tail call noundef i32 @llvm.nvvm.read.ptx.sreg.tid.x()
  %5 = sext i32 %4 to i64
  %6 = getelementptr inbounds %struct.__nv_fp8_e4m3, ptr %1, i64 %5
  %7 = load i8, ptr %6, align 1, !tbaa !27
  %8 = zext i8 %7 to i16
  %9 = tail call i32 asm "{cvt.rn.f16x2.e4m3x2 $0, $1;}\0A", "=r,h"(i16 %8) #2, !srcloc !29
  %10 = trunc i32 %9 to i16
  %11 = tail call contract noundef float asm "{cvt.f32.f16 $0, $1;}\0A", "=f,h"(i16 %10) #2, !srcloc !30
  %12 = getelementptr inbounds %struct.__nv_fp8_e5m2, ptr %2, i64 %5
  %13 = load i8, ptr %12, align 1, !tbaa !31
  %14 = zext i8 %13 to i16
  %15 = tail call i32 asm "{cvt.rn.f16x2.e5m2x2 $0, $1;}\0A", "=r,h"(i16 %14) #2, !srcloc !33
  %16 = trunc i32 %15 to i16
  %17 = tail call contract noundef float asm "{cvt.f32.f16 $0, $1;}\0A", "=f,h"(i16 %16) #2, !srcloc !30
  %18 = fadd contract float %11, %17
  %19 = tail call i16 asm "{cvt.rn.satfinite.e4m3x2.f32 $0, $2, $1;}\0A", "=h,f,f"(float %18, float 0.000000e+00) #2, !srcloc !21
  %20 = trunc i16 %19 to i8
  %21 = getelementptr inbounds %struct.__nv_fp8_e4m3, ptr %0, i64 %5
  store i8 %20, ptr %21, align 1, !tbaa !22
  ret void
}

; Function Attrs: mustprogress nocallback nofree nosync nounwind speculatable willreturn memory(none)
declare noundef i32 @llvm.nvvm.read.ptx.sreg.tid.x() #1

attributes #0 = { convergent mustprogress norecurse nounwind memory(argmem: readwrite) "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="sm_89" "target-features"="+ptx83,+sm_89" "uniform-work-group-size"="true" }
attributes #1 = { mustprogress nocallback nofree nosync nounwind speculatable willreturn memory(none) }
attributes #2 = { convergent nounwind memory(none) }

!nvvm.annotations = !{!0, !1, !2, !3, !4, !5, !6, !7, !8, !9, !10, !11, !12}
!llvm.module.flags = !{!13, !14, !15}
!llvm.ident = !{!16}

!0 = !{ptr @to_e4m3, !"kernel", i32 1}
!1 = !{ptr @to_e5m2, !"kernel", i32 1}
!2 = !{ptr @to_e4m3x2, !"kernel", i32 1}
!3 = !{ptr @from_e4m3, !"kernel", i32 1}
!4 = !{ptr @from_e5m2, !"kernel", i32 1}
!5 = !{ptr @from_e5m2x2, !"kernel", i32 1}
!6 = !{ptr @half_round_trip, !"kernel", i32 1}
!7 = !{ptr @dot_e4m3, !"kernel", i32 1}
!8 = !{ptr @dot_e5m2, !"kernel", i32 1}
!9 = !{ptr @add_e4m3, !"kernel", i32 1}
!10 = !{ptr @sub_e5m2, !"kernel", i32 1}
!11 = !{ptr @mul_e4m3, !"kernel", i32 1}
!12 = !{ptr @add_mixed, !"kernel", i32 1}
!13 = !{i32 1, !"wchar_size", i32 4}
!14 = !{i32 4, !"nvvm-reflect-ftz", i32 0}
!15 = !{i32 7, !"frame-pointer", i32 2}
!16 = !{!"Ubuntu clang version 18.1.3 (1ubuntu1)"}
!17 = !{!18, !18, i64 0}
!18 = !{!"float", !19, i64 0}
!19 = !{!"omnipotent char", !20, i64 0}
!20 = !{!"Simple C++ TBAA"}
!21 = !{i64 12168114}
!22 = !{!19, !19, i64 0}
!23 = !{i64 12167965}
!24 = !{i64 12169504}
!25 = !{!26, !26, i64 0}
!26 = !{!"short", !19, i64 0}
!27 = !{!28, !19, i64 0}
!28 = !{!"_ZTS13__nv_fp8_e4m3", !19, i64 0}
!29 = !{i64 12177649}
!30 = !{i64 12170233}
!31 = !{!32, !19, i64 0}
!32 = !{!"_ZTS13__nv_fp8_e5m2", !19, i64 0}
!33 = !{i64 12177557}
!34 = !{!35, !35, i64 0}
!35 = !{!"int", !19, i64 0}
!36 = !{i64 2154358410}
!37 = !{i64 2154423150}
!38 = !{!39, !35, i64 0}
!39 = !{!"_ZTS15__nv_fp8x4_e4m3", !35, i64 0}
!40 = !{!41, !35, i64 0}
!41 = !{!"_ZTS15__nv_fp8x4_e5m2", !35, i64 0}
