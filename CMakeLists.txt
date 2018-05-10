# cmake 最低版本号要求
cmake_minimum_required(VERSION 2.8)

# 项目蜜柑
project(BWT)

# 可执行文件路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# debug和release版本
set(CMAKE_BUILD_TYPE  "debug")
if (CMAKE_BUILD_TYPE STREQUAL debug)
    add_definitions(-D_DEBUG)
endif()

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb -std=c++11")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -std=c++11")

add_executable(bwt main.cpp compression.cpp compression.h decompression.cpp decompression.cpp decompression.h search.cpp search.h io.cpp io.h)


