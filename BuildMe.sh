#!/bin/bash
cmake --build Build/Linux-x86
cp ./Build/Linux-x86/Platform/Port/TCP/libTrioMotion_UnifiedApi-TCP-x86.so ./Build/Output/.

cmake --build Build/Linux-x64
cp ./Build/Linux-x64/Platform/Port/TCP/libTrioMotion_UnifiedApi-TCP-x64.so ./Build/Output/.

