cmake_minimum_required(VERSION 3.8)
project(lab08)

set(CMAKE_CXX_STANDARD 11)

set(EXEC_NAME lab08)

set(SOURCE_FILES HuffHeap.h HuffHeap.cpp huffman.h huffman.cpp CharRecord.cpp CharRecord.h )

add_executable(${EXEC_NAME} ${SOURCE_FILES})