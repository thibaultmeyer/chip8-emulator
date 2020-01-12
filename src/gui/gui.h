#ifndef CHIP8EMU_GUI_H
# define CHIP8EMU_GUI_H

# include "../chip8/chip8.h"
# include <gtk/gtk.h>

typedef struct s_gui_components {
    GtkWidget   *gtk_window;
    GtkWidget   *gtk_header_bar;
    GtkWidget   *gtk_drawing_area;
    guint       gtk_timer_cpu;
    guint       gtk_timer_counter;
    s_chip8_cpu *chip8_cpu;
    uint16_t    chip8_frequency;
    uint32_t    chip8_screen_width;
    uint32_t    chip8_screen_height;
    uint32_t    chip8_screen_pixel_ratio;
} s_gui_components;

s_gui_components gl_gui_components;

/**
 * Callback. Configure main window when activated. Only call once.
 *
 * @param app GTK application instance
 * @param user_data custom user data
 */
void gui_callback_app_activate(GtkApplication *app, gpointer user_data);

/**
 * Callback. Update counter.
 *
 * @param app GTK application instance
 * @param user_data custom user data
 */
gboolean gui_callback_chip8_tick_counter();

/**
 * Callback. Run the next chip8 CPU instruction.
 *
 * @return TRUE if callback need to be call again
 */
gboolean gui_callback_chip8_tick_cpu();

/**
 * Callback. Drawing area "draw".
 *
 * @param app Widget instance
 * @param allocation Allocation information
 * @param user_data custom user data
 */
gboolean gui_callback_drawing_area_draw(GtkWidget *widget, cairo_t *cr, void *data);

/**
 * Callback. Drawing area dimension changed.
 *
 * @param app Widget instance
 * @param allocation Allocation information
 * @param user_data custom user data
 */
void gui_callback_drawing_area_new_size(GtkWidget *widget, GtkAllocation *allocation, void *data);

/**
 * Callback. Load a ROM.
 *
 * @param app GTK application instance
 * @param user_data custom user data
 */
void gui_callback_header_bar_load_rom(GtkApplication *app, gpointer user_data);

/**
 * Callback. Reset chip8 CPU.
 *
 * @param app GTK application instance
 * @param user_data custom user data
 */
void gui_callback_header_bar_reset_cpu(GtkApplication *app, gpointer user_data);

/**
 * Callback. Show "about" dialog.
 *
 * @param app GTK application instance
 * @param user_data custom user data
 */
void gui_callback_menu_more_about(GtkApplication *app, gpointer user_data);

/**
 * Callback. Main window is destroyed.
 *
 * @param app GTK application instance
 * @param user_data custom user data
 */
void gui_callback_window_destroy(GtkWidget *widget, gpointer data);

/**
 * Callback. A key has been pressed or released.
 *
 * @param app GTK application instance
 * @param user_data custom user data
 */
gboolean gui_callback_window_key(GtkWidget *widget, GdkEventKey *event, gpointer data);

/**
 * Load image from memory and scale it.
 *
 * @param data Image data
 * @param length Image data length
 * @param width New image width
 * @param height New image height
 */
GdkPixbuf *gui_image_load_from_memory_scale(const unsigned char *data,
                                            unsigned int length,
                                            unsigned int width,
                                            unsigned int height);

/**
 * Initialize the header bar.
 */
void gui_initialize_header_bar(void);

/**
 * Initialize the main window.
 */
void gui_initialize_main_window(GtkApplication *app);

/**
 * Check if a GTK dark theme is currently in use.
 *
 * @return true if the current GTK theme is dark
 */
gboolean gui_toolbox_is_gtk_dark_theme_enabled(void);

#endif //CHIP8EMU_GUI_H
