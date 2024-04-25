# Set the cmake version minimum requirement for ubuntu
cmake_minimum_required(VERSION 3.22.1)

# Set cmake version if too low
if(${CMAKE_VERSION} VERSION_LESS 3.22.1)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# Sets the dragonbreath project
project(
    DragonBreath
    VERSION 2024.04.21
    DESCRIPTION "Entity Component System project"
    LANGUAGES CXX)

# Add the application include directories
set(INCLUDE_DIRS
    include/Engine
    include/Math
    include/Components
    include/Systems
    include)
    # more to come ...

# Add the application source files
set(SOURCE_FILES
    source/Engine/Debug.cpp
    source/Engine/EntityManager.cpp
    source/Engine/System.cpp
    source/Engine/ComponentManager.cpp
    source/Engine/SystemManager.cpp
    source/Engine/Commander.cpp
    source/Math/Vector3.cpp
    source/Math/Quaternion.cpp
    source/DragonBreath.cpp)
    # More to come ...

# Create the Dragonbreath library
add_library(DragonBreathLib ${SOURCE_FILES})
target_include_directories(DragonBreathLib PUBLIC ${INCLUDE_DIRS})

# Build Dragonbreath executable
add_executable(DragonBreath ${SOURCE_FILES})
target_include_directories(DragonBreath PRIVATE ${INCLUDE_DIRS})
target_link_libraries(DragonBreath PRIVATE DragonBreathLib)
