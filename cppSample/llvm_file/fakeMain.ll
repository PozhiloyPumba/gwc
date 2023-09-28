; ModuleID = 'fakeMain.cpp'
source_filename = "fakeMain.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@arr = dso_local global [100 x [3 x i32]] [[3 x i32] [i32 425, i32 536, i32 13974511], [3 x i32] [i32 151, i32 368, i32 3572079], [3 x i32] [i32 440, i32 249, i32 1591737], [3 x i32] [i32 3, i32 363, i32 4020334], [3 x i32] [i32 715, i32 400, i32 6731484], [3 x i32] [i32 58, i32 444, i32 15049432], [3 x i32] [i32 512, i32 555, i32 13193426], [3 x i32] [i32 311, i32 331, i32 2822364], [3 x i32] [i32 37, i32 103, i32 2708939], [3 x i32] [i32 656, i32 347, i32 505435], [3 x i32] [i32 133, i32 358, i32 7584055], [3 x i32] [i32 470, i32 494, i32 2201812], [3 x i32] [i32 147, i32 36, i32 12949952], [3 x i32] [i32 211, i32 396, i32 11288287], [3 x i32] [i32 451, i32 494, i32 3202092], [3 x i32] [i32 789, i32 392, i32 10526177], [3 x i32] [i32 171, i32 367, i32 6475432], [3 x i32] [i32 797, i32 484, i32 11629877], [3 x i32] [i32 186, i32 228, i32 5563096], [3 x i32] [i32 167, i32 351, i32 13589823], [3 x i32] [i32 505, i32 250, i32 3208161], [3 x i32] [i32 353, i32 284, i32 10462034], [3 x i32] [i32 196, i32 117, i32 13461283], [3 x i32] [i32 194, i32 257, i32 15139700], [3 x i32] [i32 103, i32 276, i32 12291396], [3 x i32] [i32 646, i32 144, i32 1097829], [3 x i32] [i32 188, i32 217, i32 13558239], [3 x i32] [i32 673, i32 10, i32 11114889], [3 x i32] [i32 660, i32 520, i32 1556342], [3 x i32] [i32 624, i32 169, i32 2951914], [3 x i32] [i32 394, i32 43, i32 2414789], [3 x i32] [i32 51, i32 14, i32 16103385], [3 x i32] [i32 569, i32 373, i32 15724377], [3 x i32] [i32 425, i32 523, i32 16143020], [3 x i32] [i32 211, i32 568, i32 14574142], [3 x i32] [i32 787, i32 224, i32 755813], [3 x i32] [i32 712, i32 54, i32 1316433], [3 x i32] [i32 651, i32 459, i32 1672796], [3 x i32] [i32 525, i32 230, i32 15763870], [3 x i32] [i32 129, i32 527, i32 10295048], [3 x i32] [i32 631, i32 220, i32 9377424], [3 x i32] [i32 4, i32 416, i32 12654176], [3 x i32] [i32 601, i32 32, i32 6459850], [3 x i32] [i32 252, i32 593, i32 5256075], [3 x i32] [i32 54, i32 385, i32 14883775], [3 x i32] [i32 115, i32 78, i32 8514895], [3 x i32] [i32 604, i32 434, i32 3404590], [3 x i32] [i32 20, i32 183, i32 1018311], [3 x i32] [i32 7, i32 326, i32 12269577], [3 x i32] [i32 73, i32 18, i32 6594307], [3 x i32] [i32 0, i32 456, i32 10733656], [3 x i32] [i32 479, i32 244, i32 2849870], [3 x i32] [i32 16, i32 40, i32 7429552], [3 x i32] [i32 322, i32 445, i32 7354436], [3 x i32] [i32 429, i32 465, i32 12181642], [3 x i32] [i32 633, i32 257, i32 5046100], [3 x i32] [i32 39, i32 327, i32 8084592], [3 x i32] [i32 256, i32 530, i32 16435783], [3 x i32] [i32 367, i32 29, i32 9214164], [3 x i32] [i32 245, i32 552, i32 1027154], [3 x i32] [i32 232, i32 288, i32 14172151], [3 x i32] [i32 93, i32 425, i32 10404819], [3 x i32] [i32 530, i32 496, i32 2685554], [3 x i32] [i32 205, i32 545, i32 9891471], [3 x i32] [i32 110, i32 427, i32 7628983], [3 x i32] [i32 298, i32 346, i32 11452609], [3 x i32] [i32 633, i32 359, i32 3394207], [3 x i32] [i32 609, i32 407, i32 3486714], [3 x i32] [i32 398, i32 49, i32 15366155], [3 x i32] [i32 63, i32 527, i32 6160162], [3 x i32] [i32 311, i32 96, i32 105981], [3 x i32] [i32 727, i32 201, i32 9827702], [3 x i32] [i32 630, i32 316, i32 13555200], [3 x i32] [i32 699, i32 169, i32 4481560], [3 x i32] [i32 731, i32 347, i32 12098681], [3 x i32] [i32 100, i32 381, i32 12245631], [3 x i32] [i32 770, i32 247, i32 13267674], [3 x i32] [i32 529, i32 123, i32 11677846], [3 x i32] [i32 411, i32 211, i32 13468432], [3 x i32] [i32 459, i32 342, i32 14129095], [3 x i32] [i32 433, i32 181, i32 10508253], [3 x i32] [i32 704, i32 268, i32 7340572], [3 x i32] [i32 683, i32 273, i32 6896895], [3 x i32] [i32 705, i32 3, i32 11830786], [3 x i32] [i32 66, i32 490, i32 1521645], [3 x i32] [i32 694, i32 326, i32 7597392], [3 x i32] [i32 169, i32 359, i32 13177975], [3 x i32] [i32 135, i32 265, i32 4607890], [3 x i32] [i32 92, i32 451, i32 5972511], [3 x i32] [i32 720, i32 29, i32 5711389], [3 x i32] [i32 711, i32 582, i32 11496075], [3 x i32] [i32 167, i32 469, i32 791786], [3 x i32] [i32 44, i32 583, i32 2635077], [3 x i32] [i32 630, i32 46, i32 9946804], [3 x i32] [i32 262, i32 160, i32 6162150], [3 x i32] [i32 457, i32 574, i32 14793056], [3 x i32] [i32 415, i32 266, i32 13430405], [3 x i32] [i32 16, i32 283, i32 7321896], [3 x i32] [i32 5, i32 245, i32 3194004], [3 x i32] [i32 331, i32 137, i32 3298150]], align 16

