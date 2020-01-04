#include "chip8.h"

inline void chip8_instruction_00ee(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3) {
    if (cpu->nb_jump > 0) {
        --cpu->nb_jump;
        cpu->pc = cpu->mem_jump[cpu->nb_jump];
    }
}
