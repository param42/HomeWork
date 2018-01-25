cmake_minimum_required(VERSION 3.2.2)
project(ULL_SLL_SA)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

set(SOURCE_FILES include/DoubleHashTable.h sources/DoubleHashTable.cpp include/LinearHashTable.h sources/LinearHashTable.cpp include/LinkedHashTable.h sources/LinkedHashTable.cpp )
add_executable(Examples ${SOURCE_FILES} examples/main.cpp)
add_executable(Tests ${SOURCE_FILES} tests/catch.hpp tests/main.cpp tests/DoubleHashTable_Search.cpp tests/DoubleHashTable_Remove.cpp tests/DoubleHashTable_Insert.cpp tests/DoubleHashTable_FindMaxMin.cpp)
