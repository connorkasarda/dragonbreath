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

# Add the test source files
set(
    TEST_SOURCES
    tests/source/main.cpp)

# Create the Dragonbreath library
add_library(dragonbreath_lib ${APP_SOURCES})
target_include_directories(dragonbreath_lib PUBLIC include)

# Build Dragonbreath executable
add_executable(dragonbreath ${APP_SOURCES})
target_include_directories(dragonbreath PRIVATE include)
target_link_libraries(dragonbreath PRIVATE dragonbreath_lib)

# Build test executable
add_executable(dragonbreath_test ${TEST_SOURCES})
target_include_directories(dragonbreath_test PRIVATE include tests/include)
target_link_libraries(dragonbreath_test PRIVATE dragonbreath_lib)

# Enable testing functionality
enable_testing()

# Define the testing
add_test(
    NAME dragonbreath_test
    COMMAND $<TARGET_FILE:dragonbreath_test>)
