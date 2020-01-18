#include "gui.h"

void gui_settings_callback_input_key(GtkEntry *entry, uint32_t key_idx) {
    const gchar *data = gtk_entry_get_text(entry);

    if (data[0] != 0) {
        // Set new value
        gl_gui_settings.keybinding[key_idx] = gdk_unicode_to_keyval(data[0]);

        // Persists settings
        gui_toolbox_save_settings_to_file();
    }
}
