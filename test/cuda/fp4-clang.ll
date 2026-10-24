target datalayout = "e-i64:64-i128:128-v16:16-v32:32-n16:32:64"
target triple = "nvptx64-nvidia-cuda"

%struct.__nv_fp4_e2m1 = type { i8 }

; Function Attrs: mustprogress nofree norecurse nosync nounwind willreturn memory(argmem: readwrite)
define dso_local void @to_e2m1(ptr nocapture noundef writeonly %0, ptr nocapture noundef readonly %1) local_unnamed_addr #0 {
  %3 = tail call noundef i32 @llvm.nvvm.read.ptx.sreg.tid.x()
  %4 = sext i32 %3 to i64
  %5 = getelementptr inbounds float, ptr %1, i64 %4
  %6 = load float, ptr %5, align 4, !tbaa !8
  %7 = fpext float %6 to double
  %8 = bitcast double %7 to i64
  %9 = lshr i64 %8, 60
  %10 = trunc i64 %9 to i8
  %11 = and i8 %10, 8
  %12 = lshr i64 %8, 52
  %13 = trunc i64 %12 to i8
  %14 = lshr i64 %8, 51
  %15 = trunc i64 %14 to i8
  %16 = and i8 %15, 1
  %17 = tail call double @llvm.fabs.f64(double %7)
  %18 = bitcast double %17 to i64
  %19 = icmp ult i64 %18, 4598175219545276417
  br i1 %19, label %59, label %20

20:                                               ; preds = %2
  %21 = icmp ugt i64 %18, 4618441417868443648
  br i1 %21, label %22, label %25

22:                                               ; preds = %20
  %23 = icmp ugt i64 %18, 9218868437227405312
  %24 = select i1 %23, i8 0, i8 %11
  br label %59

25:                                               ; preds = %20
  %26 = icmp ugt i64 %18, 4607182418800017407
  br i1 %26, label %27, label %38

27:                                               ; preds = %25
  %28 = shl i8 %13, 1
  %29 = add i8 %28, 4
  %30 = or disjoint i8 %29, %16
  %31 = and i64 %8, 2251799813685247
  %32 = icmp ugt i64 %31, 1125899906842624
  %33 = and i64 %8, 4503599627370495
  %34 = icmp eq i64 %33, 3377699720527872
  %35 = or i1 %32, %34
  %36 = zext i1 %35 to i8
  %37 = add i8 %30, %36
  br label %59

38:                                               ; preds = %25
  %39 = xor i8 %13, -1
  %40 = or disjoint i8 %16, 2
  %41 = zext nneg i8 %40 to i32
  %42 = zext nneg i8 %39 to i32
  %43 = lshr i32 %41, %42
  %44 = trunc i32 %43 to i8
  %45 = or i64 %8, 4503599627370496
  %46 = zext nneg i8 %39 to i64
  %47 = shl i64 2251799813685248, %46
  %48 = add i64 %47, -1
  %49 = and i64 %48, %45
  %50 = shl i64 1125899906842624, %46
  %51 = icmp ugt i64 %49, %50
  br i1 %51, label %57, label %52

52:                                               ; preds = %38
  %53 = icmp ne i64 %49, %50
  %54 = and i32 %43, 1
  %55 = icmp eq i32 %54, 0
  %56 = select i1 %53, i1 true, i1 %55
  br i1 %56, label %59, label %57

57:                                               ; preds = %52, %38
  %58 = add nuw nsw i8 %44, 1
  br label %59

59:                                               ; preds = %2, %22, %27, %52, %57
  %60 = phi i8 [ %24, %22 ], [ %11, %2 ], [ %11, %52 ], [ %11, %57 ], [ %11, %27 ]
  %61 = phi i8 [ 7, %22 ], [ 0, %2 ], [ %44, %52 ], [ %58, %57 ], [ %37, %27 ]
  %62 = or i8 %61, %60
  %63 = getelementptr inbounds i8, ptr %0, i64 %4
  store i8 %62, ptr %63, align 1, !tbaa !12
  ret void
}

