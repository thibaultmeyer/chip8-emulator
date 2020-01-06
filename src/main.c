#include "gui/gui.h"

/**
 * Entry point.
 *
 * @param argc Number of arguments
 * @param argv Arguments
 * @return Application status
 */
int main(int argc, char **argv) {
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Initialize GTK
    GtkApplication *app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK(gui_callback_app_activate), NULL);
    int status = g_application_run(G_APPLICATION (app), argc, argv);
    g_object_unref(app);

    return status;
}
