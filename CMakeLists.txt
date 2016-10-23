project(tic-tac-toe)
cmake_minimum_required(VERSION 2.8)

#version number
set (tic-tac-toe_VERSION_MAJOR 1)
set (tic-tac-toe_VERSION_MINOR 0)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

aux_source_directory(./src SOURCES)

add_executable(${PROJECT_NAME} ${SOURCES})
FILE(GLOB_RECURSE HEADERS "include/*.h")
include_directories(include)
add_custom_target(headers SOURCES ${HEADERS})
target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
