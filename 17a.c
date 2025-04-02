/*    Program Number: 17a
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 28 March, 2025
      Description: This program applies a read lock on a file.
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct
{
    int count;
} Ticket;

int main()
{
    int file = open("q17.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (file < 0)
    {
        perror("Could not open file");
        return 1;
    }

    Ticket tkt = {5};
    if (write(file, &tkt, sizeof(Ticket)) < 0)
    {
        perror("Write failed");
    }

    close(file);
    return 0;
}
