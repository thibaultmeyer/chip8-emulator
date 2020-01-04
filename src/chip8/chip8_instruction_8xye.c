#include "chip8.h"

inline void chip8_instruction_8xye(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3) {
    cpu->reg[0xF] = cpu->reg[b3] >> 7;
    cpu->reg[b3]  = cpu->reg[b3] << 1;
}
