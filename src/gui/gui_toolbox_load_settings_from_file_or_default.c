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
        gl_gui_settings.keybinding[0]  = g_key_file_get_integer(key_file, "keybinding", "0", NULL);
        gl_gui_settings.keybinding[1]  = g_key_file_get_integer(key_file, "keybinding", "1", NULL);
        gl_gui_settings.keybinding[2]  = g_key_file_get_integer(key_file, "keybinding", "2", NULL);
        gl_gui_settings.keybinding[3]  = g_key_file_get_integer(key_file, "keybinding", "3", NULL);
        gl_gui_settings.keybinding[4]  = g_key_file_get_integer(key_file, "keybinding", "4", NULL);
        gl_gui_settings.keybinding[5]  = g_key_file_get_integer(key_file, "keybinding", "5", NULL);
        gl_gui_settings.keybinding[6]  = g_key_file_get_integer(key_file, "keybinding", "6", NULL);
        gl_gui_settings.keybinding[7]  = g_key_file_get_integer(key_file, "keybinding", "7", NULL);
        gl_gui_settings.keybinding[8]  = g_key_file_get_integer(key_file, "keybinding", "8", NULL);
        gl_gui_settings.keybinding[9]  = g_key_file_get_integer(key_file, "keybinding", "9", NULL);
        gl_gui_settings.keybinding[10] = g_key_file_get_integer(key_file, "keybinding", "10", NULL);
        gl_gui_settings.keybinding[11] = g_key_file_get_integer(key_file, "keybinding", "11", NULL);
        gl_gui_settings.keybinding[12] = g_key_file_get_integer(key_file, "keybinding", "12", NULL);
        gl_gui_settings.keybinding[13] = g_key_file_get_integer(key_file, "keybinding", "13", NULL);
        gl_gui_settings.keybinding[14] = g_key_file_get_integer(key_file, "keybinding", "14", NULL);
        gl_gui_settings.keybinding[15] = g_key_file_get_integer(key_file, "keybinding", "15", NULL);
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
        gl_gui_settings.keybinding[0]  = GDK_KEY_x;
        gl_gui_settings.keybinding[1]  = GDK_KEY_ampersand;
        gl_gui_settings.keybinding[2]  = GDK_KEY_eacute;
        gl_gui_settings.keybinding[3]  = GDK_KEY_quotedbl;
        gl_gui_settings.keybinding[4]  = GDK_KEY_a;
        gl_gui_settings.keybinding[5]  = GDK_KEY_z;
        gl_gui_settings.keybinding[6]  = GDK_KEY_e;
        gl_gui_settings.keybinding[7]  = GDK_KEY_q;
        gl_gui_settings.keybinding[8]  = GDK_KEY_s;
        gl_gui_settings.keybinding[9]  = GDK_KEY_d;
        gl_gui_settings.keybinding[10] = GDK_KEY_w;
        gl_gui_settings.keybinding[11] = GDK_KEY_c;
        gl_gui_settings.keybinding[12] = GDK_KEY_apostrophe;
        gl_gui_settings.keybinding[13] = GDK_KEY_r;
        gl_gui_settings.keybinding[14] = GDK_KEY_f;
        gl_gui_settings.keybinding[15] = GDK_KEY_v;

        gui_toolbox_save_settings_to_file();
    }

    // Free allocated variables
    g_free(filename);
    g_key_file_free(key_file);
}
