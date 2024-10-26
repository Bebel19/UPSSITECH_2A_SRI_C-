cmake_minimum_required(VERSION 3.29)
project(TP1)

set(CMAKE_CXX_STANDARD 23)

add_executable(TP1 main.cpp
        Agenda.h
        Entree.h
        Tableau.h
        Entree.cpp
        Tableau.cpp
        Agenda.cpp)
