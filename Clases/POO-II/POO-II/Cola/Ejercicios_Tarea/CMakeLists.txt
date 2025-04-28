cmake_minimum_required(VERSION 3.29)
project(Ejercicios_Tarea)

set(CMAKE_CXX_STANDARD 14)

include_directories(Ejercicio_1)
include_directories(Ejercicio_2)
include_directories(Ejercicio_3)

add_executable(Ejercicios_Tarea
    Ejercicio_1/cola.h
    Ejercicio_1/main.cpp
    Ejercicio_1/nodo.h
    Ejercicio_2/cola.h
    Ejercicio_2/main.cpp
    Ejercicio_2/nodo.h
    "Ejercicio_3/cola (2).h"
    Ejercicio_3/cola.h
    Ejercicio_3/main.cpp
    Ejercicio_3/nodo.h)
