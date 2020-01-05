#include "chip8.h"

inline void chip8_instruction_fx55(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3) {
    uint8_t i = 0;

    while (i <= b3) {
        cpu->memory[cpu->i + i] = cpu->reg[i];
        ++i;
    }
}
