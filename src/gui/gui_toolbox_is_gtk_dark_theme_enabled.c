#include "gui.h"

gboolean gui_toolbox_is_gtk_dark_theme_enabled(void) {
    GtkSettings *const settings   = gtk_settings_get_default();
    gchar       *const theme_name = NULL;
    gboolean    prefer_dark_mode  = FALSE;

    g_object_get(settings,
                 "gtk-theme-name", &theme_name,
                 "gtk-application-prefer-dark-theme", &prefer_dark_mode,
                 NULL);
    const gboolean res = prefer_dark_mode == 1 || g_strrstr(theme_name, "dark") != NULL;

    g_object_unref(settings);
    g_free(theme_name);

    return (prefer_dark_mode || res);
}
