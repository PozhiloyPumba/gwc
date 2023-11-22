#include <cstdint>
#include <fstream>
#include <functional>
#include <iostream>
#include <stack>
#include <unordered_map>

#include <app.hpp>
#include <graphic.hpp>

#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/ExecutionEngine/Interpreter.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

enum InsnId_t {
    FLUSH,
    UPDATE_GPU_BUFFER,
    RET,
    ALLOCA_COORDS_AND_COLORS,
    ALLOCA,
    SET_ZEROS,
    MULI,
    ADDI,
    INC_EQ,
    XOR,
    MUL,
    ADD,
    GT,
    SET_PIXEL,
    EQ,
    DIV,
    OR,
    BR_COND,
    STORE_I8,
    STORE_I32,
    LOAD_I8,
    LOAD_I32,
    BR
};

using RegId_t = uint8_t;
using RegVal_t = int64_t;

constexpr const int REG_FILE_SIZE = 36;
struct CPU {
    RegVal_t REG_FILE[REG_FILE_SIZE] = {};
    RegVal_t PC;
    RegVal_t NEXT_PC;
    bool RUN;
    inline void dump() {}
};

enum class Fields { RS1, RS2, RS3, IMM, LABEL1, LABEL2 };

struct Instr {
    InsnId_t ID;
    std::function<void(CPU *, const Instr *,
                       const std::unordered_map<std::string, RegVal_t> *)>
        execute;
    RegId_t rs1;
    RegId_t rs2;
    RegId_t rs3;
    RegVal_t imm;
    std::string label1;
    std::string label2;
    std::string name;
    void dump() const {
        // outs()  << ID << "\n";
    }
};

void do_FLUSH(
    CPU *cpu, const Instr *instr,
    [[maybe_unused]] const std::unordered_map<std::string, RegVal_t> *BB_PC) {
    instr->dump();
    cpu->dump();

    flush();
}
void do_UPDATE_GPU_BUFFER(
    CPU *cpu, const Instr *instr,
    [[maybe_unused]] const std::unordered_map<std::string, RegVal_t> *BB_PC) {
    instr->dump();
    cpu->dump();

    updateGPUBuffer();
}
void do_RET(
    CPU *cpu, const Instr *instr,
    [[maybe_unused]] const std::unordered_map<std::string, RegVal_t> *BB_PC) {
    instr->dump();
    cpu->dump();

    cpu->RUN = false;
}

