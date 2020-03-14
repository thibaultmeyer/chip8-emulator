#include <stdlib.h>
#include "gui.h"

void gui_toolbox_create_storage_directory(void) {
    // Storage directory path
    gchar *dirpath = gui_toolbox_get_storage_file_path("");

    // Create directory if not exists
    if (g_mkdir_with_parents(dirpath, 0755) != 0) {

        // Error
        GtkWidget *error_msg_dialog = gtk_message_dialog_new(GTK_WINDOW(gl_gui_components.gtk_window),
                                                             GTK_DIALOG_DESTROY_WITH_PARENT,
                                                             GTK_MESSAGE_ERROR,
                                                             GTK_BUTTONS_CLOSE,
                                                             "%s\n%s\n\n%s",
                                                             "Can't create storage directory!",
                                                             "Please check you home directory access permissions.",
                                                             dirpath);
        gtk_dialog_run(GTK_DIALOG(error_msg_dialog));
        gtk_widget_destroy(error_msg_dialog);

        gtk_main_quit();
        exit(-1);
    }

    // Free allocated variable
    g_free(dirpath);
}
