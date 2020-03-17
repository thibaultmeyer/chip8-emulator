#ifndef CHIP8EMU_GUI_H
# define CHIP8EMU_GUI_H
# define CHIP8EMU_GUI_MAX_FILEBASE_SIZE 512
# define CHIP8EMU_GUI_MAX_FILENAME_SIZE 1024

# include "../chip8/chip8.h"
# include <gtk/gtk.h>

typedef struct s_gui_components {
    GtkWidget   *gtk_window;
    GtkWidget   *gtk_window_setting;
    GtkWidget   *gtk_header_bar;
    GtkWidget   *gtk_drawing_area;
    guint       gtk_timer_cpu;
    guint       gtk_timer_counter;
    s_chip8_cpu *chip8_cpu;
    uint32_t    chip8_screen_width;
    uint32_t    chip8_screen_height;
    uint32_t    chip8_screen_pixel_ratio;
    gchar       *current_rom_name;
} s_gui_components;

typedef struct s_gui_settings {
    uint32_t cpu_frequency;
    uint32_t display_mode;
    GdkRGBA  color_background;
    GdkRGBA  color_foreground;
    guint    keybinding[CHIP8_KEYBOARD_MAX_KEY];
} s_gui_settings;

typedef struct s_gui_settings_combobox_value {
    uint32_t   key;
    const char *value;
} s_gui_settings_combobox_value;

typedef struct s_gui_key_binding_context {
    GtkWidget *button;
    uint32_t  key_idx;
} s_gui_key_binding_context;

/**
 * Handle to the gui components.
 */
s_gui_components gl_gui_components;

/**
 * Handle to the gui settings.
 */
s_gui_settings gl_gui_settings;

/**
 * Callback - CHIP-8 CPU operation code error.
 */
void gui_chip8_callback_opcode_error(void);

/**
 * Callback - CHIP-8 CPU play sound.
 */
void gui_chip8_callback_play_sound(void);

/**
 * Stop all emulation timers. If all timers are
 * stopped, emulation will be in "pause" state.
 */
void gui_emulation_timer_stop();

/**
 * Start all emulation timers.
 */
void gui_emulation_timer_start();

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
 * Callback. Configure main window when activated. Only call once.
 *
 * @param app GTK application instance
 * @param user_data Custom user data
 */
void gui_main_callback_app_activate(GtkApplication *app, gpointer user_data);

/**
 * Callback. Update counter.
 *
 * @param app GTK application instance
 * @param user_data Custom user data
 */
gboolean gui_main_callback_chip8_tick_counter();

/**
 * Callback. Run the next chip8 CPU instruction.
 *
 * @return TRUE if callback need to be call again
 */
gboolean gui_main_callback_chip8_tick_cpu();

/**
 * Callback. Drawing area "draw".
 *
 * @param app Widget instance
 * @param allocation Allocation information
 * @param user_data Custom user data
 */
gboolean gui_main_callback_drawing_area_draw(GtkWidget *widget, cairo_t *cr, void *data);

/**
 * Callback. Drawing area dimension changed.
 *
 * @param app Widget instance
 * @param allocation Allocation information
 * @param user_data Custom user data
 */
void gui_main_callback_drawing_area_new_size(GtkWidget *widget, GtkAllocation *allocation, void *data);

/**
 * Callback. Load a ROM.
 *
 * @param app GTK application instance
 * @param user_data Custom user data
 */
void gui_main_callback_header_bar_load_rom(GtkApplication *app, gpointer user_data);

/**
 * Callback. Reset chip8 CPU.
 *
 * @param app GTK application instance
 * @param user_data Custom user data
 */
void gui_main_callback_header_bar_reset_cpu(GtkApplication *app, gpointer user_data);

/**
 * Callback. Show "about" dialog.
 *
 * @param app GTK application instance
 * @param user_data Custom user data
 */
void gui_main_callback_menu_more_about(GtkApplication *app, gpointer user_data);

/**
 * Callback. Show "settings" dialog.
 *
 * @param app GTK application instance
 * @param user_data Custom user data
 */
