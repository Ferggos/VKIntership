cmake_minimum_required(VERSION 3.10.0)
project(VKInterShip VERSION 0.1.0 LANGUAGES C CXX)

SET(HEADERS "undirectgraph.h")
SET(SOURCES "main.cpp" "undirectgraph.cpp")

add_executable(VKInterShip ${HEADERS} ${SOURCES})

include(CTest)
enable_testing()

