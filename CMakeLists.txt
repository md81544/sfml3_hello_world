cmake_minimum_required(VERSION 3.15)
project(HelloSFML3)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

# Find SFML 3 packages
find_package(SFML 3.0 COMPONENTS System Window Graphics REQUIRED)

# Add executable
add_executable(hello main.cpp)

target_compile_options(hello PRIVATE -std=c++2b -Wall -Wextra -Werror -Wpedantic)

# Link SFML libraries
target_link_libraries(hello
    PRIVATE
        SFML::System
        SFML::Window
        SFML::Graphics
)