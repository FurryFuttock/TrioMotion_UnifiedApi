cmake_minimum_required(VERSION 3.18)
project(TrioMotion_UnifiedApi-TCP VERSION 0.0.0 LANGUAGES CXX)
include_directories(../..)

add_library(TrioMotion_UnifiedApi-TCP-${CMAKE_GENERATOR_PLATFORM} SHARED dllmain.cpp TrioMotion_UnifiedApi-TCP.cpp)
