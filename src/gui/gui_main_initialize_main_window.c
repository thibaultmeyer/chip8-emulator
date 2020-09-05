#include "gui.h"
#include "gui_image_logo.h"
#include "../version.h"

void gui_main_initialize_main_window(GtkApplication *app) {
    // Initialize default value
    gl_gui_components.chip8_screen_pixel_ratio   = CHIP8EMU_GUI_SCREEN_DEFAULT_PIXEL_RATIO;
    gl_gui_components.chip8_screen_width         = CHIP8EMU_GUI_SCREEN_DEFAULT_WIDTH;
    gl_gui_components.chip8_screen_height        = CHIP8EMU_GUI_SCREEN_DEFAULT_HEIGHT;
    gl_gui_components.chip8_screen_offset_width  = CHIP8EMU_GUI_SCREEN_DEFAULT_OFFSET_WIDTH;
    gl_gui_components.chip8_screen_offset_height = CHIP8EMU_GUI_SCREEN_DEFAULT_OFFSET_HEIGHT;

    // Create main window
    gl_gui_components.gtk_window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(gl_gui_components.gtk_window), CHIP8EMU_APPNAME);
    gtk_window_set_default_size(GTK_WINDOW(gl_gui_components.gtk_window),
                                gl_gui_components.chip8_screen_width,
                                gl_gui_components.chip8_screen_height);
    gtk_window_set_titlebar(GTK_WINDOW(gl_gui_components.gtk_window), gl_gui_components.gtk_header_bar);
    GdkPixbuf *icon = gui_image_load_from_memory_scale(gui_image_logo_bytes,
                                                       gui_image_logo_length,
                                                       CHIP8EMU_GUI_APP_ICON_WIDTH,
                                                       CHIP8EMU_GUI_APP_ICON_HEIGHT);
    gtk_window_set_icon(GTK_WINDOW(gl_gui_components.gtk_window), icon);
    g_object_unref(icon);
    gtk_widget_show_all(gl_gui_components.gtk_window);

    g_signal_connect(gl_gui_components.gtk_window, "destroy", G_CALLBACK(gui_main_callback_window_destroy), NULL);
    g_signal_connect(gl_gui_components.gtk_window, "key_press_event", G_CALLBACK(gui_main_callback_window_key), NULL);
    g_signal_connect(gl_gui_components.gtk_window, "key_release_event", G_CALLBACK(gui_main_callback_window_key), NULL);

    // Create drawing area
    gl_gui_components.gtk_drawing_area = gtk_drawing_area_new();
    gtk_container_add(GTK_CONTAINER(gl_gui_components.gtk_window), gl_gui_components.gtk_drawing_area);
    gtk_widget_show_all(GTK_WIDGET(gl_gui_components.gtk_window));

    g_signal_connect(gl_gui_components.gtk_drawing_area,
                     "size-allocate",
                     G_CALLBACK(gui_main_callback_drawing_area_new_size),
                     NULL);
    g_signal_connect(gl_gui_components.gtk_drawing_area,
                     "draw",
                     G_CALLBACK(gui_main_callback_drawing_area_draw),
                     NULL);

    // Start all emulation timers
    gui_emulation_timer_start();
}
