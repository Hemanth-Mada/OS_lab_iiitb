#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int child1, child2, child3;

    printf("Main process ID: %d\n", getpid());

    child1 = fork();
    if (child1 == 0)
    {
        printf("Child 1 started: PID=%d, Parent PID=%d\n", getpid(), getppid());
    }
    else
    {
        child2 = fork();
        if (child2 == 0)
        {
            printf("Child 2 started: PID=%d, Parent PID=%d\n", getpid(), getppid());
        }
        else
        {
            child3 = fork();
            if (child3 == 0)
            {
                printf("Child 3 started: PID=%d, Parent PID=%d\n", getpid(), getppid());
            }
            else
            {
                // Parent waiting for children to finish
                printf("Process waiting for first child...\n");
                waitpid(child1, NULL, 0);
                printf("Child 1 exited.\n");

                printf("Process waiting for second child...\n");
                waitpid(child2, NULL, 0);
                printf("Child 2 exited.\n");

                printf("Process waiting for third child...\n");
                waitpid(child3, NULL, 0);
                printf("Child 3 exited.\n");
            }
        }
    }
    return 0;
}
