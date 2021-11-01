cmake_minimum_required(VERSION 3.0)

message(STATUS "link libs include dir: ${CMAKE_CURRENT_LIST_DIR}")

project(test_bins)
include_directories(../libs)



add_executable(test_bins test_bbuffer32.c)
message(STATUS "link libs include dir: ${CMAKE_CURRENT_LIST_DIR}/../src/binaryBuffer")
target_link_directories(test_bins PUBLIC  
    ${CMAKE_CURRENT_LIST_DIR}/../src/build)

target_link_libraries(test_bins binaryBuffer unity)

target_include_directories(test_bins PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/../libs/ )

