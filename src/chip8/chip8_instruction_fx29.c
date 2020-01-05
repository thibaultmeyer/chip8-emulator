#include "chip8.h"

inline void chip8_instruction_fx29(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3) {
    cpu->i = 5 * cpu->reg[b3];
}
