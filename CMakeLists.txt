CMAKE_MINIMUM_REQUIRED(VERSION 3.14)

PROJECT(lc3_vm)

SET(CMAKE_CXX_STANDARD 17)

if(CMAKE_COMPILER_IS_GNUCXX)
    MESSAGE(STATUS "GCC detected, adding compile flags")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra")
endif(CMAKE_COMPILER_IS_GNUCXX)

SET(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
SET(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")

FILE(GLOB_RECURSE SRC src/*.cpp src/*.h)
INCLUDE_DIRECTORIES(src/)

INCLUDE(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)  # Includes the contents of the conanbuildinfo.cmake file.
conan_basic_setup()  # Prepares the CMakeList.txt for Conan.

ADD_SUBDIRECTORY(test)
ADD_EXECUTABLE(${PROJECT_NAME} ${SRC})