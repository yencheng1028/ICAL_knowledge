cmake_minimum_required(VERSION 3.8)

# Set variables
set(PROJECT_NAME foo)
set(PROJECT_LANGUAGE CSharp)

# Set project
project(${PROJECT_NAME} ${PROJECT_LANGUAGE})

# Set file list
file(GLOB PROJECT_SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/*.cs
	)

# Compile library
add_library(${PROJECT_NAME} STATIC ${PROJECT_SRCS})
set_target_properties(${PROJECT_NAME}
	PROPERTIES
	OUTPUT_NAME			${PROJECT_NAME}
		PREFIX			"lib"
	)

# Set .Net references
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DOTNET_REFERENCES
	"System"
	"System.IO"
	)

# Install library
install(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION "${CMAKE_INSTALL_PREFIX}/bin"
	ARCHIVE DESTINATION "${CMAKE_INSTALL_PREFIX}/lib"
	LIBRARY DESTINATION "${CMAKE_INSTALL_PREFIX}/lib"
	PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_PREFIX}/include"
	)