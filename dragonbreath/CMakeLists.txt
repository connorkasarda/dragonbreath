# Set the cmake version minimum requirement for ubuntu
cmake_minimum_required(VERSION 3.22.1)

# Set cmake version if too low
if(${CMAKE_VERSION} VERSION_LESS 3.22.1)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# Sets the dragonbreath project
project(
    dragonbreath
    VERSION 2024.03.09
    DESCRIPTION "Entity Component System project"
    LANGUAGES CXX)

# Add the application include directories
set(INCLUDE_DIRS
    include/engine
    include/math
    include/components
    include/systems
    include)
    # more to come ...

# Add the application source files
set(SOURCE_FILES
    source/engine/debug.cpp
    source/engine/entity_manager.cpp
    source/engine/system.cpp
    source/engine/component_manager.cpp
    source/engine/system_manager.cpp
    source/engine/commander.cpp
    source/math/vector3.cpp
    source/dragonbreath.cpp)
    # More to come ...

# Create the Dragonbreath library
add_library(dragonbreath_lib ${SOURCE_FILES})
target_include_directories(dragonbreath_lib PUBLIC ${INCLUDE_DIRS})

# Build Dragonbreath executable
add_executable(dragonbreath ${SOURCE_FILES})
target_include_directories(dragonbreath PRIVATE ${INCLUDE_DIRS})
target_link_libraries(dragonbreath PRIVATE dragonbreath_lib)
