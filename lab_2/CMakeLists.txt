cmake_minimum_required(VERSION 3.16)

project(laba2)
set(CMAKE_CXX_STANDART 17)

set(SOURCE_EXE lab2_oop.cpp angle.cpp)

add_executable(main ${ SOURCE_EXE })
