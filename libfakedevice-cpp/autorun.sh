#!/bin/bash

# Create evetually the folder to contain the binary
mkdir -p ../binaries

# Configure and compile the project with Meson and Ninja
echo "Project configuration and compilation..."
env CXX=clang++ meson setup build
ninja -C build

# Copy the produced binary to the binary folder
cp build/fake-firmware-cpp ../binaries
