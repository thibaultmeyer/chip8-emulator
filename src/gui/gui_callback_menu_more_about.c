#include "gui.h"
#include "gui_image_logo.h"
#include "version.h"

void gui_callback_menu_more_about(GtkApplication *app, gpointer user_data) {
    GdkPixbuf *pixbuf = gui_image_load_from_memory_scale(gui_image_logo_bytes, gui_image_logo_length, 64, 64);

    gtk_show_about_dialog(GTK_WINDOW(gl_gui_components.gtk_window),
                          "comments", CHIP8EMU_DESCRIPTION,
                          "copyright", CHIP8EMU_COPYRIGHT,
                          "license_type", GTK_LICENSE_MIT_X11,
                          "logo", pixbuf,
                          "program_name", CHIP8EMU_APPNAME,
                          "version", CHIP8EMU_VERSION,
                          "website", CHIP8EMU_WEBSITE,
                          NULL);
    g_object_unref(pixbuf);
}
