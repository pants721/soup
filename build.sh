#!/bin/bash

# Build and run release
if [ "$1" = "release" ] || [ "$1" = "r" ]; then
    cmake --build build/release
    ./build/release/soup
# Debug build
else
    cmake --build build/debug
    ./build/debug/soup
fi
