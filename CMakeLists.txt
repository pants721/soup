cmake_minimum_required(VERSION 3.25)

project(soup)

set(SOURCES
    src/main.cpp
    src/render_buffer.cpp
    src/renderer.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

add_executable(soup ${SOURCES})

find_program(iwyu_path NAMES include-what-you-use iwyu REQUIRED)
set_property(TARGET soup PROPERTY CXX_INCLUDE_WHAT_YOU_USE ${iwyu_path})

include_directories(${PROJECT_SOURCE_DIR}/include)
target_include_directories(soup
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

