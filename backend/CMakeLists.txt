cmake_minimum_required(VERSION 3.15)
project(Multiplicator)


set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-O3")

add_executable(Multiplicator main.cpp
        Number.h
        Multiplicator.h
        Number.cpp
        Multiplicator.cpp)