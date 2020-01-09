#include "gui.h"

void gui_callback_header_bar_reset_cpu(GtkApplication *app, gpointer user_data) {
    if (gl_gui_components.chip8_cpu) {
        chip8_reset(gl_gui_components.chip8_cpu);
    }
}
