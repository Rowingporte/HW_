cmake_minimum_required(VERSION 3.10)
project(Homework)

# Inclure le dossier des headers
include_directories(include)

# Ajouter tous les fichiers source
set(SOURCES
    src/main.cpp
    src/FeatureVector.cpp
    src/Sample.cpp
    src/Data.cpp
    src/Knn.cpp
    src/KnnCosine.cpp
    src/ClassificationReport.cpp
)

# Créer l’exécutable
add_executable(executable ${SOURCES})