; Function Attrs: convergent mustprogress norecurse nounwind memory(argmem: readwrite)
define dso_local void @from_e2m1(ptr nocapture noundef writeonly %0, ptr nocapture noundef readonly %1) local_unnamed_addr #1 {
  %3 = tail call noundef i32 @llvm.nvvm.read.ptx.sreg.tid.x()
  %4 = sext i32 %3 to i64
  %5 = getelementptr inbounds %struct.__nv_fp4_e2m1, ptr %1, i64 %4
  %6 = load i8, ptr %5, align 1, !tbaa !13
  %7 = shl i8 %6, 2
  %8 = and i8 %7, 60
  %9 = zext nneg i8 %8 to i16
  %10 = shl nuw nsw i16 %9, 7
  %11 = and i16 %10, 3072
  %12 = add nuw nsw i16 %11, 14336
  %13 = and i16 %10, 512
  %14 = icmp eq i16 %11, 0
  br i1 %14, label %15, label %26

15:                                               ; preds = %2
  %16 = icmp eq i16 %13, 0
  %17 = tail call i16 @llvm.ctlz.i16(i16 %13, i1 true), !range !15
  %18 = xor i16 %17, 15
  %19 = sub nsw i16 10, %18
  %20 = shl i16 %10, %19
  %21 = shl nuw nsw i16 %17, 10
  %22 = sub nuw nsw i16 20480, %21
  %23 = and i16 %20, 512
  %24 = select i1 %16, i16 0, i16 %22
  %25 = select i1 %16, i16 0, i16 %23
  br label %26

26:                                               ; preds = %2, %15
  %27 = phi i16 [ %12, %2 ], [ %24, %15 ]
  %28 = phi i16 [ %13, %2 ], [ %25, %15 ]
  %29 = shl nuw i16 %9, 10
  %30 = and i16 %29, -32768
  %31 = or i16 %27, %30
  %32 = or i16 %31, %28
  %33 = tail call contract noundef float asm "{cvt.f32.f16 $0, $1;}\0A", "=f,h"(i16 %32) #4, !srcloc !16
  %34 = getelementptr inbounds float, ptr %0, i64 %4
  store float %33, ptr %34, align 4, !tbaa !8
  ret void
}

; Function Attrs: mustprogress nofree norecurse nosync nounwind willreturn memory(argmem: readwrite)
define dso_local void @to_e4m3_nosat(ptr nocapture noundef writeonly %0, ptr nocapture noundef readonly %1) local_unnamed_addr #0 {
  %3 = tail call noundef i32 @llvm.nvvm.read.ptx.sreg.tid.x()
  %4 = sext i32 %3 to i64
  %5 = getelementptr inbounds float, ptr %1, i64 %4
  %6 = load float, ptr %5, align 4, !tbaa !8
  %7 = tail call float @llvm.fabs.f32(float %6)
  %8 = bitcast float %7 to i32
  %9 = icmp ugt i32 %8, 2139095040
  %10 = fpext float %6 to double
  %11 = select i1 %9, double 0x7FFFFFFFE0000000, double %10
  %12 = bitcast double %11 to i64
  %13 = lshr i64 %12, 52
  %14 = trunc i64 %13 to i8
  %15 = lshr i64 %12, 49
  %16 = trunc i64 %15 to i8
  %17 = and i8 %16, 7
  %18 = tail call double @llvm.fabs.f64(double %11)
  %19 = bitcast double %18 to i64
  %20 = icmp ugt i64 %19, 4562146422526312448
  br i1 %20, label %21, label %57

21:                                               ; preds = %2
  %22 = icmp ugt i64 %19, 4646870390516219904
  br i1 %22, label %57, label %23

23:                                               ; preds = %21
  %24 = icmp ult i64 %19, 4580160821035794432
  br i1 %24, label %36, label %25

25:                                               ; preds = %23
  %26 = shl i8 %14, 3
  %27 = add i8 %26, 64
  %28 = or disjoint i8 %27, %17
  %29 = and i64 %12, 562949953421311
  %30 = icmp ugt i64 %29, 281474976710656
  %31 = and i64 %12, 1125899906842623
  %32 = icmp eq i64 %31, 844424930131968
  %33 = or i1 %30, %32
  %34 = zext i1 %33 to i8
  %35 = add i8 %28, %34
  br label %57

