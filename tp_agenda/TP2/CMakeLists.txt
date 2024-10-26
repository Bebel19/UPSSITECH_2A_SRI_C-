cmake_minimum_required(VERSION 3.29)
project(TP2)

set(CMAKE_CXX_STANDARD 23)

add_executable(TP2 main.cpp
        Entree.h
        Entree.cpp
        Tableau.h
        Tableau.cpp
        Agenda.h
        Agenda.cpp)
