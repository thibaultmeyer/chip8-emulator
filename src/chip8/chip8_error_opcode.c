#include <stdio.h>
#include "chip8.h"

void chip8_error_opcode(s_chip8_cpu *cpu) {
    if (cpu) {
        if (cpu->fun_opcode_error) {
            cpu->fun_opcode_error();
        } else {
            uint16_t i = 0;

            printf("====== DEBUG LOG ======\n");
            printf("OPCODE : 0x%X\n", cpu->current_opcode);
            printf("PC     : %d\n", cpu->pc);
            printf("I      : %d\n", cpu->i);
            printf("NB JMP : %d\n", cpu->nb_jump);
            while (i <= 0xF) {
                if (cpu->reg[i] != 0)
                    printf("register[%d] 0x%X\n", i, cpu->reg[i]);
                ++i;
            }
            if (cpu->nb_jump > 0) {
                i = 0;
                while (i < cpu->nb_jump) {
                    printf("jump[%d] 0x%X\n", i, cpu->mem_jump[i]);
                    ++i;
                }
            }
            printf("\n=====================\n\n");
        }
    }
}
