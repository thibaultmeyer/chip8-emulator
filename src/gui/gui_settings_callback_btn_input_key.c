#include "gui.h"
#include "gui_image_logo.h"

static gboolean test(GtkWidget *widget, GdkEventKey *event, s_gui_key_binding_context *key_binding_ctx) {
    // Set new value
    gl_gui_settings.keybinding[key_binding_ctx->key_idx] = event->keyval;

    // Change button label
    gtk_button_set_label(GTK_BUTTON(key_binding_ctx->button), gdk_keyval_name(event->keyval));

    // Persists settings
    gui_toolbox_save_settings_to_file();

    // Close current window
    gtk_window_close(GTK_WINDOW(widget));

    return FALSE;
}

void gui_settings_callback_btn_input_key(GtkButton *button, s_gui_key_binding_context *key_binding_ctx) {
    // Header
    GtkWidget *header = gtk_header_bar_new();
    gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(header), TRUE);
    gtk_header_bar_set_title(GTK_HEADER_BAR(header), "Bind a new key");

    // Window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_titlebar(GTK_WINDOW(window), header);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    gtk_window_set_default_size(GTK_WINDOW(window), 385, 60);
    gtk_widget_set_parent(window, gl_gui_components.gtk_window_setting);
    gtk_window_set_modal(GTK_WINDOW(window), TRUE);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER_ON_PARENT);
    gtk_window_set_transient_for(GTK_WINDOW(window), GTK_WINDOW(gl_gui_components.gtk_window_setting));
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    // Window icon
    GdkPixbuf *icon = gui_image_load_from_memory_scale(gui_image_logo_bytes, gui_image_logo_length, 256, 256);
    gtk_window_set_icon(GTK_WINDOW(window), icon);

    // Create fixed grid
    GtkWidget *fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);

    // Add help message
    GtkWidget *label_help = gtk_label_new("Please press the key you want to assign");
    gtk_fixed_put(GTK_FIXED(fixed), label_help, 0, 0);

    // Mark some widget/object to be explicitly deleted when window will be destroyed
    GSList *components = g_slist_alloc();
    components = g_slist_append(components, header);
    components = g_slist_append(components, fixed);
    components = g_slist_append(components, icon);

    // Connect signal
    g_signal_connect(window, "key_press_event", G_CALLBACK(test), key_binding_ctx);
    g_signal_connect(window, "destroy", G_CALLBACK(gui_settings_callback_window_destroy), components);

    // Show the window
    gtk_widget_show_all(window);
}
