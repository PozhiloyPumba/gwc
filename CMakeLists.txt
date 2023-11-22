cmake_minimum_required (VERSION 3.10)

project (GWC VERSION 1.0 LANGUAGES CXX C)

# clang-format
find_program(CLANG_FORMAT "clang-format")
if(CLANG_FORMAT)
    set(DIRECTORIES cppSample graphicApi llvmInstrumentalPass IR_gen isa)
    set(ALL_CXX_SOURCE_FILES )

    foreach(DIR IN LISTS DIRECTORIES)
        file(GLOB_RECURSE ALL_CXX_SOURCE_FILES_IN_DIR
            ${PROJECT_SOURCE_DIR}/${DIR}/*.[ch]pp
            ${PROJECT_SOURCE_DIR}/${DIR}/*.[ch]
        )
        list(APPEND ALL_CXX_SOURCE_FILES ${ALL_CXX_SOURCE_FILES_IN_DIR})
    endforeach()

    add_custom_target(
        format
        COMMAND clang-format
        -i
        -style=file
        ${ALL_CXX_SOURCE_FILES}
    )
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT WIN32)
    set(WIN32 0)
endif()
# compiler options build everywhere cpp sample but other functions clang only because of using llvm
if(MSVC)
    add_compile_options("/W3" "$<$<CONFIG:RELEASE>:/O2>")
else()
    add_compile_options("-Wall" "-Wextra" "$<$<CONFIG:RELEASE>:-O2>")
endif()

include(./cmake/declare_system_library.cmake)

find_package(LLVM CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")

message(STATUS "LLVM libraries: ${LLVM_LIBRARIES}")
message(STATUS "LLVM includes: ${LLVM_INCLUDE_DIRS}")
message(STATUS "LLVM definitions: ${LLVM_DEFINITIONS}")
message(STATUS "LLVM tools: ${LLVM_TOOLS_BINARY_DIR}")
llvm_map_components_to_libnames(llvm_libs support core irreader)

add_subdirectory(thirdParty)

# builds only for clang compiler and if llvm found
if ((CMAKE_CXX_COMPILER_ID STREQUAL "Clang") AND (LLVM_FOUND))
    add_subdirectory(llvmInstrumentalPass)
    add_subdirectory(IR_gen)
    add_subdirectory(isa)
endif()

add_subdirectory(graphicApi)
add_subdirectory(cppSample)
