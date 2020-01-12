#include "gui.h"

GdkPixbuf *gui_image_load_from_memory_scale(const unsigned char *data,
                                            const unsigned int length,
                                            const unsigned int width,
                                            const unsigned int height) {
    GdkPixbufLoader *loader = gdk_pixbuf_loader_new();
    gdk_pixbuf_loader_write(loader, data, length, NULL);

    GdkPixbuf *pixbuf_initial = gdk_pixbuf_loader_get_pixbuf(loader);
    GdkPixbuf *pixbuf_scaled  = gdk_pixbuf_scale_simple(pixbuf_initial, width, height, GDK_INTERP_HYPER);

    g_object_unref(pixbuf_initial);
    gdk_pixbuf_loader_close(loader, NULL);

    return pixbuf_scaled;
}
