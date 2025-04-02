/*    Program Number: 19c
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 28 March, 2025
      Description: A program that initiates a process in stopped state.
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main()
{
    printf("This process will be stopped\n");
    kill(getpid(), SIGSTOP);
}
