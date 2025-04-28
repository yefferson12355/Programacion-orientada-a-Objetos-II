cmake_minimum_required(VERSION 3.29)
project(Cola)

set(CMAKE_CXX_STANDARD 14)

include_directories(Ejercicios_Clase)
include_directories(Ejercicios_Tarea/Ejercicio_1)
include_directories(Ejercicios_Tarea/Ejercicio_2)
include_directories(Ejercicios_Tarea/Ejercicio_3)

add_executable(Cola
    Ejercicios_Clase/cola.h
    Ejercicios_Clase/main.cpp
    Ejercicios_Clase/nodo.h
    Ejercicios_Tarea/Ejercicio_1/cola.h
    Ejercicios_Tarea/Ejercicio_1/main.cpp
    Ejercicios_Tarea/Ejercicio_1/nodo.h
    Ejercicios_Tarea/Ejercicio_2/cola.h
    Ejercicios_Tarea/Ejercicio_2/main.cpp
    Ejercicios_Tarea/Ejercicio_2/nodo.h
    "Ejercicios_Tarea/Ejercicio_3/cola (2).h"
    Ejercicios_Tarea/Ejercicio_3/cola.h
    Ejercicios_Tarea/Ejercicio_3/main.cpp
    Ejercicios_Tarea/Ejercicio_3/nodo.h)
