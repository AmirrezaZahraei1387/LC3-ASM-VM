#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "memmap/memac.h"
#include "loader/loader.h"
#include "data/regisiter.h"
#include "data/opcodes.h"
#include "data/confl.h"
#include "trap/trape.h"
#include "instr/instr.h"

int main(int argc, const char* argv[]) {
    if (argc < 2)
    {
        /* show usage string */
        printf("lc3 [image-file1] ...\n");
        exit(2);
    }

    for (int j = 1; j < argc; ++j)
    {
        if (!read_image(argv[j]))
        {
            printf("failed to load image: %s\n", argv[j]);
            exit(1);
        }
    }

    signal(SIGINT, handle_interrupt);
    disable_input_buffering();

    /* since exactly one condition flag should be set at any given time, set the Z flag */
    reg[R_COND] = FL_ZRO;
    /* set the PC to starting position */
    /* 0x3000 is the default */
    enum { PC_START = 0x3000 };
    reg[R_PC] = PC_START;

    int running = 1;

    while (running)
    {
        /* FETCH */
        uint16_t instr = mem_read(reg[R_PC]++);
        uint16_t op = instr >> 12;

        switch (op)
        {
            case OP_ADD:
                ADD(instr);
                break;
            case OP_AND:
                AND(instr);
                break;
            case OP_NOT:
                NOT(instr);
                break;
            case OP_BR:
                BRANCH(instr);
                break;
            case OP_JMP:
                JUMP(instr);
                break;
            case OP_JSR:
                JUMP_REG(instr);
                break;
            case OP_LD:
                LOAD(instr);
                break;
            case OP_LDI:
                LOAD_IN(instr);
                break;
            case OP_LDR:
                LOAD_REG(instr);
                break;
            case OP_LEA:
                LOAD_EF_MEM(instr);
                break;
            case OP_ST:
                STORE(instr);
                break;
            case OP_STI:
                STORE_IN(instr);
                break;
            case OP_STR:
                STORE_REG(instr);
                break;
            case OP_TRAP:
                trap_exe(instr, &running);
                break;
            case OP_RES:
            case OP_RTI:
            default:
                abort();
        }
    }

    restore_input_buffering();
    return 0;
}
