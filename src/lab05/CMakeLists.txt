cmake_minimum_required(VERSION 3.8)
project(lab05)

set(CMAKE_CXX_STANDARD 11)

set(EXEC_NAME lab05)

set(SOURCE_FILES
        TestBlister.cpp Blister.cpp)

add_executable(${EXEC_NAME} ${SOURCE_FILES})