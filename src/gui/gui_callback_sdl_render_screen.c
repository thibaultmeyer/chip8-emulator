#include "gui.h"

gboolean gui_callback_sdl_render_screen() {
    SDL_SetRenderDrawColor(gl_gui_components.sdl_renderer, 0, 0, 0, 255);
    SDL_RenderClear(gl_gui_components.sdl_renderer);
    SDL_RenderPresent(gl_gui_components.sdl_renderer);

    return TRUE;
}
