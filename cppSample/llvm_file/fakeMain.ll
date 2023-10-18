; ModuleID = 'fakeMain.cpp'
source_filename = "fakeMain.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@arr = dso_local local_unnamed_addr global [100 x [3 x i32]] [[3 x i32] [i32 425, i32 536, i32 13974511], [3 x i32] [i32 151, i32 368, i32 3572079], [3 x i32] [i32 440, i32 249, i32 1591737], [3 x i32] [i32 3, i32 363, i32 4020334], [3 x i32] [i32 715, i32 400, i32 6731484], [3 x i32] [i32 58, i32 444, i32 15049432], [3 x i32] [i32 512, i32 555, i32 13193426], [3 x i32] [i32 311, i32 331, i32 2822364], [3 x i32] [i32 37, i32 103, i32 2708939], [3 x i32] [i32 656, i32 347, i32 505435], [3 x i32] [i32 133, i32 358, i32 7584055], [3 x i32] [i32 470, i32 494, i32 2201812], [3 x i32] [i32 147, i32 36, i32 12949952], [3 x i32] [i32 211, i32 396, i32 11288287], [3 x i32] [i32 451, i32 494, i32 3202092], [3 x i32] [i32 789, i32 392, i32 10526177], [3 x i32] [i32 171, i32 367, i32 6475432], [3 x i32] [i32 797, i32 484, i32 11629877], [3 x i32] [i32 186, i32 228, i32 5563096], [3 x i32] [i32 167, i32 351, i32 13589823], [3 x i32] [i32 505, i32 250, i32 3208161], [3 x i32] [i32 353, i32 284, i32 10462034], [3 x i32] [i32 196, i32 117, i32 13461283], [3 x i32] [i32 194, i32 257, i32 15139700], [3 x i32] [i32 103, i32 276, i32 12291396], [3 x i32] [i32 646, i32 144, i32 1097829], [3 x i32] [i32 188, i32 217, i32 13558239], [3 x i32] [i32 673, i32 10, i32 11114889], [3 x i32] [i32 660, i32 520, i32 1556342], [3 x i32] [i32 624, i32 169, i32 2951914], [3 x i32] [i32 394, i32 43, i32 2414789], [3 x i32] [i32 51, i32 14, i32 16103385], [3 x i32] [i32 569, i32 373, i32 15724377], [3 x i32] [i32 425, i32 523, i32 16143020], [3 x i32] [i32 211, i32 568, i32 14574142], [3 x i32] [i32 787, i32 224, i32 755813], [3 x i32] [i32 712, i32 54, i32 1316433], [3 x i32] [i32 651, i32 459, i32 1672796], [3 x i32] [i32 525, i32 230, i32 15763870], [3 x i32] [i32 129, i32 527, i32 10295048], [3 x i32] [i32 631, i32 220, i32 9377424], [3 x i32] [i32 4, i32 416, i32 12654176], [3 x i32] [i32 601, i32 32, i32 6459850], [3 x i32] [i32 252, i32 593, i32 5256075], [3 x i32] [i32 54, i32 385, i32 14883775], [3 x i32] [i32 115, i32 78, i32 8514895], [3 x i32] [i32 604, i32 434, i32 3404590], [3 x i32] [i32 20, i32 183, i32 1018311], [3 x i32] [i32 7, i32 326, i32 12269577], [3 x i32] [i32 73, i32 18, i32 6594307], [3 x i32] [i32 0, i32 456, i32 10733656], [3 x i32] [i32 479, i32 244, i32 2849870], [3 x i32] [i32 16, i32 40, i32 7429552], [3 x i32] [i32 322, i32 445, i32 7354436], [3 x i32] [i32 429, i32 465, i32 12181642], [3 x i32] [i32 633, i32 257, i32 5046100], [3 x i32] [i32 39, i32 327, i32 8084592], [3 x i32] [i32 256, i32 530, i32 16435783], [3 x i32] [i32 367, i32 29, i32 9214164], [3 x i32] [i32 245, i32 552, i32 1027154], [3 x i32] [i32 232, i32 288, i32 14172151], [3 x i32] [i32 93, i32 425, i32 10404819], [3 x i32] [i32 530, i32 496, i32 2685554], [3 x i32] [i32 205, i32 545, i32 9891471], [3 x i32] [i32 110, i32 427, i32 7628983], [3 x i32] [i32 298, i32 346, i32 11452609], [3 x i32] [i32 633, i32 359, i32 3394207], [3 x i32] [i32 609, i32 407, i32 3486714], [3 x i32] [i32 398, i32 49, i32 15366155], [3 x i32] [i32 63, i32 527, i32 6160162], [3 x i32] [i32 311, i32 96, i32 105981], [3 x i32] [i32 727, i32 201, i32 9827702], [3 x i32] [i32 630, i32 316, i32 13555200], [3 x i32] [i32 699, i32 169, i32 4481560], [3 x i32] [i32 731, i32 347, i32 12098681], [3 x i32] [i32 100, i32 381, i32 12245631], [3 x i32] [i32 770, i32 247, i32 13267674], [3 x i32] [i32 529, i32 123, i32 11677846], [3 x i32] [i32 411, i32 211, i32 13468432], [3 x i32] [i32 459, i32 342, i32 14129095], [3 x i32] [i32 433, i32 181, i32 10508253], [3 x i32] [i32 704, i32 268, i32 7340572], [3 x i32] [i32 683, i32 273, i32 6896895], [3 x i32] [i32 705, i32 3, i32 11830786], [3 x i32] [i32 66, i32 490, i32 1521645], [3 x i32] [i32 694, i32 326, i32 7597392], [3 x i32] [i32 169, i32 359, i32 13177975], [3 x i32] [i32 135, i32 265, i32 4607890], [3 x i32] [i32 92, i32 451, i32 5972511], [3 x i32] [i32 720, i32 29, i32 5711389], [3 x i32] [i32 711, i32 582, i32 11496075], [3 x i32] [i32 167, i32 469, i32 791786], [3 x i32] [i32 44, i32 583, i32 2635077], [3 x i32] [i32 630, i32 46, i32 9946804], [3 x i32] [i32 262, i32 160, i32 6162150], [3 x i32] [i32 457, i32 574, i32 14793056], [3 x i32] [i32 415, i32 266, i32 13430405], [3 x i32] [i32 16, i32 283, i32 7321896], [3 x i32] [i32 5, i32 245, i32 3194004], [3 x i32] [i32 331, i32 137, i32 3298150]], align 16

