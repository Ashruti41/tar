#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    char *filename = "/home/ashruti/1/tar/tar";
    int fd;

    // Set umask to 0 to ensure full permissions are applied
    mode_t old_mask = umask(0);

    // Open the file with read-write-execute permissions for user, group, and others
    fd = open(filename, O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Reset umask to previous value
    umask(old_mask);

    // Close the file descriptor
    close(fd);

    printf("Permissions set successfully for %s.\n", filename);

    return 0;
}

