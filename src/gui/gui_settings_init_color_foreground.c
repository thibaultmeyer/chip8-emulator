#include "gui.h"

void gui_settings_init_color_foreground(GtkFixed *fixed_container) {
    GtkWidget *label_color_foreground  = gtk_label_new("Foreground Color");
    GtkWidget *button_color_foreground = gtk_color_button_new_with_rgba(&gl_gui_settings.color_foreground);

    // Connect signal
    g_signal_connect(button_color_foreground,
                     "color-set",
                     G_CALLBACK(gui_settings_callback_colorbutton_foreground),
                     NULL);

    // Place components on the container
    gtk_fixed_put(fixed_container, label_color_foreground, 10, 115);
    gtk_fixed_put(fixed_container, button_color_foreground, 140, 110);
}
