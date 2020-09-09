#include "gui.h"

void gui_main_callback_window_destroy(GtkWidget *widget, gpointer data) {
    (void) data;  // Unused parameter

    // Stop emulation
    gui_emulation_timer_stop();

    // Free allocated global variables
    gtk_widget_destroy(gl_gui_components.gtk_header_bar);
    gtk_widget_destroy(gl_gui_components.gtk_drawing_area);
    gtk_widget_destroy(widget); // gl_gui_components.gtk_window

    // Free CPU
    chip8_free_cpu(gl_gui_components.chip8_cpu);
}
