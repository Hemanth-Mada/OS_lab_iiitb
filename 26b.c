/*    Program Number: 26b
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 31 March, 2025
      Description: execlp demo
*/

#include <stdio.h>

int main()
{
    printf("Testing PATH search version\n");

    char *path = "/bin/ls";
    execlp(path, "ls", "-Rl", NULL);

    perror("Failed");
    return 1;
}