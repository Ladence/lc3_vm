CMAKE_MINIMUM_REQUIRED(VERSION 3.14)

PROJECT(lc3_vm_tests)

SET(CMAKE_CXX_STANDARD 17)

if(CMAKE_COMPILER_IS_GNUCXX)
    MESSAGE(STATUS "GCC detected, adding compile flags")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra")
endif(CMAKE_COMPILER_IS_GNUCXX)

SET(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
SET(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")

SET(ROOT_DIR ../)
FILE(GLOB_RECURSE VM_SRC ${ROOT_DIR}/src/common/*.src
        ${ROOT_DIR}/src/core/*.cpp
        ${ROOT_DIR}/src/hardware/*.cpp
        ${ROOT_DIR}/src/instructions/*.cpp
        ${ROOT_DIR}/src/interfaces/*.cpp
        ${ROOT_DIR}/src/sysmanagement/*.cpp)
FILE(GLOB_RECURSE SRC src/*.cpp src/*.h)
INCLUDE_DIRECTORIES(${ROOT_DIR}/src)

ADD_EXECUTABLE(${PROJECT_NAME} ${SRC} ${VM_SRC})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${CONAN_LIBS})