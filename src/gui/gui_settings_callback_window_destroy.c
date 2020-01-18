#include "gui.h"

static void destroy_or_unref_item(gpointer data) {
    if (GTK_IS_WIDGET(data)) {
        gtk_widget_destroy(data);
    } else if (G_IS_OBJECT(data)) {
        g_object_unref(data);
    }
}

void gui_settings_callback_window_destroy(GtkWidget *widget, gpointer data) {
    // Free allocated variables
    g_slist_free_full(data, destroy_or_unref_item);

    // Free allocated window
    gtk_widget_destroy(widget);
}
