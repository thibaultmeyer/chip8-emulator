#include "gui.h"

void gui_emulation_timer_stop() {
    // Stop "CPU" timer
    if (gl_gui_components.gtk_timer_cpu > 0) {
        g_source_remove(gl_gui_components.gtk_timer_cpu);
        gl_gui_components.gtk_timer_cpu = 0;
    }

    // Stop "counter" timer
    if (gl_gui_components.gtk_timer_counter > 0) {
        g_source_remove(gl_gui_components.gtk_timer_counter);
        gl_gui_components.gtk_timer_counter = 0;
    }
}
