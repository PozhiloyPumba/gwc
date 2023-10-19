project(SIMPLE_GRAPHIC_API VERSION 1.0)

set(GRAPHIC_API_LIB "simple_graphic_api")

add_subdirectory(lib)

set(SOURCE_LIST
    graphic.cpp
)

set(HEADER_LIST
    graphic.hpp
)

add_library(${GRAPHIC_API_LIB} STATIC ${SOURCE_LIST} ${HEADER_LIST})
target_include_directories(${GRAPHIC_API_LIB} PUBLIC .)
target_link_libraries(${GRAPHIC_API_LIB} PUBLIC simple_graphic_core)