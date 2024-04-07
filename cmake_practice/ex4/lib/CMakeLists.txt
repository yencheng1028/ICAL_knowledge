cmake_minimum_required(VERSION 3.2)
set(PROJECT_NAME calc)
set(PROJECT_DEPS gcc stdc++)
set(PROJECT_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/calc.h)
project(${PROJECT_NAME})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB PROJECT_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.c
    )

add_library(calc ${PROJECT_SRCS})
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 11
    OUTPUT_NAME ${PROJECT_NAME}
    PREFIX "lib"
    )



target_link_libraries(${PROJECT_NAME} ${PROJECT_DEPS})

#target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
