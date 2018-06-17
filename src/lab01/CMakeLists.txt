cmake_minimum_required(VERSION 3.8)
project(lab01)

set(CMAKE_CXX_STANDARD 11)

set(EXEC_NAME lab01)

set(SOURCE_FILES
        NumberCount.cpp
        NumberCount.h)

add_executable(${EXEC_NAME} ${SOURCE_FILES})