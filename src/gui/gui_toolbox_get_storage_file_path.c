#include "gui.h"
#include <stdlib.h>

gchar *gui_toolbox_get_storage_file_path(const char *filename) {
    gchar *homedir = (gchar *) g_malloc0(sizeof(gchar) * CHIP8EMU_GUI_MAX_FILENAME_SIZE + 1);

#ifdef _WIN32
    snprintf(homedir,
             CHIP8EMU_GUI_MAX_FILENAME_SIZE,
             "%s%s\\.chip8-emulator\\%s",
             getenv("HOMEDRIVE"),
             getenv("HOMEPATH"), filename);
#else
    snprintf(homedir,
            CHIP8EMU_GUI_MAX_FILENAME_SIZE,
            "%s/.chip8-emulator/%s",
            getenv("HOME"),
            filename);
#endif

    return (homedir);
}
