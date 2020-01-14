#include "gui.h"

void gui_toolbox_load_settings_from_file_or_default(void) {
    gchar    *filename = gui_toolbox_get_settings_filename();
    GKeyFile *key_file = g_key_file_new();
    gboolean ret       = g_key_file_load_from_file(key_file, filename, G_KEY_FILE_KEEP_COMMENTS, NULL);

    if (ret == TRUE) {
        // Restore values
        gl_gui_settings.cpu_frequency          = g_key_file_get_integer(key_file, "cpu", "frequency", NULL);
        gl_gui_settings.display_mode           = g_key_file_get_integer(key_file, "display", "mode", NULL);
        gl_gui_settings.color_background.red   = g_key_file_get_double(key_file, "color_background", "red", NULL);
        gl_gui_settings.color_background.green = g_key_file_get_double(key_file, "color_background", "green", NULL);
        gl_gui_settings.color_background.blue  = g_key_file_get_double(key_file, "color_background", "blue", NULL);
        gl_gui_settings.color_background.alpha = 1;
        gl_gui_settings.color_foreground.red   = g_key_file_get_double(key_file, "color_foreground", "red", NULL);
        gl_gui_settings.color_foreground.green = g_key_file_get_double(key_file, "color_foreground", "green", NULL);
        gl_gui_settings.color_foreground.blue  = g_key_file_get_double(key_file, "color_foreground", "blue", NULL);
        gl_gui_settings.color_foreground.alpha = 1;
    } else {
        // Use default values
        gl_gui_settings.cpu_frequency          = 500;
        gl_gui_settings.display_mode           = 0;
        gl_gui_settings.color_background.red   = 0;
        gl_gui_settings.color_background.green = 0;
        gl_gui_settings.color_background.blue  = 0;
        gl_gui_settings.color_background.alpha = 1;
        gl_gui_settings.color_foreground.red   = 1;
        gl_gui_settings.color_foreground.green = 1;
        gl_gui_settings.color_foreground.blue  = 1;
        gl_gui_settings.color_foreground.alpha = 1;

        gui_toolbox_save_settings_to_file();
    }

    // Free allocated variables
    g_free(filename);
    g_key_file_free(key_file);
}
