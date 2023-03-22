cmake_minimum_required(VERSION 3.25)

project(soup)

set(SOURCES
    src/main.cpp
    src/render_buffer.cpp
    src/renderer.cpp
    src/common.cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(soup ${SOURCES})

include_directories(${PROJECT_SOURCE_DIR}/include)
target_include_directories(soup
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

