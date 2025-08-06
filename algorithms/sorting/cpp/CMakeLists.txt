cmake_minimum_required(VERSION 3.20)
project(sorting_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-O2 -Wall -Wextra -Wpedantic)

enable_testing()

add_executable(sorting_tests
  tests/test_sorting.cpp
)
target_include_directories(sorting_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_test(NAME sorting_all COMMAND sorting_tests)
