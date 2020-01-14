#include "gui.h"
#include "gui_image_logo.h"

void gui_settings_init() {
    // Header
    GtkWidget *header = gtk_header_bar_new();
    gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(header), TRUE);
    gtk_header_bar_set_title(GTK_HEADER_BAR(header), "Settings");

    // Window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_titlebar(GTK_WINDOW(window), header);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    gtk_window_set_default_size(GTK_WINDOW(window), 640, 220);
    gtk_window_set_modal(GTK_WINDOW(window), TRUE);
    gtk_window_set_transient_for(GTK_WINDOW(window), GTK_WINDOW(gl_gui_components.gtk_window));
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    // Window icon
    GdkPixbuf *icon = gui_image_load_from_memory_scale(gui_image_logo_bytes, gui_image_logo_length, 256, 256);
    gtk_window_set_icon(GTK_WINDOW(window), icon);
    g_object_unref(icon);

    // Create fixed grid
    GtkWidget *fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);

    // Components
    gui_settings_init_color_background(GTK_FIXED(fixed));
    gui_settings_init_color_foreground(GTK_FIXED(fixed));
    gui_settings_init_cpu_frequency(GTK_FIXED(fixed));
    gui_settings_init_display_mode(GTK_FIXED(fixed));

    // Show the window
    gtk_widget_show_all(window);
}
