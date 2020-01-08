#include <string.h>
#include <stdlib.h>
#include "chip8.h"

void chip8_free_cpu(s_chip8_cpu *cpu) {
    if (cpu) {
        memset(cpu, 0, sizeof(s_chip8_cpu));
        free(cpu);
    }
}
