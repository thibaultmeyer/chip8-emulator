#include "gui.h"

gboolean gui_main_callback_chip8_tick_cpu() {
    if (gl_gui_components.chip8_cpu) {
        chip8_do_next(gl_gui_components.chip8_cpu);

        if (gl_gui_components.chip8_cpu->draw == 1) {
            gtk_widget_queue_draw(gl_gui_components.gtk_drawing_area);
            gl_gui_components.chip8_cpu->draw = 0;
        }
    }

    return TRUE;
}
