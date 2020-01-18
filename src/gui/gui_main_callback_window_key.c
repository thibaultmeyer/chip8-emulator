#include "gui.h"

gboolean gui_main_callback_window_key(GtkWidget *widget, GdkEventKey *event, gpointer data) {
    if (gl_gui_components.chip8_cpu) {
        uint8_t value = event->type == GDK_KEY_PRESS ? 1 : 0;
        switch (event->keyval) {
            case GDK_KEY_ampersand:
                gl_gui_components.chip8_cpu->keyboard[1] = value;
                break;
            case GDK_KEY_eacute:
                gl_gui_components.chip8_cpu->keyboard[2] = value;
                break;
            case GDK_KEY_quotedbl:
                gl_gui_components.chip8_cpu->keyboard[3] = value;
                break;
            case GDK_KEY_apostrophe:
                gl_gui_components.chip8_cpu->keyboard[12] = value;
                break;
            case GDK_KEY_a:
                gl_gui_components.chip8_cpu->keyboard[4] = value;
                break;
            case GDK_KEY_z:
                gl_gui_components.chip8_cpu->keyboard[5] = value;
                break;
            case GDK_KEY_e:
                gl_gui_components.chip8_cpu->keyboard[6] = value;
                break;
            case GDK_KEY_r:
                gl_gui_components.chip8_cpu->keyboard[13] = value;
                break;
            case GDK_KEY_q:
                gl_gui_components.chip8_cpu->keyboard[7] = value;
                break;
            case GDK_KEY_s:
                gl_gui_components.chip8_cpu->keyboard[8] = value;
                break;
            case GDK_KEY_d:
                gl_gui_components.chip8_cpu->keyboard[9] = value;
                break;
            case GDK_KEY_f:
                gl_gui_components.chip8_cpu->keyboard[14] = value;
                break;
            case GDK_KEY_w:
                gl_gui_components.chip8_cpu->keyboard[10] = value;
                break;
            case GDK_KEY_x:
                gl_gui_components.chip8_cpu->keyboard[0] = value;
                break;
            case GDK_KEY_c:
                gl_gui_components.chip8_cpu->keyboard[11] = value;
                break;
            case GDK_KEY_v:
                gl_gui_components.chip8_cpu->keyboard[15] = value;
                break;
            default:
                break;
        }
    }

    return FALSE;
}
