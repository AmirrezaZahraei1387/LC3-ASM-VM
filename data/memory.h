//
// Created by KAVOSH on 10/22/2023.
//
#ifndef LC3_ASM_VM_MEMORY_H
#define LC3_ASM_VM_MEMORY_H
#include <stdint.h>

#define MEMORY_MAX (1 << 16)
extern uint16_t memory[MEMORY_MAX];  // 65536 locations
#endif //LC3_ASM_VM_MEMORY_H
