set(IR_GENERATOR IR_generator)
add_executable(${IR_GENERATOR} IR_generator.cpp generators.cpp generators.hpp)
target_include_directories(${IR_GENERATOR} SYSTEM PRIVATE ${LLVM_INCLUDE_DIRS})
target_link_libraries(${IR_GENERATOR} PRIVATE LLVM)

set_target_properties(${IR_GENERATOR} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/$<0:>)

add_custom_target(run_simulator
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${IR_GENERATOR}$<IF:${WIN32},.exe,> > ir.ll
)
add_dependencies(run_simulator ${IR_GENERATOR})