/*    Program Number: 23
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 28 March, 2025
      Description: A program to create an Orphan process.
*/

#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();

    if (pid == -1)
    {
        perror("Fork error");
        return 1;
    }

    if (pid == 0)
    { // Child process
        printf("Child process running. PID: %d, Parent PID: %d\n", getpid(), getppid());
        sleep(20);
        printf("Child process after parent exits. PID: %d, New Parent PID: %d\n", getpid(), getppid());
    }
    else
    { // Parent process
        printf("Parent process terminating. PID: %d\n", getpid());
    }

    return 0;
}
