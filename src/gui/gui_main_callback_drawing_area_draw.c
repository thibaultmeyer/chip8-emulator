#include "gui.h"

gboolean gui_main_callback_drawing_area_draw(GtkWidget *widget, cairo_t *cr, void *data) {
    if (gl_gui_components.chip8_cpu) {
        gdk_cairo_set_source_rgba(cr, &gl_gui_settings.color_background);
        cairo_rectangle(cr, 0, 0, gl_gui_components.chip8_screen_width, gl_gui_components.chip8_screen_height);
        cairo_fill(cr);

        gdk_cairo_set_source_rgba(cr, &gl_gui_settings.color_foreground);
        for (uint8_t y = 0; y < CHIP8_VIDEO_DIM_HEIGHT; ++y) {
            for (uint8_t x = 0; x < CHIP8_VIDEO_DIM_WIDTH; ++x) {
                if (gl_gui_components.chip8_cpu->video[y][x] == 1) {
                    cairo_rectangle(cr,
                                    (x * gl_gui_components.chip8_screen_pixel_ratio)
                                    + gl_gui_components.chip8_screen_offset_width,
                                    (y * gl_gui_components.chip8_screen_pixel_ratio)
                                    + gl_gui_components.chip8_screen_offset_height,
                                    gl_gui_components.chip8_screen_pixel_ratio,
                                    gl_gui_components.chip8_screen_pixel_ratio);
                    cairo_fill(cr);
                }
            }
        }
    } else {
        cairo_rectangle(cr, 0, 0, gl_gui_components.chip8_screen_width, gl_gui_components.chip8_screen_height);
        gdk_cairo_set_source_rgba(cr, &gl_gui_settings.color_background);
        cairo_fill(cr);
    }

    return TRUE;
}