; Function Attrs: mustprogress uwtable
define dso_local noundef signext i8 @_Z10fillCircleiiiiPi(i32 noundef %0, i32 noundef %1, i32 noundef %2, i32 noundef %3, i32* nocapture noundef %4) local_unnamed_addr #0 {
  %6 = sub i32 0, %2
  %7 = icmp slt i32 %2, 0
  br i1 %7, label %17, label %8

8:                                                ; preds = %5
  %9 = mul nsw i32 %2, %2
  %10 = getelementptr inbounds i32, i32* %4, i64 1
  %11 = getelementptr inbounds i32, i32* %4, i64 2
  br label %12

12:                                               ; preds = %19, %8
  %13 = phi i8 [ 0, %8 ], [ %41, %19 ]
  %14 = phi i32 [ %6, %8 ], [ %20, %19 ]
  %15 = mul nsw i32 %14, %14
  %16 = add nsw i32 %14, %1
  br label %22

17:                                               ; preds = %19, %5
  %18 = phi i8 [ 0, %5 ], [ %41, %19 ]
  ret i8 %18

19:                                               ; preds = %40
  %20 = add i32 %14, 1
  %21 = icmp eq i32 %14, %2
  br i1 %21, label %17, label %12, !llvm.loop !5

22:                                               ; preds = %12, %40
  %23 = phi i8 [ %13, %12 ], [ %41, %40 ]
  %24 = phi i32 [ %6, %12 ], [ %42, %40 ]
  %25 = mul nsw i32 %24, %24
  %26 = add nuw nsw i32 %25, %15
  %27 = icmp ugt i32 %26, %9
  br i1 %27, label %40, label %28

28:                                               ; preds = %22
  %29 = add nsw i32 %24, %0
  %30 = tail call signext i8 @setPixel(i32 noundef %29, i32 noundef %16, i32 noundef %3)
  %31 = or i8 %30, %23
  %32 = icmp eq i8 %30, 0
  br i1 %32, label %40, label %33

