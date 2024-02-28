#!/bin/bash

# Configure and compile the project with Meson and Ninja
echo "Project configuration and compilation..."
env CXX=clang++ meson setup build
ninja -C build
