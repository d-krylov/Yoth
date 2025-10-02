cmake_minimum_required(VERSION 3.25)

project(Yoth LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

include(cmake/clang_format.cmake)
include(cmake/libraries.cmake)

if (${PROJECT_IS_TOP_LEVEL})
  FetchContent_MakeAvailable(googletest)
  
  add_subdirectory(tests)
  
  add_clang_format_target(format "build")
endif()

set(CMAKE_BUILD_TYPE Release)

set(YOTH_SOURCES
  ${PROJECT_SOURCE_DIR}/yoth/common/yoth.cpp
  ${PROJECT_SOURCE_DIR}/yoth/core/core.cpp
)

add_library(${PROJECT_NAME} STATIC ${YOTH_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
  ${PROJECT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
)

if(NOT DEFINED YOTH_FLOAT_TYPE)
  set(YOTH_FLOAT_TYPE float)
endif()

if (NOT DEFINED YOTH_ENABLE_DEBUG)
  if (CMAKE_BUILD_TYPE STREQUAL "Release")
    set(YOTH_ENABLE_DEBUG 0)
  else()
    set(YOTH_ENABLE_DEBUG 1)
  endif()
endif()

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/yoth/core/config.hpp.in
  ${CMAKE_CURRENT_BINARY_DIR}/config.hpp
)