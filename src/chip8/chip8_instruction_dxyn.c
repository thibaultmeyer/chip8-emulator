#include "chip8.h"

inline void chip8_instruction_dxyn(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3) {
    uint8_t x = 0;
    uint8_t y = 0;
    uint8_t k = 0;
    uint8_t j = 0;
    uint8_t c = 0;
    uint8_t d = 0;

    cpu->reg[0xF] = 0x00;
    for (k = 0; k < b1; ++k) {
        c = cpu->memory[cpu->i + k];
        y = (cpu->reg[b2] + k) % CHIP8_VIDEO_DIM_HEIGHT;

        for (j = 0, d = 7; j < 8; ++j, --d) {
            x = (cpu->reg[b3] + j) % CHIP8_VIDEO_DIM_WIDTH;
            if (((c) & (0x1 << d)) != 0) {
                uint16_t oneDimensionIdx = x * y;
                if (cpu->video[oneDimensionIdx] == 1) {
                    cpu->video[oneDimensionIdx] = 0;
                    cpu->reg[0xF]               = 1;
                } else
                    cpu->video[oneDimensionIdx] = 1;
            }
        }
    }
}
