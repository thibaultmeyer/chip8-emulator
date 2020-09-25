#include "gui.h"

void gui_main_callback_menu_more_settings(GtkMenuItem *menuitem, gpointer user_data) {
    (void) menuitem;   // Unused parameter
    (void) user_data;  // Unused parameter

    gui_settings_init();
}
