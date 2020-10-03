#include "../sound/sound.h"

void gui_chip8_callback_play_sound(void) {
#ifdef HAVE_AUDIO_BACKEND
    sound_play_buzzer();
#endif
}
