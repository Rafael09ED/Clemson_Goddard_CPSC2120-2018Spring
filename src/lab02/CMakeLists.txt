cmake_minimum_required(VERSION 3.8)
project(lab02)

set(CMAKE_CXX_STANDARD 11)

set(EXEC_NAME lab02)

set(SOURCE_FILES
        PosPoly.cpp
        PosPoly.h main.cpp)

add_executable(${EXEC_NAME} ${SOURCE_FILES})