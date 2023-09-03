cmake_minimum_required(VERSION 3.26)
project(interview)

set(CMAKE_CXX_STANDARD 20)

# Get a list of all .cpp files in the current directory
file(GLOB CPP_SOURCES "*.cpp")

# Iterate through each .cpp file and create an executable for it
foreach(CPP_SOURCE ${CPP_SOURCES})
    # Get the file name without extension
    get_filename_component(EXEC_NAME ${CPP_SOURCE} NAME_WE)

    # Add an executable target with the file name (excluding the extension)
    add_executable(${EXEC_NAME} ${CPP_SOURCE} bits/stdc++.h)
endforeach()
