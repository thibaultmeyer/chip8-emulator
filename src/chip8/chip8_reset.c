#include "chip8.h"

void chip8_reset(s_chip8_cpu *cpu) {
    if (cpu) {
        for (uint8_t i = 0; i < 16; i++) {
            cpu->reg[i]      = 0;
            cpu->mem_jump[i] = 0;
            cpu->keyboard[i] = 0;
        }
        cpu->pc            = CHIP8_MEMORY_ROM_START;
        cpu->nb_jump       = 0;
        cpu->counter_sync  = 0;
        cpu->counter_sound = 0;
        cpu->i             = 0;
    }
}
