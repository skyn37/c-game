# Set the paths
set(INCLUDE_PATH "${CMAKE_SOURCE_DIR}/include")
set(LIB_PATH "${CMAKE_SOURCE_DIR}/lib")

# List all source files
set(SOURCE_FILES "${CMAKE_SOURCE_DIR}/main.c" "${CMAKE_SOURCE_DIR}/draw.c" "${CMAKE_SOURCE_DIR}/controls.c" "${CMAKE_SOURCE_DIR}/game.c")

# Include directories
include_directories(${INCLUDE_PATH})

# Link directories
link_directories(${LIB_PATH})

# Create the BUILD directory in the source code directory
file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/BUILD")

# Navigate into the BUILD directory
set(CMAKE_BINARY_DIR "${CMAKE_SOURCE_DIR}/BUILD")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}")

# Compile the game
add_executable(GameProject ${SOURCE_FILES})

# Link libraries
target_link_libraries(GameProject raylib)
target_link_libraries(GameProject "-framework CoreVideo")
target_link_libraries(GameProject "-framework IOKit")
target_link_libraries(GameProject "-framework Cocoa")
target_link_libraries(GameProject "-framework GLUT")
target_link_libraries(GameProject "-framework OpenGL")

# Specify the output directory for the executable (inside BUILD/bin)
set_target_properties(GameProject PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Place all generated files in BUILD directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_MODULE_PATH "${CMAKE_BINARY_DIR}/module")

# Generate compile_commands.json for LSP
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

