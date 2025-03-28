/*    Program Number: 12
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 26 March, 2025
      Description: This program determines the opening mode of a file
                   using the fcntl system call.
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int fd = open("test.txt", O_RDONLY);
    int mode = fcntl(fd, F_GETFL) & O_ACCMODE;

    if (mode == O_RDONLY)
        write(1, "Read only\n", 10);
    else if (mode == O_WRONLY)
        write(1, "Write only\n", 11);
    else if (mode == O_RDWR)
        write(1, "Read and write\n", 15);
    else
        write(1, "Unknown mode\n", 13);

    close(fd);
    return 0;
}