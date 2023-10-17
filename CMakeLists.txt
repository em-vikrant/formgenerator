cmake_minimum_required(VERSION 3.20)
project(FormGenerator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

SET(CMAKE_CXX_FLAGS "-Wall -Werror -DIL_STD -Wno-deprecated")

#SET(CMAKE_BUILD_TYPE "DEBUG")
SET(CMAKE_BUILD_TYPE "RELEASE")

IF( ${CMAKE_BUILD_TYPE} STREQUAL "DEBUG" )
    SET(CMAKE_CXX_FLAGS_RELEASE "-O0")
    SET(CMAKE_CXX_FLAGS_DEBUG  "-g")
ELSE()
    SET(CMAKE_CXX_FLAGS_RELEASE "-O3")
ENDIF()

# Compiler definitions
add_definitions(-D_ROOT_PATH=\"${CMAKE_SOURCE_DIR}\")

# SFML related settings -BEGIN
IF(WIN32)
    message(STATUS "[PLATFORM] Windows")
ELSEIF(UNIX AND APPLE)
    message(STATUS "[PLATFORM] Unix / MacOS")
    set(CMAKE_BUILD_RPATH "${CMAKE_SOURCE_DIR}/../SFML/build/lib")
ENDIF()

set(SFML_INC_PATH "${CMAKE_SOURCE_DIR}/../SFML/include")
set(SFML_LIB_PATH "${CMAKE_SOURCE_DIR}/../SFML/build/lib")
# SFML related settings -END

add_subdirectory(inc)
add_subdirectory(src)

option(BUILD_EXAMPLES "BUILD EXAMPLE DIRECTORY" ON)

if (BUILD_EXAMPLES)
    message(STATUS "BUILDING EXAMPLES PACK")
    add_subdirectory(examples)
endif()
