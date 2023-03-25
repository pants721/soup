#!/bin/bash

# Create build directories
if [ ! -d "$build" ]; then
    mkdir build
    mkdir build/debug
    mkdir build/release
fi

# Cmake init debug dir
cd build/debug
cmake -DCMAKE_BUILD_TYPE=Debug ../../
cd ../../

cd build/release
# Cmake init release dir
cmake -DCMAKE_BUILD_TYPE=Release ../../
cd ../../

# Create sym-link from debug compile_commands.json to source directory for lsp
ln -s build/debug/compile_commands.json .

# Make build.sh executable
chmod +x build.sh

