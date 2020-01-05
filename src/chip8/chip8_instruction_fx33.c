#include "chip8.h"

inline void chip8_instruction_fx33(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3) {
    cpu->memory[cpu->i]     = (cpu->reg[b3] - cpu->reg[b3] % 100) / 100;
    cpu->memory[cpu->i + 1] = (((cpu->reg[b3] - cpu->reg[b3] % 10) / 10) % 10);
    cpu->memory[cpu->i + 2] = cpu->reg[b3] - cpu->memory[cpu->i] * 100 - cpu->memory[cpu->i + 1] * 10;
}
