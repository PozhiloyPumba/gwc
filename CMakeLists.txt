cmake_minimum_required (VERSION 3.10)

project (GWC VERSION 1.0 LANGUAGES CXX)

# clang-format
find_program(CLANG_FORMAT "clang-format")
if(CLANG_FORMAT)
    set(DIRECTORIES cppSample graphicApi)
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

# compiler options build everywhere cpp sample but other functions clang only because of using llvm
if(MSVC)
    add_compile_options("/W3" "$<$<CONFIG:RELEASE>:/O2>")
else()
    add_compile_options("-Wall" "-Wextra" "$<$<CONFIG:RELEASE>:-O2>")
endif()

add_subdirectory(thirdParty)
add_subdirectory(graphicApi)
add_subdirectory(cppSample)

#add_subdirectory(sources)
