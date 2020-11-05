cmake_minimum_required(VERSION 3.14)

project(lc3_vm)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "-O2 -DNDEBUG -Wall -Wextra -pedantic")

FILE(GLOB_RECURSE SRC  src/*.cpp src/*.h)

add_executable(${PROJECT_NAME} ${SRC})