#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/InstrTypes.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"

using namespace llvm;

namespace {
struct MyPass : public FunctionPass {
    static char ID;
    MyPass() : FunctionPass(ID) {}

    static const inline StringRef myLoggerFuncName = "instrLogger";

    inline static bool isFuncLogger(StringRef name) {
        return name == myLoggerFuncName;
    }

    virtual bool runOnFunction(Function &F) {
        if (isFuncLogger(F.getName())) {
            return false;
        }
        // Dump Function
        outs() << "In a function called " << F.getName() << "\n\n";

        // skipper instruction
        auto skip = [](auto &I) -> bool {
            // Skip logger functions
            if (auto *call = dyn_cast<CallInst>(&I)) {
                Function *callee = call->getCalledFunction();
                if (callee && isFuncLogger(callee->getName())) {
                    return true;
                }
            }

            // Skip PHI Instrs
            if (auto *phi = dyn_cast<PHINode>(&I)) {
                return true;
            }
            return false;
        };

        // Prepare builder for IR modification
        LLVMContext &Ctx = F.getContext();
        IRBuilder<> builder(Ctx);
        Type *retType = Type::getVoidTy(Ctx);

        // Prepare logger function
        ArrayRef<Type *> callParamTypes = {builder.getInt8Ty()->getPointerTo()};
        FunctionType *callLogFuncType =
            FunctionType::get(retType, callParamTypes, false);
        FunctionCallee callLogFunc = F.getParent()->getOrInsertFunction(
            myLoggerFuncName, callLogFuncType);

        // Insert loggers for all instructions
        for (auto &B : F) {
            for (auto &I : B) {
                if (skip(I))
                    continue;

                builder.SetInsertPoint(&I);
                Value *instrName =
                    builder.CreateGlobalStringPtr(I.getOpcodeName());
                Value *args[] = {instrName};
                builder.CreateCall(callLogFunc, args);
            }
        }

        return true;
    }
};
} // namespace

char MyPass::ID = 0;

// Automatically enable the pass.
// http://adriansampson.net/blog/clangpass.html
static void registerMyPass(const PassManagerBuilder &,
                           legacy::PassManagerBase &PM) {
    PM.add(new MyPass());
}
// we use this pass after opimizer passes
static RegisterStandardPasses 
    RegisterMyPass(PassManagerBuilder::EP_OptimizerLast, registerMyPass);