36:                                               ; preds = %23
  %37 = sub i8 -7, %14
  %38 = or disjoint i8 %17, 8
  %39 = zext nneg i8 %38 to i32
  %40 = zext nneg i8 %37 to i32
  %41 = lshr i32 %39, %40
  %42 = trunc i32 %41 to i8
  %43 = or i64 %12, 4503599627370496
  %44 = zext i8 %37 to i64
  %45 = shl i64 562949953421312, %44
  %46 = add i64 %45, -1
  %47 = and i64 %46, %43
  %48 = shl i64 281474976710656, %44
  %49 = icmp ugt i64 %47, %48
  br i1 %49, label %55, label %50

50:                                               ; preds = %36
  %51 = icmp ne i64 %47, %48
  %52 = and i32 %41, 1
  %53 = icmp eq i32 %52, 0
  %54 = select i1 %51, i1 true, i1 %53
  br i1 %54, label %57, label %55

55:                                               ; preds = %50, %36
  %56 = add nuw nsw i8 %42, 1
  br label %57

57:                                               ; preds = %25, %21, %2, %50, %55
  %58 = phi i8 [ 0, %2 ], [ %56, %55 ], [ %42, %50 ], [ 127, %21 ], [ %35, %25 ]
  %59 = lshr i64 %12, 56
  %60 = trunc i64 %59 to i8
  %61 = and i8 %60, -128
  %62 = or i8 %58, %61
  %63 = getelementptr inbounds i8, ptr %0, i64 %4
  store i8 %62, ptr %63, align 1, !tbaa !12
  ret void
}

; Function Attrs: mustprogress nofree norecurse nosync nounwind willreturn memory(argmem: readwrite)
define dso_local void @to_e5m2_nosat(ptr nocapture noundef writeonly %0, ptr nocapture noundef readonly %1) local_unnamed_addr #0 {
  %3 = tail call noundef i32 @llvm.nvvm.read.ptx.sreg.tid.x()
  %4 = sext i32 %3 to i64
  %5 = getelementptr inbounds float, ptr %1, i64 %4
  %6 = load float, ptr %5, align 4, !tbaa !8
  %7 = tail call float @llvm.fabs.f32(float %6)
  %8 = bitcast float %7 to i32
  %9 = icmp ugt i32 %8, 2139095040
  %10 = fpext float %6 to double
  %11 = select i1 %9, double 0x7FFFFFFFE0000000, double %10
  %12 = bitcast double %11 to i64
  %13 = lshr i64 %12, 52
  %14 = trunc i64 %13 to i8
  %15 = lshr i64 %12, 50
  %16 = trunc i64 %15 to i8
  %17 = and i8 %16, 3
  %18 = tail call double @llvm.fabs.f64(double %11)
  %19 = bitcast double %18 to i64
  %20 = icmp ugt i64 %19, 4530621225134718976
  br i1 %20, label %21, label %61

21:                                               ; preds = %2
  %22 = icmp ugt i64 %19, 9218868437227405312
  br i1 %22, label %23, label %25

23:                                               ; preds = %21
  %24 = or i8 %17, 126
  br label %61

25:                                               ; preds = %21
  %26 = icmp ugt i64 %19, 4678677062884524031
  br i1 %26, label %61, label %27

27:                                               ; preds = %25
  %28 = icmp ult i64 %19, 4544132024016830464
  br i1 %28, label %40, label %29

29:                                               ; preds = %27
  %30 = shl i8 %14, 2
  %31 = add i8 %30, 64
  %32 = or disjoint i8 %31, %17
  %33 = and i64 %12, 1125899906842623
  %34 = icmp ugt i64 %33, 562949953421312
  %35 = and i64 %12, 2251799813685247
  %36 = icmp eq i64 %35, 1688849860263936
  %37 = or i1 %34, %36
  %38 = zext i1 %37 to i8
  %39 = add i8 %32, %38
  br label %61