void do_ALLOCA_COORDS_AND_COLORS(
    CPU *cpu, const Instr *instr,
    [[maybe_unused]] const std::unordered_map<std::string, RegVal_t> *BB_PC) {
    instr->dump();
    cpu->dump();

    int arr[][3] = {
        {425, 536, 13974511}, {151, 368, 3572079},  {440, 249, 1591737},
        {3, 363, 4020334},    {715, 400, 6731484},  {58, 444, 15049432},
        {512, 555, 13193426}, {311, 331, 2822364},  {37, 103, 2708939},
        {656, 347, 505435},   {133, 358, 7584055},  {470, 494, 2201812},
        {147, 36, 12949952},  {211, 396, 11288287}, {451, 494, 3202092},
        {789, 392, 10526177}, {171, 367, 6475432},  {797, 484, 11629877},
        {186, 228, 5563096},  {167, 351, 13589823}, {505, 250, 3208161},
        {353, 284, 10462034}, {196, 117, 13461283}, {194, 257, 15139700},
        {103, 276, 12291396}, {646, 144, 1097829},  {188, 217, 13558239},
        {673, 10, 11114889},  {660, 520, 1556342},  {624, 169, 2951914},
        {394, 43, 2414789},   {51, 14, 16103385},   {569, 373, 15724377},
        {425, 523, 16143020}, {211, 568, 14574142}, {787, 224, 755813},
        {712, 54, 1316433},   {651, 459, 1672796},  {525, 230, 15763870},
        {129, 527, 10295048}, {631, 220, 9377424},  {4, 416, 12654176},
        {601, 32, 6459850},   {252, 593, 5256075},  {54, 385, 14883775},
        {115, 78, 8514895},   {604, 434, 3404590},  {20, 183, 1018311},
        {7, 326, 12269577},   {73, 18, 6594307},    {0, 456, 10733656},
        {479, 244, 2849870},  {16, 40, 7429552},    {322, 445, 7354436},
        {429, 465, 12181642}, {633, 257, 5046100},  {39, 327, 8084592},
        {256, 530, 16435783}, {367, 29, 9214164},   {245, 552, 1027154},
        {232, 288, 14172151}, {93, 425, 10404819},  {530, 496, 2685554},
        {205, 545, 9891471},  {110, 427, 7628983},  {298, 346, 11452609},
        {633, 359, 3394207},  {609, 407, 3486714},  {398, 49, 15366155},
        {63, 527, 6160162},   {311, 96, 105981},    {727, 201, 9827702},
        {630, 316, 13555200}, {699, 169, 4481560},  {731, 347, 12098681},
        {100, 381, 12245631}, {770, 247, 13267674}, {529, 123, 11677846},
        {411, 211, 13468432}, {459, 342, 14129095}, {433, 181, 10508253},
        {704, 268, 7340572},  {683, 273, 6896895},  {705, 3, 11830786},
        {66, 490, 1521645},   {694, 326, 7597392},  {169, 359, 13177975},
        {135, 265, 4607890},  {92, 451, 5972511},   {720, 29, 5711389},
        {711, 582, 11496075}, {167, 469, 791786},   {44, 583, 2635077},
        {630, 46, 9946804},   {262, 160, 6162150},  {457, 574, 14793056},
        {415, 266, 13430405}, {16, 283, 7321896},   {5, 245, 3194004},
        {331, 137, 3298150}};
    int *ptr = new int[300];
    memcpy(ptr, (void *)arr, 300 * sizeof(int));
    memcpy(&cpu->REG_FILE[instr->rs1], &ptr, 8);
}
void do_ALLOCA(
    CPU *cpu, const Instr *instr,
    [[maybe_unused]] const std::unordered_map<std::string, RegVal_t> *BB_PC) {
    instr->dump();
    cpu->dump();

    int *ptr = new int[instr->imm];
    memcpy(&cpu->REG_FILE[instr->rs1], &ptr, 8);
}
void do_SET_ZEROS(
    CPU *cpu, const Instr *instr,
    [[maybe_unused]] const std::unordered_map<std::string, RegVal_t> *BB_PC) {
    instr->dump();
    cpu->dump();

    memset(reinterpret_cast<void *>(cpu->REG_FILE[instr->rs1]), 0,
           instr->imm * sizeof(char));
}
void do_MULI(
    CPU *cpu, const Instr *instr,
    [[maybe_unused]] const std::unordered_map<std::string, RegVal_t> *BB_PC) {
    instr->dump();
    cpu->dump();

    cpu->REG_FILE[instr->rs1] =
        (int)cpu->REG_FILE[instr->rs2] * (int)instr->imm;
}
void do_ADDI(
    CPU *cpu, const Instr *instr,
    [[maybe_unused]] const std::unordered_map<std::string, RegVal_t> *BB_PC) {
    instr->dump();
    cpu->dump();

    cpu->REG_FILE[instr->rs1] =
        (int)cpu->REG_FILE[instr->rs2] + (int)instr->imm;
}
void do_INC_EQ(
    CPU *cpu, const Instr *instr,
    [[maybe_unused]] const std::unordered_map<std::string, RegVal_t> *BB_PC) {
    instr->dump();
    cpu->dump();

    cpu->REG_FILE[instr->rs2] += 1;
    cpu->REG_FILE[instr->rs1] =
        (int)cpu->REG_FILE[instr->rs2] == (int)instr->imm;
}
void do_XOR(
    CPU *cpu, const Instr *instr,
    [[maybe_unused]] const std::unordered_map<std::string, RegVal_t> *BB_PC) {
    instr->dump();
    cpu->dump();

    cpu->REG_FILE[instr->rs1] =
        (int)cpu->REG_FILE[instr->rs2] ^ (int)cpu->REG_FILE[instr->rs3];
}
void do_MUL(
    CPU *cpu, const Instr *instr,
    [[maybe_unused]] const std::unordered_map<std::string, RegVal_t> *BB_PC) {
    instr->dump();
    cpu->dump();

    cpu->REG_FILE[instr->rs1] =
        (int)cpu->REG_FILE[instr->rs2] * (int)cpu->REG_FILE[instr->rs3];
}
void do_ADD(
    CPU *cpu, const Instr *instr,
    [[maybe_unused]] const std::unordered_map<std::string, RegVal_t> *BB_PC) {
    instr->dump();
    cpu->dump();

    cpu->REG_FILE[instr->rs1] =
        (int)cpu->REG_FILE[instr->rs2] + (int)cpu->REG_FILE[instr->rs3];
}
void do_GT(
    CPU *cpu, const Instr *instr,
    [[maybe_unused]] const std::unordered_map<std::string, RegVal_t> *BB_PC) {
    instr->dump();
    cpu->dump();

    cpu->REG_FILE[instr->rs1] =
        (int)cpu->REG_FILE[instr->rs2] > (int)cpu->REG_FILE[instr->rs3];
}
void do_SET_PIXEL(
    CPU *cpu, const Instr *instr,
    [[maybe_unused]] const std::unordered_map<std::string, RegVal_t> *BB_PC) {
    instr->dump();
    cpu->dump();

    cpu->REG_FILE[0] =
        setPixel((int)cpu->REG_FILE[instr->rs1], (int)cpu->REG_FILE[instr->rs2],
                 (int)cpu->REG_FILE[instr->rs3]);
}
void do_EQ(
    CPU *cpu, const Instr *instr,
    [[maybe_unused]] const std::unordered_map<std::string, RegVal_t> *BB_PC) {
    instr->dump();
    cpu->dump();

    cpu->REG_FILE[instr->rs1] =
        (int)cpu->REG_FILE[instr->rs2] == (int)cpu->REG_FILE[instr->rs3];
}
void do_DIV(
    CPU *cpu, const Instr *instr,
    [[maybe_unused]] const std::unordered_map<std::string, RegVal_t> *BB_PC) {
    instr->dump();
    cpu->dump();

    cpu->REG_FILE[instr->rs1] =
        (int)cpu->REG_FILE[instr->rs2] / (int)cpu->REG_FILE[instr->rs3];
}
void do_OR(
    CPU *cpu, const Instr *instr,
    [[maybe_unused]] const std::unordered_map<std::string, RegVal_t> *BB_PC) {
    instr->dump();
    cpu->dump();

    cpu->REG_FILE[instr->rs1] =
        (int)cpu->REG_FILE[instr->rs2] | (int)cpu->REG_FILE[instr->rs3];
}
void do_BR_COND(
    CPU *cpu, const Instr *instr,
    [[maybe_unused]] const std::unordered_map<std::string, RegVal_t> *BB_PC) {
    instr->dump();
    cpu->dump();

    if (cpu->REG_FILE[instr->rs1] != 0) {
        cpu->NEXT_PC = BB_PC->at(instr->label1);
    } else {
        cpu->NEXT_PC = BB_PC->at(instr->label2);
    }
}
void do_STORE_I8(
    CPU *cpu, const Instr *instr,
    [[maybe_unused]] const std::unordered_map<std::string, RegVal_t> *BB_PC) {
    instr->dump();
    cpu->dump();

    char *ptr = (char *)static_cast<intptr_t>(
        cpu->REG_FILE[instr->rs2] +
        ((int)cpu->REG_FILE[instr->rs3] + (int)instr->imm) * sizeof(char));
    *ptr = cpu->REG_FILE[instr->rs1];
}
void do_STORE_I32(
    CPU *cpu, const Instr *instr,
    [[maybe_unused]] const std::unordered_map<std::string, RegVal_t> *BB_PC) {
    instr->dump();
    cpu->dump();

    int *ptr = (int *)static_cast<intptr_t>(
        cpu->REG_FILE[instr->rs2] +
        ((int)cpu->REG_FILE[instr->rs3] + (int)instr->imm) * sizeof(int));
    *ptr = cpu->REG_FILE[instr->rs1];
}
void do_LOAD_I8(
    CPU *cpu, const Instr *instr,
    [[maybe_unused]] const std::unordered_map<std::string, RegVal_t> *BB_PC) {
    instr->dump();
    cpu->dump();

    char *ptr = (char *)static_cast<intptr_t>(
        cpu->REG_FILE[instr->rs2] +
        ((int)cpu->REG_FILE[instr->rs3] + (int)instr->imm) * sizeof(char));
    cpu->REG_FILE[instr->rs1] = *ptr;
}
void do_LOAD_I32(
    CPU *cpu, const Instr *instr,
    [[maybe_unused]] const std::unordered_map<std::string, RegVal_t> *BB_PC) {
    instr->dump();
    cpu->dump();

    int *ptr = (int *)static_cast<intptr_t>(
        cpu->REG_FILE[instr->rs2] +
        ((int)cpu->REG_FILE[instr->rs3] + (int)instr->imm) * sizeof(int));
    cpu->REG_FILE[instr->rs1] = *ptr;
}
void do_BR(
    CPU *cpu, const Instr *instr,
    [[maybe_unused]] const std::unordered_map<std::string, RegVal_t> *BB_PC) {
    instr->dump();
    cpu->dump();

    cpu->NEXT_PC = BB_PC->at(instr->label1);
}

