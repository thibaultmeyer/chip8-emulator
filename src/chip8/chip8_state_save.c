#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include "chip8.h"

e_statesave_status chip8_state_save(s_chip8_cpu *cpu, const char *filename) {
    int32_t file_descriptor = 0;

    // Open file
#ifdef _WIN32
    file_descriptor = open(filename, O_WRONLY | O_CREAT | O_BINARY, S_IWUSR | S_IRUSR);
#else
    file_descriptor = open(filename, O_WRONLY | O_CREAT, S_IWUSR | S_IRUSR);
#endif
    if (file_descriptor > 0) {

        // Write file content
        uint32_t size_to_write = sizeof(s_chip8_cpu) - (2 * sizeof(void (*)(void)));
        ssize_t  ret           = write(file_descriptor, cpu, size_to_write);
        if (ret != size_to_write) {

            // Write size is not same as the file size: Error!
            close(file_descriptor);

            // Delete partial file
            if (remove(filename) != 0) {
                return (STATE_SAVE_STATUS_ERROR_CANT_DELETE_PARTIAL_FILE);
            }

            // Return error
            return (STATE_SAVE_STATUS_ERROR_WRITE_ERROR);
        }

        // Success
        close(file_descriptor);
        return (STATE_SAVE_STATUS_SUCCESS);
    }

    // Can't open file
    return (STATE_SAVE_STATUS_ERROR_CANT_OPEN_FILE);
}
