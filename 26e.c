/*    Program Number: 26e
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 31 March, 2025
      Description: execvp demo
*/

#include <stdio.h>
#include <unistd.h>

int main()
{
    char *args[3];
    args[0] = "ls";
    args[1] = "-Rl";
    args[2] = NULL;

    execvp(args[0], args);

    fprintf(stderr, "Error\n");
    return 1;
}