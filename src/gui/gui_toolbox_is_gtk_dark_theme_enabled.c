#include "gui.h"

gboolean gui_toolbox_is_gtk_dark_theme_enabled(GtkWidget *const widget) {
    GtkSettings *const settings = gtk_settings_get_default();
    gchar    *theme_name      = NULL;
    gboolean prefer_dark_mode = FALSE;

    // Retrieve theme information from Gtk settings
    g_object_get(settings,
                 "gtk-theme-name", &theme_name,
                 "gtk-application-prefer-dark-theme", &prefer_dark_mode,
                 NULL);

    // Retrieve widget color information
    gtk_widget_realize(widget);
    GdkRGBA *color_font = NULL;
    GdkRGBA *color_back = NULL;
    GtkStyleContext *const gtk_style_ctx = gtk_widget_get_style_context(widget);

    gtk_style_context_get(gtk_style_ctx, GTK_STATE_FLAG_NORMAL, GTK_STYLE_PROPERTY_COLOR, &color_font, NULL);
    gtk_style_context_get(gtk_style_ctx, GTK_STATE_FLAG_NORMAL, GTK_STYLE_PROPERTY_BACKGROUND_COLOR, &color_back, NULL);

    const gdouble fg_color_avg = color_font->red + color_font->green + color_font->blue;
    const gdouble bg_color_avg = color_back->red + color_back->green + color_back->blue;

    // Detect if dark mode is needed
    const gboolean res = prefer_dark_mode == 1 || fg_color_avg > bg_color_avg || g_strrstr(theme_name, "dark") != NULL;

    // Free
    g_object_unref(settings);
    g_free(theme_name);
    gdk_rgba_free(color_font);
    gdk_rgba_free(color_back);

    // Return result
    return (res);
}
