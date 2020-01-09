#include "gui.h"

void gui_callback_drawing_area_new_size(GtkWidget *widget, GtkAllocation *allocation, void *data) {
    gl_gui_components.chip8_screen_height      = allocation->height;
    gl_gui_components.chip8_screen_width       = allocation->width;
    gl_gui_components.chip8_screen_pixel_ratio = allocation->width / 64;
}
