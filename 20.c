/*    Program Number: 20
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 28 March, 2025
      Description: 
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    pid = fork();

    if (pid < 0)
    {
        printf("Error: Fork failed\n");
        return 1;
    }
    else if (pid == 0)
    {
        printf("Child process -> PID: %d\n", getpid());
        printf("Child process -> Parent PID: %d\n", getppid());
    }
    else
    {
        wait(NULL);
        printf("Parent process -> PID: %d\n", getpid());
    }
    return 0;
}
