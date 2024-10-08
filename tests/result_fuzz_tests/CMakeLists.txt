
cmake_minimum_required(VERSION 3.20.0)


project(result_fuzz_tests 
  HOMEPAGE_URL https://github.com/meanbot/result 
  DESCRIPTION "result - result & error handling - fuzz tests" 
  VERSION 0.0.1 
  LANGUAGES CXX)

include(../../cmake/CPM.cmake)

CPMAddPackage("gh:fmtlib/fmt#10.1.1")

CPMAddPackage( 
  NAME meanbot_result 
  SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../.."
)

add_library(${PROJECT_NAME} SHARED 
  result_fuzz_tests.cpp 
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../include)

target_link_libraries(${PROJECT_NAME} fmt::fmt-header-only)
target_link_libraries(${PROJECT_NAME} meanbot::result)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
