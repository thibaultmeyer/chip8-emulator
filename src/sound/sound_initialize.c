#include <string.h>
#include "sound.h"

void sound_initialize(void) {
    memset(&gl_sound_components, 0, sizeof(s_sound_components));
    const char *defname = alcGetString(NULL, ALC_DEFAULT_DEVICE_SPECIFIER);

    gl_sound_components.openal_output_device  = alcOpenDevice(defname);
    gl_sound_components.openal_output_context = alcCreateContext(gl_sound_components.openal_output_device, NULL);

    alcMakeContextCurrent(gl_sound_components.openal_output_context);
    alGenBuffers(1, &gl_sound_components.internal_buffer);
}
