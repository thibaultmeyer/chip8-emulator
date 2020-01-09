#include "gui.h"

void gui_initialize_header_bar(void) {
    gl_gui_components.gtk_header_bar = gtk_header_bar_new();
    gtk_header_bar_set_show_close_button(GTK_HEADER_BAR (gl_gui_components.gtk_header_bar), TRUE);
    gtk_header_bar_set_title(GTK_HEADER_BAR(gl_gui_components.gtk_header_bar), "Chip8 Emulator");
    gtk_header_bar_set_subtitle(GTK_HEADER_BAR(gl_gui_components.gtk_header_bar), "no ROM loaded");


    GtkWidget *button = gtk_button_new();
    GIcon     *icon   = g_themed_icon_new("document-open");
    GtkWidget *image  = gtk_image_new_from_gicon(icon, GTK_ICON_SIZE_BUTTON);
    g_object_unref(icon);
    gtk_widget_set_tooltip_text(button, "Load a ROM");
    gtk_container_add(GTK_CONTAINER (button), image);
    gtk_header_bar_pack_start(GTK_HEADER_BAR (gl_gui_components.gtk_header_bar), button);
    g_signal_connect (button, "clicked", G_CALLBACK(gui_callback_header_bar_load_rom), NULL);

    button = gtk_button_new();
    icon   = g_themed_icon_new("object-rotate-left");
    image  = gtk_image_new_from_gicon(icon, GTK_ICON_SIZE_BUTTON);
    g_object_unref(icon);
    gtk_widget_set_tooltip_text(button, "Reset");
    gtk_container_add(GTK_CONTAINER (button), image);
    gtk_header_bar_pack_start(GTK_HEADER_BAR (gl_gui_components.gtk_header_bar), button);
    g_signal_connect (button, "clicked", G_CALLBACK(gui_callback_header_bar_reset_cpu), NULL);

    button = gtk_button_new();
    icon   = g_themed_icon_new("open-menu-symbolic");
    image  = gtk_image_new_from_gicon(icon, GTK_ICON_SIZE_BUTTON);
    g_object_unref(icon);
    gtk_widget_set_tooltip_text(button, "Settings");
    gtk_container_add(GTK_CONTAINER (button), image);
    gtk_header_bar_pack_end(GTK_HEADER_BAR (gl_gui_components.gtk_header_bar), button);
    //g_signal_connect (button, "clicked", G_CALLBACK(test), NULL);
}
