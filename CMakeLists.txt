cmake_minimum_required(VERSION 3.30)
project(projet_heros_xyz C)

set(CMAKE_C_STANDARD 11)

add_executable(projet_heros_xyz main.c
        lecture.c
        lecture.h)
