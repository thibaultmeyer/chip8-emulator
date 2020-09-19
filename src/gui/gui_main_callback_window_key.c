#include "gui.h"

gboolean gui_main_callback_window_key(GtkWidget *widget, GdkEventKey *event, gpointer user_data) {
    (void) widget;     // Unused parameter
    (void) user_data;  // Unused parameter

    if (gl_gui_components.chip8_cpu) {
        uint8_t value = event->type == GDK_KEY_PRESS ? 1 : 0;

        for (uint8_t idx = 0; idx < CHIP8_KEYBOARD_MAX_KEY; ++idx) {
            if (gl_gui_settings.keybinding[idx] == event->keyval) {
                gl_gui_components.chip8_cpu->keyboard[idx] = value;
            }
        }
    }

    return FALSE;
}
