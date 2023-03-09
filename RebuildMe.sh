#!/bin/bash
git clean -x -d -f
cmake -DCMAKE_TOOLCHAIN_FILE=./CMake/ToolchainLinux-x86.txt -DCMAKE_BUILD_TYPE=Release -S . -B ./Build/Linux-x86
cmake -DCMAKE_TOOLCHAIN_FILE=./CMake/ToolchainLinux-x64.txt -DCMAKE_BUILD_TYPE=Release -S . -B ./Build/Linux-x64

