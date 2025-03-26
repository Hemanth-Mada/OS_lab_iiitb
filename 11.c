/*    Program Number: 11 
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 26 March, 2025
      Description: This program opens a file, duplicates the file descriptor using
                   dup, dup2, and fcntl, and appends content using all descriptors.
*/

#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("test.txt", O_WRONLY | O_CREAT | O_APPEND, 0666);
    int fd_dup = dup(fd);
    int fd_dup2 = dup2(fd, 10);
    int fd_fcntl = fcntl(fd, F_DUPFD, 0);
    
    write(fd, "Using original fd\n", 18);
    write(fd_dup, "Using dup\n", 10);
    write(fd_dup2, "Using dup2\n", 11);
    write(fd_fcntl, "Using fcntl\n", 12);
    
    close(fd);
    close(fd_dup);
    close(fd_dup2);
    close(fd_fcntl);
    
    return 0;
}
