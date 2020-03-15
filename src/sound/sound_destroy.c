#include <string.h>
#include "sound.h"

void sound_destroy(void) {
    ALenum errorCode = 0;

    // Stop the sources
    alSourceStopv(1, &gl_sound_components.streaming_source[0]);
    for (int i = 0; i < 1; ++i) {
        alSourcei(gl_sound_components.streaming_source[i], AL_BUFFER, 0);
    }

    // Clean-up
    alDeleteSources(1, &gl_sound_components.streaming_source[0]);
    alDeleteBuffers(16, &gl_sound_components.streaming_source[0]);
    errorCode = alGetError();
    alcMakeContextCurrent(NULL);
    errorCode = alGetError();
    alcDestroyContext(gl_sound_components.openal_output_context);
    alcCloseDevice(gl_sound_components.openal_output_device);
}
