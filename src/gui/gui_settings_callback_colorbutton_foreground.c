#include "gui.h"

void gui_settings_callback_colorbutton_foreground(GtkColorButton *widget, gpointer user_data) {
    // Retrieves foreground color values (R, G, B)
    gtk_color_chooser_get_rgba(GTK_COLOR_CHOOSER(widget), &gl_gui_settings.color_foreground);

    // Persists settings
    gui_toolbox_save_settings_to_file();
}
