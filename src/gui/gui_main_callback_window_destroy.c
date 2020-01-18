#include "gui.h"

void gui_main_callback_window_destroy(GtkWidget *widget, gpointer data) {
    gui_emulation_timer_stop();
    gtk_widget_destroy(widget);
}
