//
// Created by KAVOSH on 10/23/2023.
//

#ifndef LC3_ASM_VM_MEMAC_H
#define LC3_ASM_VM_MEMAC_H
#include <Windows.h>
#include <stdint.h>

void disable_input_buffering();

void restore_input_buffering();

uint16_t check_key();

void mem_write(uint16_t address, uint16_t val);

uint16_t mem_read(uint16_t address);

void handle_interrupt(int signal);

#endif //LC3_ASM_VM_MEMAC_H
