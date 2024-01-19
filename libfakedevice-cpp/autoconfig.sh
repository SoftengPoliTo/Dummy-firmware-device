#!/bin/bash

# Check if Meson is already installed
if ! command -v meson &> /dev/null
then
    echo "Meson not found. Installation in progress..."
    # Install Meson
    sudo apt-get update
    sudo apt-get install meson
else
    echo "Meson already installed."
fi

# Check if clang++ is already installed
if ! command -v clang++ &> /dev/null
then
    echo "Clang++ not found. Installation in progress..."
    # Install Clang++
    sudo apt-get update
    sudo apt-get install clang
else
    echo "Clang++ already installed."
fi

# Configure and compile the project with Meson and Ninja
echo "Project configuration and compilation..."
env CXX=clang++ meson setup build
cd build
ninja

# Check whether the operation was completed successfully
if [ $? -eq 0 ]
then
    echo "Compilation completed successfully."
else
    echo "Error during compilation."
fi
