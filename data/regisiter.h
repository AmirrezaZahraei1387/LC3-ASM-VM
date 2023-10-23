//
// Created by KAVOSH on 10/22/2023.
//
#ifndef LC3_ASM_VM_REGISITER_H
#define LC3_ASM_VM_REGISITER_H
#include <stdint.h>

enum
{
    R_R0 = 0,
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R6,
    R_R7,
    R_PC, // program counter
    R_COND,
    R_COUNT
};

uint16_t reg[R_COUNT];
#endif //LC3_ASM_VM_REGISITER_H
