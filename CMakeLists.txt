cmake_minimum_required(VERSION 3.0)

set (CMAKE_CXX_STANDARD 17)

project (ode-num)

add_executable (ode-num src/ode-num.cc)
target_include_directories (ode-num PUBLIC include/)

