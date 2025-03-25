/*    Program Number: 5 
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 25 March, 2025
      Description: This program continuously creates five new files in an
                   infinite loop. It can be run in the background to inspect
                   file descriptor table at /proc/pid/fd.
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    while (1) {
        int fd1 = creat("file1.txt", 0777);
        int fd2 = creat("file2.txt", 0777);
        int fd3 = creat("file3.txt", 0777);
        int fd4 = creat("file4.txt", 0777);
        int fd5 = creat("file5.txt", 0777);
        
        printf("File Descriptors: %d %d %d %d %d\n", fd1, fd2, fd3, fd4, fd5);
        sleep(1); // avoid system overload
    }
    return 0;
}