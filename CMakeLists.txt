# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)  # Minimum version of CMake required
project(RandomLib VERSION 1.0)         # Project name and version

# Set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Specify the include directory
include_directories(include)

# Create a static library
add_library(RandomLib_static STATIC
    src/RandomC.cpp
    src/Random.cpp
)

# Create a shared library
add_library(RandomLib_shared SHARED
    src/RandomC.cpp
    src/Random.cpp
)

# Specify the library version
set_target_properties(RandomLib_shared PROPERTIES VERSION ${PROJECT_VERSION} SOVERSION 1)

# Optionally, you can install the libraries
install(TARGETS RandomLib_static RandomLib_shared
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    INCLUDES DESTINATION include
)

# Install header files
install(DIRECTORY include/
    DESTINATION include
)
