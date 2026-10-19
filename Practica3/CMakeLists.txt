cmake_minimum_required(VERSION 4.2)
project(Practica2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Practica2
        Iterador.h
        LectorCSV.cpp
        LectorCSV.h
        ListaDEnlazada.h
        main.cpp
        Nodo.h
        Parque.h
        Especie.h
        Parque.cpp
        ControlParques.cpp
        ControlParques.h
)
