#include "chip8.h"

uint16_t chip8_get_opcode(s_chip8_cpu *cpu) {
    if (cpu) {
        return ((cpu->memory[cpu->pc] << 8) + cpu->memory[cpu->pc + 1]);
    }

    return (0);
}
