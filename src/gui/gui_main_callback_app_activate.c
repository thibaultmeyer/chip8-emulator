#include "gui.h"

void gui_main_callback_app_activate(GtkApplication *app, gpointer user_data) {
    memset(&gl_gui_settings, 0, sizeof(s_gui_settings));
    memset(&gl_gui_components, 0, sizeof(s_gui_components));

    gui_toolbox_create_storage_directory();
    gui_toolbox_load_settings_from_file_or_default();
    gui_main_initialize_main_header_bar();
    gui_main_initialize_main_window(app);
}
