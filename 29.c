/* Program Number: 29
Student Name: Mada Hemanth; Register Number: IMT2023581
Date: 1 April, 2025
Description: This program obtains the current scheduling policy of the process
             and then tries to modify it to SCHED_RR (Round Robin).
*/

#include <stdio.h>
#include <unistd.h>
#include <sched.h>
#include <string.h>
#include <errno.h>

const char *get_policy_name(int policy)
{
    switch (policy)
    {
    case SCHED_OTHER:
        return "SCHED_OTHER (Normal)";
    case SCHED_FIFO:
        return "SCHED_FIFO (First In, First Out)";
    case SCHED_RR:
        return "SCHED_RR (Round Robin)";
    default:
        return "Unknown Policy";
    }
}

int main()
{

    int process_id = getpid();
    printf("Current process ID: %d\n", process_id);

    int current_policy;
    current_policy = sched_getscheduler(process_id);

    if (current_policy == -1)
    {
        printf("Error getting scheduling policy: %s\n", strerror(errno));
        return 1;
    }

    printf("Current scheduling policy is: %d (%s)\n", current_policy, get_policy_name(current_policy));

    struct sched_param new_param;
    new_param.sched_priority = 25;

    printf("Attempting to change policy to SCHED_RR\n");

    int result = sched_setscheduler(process_id, SCHED_RR, &new_param);

    if (result == -1)
    {
        printf("Failed to change scheduling policy: %s\n", strerror(errno));
        printf("Note: You might need to run this program with sudo\n");
        return 1;
    }

    int updated_policy = sched_getscheduler(process_id);
    if (updated_policy == -1)
    {
        printf("Error getting updated policy\n");
        return 1;
    }

    printf("Successfully changed scheduling policy\n");
    printf("New scheduling policy is: %d (%s)\n", updated_policy, get_policy_name(updated_policy));

    return 0;
}