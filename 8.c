/*    Program Number: 8
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 26 March, 2025
      Description: This program opens a file in read-only mode, reads it
                   line by line, and prints each line as it is read.
*/

#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("q8.txt", O_RDONLY);
    char c;

    while (read(fd, &c, 1) > 0)
    {
        write(1, &c, 1); // Print to STDOUT
    }

    close(fd);
    return 0;
}
