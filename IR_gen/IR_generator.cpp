#include "generators.hpp"

using namespace llvm;

int main() {
    LLVMContext context;
    // ; ModuleID = 'fakeMain.cpp'
    // source_filename = "fakeMain.cpp"
    Module *module = new Module("fakeMain.cpp", context);
    IRBuilder<> builder(context);

    auto *arrayType3ints = ArrayType::get(Type::getInt32Ty(context), 3);
    auto *arrayType100by3ints = ArrayType::get(arrayType3ints, 100);
    GlobalVariable* gvar_ptr_abc = new GlobalVariable(*module, static_cast<Type *>(arrayType100by3ints), true, GlobalValue::PrivateLinkage, 0, "arr");
    gvar_ptr_abc->setAlignment(Align(16));

    // define dso_local void @app() local_unnamed_addr #0 {
    Function *fakeMainFunc = IR_gen::generateFakeMain(context, builder, module);

    // Dump LLVM IR
    module->print(outs(), nullptr);
    
    return 0;
}