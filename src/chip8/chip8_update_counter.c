#include "chip8.h"

void chip8_update_counter(s_chip8_cpu *cpu) {
    if (cpu) {
        if (cpu->counter_sync > 0) {
            --cpu->counter_sync;
        }

        if (cpu->counter_sound > 0) {
            if (cpu->counter_sound == 1 && cpu->fun_play_sound) {
                cpu->fun_play_sound();
            }

            --cpu->counter_sound;
        }
    }
}
