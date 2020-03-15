#include <stdlib.h>
#include <math.h>
#include "sound.h"

void sound_play_buzzer(void) {
    float    freq        = 400.f;
    int      seconds     = 1;
    unsigned sample_rate = 44100;
    double   my_pi       = 3.14159;
    size_t   buf_size    = (seconds * sample_rate) / 2;

    // Allocate PCM audio buffer
    short *samples = malloc(sizeof(short) * buf_size);

    int i = 0;
    for (; i < buf_size; ++i) {
        samples[i] = (short) (32760 * sin((2.f * my_pi * freq) / sample_rate * i));
    }

    // Send buffer to OpenAL
    alBufferData(gl_sound_components.internal_buffer, AL_FORMAT_MONO16, samples, buf_size, sample_rate);

    // Free allocated variable
    free(samples);

    // Set-up sound source and play buffer
    alGenSources(1, &gl_sound_components.streaming_source[0]);
    alSourcei(gl_sound_components.streaming_source[0], AL_BUFFER, gl_sound_components.internal_buffer);
    alSourcePlay(gl_sound_components.streaming_source[0]);
}
