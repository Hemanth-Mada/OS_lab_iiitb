#include <stdio.h>
#include <signal.h>

int main()
{
    printf("This process will be stopped.\n");
    kill(getpid(), SIGSTOP);
    printf("If you see this, it resumed!\n");
}