33:                                               ; preds = %28
  %34 = load i32, i32* %4, align 4, !tbaa !7
  %35 = add nsw i32 %34, %29
  store i32 %35, i32* %4, align 4, !tbaa !7
  %36 = load i32, i32* %10, align 4, !tbaa !7
  %37 = add nsw i32 %36, %16
  store i32 %37, i32* %10, align 4, !tbaa !7
  %38 = load i32, i32* %11, align 4, !tbaa !7
  %39 = add nsw i32 %38, 1
  store i32 %39, i32* %11, align 4, !tbaa !7
  br label %40

40:                                               ; preds = %28, %33, %22
  %41 = phi i8 [ %23, %22 ], [ %31, %33 ], [ %31, %28 ]
  %42 = add i32 %24, 1
  %43 = icmp eq i32 %24, %2
  br i1 %43, label %19, label %22, !llvm.loop !11
}

; Function Attrs: argmemonly mustprogress nofree nosync nounwind willreturn
declare void @llvm.lifetime.start.p0i8(i64 immarg, i8* nocapture) #1

declare signext i8 @setPixel(i32 noundef, i32 noundef, i32 noundef) local_unnamed_addr #2

; Function Attrs: argmemonly mustprogress nofree nosync nounwind willreturn
declare void @llvm.lifetime.end.p0i8(i64 immarg, i8* nocapture) #1

; Function Attrs: mustprogress uwtable
define dso_local void @_Z8fakeMainv() local_unnamed_addr #0 {
  %1 = alloca [100 x i8], align 16
  %2 = alloca [100 x [3 x i32]], align 16
  %3 = getelementptr inbounds [100 x i8], [100 x i8]* %1, i64 0, i64 0
  %4 = bitcast [100 x [3 x i32]]* %2 to i8*
  br label %6

5:                                                ; preds = %153
  ret void

6:                                                ; preds = %0, %153
  %7 = phi i32 [ 0, %0 ], [ %154, %153 ]
  call void @llvm.lifetime.start.p0i8(i64 100, i8* nonnull %3) #4
  call void @llvm.memset.p0i8.i64(i8* noundef nonnull align 16 dereferenceable(100) %3, i8 0, i64 100, i1 false)
  call void @llvm.lifetime.start.p0i8(i64 1200, i8* nonnull %4) #4
  call void @llvm.memset.p0i8.i64(i8* noundef nonnull align 16 dereferenceable(1200) %4, i8 0, i64 1200, i1 false)
  br label %8

8:                                                ; preds = %6, %86
  %9 = phi i64 [ 0, %6 ], [ %87, %86 ]
  %10 = getelementptr inbounds [100 x [3 x i32]], [100 x [3 x i32]]* @arr, i64 0, i64 %9, i64 0
  %11 = load i32, i32* %10, align 4, !tbaa !7
  %12 = getelementptr inbounds [100 x [3 x i32]], [100 x [3 x i32]]* @arr, i64 0, i64 %9, i64 1
  %13 = load i32, i32* %12, align 4, !tbaa !7
  %14 = getelementptr inbounds [100 x [3 x i32]], [100 x [3 x i32]]* %2, i64 0, i64 %9, i64 0
  %15 = getelementptr inbounds [100 x [3 x i32]], [100 x [3 x i32]]* %2, i64 0, i64 %9, i64 1
  %16 = getelementptr inbounds [100 x [3 x i32]], [100 x [3 x i32]]* %2, i64 0, i64 %9, i64 2
  %17 = add nsw i32 %11, -2
  %18 = add nsw i32 %11, -1
  %19 = add nsw i32 %11, 1
  %20 = add nsw i32 %11, 2
  br label %21

21:                                               ; preds = %83, %8
  %22 = phi i32 [ -2, %8 ], [ %84, %83 ]
  %23 = mul nsw i32 %22, %22
  %24 = add nsw i32 %22, %13
  %25 = icmp eq i32 %23, 0
  br i1 %25, label %26, label %36

26:                                               ; preds = %21
  %27 = tail call signext i8 @setPixel(i32 noundef %17, i32 noundef %24, i32 noundef 0)
  %28 = icmp eq i8 %27, 0
  br i1 %28, label %38, label %29

