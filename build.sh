#!/bin/bash

# Build release
if [ "$1" = "release" ] || [ "$1" = "r" ]; then
    cmake --build build/release
# Build debug
else
    cmake --build build/debug
fi
