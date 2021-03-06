#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "chip8.h"

e_stateload_status chip8_state_load(s_chip8_cpu *cpu, const char *filename) {
    int32_t file_descriptor = 0;

    // Open file
#ifdef _WIN32
    file_descriptor = open(filename, O_RDONLY | O_BINARY);
#else
    file_descriptor = open(filename, O_RDONLY);
#endif
    if (file_descriptor > 0) {
        void *buffer = malloc(sizeof(s_chip8_cpu));
        if (buffer == NULL) {
            return (STATE_LOAD_STATUS_ERROR_CANT_OPEN_FILE);
        }

        // Read file content on temporary buffer
        uint32_t size_to_read = sizeof(s_chip8_cpu) - (2 * sizeof(void (*)(void)));
        ssize_t  ret          = read(file_descriptor, buffer, size_to_read);
        if (ret != size_to_read) {

            // Write size is not same as the file size: Error!
            close(file_descriptor);

            // Return error
            return (STATE_LOAD_STATUS_ERROR_READ_ERROR);
        }

        // Copy temporary buffer to the real destination
        memcpy(cpu, buffer, size_to_read);

        // Free allocated buffer
        free(buffer);

        // Success
        close(file_descriptor);
        return (STATE_LOAD_STATUS_SUCCESS);
    }

    // Can't open file
    return (STATE_LOAD_STATUS_ERROR_CANT_OPEN_FILE);
}
