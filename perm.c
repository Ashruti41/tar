#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    int fd;

    // Open the file with read-write permissions for user and group, read-only for others
    fd = open(filename, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Close the file descriptor
    close(fd);

    printf("Permissions set successfully for %s.\n", filename);

    return 0;
}