29:                                               ; preds = %26
  %30 = load i32, i32* %14, align 4, !tbaa !7
  %31 = add nsw i32 %30, %17
  store i32 %31, i32* %14, align 4, !tbaa !7
  %32 = load i32, i32* %15, align 4, !tbaa !7
  %33 = add nsw i32 %32, %24
  store i32 %33, i32* %15, align 4, !tbaa !7
  %34 = load i32, i32* %16, align 4, !tbaa !7
  %35 = add nsw i32 %34, 1
  store i32 %35, i32* %16, align 4, !tbaa !7
  br label %38

36:                                               ; preds = %21
  %37 = icmp ugt i32 %23, 3
  br i1 %37, label %48, label %38

38:                                               ; preds = %26, %29, %36
  %39 = tail call signext i8 @setPixel(i32 noundef %18, i32 noundef %24, i32 noundef 0)
  %40 = icmp eq i8 %39, 0
  br i1 %40, label %50, label %41

41:                                               ; preds = %38
  %42 = load i32, i32* %14, align 4, !tbaa !7
  %43 = add nsw i32 %42, %18
  store i32 %43, i32* %14, align 4, !tbaa !7
  %44 = load i32, i32* %15, align 4, !tbaa !7
  %45 = add nsw i32 %44, %24
  store i32 %45, i32* %15, align 4, !tbaa !7
  %46 = load i32, i32* %16, align 4, !tbaa !7
  %47 = add nsw i32 %46, 1
  store i32 %47, i32* %16, align 4, !tbaa !7
  br label %50

48:                                               ; preds = %36
  %49 = icmp eq i32 %23, 4
  br i1 %49, label %50, label %83

50:                                               ; preds = %38, %41, %48
  %51 = phi i1 [ true, %48 ], [ false, %41 ], [ false, %38 ]
  %52 = tail call signext i8 @setPixel(i32 noundef %11, i32 noundef %24, i32 noundef 0)
  %53 = icmp eq i8 %52, 0
  br i1 %53, label %61, label %54

54:                                               ; preds = %50
  %55 = load i32, i32* %14, align 4, !tbaa !7
  %56 = add nsw i32 %55, %11
  store i32 %56, i32* %14, align 4, !tbaa !7
  %57 = load i32, i32* %15, align 4, !tbaa !7
  %58 = add nsw i32 %57, %24
  store i32 %58, i32* %15, align 4, !tbaa !7
  %59 = load i32, i32* %16, align 4, !tbaa !7
  %60 = add nsw i32 %59, 1
  store i32 %60, i32* %16, align 4, !tbaa !7
  br i1 %51, label %72, label %62

61:                                               ; preds = %50
  br i1 %51, label %72, label %62

62:                                               ; preds = %54, %61
  %63 = tail call signext i8 @setPixel(i32 noundef %19, i32 noundef %24, i32 noundef 0)
  %64 = icmp eq i8 %63, 0
  br i1 %64, label %72, label %65

65:                                               ; preds = %62
  %66 = load i32, i32* %14, align 4, !tbaa !7
  %67 = add nsw i32 %66, %19
  store i32 %67, i32* %14, align 4, !tbaa !7
  %68 = load i32, i32* %15, align 4, !tbaa !7
  %69 = add nsw i32 %68, %24
  store i32 %69, i32* %15, align 4, !tbaa !7
  %70 = load i32, i32* %16, align 4, !tbaa !7
  %71 = add nsw i32 %70, 1
  store i32 %71, i32* %16, align 4, !tbaa !7
  br label %72

72:                                               ; preds = %54, %65, %62, %61
  br i1 %25, label %73, label %83

73:                                               ; preds = %72
  %74 = tail call signext i8 @setPixel(i32 noundef %20, i32 noundef %24, i32 noundef 0)
  %75 = icmp eq i8 %74, 0
  br i1 %75, label %83, label %76

76:                                               ; preds = %73
  %77 = load i32, i32* %14, align 4, !tbaa !7
  %78 = add nsw i32 %77, %20
  store i32 %78, i32* %14, align 4, !tbaa !7
  %79 = load i32, i32* %15, align 4, !tbaa !7
  %80 = add nsw i32 %79, %24
  store i32 %80, i32* %15, align 4, !tbaa !7
  %81 = load i32, i32* %16, align 4, !tbaa !7
  %82 = add nsw i32 %81, 1
  store i32 %82, i32* %16, align 4, !tbaa !7
  br label %83

