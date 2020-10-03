#ifndef CHIP8EMU_GUI_H
# define CHIP8EMU_GUI_H

# include "../chip8/chip8.h"
# include <gtk/gtk.h>

# define CHIP8EMU_GUI_MAX_FILEBASE_SIZE            512
# define CHIP8EMU_GUI_MAX_FILENAME_SIZE            1024
# define CHIP8EMU_GUI_APP_ICON_HEIGHT              256
# define CHIP8EMU_GUI_APP_ICON_WIDTH               256
# define CHIP8EMU_GUI_HEADERBAR_BTN_IMG_HEIGHT     20
# define CHIP8EMU_GUI_HEADERBAR_BTN_IMG_WIDTH      20
# define CHIP8EMU_GUI_SCREEN_DEFAULT_PIXEL_RATIO   10
# define CHIP8EMU_GUI_SCREEN_DEFAULT_WIDTH         CHIP8_VIDEO_DIM_WIDTH * CHIP8EMU_GUI_SCREEN_DEFAULT_PIXEL_RATIO
# define CHIP8EMU_GUI_SCREEN_DEFAULT_HEIGHT        CHIP8_VIDEO_DIM_HEIGHT * CHIP8EMU_GUI_SCREEN_DEFAULT_PIXEL_RATIO
# define CHIP8EMU_GUI_SCREEN_DEFAULT_OFFSET_WIDTH  0
# define CHIP8EMU_GUI_SCREEN_DEFAULT_OFFSET_HEIGHT 0

typedef struct s_gui_components {
    GtkWidget   *gtk_window;
    GtkWidget   *gtk_window_setting;
    GtkWidget   *gtk_header_bar;
    GtkWidget   *gtk_drawing_area;
    guint       gtk_timer_cpu;
    guint       gtk_timer_counter;
    s_chip8_cpu *chip8_cpu;
    uint32_t    chip8_screen_offset_width;
    uint32_t    chip8_screen_offset_height;
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
extern s_gui_components gl_gui_components;

/**
 * Handle to the gui settings.
 */
extern s_gui_settings gl_gui_settings;

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
void gui_emulation_timer_stop(void);

/**
 * Start all emulation timers.
 */
void gui_emulation_timer_start(void);

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
                                            int width,
                                            int height);

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
 * @param user_data Data passed to the function
 * @return TRUE if callback need to be call again
 */
gboolean gui_main_callback_chip8_tick_counter(gpointer user_data);

/**
 * Callback. Run the next chip8 CPU instruction.
 *
 * @param user_data Data passed to the function
 * @return TRUE if callback need to be call again
 */
gboolean gui_main_callback_chip8_tick_cpu(gpointer user_data);

/**
 * Callback. Drawing area "draw".
 *
 * @param widget The object which received the signal
 * @param cr The cairo context to draw to
 * @param user_data User data set when the signal handler was connected
 */
gboolean gui_main_callback_drawing_area_draw(GtkWidget *widget, cairo_t *cr, void *user_data);

/**
 * Callback. Drawing area dimension changed.
 *
 * @param widget The object which received the signal
 * @param allocation The region which has been allocated to the widget
 * @param user_data User data set when the signal handler was connected
 */
void gui_main_callback_drawing_area_new_size(GtkWidget *widget, GtkAllocation *allocation, void *user_data);

/**
 * Callback. Load a ROM.
 *
 * @param button The object that received the signal
 * @param user_data User data set when the signal handler was connected
 */
void gui_main_callback_header_bar_load_rom(GtkButton *button, gpointer user_data);

/**
 * Callback. Reset chip8 CPU.
 *
 * @param button The object that received the signal
 * @param user_data User data set when the signal handler was connected
 */
void gui_main_callback_header_bar_reset_cpu(GtkButton *button, gpointer user_data);

/**
 * Callback. Show "about" dialog.
 *
 * @param menuitem The object which received the signal
 * @param user_data User data set when the signal handler was connected
 */
void gui_main_callback_menu_more_about(GtkMenuItem *menuitem, gpointer user_data);

/**
 * Callback. Show "settings" dialog.
 *
 * @param menuitem The object which received the signal
 * @param user_data User data set when the signal handler was connected
 */
void gui_main_callback_menu_more_settings(GtkMenuItem *menuitem, gpointer user_data);

/**
 * Callback. Load CPU state.
 *
 * @param menuitem The object which received the signal
 * @param user_data User data set when the signal handler was connected
 */
void gui_main_callback_menu_state_load(GtkMenuItem *menuitem, gpointer user_data);

/**
 * Callback. Save CPU state.
 *
 * @param menuitem The object which received the signal
 * @param user_data User data set when the signal handler was connected
 */
void gui_main_callback_menu_state_save(GtkMenuItem *menuitem, gpointer user_data);

/**
 * Callback. Main window is destroyed.
 *
 * @param widget The object which received the signal
 * @param user_data User data set when the signal handler was connected
 */
void gui_main_callback_window_destroy(GtkWidget *widget, gpointer user_data);

/**
 * Callback. A key has been pressed or released.
 *
 * @param widget The object which received the signal
 * @param event The GdkEvent which triggered this signal
 * @param user_data User data set when the signal handler was connected
 */
gboolean gui_main_callback_window_key(GtkWidget *widget, GdkEventKey *event, gpointer user_data);

/**
 * Initialize the header bar.
 */
void gui_main_initialize_main_header_bar(void);

/**
 * Initialize the main window.
 *
 * @param app The Gtk application instance
 */
void gui_main_initialize_main_window(GtkApplication *app);

/**
 * Settings - Callback - Set the background color.
 *
 * @param color_button The color button that received the signal
 * @param user_data User data set when the signal handler was connected
 */
void gui_settings_callback_colorbutton_background(GtkColorButton *color_button, gpointer user_data);

/**
 * Settings - Callback - Set the foreground color.
 *
 * @param color_button The color button that received the signal
 * @param user_data User data set when the signal handler was connected
 */
void gui_settings_callback_colorbutton_foreground(GtkColorButton *color_button, gpointer user_data);

/**
 * Settings - Callback - Set the CPU frequency.
 *
 * @param widget The object which received the signal
 * @param user_data User data set when the signal handler was connected
 */
void gui_settings_callback_combobox_cpu_frequency(GtkComboBox *widget, gpointer user_data);

/**
 * Settings - Callback - Set binding for a specific key.
 *
 * @param button The object that received the signal
 * @param key_binding_ctx Key binding context
 */
void gui_settings_callback_btn_input_key(GtkButton *button, s_gui_key_binding_context *key_binding_ctx);

/**
 * Callback. Settings window is destroyed.
 *
 * @param widget The object which received the signal
 * @param user_data User data set when the signal handler was connected
 */
void gui_settings_callback_window_destroy(GtkWidget *widget, gpointer user_data);

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
 * @param widget Widget instance used to determine if dark mode is enable
 * @return true if the current GTK theme is dark
 */
gboolean gui_toolbox_is_gtk_dark_theme_enabled(GtkWidget *widget);

/**
 * Load settings from file or use default values.
 */
void gui_toolbox_load_settings_from_file_or_default(void);

/**
 * Save settings to file.
 */
void gui_toolbox_save_settings_to_file(void);

#endif //CHIP8EMU_GUI_H
