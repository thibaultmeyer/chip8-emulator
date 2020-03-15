#include "sound.h"

void sound_play_buzzer(void) {
    // Set sound source and play buffer
    alGenSources(1, &gl_sound_components.streaming_source[0]);
    alSourcei(gl_sound_components.streaming_source[0], AL_BUFFER, gl_sound_components.internal_buffer);
    alSourcePlay(gl_sound_components.streaming_source[0]);
}
