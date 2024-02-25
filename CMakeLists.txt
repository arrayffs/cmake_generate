cmake_minimum_required(VERSION 3.28.2)
project(cmake_generate)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

file (GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")

add_executable(cmake_generate ${SOURCES})
