#include "chip8.h"

inline void chip8_instruction_fx0a(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3) {
    for (uint8_t idx = 0; idx < CHIP8_KEYBOARD_MAX_KEY; ++idx) {
        if (cpu->keyboard[idx] == 1) {
            cpu->reg[b3] = idx;
            return;
        }
    }

    cpu->pc -= 2;
}
