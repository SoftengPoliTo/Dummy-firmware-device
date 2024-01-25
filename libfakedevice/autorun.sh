#!/bin/bash

# Create evetually the folder to contain the binary
mkdir -p ../binaries

# Configure and compile the project with cargo
echo "Project configuration and compilation..."
cargo build --release

# Copy the produced binary to the binary folder
cp target/release/fake-firmware ../binaries
