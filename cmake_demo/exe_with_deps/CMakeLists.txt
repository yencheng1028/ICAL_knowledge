cmake_minimum_required(VERSION 2.8)

# Set project
project(HelloWorld CXX)

# Find OpenCV
find_package(OpenCV REQUIRED)

# Include OpenCV directories
include_directories(${OpenCV_INCLUDE_DIRS})

# Set project sources
file(GLOB PROJECT_SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
	)

# Compile executable
add_executable(OpenCV_Demo ${PROJECT_SRCS})

# Link libraries
target_link_libraries(OpenCV_Demo ${OpenCV_LIBS})
