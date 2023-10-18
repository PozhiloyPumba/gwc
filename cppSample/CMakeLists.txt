set(EXEC sanek)

set(SOURCE_LIST
    main.cpp
    fakeMain.cpp
)

set(HEADER_LIST
)

add_executable(${EXEC} ${SOURCE_LIST} ${HEADER_LIST})

target_include_directories(${EXEC} PUBLIC ${SIMPLE_GRAPHIC_API_SOURCE_DIR})
target_link_libraries(${EXEC} PUBLIC simple_graphic_api)
target_link_libraries(${EXEC} PUBLIC simple_graphic_core)

add_custom_target(run 
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${EXEC}
)

add_dependencies(run ${EXEC})

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_custom_target(generate_LLVM_IR 
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMAND ${CMAKE_CXX_COMPILER} -S -emit-llvm fakeMain.cpp 
                -I${PROJECT_SOURCE_DIR}/graphicApi -O2 
                -o ${CMAKE_CURRENT_SOURCE_DIR}/llvm_file/fakeMain.ll
    )
endif()