cmake_minimum_required(VERSION 3.8)
project(lab06)

set(CMAKE_CXX_STANDARD 11)

set(EXEC_NAME lab06)

set(SOURCE_FILES PTDriver.cpp)


add_executable(${EXEC_NAME} ${SOURCE_FILES})