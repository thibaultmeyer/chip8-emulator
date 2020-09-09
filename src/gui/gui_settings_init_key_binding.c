#include <stdlib.h>
#include "gui.h"

static void gui_settings_callback_window_destroy_force(GtkWidget *widget, gpointer data) {
    (void) widget;  // Unused parameter

    free(data);
}

void gui_settings_init_key_binding(GtkFixed *fixed_container) {
    // Create label and entry components
    s_gui_key_binding_context *key_binding_ctx   = malloc(sizeof(s_gui_key_binding_context) * 16);
    GtkWidget                 *label_key_binding = gtk_label_new("Keys");
    gchar                     *key_name          = NULL;

    // Initialize key binding context
    memset(key_binding_ctx, 0, sizeof(s_gui_key_binding_context) * 16);
    key_binding_ctx[0].button   = gtk_button_new();
    key_binding_ctx[0].key_idx  = 0;
    key_binding_ctx[1].button   = gtk_button_new();
    key_binding_ctx[1].key_idx  = 1;
    key_binding_ctx[2].button   = gtk_button_new();
    key_binding_ctx[2].key_idx  = 2;
    key_binding_ctx[3].button   = gtk_button_new();
    key_binding_ctx[3].key_idx  = 3;
    key_binding_ctx[4].button   = gtk_button_new();
    key_binding_ctx[4].key_idx  = 4;
    key_binding_ctx[5].button   = gtk_button_new();
    key_binding_ctx[5].key_idx  = 5;
    key_binding_ctx[6].button   = gtk_button_new();
    key_binding_ctx[6].key_idx  = 6;
    key_binding_ctx[7].button   = gtk_button_new();
    key_binding_ctx[7].key_idx  = 7;
    key_binding_ctx[8].button   = gtk_button_new();
    key_binding_ctx[8].key_idx  = 8;
    key_binding_ctx[9].button   = gtk_button_new();
    key_binding_ctx[9].key_idx  = 9;
    key_binding_ctx[10].button  = gtk_button_new();
    key_binding_ctx[10].key_idx = 10;
    key_binding_ctx[11].button  = gtk_button_new();
    key_binding_ctx[11].key_idx = 11;
    key_binding_ctx[12].button  = gtk_button_new();
    key_binding_ctx[12].key_idx = 12;
    key_binding_ctx[13].button  = gtk_button_new();
    key_binding_ctx[13].key_idx = 13;
    key_binding_ctx[14].button  = gtk_button_new();
    key_binding_ctx[14].key_idx = 14;
    key_binding_ctx[15].button  = gtk_button_new();
    key_binding_ctx[15].key_idx = 15;

    // Restore values
    key_name = gdk_keyval_name(gl_gui_settings.keybinding[0]);
    gtk_button_set_label(GTK_BUTTON(key_binding_ctx[0].button), key_name);
    key_name = gdk_keyval_name(gl_gui_settings.keybinding[1]);
    gtk_button_set_label(GTK_BUTTON(key_binding_ctx[1].button), key_name);
    key_name = gdk_keyval_name(gl_gui_settings.keybinding[2]);
    gtk_button_set_label(GTK_BUTTON(key_binding_ctx[2].button), key_name);
    key_name = gdk_keyval_name(gl_gui_settings.keybinding[3]);
    gtk_button_set_label(GTK_BUTTON(key_binding_ctx[3].button), key_name);
    key_name = gdk_keyval_name(gl_gui_settings.keybinding[4]);
    gtk_button_set_label(GTK_BUTTON(key_binding_ctx[4].button), key_name);
    key_name = gdk_keyval_name(gl_gui_settings.keybinding[5]);
    gtk_button_set_label(GTK_BUTTON(key_binding_ctx[5].button), key_name);
    key_name = gdk_keyval_name(gl_gui_settings.keybinding[6]);
    gtk_button_set_label(GTK_BUTTON(key_binding_ctx[6].button), key_name);
    key_name = gdk_keyval_name(gl_gui_settings.keybinding[7]);
    gtk_button_set_label(GTK_BUTTON(key_binding_ctx[7].button), key_name);
    key_name = gdk_keyval_name(gl_gui_settings.keybinding[8]);
    gtk_button_set_label(GTK_BUTTON(key_binding_ctx[8].button), key_name);
    key_name = gdk_keyval_name(gl_gui_settings.keybinding[9]);
    gtk_button_set_label(GTK_BUTTON(key_binding_ctx[9].button), key_name);
    key_name = gdk_keyval_name(gl_gui_settings.keybinding[10]);
    gtk_button_set_label(GTK_BUTTON(key_binding_ctx[10].button), key_name);
    key_name = gdk_keyval_name(gl_gui_settings.keybinding[11]);
    gtk_button_set_label(GTK_BUTTON(key_binding_ctx[11].button), key_name);
    key_name = gdk_keyval_name(gl_gui_settings.keybinding[12]);
    gtk_button_set_label(GTK_BUTTON(key_binding_ctx[12].button), key_name);
    key_name = gdk_keyval_name(gl_gui_settings.keybinding[13]);
    gtk_button_set_label(GTK_BUTTON(key_binding_ctx[13].button), key_name);
    key_name = gdk_keyval_name(gl_gui_settings.keybinding[14]);
    gtk_button_set_label(GTK_BUTTON(key_binding_ctx[14].button), key_name);
    key_name = gdk_keyval_name(gl_gui_settings.keybinding[15]);
    gtk_button_set_label(GTK_BUTTON(key_binding_ctx[15].button), key_name);

    // Set button size (width, height)
    gtk_widget_set_size_request(key_binding_ctx[0].button, 125, 35);
    gtk_widget_set_size_request(key_binding_ctx[1].button, 125, 35);
    gtk_widget_set_size_request(key_binding_ctx[2].button, 125, 35);
    gtk_widget_set_size_request(key_binding_ctx[3].button, 125, 35);
    gtk_widget_set_size_request(key_binding_ctx[4].button, 125, 35);
    gtk_widget_set_size_request(key_binding_ctx[5].button, 125, 35);
    gtk_widget_set_size_request(key_binding_ctx[6].button, 125, 35);
    gtk_widget_set_size_request(key_binding_ctx[7].button, 125, 35);
    gtk_widget_set_size_request(key_binding_ctx[8].button, 125, 35);
    gtk_widget_set_size_request(key_binding_ctx[9].button, 125, 35);
    gtk_widget_set_size_request(key_binding_ctx[10].button, 125, 35);
    gtk_widget_set_size_request(key_binding_ctx[11].button, 125, 35);
    gtk_widget_set_size_request(key_binding_ctx[12].button, 125, 35);
    gtk_widget_set_size_request(key_binding_ctx[13].button, 125, 35);
    gtk_widget_set_size_request(key_binding_ctx[14].button, 125, 35);
    gtk_widget_set_size_request(key_binding_ctx[15].button, 125, 35);

    // Place components on the container
    gtk_fixed_put(fixed_container, label_key_binding, 350, 15);
    gtk_fixed_put(fixed_container, key_binding_ctx[1].button, 420, 10);
    gtk_fixed_put(fixed_container, key_binding_ctx[2].button, 550, 10);
    gtk_fixed_put(fixed_container, key_binding_ctx[3].button, 680, 10);
    gtk_fixed_put(fixed_container, key_binding_ctx[12].button, 810, 10);
    gtk_fixed_put(fixed_container, key_binding_ctx[4].button, 420, 50);
    gtk_fixed_put(fixed_container, key_binding_ctx[5].button, 550, 50);
    gtk_fixed_put(fixed_container, key_binding_ctx[6].button, 680, 50);
    gtk_fixed_put(fixed_container, key_binding_ctx[13].button, 810, 50);
    gtk_fixed_put(fixed_container, key_binding_ctx[7].button, 420, 90);
    gtk_fixed_put(fixed_container, key_binding_ctx[8].button, 550, 90);
    gtk_fixed_put(fixed_container, key_binding_ctx[9].button, 680, 90);
    gtk_fixed_put(fixed_container, key_binding_ctx[14].button, 810, 90);
    gtk_fixed_put(fixed_container, key_binding_ctx[10].button, 420, 130);
    gtk_fixed_put(fixed_container, key_binding_ctx[0].button, 550, 130);
    gtk_fixed_put(fixed_container, key_binding_ctx[11].button, 680, 130);
    gtk_fixed_put(fixed_container, key_binding_ctx[15].button, 810, 130);

    // Connect signals
    g_signal_connect(key_binding_ctx[0].button,
                     "destroy",
                     G_CALLBACK(gui_settings_callback_window_destroy_force),
                     key_binding_ctx);
    g_signal_connect(key_binding_ctx[0].button,
                     "clicked",
                     G_CALLBACK(gui_settings_callback_btn_input_key),
                     (s_gui_key_binding_context *) &key_binding_ctx[0]);
    g_signal_connect(key_binding_ctx[1].button,
                     "clicked",
                     G_CALLBACK(gui_settings_callback_btn_input_key),
                     (s_gui_key_binding_context *) &key_binding_ctx[1]);
    g_signal_connect(key_binding_ctx[2].button,
                     "clicked",
                     G_CALLBACK(gui_settings_callback_btn_input_key),
                     (s_gui_key_binding_context *) &key_binding_ctx[2]);
    g_signal_connect(key_binding_ctx[3].button,
                     "clicked",
                     G_CALLBACK(gui_settings_callback_btn_input_key),
                     (s_gui_key_binding_context *) &key_binding_ctx[3]);
    g_signal_connect(key_binding_ctx[4].button,
                     "clicked",
                     G_CALLBACK(gui_settings_callback_btn_input_key),
                     (s_gui_key_binding_context *) &key_binding_ctx[4]);
    g_signal_connect(key_binding_ctx[5].button,
                     "clicked",
                     G_CALLBACK(gui_settings_callback_btn_input_key),
                     (s_gui_key_binding_context *) &key_binding_ctx[5]);
    g_signal_connect(key_binding_ctx[6].button,
                     "clicked",
                     G_CALLBACK(gui_settings_callback_btn_input_key),
                     (s_gui_key_binding_context *) &key_binding_ctx[6]);
    g_signal_connect(key_binding_ctx[7].button,
                     "clicked",
                     G_CALLBACK(gui_settings_callback_btn_input_key),
                     (s_gui_key_binding_context *) &key_binding_ctx[7]);
    g_signal_connect(key_binding_ctx[8].button,
                     "clicked",
                     G_CALLBACK(gui_settings_callback_btn_input_key),
                     (s_gui_key_binding_context *) &key_binding_ctx[8]);
    g_signal_connect(key_binding_ctx[9].button,
                     "clicked",
                     G_CALLBACK(gui_settings_callback_btn_input_key),
                     (s_gui_key_binding_context *) &key_binding_ctx[9]);
    g_signal_connect(key_binding_ctx[10].button,
                     "clicked",
                     G_CALLBACK(gui_settings_callback_btn_input_key),
                     (s_gui_key_binding_context *) &key_binding_ctx[10]);
    g_signal_connect(key_binding_ctx[11].button,
                     "clicked",
                     G_CALLBACK(gui_settings_callback_btn_input_key),
                     (s_gui_key_binding_context *) &key_binding_ctx[11]);
    g_signal_connect(key_binding_ctx[12].button,
                     "clicked",
                     G_CALLBACK(gui_settings_callback_btn_input_key),
                     (s_gui_key_binding_context *) &key_binding_ctx[12]);
    g_signal_connect(key_binding_ctx[13].button,
                     "clicked",
                     G_CALLBACK(gui_settings_callback_btn_input_key),
                     (s_gui_key_binding_context *) &key_binding_ctx[13]);
    g_signal_connect(key_binding_ctx[14].button,
                     "clicked",
                     G_CALLBACK(gui_settings_callback_btn_input_key),
                     (s_gui_key_binding_context *) &key_binding_ctx[14]);
    g_signal_connect(key_binding_ctx[15].button,
                     "clicked",
                     G_CALLBACK(gui_settings_callback_btn_input_key),
                     (s_gui_key_binding_context *) &key_binding_ctx[15]);
}
