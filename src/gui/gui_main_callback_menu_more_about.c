#include "gui.h"
#include "gui_image_logo.h"
#include "../version.h"

void gui_main_callback_menu_more_about(GtkMenuItem *menuitem, gpointer user_data) {
    (void) menuitem;   // Unused parameter
    (void) user_data;  // Unused parameter

    GdkPixbuf      *pixbuf    = gui_image_load_from_memory_scale(gui_image_logo_bytes, gui_image_logo_length, 64, 64);
    GtkAboutDialog *gtk_about = GTK_ABOUT_DIALOG(gtk_about_dialog_new());

    gtk_about_dialog_set_comments(gtk_about, CHIP8EMU_DESCRIPTION);
    gtk_about_dialog_set_copyright(gtk_about, CHIP8EMU_COPYRIGHT);
    gtk_about_dialog_set_license_type(gtk_about, GTK_LICENSE_MIT_X11);
    gtk_about_dialog_set_logo(gtk_about, pixbuf);
    gtk_about_dialog_set_program_name(gtk_about, CHIP8EMU_APPNAME);
    gtk_about_dialog_set_version(gtk_about, CHIP8EMU_VERSION);
    gtk_about_dialog_set_website(gtk_about, CHIP8EMU_WEBSITE);

    gtk_window_set_transient_for(GTK_WINDOW(gtk_about), GTK_WINDOW(gl_gui_components.gtk_window));
    gtk_dialog_run(GTK_DIALOG(gtk_about));

    g_object_unref(pixbuf);
    gtk_widget_destroy(GTK_WIDGET(gtk_about));
}
