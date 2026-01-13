cmake_minimum_required(VERSION 3.10)
project(Homework)

# Récupération des fichiers sources
file(GLOB SOURCES "source/*.cpp")

# Créer l'exécutable
add_executable(executable ${SOURCES})

# Dossier source
target_include_directories(executable PRIVATE source)