40:                                               ; preds = %27
  %41 = sub i8 -15, %14
  %42 = or disjoint i8 %17, 4
  %43 = zext nneg i8 %42 to i32
  %44 = zext nneg i8 %41 to i32
  %45 = lshr i32 %43, %44
  %46 = trunc i32 %45 to i8
  %47 = or i64 %12, 4503599627370496
  %48 = zext i8 %41 to i64
  %49 = shl i64 1125899906842624, %48
  %50 = add i64 %49, -1
  %51 = and i64 %50, %47
  %52 = shl i64 562949953421312, %48
  %53 = icmp ugt i64 %51, %52
  br i1 %53, label %59, label %54

54:                                               ; preds = %40
  %55 = icmp ne i64 %51, %52
  %56 = and i32 %45, 1
  %57 = icmp eq i32 %56, 0
  %58 = select i1 %55, i1 true, i1 %57
  br i1 %58, label %61, label %59

59:                                               ; preds = %54, %40
  %60 = add nuw nsw i8 %46, 1
  br label %61

61:                                               ; preds = %29, %25, %2, %23, %54, %59
  %62 = phi i8 [ 0, %2 ], [ %60, %59 ], [ %46, %54 ], [ %24, %23 ], [ 124, %25 ], [ %39, %29 ]
  %63 = lshr i64 %12, 56
  %64 = trunc i64 %63 to i8
  %65 = and i8 %64, -128
  %66 = or i8 %62, %65
  %67 = getelementptr inbounds i8, ptr %0, i64 %4
  store i8 %66, ptr %67, align 1, !tbaa !12
  ret void
}

; Function Attrs: mustprogress nocallback nofree nosync nounwind speculatable willreturn memory(none)
declare noundef i32 @llvm.nvvm.read.ptx.sreg.tid.x() #2

; Function Attrs: nocallback nofree nosync nounwind speculatable willreturn memory(none)
declare double @llvm.fabs.f64(double) #3

; Function Attrs: nocallback nofree nosync nounwind speculatable willreturn memory(none)
declare i16 @llvm.ctlz.i16(i16, i1 immarg) #3

; Function Attrs: nocallback nofree nosync nounwind speculatable willreturn memory(none)
declare float @llvm.fabs.f32(float) #3

attributes #0 = { mustprogress nofree norecurse nosync nounwind willreturn memory(argmem: readwrite) "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="sm_89" "target-features"="+ptx83,+sm_89" "uniform-work-group-size"="true" }
attributes #1 = { convergent mustprogress norecurse nounwind memory(argmem: readwrite) "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="sm_89" "target-features"="+ptx83,+sm_89" "uniform-work-group-size"="true" }
attributes #2 = { mustprogress nocallback nofree nosync nounwind speculatable willreturn memory(none) }
attributes #3 = { nocallback nofree nosync nounwind speculatable willreturn memory(none) }
attributes #4 = { convergent nounwind memory(none) }

!nvvm.annotations = !{!0, !1, !2, !3}
!llvm.module.flags = !{!4, !5, !6}
!llvm.ident = !{!7}

!0 = !{ptr @to_e2m1, !"kernel", i32 1}
!1 = !{ptr @from_e2m1, !"kernel", i32 1}
!2 = !{ptr @to_e4m3_nosat, !"kernel", i32 1}
!3 = !{ptr @to_e5m2_nosat, !"kernel", i32 1}
!4 = !{i32 1, !"wchar_size", i32 4}
!5 = !{i32 4, !"nvvm-reflect-ftz", i32 0}
!6 = !{i32 7, !"frame-pointer", i32 2}
!7 = !{!"Ubuntu clang version 18.1.3 (1ubuntu1)"}
!8 = !{!9, !9, i64 0}
!9 = !{!"float", !10, i64 0}
!10 = !{!"omnipotent char", !11, i64 0}
!11 = !{!"Simple C++ TBAA"}
!12 = !{!10, !10, i64 0}
!13 = !{!14, !10, i64 0}
!14 = !{!"_ZTS13__nv_fp4_e2m1", !10, i64 0}
!15 = !{i16 6, i16 17}
!16 = !{i64 12168718}
