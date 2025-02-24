cmake_minimum_required(VERSION 3.25)

project(Yoth LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

include(cmake/clang_format.cmake)
include(cmake/libraries.cmake)

if (CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
  FetchContent_MakeAvailable(googletest)
  
  add_subdirectory(tests)
  
  add_clang_format_target(format "build")
endif()

set(YOTH_SOURCES
  ${PROJECT_SOURCE_DIR}/yoth/geometry/transform.cpp
  ${PROJECT_SOURCE_DIR}/yoth/geometry/bounding_box.cpp
  ${PROJECT_SOURCE_DIR}/yoth/geometry/shapes.cpp
)

add_library(${PROJECT_NAME} STATIC ${YOTH_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
  ${PROJECT_SOURCE_DIR}/yoth
)