void *lazyFunctionCreator(const std::string &fnName) {
    // clang-format off
    const std::unordered_map<std::string, void *> functions = {
        {"do_FLUSH", reinterpret_cast<void *>(do_FLUSH)},
        {"do_UPDATE_GPU_BUFFER", reinterpret_cast<void *>(do_UPDATE_GPU_BUFFER)},
        {"do_ALLOCA_COORDS_AND_COLORS", reinterpret_cast<void *>(do_ALLOCA_COORDS_AND_COLORS)},
        {"do_ALLOCA", reinterpret_cast<void *>(do_ALLOCA)},
        {"do_SET_ZEROS", reinterpret_cast<void *>(do_SET_ZEROS)},
        {"do_MULI", reinterpret_cast<void *>(do_MULI)},
        {"do_ADDI", reinterpret_cast<void *>(do_ADDI)},
        {"do_INC_EQ", reinterpret_cast<void *>(do_INC_EQ)},
        {"do_XOR", reinterpret_cast<void *>(do_XOR)},
        {"do_MUL", reinterpret_cast<void *>(do_MUL)},
        {"do_ADD", reinterpret_cast<void *>(do_ADD)},
        {"do_GT", reinterpret_cast<void *>(do_GT)},
        {"do_SET_PIXEL", reinterpret_cast<void *>(do_SET_PIXEL)},
        {"do_EQ", reinterpret_cast<void *>(do_EQ)},
        {"do_DIV", reinterpret_cast<void *>(do_DIV)},
        {"do_OR", reinterpret_cast<void *>(do_OR)},
        {"do_STORE_I8", reinterpret_cast<void *>(do_STORE_I8)},
        {"do_STORE_I32", reinterpret_cast<void *>(do_STORE_I32)},
        {"do_LOAD_I8", reinterpret_cast<void *>(do_LOAD_I8)},
        {"do_LOAD_I32", reinterpret_cast<void *>(do_LOAD_I32)}};
    // clang-format on

    if (auto it = functions.find(fnName); it != functions.end()) {
        return it->second;
    }
    return nullptr;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        outs() << "[ERROR] Need 1 argument: file with assembler\n";
        return 0;
    }

    std::ifstream input;
    input.open(argv[1]);
    if (!input.is_open()) {
        outs() << "[ERROR] Can't open " << argv[1] << "\n";
        return 0;
    }

    std::unordered_map<std::string, RegVal_t> BB_PC;

    RegVal_t pc = 0;
    // clang-format off
    const std::unordered_map<
        std::string,
        std::tuple<std::vector<Fields>, InsnId_t,
                   std::function<void(
                       CPU *, const Instr *,
                       const std::unordered_map<std::string, RegVal_t> *)>>>
        commands = {
            {"FLUSH", 
                {{}, FLUSH, do_FLUSH}},
            {"UPDATE_GPU_BUFFER", 
                {{}, UPDATE_GPU_BUFFER, do_UPDATE_GPU_BUFFER}},
            {"RET", 
                {{}, RET, do_RET}},
            {"ALLOCA_COORDS_AND_COLORS", 
                {{Fields::RS1}, ALLOCA_COORDS_AND_COLORS, do_ALLOCA_COORDS_AND_COLORS}},
            {"ALLOCA", 
                {{Fields::RS1, Fields::IMM}, ALLOCA, do_ALLOCA}},
            {"SET_ZEROS",
                {{Fields::RS1, Fields::IMM}, SET_ZEROS, do_SET_ZEROS}},
            {"MULI", 
                {{Fields::RS1, Fields::RS2, Fields::IMM}, MULI, do_MULI}},
            {"ADDI", 
                {{Fields::RS1, Fields::RS2, Fields::IMM}, ADDI, do_ADDI}},
            {"INC_EQ",
                {{Fields::RS1, Fields::RS2, Fields::IMM}, INC_EQ, do_INC_EQ}},
            {"XOR", 
                {{Fields::RS1, Fields::RS2, Fields::RS3}, XOR, do_XOR}},
            {"MUL", 
                {{Fields::RS1, Fields::RS2, Fields::RS3}, MUL, do_MUL}},
            {"ADD", 
                {{Fields::RS1, Fields::RS2, Fields::RS3}, ADD, do_ADD}},
            {"GT", 
                {{Fields::RS1, Fields::RS2, Fields::RS3}, GT, do_GT}},
            {"SET_PIXEL",
                {{Fields::RS1, Fields::RS2, Fields::RS3}, SET_PIXEL, do_SET_PIXEL}},
            {"EQ", 
                {{Fields::RS1, Fields::RS2, Fields::RS3}, EQ, do_EQ}},
            {"DIV", 
                {{Fields::RS1, Fields::RS2, Fields::RS3}, DIV, do_DIV}},
            {"OR", 
                {{Fields::RS1, Fields::RS2, Fields::RS3}, OR, do_OR}},
            {"BR_COND",
                {{Fields::RS1, Fields::LABEL1, Fields::LABEL2}, BR_COND, do_BR_COND}},
            {"STORE_I8",
                {{Fields::RS1, Fields::RS2, Fields::RS3, Fields::IMM}, STORE_I8, do_STORE_I8}},
            {"STORE_I32",
                {{Fields::RS1, Fields::RS2, Fields::RS3, Fields::IMM}, STORE_I32, do_STORE_I32}},
            {"LOAD_I8",
                {{Fields::RS1, Fields::RS2, Fields::RS3, Fields::IMM}, LOAD_I8, do_LOAD_I8}},
            {"LOAD_I32",
                {{Fields::RS1, Fields::RS2, Fields::RS3, Fields::IMM}, LOAD_I32, do_LOAD_I32}},
            {"BR", 
                {{Fields::LABEL1}, BR, do_BR}}
    };
    // clang-format on

    std::vector<Instr> instructions;

    std::string name;

    while (input >> name) {
        if (auto it = commands.find(name); it != commands.end()) {
            Instr tmp{};
            tmp.name = name;
            tmp.ID = std::get<InsnId_t>(it->second);
            tmp.execute = std::get<std::function<void(
                CPU *, const Instr *,
                const std::unordered_map<std::string, RegVal_t> *)>>(
                it->second);
            for (auto &&curType : std::get<std::vector<Fields>>(it->second)) {
                std::string arg;
                input >> arg;
                switch (curType) {
                case Fields::RS1:
                    tmp.rs1 = stoi(arg.erase(0, 1));
                    break;
                case Fields::RS2:
                    tmp.rs2 = stoi(arg.erase(0, 1));
                    break;
                case Fields::RS3:
                    tmp.rs3 = stoi(arg.erase(0, 1));
                    break;
                case Fields::IMM:
                    tmp.imm = stoi(arg);
                    break;
                case Fields::LABEL1:
                    tmp.label1 = arg;
                    break;
                case Fields::LABEL2:
                    tmp.label2 = arg;
                    break;
                }
            }
            instructions.push_back(tmp);
            ++pc;
            name.clear();
            continue;
        }
        int len = name.length();
        BB_PC[name.erase(len - 1, 1)] = pc;
        name.clear();
    }
    input.close();