; Function Attrs: mustprogress noinline optnone sspstrong uwtable
define dso_local noundef signext i8 @_Z10fillCircleiiiiPi(i32 noundef %0, i32 noundef %1, i32 noundef %2, i32 noundef %3, ptr noundef %4) #0 {
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca i32, align 4
  %10 = alloca ptr, align 8
  %11 = alloca i8, align 1
  %12 = alloca i32, align 4
  %13 = alloca i32, align 4
  %14 = alloca i32, align 4
  store i32 %0, ptr %6, align 4
  store i32 %1, ptr %7, align 4
  store i32 %2, ptr %8, align 4
  store i32 %3, ptr %9, align 4
  store ptr %4, ptr %10, align 8
  store i8 0, ptr %11, align 1
  %15 = load i32, ptr %8, align 4
  %16 = sub nsw i32 0, %15
  store i32 %16, ptr %12, align 4
  br label %17

17:                                               ; preds = %82, %5
  %18 = load i32, ptr %12, align 4
  %19 = load i32, ptr %8, align 4
  %20 = icmp sle i32 %18, %19
  br i1 %20, label %21, label %85

21:                                               ; preds = %17
  %22 = load i32, ptr %8, align 4
  %23 = sub nsw i32 0, %22
  store i32 %23, ptr %13, align 4
  br label %24

24:                                               ; preds = %78, %21
  %25 = load i32, ptr %13, align 4
  %26 = load i32, ptr %8, align 4
  %27 = icmp sle i32 %25, %26
  br i1 %27, label %28, label %81

28:                                               ; preds = %24
  %29 = load i32, ptr %13, align 4
  %30 = load i32, ptr %13, align 4
  %31 = mul nsw i32 %29, %30
  %32 = load i32, ptr %12, align 4
  %33 = load i32, ptr %12, align 4
  %34 = mul nsw i32 %32, %33
  %35 = add nsw i32 %31, %34
  %36 = load i32, ptr %8, align 4
  %37 = load i32, ptr %8, align 4
  %38 = mul nsw i32 %36, %37
  %39 = icmp sle i32 %35, %38
  br i1 %39, label %40, label %77

