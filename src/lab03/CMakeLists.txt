cmake_minimum_required(VERSION 3.8)
project(lab03)

set(CMAKE_CXX_STANDARD 11)

set(EXEC_NAME lab03)

set(SOURCE_FILES
        Recursion.cpp)
configure_file(sample1.txt sample.txt COPYONLY)

add_executable(${EXEC_NAME} ${SOURCE_FILES})