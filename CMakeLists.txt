cmake_minimum_required(VERSION 3.15)
project(chip8emu C)

set(CMAKE_C_STANDARD 99)

add_executable(
        chip8emu
        src/main.c
        src/chip8/chip8.h
        src/chip8/chip8_do_next.c
        src/chip8/chip8_get_offset_instruction.c
        src/chip8/chip8_get_opcode.c
        src/chip8/chip8_initialize.c
        src/chip8/chip8_reset.c
        src/chip8/chip8_update_counter.c
        src/chip8/chip8_instruction_0nnn.c
        src/chip8/chip8_instruction_00e0.c
        src/chip8/chip8_instruction_1nnn.c
        src/chip8/chip8_instruction_2nnn.c
        src/chip8/chip8_instruction_00ee.c
        src/chip8/chip8_instruction_3xkk.c
        src/chip8/chip8_instruction_4xkk.c
        src/chip8/chip8_instruction_5xy0.c
        src/chip8/chip8_instruction_6xkk.c
        src/chip8/chip8_instruction_7xkk.c
        src/chip8/chip8_instruction_8xy0.c
        src/chip8/chip8_instruction_8xy1.c
        src/chip8/chip8_instruction_8xy2.c
        src/chip8/chip8_instruction_8xy3.c
        src/chip8/chip8_instruction_8xy4.c
        src/chip8/chip8_instruction_8xy5.c
        src/chip8/chip8_instruction_8xy6.c
        src/chip8/chip8_instruction_8xy7.c
        src/chip8/chip8_instruction_8xye.c
)
