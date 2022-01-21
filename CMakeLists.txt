cmake_minimum_required(VERSION 3.2)
project(Algos VERSION 1.0)

include_directories(${CMAKE_SOURCE_DIR})

add_compile_options(-Wall -Wextra -pedantic -Werror -g)

add_executable(
    Kruskal
    KruskalMain.cpp
)

add_executable(
    Disjoint
    DisjointMain.cpp
)

add_executable(
    MinHeapMap
    MinHeapMapMain.cpp
)