void gui_main_callback_menu_more_settings(GtkApplication *app, gpointer user_data);

/**
 * Callback. Load CPU state.
 *
 * @param app GTK application instance
 * @param user_data Custom user data
 */
void gui_main_callback_menu_state_load(GtkApplication *app, gpointer user_data);

/**
 * Callback. Save CPU state.
 *
 * @param app GTK application instance
 * @param user_data Custom user data
 */
void gui_main_callback_menu_state_save(GtkApplication *app, gpointer user_data);

/**
 * Callback. Main window is destroyed.
 *
 * @param app GTK application instance
 * @param user_data Custom user data
 */
void gui_main_callback_window_destroy(GtkWidget *widget, gpointer data);

/**
 * Callback. A key has been pressed or released.
 *
 * @param app GTK application instance
 * @param user_data Custom user data
 */
gboolean gui_main_callback_window_key(GtkWidget *widget, GdkEventKey *event, gpointer data);

/**
 * Initialize the header bar.
 */
void gui_main_initialize_main_header_bar(void);

/**
 * Initialize the main window.
 */
void gui_main_initialize_main_window(GtkApplication *app);

/**
 * Settings - Callback - Set the background color.
 *
 * @param widget Handle to the GTK color button
 * @param user_data Custom user data
 */
void gui_settings_callback_colorbutton_background(GtkColorButton *widget, gpointer user_data);

/**
 * Settings - Callback - Set the foreground color.
 *
 * @param widget Handle to the GTK color button
 * @param user_data Custom user data
 */
void gui_settings_callback_colorbutton_foreground(GtkColorButton *widget, gpointer user_data);

/**
 * Settings - Callback - Set the CPU frequency.
 *
 * @param widget Handle to the combobox widget
 * @param user_data Custom user data
 */
void gui_settings_callback_combobox_cpu_frequency(GtkComboBox *widget, gpointer user_data);

/**
 * Settings - Callback - Set binding for a specific key.
 *
 * @param button Handle to the GTK button
 * @param key_binding_ctx Key binding context
 */
void gui_settings_callback_btn_input_key(GtkButton *button, s_gui_key_binding_context *key_binding_ctx);

/**
 * Callback. Settings window is destroyed.
 *
 * @param app GTK application instance
 * @param user_data Custom user data
 */
void gui_settings_callback_window_destroy(GtkWidget *widget, gpointer data);

/**
 * Initialize the settings window.
 */
void gui_settings_init(void);

/**
 * Initialize the settings window - Background Color.
 *
 * @param fixed_container Container to place components
 */
void gui_settings_init_color_background(GtkFixed *fixed_container);

/**
 * Initialize the settings window - Foreground Color.
 *
 * @param fixed_container Container to place components
 */
void gui_settings_init_color_foreground(GtkFixed *fixed_container);

/**
 * Initialize the settings window - CPU Frequency.
 *
 * @param fixed_container Container to place components
 */
void gui_settings_init_cpu_frequency(GtkFixed *fixed_container);

/**
 * Initialize the settings window - Display Mode.
 *
 * @param fixed_container Container to place components
 */
void gui_settings_init_display_mode(GtkFixed *fixed_container);

/**
 * Initialize the settings window - Key Binding.
 *
 * @param fixed_container Container to place components
 */
void gui_settings_init_key_binding(GtkFixed *fixed_container);

/**
 * Creates the storage directory.
 */
void gui_toolbox_create_storage_directory(void);

/**
 * Retrieves the storage path of the given filename.
 *
 * @param filename Needed filename
 * @return Storage path
 */
gchar *gui_toolbox_get_storage_file_path(const char *filename);

/**
 * Check if a GTK dark theme is currently in use.
 *
 * @return true if the current GTK theme is dark
 */
gboolean gui_toolbox_is_gtk_dark_theme_enabled(void);

/**
 * Load settings from file or use default values.
 */
void gui_toolbox_load_settings_from_file_or_default(void);

/**
 * Save settings to file.
 */
void gui_toolbox_save_settings_to_file(void);

#endif //CHIP8EMU_GUI_H
