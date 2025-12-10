cmake_minimum_required(VERSION 3.10)
project(MyProject)

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
