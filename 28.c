/*    Program Number: 28
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

    pid_t my_process_id;      // Variable to store the process ID
    my_process_id = getpid(); // Get the current process ID

    int current_prio; // Variable to store the current priority

    current_prio = getpriority(PRIO_PROCESS, my_process_id); // Get the current priority of the process

    printf("This program (PID: %d) has priority: %d\n", my_process_id, current_prio);

    int increment = 10;                                       // Value to decrease the priority
    printf("Trying to decrease priority by %d\n", increment);

    int result = nice(increment); // Attempt to change the priority

    if (result == -1)
    {
        printf("Something went wrong when changing priority\n");
    }
    else
    {
        printf("Priority change attempt completed\n");
    }

    int new_prio = getpriority(PRIO_PROCESS, my_process_id); // Get the new priority after change

    printf("New priority value: %d\n", new_prio);
    printf("Priority changed by: %d\n", new_prio - current_prio);

    return 0; // Exit the program
}