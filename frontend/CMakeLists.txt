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
        COMPILE_FLAGS "--defines=${CMAKE_CURRENT_BINARY_DIR}/generated/grammar.tab.hh -Wcounterexamples"
    )

    add_flex_bison_dependency(lexer parser)

    set(SOURCES
        driver/driver.hpp
        lexer/lexer.hpp
        tree/AST.hpp
    )

    add_library(frontend STATIC
        ${SOURCES}
        ${BISON_parser_OUTPUTS}
        ${FLEX_lexer_OUTPUTS}
    )

    target_include_directories(frontend PUBLIC lexer tree parser driver ${CMAKE_CURRENT_BINARY_DIR}/generated)

    set(LANG_FRONTEND lang)
    add_executable(${LANG_FRONTEND} driver/main.cpp)
    target_link_libraries(${LANG_FRONTEND} PRIVATE frontend)

    set_target_properties(${LANG_FRONTEND} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/$<0:>)

    add_custom_target(run_front
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${LANG_FRONTEND}$<IF:${WIN32},.exe,> ../frontend/fakemain.gwc
    )
    add_dependencies(run_front ${LANG_FRONTEND})
    
    add_custom_target(run_front_dump
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${LANG_FRONTEND}$<IF:${WIN32},.exe,> ../frontend/fakemain.gwc > test.dot && dot -Tx11 test.dot
    )
    add_dependencies(run_front_dump ${LANG_FRONTEND})
endif()
