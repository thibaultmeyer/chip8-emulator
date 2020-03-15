#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "chip8.h"

static inline void chip8_initialize_mask(void) {
    gl_chip8_mask.mask[0]  = 0x0000; /* 0NNN */
    gl_chip8_mask.id[0]    = 0x0FFF;
    gl_chip8_mask.mask[1]  = 0xFFFF; /* 00E0 */
    gl_chip8_mask.id[1]    = 0x00E0;
    gl_chip8_mask.mask[2]  = 0xFFFF; /* 00EE */
    gl_chip8_mask.id[2]    = 0x00EE;
    gl_chip8_mask.mask[3]  = 0xF000; /* 1NNN */
    gl_chip8_mask.id[3]    = 0x1000;
    gl_chip8_mask.mask[4]  = 0xF000; /* 2NNN */
    gl_chip8_mask.id[4]    = 0x2000;
    gl_chip8_mask.mask[5]  = 0xF000; /* 3XKK */
    gl_chip8_mask.id[5]    = 0x3000;
    gl_chip8_mask.mask[6]  = 0xF000; /* 4XKK */
    gl_chip8_mask.id[6]    = 0x4000;
    gl_chip8_mask.mask[7]  = 0xF00F; /* 5XY0 */
    gl_chip8_mask.id[7]    = 0x5000;
    gl_chip8_mask.mask[8]  = 0xF000; /* 6XKK */
    gl_chip8_mask.id[8]    = 0x6000;
    gl_chip8_mask.mask[9]  = 0xF000; /* 7XKK */
    gl_chip8_mask.id[9]    = 0x7000;
    gl_chip8_mask.mask[10] = 0xF00F; /* 8XY0 */
    gl_chip8_mask.id[10]   = 0x8000;
    gl_chip8_mask.mask[11] = 0xF00F; /* 8XY1 */
    gl_chip8_mask.id[11]   = 0x8001;
    gl_chip8_mask.mask[12] = 0xF00F; /* 8XY2 */
    gl_chip8_mask.id[12]   = 0x8002;
    gl_chip8_mask.mask[13] = 0xF00F; /* BXY3 */
    gl_chip8_mask.id[13]   = 0x8003;
    gl_chip8_mask.mask[14] = 0xF00F; /* 8XY4 */
    gl_chip8_mask.id[14]   = 0x8004;
    gl_chip8_mask.mask[15] = 0xF00F; /* 8XY5 */
    gl_chip8_mask.id[15]   = 0x8005;
    gl_chip8_mask.mask[16] = 0xF00F; /* 8XY6 */
    gl_chip8_mask.id[16]   = 0x8006;
    gl_chip8_mask.mask[17] = 0xF00F; /* 8XY7 */
    gl_chip8_mask.id[17]   = 0x8007;
    gl_chip8_mask.mask[18] = 0xF00F; /* 8XYE */
    gl_chip8_mask.id[18]   = 0x800E;
    gl_chip8_mask.mask[19] = 0xF00F; /* 9XY0 */
    gl_chip8_mask.id[19]   = 0x9000;
    gl_chip8_mask.mask[20] = 0xF000; /* ANNN */
    gl_chip8_mask.id[20]   = 0xA000;
    gl_chip8_mask.mask[21] = 0xF000; /* BNNN */
    gl_chip8_mask.id[21]   = 0xB000;
    gl_chip8_mask.mask[22] = 0xF000; /* CXKK */
    gl_chip8_mask.id[22]   = 0xC000;
    gl_chip8_mask.mask[23] = 0xF000; /* DXYN */
    gl_chip8_mask.id[23]   = 0xD000;
    gl_chip8_mask.mask[24] = 0xF0FF; /* EX9E */
    gl_chip8_mask.id[24]   = 0xE09E;
    gl_chip8_mask.mask[25] = 0xF0FF; /* EXA1 */
    gl_chip8_mask.id[25]   = 0xE0A1;
    gl_chip8_mask.mask[26] = 0xF0FF; /* FX07 */
    gl_chip8_mask.id[26]   = 0xF007;
    gl_chip8_mask.mask[27] = 0xF0FF; /* FX0A */
    gl_chip8_mask.id[27]   = 0xF00A;
    gl_chip8_mask.mask[28] = 0xF0FF; /* FX15 */
    gl_chip8_mask.id[28]   = 0xF015;
    gl_chip8_mask.mask[29] = 0xF0FF; /* FX18 */
    gl_chip8_mask.id[29]   = 0xF018;
    gl_chip8_mask.mask[30] = 0xF0FF; /* FX1E */
    gl_chip8_mask.id[30]   = 0xF01E;
    gl_chip8_mask.mask[31] = 0xF0FF; /* FX29 */
    gl_chip8_mask.id[31]   = 0xF029;
    gl_chip8_mask.mask[32] = 0xF0FF; /* FX33 */
    gl_chip8_mask.id[32]   = 0xF033;
    gl_chip8_mask.mask[33] = 0xF0FF; /* FX55 */
    gl_chip8_mask.id[33]   = 0xF055;
    gl_chip8_mask.mask[34] = 0xF0FF; /* FX65 */
    gl_chip8_mask.id[34]   = 0xF065;
}

