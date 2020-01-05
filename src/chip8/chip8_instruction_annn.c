#include "chip8.h"

inline void chip8_instruction_annn(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3) {
    cpu->i = (b3 << 8) + (b2 << 4) + b1;
}
