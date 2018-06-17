cmake_minimum_required(VERSION 3.8)
project(assignment1)

set(CMAKE_CXX_STANDARD 11)

set(EXEC_NAME assignment1)

set(SOURCE_FILES
        MySentence.cpp Corpus.cpp Corpus.h SyntaxChecker1.cpp Runner.cpp)
configure_file(juliusCaesar.txt juliusCaesar.txt COPYONLY)

add_executable(${EXEC_NAME} ${SOURCE_FILES})