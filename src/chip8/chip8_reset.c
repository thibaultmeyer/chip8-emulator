#include <string.h>
#include "chip8.h"

void chip8_reset(s_chip8_cpu *cpu) {
    if (cpu) {
        memset(cpu->video, 0, CHIP8_VIDEO_SIZE * sizeof(uint8_t));
        memset(cpu->reg, 0, CHIP8_NB_REGISTER * sizeof(uint8_t));
        memset(cpu->mem_jump, 0, CHIP8_MAX_JUMP * sizeof(uint16_t));
        memset(cpu->keyboard, 0, CHIP8_KEYBOARD_MAX_KEY * sizeof(uint8_t));

        cpu->i              = 0;
        cpu->nb_jump        = 0;
        cpu->counter_sync   = 0;
        cpu->counter_sound  = 0;
        cpu->pc             = CHIP8_MEMORY_ROM_START;
        cpu->current_opcode = 0x00;
        cpu->draw           = 1;
    }
}
