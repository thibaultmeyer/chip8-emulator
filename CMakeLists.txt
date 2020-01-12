CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
PROJECT(chip8emu C)

SET(CMAKE_C_STANDARD 99)

# Use the package PkgConfig to detect GTK+ headers/library files
FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})

# Add other flags to the compiler
ADD_DEFINITIONS(${GTK3_CFLAGS_OTHER} ${SDL2_CFLAGS_OTHER})

# Files
ADD_EXECUTABLE(
        chip8emu
        src/main.c
        src/chip8/chip8.h
        src/chip8/chip8_do_next.c
        src/chip8/chip8_error_opcode.c
        src/chip8/chip8_free_cpu.c
        src/chip8/chip8_get_offset_instruction.c
        src/chip8/chip8_get_opcode.c
        src/chip8/chip8_initialize.c
        src/chip8/chip8_load_rom.c
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
        src/chip8/chip8_instruction_9xy0.c
        src/chip8/chip8_instruction_annn.c
        src/chip8/chip8_instruction_bnnn.c
        src/chip8/chip8_instruction_cxkk.c
        src/chip8/chip8_instruction_dxyn.c
        src/chip8/chip8_instruction_ex9e.c
        src/chip8/chip8_instruction_exa1.c
        src/chip8/chip8_instruction_fx0a.c
        src/chip8/chip8_instruction_fx1e.c
        src/chip8/chip8_instruction_fx07.c
        src/chip8/chip8_instruction_fx15.c
        src/chip8/chip8_instruction_fx18.c
        src/chip8/chip8_instruction_fx29.c
        src/chip8/chip8_instruction_fx33.c
        src/chip8/chip8_instruction_fx55.c
        src/chip8/chip8_instruction_fx65.c
        src/gui/gui.h
        src/gui/gui_icon_load_rom.h
        src/gui/gui_icon_reset_cpu.h
        src/gui/gui_icon_settings.h
        src/gui/gui_callback_app_activate.c
        src/gui/gui_callback_chip8_tick.c
        src/gui/gui_callback_drawing_area_draw.c
        src/gui/gui_callback_drawing_area_new_size.c
        src/gui/gui_callback_header_bar_load_rom.c
        src/gui/gui_callback_header_bar_reset_cpu.c
        src/gui/gui_callback_window_destroy.c
        src/gui/gui_initialize_header_bar.c
        src/gui/gui_initialize_main_window.c
)

# Link the target to the GTK+ libraries
TARGET_LINK_LIBRARIES(chip8emu ${GTK3_LIBRARIES})
