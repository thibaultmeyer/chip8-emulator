#include "gui/gui.h"

#ifdef HAVE_AUDIO_BACKEND

# include "sound/sound.h"

#endif

/**
 * Entry point.
 *
 * @param argc Number of arguments
 * @param argv Arguments
 * @return Application status
 */
int main(int argc, char **argv) {
#ifdef HAVE_AUDIO_BACKEND
    // Initialize sound engine
    sound_initialize();
#endif

    // Initialize GTK
    gtk_init(&argc, &argv);
    GtkApplication *app = gtk_application_new("com.github.thibaultmeyer.chip8-emulator", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(gui_main_callback_app_activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

#ifdef HAVE_AUDIO_BACKEND
    // Destroy sound engine
    sound_destroy();
#endif

    // Return status
    return (status);
}
