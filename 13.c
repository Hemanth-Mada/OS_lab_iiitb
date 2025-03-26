/*    Program Number: 13 
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 26 March, 2025
      Description: This program waits for input from STDIN for 10 seconds
                   using the select system call.
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    fd_set fds;
    struct timeval t;
    char inp[100];
    
    write(1, "Enter input within 10 seconds:\n", 30);
    
    FD_ZERO(&fds);
    FD_SET(0, &fds);
    t.tv_sec = 10;
    t.tv_usec = 0;
    
    int ret = select(1, &fds, NULL, NULL, &t);
    
    if (ret == 0)
        write(1, "No input entered in 10 seconds\n", 30);
    else {
        int n = read(0, inp, sizeof(inp));
        write(1, "Input received:\n", 16);
        write(1, inp, n);
    }
    
    return 0;
}