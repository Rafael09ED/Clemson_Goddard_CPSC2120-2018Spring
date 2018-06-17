cmake_minimum_required(VERSION 3.8)
project(lab09)

set(CMAKE_CXX_STANDARD 11)

set(EXEC_NAME lab09)

set(SOURCE_FILES Stack.h Hanoi.h Hanoi.cpp Disk.h Disk.cpp)

add_executable(${EXEC_NAME} ${SOURCE_FILES})
