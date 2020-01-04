#include "chip8.h"

void chip8_do_next(s_chip8_cpu *cpu) {
    if (cpu) {
        cpu->current_opcode = chip8_get_opcode(cpu);

        uint8_t offset = get_offset_instruction(cpu->current_opcode);
        uint8_t b3     = (uint8_t) ((cpu->current_opcode & 0x0F00) >> 8);
        uint8_t b2     = (uint8_t) ((cpu->current_opcode & 0x00F0) >> 4);
        uint8_t b1     = (uint8_t) (cpu->current_opcode & 0x000F);

        switch (offset) {
            case 0:
                chip8_instruction_0nnn(cpu, b1, b2, b3);
                break;
            case 1:
                chip8_instruction_00e0(cpu, b1, b2, b3);
                break;
            case 2:
                chip8_instruction_00ee(cpu, b1, b2, b3);
                break;
            case 3:
                chip8_instruction_1nnn(cpu, b1, b2, b3);
                break;
            case 4:
                chip8_instruction_2nnn(cpu, b1, b2, b3);
                break;
            case 5:
                chip8_instruction_3xkk(cpu, b1, b2, b3);
                break;
        }
    }
}
