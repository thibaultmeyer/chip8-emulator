#include "chip8.h"

inline void chip8_instruction_8xy7(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3) {
    (void) b1;  // Unused parameter

    if (cpu->reg[b2] < cpu->reg[b3]) {
        cpu->reg[0xF] = 0;
    } else {
        cpu->reg[0xF] = 1;
    }

    cpu->reg[b3] = cpu->reg[b2] - cpu->reg[b3];
}
