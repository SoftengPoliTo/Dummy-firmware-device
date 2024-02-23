#!/bin/bash

# Configure and compile the project with cargo
echo "Project configuration and compilation..."
cargo build --release --target=x86_64-unknown-linux-musl
