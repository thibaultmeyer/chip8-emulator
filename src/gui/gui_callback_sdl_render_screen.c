#include "gui.h"

gboolean gui_callback_sdl_render_screen() {
    // Clear the current rendering target with the drawing color
    SDL_SetRenderDrawColor(gl_gui_components.sdl_renderer, 0, 0, 0, 255);
    SDL_RenderClear(gl_gui_components.sdl_renderer);
    if (gl_gui_components.chip8_cpu) {
        chip8_do_next(gl_gui_components.chip8_cpu);
    }


    // Draw pixels
    if (gl_gui_components.chip8_cpu) {
        SDL_Rect rect;
        rect.w = gl_gui_components.chip8_screen_pixel_ratio;
        rect.h = gl_gui_components.chip8_screen_pixel_ratio;

        SDL_SetRenderDrawColor(gl_gui_components.sdl_renderer, 255, 165, 0, 255);
        for (uint8_t y = 0; y < CHIP8_VIDEO_DIM_HEIGHT; ++y) {
            rect.y = y * gl_gui_components.chip8_screen_pixel_ratio;
            for (uint8_t x = 0; x < CHIP8_VIDEO_DIM_WIDTH; ++x) {
                rect.x = x * gl_gui_components.chip8_screen_pixel_ratio;
                if (gl_gui_components.chip8_cpu->video[y][x] == 1) {
                    SDL_RenderFillRect(gl_gui_components.sdl_renderer, &rect);
                }
            }
        }
    }

    // Render
    SDL_RenderPresent(gl_gui_components.sdl_renderer);

    // Return TRUE to continue to call this callback
    return TRUE;
}
