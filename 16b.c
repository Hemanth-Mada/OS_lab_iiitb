/*    Program Number: 16b
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 27 March, 2025
      Description: This program applies a read lock on a file.
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    // Open the file "q16.txt" for reading and writing
    int fd = open("q16.txt", O_RDWR);
    if (fd == -1)
    {
        printf("Error opening file\n");
        return 1;
    }

    struct flock flk;
    flk.l_type = F_RDLCK;    // Set the lock type to read lock
    flk.l_whence = SEEK_SET; // Set the starting point for the lock
    flk.l_start = 0;         // Start locking from the beginning of the file
    flk.l_len = 0;           // Lock the entire file

    // Apply the read lock on the file
    if (fcntl(fd, F_SETLKW, &flk) == -1)
    {
        printf("Error setting read lock\n");
        close(fd);
        return 1;
    }

    printf("Read lock active. Press Enter to release\n");
    getchar(); // Wait for user input to release the lock

    flk.l_type = F_UNLCK;      // Set the lock type to unlock
    fcntl(fd, F_SETLKW, &flk); // Release the lock
    printf("Lock released\n");
    close(fd); // Close the file descriptor
}
