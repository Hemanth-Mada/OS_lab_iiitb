/*    Program Number: 10
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 26 March, 2025
      Description: This program writes 10 bytes to a file, moves the file pointer
                   forward by 10 bytes using lseek, then writes another 10 bytes.
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int fd;
    char buff[] = "ABCDEFGHIJ";

    fd = open("q10.txt", O_RDWR | O_CREAT, 0666);
    write(fd, buff, 10);

    off_t pos = lseek(fd, 10, SEEK_CUR);
    printf("lseek result: %ld\n", (long)pos);

    write(fd, buff, 10);
    close(fd);
    return 0;
}
