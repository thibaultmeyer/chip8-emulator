#include "chip8.h"

inline void chip8_instruction_dxyn(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3) {
    uint8_t x      = 0;
    uint8_t y      = 0;
    uint8_t k      = 0;
    uint8_t j      = 0;
    uint8_t coding = 0;
    uint8_t shift  = 0;

    cpu->reg[0xF] = 0x00;
    for (k = 0; k < b1; ++k) {
        coding = cpu->memory[cpu->i + k];
        y      = (cpu->reg[b2] + k) % CHIP8_VIDEO_DIM_HEIGHT;
        for (j = 0, shift = 7; j < 8; ++j, --shift) {
            x = (cpu->reg[b3] + j) % CHIP8_VIDEO_DIM_WIDTH;
            if (((coding) & (0x1 << shift)) != 0) {
                if (cpu->video[y][x] == 1) {
                    cpu->video[y][x] = 0;
                    cpu->reg[0xF]    = 1;
                } else
                    cpu->video[y][x] = 1;
            }
        }
    }
}
