#include "gui.h"

void gui_callback_app_activate(GtkApplication *app, gpointer user_data) {
    gui_initialize_header_bar();
    gui_initialize_main_window(app);
}
