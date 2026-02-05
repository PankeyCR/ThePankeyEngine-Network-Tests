cmake_minimum_required(VERSION 3.15)
project(PankeyEngineNetworkTests)

# Header-only library
add_library(PankeyEngineNetworkTests INTERFACE)

# Expose the folder with headers
target_include_directories(PankeyEngineNetworkTests INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}   # headers are in the root of ThePankeyEngine-Network-Tests
)

