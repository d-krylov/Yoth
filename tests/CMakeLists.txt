enable_testing()

set(YOTH_TESTS_SOURCES
  ${PROJECT_SOURCE_DIR}/tests/test.cpp
)

add_executable(Tests ${YOTH_TESTS_SOURCES})

target_include_directories(Tests PRIVATE
  ${PROJECT_SOURCE_DIR}/yoth
)

target_link_libraries(Tests PRIVATE gtest gtest_main)

add_test(NAME Tests COMMAND Tests)