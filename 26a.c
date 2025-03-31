/*    Program Number: 26a
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 31 March, 2025
      Description: execl demo
*/


#include <stdio.h>
#include <unistd.h>

int main() {
    int dummy = 0;
    printf("Trying execl version:\n");
    sleep(1);
    execl("/bin/ls", "ls", "-Rl", (char *)NULL);

    printf("This won't print\n");
    return 0;
}