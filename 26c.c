/*    Program Number: 26c
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 31 March, 2025
      Description: execle demo
*/
#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main() {
    printf("Environment version\n");

    char **env_copy = environ;
    execle("/bin/ls", "ls", "-Rl", NULL, env_copy);

    puts("Execution failed!");
    return 0;
}