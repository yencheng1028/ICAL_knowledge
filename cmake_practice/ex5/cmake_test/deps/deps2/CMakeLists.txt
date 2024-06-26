cmake_minimum_required(VERSION 2.8)

# Set variables
set(PROJECT_NAME deps2)
set(PROJECT_LANGUAGE C)
set(PROJECT_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/deps2.h)

# Compile setting
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_C_FLAGS_RELEASE "-O3")

# Set project
project(${PROJECT_NAME} ${PROJECT_LANGUAGE})

# Add definition
if(CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DDEBUG)
endif()

# Include directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Set file list
file(GLOB PROJECT_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/*.c)

# Build library
add_library(${PROJECT_NAME} STATIC ${PROJECT_SRCS})
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_NAME ${PROJECT_NAME}
    PREFIX "lib"
    )

# Install
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION "${CMAKE_INSTALL_PREFIX}/bin"
    ARCHIVE DESTINATION "${CMAKE_INSTALL_PREFIX}/lib"
    LIBRARY DESTINATION "${CMAKE_INSTALL_PREFIX}/lib"
    PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_PREFIX}/include"
    )
install(FILES ${PROJECT_HEADERS}
    DESTINATION "${CMAKE_INSTALL_PREFIX}/include"
    )
