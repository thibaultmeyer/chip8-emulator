#include "gui.h"

void gui_emulation_timer_start() {
    // Start "cpu" timer
    if (gl_gui_components.gtk_timer_cpu == 0) {
        gl_gui_components.gtk_timer_cpu = g_timeout_add(1000 / gl_gui_settings.cpu_frequency,
                                                        G_SOURCE_FUNC(gui_main_callback_chip8_tick_cpu),
                                                        NULL);
    }

    // Start "counter" timer (60 hz)
    if (gl_gui_components.gtk_timer_counter == 0) {
        gl_gui_components.gtk_timer_counter = g_timeout_add(1000 / 60,
                                                            G_SOURCE_FUNC(gui_main_callback_chip8_tick_counter),
                                                            NULL);
    }
}
