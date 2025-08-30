cmake_minimum_required(VERSION 3.10)

# Project name and version
project(rtiow VERSION 1.0 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add executable or library
add_executable(${PROJECT_NAME} main.cpp vec3.h)

# Optionally, specify include directories
# target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Optionally, link libraries
# target_link_libraries(${PROJECT_NAME} PRIVATE some_library)
