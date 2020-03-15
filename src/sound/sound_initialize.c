#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "sound.h"

void sound_initialize(void) {
    const char *defname       = alcGetString(NULL, ALC_DEFAULT_DEVICE_SPECIFIER);
    float      freq           = 400.f;
    int        seconds        = 1;
    unsigned   sample_rate    = 44100;
    double     my_pi          = 3.14159;
    size_t     buf_size       = (seconds * sample_rate);
    size_t     duration_bound = (seconds * sample_rate) / 60;

    // Open device and initialize context
    memset(&gl_sound_components, 0, sizeof(s_sound_components));
    gl_sound_components.openal_output_device  = alcOpenDevice(defname);
    gl_sound_components.openal_output_context = alcCreateContext(gl_sound_components.openal_output_device, NULL);

    alcMakeContextCurrent(gl_sound_components.openal_output_context);
    alGenBuffers(1, &gl_sound_components.internal_buffer);

    // Allocate PCM audio buffer
    short *buzzer_buffer = malloc(sizeof(short) * buf_size);
    if (buzzer_buffer != NULL) {

        for (int idx = 0; idx < buf_size; ++idx) {
            if (idx < duration_bound) {
                buzzer_buffer[idx] = (short) (32760 * sin((2.f * my_pi * freq) / sample_rate * idx));
            } else {
                buzzer_buffer[idx] = 0;
            }
        }

        // Send buffer to OpenAL
        alBufferData(gl_sound_components.internal_buffer, AL_FORMAT_MONO16, buzzer_buffer, buf_size, sample_rate);

        // Free allocated variable
        free(buzzer_buffer);
    }
}
