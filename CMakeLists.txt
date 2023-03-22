cmake_minimum_required(VERSION 3.25)

project(soup)

set(SOURCES
    src/main.cpp
        src/render_buffer.cpp
        src/render_buffer.hpp
    src/renderer.cpp
    src/renderer.hpp
    src/common.cpp
    src/common.hpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(soup ${SOURCES})

