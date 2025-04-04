/*    Program Number: 16a
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 27 March, 2025
      Description: This program applies a write lock on a file.
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

    // Initialize a flock structure for the write lock
    struct flock flk;
    flk.l_type = F_WRLCK;    // Set the lock type to write lock
    flk.l_whence = SEEK_SET; // Set the starting point for the lock
    flk.l_start = 0;         // Set the starting offset for the lock
    flk.l_len = 0;           // Set the length of the lock (0 means until EOF)

    // Apply the write lock on the file
    if (fcntl(fd, F_SETLKW, &flk) == -1)
    {
        printf("Error setting write lock\n");
        close(fd);
        return 1;
    }

    printf("Write lock active. Press Enter to release\n");
    getchar(); // Wait for user input to release the lock

    // Release the write lock
    flk.l_type = F_UNLCK;      // Set the lock type to unlock
    fcntl(fd, F_SETLKW, &flk); // Apply the unlock
    printf("Lock released\n");
    close(fd); // Close the file descriptor
}