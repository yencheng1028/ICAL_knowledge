cmake_minimum_required(VERSION 3.2)

include_directories(${CMAKE_SOURCE_DIR})
project(App)

file(GLOB PROJECT_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    )


add_executable(app main.cpp)
target_link_libraries(app calc)
