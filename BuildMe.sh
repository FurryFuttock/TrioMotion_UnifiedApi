#!/bin/bash
git clean -x -d -f

cmake -DCMAKE_TOOLCHAIN_FILE=./CMake/ToolchainLinux-x86.txt -DCMAKE_BUILD_TYPE=Release -S . -B ./Build/Linux-x86
cmake --build Build/Linux-x86
cp ./Build/Linux-x86/Platform/Port/TCP/libTrioMotion_UnifiedApi-TCP-x86.so ./Build/Output/.

cmake -DCMAKE_TOOLCHAIN_FILE=./CMake/ToolchainLinux-x64.txt -DCMAKE_BUILD_TYPE=Release -S . -B ./Build/Linux-x64
cmake --build Build/Linux-x64
cp ./Build/Linux-x64/Platform/Port/TCP/libTrioMotion_UnifiedApi-TCP-x64.so ./Build/Output/.

