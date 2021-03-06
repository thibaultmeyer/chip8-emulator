#include "gui.h"
#include "gui_image_load_rom_dark.h"
#include "gui_image_load_rom_light.h"
#include "gui_image_reset_cpu_dark.h"
#include "gui_image_reset_cpu_light.h"
#include "gui_image_state_dark.h"
#include "gui_image_state_light.h"
#include "gui_image_more_dark.h"
#include "gui_image_more_light.h"
#include "../version.h"

void gui_main_initialize_main_header_bar(void) {
    // Header bar
    gl_gui_components.gtk_header_bar = gtk_header_bar_new();
    gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(gl_gui_components.gtk_header_bar), TRUE);
    gtk_header_bar_set_title(GTK_HEADER_BAR(gl_gui_components.gtk_header_bar), CHIP8EMU_APPNAME);
    gtk_header_bar_set_subtitle(GTK_HEADER_BAR(gl_gui_components.gtk_header_bar), "no ROM loaded");
    gtk_window_set_titlebar(GTK_WINDOW(gl_gui_components.gtk_window), gl_gui_components.gtk_header_bar);

    // Check dark theme
    gboolean is_dark_theme_enabled = gui_toolbox_is_gtk_dark_theme_enabled(gl_gui_components.gtk_window);

    // Button - Load ROM
    GtkWidget *button = gtk_button_new();
    GdkPixbuf *pixbuf = is_dark_theme_enabled ? gui_image_load_from_memory_scale(gui_image_load_rom_light_bytes,
                                                                                 gui_image_load_rom_light_length,
                                                                                 CHIP8EMU_GUI_HEADERBAR_BTN_IMG_WIDTH,
                                                                                 CHIP8EMU_GUI_HEADERBAR_BTN_IMG_HEIGHT)
                                              : gui_image_load_from_memory_scale(gui_image_load_rom_dark_bytes,
                                                                                 gui_image_load_rom_dark_length,
                                                                                 CHIP8EMU_GUI_HEADERBAR_BTN_IMG_WIDTH,
                                                                                 CHIP8EMU_GUI_HEADERBAR_BTN_IMG_HEIGHT);
    GtkWidget *image  = gtk_image_new_from_pixbuf(pixbuf);
    gtk_widget_set_tooltip_text(button, "Load a ROM");
    gtk_container_add(GTK_CONTAINER(button), image);
    gtk_header_bar_pack_start(GTK_HEADER_BAR(gl_gui_components.gtk_header_bar), button);
    g_signal_connect(button, "clicked", G_CALLBACK(gui_main_callback_header_bar_load_rom), NULL);

    // Button - Reset CPU
    button = gtk_button_new();
    pixbuf = is_dark_theme_enabled ? gui_image_load_from_memory_scale(gui_image_reset_cpu_light_bytes,
                                                                      gui_image_reset_cpu_light_length,
                                                                      CHIP8EMU_GUI_HEADERBAR_BTN_IMG_WIDTH,
                                                                      CHIP8EMU_GUI_HEADERBAR_BTN_IMG_HEIGHT)
                                   : gui_image_load_from_memory_scale(gui_image_reset_cpu_dark_bytes,
                                                                      gui_image_reset_cpu_dark_length,
                                                                      CHIP8EMU_GUI_HEADERBAR_BTN_IMG_WIDTH,
                                                                      CHIP8EMU_GUI_HEADERBAR_BTN_IMG_HEIGHT);
    image  = gtk_image_new_from_pixbuf(pixbuf);
    gtk_widget_set_tooltip_text(button, "Reset");
    gtk_container_add(GTK_CONTAINER(button), image);
    gtk_header_bar_pack_start(GTK_HEADER_BAR(gl_gui_components.gtk_header_bar), button);
    g_signal_connect(button, "clicked", G_CALLBACK(gui_main_callback_header_bar_reset_cpu), NULL);

    // Button - Load/Save state
    button = gtk_menu_button_new();
    pixbuf = is_dark_theme_enabled ? gui_image_load_from_memory_scale(gui_image_state_light_bytes,
                                                                      gui_image_state_light_length,
                                                                      CHIP8EMU_GUI_HEADERBAR_BTN_IMG_WIDTH,
                                                                      CHIP8EMU_GUI_HEADERBAR_BTN_IMG_HEIGHT)
                                   : gui_image_load_from_memory_scale(gui_image_state_dark_bytes,
                                                                      gui_image_state_dark_length,
                                                                      CHIP8EMU_GUI_HEADERBAR_BTN_IMG_WIDTH,
                                                                      CHIP8EMU_GUI_HEADERBAR_BTN_IMG_HEIGHT);

    image = gtk_image_new_from_pixbuf(pixbuf);
    gtk_widget_set_tooltip_text(button, "Load/Save state");
    gtk_container_add(GTK_CONTAINER(button), image);
    gtk_header_bar_pack_start(GTK_HEADER_BAR(gl_gui_components.gtk_header_bar), button);

    // Load/Save state menu
    GtkWidget *menu_state = gtk_menu_new();
    gtk_menu_button_set_popup(GTK_MENU_BUTTON(button), menu_state);

    // Load/Save state menu: Load
    GtkWidget *menu_item_state_load = gtk_menu_item_new_with_label("Load state");
    gtk_container_add(GTK_CONTAINER(menu_state), menu_item_state_load);
    gtk_menu_attach(GTK_MENU(menu_state), menu_item_state_load, 0, 1, 0, 1);
    g_signal_connect(menu_item_state_load, "activate", G_CALLBACK(gui_main_callback_menu_state_load), NULL);

    // Load/Save state menu: Save
    GtkWidget *menu_item_state_save = gtk_menu_item_new_with_label("Save state");
    gtk_container_add(GTK_CONTAINER(menu_state), menu_item_state_save);
    gtk_menu_attach(GTK_MENU(menu_state), menu_item_state_save, 0, 1, 1, 2);
    g_signal_connect(menu_item_state_save, "activate", G_CALLBACK(gui_main_callback_menu_state_save), NULL);

    // Load/Save state menu (Refresh)
    gtk_widget_show_all(menu_state);

    // Button - More
    button = gtk_menu_button_new();
    pixbuf = is_dark_theme_enabled ? gui_image_load_from_memory_scale(gui_image_more_light_bytes,
                                                                      gui_image_more_light_length,
                                                                      CHIP8EMU_GUI_HEADERBAR_BTN_IMG_WIDTH,
                                                                      CHIP8EMU_GUI_HEADERBAR_BTN_IMG_HEIGHT)
                                   : gui_image_load_from_memory_scale(gui_image_more_dark_bytes,
                                                                      gui_image_more_dark_length,
                                                                      CHIP8EMU_GUI_HEADERBAR_BTN_IMG_WIDTH,
                                                                      CHIP8EMU_GUI_HEADERBAR_BTN_IMG_HEIGHT);

    image = gtk_image_new_from_pixbuf(pixbuf);
    gtk_widget_set_tooltip_text(button, "More");
    gtk_container_add(GTK_CONTAINER(button), image);
    gtk_header_bar_pack_end(GTK_HEADER_BAR(gl_gui_components.gtk_header_bar), button);

    // More menu
    GtkWidget *menu_more = gtk_menu_new();
    gtk_menu_button_set_popup(GTK_MENU_BUTTON(button), menu_more);

    // More menu: Settings
    GtkWidget *menu_item_settings = gtk_menu_item_new_with_label("Settings");
    gtk_container_add(GTK_CONTAINER(menu_more), menu_item_settings);
    gtk_menu_attach(GTK_MENU(menu_more), menu_item_settings, 0, 1, 0, 1);
    g_signal_connect(menu_item_settings, "activate", G_CALLBACK(gui_main_callback_menu_more_settings), NULL);

    // More menu: About
    GtkWidget *menu_item_about = gtk_menu_item_new_with_label("About");
    gtk_container_add(GTK_CONTAINER(menu_more), menu_item_about);
    gtk_menu_attach(GTK_MENU(menu_more), menu_item_about, 0, 1, 1, 2);
    g_signal_connect(menu_item_about, "activate", G_CALLBACK(gui_main_callback_menu_more_about), NULL);

    // More menu (Refresh)
    gtk_widget_show_all(menu_more);
}
