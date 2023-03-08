#!/bin/bash
cmake -DCMAKE_TOOLCHAIN_FILE=./CMake/ToolchainLinux-x86.txt -DCMAKE_BUILD_TYPE=Release -S . -B ./Build/Linux-x86
cmake --build Build/Linux-x86
