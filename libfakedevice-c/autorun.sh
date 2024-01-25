#!/bin/bash

# Create evetually the folder to contain the build
mkdir -p ../binaries/libfakedevice-c

# Configure and compile the project with Meson and Ninja
echo "Project configuration and compilation..."
env CC=clang meson setup build
ninja -C build

# Copy the produced build to the binary folder
cp -r build/** ../binaries/libfakedevice-c/
