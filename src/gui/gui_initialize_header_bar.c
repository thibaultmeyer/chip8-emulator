#include "gui.h"
#include "gui_icon_load_rom.h"
#include "gui_icon_reset_cpu.h"
#include "gui_icon_settings.h"

static GdkPixbuf *load_icon(const unsigned char *data, const unsigned int length) {
    GdkPixbufLoader *loader = gdk_pixbuf_loader_new();
    gdk_pixbuf_loader_write(loader, data, length, NULL);

    GdkPixbuf *pixbuf_initial = gdk_pixbuf_loader_get_pixbuf(loader);
    GdkPixbuf *pixbuf_scaled  = gdk_pixbuf_scale_simple(pixbuf_initial, 20, 20, GDK_INTERP_HYPER);

    g_object_unref(pixbuf_initial);
    gdk_pixbuf_loader_close(loader, NULL);

    return pixbuf_scaled;
}

void gui_initialize_header_bar(void) {
    gl_gui_components.gtk_header_bar = gtk_header_bar_new();
    gtk_header_bar_set_show_close_button(GTK_HEADER_BAR (gl_gui_components.gtk_header_bar), TRUE);
    gtk_header_bar_set_title(GTK_HEADER_BAR(gl_gui_components.gtk_header_bar), "Chip8 Emulator");
    gtk_header_bar_set_subtitle(GTK_HEADER_BAR(gl_gui_components.gtk_header_bar), "no ROM loaded");

    // Button - Load ROM
    GtkWidget *button = gtk_button_new();
    GdkPixbuf *pixbuf = load_icon(gui_icon_load_rom_bytes, gui_icon_load_rom_length);
    GtkWidget *image  = gtk_image_new_from_pixbuf(pixbuf);
    gtk_widget_set_tooltip_text(button, "Load a ROM");
    gtk_container_add(GTK_CONTAINER (button), image);
    gtk_header_bar_pack_start(GTK_HEADER_BAR (gl_gui_components.gtk_header_bar), button);
    g_signal_connect (button, "clicked", G_CALLBACK(gui_callback_header_bar_load_rom), NULL);

    // Button - Reset CPU
    button = gtk_button_new();
    pixbuf = load_icon(gui_icon_reset_cpu_bytes, gui_icon_reset_cpu_length);
    image  = gtk_image_new_from_pixbuf(pixbuf);
    gtk_widget_set_tooltip_text(button, "Reset");
    gtk_container_add(GTK_CONTAINER (button), image);
    gtk_header_bar_pack_start(GTK_HEADER_BAR (gl_gui_components.gtk_header_bar), button);
    g_signal_connect (button, "clicked", G_CALLBACK(gui_callback_header_bar_reset_cpu), NULL);

    // Button - Settings
    button = gtk_button_new();
    pixbuf = load_icon(gui_icon_settings_bytes, gui_icon_settings_length);
    image  = gtk_image_new_from_pixbuf(pixbuf);
    gtk_widget_set_tooltip_text(button, "Settings");
    gtk_container_add(GTK_CONTAINER (button), image);
    gtk_header_bar_pack_end(GTK_HEADER_BAR (gl_gui_components.gtk_header_bar), button);
    //g_signal_connect (button, "clicked", G_CALLBACK(test), NULL);
}
