cmake_minimum_required(VERSION 3.10)
project(SmartSockets)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.cpp")

file(GLOB_RECURSE HEADERS "include/*.h")

add_library(smartSockets SHARED ${SOURCES})

add_executable(test_app tests/test_main.cpp)

target_link_libraries(test_app smartSockets)

add_custom_target(clean_build
    COMMAND rm -rf CMakeFiles CMakeCache.txt Makefile *.so *.a *.o *.obj
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target clean
    COMMAND ${CMAKE_COMMAND} ..
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Clean and rebuild."
)
