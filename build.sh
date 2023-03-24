#!/bin/bash

if [ "$1" = "release" ] || [ "$1" = "r" ]; then
    # Relase build
    cmake --build build/release
    ./build/release/soup
else
    # Debug build
    cmake --build build/debug
    ./build/debug/soup
fi
