/*    Program Number: 17a
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 28 March, 2025
      Description: This program to open a file, store a ticket number, and exit.
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
    // Open a file named "q17.txt" for reading and writing, creating it if it doesn't exist
    int file = open("q17.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (file < 0)
    {
        perror("Could not open file");
        return 1;
    }

    // Initialize a Ticket structure with a count of 5
    Ticket tkt = {5};

    // Write the Ticket structure to the file
    if (write(file, &tkt, sizeof(Ticket)) < 0)
    {
        perror("Write failed");
    }

    // Close the file
    close(file);
    return 0;
}