40:                                               ; preds = %28
  %41 = load i32, ptr %6, align 4
  %42 = load i32, ptr %13, align 4
  %43 = add nsw i32 %41, %42
  %44 = load i32, ptr %7, align 4
  %45 = load i32, ptr %12, align 4
  %46 = add nsw i32 %44, %45
  %47 = load i32, ptr %9, align 4
  %48 = call signext i8 @setPixel(i32 noundef %43, i32 noundef %46, i32 noundef %47)
  %49 = sext i8 %48 to i32
  store i32 %49, ptr %14, align 4
  %50 = load i32, ptr %14, align 4
  %51 = load i8, ptr %11, align 1
  %52 = sext i8 %51 to i32
  %53 = or i32 %52, %50
  %54 = trunc i32 %53 to i8
  store i8 %54, ptr %11, align 1
  %55 = load i32, ptr %14, align 4
  %56 = icmp ne i32 %55, 0
  br i1 %56, label %57, label %76

57:                                               ; preds = %40
  %58 = load i32, ptr %6, align 4
  %59 = load i32, ptr %13, align 4
  %60 = add nsw i32 %58, %59
  %61 = load ptr, ptr %10, align 8
  %62 = getelementptr inbounds i32, ptr %61, i64 0
  %63 = load i32, ptr %62, align 4
  %64 = add nsw i32 %63, %60
  store i32 %64, ptr %62, align 4
  %65 = load i32, ptr %7, align 4
  %66 = load i32, ptr %12, align 4
  %67 = add nsw i32 %65, %66
  %68 = load ptr, ptr %10, align 8
  %69 = getelementptr inbounds i32, ptr %68, i64 1
  %70 = load i32, ptr %69, align 4
  %71 = add nsw i32 %70, %67
  store i32 %71, ptr %69, align 4
  %72 = load ptr, ptr %10, align 8
  %73 = getelementptr inbounds i32, ptr %72, i64 2
  %74 = load i32, ptr %73, align 4
  %75 = add nsw i32 %74, 1
  store i32 %75, ptr %73, align 4
  br label %76

76:                                               ; preds = %57, %40
  br label %77

77:                                               ; preds = %76, %28
  br label %78

78:                                               ; preds = %77
  %79 = load i32, ptr %13, align 4
  %80 = add nsw i32 %79, 1
  store i32 %80, ptr %13, align 4
  br label %24, !llvm.loop !6

81:                                               ; preds = %24
  br label %82

82:                                               ; preds = %81
  %83 = load i32, ptr %12, align 4
  %84 = add nsw i32 %83, 1
  store i32 %84, ptr %12, align 4
  br label %17, !llvm.loop !8

85:                                               ; preds = %17
  %86 = load i8, ptr %11, align 1
  ret i8 %86
}

declare signext i8 @setPixel(i32 noundef, i32 noundef, i32 noundef) #1

; Function Attrs: mustprogress noinline optnone sspstrong uwtable
define dso_local void @_Z8fakeMainv() #0 {
  %1 = alloca i32, align 4
  %2 = alloca [100 x i8], align 16
  %3 = alloca [100 x [3 x i32]], align 16
  %4 = alloca i32, align 4
  %5 = alloca i8, align 1
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  store i32 100, ptr %1, align 4
  call void @llvm.memset.p0.i64(ptr align 16 %2, i8 0, i64 100, i1 false)
  call void @llvm.memset.p0.i64(ptr align 16 %3, i8 0, i64 1200, i1 false)
  store i32 2, ptr %4, align 4
  store i8 1, ptr %5, align 1
  store i32 0, ptr %6, align 4
  br label %9

9:                                                ; preds = %29, %0
  %10 = load i32, ptr %6, align 4
  %11 = icmp slt i32 %10, 100
  br i1 %11, label %12, label %32