83:                                               ; preds = %48, %76, %73, %72
  %84 = add nsw i32 %22, 1
  %85 = icmp eq i32 %22, 2
  br i1 %85, label %86, label %21, !llvm.loop !5

86:                                               ; preds = %83
  %87 = add nuw nsw i64 %9, 1
  %88 = icmp eq i64 %87, 100
  br i1 %88, label %91, label %8, !llvm.loop !12

89:                                               ; preds = %148
  %90 = icmp eq i8 %149, 0
  br i1 %90, label %152, label %91, !llvm.loop !13

91:                                               ; preds = %86, %89
  %92 = phi i32 [ %93, %89 ], [ 2, %86 ]
  %93 = add nuw nsw i32 %92, 1
  %94 = xor i32 %92, -1
  %95 = mul nsw i32 %93, %93
  br label %96

96:                                               ; preds = %91, %148
  %97 = phi i64 [ 0, %91 ], [ %150, %148 ]
  %98 = phi i8 [ 0, %91 ], [ %149, %148 ]
  %99 = getelementptr inbounds [100 x i8], [100 x i8]* %1, i64 0, i64 %97
  %100 = load i8, i8* %99, align 1, !tbaa !14
  %101 = icmp eq i8 %100, 0
  br i1 %101, label %102, label %148

102:                                              ; preds = %96
  %103 = getelementptr inbounds [100 x [3 x i32]], [100 x [3 x i32]]* @arr, i64 0, i64 %97, i64 0
  %104 = load i32, i32* %103, align 4, !tbaa !7
  %105 = getelementptr inbounds [100 x [3 x i32]], [100 x [3 x i32]]* @arr, i64 0, i64 %97, i64 1
  %106 = load i32, i32* %105, align 4, !tbaa !7
  %107 = getelementptr inbounds [100 x [3 x i32]], [100 x [3 x i32]]* @arr, i64 0, i64 %97, i64 2
  %108 = load i32, i32* %107, align 4, !tbaa !7
  %109 = getelementptr inbounds [100 x [3 x i32]], [100 x [3 x i32]]* %2, i64 0, i64 %97, i64 0
  %110 = getelementptr inbounds [100 x [3 x i32]], [100 x [3 x i32]]* %2, i64 0, i64 %97, i64 1
  %111 = getelementptr inbounds [100 x [3 x i32]], [100 x [3 x i32]]* %2, i64 0, i64 %97, i64 2
  br label %112

112:                                              ; preds = %117, %102
  %113 = phi i8 [ 0, %102 ], [ %139, %117 ]
  %114 = phi i32 [ %94, %102 ], [ %118, %117 ]
  %115 = mul nsw i32 %114, %114
  %116 = add nsw i32 %114, %106
  br label %120

117:                                              ; preds = %138
  %118 = add i32 %114, 1
  %119 = icmp eq i32 %114, %93
  br i1 %119, label %142, label %112, !llvm.loop !5

120:                                              ; preds = %138, %112
  %121 = phi i8 [ %113, %112 ], [ %139, %138 ]
  %122 = phi i32 [ %94, %112 ], [ %140, %138 ]
  %123 = mul nsw i32 %122, %122
  %124 = add nuw nsw i32 %123, %115
  %125 = icmp ugt i32 %124, %95
  br i1 %125, label %138, label %126

126:                                              ; preds = %120
  %127 = add nsw i32 %122, %104
  %128 = tail call signext i8 @setPixel(i32 noundef %127, i32 noundef %116, i32 noundef %108)
  %129 = or i8 %128, %121
  %130 = icmp eq i8 %128, 0
  br i1 %130, label %138, label %131

131:                                              ; preds = %126
  %132 = load i32, i32* %109, align 4, !tbaa !7
  %133 = add nsw i32 %132, %127
  store i32 %133, i32* %109, align 4, !tbaa !7
  %134 = load i32, i32* %110, align 4, !tbaa !7
  %135 = add nsw i32 %134, %116
  store i32 %135, i32* %110, align 4, !tbaa !7
  %136 = load i32, i32* %111, align 4, !tbaa !7
  %137 = add nsw i32 %136, 1
  store i32 %137, i32* %111, align 4, !tbaa !7
  br label %138

