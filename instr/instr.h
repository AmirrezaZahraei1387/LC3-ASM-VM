//
// Created by KAVOSH on 10/22/2023.
//

#ifndef LC3_ASM_VM_INSTR_H
#define LC3_ASM_VM_INSTR_H
void ADD(uint16_t instr);

void NOT(uint16_t instr);

void  BRANCH(uint16_t instr);

void JUMP(uint16_t instr);

void JUMP_REG(uint16_t instr);

void LOAD(uint16_t instr);

void LOAD_REG(uint16_t instr);

void LOAD_EF_MEM(uint16_t instr);

void STORE(uint16_t instr);

void STORE_IN(uint16_t instr);

void STORE_REG(uint16_t instr);

void AND(uint16_t instr);

void LOAD_IN(uint16_t instr);
#endif //LC3_ASM_VM_INSTR_H

