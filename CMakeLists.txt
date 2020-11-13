cmake_minimum_required(VERSION 3.14)

project(lc3_vm)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")

SET(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")

SET(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")

FILE(GLOB_RECURSE SRC src/*.cpp src/*.h)
INCLUDE_DIRECTORIES(src/)

add_executable(${PROJECT_NAME} ${SRC})