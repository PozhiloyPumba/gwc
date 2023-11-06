#include "generators.hpp"

namespace IR_gen {

using namespace llvm;

Function *generateFakeMain(LLVMContext &context, IRBuilder<> &builder, llvm::Module *module) {

    // declare char @setPixel(i32 noundef, i32 noundef, i32 noundef)
    // local_unnamed_addr #1
    ArrayRef<Type *> setPixelParamTypes = { Type::getInt32Ty(context),
                                            Type::getInt32Ty(context),
                                            Type::getInt32Ty(context)};
    FunctionType *setPixelType =
        FunctionType::get(Type::getInt8Ty(context), setPixelParamTypes, false);
    FunctionType *emptyType =
        FunctionType::get(Type::getVoidTy(context), false);

    FunctionCallee setPixelCallee = module->getOrInsertFunction("setPixel", setPixelType);
    FunctionCallee updateGPUBufferCallee = module->getOrInsertFunction("updateGPUBuffer", emptyType);
    FunctionCallee flushCallee = module->getOrInsertFunction("flush", emptyType);

    Function *fakeMainFunc = 
        Function::Create(emptyType, Function::ExternalLinkage, "fakeMain", module);
    // BasicBlocks:
    BasicBlock *BB0 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB7 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB8 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB10 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB23 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB28 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB31 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB38 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB40 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB43 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB50 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB52 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB56 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB63 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB64 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB67 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB74 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB75 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB78 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB85 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB88 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB91 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB93 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB98 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB104 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB114 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB119 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB122 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB128 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB133 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB140 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB144 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB150 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB154 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB155 = BasicBlock::Create(context, "", fakeMainFunc);
    BasicBlock *BB158 = BasicBlock::Create(context, "", fakeMainFunc);

    builder.SetInsertPoint(BB0);

    // %1 = alloca [100 x [3 x i32]], align 16
    auto arrayType3ints = ArrayType::get(Type::getInt32Ty(context), 3);
    auto arrayType100by3ints = ArrayType::get(arrayType3ints, 100);
    auto *val1 = builder.CreateAlloca(arrayType100by3ints);
    val1->setAlignment(Align(16));

    // %2 = alloca [100 x i8], align 16
    auto *val2 = builder.CreateAlloca(ArrayType::get(Type::getInt8Ty(context), 100));
    val2->setAlignment(Align(16));

    // %3 = alloca [100 x [3 x i32]], align 16
    auto *val3 = builder.CreateAlloca(arrayType100by3ints);
    val3->setAlignment(Align(16));

    // %4 = bitcast [100 x [3 x i32]]* %1 to i8*
    auto *val4 = builder.CreateBitCast(val1, Type::getInt8PtrTy(context));

    //TODO: call void @llvm.lifetime.start.p0i8(i64 1200, i8* nonnull %4) #5

    //TODO: call void @llvm.memcpy.p0i8.p0i8.i64(i8* noundef nonnull align 16 dereferenceable(1200) %4, i8* noundef nonnull align 16 dereferenceable(1200) bitcast ([100 x [3 x i32]]* @__const.fakeMain.arr to i8*), i64 1200, i1 false)

    // %5 = getelementptr inbounds [100 x i8], [100 x i8]* %2, i64 0, i64 0
    auto *val5 = builder.CreateConstInBoundsGEP2_64(ArrayType::get(Type::getInt8Ty(context), 100), val2, 0, 0);

    // %6 = bitcast [100 x [3 x i32]]* %3 to i8*
    auto *val6 = builder.CreateBitCast(val3, Type::getInt8PtrTy(context));
    // br label %8
    builder.CreateBr(BB8);

    // 7:                                                ; preds = %155
    builder.SetInsertPoint(BB7);
    // TODO: call void @llvm.lifetime.end.p0i8(i64 1200, i8* nonnull %4) #5

    // ret void
    builder.CreateRetVoid();

    // 8:                                                ; preds = %0, %155
    builder.SetInsertPoint(BB8);

    // %9 = phi i32 [ 0, %0 ], [ %156, %155 ]
    auto *val9 = builder.CreatePHI(Type::getInt32Ty(context), 2);
    // br label %10
    builder.CreateBr(BB10);

    // 10:                                               ; preds = %8, %88
    builder.SetInsertPoint(BB10);

    // %11 = phi i64 [ 0, %8 ], [ %89, %88 ]
    auto *val11 = builder.CreatePHI(Type::getInt64Ty(context), 2);

    // %12 = getelementptr inbounds [100 x [3 x i32]], [100 x [3 x i32]]* %1, i64 0, i64 %11, i64 0
    std::vector<Value *> valuesForGEP12 = {builder.getInt64(0), val11, builder.getInt64(0)};
    auto *val12 = builder.CreateGEP(arrayType100by3ints, val1, valuesForGEP12);

    // %13 = load i32, i32* %12, align 4, !tbaa !7
    auto *val13 = builder.CreateLoad(Type::getInt32Ty(context), val12);
    val13->setAlignment(Align(4));
    // TODO: val13->setAAMetadata(,);

    // %14 = getelementptr inbounds [100 x [3 x i32]], [100 x [3 x i32]]* %1, i64 0, i64 %11, i64 1
    std::vector<Value *> valuesForGEP14 = {builder.getInt64(0), val11, builder.getInt64(1)};
    auto *val14 = builder.CreateGEP(arrayType100by3ints, val1, valuesForGEP14);

    // %15 = load i32, i32* %14, align 4, !tbaa !7
    auto *val15 = builder.CreateLoad(Type::getInt32Ty(context), val14);
    val15->setAlignment(Align(4));

    // %16 = getelementptr inbounds [100 x [3 x i32]], [100 x [3 x i32]]* %3, i64 0, i64 %11, i64 0
    auto *val16 = builder.CreateGEP(arrayType100by3ints, val3, valuesForGEP12);

    // %17 = getelementptr inbounds [100 x [3 x i32]], [100 x [3 x i32]]* %3, i64 0, i64 %11, i64 1
    auto *val17 = builder.CreateGEP(arrayType100by3ints, val3, valuesForGEP14);

    // %18 = getelementptr inbounds [100 x [3 x i32]], [100 x [3 x i32]]* %3, i64 0, i64 %11, i64 2
    std::vector<Value *> valuesForGEP18 = {builder.getInt64(0), val11, builder.getInt64(2)};
    auto *val18 = builder.CreateGEP(arrayType100by3ints, val3, valuesForGEP18);

    // %19 = add nsw i32 %13, -2
    auto *val19 = builder.CreateNSWAdd(val13, builder.getInt32(-2));

    // %20 = add nsw i32 %13, -1
    auto *val20 = builder.CreateNSWAdd(val13, builder.getInt32(-1));

    // %21 = add nsw i32 %13, 1
    auto *val21 = builder.CreateNSWAdd(val13, builder.getInt32(1));

    // %22 = add nsw i32 %13, 2
    auto *val22 = builder.CreateNSWAdd(val13, builder.getInt32(2));

    // br label %23
    builder.CreateBr(BB23);

    // 23:                                               ; preds = %85, %10
    builder.SetInsertPoint(BB23);

    // %24 = phi i32 [ -2, %10 ], [ %86, %85 ]
    auto *val24 = builder.CreatePHI(Type::getInt32Ty(context), 2);

    // %25 = mul nsw i32 %24, %24
    auto *val25 = builder.CreateNSWMul(val24, val24);

    // %26 = add nsw i32 %24, %15
    auto *val26 = builder.CreateNSWAdd(val24, val15);

    // %27 = icmp eq i32 %25, 0
    auto *val27 = builder.CreateICmpEQ(val25, builder.getInt32(0));

    // br i1 %27, label %28, label %38
    builder.CreateCondBr(val27, BB28, BB38);

    // 28:                                               ; preds = %23
    builder.SetInsertPoint(BB28);

    //TODO: %29 = tail call signext i8 @setPixel(i32 noundef %19, i32 noundef %26, i32 noundef 0)
    std::vector<Value *> valuesForCall29 = {val19, val26, builder.getInt32(0)};
    auto *val29 = builder.CreateCall(setPixelCallee, valuesForCall29);

    // %30 = icmp eq i8 %29, 0
    auto *val30 = builder.CreateICmpEQ(val29, builder.getInt8(0));

    // br i1 %30, label %40, label %31
    builder.CreateCondBr(val30, BB40, BB31);

    // 31:                                               ; preds = %28
    builder.SetInsertPoint(BB31);

    // %32 = load i32, i32* %16, align 4, TODO: !tbaa !7
    auto *val32 = builder.CreateLoad(Type::getInt32Ty(context), val16);
    val32->setAlignment(Align(4));

    // %33 = add nsw i32 %32, %19
    auto *val33 = builder.CreateNSWAdd(val32, val19);

    // store i32 %33, i32* %16, align 4, TODO: !tbaa !7
    builder.CreateStore(val33, val16)->setAlignment(Align(4));

    // %34 = load i32, i32* %17, align 4, TODO: !tbaa !7
    auto *val34 = builder.CreateLoad(Type::getInt32Ty(context), val17);
    val34->setAlignment(Align(4));

    // %35 = add nsw i32 %34, %26
    auto *val35 = builder.CreateNSWAdd(val34, val26);

    // store i32 %35, i32* %17, align 4, TODO: !tbaa !7
    builder.CreateStore(val35, val17)->setAlignment(Align(4));

    // %36 = load i32, i32* %18, align 4, TODO: !tbaa !7
    auto *val36 = builder.CreateLoad(Type::getInt32Ty(context), val18);
    val34->setAlignment(Align(4));

    // %37 = add nsw i32 %36, 1
    auto *val37 = builder.CreateNSWAdd(val36, builder.getInt32(1));

    // store i32 %37, i32* %18, align 4, TODO: !tbaa !7
    builder.CreateStore(val37, val18)->setAlignment(Align(4));

    // br label %40
    builder.CreateBr(BB40);

    // 38:                                               ; preds = %23
    builder.SetInsertPoint(BB38);

    // %39 = icmp ugt i32 %25, 3
    auto *val39 = builder.CreateICmpUGT(val25, builder.getInt32(3));

    // br i1 %39, label %50, label %40
    builder.CreateCondBr(val39, BB50, BB40);

    // 40:                                               ; preds = %28, %31, %38
    builder.SetInsertPoint(BB40);

    //TODO: %41 = tail call signext i8 @setPixel(i32 noundef %20, i32 noundef %26, i32 noundef 0)
    std::vector<Value *> valuesForCall41 = {val20, val26, builder.getInt32(0)};
    auto *val41 = builder.CreateCall(setPixelCallee, valuesForCall41);

    // %42 = icmp eq i8 %41, 0
    auto *val42 = builder.CreateICmpEQ(val41, builder.getInt8(0));

    // br i1 %42, label %52, label %43
    builder.CreateCondBr(val42, BB52, BB43);

    // 43:                                               ; preds = %40
    builder.SetInsertPoint(BB43);

    //TODO: %44 = load i32, i32* %16, align 4, !tbaa !7
    auto *val44 = builder.CreateLoad(Type::getInt32Ty(context), val16);
    val44->setAlignment(Align(4));

    // %45 = add nsw i32 %44, %20
    auto *val45 = builder.CreateNSWAdd(val44, val20);

    //TODO: store i32 %45, i32* %16, align 4, !tbaa !7
    builder.CreateStore(val45, val16)->setAlignment(Align(4));

    //TODO: %46 = load i32, i32* %17, align 4, !tbaa !7
    auto *val46 = builder.CreateLoad(Type::getInt32Ty(context), val17);
    val46->setAlignment(Align(4));

    // %47 = add nsw i32 %46, %26
    auto *val47 = builder.CreateNSWAdd(val46, val26);

    //TODO: store i32 %47, i32* %17, align 4, !tbaa !7
    builder.CreateStore(val47, val17)->setAlignment(Align(4));

    //TODO: %48 = load i32, i32* %18, align 4, !tbaa !7
    auto *val48 = builder.CreateLoad(Type::getInt32Ty(context), val18);
    val48->setAlignment(Align(4));

    // %49 = add nsw i32 %48, 1
    auto *val49 = builder.CreateNSWAdd(val48, builder.getInt32(1));

    //TODO: store i32 %49, i32* %18, align 4, !tbaa !7
    builder.CreateStore(val49, val18)->setAlignment(Align(4));

    // br label %52
    builder.CreateBr(BB52);

    // 50:                                               ; preds = %38
    builder.SetInsertPoint(BB50);

    // %51 = icmp eq i32 %25, 4
    auto *val51 = builder.CreateICmpEQ(val25, builder.getInt32(4));

    // br i1 %51, label %52, label %85
    builder.CreateCondBr(val51, BB52, BB85);

    // 52:                                               ; preds = %40, %43, %50
    builder.SetInsertPoint(BB52);

    // %53 = phi i1 [ true, %50 ], [ false, %43 ], [ false, %40 ]
    auto *val53 = builder.CreatePHI(builder.getInt1Ty(), 3);

    //TODO: %54 = tail call signext i8 @setPixel(i32 noundef %13, i32 noundef %26, i32 noundef 0)
    std::vector<Value *> valuesForCall54 = {val13, val26, builder.getInt32(0)};
    auto *val54 = builder.CreateCall(setPixelCallee, valuesForCall54);

    // %55 = icmp eq i8 %54, 0
    auto *val55 = builder.CreateICmpEQ(val54, builder.getInt8(0));

    // br i1 %55, label %63, label %56
    builder.CreateCondBr(val55, BB63, BB56);

    // 56:                                               ; preds = %52
    builder.SetInsertPoint(BB56);

    //TODO: %57 = load i32, i32* %16, align 4, !tbaa !7
    auto *val57 = builder.CreateLoad(Type::getInt32Ty(context), val16);
    val57->setAlignment(Align(4));

    // %58 = add nsw i32 %57, %13
    auto *val58 = builder.CreateNSWAdd(val57, val13);

    //TODO: store i32 %58, i32* %16, align 4, !tbaa !7
    builder.CreateStore(val58, val16)->setAlignment(Align(4));

    //TODO: %59 = load i32, i32* %17, align 4, !tbaa !7
    auto *val59 = builder.CreateLoad(Type::getInt32Ty(context), val17);
    val59->setAlignment(Align(4));

    // %60 = add nsw i32 %59, %26
    auto *val60 = builder.CreateNSWAdd(val59, val26);

    // store i32 %60, i32* %17, align 4, !tbaa !7
    builder.CreateStore(val60, val17)->setAlignment(Align(4));

    //TODO: %61 = load i32, i32* %18, align 4, !tbaa !7
    auto *val61 = builder.CreateLoad(Type::getInt32Ty(context), val18);
    val61->setAlignment(Align(4));

    // %62 = add nsw i32 %61, 1
    auto *val62 = builder.CreateNSWAdd(val61, builder.getInt32(1));

    //TODO: store i32 %62, i32* %18, align 4, !tbaa !7
    builder.CreateStore(val62, val18)->setAlignment(Align(4));

    // br i1 %53, label %74, label %64
    builder.CreateCondBr(val53, BB74, BB64);

    // 63:                                               ; preds = %52
    builder.SetInsertPoint(BB63);

    // br i1 %53, label %74, label %64
    builder.CreateCondBr(val53, BB74, BB64);

    // 64:                                               ; preds = %56, %63
    builder.SetInsertPoint(BB64);

    //TODO: %65 = tail call signext i8 @setPixel(i32 noundef %21, i32 noundef %26, i32 noundef 0)
    std::vector<Value *> valuesForCall65 = {val21, val26, builder.getInt32(0)};
    auto *val65 = builder.CreateCall(setPixelCallee, valuesForCall65);

    // %66 = icmp eq i8 %65, 0
    auto *val66 = builder.CreateICmpEQ(val65, builder.getInt8(0));

    // br i1 %66, label %74, label %67
    builder.CreateCondBr(val66, BB74, BB67);

    // 67:                                               ; preds = %64
    builder.SetInsertPoint(BB67);

    //TODO: %68 = load i32, i32* %16, align 4, !tbaa !7
    auto *val68 = builder.CreateLoad(Type::getInt32Ty(context), val16);
    val68->setAlignment(Align(4));

    // %69 = add nsw i32 %68, %21
    auto *val69 = builder.CreateNSWAdd(val68, val21);

    //TODO: store i32 %69, i32* %16, align 4, !tbaa !7
    builder.CreateStore(val69, val16)->setAlignment(Align(4));

    //TODO: %70 = load i32, i32* %17, align 4, !tbaa !7
    auto *val70 = builder.CreateLoad(Type::getInt32Ty(context), val17);
    val70->setAlignment(Align(4));

    // %71 = add nsw i32 %70, %26
    auto *val71 = builder.CreateNSWAdd(val70, val26);

    //TODO: store i32 %71, i32* %17, align 4, !tbaa !7
    builder.CreateStore(val71, val17)->setAlignment(Align(4));

    //TODO: %72 = load i32, i32* %18, align 4, !tbaa !7
    auto *val72 = builder.CreateLoad(Type::getInt32Ty(context), val18);
    val72->setAlignment(Align(4));

    // %73 = add nsw i32 %72, 1
    auto *val73 = builder.CreateNSWAdd(val72, builder.getInt32(1));

    //TODO: store i32 %73, i32* %18, align 4, !tbaa !7
    builder.CreateStore(val73, val18)->setAlignment(Align(4));

    // br label %74
    builder.CreateBr(BB74);

    // 74:                                               ; preds = %56, %67, %64, %63
    builder.SetInsertPoint(BB74);

    // br i1 %27, label %75, label %85
    builder.CreateCondBr(val27, BB75, BB85);

    // 75:                                               ; preds = %74
    builder.SetInsertPoint(BB75);

    //TODO: %76 = tail call signext i8 @setPixel(i32 noundef %22, i32 noundef %26, i32 noundef 0)
    std::vector<Value *> valuesForCall76 = {val22, val26, builder.getInt32(0)};
    auto *val76 = builder.CreateCall(setPixelCallee, valuesForCall76);

    // %77 = icmp eq i8 %76, 0
    auto *val77 = builder.CreateICmpEQ(val76, builder.getInt8(0));

    // br i1 %77, label %85, label %78
    builder.CreateCondBr(val77, BB85, BB78);

    // 78:                                               ; preds = %75
    builder.SetInsertPoint(BB78);

    //TODO: %79 = load i32, i32* %16, align 4, !tbaa !7
    auto *val79 = builder.CreateLoad(Type::getInt32Ty(context), val16);
    val79->setAlignment(Align(4));

    // %80 = add nsw i32 %79, %22
    auto *val80 = builder.CreateNSWAdd(val79, val22);

    //TODO: store i32 %80, i32* %16, align 4, !tbaa !7
    builder.CreateStore(val80, val16)->setAlignment(Align(4));

    //TODO: %81 = load i32, i32* %17, align 4, !tbaa !7
    auto *val81 = builder.CreateLoad(Type::getInt32Ty(context), val17);
    val81->setAlignment(Align(4));

    // %82 = add nsw i32 %81, %26
    auto *val82 = builder.CreateNSWAdd(val81, val26);

    //TODO: store i32 %82, i32* %17, align 4, !tbaa !7
    builder.CreateStore(val82, val17)->setAlignment(Align(4));

    //TODO: %83 = load i32, i32* %18, align 4, !tbaa !7
    auto *val83 = builder.CreateLoad(Type::getInt32Ty(context), val18);
    val83->setAlignment(Align(4));

    // %84 = add nsw i32 %83, 1
    auto *val84 = builder.CreateNSWAdd(val83, builder.getInt32(1));

    //TODO: store i32 %84, i32* %18, align 4, !tbaa !7
    builder.CreateStore(val84, val18)->setAlignment(Align(4));

    // br label %85
    builder.CreateBr(BB85);

    // 85:                                               ; preds = %50, %78, %75, %74
    builder.SetInsertPoint(BB85);

    // %86 = add nsw i32 %24, 1
    auto *val86 = builder.CreateNSWAdd(val24, builder.getInt32(1));

    // %87 = icmp eq i32 %24, 2
    auto *val87 = builder.CreateICmpEQ(val24, builder.getInt32(2));

    //TODO: br i1 %87, label %88, label %23, !llvm.loop !5
    builder.CreateCondBr(val87, BB88, BB23);

    // 88:                                               ; preds = %85
    builder.SetInsertPoint(BB88);

    // %89 = add nuw nsw i64 %11, 1
    auto *val89 = builder.CreateNSWAdd(val11, builder.getInt64(1));

    // %90 = icmp eq i64 %89, 100
    auto *val90 = builder.CreateICmpEQ(val89, builder.getInt64(100));

    //TODO: br i1 %90, label %93, label %10, !llvm.loop !12
    builder.CreateCondBr(val90, BB93, BB10);

    // 93:                                               ; preds = %88, %91
    builder.SetInsertPoint(BB93);

    // %94 = phi i32 [ %95, %91 ], [ 2, %88 ]
    auto *val94 = builder.CreatePHI(builder.getInt32Ty(), 2);

    // %95 = add nuw nsw i32 %94, 1
    auto *val95 = builder.CreateNSWAdd(val94, builder.getInt32(1));

    // %96 = xor i32 %94, -1
    auto *val96 = builder.CreateXor(val94, builder.getInt32(-1));

    // %97 = mul nsw i32 %95, %95
    auto *val97 = builder.CreateNSWMul(val95, val95);

    // br label %98
    builder.CreateBr(BB98);

    // 98:                                               ; preds = %93, %150
    builder.SetInsertPoint(BB98);

    // %99 = phi i64 [ 0, %93 ], [ %152, %150 ]
    auto *val99 = builder.CreatePHI(builder.getInt64Ty(), 2);

    // %100 = phi i8 [ 0, %93 ], [ %151, %150 ]
    auto *val100 = builder.CreatePHI(builder.getInt8Ty(), 2);

    // %101 = getelementptr inbounds [100 x i8], [100 x i8]* %2, i64 0, i64 %99
    std::vector<Value *> valuesForGEP101 = {builder.getInt64(0), val99};
    auto *val101 = builder.CreateGEP(ArrayType::get(builder.getInt8Ty(), 100), val2, valuesForGEP101);

    //TODO: %102 = load i8, i8* %101, align 1, !tbaa !14
    auto *val102 = builder.CreateLoad(Type::getInt8Ty(context), val101);
    val102->setAlignment(Align(1));

    // %103 = icmp eq i8 %102, 0
    auto *val103 = builder.CreateICmpEQ(val102, builder.getInt8(0));

    // br i1 %103, label %104, label %150
    builder.CreateCondBr(val103, BB104, BB150);

    // 104:                                              ; preds = %98
    builder.SetInsertPoint(BB104);

    // %105 = getelementptr inbounds [100 x [3 x i32]], [100 x [3 x i32]]* %1, i64 0, i64 %99, i64 0
    std::vector<Value *> valuesForGEP105 = {builder.getInt64(0), val99, builder.getInt64(0)};
    auto *val105 = builder.CreateGEP(arrayType100by3ints, val1, valuesForGEP105);

    //TODO: %106 = load i32, i32* %105, align 4, !tbaa !7
    auto *val106 = builder.CreateLoad(Type::getInt32Ty(context), val105);
    val106->setAlignment(Align(4));

    // %107 = getelementptr inbounds [100 x [3 x i32]], [100 x [3 x i32]]* %1, i64 0, i64 %99, i64 1
    valuesForGEP105[2] = builder.getInt64(1);
    auto *val107 = builder.CreateGEP(arrayType100by3ints, val1, valuesForGEP105);

    //TODO: %108 = load i32, i32* %107, align 4, !tbaa !7
    auto *val108 = builder.CreateLoad(Type::getInt32Ty(context), val107);
    val108->setAlignment(Align(4));

    // %109 = getelementptr inbounds [100 x [3 x i32]], [100 x [3 x i32]]* %1, i64 0, i64 %99, i64 2
    valuesForGEP105[2] = builder.getInt64(2);
    auto *val109 = builder.CreateGEP(arrayType100by3ints, val1, valuesForGEP105);

    //TODO: %110 = load i32, i32* %109, align 4, !tbaa !7
    auto *val110 = builder.CreateLoad(Type::getInt32Ty(context), val109);
    val110->setAlignment(Align(4));

    // %111 = getelementptr inbounds [100 x [3 x i32]], [100 x [3 x i32]]* %3, i64 0, i64 %99, i64 0
    valuesForGEP105[2] = builder.getInt64(0);
    auto *val111 = builder.CreateGEP(arrayType100by3ints, val3, valuesForGEP105);

    // %112 = getelementptr inbounds [100 x [3 x i32]], [100 x [3 x i32]]* %3, i64 0, i64 %99, i64 1
    valuesForGEP105[2] = builder.getInt64(1);
    auto *val112 = builder.CreateGEP(arrayType100by3ints, val3, valuesForGEP105);

    // %113 = getelementptr inbounds [100 x [3 x i32]], [100 x [3 x i32]]* %3, i64 0, i64 %99, i64 2
    valuesForGEP105[2] = builder.getInt64(2);
    auto *val113 = builder.CreateGEP(arrayType100by3ints, val3, valuesForGEP105);

    // br label %114
    builder.CreateBr(BB114);

    // 114:                                              ; preds = %119, %104
    builder.SetInsertPoint(BB114);

    // %115 = phi i8 [ 0, %104 ], [ %141, %119 ]
    auto *val115 = builder.CreatePHI(builder.getInt8Ty(), 2);

    // %116 = phi i32 [ %96, %104 ], [ %120, %119 ]
    auto *val116 = builder.CreatePHI(builder.getInt32Ty(), 2);

    // %117 = mul nsw i32 %116, %116
    auto *val117 = builder.CreateNSWMul(val116, val116);

    // %118 = add nsw i32 %116, %108
    auto *val118 = builder.CreateNSWAdd(val116, val108);

    // br label %122
    builder.CreateBr(BB122);

    // 119:                                              ; preds = %140
    builder.SetInsertPoint(BB119);

    // %120 = add i32 %116, 1
    auto *val120 = builder.CreateAdd(val116, builder.getInt32(1));

    // %121 = icmp eq i32 %116, %95
    auto *val121 = builder.CreateICmpEQ(val116, val95);

    //TODO: br i1 %121, label %144, label %114, !llvm.loop !5
    builder.CreateCondBr(val121, BB144, BB114);

    // 122:                                              ; preds = %140, %114
    builder.SetInsertPoint(BB122);

    // %123 = phi i8 [ %115, %114 ], [ %141, %140 ]
    auto *val123 = builder.CreatePHI(builder.getInt8Ty(), 2);

    // %124 = phi i32 [ %96, %114 ], [ %142, %140 ]
    auto *val124 = builder.CreatePHI(builder.getInt32Ty(), 2);

    // %125 = mul nsw i32 %124, %124
    auto *val125 = builder.CreateNSWMul(val124, val124);

    // %126 = add nuw nsw i32 %125, %117
    auto *val126 = builder.CreateAdd(val125, val117, "", true, true);

    // %127 = icmp ugt i32 %126, %97
    auto *val127 = builder.CreateICmpUGT(val126, val97);

    // br i1 %127, label %140, label %128
    builder.CreateCondBr(val127, BB140, BB128);

    // 128:                                              ; preds = %122
    builder.SetInsertPoint(BB128);

    // %129 = add nsw i32 %124, %106
    auto *val129 = builder.CreateNSWAdd(val124, val106);

    //TODO: %130 = tail call signext i8 @setPixel(i32 noundef %129, i32 noundef %118, i32 noundef %110)
    std::vector<Value *> valuesForCall130 = {val129, val118, val110};
    auto *val130 = builder.CreateCall(setPixelCallee, valuesForCall130);

    // %131 = or i8 %130, %123
    auto *val131 = builder.CreateOr(val130, val123);

    // %132 = icmp eq i8 %130, 0
    auto *val132 = builder.CreateICmpEQ(val130, builder.getInt8(0));

    // br i1 %132, label %140, label %133
    builder.CreateCondBr(val132, BB140, BB133);

    // 133:                                              ; preds = %128
    builder.SetInsertPoint(BB133);

    //TODO: %134 = load i32, i32* %111, align 4, !tbaa !7
    auto *val134 = builder.CreateLoad(Type::getInt32Ty(context), val111);
    val134->setAlignment(Align(4));

    // %135 = add nsw i32 %134, %129
    auto *val135 = builder.CreateNSWAdd(val134, val129);

    //TODO: store i32 %135, i32* %111, align 4, !tbaa !7
    builder.CreateStore(val135, val111)->setAlignment(Align(4));

    //TODO: %136 = load i32, i32* %112, align 4, !tbaa !7
    auto *val136 = builder.CreateLoad(Type::getInt32Ty(context), val112);
    val136->setAlignment(Align(4));

    // %137 = add nsw i32 %136, %118
    auto *val137 = builder.CreateNSWAdd(val136, val118);

    //TODO: store i32 %137, i32* %112, align 4, !tbaa !7
    builder.CreateStore(val137, val112)->setAlignment(Align(4));

    //TODO: %138 = load i32, i32* %113, align 4, !tbaa !7
    auto *val138 = builder.CreateLoad(Type::getInt32Ty(context), val113);
    val138->setAlignment(Align(4));

    // %139 = add nsw i32 %138, 1
    auto *val139 = builder.CreateNSWAdd(val138, builder.getInt32(1));

    //TODO: store i32 %139, i32* %113, align 4, !tbaa !7
    builder.CreateStore(val139, val113)->setAlignment(Align(4));

    // br label %140
    builder.CreateBr(BB140);

    // 140:                                              ; preds = %133, %128, %122
    builder.SetInsertPoint(BB140);

    // %141 = phi i8 [ %123, %122 ], [ %131, %133 ], [ %131, %128 ]
    auto *val141 = builder.CreatePHI(builder.getInt8Ty(), 3);

    // %142 = add i32 %124, 1
    auto *val142 = builder.CreateAdd(val124, builder.getInt32(1));

    // %143 = icmp eq i32 %124, %95
    auto *val143 = builder.CreateICmpEQ(val124, val95);

    //TODO: br i1 %143, label %119, label %122, !llvm.loop !11
    builder.CreateCondBr(val143, BB119, BB122);

    // 144:                                              ; preds = %119
    builder.SetInsertPoint(BB144);

    // %145 = icmp ne i8 %141, 0
    auto *val145 = builder.CreateICmpNE(val141, builder.getInt8(0));

    // %146 = xor i1 %145, true
    auto *val146 = builder.CreateXor(val145, builder.getTrue());

    // %147 = zext i1 %146 to i8
    auto val147 = builder.CreateZExt(val146, builder.getInt8Ty());

    //TODO: store i8 %147, i8* %101, align 1, !tbaa !14
    builder.CreateStore(val147, val101)->setAlignment(Align(1));

    // %148 = zext i1 %145 to i8
    auto val148 = builder.CreateZExt(val145, builder.getInt8Ty());

    // %149 = or i8 %100, %148
    auto *val149 = builder.CreateOr(val100, val148);

    // br label %150
    builder.CreateBr(BB150);

    // 150:                                              ; preds = %98, %144
    builder.SetInsertPoint(BB150);

    // %151 = phi i8 [ %100, %98 ], [ %149, %144 ]
    auto *val151 = builder.CreatePHI(builder.getInt8Ty(), 2);

    // %152 = add nuw nsw i64 %99, 1
    auto *val152 = builder.CreateAdd(val99, builder.getInt64(1), "", true, true);

    // %153 = icmp eq i64 %152, 100
    auto *val153 = builder.CreateICmpEQ(val152, builder.getInt64(100));

    //TODO: br i1 %153, label %91, label %98, !llvm.loop !15
    builder.CreateCondBr(val153, BB91, BB98);

    // 91:                                               ; preds = %150
    builder.SetInsertPoint(BB91);

    // %92 = icmp eq i8 %151, 0
    auto *val92 = builder.CreateICmpEQ(val151, builder.getInt8(0));

    //TODO: br i1 %92, label %154, label %93, !llvm.loop !13
    builder.CreateCondBr(val92, BB154, BB93);

    // 154:                                              ; preds = %91
    builder.SetInsertPoint(BB154);

    //TODO: tail call void @updateGPUBuffer()
    builder.CreateCall(updateGPUBufferCallee);

    // br label %158
    builder.CreateBr(BB158);

    // 155:                                              ; preds = %158
    builder.SetInsertPoint(BB155);

    //TODO: tail call void @flush()
    builder.CreateCall(flushCallee);

    //TODO: call void @llvm.lifetime.end.p0i8(i64 1200, i8* nonnull %6) #5
    //TODO: call void @llvm.lifetime.end.p0i8(i64 100, i8* nonnull %5) #5
    // %156 = add nuw nsw i32 %9, 1
    auto *val156 = builder.CreateAdd(val9, builder.getInt32(1), "", true, true);

    // %157 = icmp eq i32 %156, 100
    auto *val157 = builder.CreateICmpEQ(val156, builder.getInt32(100));

    //TODO: br i1 %157, label %7, label %8, !llvm.loop !16
    builder.CreateCondBr(val157, BB7, BB8);

    // 158:                                              ; preds = %154, %158
    builder.SetInsertPoint(BB158);

    // %159 = phi i64 [ 0, %154 ], [ %170, %158 ]
    auto *val159 = builder.CreatePHI(builder.getInt64Ty(), 2);

    // %160 = getelementptr inbounds [100 x [3 x i32]], [100 x [3 x i32]]* %3, i64 0, i64 %159, i64 0
    std::vector<Value *> valuesForGEP160 = {builder.getInt64(0), val159, builder.getInt64(0)};
    auto *val160 = builder.CreateGEP(arrayType100by3ints, val3, valuesForGEP160);

    //TODO: %161 = load i32, i32* %160, align 4, !tbaa !7
    auto *val161 = builder.CreateLoad(Type::getInt32Ty(context), val160);
    val161->setAlignment(Align(4));

    // %162 = getelementptr inbounds [100 x [3 x i32]], [100 x [3 x i32]]* %3, i64 0, i64 %159, i64 2
    valuesForGEP160[2] = builder.getInt64(2);
    auto *val162 = builder.CreateGEP(arrayType100by3ints, val3, valuesForGEP160);

    //TODO: %163 = load i32, i32* %162, align 4, !tbaa !7
    auto *val163 = builder.CreateLoad(Type::getInt32Ty(context), val162);
    val163->setAlignment(Align(4));

    // %164 = sdiv i32 %161, %163
    auto *val164 = builder.CreateSDiv(val161, val163);

    // %165 = getelementptr inbounds [100 x [3 x i32]], [100 x [3 x i32]]* %1, i64 0, i64 %159, i64 0
    valuesForGEP160[2] = builder.getInt64(0);
    auto *val165 = builder.CreateGEP(arrayType100by3ints, val1, valuesForGEP160);

    // store i32 %164, i32* %165, align 4, !tbaa !7
    builder.CreateStore(val164, val165)->setAlignment(Align(4));

    // %166 = getelementptr inbounds [100 x [3 x i32]], [100 x [3 x i32]]* %3, i64 0, i64 %159, i64 1
    valuesForGEP160[2] = builder.getInt64(1);
    auto *val166 = builder.CreateGEP(arrayType100by3ints, val3, valuesForGEP160);

    //TODO: %167 = load i32, i32* %166, align 4, !tbaa !7
    auto *val167 = builder.CreateLoad(Type::getInt32Ty(context), val166);
    val167->setAlignment(Align(4));

    // %168 = sdiv i32 %167, %163
    auto *val168 = builder.CreateSDiv(val167, val163);

    // %169 = getelementptr inbounds [100 x [3 x i32]], [100 x [3 x i32]]* %1, i64 0, i64 %159, i64 1
    valuesForGEP160[2] = builder.getInt64(1);
    auto *val169 = builder.CreateGEP(arrayType100by3ints, val1, valuesForGEP160);

    //TODO: store i32 %168, i32* %169, align 4, !tbaa !7
    builder.CreateStore(val168, val169)->setAlignment(Align(4));

    // %170 = add nuw nsw i64 %159, 1
    auto *val170 = builder.CreateAdd(val159, builder.getInt64(1), "", true, true);

    // %171 = icmp eq i64 %170, 100
    auto *val171 = builder.CreateICmpEQ(val170, builder.getInt64(100));

    //TODO: br i1 %171, label %155, label %158, !llvm.loop !17
    builder.CreateCondBr(val171, BB155, BB158);

    return fakeMainFunc;
}

}