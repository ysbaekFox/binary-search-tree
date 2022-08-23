project(binary-search-tree)

cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE)

include_directories(.)
add_executable(exec "main.cpp" "bst.h")