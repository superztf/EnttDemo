# First CMake Test

cmake_minimum_required(VERSION 3.13.1)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "Prevented in-tree built. Please create a build directory outside of the source code and call cmake from there. Thank you.")
endif()

project(EnttDemo VERSION 1.0.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

include(GNUInstallDirs)
add_compile_options("/std:c++17")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

message("*")
message("* ${PROJECT_NAME} v${PROJECT_VERSION} (${CMAKE_BUILD_TYPE}) start building")
message("*")


include_directories(
    "./deps/"
)


add_subdirectory(main)
file(COPY "${CMAKE_SOURCE_DIR}/lib/x86/SDL2.dll" DESTINATION "${CMAKE_SOURCE_DIR}/build/bin/Debug")