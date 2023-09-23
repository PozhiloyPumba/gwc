project(GLAD VERSION 1.0)

set(LIB_NAME "glad")

file(GLOB_RECURSE HEADER_LIST
    ./include/glad/glad.h
	./include/KHR/khrplatform.h
)

file(GLOB_RECURSE SOURCE_LIST
    src/glad.c
)

add_library(${LIB_NAME} ${SOURCE_LIST} ${HEADER_LIST})
target_include_directories(${LIB_NAME} PUBLIC include)