cmake_minimum_required(VERSION 2.8)

# Set project
project(exe_set C)

# Set file list
file(GLOB PROJECT_SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/*.c
	)

# Build executables
foreach(TEST_FILE_PATH ${PROJECT_SRCS})
	# Get each file name
	get_filename_component(TEST_FILE_NAME ${TEST_FILE_PATH} NAME_WE)

	# Build executable
	add_executable(${TEST_FILE_NAME} ${TEST_FILE_PATH})

endforeach()

