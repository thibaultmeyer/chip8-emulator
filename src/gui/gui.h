#ifndef CHIP8EMU_GUI_H
# define CHIP8EMU_GUI_H

# include "../chip8/chip8.h"
# include <gtk/gtk.h>
# include <SDL2/SDL.h>

typedef struct s_gui_components {
    GtkWidget    *gtk_window;
    GtkWidget    *gtk_header_bar;
    SDL_Renderer *sdl_renderer;
    s_chip8_cpu  *chip8_cpu;
} s_gui_components;

s_gui_components gl_gui_components;

/**
 * Callback. Configure main windows when activated. Only call once.
 *
 * @param app GTK application instance
 * @param user_data custom user data
 */
void gui_callback_app_activate(GtkApplication *app, gpointer user_data);

/**
 * Callback. Load a ROM.
 *
 * @param app GTK application instance
 * @param user_data custom user data
 */
void gui_callback_header_bar_load_rom(GtkApplication *app, gpointer user_data);

/**
 * Callback. Render Chip8 video memory on screen.
 *
 * @return TRUE if callback need to be call again
 */
gboolean gui_callback_sdl_render_screen();

/**
 * Initialize the header bar.
 */
void gui_initialize_header_bar(void);

/**
 * Initialize the main window.
 */
void gui_initialize_main_window(GtkApplication *app);

#endif //CHIP8EMU_GUI_H
