#include "gui.h"

void gui_settings_init_display_mode(GtkFixed *fixed_container) {
    // Available display modes
    static const s_gui_settings_combobox_value screen_mode[] = {
            {0, "Normal"},
            {1, "Phosphor"},
            {-1, NULL},
    };

    // Create label and pre-filled combobox
    GtkWidget       *label_display_mode = gtk_label_new("Display Mode");
    GtkListStore    *model_display      = gtk_list_store_new(2, G_TYPE_INT, G_TYPE_STRING);
    GtkWidget       *combo_display_mode = gtk_combo_box_new_with_model(GTK_TREE_MODEL(model_display));
    GtkCellRenderer *cell_renderer2;
    GtkTreeIter     iter2;

    cell_renderer2 = gtk_cell_renderer_text_new();
    gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(combo_display_mode), cell_renderer2, FALSE);
    gtk_cell_layout_set_attributes(
            GTK_CELL_LAYOUT (combo_display_mode),
            cell_renderer2, "text", 1,
            NULL
    );

    for (uint32_t idx = 0; screen_mode[idx].key != -1; ++idx) {
        gtk_list_store_append(model_display, &iter2);
        gtk_list_store_set(model_display, &iter2,
                           0, screen_mode[idx].key, 1, screen_mode[idx].value,
                           -1);

        if (screen_mode[idx].key == gl_gui_settings.display_mode) {
            gtk_combo_box_set_active(GTK_COMBO_BOX(combo_display_mode), idx);
        }
    }

    // Connect signal
    //g_signal_connect(combo_display_mode, "changed", G_CALLBACK(), NULL);

    // Disable widget
    gtk_widget_set_sensitive(combo_display_mode, FALSE);

    // Place components on the container
    gtk_fixed_put(fixed_container, label_display_mode, 10, 15);
    gtk_fixed_put(fixed_container, combo_display_mode, 170, 10);
}
