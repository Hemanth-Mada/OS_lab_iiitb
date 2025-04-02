/*    Program Number: 7
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 2 April, 2025
      Description: This program copies the contents of file1 into file2,
                   mimicking the behavior of the cp command.
                   ./a.out "src_file" "dest_file"
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int src_fd, dest_fd;
    ssize_t bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];

    if (argc != 3)
    {
        write(2, "Usage: ./7 file1 file2\n", 23);
        exit(1);
    }

    src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1)
    {
        perror("Error opening source file");
        exit(1);
    }

    dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1)
    {
        perror("Error opening destination file");
        close(src_fd);
        exit(1);
    }

    while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0)
    {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read)
        {
            perror("Error writing to file");
            close(src_fd);
            close(dest_fd);
            exit(1);
        }
    }

    if (bytes_read == -1)
    {
        perror("Error reading from source file");
    }

    close(src_fd);
    close(dest_fd);

    write(1, "File copied successfully\n", 25);
    return 0;
}
