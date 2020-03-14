#include "gui.h"

void gui_main_callback_menu_state_save(GtkApplication *app, gpointer user_data) {
    if (gl_gui_components.chip8_cpu != NULL && gl_gui_components.current_rom_name != NULL) {
        gchar *state_basename = (gchar *) g_malloc0(sizeof(gchar) * CHIP8EMU_GUI_MAX_FILEBASE_SIZE + 1);

        if (state_basename != NULL) {
            snprintf(state_basename, CHIP8EMU_GUI_MAX_FILEBASE_SIZE, "%s.state", gl_gui_components.current_rom_name);
            gchar *state_filename = gui_toolbox_get_storage_file_path(state_basename);

            gui_emulation_timer_stop();
            chip8_state_save(gl_gui_components.chip8_cpu, state_filename);
            gui_emulation_timer_start();

            g_free(state_filename);
            g_free(state_basename);
        }
    }
}
