#include "gui.h"

void gui_main_callback_header_bar_reset_cpu(GtkButton *button, gpointer user_data) {
    (void) button;     // Unused parameter
    (void) user_data;  // Unused parameter

    if (gl_gui_components.chip8_cpu) {
        // Stop all emulation timers
        gui_emulation_timer_stop();

        // Reset CPU
        chip8_reset(gl_gui_components.chip8_cpu);

        // Start all emulation timers
        gui_emulation_timer_start();
    }
}
