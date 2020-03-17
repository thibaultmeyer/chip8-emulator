#include "gui.h"

void gui_settings_init_cpu_frequency(GtkFixed *fixed_container) {
    // Available frequencies
    static const s_gui_settings_combobox_value frequencies[] = {
            {1,    "1 Hz"},
            {5,    "5 Hz"},
            {50,   "50 Hz"},
            {100,  "100 Hz"},
            {200,  "200 Hz"},
            {250,  "250 Hz"},
            {333,  "333 Hz"},
            {500,  "500 Hz"},
            {1000, "1000 Hz"},
            {-1, NULL},
    };

    // Create label and pre-filled combobox
    GtkWidget       *label_cpu_frequency = gtk_label_new("CPU Frequency");
    GtkListStore    *model_frequency     = gtk_list_store_new(2, G_TYPE_INT, G_TYPE_STRING);
    GtkWidget       *combo_cpu_frequency = gtk_combo_box_new_with_model(GTK_TREE_MODEL(model_frequency));
    GtkCellRenderer *cell_renderer;
    GtkTreeIter     iter;

    cell_renderer = gtk_cell_renderer_text_new();
    gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(combo_cpu_frequency), cell_renderer, FALSE);
    gtk_cell_layout_set_attributes(
            GTK_CELL_LAYOUT(combo_cpu_frequency),
            cell_renderer, "text", 1,
            NULL
    );

    for (uint32_t idx = 0; frequencies[idx].key != -1; ++idx) {
        gtk_list_store_append(model_frequency, &iter);
        gtk_list_store_set(model_frequency, &iter,
                           0, frequencies[idx].key, 1, frequencies[idx].value,
                           -1);

        if (frequencies[idx].key == gl_gui_settings.cpu_frequency) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(combo_cpu_frequency), idx);
        }
    }

    // Connect signal
    g_signal_connect(combo_cpu_frequency, "changed", G_CALLBACK(gui_settings_callback_combobox_cpu_frequency), NULL);

    // Place components on the container
    gtk_fixed_put(fixed_container, label_cpu_frequency, 10, 65);
    gtk_fixed_put(fixed_container, combo_cpu_frequency, 170, 60);
}
