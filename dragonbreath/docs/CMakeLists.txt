# Generate documentation using Doxygen

# Ensure Doxygen required
find_package(Doxygen REQUIRED)

# Add a target to generate the documentation
add_custom_target(docs
    COMMAND ${DOXYGEN_EXECUTABLE} Doxyfile
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating API documentation with Doxygen"
    VERBATIM
)
