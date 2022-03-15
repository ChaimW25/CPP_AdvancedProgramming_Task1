cmake_minimum_required(VERSION 3.20)
project(taskA)

set(CMAKE_CXX_STANDARD 14)

add_executable(taskA mat.cpp mat.hpp Main.cpp )

add_executable(taskTrain check.cpp)
