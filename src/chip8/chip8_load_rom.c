#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include "chip8.h"

e_loadrom_status chip8_load_rom(s_chip8_cpu *cpu, const char *filename) {
    int32_t     file_descriptor = 0;
    struct stat file_info       = {0};

    // Check file
    stat(filename, &file_info);
    if (S_ISDIR(file_info.st_mode) || file_info.st_size == 0) {
        return (LOAD_ROM_STATUS_NOT_A_VALID_FILE);
    }

    // Open file
    file_descriptor = open(filename, O_RDONLY);
    if (file_descriptor > 0) {

        // Read file content
        if (read(file_descriptor, &cpu->memory[CHIP8_MEMORY_ROM_START], file_info.st_size) != file_info.st_size) {

            // Read size is not same as the file size: Error!
            close(file_descriptor);
            return (LOAD_ROM_STATUS_READ_ERROR);
        }

        // Success
        close(file_descriptor);
        return (LOAD_ROM_STATUS_SUCCESS);
    }

    // Can't open file
    return (LOAD_ROM_STATUS_CANT_OPEN_FILE);
}
