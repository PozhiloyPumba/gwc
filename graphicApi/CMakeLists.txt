project(SIMPLE_GRAPHIC_API VERSION 1.0)

set(GRAPHIC_API_LIB "simple_graphic_api")

set(SOURCE_LIST
    graphic.cpp
)

set(HEADER_LIST
    graphic.hpp
)

add_library(${GRAPHIC_API_LIB} STATIC ${SOURCE_LIST} ${HEADER_LIST})

target_include_directories(${GRAPHIC_API_LIB} PUBLIC ../include)

target_include_directories(${GRAPHIC_API_LIB} PUBLIC ${std_image_SOURCE_DIR})

target_link_libraries(${GRAPHIC_API_LIB} PUBLIC glad)
target_link_libraries(${GRAPHIC_API_LIB} PUBLIC glfw)
target_link_libraries(${GRAPHIC_API_LIB} PUBLIC glm)