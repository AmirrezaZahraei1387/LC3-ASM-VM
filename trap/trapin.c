//
// Created by KAVOSH on 10/22/2023.
//
#include <stdint.h>
#include <stdio.h>

#include "trapin.h"
#include "../data/memory.h"
#include "../spec/spec.h"
#include "../data/regisiter.h"

uint16_t memory[MEMORY_MAX];


void PUTS(){
    /* one char per word */
    uint16_t* c = memory + reg[R_R0];
    while (*c)
    {
        putc((char)*c, stdout);
        ++c;
    }
    fflush(stdout);
}

void GETC() {
    reg[R_R0] = (uint16_t) getchar();
    update_flags(R_R0);
}

void OUT(){
    putc((char)reg[R_R0], stdout);
    fflush(stdout);
}

void IN(){
    printf("Enter a character: ");
    char c = getchar();
    putc(c, stdout);
    fflush(stdout);
    reg[R_R0] = (uint16_t)c;
    update_flags(R_R0);
}

void PUTSP(){
/* one char per byte (two bytes per word)
   here we need to swap back to
   big endian format */
    uint16_t* c = memory + reg[R_R0];
    while (*c)
    {
        char char1 = (*c) & 0xFF;

        putc(char1, stdout);

        char char2 = (*c) >> 8;

        if (char2) putc(char2, stdout);
            ++c;
        }

        fflush(stdout);
}


void HALT(int* running){
    puts("HALT");
    fflush(stdout);
    *running = 0;
}

