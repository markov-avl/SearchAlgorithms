cmake_minimum_required(VERSION 3.17)
project(SearchAlgorithms)

set(CMAKE_CXX_STANDARD 20)

add_executable(SearchAlgorithms main.cpp src/matrix.cpp src/search_algorithms.cpp src/constants.cpp)