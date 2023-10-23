cmake_minimum_required(VERSION 3.23)
project(LC3_ASM_VM C)

set(CMAKE_C_STANDARD 23)

add_executable(LC3_ASM_VM main.c data/memory.h data/regisiter.h data/opcodes.h data/confl.h)
