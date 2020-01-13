#include "gui.h"

void gui_emulation_timer_start() {
    // Start "cpu" timer
    if (gl_gui_components.gtk_timer_cpu == 0) {
        gl_gui_components.gtk_timer_cpu = g_timeout_add(1000 / gl_gui_components.chip8_frequency,
                                                        gui_callback_chip8_tick_cpu,
                                                        0);
    }

    // Start "counter" timer (60 hz)
    if (gl_gui_components.gtk_timer_counter == 0) {
        gl_gui_components.gtk_timer_counter = g_timeout_add(1000 / 60,
                                                            gui_callback_chip8_tick_counter,
                                                            0);
    }
}
