project(SIMPLE_GRAPHIC_CORE VERSION 1.0)

set(GRAPHIC_API_CORE_LIB "simple_graphic_core")

set(SOURCE_LIST
    sources/app.cpp
    sources/shader.cpp
)

set(HEADER_LIST
    include/app.hpp
    include/shader.hpp
)

add_library(${GRAPHIC_API_CORE_LIB} STATIC ${SOURCE_LIST} ${HEADER_LIST})

target_include_directories(${GRAPHIC_API_CORE_LIB} PUBLIC include)

target_link_libraries(${GRAPHIC_API_CORE_LIB} PUBLIC glad)
target_link_libraries(${GRAPHIC_API_CORE_LIB} PUBLIC glfw)
target_link_libraries(${GRAPHIC_API_CORE_LIB} PUBLIC glm)