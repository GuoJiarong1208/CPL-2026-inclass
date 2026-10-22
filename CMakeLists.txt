cmake_minimum_required(VERSION 3.16)
project(c_input_course LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_executable(tokens tokens.c)
add_executable(emit_numbers emit_numbers.c)
add_executable(scores scores.c)
add_executable(fopen_demo fopen_demo.c)
add_executable(freopen_demo freopen_demo.c)
add_executable(clion_demo clion_demo.c)
add_executable(present_demo present_demo.c)

