#include "gui.h"

gboolean gui_toolbox_is_gtk_dark_theme_enabled(void) {
    GtkSettings *settings = gtk_settings_get_default();
    gchar       *value;

    g_object_get(settings, "gtk-theme-name", &value, NULL);
    return g_strrstr(value, "dark") != NULL;
}
