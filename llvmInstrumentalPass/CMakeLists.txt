project (MyInstrumentalPass VERSION 1.0 LANGUAGES CXX)

find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")

message(STATUS "LLVM libraries: ${LLVM_LIBRARIES}")
message(STATUS "LLVM includes: ${LLVM_INCLUDE_DIRS}")
message(STATUS "LLVM definitions: ${LLVM_DEFINITIONS}")
message(STATUS "LLVM tools: ${LLVM_TOOLS_BINARY_DIR}")

# Link against LLVM
add_library(${PROJECT_NAME} SHARED cfg_pass.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${LLVM_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE LLVM)