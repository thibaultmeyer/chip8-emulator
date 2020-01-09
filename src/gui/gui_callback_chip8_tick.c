#include "gui.h"

gboolean gui_callback_chip8_tick() {
    if (gl_gui_components.chip8_cpu) {
        chip8_do_next(gl_gui_components.chip8_cpu);
        gtk_widget_queue_draw(gl_gui_components.gtk_drawing_area);
    }

    return TRUE;
}
