/*    Program Number: 16b 
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 27 March, 2025
      Description: This program applies a read lock on a file.
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int fd = open("test.txt", O_RDWR);
    if (fd == -1) {
        printf("Error opening file\n");
        return 1;
    }

    struct flock flk;
    flk.l_type = F_RDLCK;
    flk.l_whence = SEEK_SET;
    flk.l_start = 0;
    flk.l_len = 0;

    if (fcntl(fd, F_SETLKW, &flk) == -1) {
        printf("Error setting read lock\n");
        close(fd);
        return 1;
    }

    printf("Read lock active. Press Enter to release\n");
    getchar();

    flk.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &flk);
    printf("Lock released\n");
    close(fd);
}
