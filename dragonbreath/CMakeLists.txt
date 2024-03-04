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

# Add the application source files
set(APP_SOURCES
    source/main.cpp
    source/debug.cpp
    source/entity_manager.cpp
    source/system.cpp
    source/component_array.tpp
    source/component_manager.tpp
    source/component_manager.cpp
    source/system_manager.tpp
    source/system_manager.cpp)

# Create the Dragonbreath library
add_library(dragonbreath_lib ${APP_SOURCES})
target_include_directories(dragonbreath_lib PUBLIC include)

# Build Dragonbreath executable
add_executable(dragonbreath ${APP_SOURCES})
target_include_directories(dragonbreath PRIVATE include)
target_link_libraries(dragonbreath PRIVATE dragonbreath_lib)
