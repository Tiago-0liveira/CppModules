cmake_minimum_required(VERSION 3.10)
project(ProjectName)

# Assuming your directory structure has multiple exercises each with their own 'includes' folder
#include_directories(Module00/includes)
include_directories(Module00/ex01/includes)
# Add more directories as needed

# Create a dummy target - doesn't need to be built
file(GLOB SOURCES "Module00/ex01/src/*.cpp")  # Adjust path as necessary for at least one exercise
add_executable(dummy ${SOURCES})
