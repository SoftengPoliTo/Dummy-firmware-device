#!/bin/bash

# Create evetually the folder to contain the build
mkdir -p ../binaries/libfakedevice-cpp

# Configure and compile the project with Meson and Ninja
echo "Project configuration and compilation..."
env CXX=clang++ meson setup build
ninja -C build

# Copy the produced build to the binary folder
cp -r build/** ../binaries/libfakedevice-cpp/
