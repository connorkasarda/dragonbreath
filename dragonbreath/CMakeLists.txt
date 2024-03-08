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
    source/engine/main.cpp
    source/engine/debug.cpp
    source/engine/entity_manager.cpp
    source/engine/system.cpp
    source/engine/component_manager.cpp
    source/engine/system_manager.cpp
    source/engine/commander.cpp
    source/math/vector3.cpp)

# Create the Dragonbreath library
add_library(dragonbreath_lib ${APP_SOURCES})
target_include_directories(dragonbreath_lib PUBLIC
    include/engine
    include/components
    include/systems
    include/math)

# Build Dragonbreath executable
add_executable(dragonbreath ${APP_SOURCES})
target_include_directories(dragonbreath PRIVATE
    include/engine
    include/components
    include/systems
    include/math)
target_link_libraries(dragonbreath PRIVATE dragonbreath_lib)
