#include "chip8.h"

inline void chip8_instruction_8xy4(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3) {
    if ((cpu->reg[b3] + cpu->reg[b2]) > 0xFF) {
        cpu->reg[0xF] = 1;
    } else {
        cpu->reg[0xF] = 0;
    }

    cpu->reg[b3] += cpu->reg[b2];
}