static inline void chip8_initialize_font(s_chip8_cpu *cpu) {
    if (cpu) {
        /*
        ** Memory from 0 to 512 contain 0-9 A-F
        **
        **  1 1 1 1 0 0 0 0    0xF0
        **  1 0 0 1 0 0 0 0    0x90
        **  1 0 0 1 0 0 0 0    0x90      0
        **  1 0 0 1 0 0 0 0    0x90
        **  1 1 1 1 0 0 0 0    0xF0
        */
        cpu->memory[0] = 0xF0; /* 0 */
        cpu->memory[1] = 0x90;
        cpu->memory[2] = 0x90;
        cpu->memory[3] = 0x90;
        cpu->memory[4] = 0xF0;

        cpu->memory[5] = 0x20; /* 1 */
        cpu->memory[6] = 0x60;
        cpu->memory[7] = 0x20;
        cpu->memory[8] = 0x20;
        cpu->memory[9] = 0x70;

        cpu->memory[10] = 0xF0; /* 2 */
        cpu->memory[11] = 0x10;
        cpu->memory[12] = 0xF0;
        cpu->memory[13] = 0x80;
        cpu->memory[14] = 0xF0;

        cpu->memory[15] = 0xF0; /* 3 */
        cpu->memory[16] = 0x10;
        cpu->memory[17] = 0x70;
        cpu->memory[18] = 0x10;
        cpu->memory[19] = 0xF0;

        cpu->memory[20] = 0x20; /* 4 */
        cpu->memory[21] = 0x40;
        cpu->memory[22] = 0xA0;
        cpu->memory[23] = 0xF0;
        cpu->memory[24] = 0x20;

        cpu->memory[25] = 0xF0; /* 5 */
        cpu->memory[26] = 0x80;
        cpu->memory[27] = 0xF0;
        cpu->memory[28] = 0x10;
        cpu->memory[29] = 0xF0;

        cpu->memory[30] = 0xF0; /* 6 */
        cpu->memory[31] = 0x80;
        cpu->memory[32] = 0xF0;
        cpu->memory[33] = 0x90;
        cpu->memory[34] = 0xF0;

        cpu->memory[35] = 0xF0; /* 7 */
        cpu->memory[36] = 0x20;
        cpu->memory[37] = 0x40;
        cpu->memory[38] = 0x40;
        cpu->memory[39] = 0x40;

        cpu->memory[40] = 0xF0; /* 8 */
        cpu->memory[41] = 0x90;
        cpu->memory[42] = 0xF0;
        cpu->memory[43] = 0x90;
        cpu->memory[44] = 0xF0;

        cpu->memory[45] = 0xF0; /* 9 */
        cpu->memory[46] = 0x90;
        cpu->memory[47] = 0xF0;
        cpu->memory[48] = 0x10;
        cpu->memory[49] = 0xF0;

        cpu->memory[50] = 0xF0; /* A */
        cpu->memory[51] = 0x90;
        cpu->memory[52] = 0xF0;
        cpu->memory[53] = 0x90;
        cpu->memory[54] = 0x90;

        cpu->memory[55] = 0xE0; /* B */
        cpu->memory[56] = 0x90;
        cpu->memory[57] = 0xE0;
        cpu->memory[58] = 0x90;
        cpu->memory[59] = 0xE0;

        cpu->memory[60] = 0xF0; /* C */
        cpu->memory[61] = 0x80;
        cpu->memory[62] = 0x80;
        cpu->memory[63] = 0x80;
        cpu->memory[64] = 0xF0;

        cpu->memory[65] = 0xE0; /* D */
        cpu->memory[66] = 0x90;
        cpu->memory[67] = 0x90;
        cpu->memory[68] = 0x90;
        cpu->memory[69] = 0xE0;

        cpu->memory[70] = 0xF0; /* E */
        cpu->memory[71] = 0x80;
        cpu->memory[72] = 0xF0;
        cpu->memory[73] = 0x80;
        cpu->memory[74] = 0xF0;

        cpu->memory[75] = 0xF0; /* F */
        cpu->memory[76] = 0x80;
        cpu->memory[77] = 0xF0;
        cpu->memory[78] = 0x80;
        cpu->memory[79] = 0x80;
    }
}

void chip8_initialize(s_chip8_cpu *cpu, void (*fun_opcode_error)(void), void (*fun_play_sound)(void)) {
    if (cpu) {
        memset(cpu->memory, 0, CHIP8_MEMORY_SIZE * sizeof(uint8_t));
        memset(cpu->video, 0, CHIP8_VIDEO_SIZE * sizeof(uint8_t));
        memset(cpu->reg, 0, CHIP8_NB_REGISTER * sizeof(uint8_t));
        memset(cpu->mem_jump, 0, CHIP8_MAX_JUMP * sizeof(uint16_t));
        memset(cpu->keyboard, 0, CHIP8_KEYBOARD_MAX_KEY * sizeof(uint8_t));

        cpu->i                = 0;
        cpu->nb_jump          = 0;
        cpu->counter_sync     = 0;
        cpu->counter_sound    = 0;
        cpu->pc               = CHIP8_MEMORY_ROM_START;
        cpu->current_opcode   = 0x00;
        cpu->draw             = 0;
        cpu->fun_opcode_error = fun_opcode_error;
        cpu->fun_play_sound   = fun_play_sound;

        chip8_initialize_font(cpu);
        chip8_initialize_mask();
        srand(time(0) + getpid());
    }
}
