#include "gui/gui.h"
#include "sound/sound.h"

/**
 * Entry point.
 *
 * @param argc Number of arguments
 * @param argv Arguments
 * @return Application status
 */
int main(int argc, char **argv) {
    // Initialize sound engine
    sound_initialize();

    // Initialize GTK
    gtk_init(&argc, &argv);
    GtkApplication *app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(gui_main_callback_app_activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    // Destroy sound engine
    sound_destroy();

    // Return status
    return status;
}
