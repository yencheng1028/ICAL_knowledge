cmake_minimum_required(VERSION 3.10)

project(basic_tutorial)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_subdirectory(kmeans)

add_executable(ch1 ch1_meow.cpp)
add_executable(ch2 ch2_opencv.cpp)
add_executable(ch3 ch3_cpp_basic.cpp)
add_executable(ch4 ch4_cpp_intermediate.cpp)
add_executable(ch5 ch5_cpp_hard.cpp)
add_executable(ch6 ch6_kmeans.cpp)
add_executable(test test.cpp)

target_link_libraries(ch1 ${OpenCV_LIBRARIES})
target_link_libraries(ch2 ${OpenCV_LIBRARIES})
target_link_libraries(ch6 kmeans_lib ${OpenCV_LIBRARIES})
target_link_libraries(test kmeans_lib ${OpenCV_LIBRARIES})