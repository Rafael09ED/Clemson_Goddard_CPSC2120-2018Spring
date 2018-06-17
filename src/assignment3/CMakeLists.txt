cmake_minimum_required(VERSION 3.8)
project(assignment3)

set(CMAKE_CXX_STANDARD 11)

set(EXEC_NAME assignment3)

set(SOURCE_FILES SyntaxChecker3.cpp Position.cpp Position.h mancala.cpp PositionTreeNode.cpp PositionTreeNode.h)

add_executable(${EXEC_NAME} ${SOURCE_FILES})
