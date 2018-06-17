cmake_minimum_required(VERSION 3.8)
project(assignment2)

set(CMAKE_CXX_STANDARD 11)

set(EXEC_NAME assignment2)

set(SOURCE_FILES
        SyntaxChecker.cpp RangeSet.h RangeSet.cpp RNode.cpp RNode.h)

add_executable(${EXEC_NAME} ${SOURCE_FILES})
