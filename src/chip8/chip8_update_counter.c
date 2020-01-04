#include <stdio.h>
#include "chip8.h"

void chip8_update_counter(s_chip8_cpu *cpu) {
    if (cpu) {
        if (cpu->counter_sync > 0) {
            --cpu->counter_sync;
        }

        if (cpu->counter_sound > 0) {
            if (cpu->counter_sound == 1) {
                printf("\a");
            }

            --cpu->counter_sound;
        }
    }
}
