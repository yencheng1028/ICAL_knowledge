cmake_minimum_required(VERSION 3.8)

# Set variables
set(PROJECT_NAME cmake_demo)
set(PROJECT_LANGUAGE CSharp)

# Environment variables
set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "Installation directory")
set(BUILD_TEST OFF CACHE BOOL "Enable building test")

# Set project
project(${PROJECT_NAME} ${PROJECT_LANGUAGE})

# Build library
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib)

# Build test
if(${BUILD_TEST})
	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)
endif()
