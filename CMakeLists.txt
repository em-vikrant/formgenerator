cmake_minimum_required(VERSION 3.20)
project(FormGenerator)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(CMAKE_CXX_FLAGS "-Wall -Werror -DIL_STD -Wno-deprecated")

#SET(CMAKE_BUILD_TYPE "DEBUG")
SET(CMAKE_BUILD_TYPE "RELEASE")

IF( ${CMAKE_BUILD_TYPE} STREQUAL "DEBUG" )
    SET(CMAKE_CXX_FLAGS_RELEASE "-O0")
    SET(CMAKE_CXX_FLAGS_DEBUG  "-g")
ELSE()
    SET(CMAKE_CXX_FLAGS_RELEASE "-O3")
ENDIF()

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(lib)

option(BUILD_EXAMPLES "BUILD EXAMPLE DIRECTORY" ON)

if (BUILD_EXAMPLES)
    message(STATUS "Building examples...")
    add_subdirectory(examples)
endif()
