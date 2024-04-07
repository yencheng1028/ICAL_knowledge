cmake_minimum_required(VERSION 2.8)

# Set variables
set(PROJECT_NAME cmake_test)
set(PROJECT_LANGUAGE C)
set(PROJECT_DEPS foo)

# Set project
project(${PROJECT_NAME} ${PROJECT_LANGUAGE})

# Set file list
file(GLOB PROJECT_SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/*.c
	)

# Build test
foreach(TEST_FILE_PATH ${PROJECT_SRCS})
	# Get each file name
	get_filename_component(TEST_FILE_NAME ${TEST_FILE_PATH} NAME_WE)

	# Build executable
	add_executable(${TEST_FILE_NAME} ${TEST_FILE_PATH})
	set_target_properties(${TEST_FILE_NAME}
		PROPERTIES OUTPUT_NAME ${TEST_FILE_NAME}
		)
	target_link_libraries(${TEST_FILE_NAME} ${PROJECT_DEPS})

	# Install
	install(TARGETS ${TEST_FILE_NAME}
		RUNTIME DESTINATION "${CMAKE_INSTALL_PREFIX}/bin"
		)
endforeach()

