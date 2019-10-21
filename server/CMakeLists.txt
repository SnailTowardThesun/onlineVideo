cmake_minimum_required(VERSION 3.5)

Project(onlineVideoServer)

set(CMAKE_BUILD_TYPE DEBUG)

set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -std=c++11 -pthread -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "-g -O3 -std=c++11 -pthread -Wall")

set(SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR}/output)
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR}/output)

# add third-party support
set(THIRD_PARTY_DIR ${CMAKE_CURRENT_LIST_DIR}/third-party)

# libuv
include_directories(${THIRD_PARTY_DIR}/libuv-1.33.1/include)
find_library(LIBUV_LIBRARY NAMES uv HINTS ${THIRD_PARTY_DIR}/libuv-1.33.1/build)


# gflags
include_directories(${THIRD_PARTHDIR}/gflags/include)
find_library(LIBGFLAGS_LIBRARY NAMES gflags HINTS ${THIRD_PARTY_DIR}/gflags/lib)

# source
set(SRC_COMMON_FILES)
include_directories(${SOURCE_DIR}/common)
aux_source_directory(${SOURCE_DIR}/common SRC_COMMON_FILES)

set(SRC_MODULE_FILES)
include_directories(${SOURCE_DIR}/module)
aux_source_directory(${SOURCE_DIR}/module SRC_MODULE_FILES)

add_executable(mediaServer ${SOURCE_DIR}/main/media_server.cpp ${SRC_COMMON_FILES} ${SRC_MODULE_FILES})
target_link_libraries(mediaServer ${LIBUV_LIBRARY} ${LIBGLOG_LIBRARY} ${LIBGFLAGS_LIBRARY})

# unittest

include_directories(${THIRD_PARTY_DIR}/gtest/googletest-release-1.10.0/googletest)
include_directories(${THIRD_PARTY_DIR}/gtest/googletest-release-1.10.0/googletest/include)
add_library(gtest ${THIRD_PARTY_DIR}/gtest/googletest-release-1.10.0/googletest/src/gtest-all.cc)
add_library(gtest_main ${THIRD_PARTY_DIR}/gtest/googletest-release-1.10.0/googletest/src/gtest_main.cc)
target_link_libraries(gtest_main gtest)


add_executable(ms_utest ${SOURCE_DIR}/utest/ms_utest.cpp)
target_link_libraries(ms_utest gtest_main)