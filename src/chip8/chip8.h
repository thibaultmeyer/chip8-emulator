#ifndef CHIP8EMU_CHIP8_H
# define CHIP8EMU_CHIP8_H

# include <stdint.h>

# define CHIP8_MEMORY_SIZE      4096
# define CHIP8_VIDEO_DIM_WIDTH  64
# define CHIP8_VIDEO_DIM_HEIGHT 32
# define CHIP8_VIDEO_SIZE       CHIP8_VIDEO_DIM_WIDTH * CHIP8_VIDEO_DIM_HEIGHT
# define CHIP8_NB_REGISTER      16
# define CHIP8_MAX_JUMP         16
# define CHIP8_NB_OPCODE        35
# define CHIP8_MEMORY_ROM_START 512
# define CHIP8_KEYBOARD_MAX_KEY 16

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
    uint8_t  video[CHIP8_VIDEO_DIM_HEIGHT][CHIP8_VIDEO_DIM_WIDTH];
    uint8_t  draw;

    void (*fun_opcode_error)(void);

    void (*fun_play_sound)(void);
} s_chip8_cpu;

typedef struct s_chip8_mask {
    uint16_t mask[CHIP8_NB_OPCODE];
    uint16_t id[CHIP8_NB_OPCODE];
} s_chip8_mask;

typedef enum e_loadrom_status {
    LOAD_ROM_STATUS_SUCCESS                = 0,
    LOAD_ROM_STATUS_ERROR_NOT_A_VALID_FILE = 1,
    LOAD_ROM_STATUS_ERROR_FILE_TOO_BIG     = 2,
    LOAD_ROM_STATUS_ERROR_CANT_OPEN_FILE   = 3,
    LOAD_ROM_STATUS_ERROR_READ_ERROR       = 4,
} e_loadrom_status;

typedef enum e_stateload_status {
    STATE_LOAD_STATUS_SUCCESS                = 0,
    STATE_LOAD_STATUS_ERROR_NOT_A_VALID_FILE = 1,
    STATE_LOAD_STATUS_ERROR_FILE_TOO_BIG     = 2,
    STATE_LOAD_STATUS_ERROR_CANT_OPEN_FILE   = 3,
    STATE_LOAD_STATUS_ERROR_READ_ERROR       = 4,
} e_stateload_status;

typedef enum e_statesave_status {
    STATE_SAVE_STATUS_SUCCESS                        = 0,
    STATE_SAVE_STATUS_ERROR_CANT_OPEN_FILE           = 1,
    STATE_SAVE_STATUS_ERROR_CANT_DELETE_PARTIAL_FILE = 2,
    STATE_SAVE_STATUS_ERROR_WRITE_ERROR              = 3,
} e_statesave_status;

extern const s_chip8_mask gl_chip8_mask;

/**
 * Execute current operation code and increment PC.
 *
 * @param cpu Handle to the chip8 CPU instance
 */
void chip8_do_next(s_chip8_cpu *cpu);

/**
 * Show operation code error.
 *
 * @param cpu Handle to the chip8 CPU instance
 */
void chip8_error_opcode(s_chip8_cpu *cpu);

/**
 * Free an existing chip8 CPU.
 *
 * @param cpu The chip8 CPU to free
 */
void chip8_free_cpu(s_chip8_cpu *cpu);

/**
 * Retrieves internal offset of the instruction.
 *
 * @param opcode The instruction operation code
 * @return
 */
uint8_t get_offset_instruction(uint16_t opcode);

/**
 * Retrieves the current operation code.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @return The current operation code
 */
uint16_t chip8_get_opcode(s_chip8_cpu *cpu);

/**
 * Initialize the Chip8 CPU.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param fun_opcode_error Optional operation code error callback
 * @param fun_play_sound Optional play sound callback
 */
void chip8_initialize(s_chip8_cpu *cpu, void (*fun_opcode_error)(void), void (*fun_play_sound)(void));

/**
 * Load ROM into memory.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param filename Name of the file to load
 * @return Status of the operation
 */
e_loadrom_status chip8_load_rom(s_chip8_cpu *cpu, const char *filename);

/**
 * Reset the Chip8 CPU (but keep the current rom loaded).
 *
 * @param cpu Handle to the chip8 CPU instance
 */
void chip8_reset(s_chip8_cpu *cpu);

/**
 * Loads state from file.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param filename Name of the file to load
 * @return Status of the operation
 */
e_stateload_status chip8_state_load(s_chip8_cpu *cpu, const char *filename);

/**
 * Saves given CPU state to file.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param filename Name of the file to save
 * @return Status of the operation
 */
e_statesave_status chip8_state_save(s_chip8_cpu *cpu, const char *filename);

/**
 * Update counter.
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

/**
 * Skip next instruction if VX != Byte.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_4xkk(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Skip next instruction if VX == VY.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_5xy0(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Set VX = Byte.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_6xkk(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Set VX = VX + Byte.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_7xkk(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Set VX = VY, VF updates.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_8xy0(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Set VX = VX | VY, VF updates.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_8xy1(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Set VX = VX & VY, VF updates.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_8xy2(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Set VX = VX ^ VY, VF updates.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_8xy3(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Set VX = VX + VY, VF = carry.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_8xy4(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Set VX = VX - VY, VF = !borrow.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_8xy5(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Set VX = VX >> 1, VF = carry.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_8xy6(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Set VX = VY - VX, VF = !borrow.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_8xy7(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Set VX = VX << 1, VF = carry.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_8xye(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Skip next instruction if VX != VY.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_9xy0(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Set I = Addr.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_annn(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Jump to Addr + V0.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_bnnn(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Set VX = random & Byte.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_cxkk(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Draw Nibble byte sprite stored at [I] at VX, VY. Set VF = collision.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_dxyn(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Skip next instruction if key VX down.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_ex9e(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Skip next instruction if key VX up.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_exa1(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Set VX = key, wait for keypress.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_fx0a(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Set VX = delaytimer.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_fx07(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Set delaytimer = VX.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_fx15(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Set soundtimer = VX.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_fx18(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Set I = I + VX.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_fx1e(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Point I to 5 byte numeric sprite for value in VX.
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_fx29(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Store BCD of VX in [I], [I+1], [I+2].
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_fx33(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Store V0 .. VX in [I] .. [I+X].
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_fx55(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

/**
 * Read V0 .. VX from [I] .. [I+X].
 *
 * @param cpu Handle to the chip8 CPU instance
 * @param b1 Opcode first byte
 * @param b2 Opcode second byte
 * @param b3 Opcode third byte
 */
void chip8_instruction_fx65(s_chip8_cpu *cpu, uint8_t b1, uint8_t b2, uint8_t b3);

#endif //CHIP8EMU_CHIP8_H
