# Set the cmake version minimum requirement for ubuntu
cmake_minimum_required(VERSION 3.22.1)

# Set cmake version if too low
if(${CMAKE_VERSION} VERSION_LESS 3.22.1)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# Sets the dragonbreath project
project(
    dragonbreath
    VERSION 2024.1.30
    DESCRIPTION "Entity Component System project"
    LANGUAGES CXX)

# If Doxygen included, generate docs
find_package(Doxygen)
if(Doxygen_FOUND)
    add_subdirectory(docs)
else()
    message(STATUS "Doxygen not found, not building docs")
endif()

# Add the application source files
set(APP_SOURCES
    source/main.cpp
    source/debug.cpp
    source/entity_manager.cpp)

# Add the application target
add_executable(dragonbreath ${APP_SOURCES})

# Include directories
target_include_directories(dragonbreath PRIVATE include)

# Define compiler features
target_compile_features(dragonbreath PRIVATE cxx_std_23)
