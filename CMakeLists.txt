cmake_minimum_required(VERSION 3.20)
project(mystl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(mystl INTERFACE)
target_include_directories(mystl INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(tests
  tests/vector_tests.cpp
)
target_link_libraries(tests PRIVATE mystl)

add_executable(demo examples/demo_vector.cpp)
target_link_libraries(demo PRIVATE mystl)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  target_compile_options(tests PRIVATE -Wall -Wextra -Wpedantic -Wconversion -Wshadow)
  target_compile_options(demo  PRIVATE -Wall -Wextra -Wpedantic -Wconversion -Wshadow)
  target_link_options(tests PRIVATE -fsanitize=address,undefined)
  target_compile_options(tests PRIVATE -fsanitize=address,undefined)
endif()