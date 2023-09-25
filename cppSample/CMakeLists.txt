set(EXEC sanek)

set(SOURCE_LIST
    main.cpp
)

set(HEADER_LIST
    calculate.hpp
)

add_executable(${EXEC} ${SOURCE_LIST} ${HEADER_LIST})

target_include_directories(${EXEC} PUBLIC ${SIMPLE_GRAPHIC_API_SOURCE_DIR})
target_link_libraries(${EXEC} PUBLIC simple_graphic_api)

add_custom_target(run 
    DEPENDS ${EXEC}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${EXEC}
)