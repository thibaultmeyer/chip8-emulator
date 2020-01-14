#include "gui.h"
#include <stdlib.h>

gchar *gui_toolbox_get_settings_filename(void) {
    gchar *homedir = (gchar *) g_malloc0(sizeof(gchar) * 1024 + 1);

#ifdef _WIN32
    snprintf(homedir, 1024, "%s%s\\.chip8-emulator.conf", getenv("HOMEDRIVE"), getenv("HOMEPATH"));
#else
    snprintf(homedir, 1024, "%s/.chip8-emulator.conf", getenv("HOME"));
#endif

    return (homedir);
}
