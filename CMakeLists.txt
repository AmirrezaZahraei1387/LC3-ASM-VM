cmake_minimum_required(VERSION 3.23)
project(LC3_ASM_VM C)

set(CMAKE_C_STANDARD 23)

add_executable(LC3_ASM_VM main.c data/memory.h data/regisiter.h data/opcodes.h data/confl.h instr/instr.c instr/instr.h spec/spec.c spec/spec.h data/trapr.h trap/trape.c trap/trapin.c trap/trape.h trap/trapin.h loader/loader.h loader/loader.c)
