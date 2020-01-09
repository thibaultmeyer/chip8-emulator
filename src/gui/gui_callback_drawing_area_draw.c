#include "gui.h"

gboolean gui_callback_drawing_area_draw(GtkWidget *widget, cairo_t *cr, void *data) {
    GdkRGBA color_black = {0, 0, 0, 255};
    GdkRGBA color_white = {255, 255, 255, 255};

    if (gl_gui_components.chip8_cpu) {
        gdk_cairo_set_source_rgba(cr, &color_black);
        cairo_rectangle(cr, 0, 0, gl_gui_components.chip8_screen_width, gl_gui_components.chip8_screen_height);
        cairo_fill(cr);

        gdk_cairo_set_source_rgba(cr, &color_white);
        for (uint8_t y = 0; y < CHIP8_VIDEO_DIM_HEIGHT; ++y) {
            for (uint8_t x = 0; x < CHIP8_VIDEO_DIM_WIDTH; ++x) {
                if (gl_gui_components.chip8_cpu->video[y][x] == 1) {
                    cairo_rectangle(cr,
                                    x * gl_gui_components.chip8_screen_pixel_ratio,
                                    y * gl_gui_components.chip8_screen_pixel_ratio,
                                    gl_gui_components.chip8_screen_pixel_ratio,
                                    gl_gui_components.chip8_screen_pixel_ratio);
                    cairo_fill(cr);
                }
            }
        }
    } else {
        cairo_rectangle(cr, 0, 0, 640, 320);
        gdk_cairo_set_source_rgba(cr, &color_black);
        cairo_fill(cr);
    }

    return TRUE;
}
