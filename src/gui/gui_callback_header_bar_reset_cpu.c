#include "gui.h"

void gui_callback_header_bar_reset_cpu(GtkApplication *app, gpointer user_data) {
    if (gl_gui_components.chip8_cpu) {
        // Remove current CPU timer
        g_source_remove(gl_gui_components.gtk_timer_cpu);

        // Reset CPU
        chip8_reset(gl_gui_components.chip8_cpu);

        // Start a new CPU timer
        gl_gui_components.gtk_timer_cpu = g_timeout_add(1000 / gl_gui_components.chip8_frequency,
                                                        gui_callback_chip8_tick,
                                                        0);
    }
}
