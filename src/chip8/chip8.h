#ifndef CHIP8EMU_CHIP8_H
# define CHIP8EMU_CHIP8_H
# define CHIP8_MEMORY_SIZE      4096
# define CHIP8_NB_REGISTER      16
# define CHIP8_MAX_JUMP         16
# define CHIP8_NB_OPCODE        35
# define CHIP8_MEMORY_ROM_START 512
# define CHIP8_KEYBOARD_MAX_KEY 16

# include <unitypes.h>

typedef struct s_chip8_cpu {
    uint8_t  memory[CHIP8_MEMORY_SIZE];
    uint8_t  reg[CHIP8_NB_REGISTER];
    uint16_t i;
    uint16_t mem_jump[CHIP8_MAX_JUMP];
    uint8_t  nb_jump;
    uint8_t  counter_sync;
    uint8_t  counter_sound;
    uint16_t pc;
    uint16_t current_opcode;
    uint8_t  keyboard[CHIP8_KEYBOARD_MAX_KEY];
} s_chip8_cpu;

typedef struct s_chip8_mask {
    uint16_t mask[CHIP8_NB_OPCODE];
    uint16_t id[CHIP8_NB_OPCODE];
} s_chip8_mask;

s_chip8_mask gl_chip8_mask;

/**
 *
 * @param cpu Handle to the chip8 CPU instance
 */
void chip8_do_next(s_chip8_cpu *cpu);

/**
 *
 * @param opcode
 * @return
 */
uint8_t get_offset_instruction(uint16_t opcode);

/**
 *
 * @param cpu Handle to the chip8 CPU instance
 * @return
 */
uint16_t chip8_get_opcode(s_chip8_cpu *cpu);

/**
 *
 * @param cpu Handle to the chip8 CPU instance
 */
void chip8_initialize(s_chip8_cpu *cpu);

/**
 *
 * @param cpu Handle to the chip8 CPU instance
 */
void chip8_reset(s_chip8_cpu *cpu);

/**
 *
 * @param cpu Handle to the chip8 CPU instance
 */
void chip8_update_counter(s_chip8_cpu *cpu);

/**
 * Call CDP1802 code at Address.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_0nnn(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Jump to address.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_1nnn(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Call subroutine at Addr (16 levels).
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_2nnn(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Clear display.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_00e0(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Return from subroutine (16 levels).
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_00ee(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Skip next instruction if VX == Byte.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_3xkk(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

#endif //CHIP8EMU_CHIP8_H
