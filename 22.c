/*    Program Number: 22
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 28 March, 2025
      Description: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t id = fork();

    if (id == -1)
    {
        perror("fork failed");
        return 1;
    }

    if (id == 0)
    {
        printf("Child process created, ID: %d\n", getpid());
        exit(0); // Child exits, becoming a zombie
    }
    else
    {
        printf("Parent process, ID: %d, child ID: %d\n", getpid(), id);
        sleep(30); // Keep parent alive to observe the zombie
    }

    return 0;
}
