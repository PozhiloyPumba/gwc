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