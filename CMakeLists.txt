cmake_minimum_required(VERSION 3.18)
if (CMAKE_GENERATOR MATCHES "Visual Studio")
    # Do Visual Studio specific stuff
    project(TrioMotion_UnifiedApi LANGUAGES C CXX CSharp)
else()
    # Other stuff
    project(TrioMotion_UnifiedApi LANGUAGES C CXX)
endif()

add_subdirectory(./Platform/Port/TCP)
