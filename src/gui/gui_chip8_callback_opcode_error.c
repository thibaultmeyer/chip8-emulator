#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "gui.h"

void gui_chip8_callback_opcode_error(void) {
    gui_emulation_timer_stop();

    char *buffer_cpu = NULL;
    asprintf(&buffer_cpu,
             "OPCODE = 0x%X\nPC = %d\nI = %d\nJUMP COUNT = %d",
             gl_gui_components.chip8_cpu->current_opcode,
             gl_gui_components.chip8_cpu->pc,
             gl_gui_components.chip8_cpu->i,
             gl_gui_components.chip8_cpu->nb_jump);

    char          *buffer_register = NULL;
    for (uint32_t idx              = 0; idx < CHIP8_NB_REGISTER; ++idx) {
        if (buffer_register == NULL) {
            asprintf(&buffer_register, "register[%d] = 0x%X", idx, gl_gui_components.chip8_cpu->reg[idx]);
        } else {
            char *tmp = buffer_register;
            asprintf(&buffer_register, "%s\nregister[%d] = 0x%X", tmp, idx, gl_gui_components.chip8_cpu->reg[idx]);
            free(tmp);
        }
    }

    GtkWidget *error_msg_dialog = gtk_message_dialog_new(GTK_WINDOW(gl_gui_components.gtk_window),
                                                         GTK_DIALOG_DESTROY_WITH_PARENT,
                                                         GTK_MESSAGE_ERROR,
                                                         GTK_BUTTONS_CLOSE,
                                                         "%s\n\n%s\n\n%s",
                                                         "Operation Code Error",
                                                         buffer_cpu,
                                                         buffer_register);
    gtk_dialog_run(GTK_DIALOG(error_msg_dialog));
    gtk_widget_destroy(error_msg_dialog);
    free(buffer_cpu);
    free(buffer_register);
}
