/*    Program Number: 3
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 25 March, 2025
      Description: This program creates files and prints their file descriptors
                   using the creat() system call.
*/

#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd1, fd2, fd3;

    fd1 = creat("file1.txt", 0777);
    fd2 = creat("file2.txt", 0777);
    fd3 = creat("file3.txt", 0777);

    printf("File Descriptors: %d %d %d\n", fd1, fd2, fd3);

    return 0;
}
