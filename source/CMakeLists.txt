cmake_minimum_required(VERSION 3.29)
project(source)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(source
    ClassificationReport.cpp
    ClassificationReport.h
    Data.cpp
    Data.h
    FeatureVector.cpp
    FeatureVector.h
    knn.cpp
    knn.h
    KnnCosine.cpp
    KnnCosine.h
    main.cpp
    Sample.cpp
    Sample.h)



# CMAKELIST A MODIF QUAN ARBORESCENCE REFAITE

#cmake_minimum_required(VERSION 3.29)
#project(Homework)

# Inclure le dossier des headers
#include_directories(include) # Mettre les .h dedans

# Ajouter tous les fichiers source
#set(SOURCES
#    src/main.cpp
#    src/FeatureVector.cpp
#    src/Sample.cpp
#    src/Data.cpp
#    src/Knn.cpp
#    src/KnnCosine.cpp
#    src/ClassificationReport.cpp
#)

# Créer l’exécutable
#add_executable(knn ${SOURCES})

