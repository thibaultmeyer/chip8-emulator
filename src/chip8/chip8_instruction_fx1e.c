#include "chip8.h"

inline void chip8_instruction_fx1e(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3) {
    (void) b1;  // Unused parameter
    (void) b2;  // Unused parameter

    if ((cpu->i + cpu->reg[b3]) > 0xFFF) {
        cpu->reg[0xF] = 1;
    } else {
        cpu->reg[0xF] = 0;
    }

    cpu->i += cpu->reg[b3];
}
