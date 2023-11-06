add_subdirectory(glfw)
add_subdirectory(glad)
target_compile_options(glfw PRIVATE -w)
target_compile_options(glad PRIVATE -w)