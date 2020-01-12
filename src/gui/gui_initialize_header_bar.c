#include "gui.h"
#include "gui_image_load_rom_dark.h"
#include "gui_image_load_rom_light.h"
#include "gui_image_reset_cpu_dark.h"
#include "gui_image_reset_cpu_light.h"
#include "gui_image_more_dark.h"
#include "gui_image_more_light.h"
#include "version.h"

void gui_initialize_header_bar(void) {
    // Header bar
    gl_gui_components.gtk_header_bar = gtk_header_bar_new();
    gtk_header_bar_set_show_close_button(GTK_HEADER_BAR (gl_gui_components.gtk_header_bar), TRUE);
    gtk_header_bar_set_title(GTK_HEADER_BAR(gl_gui_components.gtk_header_bar), CHIP8EMU_APPNAME);
    gtk_header_bar_set_subtitle(GTK_HEADER_BAR(gl_gui_components.gtk_header_bar), "no ROM loaded");

    // Check dark theme
    gboolean is_dark_theme_enabled = gui_toolbox_is_gtk_dark_theme_enabled();

    // Button - Load ROM
    GtkWidget *button = gtk_button_new();
    GdkPixbuf *pixbuf = is_dark_theme_enabled ? gui_image_load_from_memory_scale(gui_image_load_rom_light_bytes,
                                                                                 gui_image_load_rom_light_length,
                                                                                 20,
                                                                                 20)
                                              : gui_image_load_from_memory_scale(gui_image_load_rom_dark_bytes,
                                                                                 gui_image_load_rom_dark_length,
                                                                                 20,
                                                                                 20);
    GtkWidget *image  = gtk_image_new_from_pixbuf(pixbuf);
    gtk_widget_set_tooltip_text(button, "Load a ROM");
    gtk_container_add(GTK_CONTAINER (button), image);
    gtk_header_bar_pack_start(GTK_HEADER_BAR (gl_gui_components.gtk_header_bar), button);
    g_signal_connect (button, "clicked", G_CALLBACK(gui_callback_header_bar_load_rom), NULL);

    // Button - Reset CPU
    button = gtk_button_new();
    pixbuf = is_dark_theme_enabled ? gui_image_load_from_memory_scale(gui_image_reset_cpu_light_bytes,
                                                                      gui_image_reset_cpu_light_length,
                                                                      20,
                                                                      20)
                                   : gui_image_load_from_memory_scale(gui_image_reset_cpu_dark_bytes,
                                                                      gui_image_reset_cpu_dark_length,
                                                                      20,
                                                                      20);
    image  = gtk_image_new_from_pixbuf(pixbuf);
    gtk_widget_set_tooltip_text(button, "Reset");
    gtk_container_add(GTK_CONTAINER (button), image);
    gtk_header_bar_pack_start(GTK_HEADER_BAR (gl_gui_components.gtk_header_bar), button);
    g_signal_connect (button, "clicked", G_CALLBACK(gui_callback_header_bar_reset_cpu), NULL);

    // Button - More
    button = gtk_menu_button_new();
    pixbuf = is_dark_theme_enabled ? gui_image_load_from_memory_scale(gui_image_more_light_bytes,
                                                                      gui_image_more_light_length,
                                                                      20,
                                                                      20)
                                   : gui_image_load_from_memory_scale(gui_image_more_dark_bytes,
                                                                      gui_image_more_dark_length,
                                                                      20,
                                                                      20);

    image = gtk_image_new_from_pixbuf(pixbuf);
    gtk_widget_set_tooltip_text(button, "Settings");
    gtk_container_add(GTK_CONTAINER (button), image);
    gtk_header_bar_pack_end(GTK_HEADER_BAR (gl_gui_components.gtk_header_bar), button);

    // More menu
    GtkWidget *menu_more       = gtk_menu_new();
    GtkWidget *menu_item_about = gtk_menu_item_new_with_label("About");
    gtk_menu_button_set_popup(GTK_MENU_BUTTON(button), menu_more);
    gtk_container_add(GTK_CONTAINER(menu_more), menu_item_about);
    gtk_menu_attach(GTK_MENU(menu_more), menu_item_about, 0, 1, 0, 1);
    gtk_widget_show_all(menu_more);
    g_signal_connect (menu_item_about, "activate", G_CALLBACK(gui_callback_menu_more_about), NULL);
}
