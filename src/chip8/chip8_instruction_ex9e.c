#include "chip8.h"

inline void chip8_instruction_ex9e(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3) {
    if (cpu->keyboard[cpu->reg[b3]] == 1) {
        cpu->pc += 2;
    }
}
