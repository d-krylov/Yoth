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

set(YOTH_SOURCES
  ${PROJECT_SOURCE_DIR}/yoth/common/yoth.cpp
)

add_library(${PROJECT_NAME} STATIC ${YOTH_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
  ${PROJECT_SOURCE_DIR}
)

if(NOT DEFINED YOTH_FLOAT_TYPE)
  set(YOTH_FLOAT_TYPE float)
endif()

if(YOTH_FLOAT_TYPE STREQUAL "float")
  target_compile_definitions(${PROJECT_NAME} PUBLIC YOTH_FLOAT_TYPE_FLOAT)
elseif(LINALG_FLOAT_TYPE STREQUAL "double")
  target_compile_definitions(${PROJECT_NAME} PUBLIC YOTH_FLOAT_TYPE_DOUBLE)
else()
  message(FATAL_ERROR "Unsupported YOTH_FLOAT_TYPE")
endif()
