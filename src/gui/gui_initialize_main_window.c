#include <gdk/gdkx.h>
#include "gui.h"

void gui_initialize_main_window(GtkApplication *app) {
    gl_gui_components.chip8_screen_pixel_ratio = 10;
    gl_gui_components.gtk_window               = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(gl_gui_components.gtk_window), "Chip8 Emulator");
    gtk_window_set_default_size(GTK_WINDOW(gl_gui_components.gtk_window), 640, 320);
    gtk_window_set_titlebar(GTK_WINDOW (gl_gui_components.gtk_window), gl_gui_components.gtk_header_bar);
    gtk_widget_show_all(gl_gui_components.gtk_window);

    GtkWidget *gtk_da = gtk_drawing_area_new();
    gtk_container_add(GTK_CONTAINER(gl_gui_components.gtk_window), gtk_da);
    gtk_widget_show_all(GTK_WIDGET(gl_gui_components.gtk_window));

    void *gdk_window = gtk_widget_get_window(GTK_WIDGET(gtk_da));
    void *window_id  = (void *) (intptr_t) GDK_WINDOW_XID(gdk_window);

    //gl_gui_components.sdl_window   = SDL_CreateWindowFrom(window_id);
    gl_gui_components.sdl_window   = SDL_CreateWindow("TEST", 10, 10, 640, 320, 0);
    gl_gui_components.sdl_renderer = SDL_CreateRenderer(gl_gui_components.sdl_window,
                                                        -1,
                                                        SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);

    g_signal_connect (gtk_da, "size-allocate", G_CALLBACK(gui_callback_drawing_area_new_size), NULL);
    g_timeout_add(16, gui_callback_sdl_render_screen, 0);
}
