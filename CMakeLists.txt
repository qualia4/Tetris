cmake_minimum_required(VERSION 3.20)
project(Tetris)

set(CMAKE_CXX_STANDARD 14)

add_executable(Tetris main.cpp Shape.cpp Shape.h Generator.cpp Generator.h Field.cpp Field.h GameEngine.cpp GameEngine.h)
