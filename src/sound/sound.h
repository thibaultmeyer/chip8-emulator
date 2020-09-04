#ifndef CHIP8EMU_SOUND_H
# define CHIP8EMU_SOUND_H
# ifdef __APPLE__

#  include <OpenAL/al.h>
#  include <OpenAL/alc.h>

# else

#  include <AL/al.h>
#  include <AL/alc.h>

# endif

# define CHIP8EMU_SOUND_FREQUENCY            400.f
# define CHIP8EMU_SOUND_SAMPLE_RATE          44100
# define CHIP8EMU_SOUND_DURATION_SECOND      1
# define CHIP8EMU_SOUND_MAX_AMPLITUDE_16BITS 32760
# define CHIP8EMU_SOUND_PI                   3.141592

typedef struct s_sound_components {
    ALCdevice  *openal_output_device;
    ALCcontext *openal_output_context;
    ALuint     internal_buffer;
    ALuint     streaming_source[1];
} s_sound_components;

/**
 * Handle to the gui components.
 */
extern s_sound_components gl_sound_components;

void sound_initialize(void);

void sound_play_buzzer(void);

void sound_destroy(void);

#endif //CHIP8EMU_SOUND_H
