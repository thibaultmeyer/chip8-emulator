#include "gui.h"

void gui_settings_callback_colorbutton_background(GtkColorButton *color_button, gpointer user_data) {
    (void) user_data;  // Unused parameter

    // Retrieves background color values (R, G, B)
    gtk_color_chooser_get_rgba(GTK_COLOR_CHOOSER(color_button), &gl_gui_settings.color_background);

    // Persists settings
    gui_toolbox_save_settings_to_file();
}
