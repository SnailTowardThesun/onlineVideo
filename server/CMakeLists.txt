cmake_minimum_required(VERSION 3.5)

Project(onlineVideoServer)

set(CMAKE_CXX_FLAGS "-g -std=c++11 -pthread -Wall")

set(SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
set (EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR}/output)
set (LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR}/output)

add_executable(onlineMediaVideoServer ${SOURCE_DIR}/main/media_server.cpp)