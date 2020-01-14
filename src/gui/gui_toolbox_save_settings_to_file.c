#include "gui.h"

void gui_toolbox_save_settings_to_file(void) {
    gchar    *filename = gui_toolbox_get_settings_filename();
    GKeyFile *key_file = g_key_file_new();

    // Create Key-File
    g_key_file_set_integer(key_file, "cpu", "frequency", gl_gui_settings.cpu_frequency);
    g_key_file_set_integer(key_file, "display", "mode", gl_gui_settings.display_mode);
    g_key_file_set_double(key_file, "color_background", "red", gl_gui_settings.color_background.red);
    g_key_file_set_double(key_file, "color_background", "green", gl_gui_settings.color_background.green);
    g_key_file_set_double(key_file, "color_background", "blue", gl_gui_settings.color_background.blue);
    g_key_file_set_double(key_file, "color_foreground", "red", gl_gui_settings.color_foreground.red);
    g_key_file_set_double(key_file, "color_foreground", "green", gl_gui_settings.color_foreground.green);
    g_key_file_set_double(key_file, "color_foreground", "blue", gl_gui_settings.color_foreground.blue);

    // Save to file
    g_key_file_save_to_file(key_file, filename, NULL);

    // Free allocated variables
    g_free(filename);
    g_key_file_free(key_file);
}
