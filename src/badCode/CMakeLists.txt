cmake_minimum_required(VERSION 3.8)
project(badCode)

set(CMAKE_CXX_STANDARD 11)

set(EXEC_NAME badCode)

set(SOURCE_FILES
        BadCode.cpp)

add_executable(${EXEC_NAME} ${SOURCE_FILES})