138:                                              ; preds = %131, %126, %120
  %139 = phi i8 [ %121, %120 ], [ %129, %131 ], [ %129, %126 ]
  %140 = add i32 %122, 1
  %141 = icmp eq i32 %122, %93
  br i1 %141, label %117, label %120, !llvm.loop !11

142:                                              ; preds = %117
  %143 = icmp ne i8 %139, 0
  %144 = xor i1 %143, true
  %145 = zext i1 %144 to i8
  store i8 %145, i8* %99, align 1, !tbaa !14
  %146 = zext i1 %143 to i8
  %147 = or i8 %98, %146
  br label %148

148:                                              ; preds = %96, %142
  %149 = phi i8 [ %98, %96 ], [ %147, %142 ]
  %150 = add nuw nsw i64 %97, 1
  %151 = icmp eq i64 %150, 100
  br i1 %151, label %89, label %96, !llvm.loop !15

152:                                              ; preds = %89
  tail call void @updateGPUBuffer()
  br label %156

153:                                              ; preds = %156
  tail call void @flush()
  call void @llvm.lifetime.end.p0i8(i64 1200, i8* nonnull %4) #4
  call void @llvm.lifetime.end.p0i8(i64 100, i8* nonnull %3) #4
  %154 = add nuw nsw i32 %7, 1
  %155 = icmp eq i32 %154, 100
  br i1 %155, label %5, label %6, !llvm.loop !16

156:                                              ; preds = %152, %156
  %157 = phi i64 [ 0, %152 ], [ %168, %156 ]
  %158 = getelementptr inbounds [100 x [3 x i32]], [100 x [3 x i32]]* %2, i64 0, i64 %157, i64 0
  %159 = load i32, i32* %158, align 4, !tbaa !7
  %160 = getelementptr inbounds [100 x [3 x i32]], [100 x [3 x i32]]* %2, i64 0, i64 %157, i64 2
  %161 = load i32, i32* %160, align 4, !tbaa !7
  %162 = sdiv i32 %159, %161
  %163 = getelementptr inbounds [100 x [3 x i32]], [100 x [3 x i32]]* @arr, i64 0, i64 %157, i64 0
  store i32 %162, i32* %163, align 4, !tbaa !7
  %164 = getelementptr inbounds [100 x [3 x i32]], [100 x [3 x i32]]* %2, i64 0, i64 %157, i64 1
  %165 = load i32, i32* %164, align 4, !tbaa !7
  %166 = sdiv i32 %165, %161
  %167 = getelementptr inbounds [100 x [3 x i32]], [100 x [3 x i32]]* @arr, i64 0, i64 %157, i64 1
  store i32 %166, i32* %167, align 4, !tbaa !7
  %168 = add nuw nsw i64 %157, 1
  %169 = icmp eq i64 %168, 100
  br i1 %169, label %153, label %156, !llvm.loop !17
}

; Function Attrs: argmemonly mustprogress nofree nounwind willreturn writeonly
declare void @llvm.memset.p0i8.i64(i8* nocapture writeonly, i8, i64, i1 immarg) #3

declare void @updateGPUBuffer() local_unnamed_addr #2

declare void @flush() local_unnamed_addr #2

attributes #0 = { mustprogress uwtable "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { argmemonly mustprogress nofree nosync nounwind willreturn }
attributes #2 = { "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { argmemonly mustprogress nofree nounwind willreturn writeonly }
attributes #4 = { nounwind }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 1}
!4 = !{!"Ubuntu clang version 14.0.0-1ubuntu1.1"}
!5 = distinct !{!5, !6}
!6 = !{!"llvm.loop.mustprogress"}
!7 = !{!8, !8, i64 0}
!8 = !{!"int", !9, i64 0}
!9 = !{!"omnipotent char", !10, i64 0}
!10 = !{!"Simple C++ TBAA"}
!11 = distinct !{!11, !6}
!12 = distinct !{!12, !6}
!13 = distinct !{!13, !6}
!14 = !{!9, !9, i64 0}
!15 = distinct !{!15, !6}
!16 = distinct !{!16, !6}
!17 = distinct !{!17, !6}