12:                                               ; preds = %9
  %13 = load i32, ptr %6, align 4
  %14 = sext i32 %13 to i64
  %15 = getelementptr inbounds [100 x [3 x i32]], ptr @arr, i64 0, i64 %14
  %16 = getelementptr inbounds [3 x i32], ptr %15, i64 0, i64 0
  %17 = load i32, ptr %16, align 4
  %18 = load i32, ptr %6, align 4
  %19 = sext i32 %18 to i64
  %20 = getelementptr inbounds [100 x [3 x i32]], ptr @arr, i64 0, i64 %19
  %21 = getelementptr inbounds [3 x i32], ptr %20, i64 0, i64 1
  %22 = load i32, ptr %21, align 4
  %23 = load i32, ptr %4, align 4
  %24 = load i32, ptr %6, align 4
  %25 = sext i32 %24 to i64
  %26 = getelementptr inbounds [100 x [3 x i32]], ptr %3, i64 0, i64 %25
  %27 = getelementptr inbounds [3 x i32], ptr %26, i64 0, i64 0
  %28 = call noundef signext i8 @_Z10fillCircleiiiiPi(i32 noundef %17, i32 noundef %22, i32 noundef %23, i32 noundef 0, ptr noundef %27)
  br label %29

29:                                               ; preds = %12
  %30 = load i32, ptr %6, align 4
  %31 = add nsw i32 %30, 1
  store i32 %31, ptr %6, align 4
  br label %9, !llvm.loop !9

32:                                               ; preds = %9
  br label %33

33:                                               ; preds = %91, %32
  %34 = load i8, ptr %5, align 1
  %35 = icmp ne i8 %34, 0
  br i1 %35, label %36, label %92

36:                                               ; preds = %33
  store i8 0, ptr %5, align 1
  %37 = load i32, ptr %4, align 4
  %38 = add nsw i32 %37, 1
  store i32 %38, ptr %4, align 4
  store i32 0, ptr %7, align 4
  br label %39

39:                                               ; preds = %88, %36
  %40 = load i32, ptr %7, align 4
  %41 = icmp slt i32 %40, 100
  br i1 %41, label %42, label %91

42:                                               ; preds = %39
  %43 = load i32, ptr %7, align 4
  %44 = sext i32 %43 to i64
  %45 = getelementptr inbounds [100 x i8], ptr %2, i64 0, i64 %44
  %46 = load i8, ptr %45, align 1
  %47 = icmp ne i8 %46, 0
  br i1 %47, label %48, label %49

48:                                               ; preds = %42
  br label %88

49:                                               ; preds = %42
  %50 = load i32, ptr %7, align 4
  %51 = sext i32 %50 to i64
  %52 = getelementptr inbounds [100 x [3 x i32]], ptr @arr, i64 0, i64 %51
  %53 = getelementptr inbounds [3 x i32], ptr %52, i64 0, i64 0
  %54 = load i32, ptr %53, align 4
  %55 = load i32, ptr %7, align 4
  %56 = sext i32 %55 to i64
  %57 = getelementptr inbounds [100 x [3 x i32]], ptr @arr, i64 0, i64 %56
  %58 = getelementptr inbounds [3 x i32], ptr %57, i64 0, i64 1
  %59 = load i32, ptr %58, align 4
  %60 = load i32, ptr %4, align 4
  %61 = load i32, ptr %7, align 4
  %62 = sext i32 %61 to i64
  %63 = getelementptr inbounds [100 x [3 x i32]], ptr @arr, i64 0, i64 %62
  %64 = getelementptr inbounds [3 x i32], ptr %63, i64 0, i64 2
  %65 = load i32, ptr %64, align 4
  %66 = load i32, ptr %7, align 4
  %67 = sext i32 %66 to i64
  %68 = getelementptr inbounds [100 x [3 x i32]], ptr %3, i64 0, i64 %67
  %69 = getelementptr inbounds [3 x i32], ptr %68, i64 0, i64 0
  %70 = call noundef signext i8 @_Z10fillCircleiiiiPi(i32 noundef %54, i32 noundef %59, i32 noundef %60, i32 noundef %65, ptr noundef %69)
  %71 = icmp ne i8 %70, 0
  %72 = xor i1 %71, true
  %73 = zext i1 %72 to i8
  %74 = load i32, ptr %7, align 4
  %75 = sext i32 %74 to i64
  %76 = getelementptr inbounds [100 x i8], ptr %2, i64 0, i64 %75
  store i8 %73, ptr %76, align 1
  %77 = load i32, ptr %7, align 4
  %78 = sext i32 %77 to i64
  %79 = getelementptr inbounds [100 x i8], ptr %2, i64 0, i64 %78
  %80 = load i8, ptr %79, align 1
  %81 = icmp ne i8 %80, 0
  %82 = xor i1 %81, true
  %83 = zext i1 %82 to i32
  %84 = load i8, ptr %5, align 1
  %85 = sext i8 %84 to i32
  %86 = or i32 %85, %83
  %87 = trunc i32 %86 to i8
  store i8 %87, ptr %5, align 1
  br label %88

