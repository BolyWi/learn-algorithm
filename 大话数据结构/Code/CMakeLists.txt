cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME "LearnAlgorithm")
project(${PROJECT_NAME})

include_directories(
    src/list
    src/tree
    src/graph
)

file(GLOB_RECURSE SOURCE_FILE src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILE})