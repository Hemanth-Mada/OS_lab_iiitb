/*    Program Number: 26d
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 31 March, 2025
      Description: execv demo
*/

#include <stdio.h>
#include <unistd.h>

int main()
{
    char *cmd[3];
    cmd[0] = "ls";
    cmd[1] = "-Rl";
    cmd[2] = NULL;

    execv("/bin/ls", cmd);

    return 1;
}