cmake_minimum_required(VERSION 3.22.1)

set(CMAKE_CXX_STANDARD 23)

project(dragonbreath VERSION 2024.0)

file(GLOB SOURCES "source/*.cpp")

include_directories("include")

add_executable(dragonbreath ${SOURCES})
