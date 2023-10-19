set(EXEC sanek)
set(FAKE_LIB fake_lib)

add_library(${FAKE_LIB} STATIC fakeMain.cpp)

add_dependencies(${FAKE_LIB} MyInstrumentalPass)
target_compile_options(${FAKE_LIB} PRIVATE -O2
                        "SHELL:-Xclang -load" 
                        "SHELL:-Xclang ${CMAKE_BINARY_DIR}/llvmInstrumentalPass/libMyInstrumentalPass.so" -flegacy-pass-manager)

target_include_directories(${FAKE_LIB} PUBLIC ${SIMPLE_GRAPHIC_API_SOURCE_DIR})
target_link_libraries(${FAKE_LIB} PUBLIC simple_graphic_api)
target_link_libraries(${FAKE_LIB} PUBLIC simple_graphic_core)

set(SOURCE_LIST
    ${PROJECT_SOURCE_DIR}/llvmInstrumentalPass/log.cpp
    main.cpp
)

set(HEADER_LIST
)

add_executable(${EXEC} ${SOURCE_LIST} ${HEADER_LIST})

target_include_directories(${EXEC} PUBLIC ${SIMPLE_GRAPHIC_API_SOURCE_DIR})
target_link_libraries(${EXEC} PUBLIC ${FAKE_LIB})
target_link_libraries(${EXEC} PUBLIC simple_graphic_api)
target_link_libraries(${EXEC} PUBLIC simple_graphic_core)

add_custom_target(run 
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${EXEC}
)

add_dependencies(run ${EXEC})

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_custom_target(generate_LLVM_IR 
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_CXX_COMPILER} -S -emit-llvm ${CMAKE_CURRENT_SOURCE_DIR}/fakeMain.cpp 
                -I${PROJECT_SOURCE_DIR}/graphicApi -O2 
                -o ${CMAKE_CURRENT_SOURCE_DIR}/llvm_file/fakeMain.ll
    )
endif()