#include "chip8.h"

inline void chip8_instruction_fx15(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3) {
    (void) b1;  // Unused parameter
    (void) b2;  // Unused parameter

    cpu->counter_sync = cpu->reg[b3];
}
