#ifndef __IR_GENERATOR__
#define __IR_GENERATOR__

#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/MDBuilder.h"
#include "llvm/IR/Metadata.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/ADT/StringMap.h"
#include "llvm/Support/Alignment.h"

namespace IR_gen {

llvm::Function *generateFakeMain(llvm::LLVMContext &context, llvm::IRBuilder<> &builder, llvm::Module *module);

}

#endif