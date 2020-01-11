#include "gui.h"

void gui_callback_window_destroy(GtkWidget *widget, gpointer data) {
    g_source_remove(gl_gui_components.gtk_timer_cpu);
}
