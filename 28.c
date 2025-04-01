/* Program Number: 28
Student Name: Mada Hemanth; Register Number: IMT2023581
Date: 1 April, 2025
Description: This program finds out the current priority of itself and then
             modifies it using the nice system call.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main()
{

    pid_t my_process_id;
    my_process_id = getpid();

    int current_prio;

    current_prio = getpriority(PRIO_PROCESS, my_process_id);

    printf("This program (PID: %d) has priority: %d\n",
           my_process_id, current_prio);

    int increment = 10;
    printf("Trying to decrease priority by %d\n", increment);

    int result = nice(increment);

    if (result == -1)
    {
        printf("Something went wrong when changing priority\n");
    }
    else
    {
        printf("Priority change attempt completed\n");
    }

    int new_prio = getpriority(PRIO_PROCESS, my_process_id);

    printf("New priority value: %d\n", new_prio);
    printf("Priority changed by: %d\n", new_prio - current_prio);

    return 0;
}