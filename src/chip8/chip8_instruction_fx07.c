#include "chip8.h"

inline void chip8_instruction_fx07(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3) {
    cpu->reg[b3] = cpu->counter_sync;
}
