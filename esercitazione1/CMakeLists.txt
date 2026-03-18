cmake_minimum_required(VERSION 3.20)
project(esercitazione1)

set(CMAKE_CXX_STANDART 20)
set(CMAKE_CXX_STANDART_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow")

set(SOURCES temperature_medie.cpp)

add_executable(prog printargs.cpp)
add_executable(programma ${SOURCES})