#if defined(ASM_RUN)
    CPU cpu;
    for (int i = 0; i < REG_FILE_SIZE; i++) {
        cpu.REG_FILE[i] = 0;
    }
    cpu.RUN = true;
    cpu.PC = 0;

    auto app = Graphic_core::App::getApp();
    app->initWindow("fox_asm", 800, 600);
    app->createProgram("../graphicApi/lib/shaders/common.vert",
                       "../graphicApi/lib/shaders/common.frag");
    app->createBuffers();

    // execution
    while (cpu.RUN) {
        cpu.NEXT_PC = cpu.PC + 1;
        instructions[cpu.PC].execute(&cpu, &instructions[cpu.PC], &BB_PC);
        cpu.PC = cpu.NEXT_PC;
    }

    while (!glfwWindowShouldClose(app->getWindow()))
        glfwPollEvents();
    app->destroy();

    // strategic deletes
    delete[](int *) cpu.REG_FILE[1];
    delete[](int *) cpu.REG_FILE[2];
    delete[](int *) cpu.REG_FILE[3];
#else

    CPU cpu;
    LLVMContext context;
    // ; ModuleID = 'main'
    // source_filename = "main"
    Module *module = new Module("main", context);
    IRBuilder<> builder(context);

    // declare void @main()
    FunctionType *funcType = FunctionType::get(builder.getVoidTy(), false);
    Function *mainFunc = Function::Create(funcType, Function::ExternalLinkage,
                                          "fakeMain", module);

    // main_entry:
    BasicBlock *main_entryBB =
        BasicBlock::Create(context, "entry_point", mainFunc);

    builder.SetInsertPoint(main_entryBB);

    // set const 
    std::vector<std::vector<int>> arr = {
        {425, 536, 13974511}, {151, 368, 3572079},  {440, 249, 1591737},
        {3, 363, 4020334},    {715, 400, 6731484},  {58, 444, 15049432},
        {512, 555, 13193426}, {311, 331, 2822364},  {37, 103, 2708939},
        {656, 347, 505435},   {133, 358, 7584055},  {470, 494, 2201812},
        {147, 36, 12949952},  {211, 396, 11288287}, {451, 494, 3202092},
        {789, 392, 10526177}, {171, 367, 6475432},  {797, 484, 11629877},
        {186, 228, 5563096},  {167, 351, 13589823}, {505, 250, 3208161},
        {353, 284, 10462034}, {196, 117, 13461283}, {194, 257, 15139700},
        {103, 276, 12291396}, {646, 144, 1097829},  {188, 217, 13558239},
        {673, 10, 11114889},  {660, 520, 1556342},  {624, 169, 2951914},
        {394, 43, 2414789},   {51, 14, 16103385},   {569, 373, 15724377},
        {425, 523, 16143020}, {211, 568, 14574142}, {787, 224, 755813},
        {712, 54, 1316433},   {651, 459, 1672796},  {525, 230, 15763870},
        {129, 527, 10295048}, {631, 220, 9377424},  {4, 416, 12654176},
        {601, 32, 6459850},   {252, 593, 5256075},  {54, 385, 14883775},
        {115, 78, 8514895},   {604, 434, 3404590},  {20, 183, 1018311},
        {7, 326, 12269577},   {73, 18, 6594307},    {0, 456, 10733656},
        {479, 244, 2849870},  {16, 40, 7429552},    {322, 445, 7354436},
        {429, 465, 12181642}, {633, 257, 5046100},  {39, 327, 8084592},
        {256, 530, 16435783}, {367, 29, 9214164},   {245, 552, 1027154},
        {232, 288, 14172151}, {93, 425, 10404819},  {530, 496, 2685554},
        {205, 545, 9891471},  {110, 427, 7628983},  {298, 346, 11452609},
        {633, 359, 3394207},  {609, 407, 3486714},  {398, 49, 15366155},
        {63, 527, 6160162},   {311, 96, 105981},    {727, 201, 9827702},
        {630, 316, 13555200}, {699, 169, 4481560},  {731, 347, 12098681},
        {100, 381, 12245631}, {770, 247, 13267674}, {529, 123, 11677846},
        {411, 211, 13468432}, {459, 342, 14129095}, {433, 181, 10508253},
        {704, 268, 7340572},  {683, 273, 6896895},  {705, 3, 11830786},
        {66, 490, 1521645},   {694, 326, 7597392},  {169, 359, 13177975},
        {135, 265, 4607890},  {92, 451, 5972511},   {720, 29, 5711389},
        {711, 582, 11496075}, {167, 469, 791786},   {44, 583, 2635077},
        {630, 46, 9946804},   {262, 160, 6162150},  {457, 574, 14793056},
        {415, 266, 13430405}, {16, 283, 7321896},   {5, 245, 3194004},
        {331, 137, 3298150}};
    std::vector<Constant *> init;
    auto *arrayType3ints = ArrayType::get(Type::getInt32Ty(context), 3);

    for (auto it = arr.begin(); it != arr.end(); ++it) {
        std::vector<Constant *> tmp = {
            ConstantInt::get(Type::getInt32Ty(context), (*it)[0], true),
            ConstantInt::get(Type::getInt32Ty(context), (*it)[1], true),
            ConstantInt::get(Type::getInt32Ty(context), (*it)[2], true)};
        init.push_back(ConstantArray::get(arrayType3ints, tmp));
    }

    auto *arrayType100by3ints = ArrayType::get(arrayType3ints, 100);
    GlobalVariable *garr_const =
        new GlobalVariable(*module, static_cast<Type *>(arrayType100by3ints),
                           true, GlobalValue::PrivateLinkage, 0, "arr");
    garr_const->setAlignment(Align(16));
    garr_const->setInitializer(ConstantArray::get(arrayType100by3ints, init));

    // Get pointer to CPU for function args
    Value *cpu_p = builder.getInt64((uint64_t)&cpu);
    Value *BB_p = builder.getInt64((uint64_t)&BB_PC);

    ArrayType *regFileType =
        ArrayType::get(builder.getInt64Ty(), REG_FILE_SIZE);
    module->getOrInsertGlobal("regFile", regFileType);
    GlobalVariable *regFile = module->getNamedGlobal("regFile");

    FunctionType *CalleeType = FunctionType::get(
        builder.getVoidTy(),
        std::vector<Type *>({builder.getInt8PtrTy(), builder.getInt8PtrTy(),
                             builder.getInt8PtrTy()}),
        false);

    std::unordered_map<RegVal_t, BasicBlock *> BBMap;

    for (auto &name : BB_PC) {
        if (name.first != "entry_point")
            BBMap[name.second] =
                BasicBlock::Create(context, name.first, mainFunc);
    }

    for (RegVal_t PC = 0; PC < instructions.size(); PC++) {

        if (BBMap.find(PC) != BBMap.end()) {
            builder.SetInsertPoint(BBMap[PC]);
        }

        switch (instructions[PC].ID) {
        case FLUSH:
        case UPDATE_GPU_BUFFER:
        case SET_PIXEL: {
            Value *instr_p = builder.getInt64((uint64_t) & (instructions[PC]));
            builder.CreateCall(module->getOrInsertFunction(
                                   "do_" + instructions[PC].name, CalleeType),
                               std::vector<Value *>({cpu_p, instr_p, BB_p}));
            break;
        }
        case ALLOCA_COORDS_AND_COLORS: {
            Value *res = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                    instructions[PC].rs1);
            Value *imm = builder.getInt64(1200);
            Type *ArrayTy =
                ArrayType::get(builder.getInt8Ty(),
                               static_cast<ConstantInt *>(imm)->getZExtValue());
            Value *alloc = builder.CreateAlloca(ArrayTy);
            builder.CreateStore(alloc, res);

            auto *arg1 = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                     instructions[PC].rs1);
            auto *argAddr = builder.CreateLoad(Type::getInt8PtrTy(context), arg1);
            std::vector<Type *> memcpyParTypes = {
                Type::getInt8PtrTy(context), Type::getInt8PtrTy(context),
                Type::getInt64Ty(context), Type::getInt1Ty(context)};
            std::vector<Value *> valuesFormemcpy1 = {
                argAddr, builder.CreateBitCast(garr_const, Type::getInt8PtrTy(context)),
                builder.getInt64(1200), builder.getInt1(false)};
            auto setMemcpyAttr = [](auto *memcpy) {
                memcpy->addParamAttr(0, Attribute::NoUndef);
                memcpy->addParamAttr(0, Attribute::NonNull);

                memcpy->addParamAttr(1, Attribute::NoUndef);
                memcpy->addParamAttr(1, Attribute::NonNull);
            };

            auto *memcpy1 = builder.CreateIntrinsic(Intrinsic::memcpy, memcpyParTypes,
                                                    valuesFormemcpy1);
            setMemcpyAttr(memcpy1);
            break;
        }
        case SET_ZEROS: {
            std::vector<Type *> memsetParTypes = {
                Type::getInt8PtrTy(context), Type::getInt8Ty(context),
                Type::getInt64Ty(context), Type::getInt1Ty(context)};
            auto setMemsetAttr = [](auto *memset) {
                memset->addParamAttr(0, Attribute::NoUndef);
                memset->addParamAttr(0, Attribute::NonNull);
            };
            auto *arg1 = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                     instructions[PC].rs1);
            auto *argAddr = builder.CreateLoad(Type::getInt8PtrTy(context), arg1);

            std::vector<Value *> valuesFormemset1 = {argAddr, builder.getInt8(0),
                                                    builder.getInt64(int64_t(instructions[PC].imm)),
                                                    builder.getInt1(false)};

            auto *memset1 = builder.CreateIntrinsic(Intrinsic::memset, memsetParTypes,
                                                    valuesFormemset1);
            setMemsetAttr(memset1);
            break;
        }
        case RET: {
            builder.CreateRetVoid();
            break;
        }
        case ALLOCA: {
            Value *res = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                    instructions[PC].rs1);
            Value *imm = builder.getInt64(instructions[PC].imm);
            Type *ArrayTy =
                ArrayType::get(builder.getInt8Ty(),
                               static_cast<ConstantInt *>(imm)->getZExtValue());
            Value *alloc = builder.CreateAlloca(ArrayTy);
            builder.CreateStore(alloc, res);
            break;
        }
        case MULI: {
            Value *res = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                    instructions[PC].rs1);
            Value *arg1 = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                     instructions[PC].rs2);
            Value *arg2 = builder.getInt64(instructions[PC].imm);
            Value *res_bin_instr = builder.CreateMul(
                builder.CreateLoad(builder.getInt64Ty(), arg1), arg2);
            builder.CreateStore(res_bin_instr, res);
            break;
        }
        case ADDI: {
            Value *res = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                    instructions[PC].rs1);
            Value *arg1 = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                     instructions[PC].rs2);
            Value *arg2 = builder.getInt64(instructions[PC].imm);
            Value *res_bin_instr = builder.CreateAdd(
                builder.CreateLoad(builder.getInt64Ty(), arg1), arg2);
            builder.CreateStore(res_bin_instr, res);
            break;
        }
        case INC_EQ: {
            Value *res = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                    instructions[PC].rs1);
            Value *arg1 = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                     instructions[PC].rs2);
            Value *arg2 = builder.getInt32(instructions[PC].imm);
            Value *incremented_val = builder.CreateAdd(
                builder.CreateLoad(builder.getInt64Ty(), arg1),
                builder.getInt64(1));
            Value *icmp_eq = builder.CreateICmpEQ(incremented_val, arg2);
            builder.CreateStore(incremented_val, arg1);
            builder.CreateStore(
                builder.CreateZExt(icmp_eq, builder.getInt64Ty()), res);
            break;
        }
        case XOR: {
            Value *res = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                    instructions[PC].rs1);
            Value *arg1 = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                     instructions[PC].rs2);
            Value *arg2 = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                     instructions[PC].rs3);
            Value *res_bin_instr = builder.CreateXor(
                builder.CreateLoad(builder.getInt64Ty(), arg1),
                builder.CreateLoad(builder.getInt64Ty(), arg2));
            builder.CreateStore(res_bin_instr, res);
            break;
        }
        case MUL: {
            Value *res = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                    instructions[PC].rs1);
            Value *arg1 = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                     instructions[PC].rs2);
            Value *arg2 = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                     instructions[PC].rs3);
            Value *res_bin_instr = builder.CreateMul(
                builder.CreateLoad(builder.getInt64Ty(), arg1),
                builder.CreateLoad(builder.getInt64Ty(), arg2));
            builder.CreateStore(res_bin_instr, res);
            break;
        }
        case ADD: {
            Value *res = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                    instructions[PC].rs1);
            Value *arg1 = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                     instructions[PC].rs2);
            Value *arg2 = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                     instructions[PC].rs3);
            Value *res_bin_instr = builder.CreateAdd(
                builder.CreateLoad(builder.getInt64Ty(), arg1),
                builder.CreateLoad(builder.getInt64Ty(), arg2));
            builder.CreateStore(res_bin_instr, res);
            break;
        }
        case GT: {
            Value *res = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                    instructions[PC].rs1);
            Value *arg1 = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                     instructions[PC].rs2);
            Value *arg2 = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                     instructions[PC].rs3);
            Value *res_bin_instr = builder.CreateICmpUGT(
                builder.CreateLoad(builder.getInt64Ty(), arg1),
                builder.CreateLoad(builder.getInt64Ty(), arg2));
            builder.CreateStore(res_bin_instr, res);
            break;
        }
        case EQ: {
            Value *res = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                    instructions[PC].rs1);
            Value *arg1 = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                     instructions[PC].rs2);
            Value *arg2 = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                     instructions[PC].rs3);
            Value *res_bin_instr = builder.CreateICmpEQ(
                builder.CreateLoad(builder.getInt64Ty(), arg1),
                builder.CreateLoad(builder.getInt64Ty(), arg2));
            builder.CreateStore(res_bin_instr, res);
            break;
        }
        case DIV: {
            Value *res = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                    instructions[PC].rs1);
            Value *arg1 = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                     instructions[PC].rs2);
            Value *arg2 = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                     instructions[PC].rs3);
            Value *res_bin_instr = builder.CreateSDiv(
                builder.CreateLoad(builder.getInt64Ty(), arg1),
                builder.CreateLoad(builder.getInt64Ty(), arg2));
            builder.CreateStore(res_bin_instr, res);
            break;
        }
        case OR: {
            Value *res = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                    instructions[PC].rs1);
            Value *arg1 = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                     instructions[PC].rs2);
            Value *arg2 = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                     instructions[PC].rs3);
            Value *res_bin_instr = builder.CreateOr(
                builder.CreateLoad(builder.getInt64Ty(), arg1),
                builder.CreateLoad(builder.getInt64Ty(), arg2));
            builder.CreateStore(res_bin_instr, res);
            break;
        }
        case BR_COND: {
            Value *arg = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                    instructions[PC].rs1);
            Value *cond = builder.CreateLoad(builder.getInt64Ty(), arg);
            builder.CreateCondBr(cond, BBMap[BB_PC[instructions[PC].label1]],
                                 BBMap[BB_PC[instructions[PC].label2]]);
            break;
        }
        case STORE_I8: {
            Value *res = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                    instructions[PC].rs1);
            Value *arg1 = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                     instructions[PC].rs2);
            Value *arg2 = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                     instructions[PC].rs3);
            Value *imm = builder.getInt64(instructions[PC].imm);
            Value *idx = builder.CreateAdd(
                builder.CreateLoad(builder.getInt64Ty(), arg2), imm);
            Value *gep = builder.CreateInBoundsGEP(
                builder.getInt8Ty(),
                builder.CreateLoad(Type::getInt8PtrTy(context), arg1), idx);
            builder.CreateStore(builder.CreateLoad(builder.getInt8Ty(), res),
                                gep);
            break;
        }
        case STORE_I32: {
            Value *res = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                    instructions[PC].rs1);
            Value *arg1 = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                     instructions[PC].rs2);
            Value *arg2 = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                     instructions[PC].rs3);
            Value *imm = builder.getInt64(instructions[PC].imm);
            Value *idx = builder.CreateAdd(
                builder.CreateLoad(builder.getInt64Ty(), arg2), imm);
            Value *gep = builder.CreateInBoundsGEP(
                builder.getInt32Ty(),
                builder.CreateLoad(Type::getInt32PtrTy(context), arg1), idx);
            builder.CreateStore(builder.CreateLoad(builder.getInt32Ty(), res),
                                gep);
            break;
        }
        case LOAD_I8: {
            Value *res = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                    instructions[PC].rs1);
            Value *arg1 = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                     instructions[PC].rs2);
            Value *arg2 = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                     instructions[PC].rs3);
            Value *imm = builder.getInt64(instructions[PC].imm);
            Value *idx = builder.CreateAdd(
                builder.CreateLoad(builder.getInt64Ty(), arg2), imm);
            Value *gep = builder.CreateInBoundsGEP(
                builder.getInt8Ty(),
                builder.CreateLoad(Type::getInt8PtrTy(context), arg1), idx);
            builder.CreateStore(
                builder.CreateZExt(builder.CreateLoad(builder.getInt8Ty(), gep),
                                   builder.getInt64Ty()),
                res);
            break;
        }
        case LOAD_I32: {
            Value *res = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                    instructions[PC].rs1);
            Value *arg1 = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                     instructions[PC].rs2);
            Value *arg2 = builder.CreateConstGEP2_64(regFileType, regFile, 0,
                                                     instructions[PC].rs3);
            Value *imm = builder.getInt64(instructions[PC].imm);
            Value *idx = builder.CreateAdd(
                builder.CreateLoad(builder.getInt64Ty(), arg2), imm);
            Value *gep = builder.CreateInBoundsGEP(
                builder.getInt32Ty(),
                builder.CreateLoad(Type::getInt32PtrTy(context), arg1), idx);
            builder.CreateStore(builder.CreateLoad(builder.getInt32Ty(), gep),
                                res);
            break;
        }
        case BR: {
            builder.CreateBr(BBMap[BB_PC[instructions[PC].label1]]);
            break;
        }
        default:
            outs() << "unexpected\n";
        }
    }

    // verifyModule(*module, &outs());
    // module->print(outs(), nullptr);

    for (int i = 0; i < REG_FILE_SIZE; i++) {
        cpu.REG_FILE[i] = 0;
    }

    InitializeNativeTarget();
    InitializeNativeTargetAsmPrinter();

    ExecutionEngine *ee =
        EngineBuilder(std::unique_ptr<Module>(module)).create();
    ee->InstallLazyFunctionCreator(lazyFunctionCreator);
    ee->addGlobalMapping(regFile, (void *)cpu.REG_FILE);
    ee->finalizeObject();
    ArrayRef<GenericValue> noargs;

    auto app = Graphic_core::App::getApp();
    app->initWindow("fox_asm_to_IR", 800, 600);
    app->createProgram("../graphicApi/lib/shaders/common.vert",
                       "../graphicApi/lib/shaders/common.frag");
    app->createBuffers();

    // execution
    ee->runFunction(mainFunc, noargs);

    while (!glfwWindowShouldClose(app->getWindow()))
        glfwPollEvents();
    app->destroy();

#endif
    return 0;
}