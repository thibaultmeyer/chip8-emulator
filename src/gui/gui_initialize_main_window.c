#include <gdk/gdkx.h>
#include "gui.h"

void gui_initialize_main_window(GtkApplication *app) {
    gl_gui_components.chip8_screen_pixel_ratio = 10;
    gl_gui_components.chip8_screen_width       = 640;
    gl_gui_components.chip8_screen_height      = 320;
    gl_gui_components.gtk_window               = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(gl_gui_components.gtk_window), "Chip8 Emulator");
    gtk_window_set_default_size(GTK_WINDOW(gl_gui_components.gtk_window),
                                gl_gui_components.chip8_screen_width,
                                gl_gui_components.chip8_screen_height);
    gtk_window_set_titlebar(GTK_WINDOW (gl_gui_components.gtk_window), gl_gui_components.gtk_header_bar);
    gtk_widget_show_all(gl_gui_components.gtk_window);

    gl_gui_components.gtk_drawing_area = gtk_drawing_area_new();
    gtk_container_add(GTK_CONTAINER(gl_gui_components.gtk_window), gl_gui_components.gtk_drawing_area);
    gtk_widget_show_all(GTK_WIDGET(gl_gui_components.gtk_window));

    g_signal_connect (gl_gui_components.gtk_drawing_area,
                      "size-allocate",
                      G_CALLBACK(gui_callback_drawing_area_new_size),
                      NULL);

    g_signal_connect (gl_gui_components.gtk_drawing_area,
                      "draw",
                      G_CALLBACK(gui_callback_drawing_area_draw),
                      NULL);

    g_timeout_add(2, gui_callback_chip8_tick, 0);
}
