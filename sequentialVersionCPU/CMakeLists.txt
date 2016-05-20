cmake_minimum_required(VERSION 2.8.11)
project(performanceExperiment)

set(GCC_COVERAGE_COMPILE_FLAGS "-std=c++11 -fopenmp")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

set(GCC_COVERAGE_LINK_FLAGS "-fopenmp")
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

include_directories(/usr/local/include/benchmark)

add_executable(performanceExperiment  
            main.cpp)

link_directories(/usr/local/lib)

target_link_libraries(performanceExperiment benchmark) 
target_link_libraries(performanceExperiment pthread) 


