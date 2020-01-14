#include "gui.h"

void gui_settings_callback_combobox_cpu_frequency(GtkComboBox *widget, gpointer user_data) {
    uint32_t    value;
    gboolean    res;
    GtkTreeIter iter;

    // Retrieve current value
    res = gtk_combo_box_get_active_iter(widget, &iter);
    if (res) {
        GtkTreeModel *tree_model = gtk_combo_box_get_model(widget);
        if (tree_model != NULL) {
            gtk_tree_model_get(tree_model, &iter, 0, &value, -1);

            gl_gui_settings.cpu_frequency = value;
            gui_emulation_timer_stop();
            gui_emulation_timer_start();
        }
    }

    // Persists settings
    gui_toolbox_save_settings_to_file();
}
