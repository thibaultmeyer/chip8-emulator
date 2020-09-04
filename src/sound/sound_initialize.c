#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "sound.h"

s_sound_components gl_sound_components = {0};

void sound_initialize(void) {
    const char *defname       = alcGetString(NULL, ALC_DEFAULT_DEVICE_SPECIFIER);
    size_t     buf_size       = (CHIP8EMU_SOUND_DURATION_SECOND * CHIP8EMU_SOUND_SAMPLE_RATE);
    size_t     duration_bound = (CHIP8EMU_SOUND_DURATION_SECOND * CHIP8EMU_SOUND_SAMPLE_RATE) / 60;

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
                buzzer_buffer[idx] = (short) (CHIP8EMU_SOUND_MAX_AMPLITUDE_16BITS
                                              * sin((2.f * CHIP8EMU_SOUND_PI * CHIP8EMU_SOUND_FREQUENCY)
                                                    / CHIP8EMU_SOUND_SAMPLE_RATE * idx));
            } else {
                buzzer_buffer[idx] = 0;
            }
        }

        // Send buffer to OpenAL
        alBufferData(gl_sound_components.internal_buffer,
                     AL_FORMAT_MONO16,
                     buzzer_buffer,
                     buf_size,
                     CHIP8EMU_SOUND_SAMPLE_RATE);

        // Free allocated variable
        free(buzzer_buffer);
    }
}
