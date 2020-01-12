#include "chip8.h"

inline void chip8_instruction_dxyn(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3) {
    uint8_t x;
    uint8_t y;
    uint8_t yline;
    uint8_t xline;
    uint8_t coding;
    uint8_t shift;

    cpu->reg[0xF] = 0x00;
    for (yline = 0; yline < b1; ++yline) {
        coding = cpu->memory[cpu->i + yline];
        y      = (cpu->reg[b2] + yline) % CHIP8_VIDEO_DIM_HEIGHT;

        for (xline = 0, shift = 7; xline < 8; ++xline, --shift) {
            x = (cpu->reg[b3] + xline) % CHIP8_VIDEO_DIM_WIDTH;

            if ((coding & (0x1 << shift)) != 0) {
                if (cpu->video[y][x] == 1) {
                    cpu->video[y][x] = 0;
                    cpu->reg[0xF]    = 1;
                } else {
                    cpu->video[y][x] = 1;
                }
            }
        }
    }

    // Not part of the real chip8 CPU. It is just a flag to
    // tell the GUI that it can redraw the display
    cpu->draw = 1;
}
