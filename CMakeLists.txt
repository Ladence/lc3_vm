cmake_minimum_required(VERSION 3.14)

project(lc3_vm)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "-O2 -DNDEBUG -Wall -Wextra -pedantic")

SET(CMAKE_CXX_FLAGS_DEBUG "-fsanitize=address")
SET(CMAKE_CXX_FLAGS_DEBUG "-fsanitize=leak")
SET(CMAKE_CXX_FLAGS_DEBUG "-fsanitize=thread")
SET(CMAKE_CXX_FLAGS_DEBUG "-fsanitize=undefined")
SET(CMAKE_CXX_FLAGS_DEBUG "-fsanitize=memory")

FILE(GLOB_RECURSE SRC  src/*.cpp src/*.h)
INCLUDE_DIRECTORIES(src/)

add_executable(${PROJECT_NAME} ${SRC})