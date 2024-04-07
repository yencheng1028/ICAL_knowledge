cmake_minimum_required(VERSION 3.2)
project(Ex4)


set(LIB_PATHS
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/
            )


message(${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib)
#include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/lib.cmake)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)

