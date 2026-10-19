cmake_minimum_required(VERSION 3.10)
project(Practica3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(.)

add_executable(Practica3
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

add_custom_command(TARGET Practica3 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/data"
        "$<TARGET_FILE_DIR:Practica3>/data"
)
