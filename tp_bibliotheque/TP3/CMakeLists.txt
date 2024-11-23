# Version minimale de CMake requise
cmake_minimum_required(VERSION 3.16)

# Nom du projet
project(TP_Bibliotheque)

# Spécifie la version de C++ utilisée
set(CMAKE_CXX_STANDARD 17)

# Liste les fichiers sources du projet
add_executable(TP_Bibliotheque
        main.cpp
        Document.cpp
        Livre.cpp
        Article.cpp
)
