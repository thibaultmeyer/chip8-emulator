#include "chip8.h"

inline void chip8_instruction_5xy0(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3) {
    if (cpu->reg[b3] == cpu->reg[b2]) {
        cpu->pc += 2;
    }
}
