cmake_minimum_required(VERSION 3.29)
project(numero11)

set(CMAKE_CXX_STANDARD 20)

add_executable(numero11 main.cpp
        cliente.h
        cola.h
        Nodo.h)
