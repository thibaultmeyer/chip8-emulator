#include "chip8.h"

inline void chip8_instruction_bnnn(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3) {
    cpu->pc = (b3 << 8) + (b2 << 4) + b1 + cpu->reg[0];
    cpu->pc -= 2;
}
