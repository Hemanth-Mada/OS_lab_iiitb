/*    Program Number: 26b
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 31 March, 2025
      Description: execlp demo
*/

#include <stdio.h>
#include <unistd.h>

int main()
{
    char *path = "/bin/ls";
    execlp(path, "ls", "-Rl", NULL);

    perror("Failed");
    return 1;
}