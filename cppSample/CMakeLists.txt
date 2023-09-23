set(EXEC sanek)

set(SOURCE_LIST
    main.cpp
)

set(HEADER_LIST
)

add_executable(${EXEC} ${SOURCE_LIST} ${HEADER_LIST})

target_include_directories(${EXEC} PRIVATE ${SIMPLE_GRAPHIC_API_SOURCE_DIR})
target_link_libraries(${EXEC} PRIVATE simple_graphic_api)