include_directories(../libs/)

add_library(binaryBuffer 
STATIC binaryBuffer.c unity.c )

add_library(unity STATIC unity.c ../libs/unity.h ../libs/unity_internals.h)
message(STATUS "LIBS ${CMAKE_CURRENT_LIST_DIR}/../libs/binaryBuffer.h")


target_link_directories(binaryBuffer PUBLIC 
${CMAKE_CURRENT_LIST_DIR}/../libs/)

target_link_directories(unity PUBLIC 
${CMAKE_CURRENT_LIST_DIR}/../libs/)


target_include_directories(binaryBuffer 
        PUBLIC 
        ${CMAKE_CURRENT_LIST_DIR}/../libs/)
