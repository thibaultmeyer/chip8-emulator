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
    g_key_file_set_integer(key_file, "keybinding", "0", gl_gui_settings.keybinding[0]);
    g_key_file_set_integer(key_file, "keybinding", "1", gl_gui_settings.keybinding[1]);
    g_key_file_set_integer(key_file, "keybinding", "2", gl_gui_settings.keybinding[2]);
    g_key_file_set_integer(key_file, "keybinding", "3", gl_gui_settings.keybinding[3]);
    g_key_file_set_integer(key_file, "keybinding", "4", gl_gui_settings.keybinding[4]);
    g_key_file_set_integer(key_file, "keybinding", "5", gl_gui_settings.keybinding[5]);
    g_key_file_set_integer(key_file, "keybinding", "6", gl_gui_settings.keybinding[6]);
    g_key_file_set_integer(key_file, "keybinding", "7", gl_gui_settings.keybinding[7]);
    g_key_file_set_integer(key_file, "keybinding", "8", gl_gui_settings.keybinding[8]);
    g_key_file_set_integer(key_file, "keybinding", "9", gl_gui_settings.keybinding[9]);
    g_key_file_set_integer(key_file, "keybinding", "10", gl_gui_settings.keybinding[10]);
    g_key_file_set_integer(key_file, "keybinding", "11", gl_gui_settings.keybinding[11]);
    g_key_file_set_integer(key_file, "keybinding", "12", gl_gui_settings.keybinding[12]);
    g_key_file_set_integer(key_file, "keybinding", "13", gl_gui_settings.keybinding[13]);
    g_key_file_set_integer(key_file, "keybinding", "14", gl_gui_settings.keybinding[14]);
    g_key_file_set_integer(key_file, "keybinding", "15", gl_gui_settings.keybinding[15]);

    // Save to file
    g_key_file_save_to_file(key_file, filename, NULL);

    // Free allocated variables
    g_free(filename);
    g_key_file_free(key_file);
}
