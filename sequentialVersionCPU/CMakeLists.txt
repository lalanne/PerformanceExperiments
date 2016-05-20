cmake_minimum_required(VERSION 2.8.11)
project(performanceExperiment)

add_definitions("-std=c++11 -openmp")

include_directories(/usr/local/include/benchmark)

add_executable(performanceExperiment  
            main.cpp)

link_directories(/usr/local/lib)

target_link_libraries(performanceExperiment benchmark) 
target_link_libraries(performanceExperiment pthread) 


