#include "gui.h"

static void destroy_or_unref_item(gpointer user_data) {
    if (GTK_IS_WIDGET(user_data)) {
        gtk_widget_destroy(user_data);
    } else if (G_IS_OBJECT(user_data)) {
        g_object_unref(user_data);
    }
}

void gui_settings_callback_window_destroy(GtkWidget *widget, gpointer user_data) {
    // Free allocated variables
    g_slist_free_full(user_data, destroy_or_unref_item);

    // Free allocated window
    gtk_widget_destroy(widget);
}
