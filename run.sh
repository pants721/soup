#!/bin/bash

# Run release
if [ "$1" = "release" ] || [ "$1" = "r" ]; then
    ./build/release/soup
# Run debug
else
    ./build/debug/soup
fi
