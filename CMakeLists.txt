cmake_minimum_required(VERSION 3.18)
project(TrioMotion_UnifiedApi LANGUAGES C CXX CSharp)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

add_subdirectory(./Platform/Port/TCP)
