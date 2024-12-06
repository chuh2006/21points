cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Game21)

# Add the executable
add_executable(Game21 main.cpp game.cpp player.cpp)

# Set the build directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)