/*    Program Number: 14
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 26 March, 2025
      Description: This program identifies the type of file given as input
                   from the command line.
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    struct stat buf;

    for (int i = 1; i < argc; i++)
    {
        stat(argv[i], &buf);
        write(1, argv[i], sizeof(argv[i]));
        write(1, " is ", 4);

        if (S_ISDIR(buf.st_mode))
            write(1, "a directory\n", 12);
        else if (S_ISLNK(buf.st_mode))
            write(1, "a symlink\n", 10);
        else if (S_ISREG(buf.st_mode))
            write(1, "a regular file\n", 16);
        else if (S_ISFIFO(buf.st_mode))
            write(1, "a FIFO\n", 7);
        else if (S_ISBLK(buf.st_mode))
            write(1, "a block device\n", 16);
        else if (S_ISCHR(buf.st_mode))
            write(1, "a character device\n", 20);
        else
            write(1, "an unknown file type\n", 22);
    }

    return 0;
}
