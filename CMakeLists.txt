cmake_minimum_required(VERSION 3.25)

project(Yoth LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

include(cmake/clang_format.cmake)

add_clang_format_target(format "build")

add_executable(test ${PROJECT_SOURCE_DIR}/test/test.cpp)

target_include_directories(test PUBLIC
  ${PROJECT_SOURCE_DIR}/yoth
)