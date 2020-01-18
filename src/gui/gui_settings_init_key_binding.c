#include "gui.h"

void gui_settings_init_key_binding(GtkFixed *fixed_container) {
    // Create label and entry components
    GtkWidget *label_key_binding = gtk_label_new("Keys");
    GtkWidget *entry_key_0       = gtk_entry_new();
    GtkWidget *entry_key_1       = gtk_entry_new();
    GtkWidget *entry_key_2       = gtk_entry_new();
    GtkWidget *entry_key_3       = gtk_entry_new();
    GtkWidget *entry_key_4       = gtk_entry_new();
    GtkWidget *entry_key_5       = gtk_entry_new();
    GtkWidget *entry_key_6       = gtk_entry_new();
    GtkWidget *entry_key_7       = gtk_entry_new();
    GtkWidget *entry_key_8       = gtk_entry_new();
    GtkWidget *entry_key_9       = gtk_entry_new();
    GtkWidget *entry_key_A       = gtk_entry_new();
    GtkWidget *entry_key_B       = gtk_entry_new();
    GtkWidget *entry_key_C       = gtk_entry_new();
    GtkWidget *entry_key_D       = gtk_entry_new();
    GtkWidget *entry_key_E       = gtk_entry_new();
    GtkWidget *entry_key_F       = gtk_entry_new();

    // Configure entry components
    gtk_entry_set_max_length(GTK_ENTRY(entry_key_0), 1);
    gtk_entry_set_width_chars(GTK_ENTRY(entry_key_0), 2);
    gtk_entry_set_alignment(GTK_ENTRY(entry_key_0), 0.5);
    gtk_entry_set_max_length(GTK_ENTRY(entry_key_1), 1);
    gtk_entry_set_width_chars(GTK_ENTRY(entry_key_1), 2);
    gtk_entry_set_alignment(GTK_ENTRY(entry_key_1), 0.5);
    gtk_entry_set_max_length(GTK_ENTRY(entry_key_2), 1);
    gtk_entry_set_width_chars(GTK_ENTRY(entry_key_2), 2);
    gtk_entry_set_alignment(GTK_ENTRY(entry_key_2), 0.5);
    gtk_entry_set_max_length(GTK_ENTRY(entry_key_3), 1);
    gtk_entry_set_width_chars(GTK_ENTRY(entry_key_3), 2);
    gtk_entry_set_alignment(GTK_ENTRY(entry_key_3), 0.5);
    gtk_entry_set_max_length(GTK_ENTRY(entry_key_4), 1);
    gtk_entry_set_width_chars(GTK_ENTRY(entry_key_4), 2);
    gtk_entry_set_alignment(GTK_ENTRY(entry_key_4), 0.5);
    gtk_entry_set_max_length(GTK_ENTRY(entry_key_5), 1);
    gtk_entry_set_width_chars(GTK_ENTRY(entry_key_5), 2);
    gtk_entry_set_alignment(GTK_ENTRY(entry_key_5), 0.5);
    gtk_entry_set_max_length(GTK_ENTRY(entry_key_6), 1);
    gtk_entry_set_width_chars(GTK_ENTRY(entry_key_6), 2);
    gtk_entry_set_alignment(GTK_ENTRY(entry_key_6), 0.5);
    gtk_entry_set_max_length(GTK_ENTRY(entry_key_7), 1);
    gtk_entry_set_width_chars(GTK_ENTRY(entry_key_7), 2);
    gtk_entry_set_alignment(GTK_ENTRY(entry_key_7), 0.5);
    gtk_entry_set_max_length(GTK_ENTRY(entry_key_8), 1);
    gtk_entry_set_width_chars(GTK_ENTRY(entry_key_8), 2);
    gtk_entry_set_alignment(GTK_ENTRY(entry_key_8), 0.5);
    gtk_entry_set_max_length(GTK_ENTRY(entry_key_9), 1);
    gtk_entry_set_width_chars(GTK_ENTRY(entry_key_9), 2);
    gtk_entry_set_alignment(GTK_ENTRY(entry_key_9), 0.5);
    gtk_entry_set_max_length(GTK_ENTRY(entry_key_A), 1);
    gtk_entry_set_width_chars(GTK_ENTRY(entry_key_A), 2);
    gtk_entry_set_alignment(GTK_ENTRY(entry_key_A), 0.5);
    gtk_entry_set_max_length(GTK_ENTRY(entry_key_B), 1);
    gtk_entry_set_width_chars(GTK_ENTRY(entry_key_B), 2);
    gtk_entry_set_alignment(GTK_ENTRY(entry_key_B), 0.5);
    gtk_entry_set_max_length(GTK_ENTRY(entry_key_C), 1);
    gtk_entry_set_width_chars(GTK_ENTRY(entry_key_C), 2);
    gtk_entry_set_alignment(GTK_ENTRY(entry_key_C), 0.5);
    gtk_entry_set_max_length(GTK_ENTRY(entry_key_D), 1);
    gtk_entry_set_width_chars(GTK_ENTRY(entry_key_D), 2);
    gtk_entry_set_alignment(GTK_ENTRY(entry_key_D), 0.5);
    gtk_entry_set_max_length(GTK_ENTRY(entry_key_E), 1);
    gtk_entry_set_width_chars(GTK_ENTRY(entry_key_E), 2);
    gtk_entry_set_alignment(GTK_ENTRY(entry_key_E), 0.5);
    gtk_entry_set_max_length(GTK_ENTRY(entry_key_F), 1);
    gtk_entry_set_width_chars(GTK_ENTRY(entry_key_F), 2);
    gtk_entry_set_alignment(GTK_ENTRY(entry_key_F), 0.5);

    // Restore values
    gchar *text = g_malloc0(2);
    text[0] = gl_gui_settings.keybinding[0];
    gtk_entry_set_text(GTK_ENTRY(entry_key_0), text);
    text[0] = gl_gui_settings.keybinding[1];
    gtk_entry_set_text(GTK_ENTRY(entry_key_1), text);
    text[0] = gl_gui_settings.keybinding[2];
    gtk_entry_set_text(GTK_ENTRY(entry_key_2), text);
    text[0] = gl_gui_settings.keybinding[3];
    gtk_entry_set_text(GTK_ENTRY(entry_key_3), text);
    text[0] = gl_gui_settings.keybinding[4];
    gtk_entry_set_text(GTK_ENTRY(entry_key_4), text);
    text[0] = gl_gui_settings.keybinding[5];
    gtk_entry_set_text(GTK_ENTRY(entry_key_5), text);
    text[0] = gl_gui_settings.keybinding[6];
    gtk_entry_set_text(GTK_ENTRY(entry_key_6), text);
    text[0] = gl_gui_settings.keybinding[7];
    gtk_entry_set_text(GTK_ENTRY(entry_key_7), text);
    text[0] = gl_gui_settings.keybinding[8];
    gtk_entry_set_text(GTK_ENTRY(entry_key_8), text);
    text[0] = gl_gui_settings.keybinding[9];
    gtk_entry_set_text(GTK_ENTRY(entry_key_9), text);
    text[0] = gl_gui_settings.keybinding[10];
    gtk_entry_set_text(GTK_ENTRY(entry_key_A), text);
    text[0] = gl_gui_settings.keybinding[11];
    gtk_entry_set_text(GTK_ENTRY(entry_key_B), text);
    text[0] = gl_gui_settings.keybinding[12];
    gtk_entry_set_text(GTK_ENTRY(entry_key_C), text);
    text[0] = gl_gui_settings.keybinding[13];
    gtk_entry_set_text(GTK_ENTRY(entry_key_D), text);
    text[0] = gl_gui_settings.keybinding[14];
    gtk_entry_set_text(GTK_ENTRY(entry_key_E), text);
    text[0] = gl_gui_settings.keybinding[15];
    gtk_entry_set_text(GTK_ENTRY(entry_key_F), text);
    g_free(text);

    // Connect signal
    g_signal_connect(entry_key_0, "changed", G_CALLBACK(gui_settings_callback_input_key), (void *) 0);
    g_signal_connect(entry_key_1, "changed", G_CALLBACK(gui_settings_callback_input_key), (void *) 1);
    g_signal_connect(entry_key_2, "changed", G_CALLBACK(gui_settings_callback_input_key), (void *) 2);
    g_signal_connect(entry_key_3, "changed", G_CALLBACK(gui_settings_callback_input_key), (void *) 3);
    g_signal_connect(entry_key_4, "changed", G_CALLBACK(gui_settings_callback_input_key), (void *) 4);
    g_signal_connect(entry_key_5, "changed", G_CALLBACK(gui_settings_callback_input_key), (void *) 5);
    g_signal_connect(entry_key_6, "changed", G_CALLBACK(gui_settings_callback_input_key), (void *) 6);
    g_signal_connect(entry_key_7, "changed", G_CALLBACK(gui_settings_callback_input_key), (void *) 7);
    g_signal_connect(entry_key_8, "changed", G_CALLBACK(gui_settings_callback_input_key), (void *) 8);
    g_signal_connect(entry_key_9, "changed", G_CALLBACK(gui_settings_callback_input_key), (void *) 9);
    g_signal_connect(entry_key_A, "changed", G_CALLBACK(gui_settings_callback_input_key), (void *) 10);
    g_signal_connect(entry_key_B, "changed", G_CALLBACK(gui_settings_callback_input_key), (void *) 11);
    g_signal_connect(entry_key_C, "changed", G_CALLBACK(gui_settings_callback_input_key), (void *) 12);
    g_signal_connect(entry_key_D, "changed", G_CALLBACK(gui_settings_callback_input_key), (void *) 13);
    g_signal_connect(entry_key_E, "changed", G_CALLBACK(gui_settings_callback_input_key), (void *) 14);
    g_signal_connect(entry_key_F, "changed", G_CALLBACK(gui_settings_callback_input_key), (void *) 15);

    // Place components on the container
    gtk_fixed_put(fixed_container, label_key_binding, 350, 15);
    gtk_fixed_put(fixed_container, entry_key_1, 420, 10);
    gtk_fixed_put(fixed_container, entry_key_2, 460, 10);
    gtk_fixed_put(fixed_container, entry_key_3, 500, 10);
    gtk_fixed_put(fixed_container, entry_key_C, 540, 10);
    gtk_fixed_put(fixed_container, entry_key_4, 420, 50);
    gtk_fixed_put(fixed_container, entry_key_5, 460, 50);
    gtk_fixed_put(fixed_container, entry_key_6, 500, 50);
    gtk_fixed_put(fixed_container, entry_key_D, 540, 50);
    gtk_fixed_put(fixed_container, entry_key_7, 420, 90);
    gtk_fixed_put(fixed_container, entry_key_8, 460, 90);
    gtk_fixed_put(fixed_container, entry_key_9, 500, 90);
    gtk_fixed_put(fixed_container, entry_key_E, 540, 90);
    gtk_fixed_put(fixed_container, entry_key_A, 420, 130);
    gtk_fixed_put(fixed_container, entry_key_0, 460, 130);
    gtk_fixed_put(fixed_container, entry_key_B, 500, 130);
    gtk_fixed_put(fixed_container, entry_key_F, 540, 130);

    //uint32_t t = ;
}
