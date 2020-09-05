#include "gui.h"

void gui_main_callback_drawing_area_new_size(GtkWidget *widget, GtkAllocation *allocation, void *data) {
    gl_gui_components.chip8_screen_height = allocation->height;
    gl_gui_components.chip8_screen_width  = allocation->width;

    uint32_t new_pixel_ratio = allocation->width / CHIP8_VIDEO_DIM_WIDTH;
    if (new_pixel_ratio * CHIP8_VIDEO_DIM_HEIGHT <= allocation->height) {
        gl_gui_components.chip8_screen_pixel_ratio = new_pixel_ratio;
    } else {
        gl_gui_components.chip8_screen_pixel_ratio = allocation->height / CHIP8_VIDEO_DIM_HEIGHT;
    }
}
