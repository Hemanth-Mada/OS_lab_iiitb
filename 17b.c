/*    Program Number: 17b
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 28 March, 2025
      Description: This program to open the file, implement a write lock,
                   read the ticket number, increment the number,
                   print the new ticket number, and then close the file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct
{
    int count;
} Ticket;

int main()
{
    // Open the file "q17.txt" for reading and writing
    int file = open("q17.txt", O_RDWR);
    if (file < 0)
    {
        perror("Failed to open file");
        return 1;
    }

    // Initialize a file lock structure for write locking
    struct flock lock;
    lock.l_type = F_WRLCK;    // Set the lock type to write lock
    lock.l_whence = SEEK_SET; // Set the starting point for the lock
    lock.l_start = 0;         // Start locking from the beginning of the file
    lock.l_len = 0;           // Lock the entire file

    // Apply the write lock on the file
    if (fcntl(file, F_SETLKW, &lock) < 0)
    {
        perror("Locking failed");
        close(file);
        return 1;
    }

    // Read the current ticket information from the file
    Ticket tkt;
    if (read(file, &tkt, sizeof(Ticket)) < 0)
    {
        perror("Read error");
        close(file);
        return 1;
    }

    // Increment the ticket count
    tkt.count++;
    lseek(file, 0, SEEK_SET); // Move the file pointer back to the start

    // Write the updated ticket information back to the file
    if (write(file, &tkt, sizeof(Ticket)) < 0)
    {
        perror("Write error");
        close(file);
        return 1;
    }

    printf("New Ticket Count: %d\n", tkt.count);

    // Unlock the file
    lock.l_type = F_UNLCK;       // Set the lock type to unlock
    fcntl(file, F_SETLK, &lock); // Apply the unlock

    // Close the file
    close(file);
    return 0;
}
