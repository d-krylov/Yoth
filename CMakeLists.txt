cmake_minimum_required(VERSION 3.25)

project(Yoth LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

include(cmake/clang_format.cmake)
include(cmake/libraries.cmake)

if (CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
  FetchContent_MakeAvailable(googletest)
  
  add_subdirectory(tests)
  
  add_clang_format_target(format "build")
endif()

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE
  ${PROJECT_SOURCE_DIR}/yoth
)

