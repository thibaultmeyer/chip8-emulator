#include <string.h>
#include "chip8.h"

inline void chip8_instruction_00e0(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3) {
    (void) b1;  // Unused parameter
    (void) b2;  // Unused parameter
    (void) b3;  // Unused parameter

    memset(cpu->video, 0, CHIP8_VIDEO_SIZE);
    cpu->draw = 1;
}
