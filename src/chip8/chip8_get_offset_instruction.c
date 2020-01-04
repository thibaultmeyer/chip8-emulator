#include "chip8.h"

uint8_t get_offset_instruction(uint16_t opcode) {
    uint8_t offset = 0x00;

    while (offset < CHIP8_NB_OPCODE) {
        if ((gl_chip8_mask.mask[offset] & opcode) == gl_chip8_mask.id[offset]) {
            return (offset);
        }

        ++offset;
    }

    return (0xFF);
}
