cmake_minimum_required(VERSION 3.18)
project(TrioMotion_UnifiedApi-TCP VERSION 0.0.0 LANGUAGES CXX)
include_directories(../..)

if (CMAKE_GENERATOR MATCHES "Visual Studio")
    # Do Visual Studio specific stuff
    add_library(TrioMotion_UnifiedApi-TCP-${CMAKE_GENERATOR_PLATFORM} SHARED dllmain.cpp TrioMotion_UnifiedApi-TCP.cpp)
else()
    # Other stuff
    add_library(TrioMotion_UnifiedApi-TCP-${CMAKE_SYSTEM_PROCESSOR} SHARED TrioMotion_UnifiedApi-TCP.cpp)
endif()
