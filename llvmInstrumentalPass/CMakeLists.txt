# builds only for clang compiler
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    find_package(LLVM CONFIG)
    message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")

    message(STATUS "LLVM libraries: ${LLVM_LIBRARIES}")
    message(STATUS "LLVM includes: ${LLVM_INCLUDE_DIRS}")
    message(STATUS "LLVM definitions: ${LLVM_DEFINITIONS}")
    message(STATUS "LLVM tools: ${LLVM_TOOLS_BINARY_DIR}")

    # Link against LLVM
    if (LLVM_FOUND)
        set(MY_PASS_LIB MyInstrumentalPass)
        add_library(${MY_PASS_LIB} SHARED cfg_pass.cpp)
        target_include_directories(${MY_PASS_LIB} PRIVATE ${LLVM_INCLUDE_DIRS})
        target_link_libraries(${MY_PASS_LIB} PRIVATE LLVM)

        # unnesessary python for show graphic representation
        find_package(Python3)
        if (Python3_FOUND)
            execute_process(
                COMMAND pip show matplotlib
                RESULT_VARIABLE EXIT_CODE
                OUTPUT_QUIET
            )

            if (${EXIT_CODE} EQUAL 0)
                add_custom_target(show_instr
                    COMMENT "Show graphic representation of instrumentation"
                    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
                    DEPENDS generated_instr install_requirements
                    COMMAND ${Python3_EXECUTABLE} ${PROJECT_SOURCE_DIR}/llvmInstrumentalPass/instrDump.py ${CMAKE_BINARY_DIR}/dump.txt
                )
            else()
                add_custom_target(show_instr
                    COMMENT "You cannot run this target because of you don\'t have matplotlib"
                    COMMAND pip show matplotlib
                )
            endif()
        endif()
    endif()
endif()