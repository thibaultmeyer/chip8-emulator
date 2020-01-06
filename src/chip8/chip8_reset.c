#include <string.h>
#include "chip8.h"

void chip8_reset(s_chip8_cpu *cpu) {
    if (cpu) {
        memset(cpu->memory, 0x00, CHIP8_MEMORY_SIZE);
        memset(cpu->video, 0x00, CHIP8_VIDEO_SIZE);
        memset(cpu->reg, 0x00, CHIP8_NB_REGISTER);
        memset(cpu->mem_jump, 0x00, CHIP8_MAX_JUMP);
        memset(cpu->keyboard, 0x00, CHIP8_KEYBOARD_MAX_KEY);

        cpu->i              = 0;
        cpu->nb_jump        = 0;
        cpu->counter_sync   = 0;
        cpu->counter_sound  = 0;
        cpu->pc             = CHIP8_MEMORY_ROM_START;
        cpu->current_opcode = 0x00;
    }
}
