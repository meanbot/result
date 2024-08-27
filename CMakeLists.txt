
cmake_minimum_required(VERSION 3.20.0)


project(result 
  HOMEPAGE_URL https://github.com/meanbot/result
  DESCRIPTION "result - result & error handling" 
  VERSION 0.0.1 
  LANGUAGES CXX)

include(cmake/CPM.cmake)

CPMAddPackage("gh:fmtlib/fmt#10.1.1")
CPMAddPackage("gh:TartanLlama/expected#v1.1.0")
CPMAddPackage("gh:boostorg/preprocessor#boost-1.86.0")

CPMAddPackage( 
  NAME meanbot_error 
  SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../error"
)

add_library(${PROJECT_NAME} STATIC 
  src/precomp.cpp 
)

add_library(meanbot::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_compile_options(${PROJECT_NAME} PUBLIC "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/permissive->")

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(${PROJECT_NAME} fmt::fmt-header-only)
target_link_libraries(${PROJECT_NAME} tl::expected)
target_link_libraries(${PROJECT_NAME} Boost::preprocessor)
target_link_libraries(${PROJECT_NAME} meanbot::error)

target_precompile_headers(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/precomp.hpp")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
