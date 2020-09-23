#include "gui.h"

gboolean gui_main_callback_chip8_tick_counter(void) {
    if (gl_gui_components.chip8_cpu) {
        chip8_update_counter(gl_gui_components.chip8_cpu);
    }

    return (TRUE);
}
