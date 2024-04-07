cmake_minimum_required(VERSION 2.8)

# Set project
project(HelloWorld C)

# Set project sources
set(PROJECT_SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/foo.h
	${CMAKE_CURRENT_SOURCE_DIR}/foo.c
	)

# Compile library
add_library(foo STATIC ${PROJECT_SRCS})
