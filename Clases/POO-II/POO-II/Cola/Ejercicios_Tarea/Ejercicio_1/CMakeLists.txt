cmake_minimum_required(VERSION 3.29)
project(test_cola)

set(CMAKE_CXX_STANDARD 20)

add_executable(test_cola main.cpp
        cola.h
        nodo.h)
