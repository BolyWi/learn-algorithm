cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME "LearnAlgorithm")
project(${PROJECT_NAME})

include_directories(
	src/array
    src/list
	src/stack
	src/queue
	src/string
    src/tree
    src/graph
	src/search
	src/sort
)

file(GLOB_RECURSE SOURCE_FILE src/*.cpp src/*.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILE})