/*    Program Number: 1
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 24 March, 2025
      Description: This program demonstrates the creation of different file types
                   using system calls: soft link, hard link, and FIFO.
                   ./a.out 1.sh
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Create a new file with read, write, and execute permissions
    int fd = open(argv[1], O_CREAT | O_WRONLY, 0777);
    if (fd == -1)
    {
        perror("File creation failed");
        return 1;
    }
    close(fd);

    // Create a symbolic link
    if (symlink(argv[1], "symbolic_link") == -1)
    {
        perror("Failed to create symbolic link");
    }

    // Create a hard link
    if (link(argv[1], "hard_link") == -1)
    {
        perror("Failed to create hard link");
    }

    // Create a named pipe (FIFO)
    if (mkfifo("named_pipe", 0777) == -1)
    {
        perror("Failed to create FIFO");
    }

    return 0;
}
