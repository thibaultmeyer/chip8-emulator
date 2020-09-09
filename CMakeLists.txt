CMAKE_MINIMUM_REQUIRED(VERSION 3.10.2)
PROJECT(chip8-emulator C)

# Settings
SET(CMAKE_C_STANDARD 99)
SET(CMAKE_C_FLAGS "-Wall")
SET(CMAKE_CXX_FLAGS_DEBUG "-g")
SET(CMAKE_CXX_FLAGS_RELEASE "-O2")

# Configure windres: don't use flags
IF (MINGW)
    SET(CMAKE_RC_COMPILER_INIT windres)
    ENABLE_LANGUAGE(RC)
    SET(CMAKE_RC_COMPILE_OBJECT
            "<CMAKE_RC_COMPILER> -O coff <DEFINES> -i <SOURCE> -o <OBJECT>")
ENDIF (MINGW)

# Display build type
IF (NOT CMAKE_BUILD_TYPE)
    MESSAGE(STATUS "Build type: -")
ELSE (NOT CMAKE_BUILD_TYPE)
    MESSAGE(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
ENDIF (NOT CMAKE_BUILD_TYPE)

# Use the package PkgConfig to detect GTK+ headers/library files
FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)
PKG_CHECK_MODULES(OPENAL REQUIRED openal)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS} ${OPENAL_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS} ${OPENAL_LIBRARY_DIRS})

# Add other flags to the compiler
ADD_DEFINITIONS(${GTK3_CFLAGS_OTHER})

# Files
ADD_EXECUTABLE(
        chip8-emulator WIN32
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
        src/chip8/chip8_state_load.c
        src/chip8/chip8_state_save.c
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
        src/version.h
        src/gui/gui_chip8_callback_opcode_error.c
        src/gui/gui_chip8_callback_play_sound.c
        src/gui/gui_emulation_timer_start.c
        src/gui/gui_emulation_timer_stop.c
        src/gui/gui_image_load_from_memory_scale.c
        src/gui/gui_image_load_rom_dark.h
        src/gui/gui_image_load_rom_light.h
        src/gui/gui_image_logo.h
        src/gui/gui_image_more_dark.h
        src/gui/gui_image_more_light.h
        src/gui/gui_image_reset_cpu_dark.h
        src/gui/gui_image_reset_cpu_light.h
        src/gui/gui_main_callback_app_activate.c
        src/gui/gui_main_callback_chip8_tick_counter.c
        src/gui/gui_main_callback_chip8_tick_cpu.c
        src/gui/gui_main_callback_drawing_area_draw.c
        src/gui/gui_main_callback_drawing_area_new_size.c
        src/gui/gui_main_callback_header_bar_load_rom.c
        src/gui/gui_main_callback_header_bar_reset_cpu.c
        src/gui/gui_main_callback_menu_more_about.c
        src/gui/gui_main_callback_menu_more_settings.c
        src/gui/gui_main_callback_menu_state_load.c
        src/gui/gui_main_callback_menu_state_save.c
        src/gui/gui_main_callback_window_destroy.c
        src/gui/gui_main_callback_window_key.c
        src/gui/gui_main_initialize_main_header_bar.c
        src/gui/gui_main_initialize_main_window.c
        src/gui/gui_settings_callback_colorbutton_background.c
        src/gui/gui_settings_callback_colorbutton_foreground.c
        src/gui/gui_settings_callback_combobox_cpu_frequency.c
        src/gui/gui_settings_callback_btn_input_key.c
        src/gui/gui_settings_callback_window_destroy.c
        src/gui/gui_settings_init.c
        src/gui/gui_settings_init_color_background.c
        src/gui/gui_settings_init_color_foreground.c
        src/gui/gui_settings_init_cpu_frequency.c
        src/gui/gui_settings_init_display_mode.c
        src/gui/gui_settings_init_key_binding.c
        src/gui/gui_toolbox_create_storage_directory.c
        src/gui/gui_toolbox_get_storage_file_path.c
        src/gui/gui_toolbox_is_gtk_dark_theme_enabled
        src/gui/gui_toolbox_load_settings_from_file_or_default.c
        src/gui/gui_toolbox_save_settings_to_file.c
        src/sound/sound_destroy.c
        src/sound/sound_initialize.c
        src/sound/sound_play_buzzer.c
        chip8-emulator.rc)

# Link the target to the GTK+ libraries
TARGET_LINK_LIBRARIES(chip8-emulator -lm ${GTK3_LIBRARIES} ${OPENAL_LIBRARIES})

# Install
INSTALL(TARGETS chip8-emulator DESTINATION bin)
