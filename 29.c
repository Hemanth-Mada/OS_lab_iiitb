/*    Program Number: 29
      Student Name: Mada Hemanth; Register Number: IMT2023581
      Date: 3 April, 2025
      Description: This program finds out the current scheduling policy of itself and then
                   modifies it using the sched_setscheduler system call.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <sys/types.h>

void print_policy(int policy)
{
    if (policy == SCHED_OTHER)
    {
        printf("Current Scheduling Policy: SCHED_OTHER\n");
    }
    else if (policy == SCHED_FIFO)
    {
        printf("Current Scheduling Policy: SCHED_FIFO\n");
    }
    else if (policy == SCHED_RR)
    {
        printf("Current Scheduling Policy: SCHED_RR\n");
    }
    else
    {
        printf("Unknown Scheduling Policy\n");
    }
}

int main()
{
    pid_t pid = getpid(); // Get current process ID
    int current_policy = sched_getscheduler(pid);

    if (current_policy == -1)
    {
        perror("sched_getscheduler failed");
        return 1;
    }

    // Print current scheduling policy
    print_policy(current_policy);

    // Set scheduling policy to SCHED_RR (Round Robin)
    struct sched_param param;
    param.sched_priority = 10; // Priority for real-time policies

    if (sched_setscheduler(pid, SCHED_RR, &param) == -1)
    {
        perror("sched_setscheduler failed");
        return 1;
    }

    printf("Changed scheduling policy to SCHED_RR\n");

    // Verify the change
    current_policy = sched_getscheduler(pid);
    print_policy(current_policy);

    return 0;
}
