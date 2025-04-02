/*    Program Number: 17b
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 28 March, 2025
      Description: This program applies a read lock on a file.
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
    int file = open("q17.txt", O_RDWR);
    if (file < 0)
    {
        perror("Failed to open file");
        return 1;
    }

    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    if (fcntl(file, F_SETLKW, &lock) < 0)
    {
        perror("Locking failed");
        close(file);
        return 1;
    }

    Ticket tkt;
    if (read(file, &tkt, sizeof(Ticket)) < 0)
    {
        perror("Read error");
        close(file);
        return 1;
    }

    tkt.count++;
    lseek(file, 0, SEEK_SET);

    if (write(file, &tkt, sizeof(Ticket)) < 0)
    {
        perror("Write error");
        close(file);
        return 1;
    }

    printf("New Ticket Count: %d\n", tkt.count);

    lock.l_type = F_UNLCK;
    fcntl(file, F_SETLK, &lock);

    close(file);
    return 0;
}
