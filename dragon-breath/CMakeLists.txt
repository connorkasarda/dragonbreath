cmake_minimum_required(VERSION 3.22.1)

set(CMAKE_CXX_STANDARD 23)

project(dragonbreath VERSION 2023.0)

find_package(OpenSSL REQUIRED)

add_subdirectory(external/curl)

file(GLOB SOURCES "src/*.cpp")

include_directories("include")

add_executable(dragonbreath ${SOURCES})
