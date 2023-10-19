set(FAKE_LIB fake_lib)
add_library(${FAKE_LIB} STATIC fakeMain.cpp)

# builds only for clang compiler
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(FAKE_LIB_INSTR fake_lib_instr)
    add_library(${FAKE_LIB_INSTR} STATIC fakeMain.cpp 
                ${PROJECT_SOURCE_DIR}/llvmInstrumentalPass/log.cpp)

    add_dependencies(${FAKE_LIB_INSTR} MyInstrumentalPass)
    target_compile_options(${FAKE_LIB_INSTR} PRIVATE -O2
                            "SHELL:-Xclang -load" 
                            "SHELL:-Xclang ${CMAKE_BINARY_DIR}/llvmInstrumentalPass/libMyInstrumentalPass.so"
                            -flegacy-pass-manager
    )
endif()

set(FAKE_LIBS ${FAKE_LIB} ${FAKE_LIB_INSTR})

foreach(LIB IN LISTS FAKE_LIBS)
    target_link_libraries(${LIB} PUBLIC simple_graphic_api)
endforeach()

set(SOURCE_LIST
    main.cpp
)

set(HEADER_LIST
)

set(EXEC sanek)

add_executable(${EXEC} ${SOURCE_LIST} ${HEADER_LIST})

target_link_libraries(${EXEC} PUBLIC ${FAKE_LIB})
target_link_libraries(${EXEC} PUBLIC simple_graphic_api)

add_custom_target(run 
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${EXEC}
)

add_dependencies(run ${EXEC})

# targets only for clang compiler
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(EXEC_INSTR sanek_instr)
    add_executable(${EXEC_INSTR} ${SOURCE_LIST} ${HEADER_LIST})

    target_compile_definitions(${EXEC_INSTR} PRIVATE INSTRUMENTAL_PASS)
    target_link_libraries(${EXEC_INSTR} PUBLIC ${FAKE_LIB_INSTR})
    target_link_libraries(${EXEC_INSTR} PUBLIC simple_graphic_api)

    add_custom_target(run_instr
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${EXEC_INSTR} > ${CMAKE_BINARY_DIR}/dump.txt
    )
    add_dependencies(run_instr ${EXEC_INSTR})

    add_custom_command(
        OUTPUT "${CMAKE_BINARY_DIR}/dump.txt"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${EXEC_INSTR} > ${CMAKE_BINARY_DIR}/dump.txt
    )
    add_custom_target(
        generated_instr ALL
        DEPENDS ${CMAKE_BINARY_DIR}/dump.txt
    )
    add_dependencies(generated_instr ${EXEC_INSTR})

    add_custom_target(generate_LLVM_IR 
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_CXX_COMPILER} -S -emit-llvm ${CMAKE_CURRENT_SOURCE_DIR}/fakeMain.cpp 
                -I${PROJECT_SOURCE_DIR}/graphicApi -O2 
                -o ${CMAKE_CURRENT_SOURCE_DIR}/llvm_file/fakeMain.ll
    )
endif()