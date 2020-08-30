#include "gui.h"

gboolean gui_toolbox_is_gtk_dark_theme_enabled(void) {
    GtkSettings *settings = gtk_settings_get_default();
    gchar       *value    = NULL;

    g_object_get(settings, "gtk-theme-name", &value, NULL);
    gboolean res = g_strrstr(value, "dark") != NULL;

    g_object_unref(settings);
    g_free(value);

    return res;
}
