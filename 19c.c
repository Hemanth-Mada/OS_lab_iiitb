/*    Program Number: 19c
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 28 March, 2025
      Description: 
*/

#include <stdio.h>
#include <signal.h>

int main()
{
    printf("This process will be stopped\n");
    kill(getpid(), SIGSTOP);
    printf("If you see this, it resumed\n");
}
