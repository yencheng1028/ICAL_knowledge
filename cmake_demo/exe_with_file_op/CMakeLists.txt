cmake_minimum_required(VERSION 2.8)

# Set project
project(HelloWorld C)

# Set project sources
file(GLOB PROJECT_SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/*.c
	${CMAKE_CURRENT_SOURCE_DIR}/*.h
	)

# Compile executable
add_executable(HelloWorld ${PROJECT_SRCS})
