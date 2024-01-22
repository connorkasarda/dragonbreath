cmake_minimum_required(VERSION 3.22.1)

set(CMAKE_CXX_STANDARD 23)

project(dragonbreath VERSION 2023.0)

find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})

file(GLOB SOURCES "src/*.cpp")

include_directories("include")

add_executable(dragonbreath ${SOURCES})

target_link_libraries(dragonbreath ${OPENSSL_LIBRARIES})
target_link_libraries(dragonbreath ${CURL_LIBRARIES})
