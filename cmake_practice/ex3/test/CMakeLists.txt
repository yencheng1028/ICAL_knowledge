cmake_minimum_required(VERSION 3.2)

project(App)
include_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(app main.cpp)
target_link_libraries(app calc)
