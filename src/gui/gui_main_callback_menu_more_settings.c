#include "gui.h"

void gui_main_callback_menu_more_settings(GtkApplication *app, gpointer user_data) {
    (void) app;        // Unused parameter
    (void) user_data;  // Unused parameter

    gui_settings_init();
}
