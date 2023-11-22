set(ASM_RUNNER asm_runner)
add_executable(${ASM_RUNNER} main.cpp)
target_compile_definitions(${ASM_RUNNER} PRIVATE ASM_RUN)
target_include_directories(${ASM_RUNNER} SYSTEM PRIVATE ${LLVM_INCLUDE_DIRS})
target_link_libraries(${ASM_RUNNER} PRIVATE LLVM)
target_link_libraries(${ASM_RUNNER} PRIVATE simple_graphic_api)

set_target_properties(${ASM_RUNNER} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/$<0:>)

add_custom_target(run_asm
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${ASM_RUNNER}$<IF:${WIN32},.exe,> ../asm_IR/main.asm
)
add_dependencies(run_asm ${ASM_RUNNER})

set(ASM_TO_IR_RUNNER asm_to_IR_runner)
add_executable(${ASM_TO_IR_RUNNER} main.cpp)
target_include_directories(${ASM_TO_IR_RUNNER} SYSTEM PRIVATE ${LLVM_INCLUDE_DIRS})
target_link_libraries(${ASM_TO_IR_RUNNER} PRIVATE LLVM)
target_link_libraries(${ASM_TO_IR_RUNNER} PRIVATE simple_graphic_api)

set_target_properties(${ASM_TO_IR_RUNNER} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/$<0:>)

add_custom_target(run_asm_to_IR
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${ASM_TO_IR_RUNNER}$<IF:${WIN32},.exe,> ../asm_IR/main.asm
)
add_dependencies(run_asm_to_IR ${ASM_TO_IR_RUNNER})