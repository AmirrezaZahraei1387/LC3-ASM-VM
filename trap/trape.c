//
// Created by KAVOSH on 10/22/2023.
//
#include <stdint.h>

#include "trape.h"
#include "trapin.h"
#include "../data/regisiter.h"
#include "../data/trapr.h"


void trap_exe(uint16_t instr, int* running){
reg[R_R7] = reg[R_PC];

switch (instr & 0xFF)
{
    case TRAP_GETC:
        GETC();
    break;
    case TRAP_OUT:
        OUT();
    break;
    case TRAP_PUTS:
        PUTS();
    break;
    case TRAP_IN:
        IN();
    break;
    case TRAP_PUTSP:
        PUTSP();
    break;
    case TRAP_HALT:
        HALT(running);
    break;
}
}