88:                                               ; preds = %49, %48
  %89 = load i32, ptr %7, align 4
  %90 = add nsw i32 %89, 1
  store i32 %90, ptr %7, align 4
  br label %39, !llvm.loop !10

91:                                               ; preds = %39
  br label %33, !llvm.loop !11

92:                                               ; preds = %33
  call void @updateGPUBuffer()
  store i32 0, ptr %8, align 4
  br label %93

93:                                               ; preds = %127, %92
  %94 = load i32, ptr %8, align 4
  %95 = icmp slt i32 %94, 100
  br i1 %95, label %96, label %130

96:                                               ; preds = %93
  %97 = load i32, ptr %8, align 4
  %98 = sext i32 %97 to i64
  %99 = getelementptr inbounds [100 x [3 x i32]], ptr %3, i64 0, i64 %98
  %100 = getelementptr inbounds [3 x i32], ptr %99, i64 0, i64 0
  %101 = load i32, ptr %100, align 4
  %102 = load i32, ptr %8, align 4
  %103 = sext i32 %102 to i64
  %104 = getelementptr inbounds [100 x [3 x i32]], ptr %3, i64 0, i64 %103
  %105 = getelementptr inbounds [3 x i32], ptr %104, i64 0, i64 2
  %106 = load i32, ptr %105, align 4
  %107 = sdiv i32 %101, %106
  %108 = load i32, ptr %8, align 4
  %109 = sext i32 %108 to i64
  %110 = getelementptr inbounds [100 x [3 x i32]], ptr @arr, i64 0, i64 %109
  %111 = getelementptr inbounds [3 x i32], ptr %110, i64 0, i64 0
  store i32 %107, ptr %111, align 4
  %112 = load i32, ptr %8, align 4
  %113 = sext i32 %112 to i64
  %114 = getelementptr inbounds [100 x [3 x i32]], ptr %3, i64 0, i64 %113
  %115 = getelementptr inbounds [3 x i32], ptr %114, i64 0, i64 1
  %116 = load i32, ptr %115, align 4
  %117 = load i32, ptr %8, align 4
  %118 = sext i32 %117 to i64
  %119 = getelementptr inbounds [100 x [3 x i32]], ptr %3, i64 0, i64 %118
  %120 = getelementptr inbounds [3 x i32], ptr %119, i64 0, i64 2
  %121 = load i32, ptr %120, align 4
  %122 = sdiv i32 %116, %121
  %123 = load i32, ptr %8, align 4
  %124 = sext i32 %123 to i64
  %125 = getelementptr inbounds [100 x [3 x i32]], ptr @arr, i64 0, i64 %124
  %126 = getelementptr inbounds [3 x i32], ptr %125, i64 0, i64 1
  store i32 %122, ptr %126, align 4
  br label %127

127:                                              ; preds = %96
  %128 = load i32, ptr %8, align 4
  %129 = add nsw i32 %128, 1
  store i32 %129, ptr %8, align 4
  br label %93, !llvm.loop !12

130:                                              ; preds = %93
  call void @draw()
  ret void
}

; Function Attrs: nocallback nofree nounwind willreturn memory(argmem: write)
declare void @llvm.memset.p0.i64(ptr nocapture writeonly, i8, i64, i1 immarg) #2

declare void @updateGPUBuffer() #1

declare void @draw() #1

attributes #0 = { mustprogress noinline optnone sspstrong uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { nocallback nofree nounwind willreturn memory(argmem: write) }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"clang version 16.0.6"}
!6 = distinct !{!6, !7}
!7 = !{!"llvm.loop.mustprogress"}
!8 = distinct !{!8, !7}
!9 = distinct !{!9, !7}
!10 = distinct !{!10, !7}
!11 = distinct !{!11, !7}
!12 = distinct !{!12, !7}
