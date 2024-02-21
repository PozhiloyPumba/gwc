find_package(FLEX)
find_package(BISON)

if (FLEX_FOUND AND BISON_FOUND)
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/generated)

    flex_target(lexer 
        lexer/lexer.ll
        ${CMAKE_CURRENT_BINARY_DIR}/generated/lexer.cpp
    )

    bison_target(parser 
        parser/parser.yy
        ${CMAKE_CURRENT_BINARY_DIR}/generated/parcer.cpp
        COMPILE_FLAGS "--defines=${CMAKE_CURRENT_BINARY_DIR}/generated/grammar.tab.hh"
    )

    add_flex_bison_dependency(lexer parser)

    set(SOURCES
        driver/driver.hpp
        driver/driver.cpp
        lexer/lexer.hpp
    )

    message(${BISON_parser_OUTPUTS})
    add_library(frontend STATIC
        ${SOURCES}
        ${BISON_parser_OUTPUTS}
        ${FLEX_lexer_OUTPUTS}
    )

    target_include_directories(frontend PUBLIC lexer parser driver ${CMAKE_CURRENT_BINARY_DIR}/generated)

    # set(ASM_RUNNER asm_runner)
    # add_executable(${ASM_RUNNER} main.cpp)
    # target_compile_definitions(${ASM_RUNNER} PRIVATE ASM_RUN)
    # target_include_directories(${ASM_RUNNER} SYSTEM PRIVATE ${LLVM_INCLUDE_DIRS})
    # target_link_libraries(${ASM_RUNNER} PRIVATE LLVM)
    # target_link_libraries(${ASM_RUNNER} PRIVATE simple_graphic_api)

    # set_target_properties(${ASM_RUNNER} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/$<0:>)

    # add_custom_target(run_asm
    #     WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    #     COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${ASM_RUNNER}$<IF:${WIN32},.exe,> ../asm_IR/main.asm
    # )
    # add_dependencies(run_asm ${ASM_RUNNER})
endif()