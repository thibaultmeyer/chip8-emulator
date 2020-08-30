#include <libintl.h>
#include <stdlib.h>
#include "gui.h"

void gui_main_callback_header_bar_load_rom(GtkApplication *app, gpointer user_data) {
    // Create a file chooser dialog
    GtkWidget *dialog = gtk_file_chooser_dialog_new("Load a ROM",
                                                    GTK_WINDOW(gl_gui_components.gtk_window),
                                                    GTK_FILE_CHOOSER_ACTION_OPEN,
                                                    gettext("_Cancel"),
                                                    GTK_RESPONSE_CANCEL,
                                                    gettext("_Open"),
                                                    GTK_RESPONSE_ACCEPT,
                                                    NULL);

    // Defines file filter
    GtkFileFilter *filter = gtk_file_filter_new();
    gtk_file_filter_set_name(GTK_FILE_FILTER(filter), "Chip8 ROM");
    gtk_file_filter_add_pattern(GTK_FILE_FILTER(filter), "*.ch8");
    gtk_file_chooser_set_filter(GTK_FILE_CHOOSER(dialog), filter);

    // Open dialog
    gint res = gtk_dialog_run(GTK_DIALOG(dialog));
    if (res == GTK_RESPONSE_ACCEPT) {
        // Retrieve selected filename
        GtkFileChooser *chooser  = GTK_FILE_CHOOSER(dialog);
        gchar          *filename = gtk_file_chooser_get_filename(chooser);

        // Destroy file chooser dialog
        gtk_widget_destroy(dialog);

        // Initialize a new chip8 CPU
        s_chip8_cpu *cpu = (s_chip8_cpu *) malloc(sizeof(s_chip8_cpu));
        if (cpu != NULL) {
            chip8_initialize(cpu, &gui_chip8_callback_opcode_error, &gui_chip8_callback_play_sound);

            // Load ROM
            GtkWidget        *error_msg_dialog = NULL;
            e_loadrom_status status = chip8_load_rom(cpu, filename);
            switch (status) {
                case LOAD_ROM_STATUS_ERROR_NOT_A_VALID_FILE: {
                    error_msg_dialog = gtk_message_dialog_new(GTK_WINDOW(gl_gui_components.gtk_window),
                                                              GTK_DIALOG_DESTROY_WITH_PARENT,
                                                              GTK_MESSAGE_ERROR,
                                                              GTK_BUTTONS_CLOSE,
                                                              "Not a valid ROM file");
                    gtk_dialog_run(GTK_DIALOG(error_msg_dialog));
                    gtk_widget_destroy(error_msg_dialog);
                    free(cpu);
                    break;
                }
                case LOAD_ROM_STATUS_ERROR_FILE_TOO_BIG: {
                    error_msg_dialog = gtk_message_dialog_new(GTK_WINDOW(gl_gui_components.gtk_window),
                                                              GTK_DIALOG_DESTROY_WITH_PARENT,
                                                              GTK_MESSAGE_ERROR,
                                                              GTK_BUTTONS_CLOSE,
                                                              "ROM file is too big");
                    gtk_dialog_run(GTK_DIALOG(error_msg_dialog));
                    gtk_widget_destroy(error_msg_dialog);
                    free(cpu);
                    break;
                }
                case LOAD_ROM_STATUS_ERROR_CANT_OPEN_FILE: {
                    error_msg_dialog = gtk_message_dialog_new(GTK_WINDOW(gl_gui_components.gtk_window),
                                                              GTK_DIALOG_DESTROY_WITH_PARENT,
                                                              GTK_MESSAGE_ERROR,
                                                              GTK_BUTTONS_CLOSE,
                                                              "Can't open ROM file");
                    gtk_dialog_run(GTK_DIALOG(error_msg_dialog));
                    gtk_widget_destroy(error_msg_dialog);
                    free(cpu);
                    break;
                }
                case LOAD_ROM_STATUS_ERROR_READ_ERROR: {
                    error_msg_dialog = gtk_message_dialog_new(GTK_WINDOW(gl_gui_components.gtk_window),
                                                              GTK_DIALOG_DESTROY_WITH_PARENT,
                                                              GTK_MESSAGE_ERROR,
                                                              GTK_BUTTONS_CLOSE,
                                                              "Cannot read the whole ROM file");
                    gtk_dialog_run(GTK_DIALOG(error_msg_dialog));
                    gtk_widget_destroy(error_msg_dialog);
                    free(cpu);
                    break;
                }
                default:
                    // Stop emulation
                    gui_emulation_timer_stop();

                    // Use newly created CPU instance
                    if (gl_gui_components.chip8_cpu) {
                        chip8_free_cpu(gl_gui_components.chip8_cpu);
                    }
                    gl_gui_components.chip8_cpu = cpu;

                    // Update UI
                    gchar *basename = g_filename_display_basename(filename);
                    gtk_header_bar_set_subtitle(GTK_HEADER_BAR(gl_gui_components.gtk_header_bar), basename);

                    // Keep ROM basename for load/save state
                    if (gl_gui_components.current_rom_name != NULL) {
                        g_free(gl_gui_components.current_rom_name);
                    }
                    gl_gui_components.current_rom_name = basename;

                    // Start emulation
                    gui_emulation_timer_start();
                    break;
            }
        }

        // Free memory
        g_free(filename);
    } else {
        // Destroy file chooser dialog
        gtk_widget_destroy(dialog);
    }
}
