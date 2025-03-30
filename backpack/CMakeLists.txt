cmake_minimum_required(VERSION 3.28)
project(backpack)

set(CMAKE_CXX_STANDARD 20)

set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.hpp *.cpp *.txt)

set(SOURCES ${SOURCES})

add_executable(backpack_run backpack.cpp)

add_library(${BINARY}_lib STATIC ${SOURCES})