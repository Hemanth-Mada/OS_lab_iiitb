/*    Program Number: 4 
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 25 March, 2025
      Description: This program opens an existing file in read-write mode
                   and tries to create a new file with O_EXCL flag.
*/

#include <stdio.h>
#include <fcntl.h>

int main() {
    int fd1, fd2;
    
    fd1 = open("test.txt", O_RDWR);
    fd2 = open("newfile.txt", O_CREAT | O_EXCL, 0777);
    
    printf("File Descriptors: %d %d\n", fd1, fd2);
    
    return 0;
}
