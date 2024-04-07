cmake_minimum_required(VERSION 2.8)

# Set project
project(HelloWorld C)

# Set project sources
set(PROJECT_LIB_SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/foo.h
	${CMAKE_CURRENT_SOURCE_DIR}/foo.c
	)

set(PROJECT_EXE_SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/main.c
	)

# Compile library
add_library(foo STATIC ${PROJECT_LIB_SRCS})

# Compile executable
add_executable(HelloWorld ${PROJECT_EXE_SRCS})

# Link library
target_link_libraries(HelloWorld foo)
