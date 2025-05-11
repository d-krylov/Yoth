enable_testing()

set(YOTH_TESTS_SOURCES
  ${PROJECT_SOURCE_DIR}/tests/test.cpp
  ${PROJECT_SOURCE_DIR}/tests/matrix_tests.cpp
)

add_executable(Tests ${YOTH_TESTS_SOURCES})

target_link_libraries(Tests 
  PRIVATE gtest gtest_main Yoth  
)

add_test(NAME Tests COMMAND Tests)