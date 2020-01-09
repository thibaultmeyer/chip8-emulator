#include "gui.h"

void gui_callback_drawing_area_new_size(GtkWidget *widget, GtkAllocation *allocation, void *data) {
    gl_gui_components.chip8_screen_pixel_ratio = allocation->width / 64;
    printf("Pixel ratio: %d\n", gl_gui_components.chip8_screen_pixel_ratio);
}
