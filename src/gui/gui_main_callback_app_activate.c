#include "gui.h"

void gui_main_callback_app_activate(GtkApplication *app, gpointer user_data) {
    gui_toolbox_load_settings_from_file_or_default();
    gui_main_initialize_main_header_bar();
    gui_main_initialize_main_window(app);
}
